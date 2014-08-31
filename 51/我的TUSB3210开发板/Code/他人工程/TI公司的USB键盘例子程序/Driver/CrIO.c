//
// Copyright (c) 2004 Golden Bits Software, Inc.
// All rights reserved
// www.goldenbits.com
//
//  WARNING: For sample/demonstration use only, no warranty
//           of any kind.
//
//    CrIO.c
//    
//    Desc: Code to create, close, perform IO
//


#include "ntddk.h"
#include "wmilib.h"
#include "usbdi.h"
#include "usbdlib.h"
#include "CrMain.h"
#include "CrPnp.h"
#include "..\Include\UsbCryptAppInc.h"




// ==================== UsbCrypt_Create() =============
//  Desc: Creates open file handle do our USB device.
//        Saves a pointer to the USB pipe handles in the
//        FsContext of the open handle.
//
//  Returns: STATUS_SUCCESS or failure.
// 
NTSTATUS UsbCrypt_Create(IN PDEVICE_OBJECT pDeviceObject,
                         IN PIRP           pIrp)
{
  PCRYPT_HANDLE_INFO pCryptInfo;
  PUSB_CRYPT_EXT pCryptExt = (PUSB_CRYPT_EXT)pDeviceObject->DeviceExtension;
  PIO_STACK_LOCATION pIrpStack;

    pIrpStack = IoGetCurrentIrpStackLocation(pIrp);

    // set crypt handle info
    pCryptInfo = ExAllocatePoolWithTag(PagedPool, sizeof(CRYPT_HANDLE_INFO),
                                       CRYT_MEM_TAG);

    if(pCryptInfo == NULL)
    {
        USB_TRACE("UsbCrypt_Create(): Failed to alloc memory for crypt handle\n");
        pIrp->IoStatus.Status = STATUS_INSUFFICIENT_RESOURCES;
        IoCompleteRequest(pIrp, IO_NO_INCREMENT);
        return STATUS_INSUFFICIENT_RESOURCES;
    }

    // set default as encryption
    RtlCopyMemory(pCryptInfo,  &pCryptExt->EncryptionInfo, 
                  sizeof(CRYPT_HANDLE_INFO));

    // save off handle context into file context
    // we'll use this later to when processing an
    // IO to the device
    pIrpStack->FileObject->FsContext = pCryptInfo;

    // complete request
    pIrp->IoStatus.Status = STATUS_SUCCESS;
    IoCompleteRequest(pIrp, IO_NO_INCREMENT);
    return STATUS_SUCCESS;
}


// ==================== UsbCrypt_Close() =============
//  Desc: Closes an open file handle and frees the memory
//        allocated for the USB pipe handles.
//
//  Returns: STATUS_SUCCESS
// 
NTSTATUS UsbCrypt_Close(IN PDEVICE_OBJECT pDeviceObject,
                        IN PIRP           pIrp)
{
  PUSB_CRYPT_EXT pCryptExt = (PUSB_CRYPT_EXT)pDeviceObject->DeviceExtension;
  PIO_STACK_LOCATION pIrpStack;

    pIrpStack = IoGetCurrentIrpStackLocation(pIrp);

    // delete memory allocated for crypt handle info
    if(pIrpStack->FileObject->FsContext != NULL)
    {
        ExFreePool(pIrpStack->FileObject->FsContext);
        pIrpStack->FileObject->FsContext = NULL;
    }


    // complete request
    pIrp->IoStatus.Status = STATUS_SUCCESS;
    IoCompleteRequest(pIrp, IO_NO_INCREMENT);

    return STATUS_SUCCESS;
}



