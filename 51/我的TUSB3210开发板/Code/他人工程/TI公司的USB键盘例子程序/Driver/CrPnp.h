//
// Copyright (c) 2004 Golden Bits Software, Inc.
// All rights reserved
// www.goldenbits.com
//
//  WARNING: For sample/demonstration use only, no warranty
//           of any kind.
//
//
//  File: CrPnp.h
//  Desc: Header file for USB Cryption PNP routines.
//

#pragma once


NTSTATUS UsbCrypt_PnPHandler(IN PDEVICE_OBJECT pDeviceObject,
                             IN PIRP pIrp);

NTSTATUS UsbCrypt_AddDevice(IN PDRIVER_OBJECT pDriverObject,
                            IN PDEVICE_OBJECT pPhysicalDevbject);

NTSTATUS CryptCapabilities(IN PDEVICE_OBJECT pDeviceObject,
                           IN PIRP pIrp);

PCHAR PnPMinorFunctionString(UCHAR MinorFunction);

NTSTATUS StartUSBCryptDevice(IN PDEVICE_OBJECT pDeviceObject,
                             IN PIRP pIrp);

NTSTATUS CancelRemove(IN PUSB_CRYPT_EXT pCryptExt, 
                      IN PIRP pIrp);

NTSTATUS USBCryptSurpriseRemoval(IN PDEVICE_OBJECT pDeviceObject,
                                 IN PUSB_CRYPT_EXT pCryptExt);

NTSTATUS RemoveCryptDevice(IN PDEVICE_OBJECT pDevObj,
                           IN PUSB_CRYPT_EXT pCryptExt,
                           IN PIRP pIrp);


NTSTATUS IrpGenericCompletionRoutine(IN PDEVICE_OBJECT pDeviceObject,
                                     IN PIRP pIrp,
                                     IN PVOID pContext);



