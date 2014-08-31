//
// Copyright (c) 2004 Golden Bits Software, Inc.
// All rights reserved
// www.goldenbits.com
//
//  WARNING: For sample/demonstration use only, no warranty
//           of any kind.
//
//  File: CrConfig.c
//
//  Desc: Contains routines to configure USB device.  Setup pipes and
//        USB device descriptors.
//
  

#include "ntddk.h"
#include "wmilib.h"
#include "usbdi.h"
#include "usbdlib.h"
#include "CrMain.h"
#include "CrPnp.h"
#include "CrConfig.h"
#include "..\Include\UsbCryptAppInc.h"



// ================== ConfigureDriver() ===============
//  Desc: Configures the USB device.
//
// Returns: NTSTATUS
//
NTSTATUS ConfigureDriver(IN PDEVICE_OBJECT pDeviceObject)
{
  NTSTATUS RetStatus;

    // get device descriptor, one per USB device
    // describes USB device as a whole
    RetStatus = GetUSBDeviceDescripitor(pDeviceObject);

    if(!NT_SUCCESS(RetStatus))
    {
        USB_TRACE("ConfigureDriver() Error when getting device descriptor.\n");
        return RetStatus;
    }


    // get the configurations, it's possible an
    // USB device can have multiple configurations
    GetUSBConfigDescriptor(pDeviceObject);

    // we should be ready to go!!
    return STATUS_SUCCESS;
}



// =============== GetUSBDeviceDescripitor() =============
//  Desc: Gets the device descriptor and stores in the device
//        extension at pCryptExt->My_USBDeviceDesc.  Calls other
//        functions to finish configuring the USB device.
//
//  Returns: NTSTATUS
//
NTSTATUS GetUSBDeviceDescripitor(IN PDEVICE_OBJECT pDeviceObject)
{
  PUSB_CRYPT_EXT pCryptExt;
  PURB  pURB;
  NTSTATUS Status;

  
    // get device extension
    pCryptExt = (PUSB_CRYPT_EXT)pDeviceObject->DeviceExtension;


    // get memory for URB request
    pURB = ExAllocatePool(NonPagedPool, 
                         sizeof(struct _URB_CONTROL_DESCRIPTOR_REQUEST));

    if(pURB == NULL)
    {
        // out of memory?? log error and exit
        USB_TRACE("GetUSBDeviceDescripitor() - Allocate memory failed\n");
        return STATUS_NO_MEMORY;
    }


    // build a descriptor request for our
    // USB Device
    UsbBuildGetDescriptorRequest(pURB, 
                                 (USHORT) sizeof(struct _URB_CONTROL_DESCRIPTOR_REQUEST),
                                 USB_DEVICE_DESCRIPTOR_TYPE, 
                                 0, 
                                 0, 
                                 &pCryptExt->My_USBDeviceDesc, 
                                 NULL, 
                                 sizeof(pCryptExt->My_USBDeviceDesc), 
                                 NULL);

    // Call USB bus driver, with blocking flag set
    // to TRUE. This means we'll wait here until we get
    // a response
    Status = SendUSBRequest(pDeviceObject, pURB, TRUE);

    return Status;

}