// ==================== UsbCrypt_Read() =============
//  Desc: Reads data from the USB device.  The pipe handles 
//        saved in the memory pointed to by FsContext is used
//        to perform the actual read.
//
//  Returns: STATUS_SUCCESS or NT Status failure
// 
NTSTATUS UsbCrypt_Read(IN PDEVICE_OBJECT pDeviceObject,
                       IN PIRP           pIrp)
{
  NTSTATUS Status;
  PUSB_CRYPT_EXT pCryptExt;
  USBD_PIPE_HANDLE PipeHandle;
  PIO_STACK_LOCATION pStack;
  PCRYPT_HANDLE_INFO pHInfo;
  ULONG ulBufXferLen;
  PBYTE pReadBuf;


    pCryptExt = (PUSB_CRYPT_EXT)pDeviceObject->DeviceExtension;

    // check our device state
    if(GET_CURRENT_PNP_STATE(pCryptExt) != Working)
    {
        // complete IRP with error status
        pIrp->IoStatus.Status = STATUS_INVALID_DEVICE_STATE;
        pIrp->IoStatus.Information = 0;
        IoCompleteRequest(pIrp, IO_NO_INCREMENT);
        return STATUS_INVALID_DEVICE_STATE;
    }    

    // get pointer to device stack and associated
    // arguments for input/ouput
    pStack = IoGetCurrentIrpStackLocation(pIrp);

    pHInfo = (PCRYPT_HANDLE_INFO)pStack->FileObject->FsContext;

    // sanity check
    ASSERT(pHInfo != NULL);

    // grab IO lock so we don't get removed while
    // we've got an IO in process
    IoAcquireRemoveLock(&pCryptExt->RemoveLock, (PVOID)CRYT_MEM_TAG);

    // get correct pipe handle for our read operation
    // we're "outputting" data to the host
    PipeHandle = pHInfo->OutputPipe;
        

    // get buffer to write data to device, since we're
    // using DirectIO method, the buffer should be
    // setup for us (i.e. locked and mapped).  However, we'll
    // call MmGetSystemAddressForMdlSafe() to insure the buffer
    // is locked and mapped to system space
    pReadBuf = (PBYTE)MmGetSystemAddressForMdlSafe(pIrp->MdlAddress, 
                                                   NormalPagePriority);

    // get max len to write, if greater than waht our USB device
    // can handle then we'll just truncate.  The amount of 
    // data you can transfer to your device depends on the
    // device itself.  Our simple device an only handle
    // a small amount of data.  
    //
    // If your device can not handle the entire transfer,
    // an alternative is to break up the IO into multiple
    // transfers.
    ulBufXferLen = MmGetMdlByteCount(pIrp->MdlAddress);


    ulBufXferLen = ulBufXferLen > MAX_CRYPT_TRANSFER ? 
                    MAX_CRYPT_TRANSFER : ulBufXferLen;

    // NOTE: The pipe handle determines if we're sending
    //       or recieving data to/from the USB device.
    Status = SendBulkIntTransfer(pDeviceObject, pReadBuf, 
                                 ulBufXferLen,  PipeHandle,
                                 TRUE, &ulBufXferLen);

    // complete request
    pIrp->IoStatus.Status = Status;
    pIrp->IoStatus.Information = ulBufXferLen;
    IoCompleteRequest(pIrp, IO_NO_INCREMENT);

    // Release IO lock
    IoReleaseRemoveLock(&pCryptExt->RemoveLock, (PVOID)CRYT_MEM_TAG);

    return STATUS_SUCCESS;
}


