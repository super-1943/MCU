//
// Copyright (c) 2004 Golden Bits Software, Inc.
// All rights reserved
// www.goldenbits.com
//
//  WARNING: For sample/demonstration use only, no warranty
//           of any kind.
//
//   File: CrWmi.c
//   Desc: Contains WMI code
//


#define INITGUID  1

#include "ntddk.h"
#include "wmilib.h"
#include "wmistr.h"
#include "usbdi.h"
#include "usbdlib.h"
#include "CrMain.h"
#include "CrPnp.h"



#define MOFRESOURCENAME L"MofResourceName"

#define USBCRYPT_DRIVER_INFORMATION        0

DEFINE_GUID (USBCRYPT_WMI_STD_DATA_GUID,   
0x11656D81, 0xF533, 0x461a, 0xB1, 0xDA, 0xF0, 0xBD, 0xEB, 0x08, 0x9C, 0xC4);

// forward declaration
PCHAR
WMIMinorFunctionString(UCHAR MinorFunction);


WMIGUIDREGINFO USBCryptGuidList[1] = { 
    { &USBCRYPT_WMI_STD_DATA_GUID, 1, 0 } // driver information
};




// =============== UsbCrypt_WmiRequest() ==============
//
//  Desc: Handles WMI request.
//
//  Returns: NTSTATUS
//
NTSTATUS UsbCrypt_WmiRequest(IN PDEVICE_OBJECT pDeviceObj,
                             IN PIRP pIrp)
{
  PUSB_CRYPT_EXT pCryptExt;
  NTSTATUS  Status;
  PIO_STACK_LOCATION  pIrpStack;
  SYSCTL_IRP_DISPOSITION  WmiDisposition;
    

    pIrpStack = IoGetCurrentIrpStackLocation(pIrp);
    pCryptExt = (PUSB_CRYPT_EXT)pDeviceObj->DeviceExtension;

#if DBG
    USB_TRACE1("UsbCrypt_WmiRequest - %s\n", WMIMinorFunctionString(pIrpStack->MinorFunction));
#endif

    if(GET_CURRENT_PNP_STATE(pCryptExt) != Working) 
    {
        Status = STATUS_DELETE_PENDING;
        pIrp->IoStatus.Status = Status;
        pIrp->IoStatus.Information = 0;

        IoCompleteRequest(pIrp, IO_NO_INCREMENT);
        return Status;
    }


    // increment remove lock
    IoAcquireRemoveLock(&pCryptExt->RemoveLock, (PVOID)CRYT_MEM_TAG);


    // call into WMI helper library
    Status = WmiSystemControl(&pCryptExt->CryptWminfo, 
                              pDeviceObj, pIrp,
                              &WmiDisposition);

    switch(WmiDisposition) 
    {

        case IrpProcessed: 
            // Processed, nothing for us to do
            break;
        
        case IrpNotCompleted:

            //
            // This irp has not been completed, but has been fully processed.
            // we will complete it now
            //
            IoCompleteRequest(pIrp, IO_NO_INCREMENT);                
            break;
        

        case IrpForward:
        case IrpNotWmi:

            // Not for us or for lower driver, just pass down
            // the driver stack
            IoSkipCurrentIrpStackLocation(pIrp);

            Status = IoCallDriver(pCryptExt->pTopStackDeviceObject,
                                  pIrp);
            break;
                                    
        default:

            // SHOULDN'T BE HERE

            ASSERT(FALSE);

            IoSkipCurrentIrpStackLocation(pIrp);

            Status = IoCallDriver(pCryptExt->pTopStackDeviceObject,
                                  pIrp);
            break;
    }

    // release our lock
    IoReleaseRemoveLock(&pCryptExt->RemoveLock, (PVOID)CRYT_MEM_TAG);

    return Status;
}