// =============== GetUSBConfigDescriptor() =============
//  Desc: Returns configuration descriptors for this USB device.
//        Remember, you can have multiple configuration descriptors
//        for a single USB device.
//
//  Returns: NTSTATUS
//
NTSTATUS GetUSBConfigDescriptor(IN PDEVICE_OBJECT pDeviceObj)
{
  PURB            pUrb;
  ULONG           DescLen;
  NTSTATUS        ntStatus;
  PUSB_CRYPT_EXT  pCryptExt;
  PUSB_CONFIGURATION_DESCRIPTOR  pConfigDescriptor;

    //
    // initialize the variables
    //
    pConfigDescriptor = NULL;

    pCryptExt = (PUSB_CRYPT_EXT)pDeviceObj->DeviceExtension;

    //
    // Get the configuration descriptor for this device
    // Note that.... this first request is just for the 
    // the descriptor itself, not including any interfaces.
    // The first call get's the lenght required for all of the
    // interfaces.  From this we can allocate enough memory to 
    // perform the second call, which actually gets the 
    // interfaces.
    //

    pUrb = ExAllocatePool(NonPagedPool, 
                         sizeof(struct _URB_CONTROL_DESCRIPTOR_REQUEST));

    if(pUrb == NULL)
    {
        // log error message
        USB_TRACE("GetUSBConfigDescriptor() Failed to allocate memory for URB\n");
        return STATUS_INSUFFICIENT_RESOURCES;
    }


    DescLen = sizeof(USB_CONFIGURATION_DESCRIPTOR);

    pConfigDescriptor = ExAllocatePool(NonPagedPool, DescLen);

    if(pConfigDescriptor == NULL)
    {
        ExFreePool(pUrb);

        // log error message
        USB_TRACE("GetUSBConfigDescriptor() Failed to allocate memory for config descriptor.\n");
        return STATUS_INSUFFICIENT_RESOURCES;
    }


    // now build the URB to get the device's configuration descriptor
    UsbBuildGetDescriptorRequest(pUrb,
                        (USHORT)sizeof(struct _URB_CONTROL_DESCRIPTOR_REQUEST),
                        USB_CONFIGURATION_DESCRIPTOR_TYPE, 
                        0, 
                        0, 
                        pConfigDescriptor,
                        NULL, 
                        DescLen, 
                        NULL);

    // send request to USB bus driver
    ntStatus = SendUSBRequest(pDeviceObj, pUrb, TRUE);

    if(!NT_SUCCESS(ntStatus)) 
    {

        USB_TRACE1("GetUSBConfigDescriptor() device config request failed, status 0x%x\n",
                     ntStatus);

        ExFreePool(pUrb);
        ExFreePool(pConfigDescriptor);

        return STATUS_UNSUCCESSFUL;
    }

    // successfully got the descriptor, now let's look 
    // at it and determine how large we should make
    // our next descriptor
    DescLen = pConfigDescriptor->wTotalLength;

    // free original allocation and re-allocate with
    // new config descriptor len
    ExFreePool(pConfigDescriptor);

    pConfigDescriptor = ExAllocatePool(NonPagedPool, DescLen);

    if(pConfigDescriptor == NULL)
    {
        ExFreePool(pUrb);

        // log error message
        USB_TRACE("GetUSBConfigDescriptor() Failed to allocate memory for second config descriptor.\n");
        return STATUS_INSUFFICIENT_RESOURCES;
    }


    // build our second request, this will actually
    // get the device interfaces
    UsbBuildGetDescriptorRequest(pUrb,
                    (USHORT)sizeof(struct _URB_CONTROL_DESCRIPTOR_REQUEST),
                    USB_CONFIGURATION_DESCRIPTOR_TYPE,
                    0, 
                    0, 
                    pConfigDescriptor, 
                    NULL, 
                    DescLen, 
                    NULL);

    // send request to bus driver
    ntStatus = SendUSBRequest(pDeviceObj, pUrb, TRUE);

    if(!NT_SUCCESS(ntStatus)) 
    {
        USB_TRACE1("GetUSBConfigDescriptor() device config second request failed, status 0x%x\n",
                     ntStatus);

        ExFreePool(pUrb);
        ExFreePool(pConfigDescriptor);
        return STATUS_UNSUCCESSFUL;
    }

    // free the URB only, the config descriptor we'll keep
    // in the device extension
    ExFreePool(pUrb);

    pCryptExt->pConfigDesc = pConfigDescriptor;

    // let's setup our USB interface for this device
    ntStatus = SetupInterfaces(pDeviceObj);

    return ntStatus;
}