// ==================== UsbCrypt_Write() =============
//  Desc: Writes data from the USB device.  The pipe handles 
//        saved in the memory pointed to by FsContext is used
//        to perform the actual read.
//
//  Returns: STATUS_SUCCESS or NT Status failure
// 
NTSTATUS UsbCrypt_Write(IN PDEVICE_OBJECT pDeviceObject,
                        IN PIRP           pIrp)
{
  NTSTATUS Status;
  PUSB_CRYPT_EXT pCryptExt;
  USBD_PIPE_HANDLE PipeHandle;
  PIO_STACK_LOCATION pStack;
  PCRYPT_HANDLE_INFO pHInfo;
  ULONG ulBufXferLen;
  PBYTE pWriteBuf;


    pCryptExt = (PUSB_CRYPT_EXT)pDeviceObject->DeviceExtension;

    // check our device state
    if(GET_CURRENT_PNP_STATE(pCryptExt) != Working)
    {
        // complete IRP with error status
        pIrp->IoStatus.Status = STATUS_INVALID_DEVICE_STATE;
        pIrp->IoStatus.Information = 0;
        IoCompleteRequest(pIrp, IO_NO_INCREMENT);
        return STATUS_INVALID_DEVICE_STATE;
    }    

    // get pointer to device stack and associated
    // arguments for input/ouput
    pStack = IoGetCurrentIrpStackLocation(pIrp);

    pHInfo = (PCRYPT_HANDLE_INFO)pStack->FileObject->FsContext;

    // sanity check
    ASSERT(pHInfo != NULL);

    // grab IO lock so we don't get removed while
    // we've got an IO in process
    IoAcquireRemoveLock(&pCryptExt->RemoveLock, (PVOID)CRYT_MEM_TAG);

    // get correct pipe handle for our write operation
    // we're "inputting" data to the USB device
    PipeHandle = pHInfo->InputPipe;
        

    // get buffer to write data to device, since we're
    // using DirectIO method, the buffer should be
    // setup for us (i.e. locked and mapped).  However, we'll
    // call MmGetSystemAddressForMdlSafe() to insure the buffer
    // is locked and mapped to system space
    pWriteBuf = (PBYTE)MmGetSystemAddressForMdlSafe(pIrp->MdlAddress, 
                                                    NormalPagePriority);

    // get max len to write, if greater than waht our USB device
    // can handle then we'll just truncate.  The amount of 
    // data you can transfer to your device depends on the
    // device itself.  Our simple device an only handle
    // a small amount of data.  
    //
    // If your device can not handle the entire transfer,
    // an alternative is to break up the IO into multiple
    // transfers.
    ulBufXferLen = MmGetMdlByteCount(pIrp->MdlAddress);


    ulBufXferLen = ulBufXferLen > MAX_CRYPT_TRANSFER ? 
                    MAX_CRYPT_TRANSFER : ulBufXferLen;

    // NOTE: The pipe handle determines if we're sending
    //       or recieving data to/from the USB device.
    Status = SendBulkIntTransfer(pDeviceObject, pWriteBuf, 
                                 ulBufXferLen,  PipeHandle,
                                 FALSE, &ulBufXferLen);

    // complete request
    pIrp->IoStatus.Status = Status;
    pIrp->IoStatus.Information = ulBufXferLen;
    IoCompleteRequest(pIrp, IO_NO_INCREMENT);

    // Release IO lock
    IoReleaseRemoveLock(&pCryptExt->RemoveLock, (PVOID)CRYT_MEM_TAG);

    return Status;
}