// =============== UsbCrypt_QueryWmiRegInfo() ==============
//
//  Desc: Handles query reqeuest from WMI system, bascially a 
//        callback from Wmi helper library.
//
//  Returns: NTSTATUS
//
NTSTATUS
UsbCrypt_QueryWmiRegInfo(IN  PDEVICE_OBJECT  pDeviceObj,
                         OUT ULONG           *pRegFlags,
                         OUT PUNICODE_STRING InstanceName,
                         OUT PUNICODE_STRING *pRegistryPath,
                         OUT PUNICODE_STRING pMofResourceName,
                         OUT PDEVICE_OBJECT  *pPdo)

{
  PUSB_CRYPT_EXT  pCryptDevExt;

    pCryptDevExt = (PUSB_CRYPT_EXT)pDeviceObj->DeviceExtension;

    *pRegFlags     = WMIREG_FLAG_INSTANCE_PDO;
    *pRegistryPath = &g_RegPath;
    *pPdo          = pCryptDevExt->pLowerPhysDevObject;

    RtlInitUnicodeString(pMofResourceName, MOFRESOURCENAME);

    return STATUS_SUCCESS;
}




// =============== UsbCrypt_QueryWmiRegInfo() ==============
//
//  Desc: Queries our driver' data block, bascially a 
//        callback from Wmi helper library.
//
//        Our data block contains the decrypt byte
//        progress.
//
//  Returns: NTSTATUS
//
NTSTATUS
UsbCrypt_QueryWmiDataBlock(IN PDEVICE_OBJECT pDeviceObj,
                           IN PIRP           pIrp,
                           IN ULONG          GuidIndex,
                           IN ULONG          InstanceIndex,
                           IN ULONG          InstanceCount,
                           IN OUT PULONG     pInstanceLengthArray,
                           IN ULONG          OutBufferSize,
                           OUT PUCHAR        pBuffer)
{
  PUSB_CRYPT_EXT pCryptExt;
  NTSTATUS Status;
  ULONG DataBlockSize = 0;


    //
    // Only ever registers 1 instance per guid
    //

    ASSERT((InstanceIndex == 0) &&
           (InstanceCount == 1));
    
    pCryptExt = (PUSB_CRYPT_EXT)pDeviceObj->DeviceExtension;

    switch (GuidIndex) 
    {
        case USBCRYPT_DRIVER_INFORMATION:

            DataBlockSize = sizeof(ULONG);

            // since we only have one piece of data
            // the number of bytes that has been decrypted
            if (OutBufferSize < DataBlockSize) 
            {
                USB_TRACE("UsbCrypt_QueryWmiDataBlock()  too small\n");
                Status = STATUS_BUFFER_TOO_SMALL;
                break;
            }

            *(PULONG)pBuffer = pCryptExt->ulByteProgress;
            *pInstanceLengthArray = sizeof(ULONG);
            Status = STATUS_SUCCESS;

            break;

        default:

            Status = STATUS_WMI_GUID_NOT_FOUND;
            break;

    }  // end of switch()


    Status = WmiCompleteRequest(pDeviceObj, pIrp, 
                                Status, DataBlockSize,     
                                IO_NO_INCREMENT);

    return Status;
}