// ================ SetupInterfaces() =======================
//  Desc: Sets up interface for this device
// 
//  Returns: NTSTATUS
//
NTSTATUS SetupInterfaces(IN PDEVICE_OBJECT pDeviceObj)
{
  PUSB_CRYPT_EXT  pCryptExt;
  PUSB_CONFIGURATION_DESCRIPTOR  pConfigDescriptor;
  PURB pUrb;
  long lNumInterfaces, lIFNumber;
  long lCount;
  NTSTATUS  Status;
  PUSBD_INTERFACE_LIST_ENTRY pInterfaceList, pBegList;
  PUSB_INTERFACE_DESCRIPTOR pInterfaceDesc;
  PUSBD_INTERFACE_INFORMATION pInterfaceInfo;


    pCryptExt = (PUSB_CRYPT_EXT)pDeviceObj->DeviceExtension;
    pConfigDescriptor = pCryptExt->pConfigDesc;

    lNumInterfaces = pConfigDescriptor->bNumInterfaces;


    // allocate mem for interface list, add one to last entry
    // to indicate end of list - NULL termination of sorts
    pInterfaceList = ExAllocatePool(NonPagedPool, 
                                    sizeof(USBD_INTERFACE_LIST_ENTRY) * 
                                    (lNumInterfaces + 1));

    if(pInterfaceList == NULL) 
    {
        USB_TRACE("SetupInterfaces() Failed to allocate memory\n");
        return STATUS_INSUFFICIENT_RESOURCES;
    }

    // save off beginning of interface lis
    pBegList = pInterfaceList;


    // cycle through interfaces in configuration
    // descriptor and get for our private list
    for(lIFNumber = 0; lIFNumber < lNumInterfaces; lIFNumber++)
    {
        pInterfaceDesc = USBD_ParseConfigurationDescriptorEx(
                                            pConfigDescriptor, 
                                            pConfigDescriptor,
                                            lIFNumber,
                                            0, -1, -1, -1);

        if(pInterfaceDesc) 
        {
            pInterfaceList->InterfaceDescriptor = pInterfaceDesc;
            pInterfaceList->Interface = NULL;
            pInterfaceList++;
        }

    }  // end for()

    // add NULL to end to termiante list
    pInterfaceList->InterfaceDescriptor = NULL;
    pInterfaceList->Interface = NULL;

    // now create descriptor which will request USB host
    // driver to use interface
    //
    pUrb = USBD_CreateConfigurationRequestEx(pConfigDescriptor, pBegList);

    if(pUrb == NULL)
    {
        ExFreePool(pBegList);
        return STATUS_INSUFFICIENT_RESOURCES;
    }


    // get pointer to first interface -- 2 pipes
    pInterfaceInfo = &pUrb->UrbSelectConfiguration.Interface;

    for(lCount = 0; lCount < (long)pInterfaceInfo->NumberOfPipes; lCount++) 
    {
        //
        // perform pipe initialization here
        // set the transfer size and any pipe flags we use
        // USBD sets the rest of the Interface struct members
        //
        pInterfaceInfo->Pipes[lCount].MaximumTransferSize = 
                            USBD_DEFAULT_MAXIMUM_TRANSFER_SIZE;
    }

    // now setup second interface - 3 pipes
    // get pointer to second interface
    (PCHAR)pInterfaceInfo = (PCHAR)pInterfaceInfo + pInterfaceInfo->Length;

    for(lCount = 0; lCount < (long)pInterfaceInfo->NumberOfPipes; lCount++) 
    {
        //
        // perform pipe initialization here
        // set the transfer size and any pipe flags we use
        // USBD sets the rest of the Interface struct members
        //
        pInterfaceInfo->Pipes[lCount].MaximumTransferSize = 
                            USBD_DEFAULT_MAXIMUM_TRANSFER_SIZE;
    }

    // call the USB bus driver to request these interfaces
    Status = SendUSBRequest(pDeviceObj, pUrb, TRUE);

    if(!NT_SUCCESS(Status)) 
    {
        ExFreePool(pUrb);
        ExFreePool(pBegList);
        return Status;
    }


    // save first interface info
    pInterfaceInfo = &pUrb->UrbSelectConfiguration.Interface;

    do {

        pCryptExt->EncryptionInfo.FunctionType = CRYPT_FUNCTION_ENCRYPTION;

        Status = SaveInterfaceInfo(pInterfaceInfo, &pCryptExt->pEncryptIFInfo,
                                   &pCryptExt->EncryptionInfo);

        if(!NT_SUCCESS(Status))
            break;

        // save second interface info
        (PCHAR)pInterfaceInfo = (PCHAR)pInterfaceInfo + pInterfaceInfo->Length;

        pCryptExt->DecryptionInfo.FunctionType = CRYPT_FUNCTION_DECRYPTION;

        Status = SaveInterfaceInfo(pInterfaceInfo, &pCryptExt->pDecryptIFInfo, 
                                   &pCryptExt->DecryptionInfo);

        if(!NT_SUCCESS(Status))
            break;

    } while(FALSE);



    // output interface info, for debugging purposes
    DumpInterfaceInfo(pDeviceObj, pCryptExt->pEncryptIFInfo);
    DumpInterfaceInfo(pDeviceObj, pCryptExt->pDecryptIFInfo);

    // all done, free memory
    ExFreePool(pUrb);
    ExFreePool(pBegList);

    return Status;
}