// ==================== UsbCrypt_DeviceCtrl() =============
//  Desc: Handles IOCTLs from user app.
//
//  Returns: STATUS_SUCCESS or NT Status failure
// 
NTSTATUS UsbCrypt_DeviceCtrl(IN PDEVICE_OBJECT pDeviceObject,
                             IN PIRP           pIrp)
{
  PIO_STACK_LOCATION pIrpStack;
  ULONG ulInputLen, ulOutLen;
  ULONG ulIoCode, ulInfoLen;
  ULONG ulFunctionType;
  NTSTATUS Status;
  PUSB_CRYPT_EXT pCryptExt;
  PCRYPT_HANDLE_INFO pHInfo;


    // get pointer to device stack and associated
    // arguments for input/ouput
    pIrpStack = IoGetCurrentIrpStackLocation(pIrp);

    pHInfo = (PCRYPT_HANDLE_INFO)pIrpStack->FileObject->FsContext;

    ulIoCode = pIrpStack->Parameters.DeviceIoControl.IoControlCode;

    pCryptExt = (PUSB_CRYPT_EXT)pDeviceObject->DeviceExtension;

    ulInputLen = pIrpStack->Parameters.DeviceIoControl.InputBufferLength;
    ulOutLen = pIrpStack->Parameters.DeviceIoControl.OutputBufferLength;

    ulInfoLen = 0;

    // if we're not in the working state, then
    // fail the request 
    if(GET_CURRENT_PNP_STATE(pCryptExt) != Working) 
    {
        USB_TRACE("UsbCrypt_DeviceCtrl() Error, recieved in non-working state.\n");

        pIrp->IoStatus.Status = STATUS_INVALID_DEVICE_STATE;
        pIrp->IoStatus.Information = 0;

        IoCompleteRequest(pIrp, IO_NO_INCREMENT);
        return STATUS_INVALID_DEVICE_STATE;
    }


    IoAcquireRemoveLock(&pCryptExt->RemoveLock, (PVOID)CRYT_MEM_TAG);

    
    // now handle the request itself
    switch(ulIoCode) 
    {

        case IOCTL_CRYPT_GET_CONFIG_DESCRIPTOR:
        {
            ASSERT(pCryptExt->pConfigDesc != NULL);

            USB_TRACE("UsbCrypt_DeviceCtrl() Handling " \
                      "IOCTL_CRYPT_GET_CONFIG_DESCRIPTOR request.\n");

            // sanity check for NULL pointer
            if(pCryptExt->pConfigDesc == NULL) 
            {
                Status = STATUS_UNSUCCESSFUL;
                break;
            }

            // check length of descriptor, do we have enough
            // buffer space to copy info back
            if(pCryptExt->pConfigDesc->wTotalLength > ulOutLen)
            {
                Status = STATUS_BUFFER_TOO_SMALL;
                break;
            }

            // looks, good copy info back
            ulInfoLen = pCryptExt->pConfigDesc->wTotalLength;

            RtlCopyMemory(pIrp->AssociatedIrp.SystemBuffer,
                          pCryptExt->pConfigDesc,
                          ulInfoLen);

            Status = STATUS_SUCCESS;
            break;
        }


        case IOCTL_CRYPT_SET_FUNCTION:
             // validate
             ulFunctionType = *((ULONG*)pIrp->AssociatedIrp.SystemBuffer);

             if(ulFunctionType != CRYPT_FUNCTION_ENCRYPTION &&
                ulFunctionType != CRYPT_FUNCTION_DECRYPTION)
             {
                Status = STATUS_INVALID_PARAMETER;
                break;
             }

             Status = STATUS_SUCCESS;
             pHInfo->FunctionType = ulFunctionType;

             // now set the correct USB pipe hanles, depending
             // if we're doing encryption or decryption
             if(pHInfo->FunctionType == CRYPT_FUNCTION_ENCRYPTION)
             {
                 pHInfo->InputPipe = pCryptExt->EncryptionInfo.InputPipe;
                 pHInfo->OutputPipe = pCryptExt->EncryptionInfo.OutputPipe;
                 pHInfo->ProgressPipe = NULL;  // progress pipe only for 
                                               // decryption interface
             }
             else
             {
                 pHInfo->InputPipe = pCryptExt->DecryptionInfo.InputPipe;
                 pHInfo->OutputPipe = pCryptExt->DecryptionInfo.OutputPipe;
                 pHInfo->ProgressPipe = pCryptExt->DecryptionInfo.ProgressPipe;
             }


             break;

        case IOCTL_CRYPT_GET_FUNCTION:

             *((ULONG*)pIrp->AssociatedIrp.SystemBuffer) = pHInfo->FunctionType;
             ulInfoLen = sizeof(ULONG);  
             Status = STATUS_SUCCESS;
             break;


        default:
            Status = STATUS_INVALID_DEVICE_REQUEST;
            break;

    }  // end switch()

    // release our lock
    IoReleaseRemoveLock(&pCryptExt->RemoveLock, (PVOID)CRYT_MEM_TAG);

    // compelte the request
    pIrp->IoStatus.Status = Status;
    pIrp->IoStatus.Information = ulInfoLen;

    IoCompleteRequest(pIrp, IO_NO_INCREMENT);

    return Status;
}


ULONG SwapBytes(IN ULONG ulValue)
{
  ULONG ulRetVal;
  BYTESWAP SwapIt;

    SwapIt.LongVal = ulValue;

    ulRetVal =  SwapIt.ByteValues.Byte0;
    ulRetVal |= (SwapIt.ByteValues.Byte1 << 8);
    ulRetVal |= (SwapIt.ByteValues.Byte2 << 16);
    ulRetVal |= (SwapIt.ByteValues.Byte3 << 24);

    return ulRetVal;
}


