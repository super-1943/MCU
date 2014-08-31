//
// Copyright (c) 2004 Golden Bits Software, Inc.
// All rights reserved
// www.goldenbits.com
//
//  WARNING: For sample/demonstration use only, no warranty
//           of any kind.
//
//  Main entry points for our driver.
//


#include "ntddk.h"
#include "wmilib.h"
#include "usbdi.h"
#include "usbdlib.h"
#include "CrMain.h"
#include "CrPnp.h"
#include "..\Include\UsbCryptAppInc.h"

// Globals
WCHAR g_RegistryPathBuf[REG_PATH_LEN];
UNICODE_STRING g_RegPath;


#ifdef PAGE_CODE
#ifdef ALLOC_PRAGMA
#pragma alloc_text(INIT, DriverEntry)
#endif
#endif



// =============== DriverEntry() ==================
//  Desc: Main entry point to driver, sets up all of the
//        other entry points.
//
//  Returns NTSTATUS
//
NTSTATUS
DriverEntry(IN PDRIVER_OBJECT   pDriverObject,
            IN PUNICODE_STRING  pRegistryPath)
{
   
    //
    // Save off registry path
    //

    RtlZeroMemory(g_RegistryPathBuf,  sizeof(g_RegistryPathBuf));

    g_RegPath.Buffer = g_RegistryPathBuf;
    g_RegPath.Length = pRegistryPath->Length;
    g_RegPath.MaximumLength = sizeof(g_RegistryPathBuf) / sizeof(WCHAR);

    // sanity check
    ASSERT(g_RegPath.MaximumLength > pRegistryPath->Length);

    // now copy reg path to global var
    RtlMoveMemory (g_RegPath.Buffer, pRegistryPath->Buffer, 
                   pRegistryPath->Length);

    //
    // Setup entry points.
    //

    pDriverObject->MajorFunction[IRP_MJ_DEVICE_CONTROL] = UsbCrypt_DeviceCtrl;
    pDriverObject->MajorFunction[IRP_MJ_POWER]          = NULL;  
    pDriverObject->MajorFunction[IRP_MJ_PNP]            = UsbCrypt_PnPHandler;
    pDriverObject->MajorFunction[IRP_MJ_CREATE]         = UsbCrypt_Create;
    pDriverObject->MajorFunction[IRP_MJ_CLOSE]          = UsbCrypt_Close;
    pDriverObject->MajorFunction[IRP_MJ_CLEANUP]        = UsbCrypt_Clean;
    pDriverObject->MajorFunction[IRP_MJ_READ]           = UsbCrypt_Read;
    pDriverObject->MajorFunction[IRP_MJ_WRITE]          = UsbCrypt_Write;
    pDriverObject->MajorFunction[IRP_MJ_SYSTEM_CONTROL] = UsbCrypt_WmiRequest;
    pDriverObject->DriverUnload                         = UsbCrypt_Unload;
    pDriverObject->DriverExtension->AddDevice           = (PDRIVER_ADD_DEVICE)
                                                           UsbCrypt_AddDevice;

    return STATUS_SUCCESS;
}





NTSTATUS UsbCrypt_Clean(IN PDEVICE_OBJECT pDeviceObject,
                        IN PIRP           pIrp)
{
    return STATUS_SUCCESS;
}



VOID UsbCrypt_Unload(IN PDRIVER_OBJECT pDriverObject)
{

}

// =============== SendUSBRequest() ==================
//  Desc: Send USB request down device stack.
//
//  Returns NTSTATUS
//
NTSTATUS SendUSBRequest(IN PDEVICE_OBJECT pDeviceObject,
                        IN PURB  pURB,
                        /* NOT USED */ IN BOOLEAN bBlockCall)
{
  NTSTATUS Status;
  PIRP pIrp;
  PUSB_CRYPT_EXT pCryptExt;
  KEVENT ReqWaitEvent;
  IO_STATUS_BLOCK  IOStat;
  PIO_STACK_LOCATION pNextStack;

    // for now set to TRUE.  Do we need to send IO to
    // USB device async??? If so, then the wait event
    // can't be on the stack, also maybe we'll need
    // to use IoAllocateIrp() and build the IRP differently.
    // 
    // For this sample, we'll just be making blocking calls
    bBlockCall = TRUE;

    //
    // initialize the variables
    //
    pCryptExt = (PUSB_CRYPT_EXT)pDeviceObject->DeviceExtension;
    
    KeInitializeEvent(&ReqWaitEvent, NotificationEvent, FALSE);

    pIrp = IoBuildDeviceIoControlRequest(IOCTL_INTERNAL_USB_SUBMIT_URB, 
                                         pCryptExt->pTopStackDeviceObject,
                                         NULL, 
                                         0, 
                                         NULL, 
                                         0, 
                                         TRUE, 
                                         &ReqWaitEvent, 
                                         &IOStat);

    // did we fail to build the IRP
    if(!pIrp) 
    {
        USB_TRACE("SendUSBRequest() failed to build control IRP.\n");
        return STATUS_INSUFFICIENT_RESOURCES;
    }

    pNextStack = IoGetNextIrpStackLocation(pIrp);

    // sanity check
    ASSERT(pNextStack != NULL);

    pNextStack->Parameters.Others.Argument1 = pURB;

    // some debug, maybe too verbose
    //USB_TRACE("SendUSBRequest() ..\n");
    
    Status = IoCallDriver(pCryptExt->pTopStackDeviceObject, pIrp);

    // we'll wait here depending if the block call flag
    if(Status == STATUS_PENDING && bBlockCall) 
    {
        KeWaitForSingleObject(&ReqWaitEvent, 
                              Executive, 
                              KernelMode, 
                              FALSE, 
                              NULL);

        Status = IOStat.Status;
    }


    return Status;
}