// =============== SaveInterfaceInfo() ==============
//
//  Desc: Save's off interface and pipe context info.
//
//  Returns: STATUS_SUCCESS or NT failure status
//
//
NTSTATUS SaveInterfaceInfo(IN PUSBD_INTERFACE_INFORMATION pInterfaceInfo,
                           IN PUSBD_INTERFACE_INFORMATION *pSaveUsbIF,
                           IN PCRYPT_HANDLE_INFO pHandleInfo)
{
  long lCnt;
  
    // save interface info in device extension
    *pSaveUsbIF = ExAllocatePool(NonPagedPool, pInterfaceInfo->Length);

    if(*pSaveUsbIF == NULL)
    {
        USB_TRACE("SaveInterfaceInfo() Memory alloc for failed\n");
        return STATUS_INSUFFICIENT_RESOURCES;
    }


    // save off interfaces into our device extension
    RtlCopyMemory((*pSaveUsbIF), pInterfaceInfo,  pInterfaceInfo->Length);

     // sanity check, the first pipe should be output from 
     // from device, the high bit in the endpoint address
     // should be set
     ASSERT(pInterfaceInfo->Pipes[0].EndpointAddress  & 0x80);

     ASSERT( !(pInterfaceInfo->Pipes[1].EndpointAddress  & 0x80) );


    // now save off the pipe info, depending on type of IF
    switch(pHandleInfo->FunctionType)
    {
        case CRYPT_FUNCTION_ENCRYPTION:


             pHandleInfo->OutputPipe   = pInterfaceInfo->Pipes[0].PipeHandle;
             pHandleInfo->InputPipe    = pInterfaceInfo->Pipes[1].PipeHandle;
             pHandleInfo->ProgressPipe = NULL;
             break;

        case CRYPT_FUNCTION_DECRYPTION:

             pHandleInfo->OutputPipe   = pInterfaceInfo->Pipes[0].PipeHandle;
             pHandleInfo->InputPipe    = pInterfaceInfo->Pipes[1].PipeHandle;
             pHandleInfo->ProgressPipe = pInterfaceInfo->Pipes[2].PipeHandle;
             break;

        default:

            ASSERT(FALSE);
            break;
    }


    return STATUS_SUCCESS;
}
                       
                       

// =============== DumpInterfaceInfo() ==============
//
//  For debugging purposes, dump the interface info
//
//
//
void DumpInterfaceInfo(IN PDEVICE_OBJECT pDeviceObject,
                       IN PUSBD_INTERFACE_INFORMATION pUsbIF)
{
  PUSB_CRYPT_EXT pCryptExt;
  int nIndex;

    pCryptExt = (PUSB_CRYPT_EXT)pDeviceObject->DeviceExtension;


    //
    // Dump interface info 
    //

    // dump Interface Info
    USB_TRACE("\n---- Interface Info-----\n");
    USB_TRACE1("Number of Pipes: 0x%x\n", pUsbIF->NumberOfPipes);
    USB_TRACE1("Interface Number: 0x%x\n", pUsbIF->InterfaceNumber);


    USB_TRACE3("Class, subclass, protocol 0x%x 0x%x 0x%x\n",
                         pUsbIF->Class,
                         pUsbIF->SubClass,
                         pUsbIF->Protocol);

    // dump pipe info
    USB_TRACE("---- Pipe Info-----\n");

    for(nIndex=0; nIndex < (int)pUsbIF->NumberOfPipes; nIndex++) 
    {
        USB_TRACE1("PipeType 0x%x\n", pUsbIF->Pipes[nIndex].PipeType);

        USB_TRACE1("EndpointAddress 0x%x\n", 
                             pUsbIF->Pipes[nIndex].EndpointAddress);

        USB_TRACE1("MaxPacketSize 0x%x\n", 
                            pUsbIF->Pipes[nIndex].MaximumPacketSize);

        USB_TRACE1("Interval 0x%x\n", 
                             pUsbIF->Pipes[nIndex].Interval);

        USB_TRACE1("Handle 0x%x\n", 
                             pUsbIF->Pipes[nIndex].PipeHandle);

        USB_TRACE1("MaximumTransferSize 0x%x\n", 
                            pUsbIF->Pipes[nIndex].MaximumTransferSize);
    }

}