// ================ GetProgress() ==============
//  Desc: This is the work item function that is called
//        to get the number of bytes the decryption interface
//        has processed.  Since we don't want to have the
//        app issue the read and potentially block, we'll
//        issue the read here and block.  When the number
//        of bytes has changed, then we'll get a response
//        from the device, thus satifying the read.
//
//        After getting the progress bytes, we'll issue another
//        read.
//
//  Returns: Nothing.
//
VOID GetProgress(IN PDEVICE_OBJECT pDeviceObject,
                 IN PVOID pContext)
{
  PUSB_CRYPT_EXT pCryptExt;
  ULONG ulNumBytesDecrypted;
  NTSTATUS Status;
  ULONG ulBufXferLen;


    pCryptExt = (PUSB_CRYPT_EXT)pDeviceObject->DeviceExtension;

    // check our device state
    if(GET_CURRENT_PNP_STATE(pCryptExt) != Working)
    {
        USB_TRACE("GetProgress() UsbCrypt device not ready, unable to get byte progress.\n");
        return;
    }

    // sanity check on pipe
    if(pCryptExt->DecryptionInfo.ProgressPipe == NULL)
    {
        USB_TRACE("GetProgress() Byte progress pipe not initialized correctly.\n");
        return;
    }

    // grab IO lock so we don't get removed while
    // we've got an IO in process
    Status = IoAcquireRemoveLock(&pCryptExt->RemoveLock, (PVOID)CRYT_MEM_TAG);

    // check if our driver is in the process of being
    // removed (we've recieved a IRP_MN_REMOVE_DEVICE)
    if(Status == STATUS_DELETE_PENDING)
        return;

    // Send read request on interupt 
    //       or recieving data to/from the USB device.
    Status = SendBulkIntTransfer(pDeviceObject, (PUCHAR)&ulNumBytesDecrypted, 
                                 sizeof(ulNumBytesDecrypted),  
                                 pCryptExt->DecryptionInfo.ProgressPipe,
                                 TRUE, &ulBufXferLen);

    // Release IO lock
    IoReleaseRemoveLock(&pCryptExt->RemoveLock, (PVOID)CRYT_MEM_TAG);

    // if the status was good, then update our
    // device extension
    if(NT_SUCCESS(Status))
    {
        // need to swap bytes since the byte order
        // comming from the device is big endian
        ulNumBytesDecrypted = SwapBytes(ulNumBytesDecrypted);

        pCryptExt->ulByteProgress = ulNumBytesDecrypted;

        USB_TRACE1("GetProgress() byte count is: 0x%x\n", ulNumBytesDecrypted);

        // queue same work item again
        IoQueueWorkItem(pCryptExt->pProgressWkItem, 
                        GetProgress,   // func which gets called
                        DelayedWorkQueue, NULL);

    }

}


// ==================== SendBulkIntTransfer() =============
//  Desc: Sends or recieves data to our sammple
//        encryption device.  Either Bulk or interrupt data
//
//  Returns: NTSTATUS and number of bytes actually 
//           transfered.
// 
NTSTATUS SendBulkIntTransfer(IN PDEVICE_OBJECT pDevObj,
                             IN PBYTE pXferBuffer,
                             IN ULONG BufferLen,
                             IN USBD_PIPE_HANDLE hPipe,
                             IN BOOLEAN bReadFromDevice,
                             OUT PULONG pBytesXfered)
{
  PURB pUrb;
  NTSTATUS Status;
  ULONG XferFlags;

    *pBytesXfered = 0;

    XferFlags = 0;

    if(bReadFromDevice)
    {
        XferFlags = USBD_TRANSFER_DIRECTION_IN|USBD_SHORT_TRANSFER_OK;
    }


    // alloc memory for USB request
    pUrb = ExAllocatePool(NonPagedPool,
                         sizeof(struct _URB_BULK_OR_INTERRUPT_TRANSFER));

    if(pUrb == NULL) 
    {
        return STATUS_NO_MEMORY;
    }


    UsbBuildInterruptOrBulkTransferRequest(
                            pUrb,
                            sizeof(struct _URB_BULK_OR_INTERRUPT_TRANSFER),
                            hPipe,
                            pXferBuffer,
                            NULL,
                            BufferLen,
                            XferFlags,
                            NULL);

    // now send request and wait for completion
    Status = SendUSBRequest(pDevObj, pUrb, TRUE);

    if(NT_SUCCESS(Status))
    {
        *pBytesXfered = BufferLen;
    }

    // free memory
    ExFreePool(pUrb);

    return Status;
}