// =============== UsbCrypt_SetWmiDataItem() ==============
//
//  Desc: Sets a specific data item in our driver.
//
//  Returns: NTSTATUS
//
NTSTATUS
UsbCrypt_SetWmiDataItem(IN PDEVICE_OBJECT pDeviceObj,
                        IN PIRP           pIrp,
                        IN ULONG          GuidIndex,
                        IN ULONG          InstanceIndex,
                        IN ULONG          DataItemId,
                        IN ULONG          BufferSize,
                        IN PUCHAR         pBuffer)
{
  PUSB_CRYPT_EXT pCryptExt;
  NTSTATUS  Status;
  ULONG info;
    

    pCryptExt = (PUSB_CRYPT_EXT)pDeviceObj->DeviceExtension;
    info = 0;

    switch(GuidIndex) 
    {
        case USBCRYPT_DRIVER_INFORMATION:

            if(DataItemId == 1) 
            {
                if(BufferSize == sizeof(ULONG)) 
                {
                    // we'll reset the byte progress count
                    // here, but we could use the value passed
                    // in Buffer to set the byte progress value
                    //*((PULONG)pBuffer);
                    pCryptExt->ulByteProgress = 0;
                    info = sizeof(ULONG);
                    Status = STATUS_SUCCESS;
                }
                else 
                {
                    Status = STATUS_INFO_LENGTH_MISMATCH;
                }
            }
            else 
            {
                Status = STATUS_WMI_READ_ONLY;
            }

            break;

        default:
            Status = STATUS_WMI_GUID_NOT_FOUND;
            break;
    }

    Status = WmiCompleteRequest(pDeviceObj, pIrp,
                                Status, info,
                                IO_NO_INCREMENT);
    return Status;
}


// =============== UsbCrypt_SetWmiDataItem() ==============
//
//  Desc: Sets a block of data in our driver.
//
//  Returns: NTSTATUS
//
NTSTATUS
UsbCrypt_SetWmiDataBlock(IN PDEVICE_OBJECT pDeviceObj,
                         IN PIRP           pIrp,
                         IN ULONG          GuidIndex,
                         IN ULONG          InstanceIndex,
                         IN ULONG          BufferSize,
                         IN PUCHAR         pBuffer)
{
  PUSB_CRYPT_EXT pCryptExt;
  NTSTATUS Status;
  ULONG info;

    pCryptExt = (PUSB_CRYPT_EXT)pDeviceObj->DeviceExtension;
    info = 0;


    switch(GuidIndex) 
    {
        case USBCRYPT_DRIVER_INFORMATION:

            if(BufferSize == sizeof(ULONG)) 
            {
                //*(PULONG)pBuffer;
                // we'll just set the byte progress to zero
                // instead of the value in pBuffer
                pCryptExt->ulByteProgress = 0;
                Status = STATUS_SUCCESS;
                info = sizeof(ULONG);
            }
            else 
            {
                Status = STATUS_INFO_LENGTH_MISMATCH;
            }
            break;

        default:
            Status = STATUS_WMI_GUID_NOT_FOUND;
            break;
    }

    Status = WmiCompleteRequest(pDeviceObj, pIrp,
                                Status, info,
                                IO_NO_INCREMENT);

    return Status;
}

PCHAR
WMIMinorFunctionString(UCHAR MinorFunction)
{
    switch (MinorFunction) {

        case IRP_MN_CHANGE_SINGLE_INSTANCE:
            return "IRP_MN_CHANGE_SINGLE_INSTANCE\n";

        case IRP_MN_CHANGE_SINGLE_ITEM:
            return "IRP_MN_CHANGE_SINGLE_ITEM\n";

        case IRP_MN_DISABLE_COLLECTION:
            return "IRP_MN_DISABLE_COLLECTION\n";

        case IRP_MN_DISABLE_EVENTS:
            return "IRP_MN_DISABLE_EVENTS\n";

        case IRP_MN_ENABLE_COLLECTION:
            return "IRP_MN_ENABLE_COLLECTION\n";

        case IRP_MN_ENABLE_EVENTS:
            return "IRP_MN_ENABLE_EVENTS\n";

        case IRP_MN_EXECUTE_METHOD:
            return "IRP_MN_EXECUTE_METHOD\n";

        case IRP_MN_QUERY_ALL_DATA:
            return "IRP_MN_QUERY_ALL_DATA\n";

        case IRP_MN_QUERY_SINGLE_INSTANCE:
            return "IRP_MN_QUERY_SINGLE_INSTANCE\n";

        case IRP_MN_REGINFO:
            return "IRP_MN_REGINFO\n";

        default:
            return "IRP_MN_?????\n";
    }
}
