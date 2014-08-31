//
// Copyright (c) 2004 Golden Bits Software, Inc.
// All rights reserved
// www.goldenbits.com
//
//  WARNING: For sample/demonstration use only, no warranty
//           of any kind.
//
//
//  File: CrMain.h
//  Desc: Header file for USB Cryption driver.
//


#pragma once

#define     REG_PATH_LEN            300
#define     MAX_CRYPT_TRANSFER      0x40     // max size of buffer on 
                                             // our usb device
#define     CRYT_MEM_TAG            'pyrC'

#if DBG
#define     USB_TRACE(a)            DbgPrint((a))
#define     USB_TRACE1(a, b)        DbgPrint((a), (b))
#define     USB_TRACE2(a, b, c)     DbgPrint((a), (b), (c))
#define     USB_TRACE3(a, b, c, d)  DbgPrint((a), (b), (c), (d))
#else
#define     USB_TRACE(a) 
#define     USB_TRACE1(a, b) 
#define     USB_TRACE2(a, b, c) 
#define     USB_TRACE3(a, b, c, d) 
#endif


#ifndef PBYTE
#define PBYTE PUCHAR
#endif

#ifndef BYTE
#define BYTE UCHAR
#endif

#define INITIALIZE_PNP_STATE(_Data_)    \
        (_Data_)->DeviceState =  NotStarted;\
        (_Data_)->PrevDevState = NotStarted;

#define SET_NEW_PNP_STATE(_Data_, _state_) \
        (_Data_)->PrevDevState =  (_Data_)->DeviceState;\
        (_Data_)->DeviceState = (_state_);

#define RESTORE_PREVIOUS_PNP_STATE(_Data_)   \
        (_Data_)->DeviceState =   (_Data_)->PrevDevState;

#define GET_CURRENT_PNP_STATE(_Data_)   \
        (_Data_)->DeviceState


typedef enum _DEVSTATE {

    NotStarted,         // not started
    Stopped,            // device stopped
    Working,            // started and working
    PendingStop,        // stop pending
    PendingRemove,      // remove pending
    SurpriseRemoved,    // removed by surprise
    Removed             // removed
} DEVSTATE;


typedef union _BYTESWAP {
    ULONG LongVal;

    struct {
            BYTE Byte3;
            BYTE Byte2;
            BYTE Byte1;
            BYTE Byte0;
    } ByteValues;

} BYTESWAP, *PBYTESWAP;

// Info used to store per open file handle
// info.  Tells the drive how this open handle
// is configured, either encryption, or compression
typedef struct _CRYPT_HANDLE_INFO {
    ULONG FunctionType;
    USBD_PIPE_HANDLE InputPipe;     // input to USB device
    USBD_PIPE_HANDLE OutputPipe;    // output from device
    USBD_PIPE_HANDLE ProgressPipe;  // if decrypting, then progress
} CRYPT_HANDLE_INFO, *PCRYPT_HANDLE_INFO;


// Device extension for our driver
typedef struct _USB_CRYPT_EXT {
    ULONG ulInstanceID;

    // power states for device and system
    SYSTEM_POWER_STATE SytemPower;
    DEVICE_POWER_STATE DevicePower;


    // PNP device states
    DEVSTATE       DeviceState;
    DEVSTATE       PrevDevState;

    // remove lock, used to track IO to
    // determine when we can remove device AND
    // in response to query stop device
    IO_REMOVE_LOCK RemoveLock;


    // Interface name returned by IoRegisterDeviceInterface(), this is
    // a symbolic name used by apps to talk to our
    UNICODE_STRING OurInterfaceName;

    // this is the lower dev object we forward
    // PNP IRPs down to
    PDEVICE_OBJECT pLowerPhysDevObject;

    // this is our device object
    PDEVICE_OBJECT pOurDeviceObject;

    // device object for the top of our stack
    PDEVICE_OBJECT pTopStackDeviceObject;

    // USB structs and device info we'll keep here
    USB_DEVICE_DESCRIPTOR  My_USBDeviceDesc;

    // USB config descriptor
    PUSB_CONFIGURATION_DESCRIPTOR pConfigDesc;

    // USB Interface use for encryption
    PUSBD_INTERFACE_INFORMATION pEncryptIFInfo;

    // Interface used for decryption
    PUSBD_INTERFACE_INFORMATION pDecryptIFInfo;

    PIO_WORKITEM pProgressWkItem;

    // number of bytes decrypted 
    ULONG ulByteProgress;

    // WMI information
    WMILIB_CONTEXT CryptWminfo;

    // contains info used for encryption
    // an decryption pipes
    CRYPT_HANDLE_INFO EncryptionInfo;
    CRYPT_HANDLE_INFO DecryptionInfo;

} USB_CRYPT_EXT, *PUSB_CRYPT_EXT;


extern UNICODE_STRING g_RegPath;
extern WMIGUIDREGINFO USBCryptGuidList[1];

// function delcarations
NTSTATUS DriverEntry(IN PDRIVER_OBJECT   pDriverObject,
                     IN PUNICODE_STRING  pRegistryPath);


NTSTATUS UsbCrypt_Create(IN PDEVICE_OBJECT pDeviceObject,
                         IN PIRP           pIrp);

NTSTATUS UsbCrypt_Close(IN PDEVICE_OBJECT pDeviceObject,
                        IN PIRP           pIrp);

NTSTATUS UsbCrypt_Read(IN PDEVICE_OBJECT pDeviceObject,
                        IN PIRP           pIrp);

NTSTATUS UsbCrypt_Write(IN PDEVICE_OBJECT pDeviceObject,
                        IN PIRP           pIrp);

NTSTATUS UsbCrypt_Clean(IN PDEVICE_OBJECT pDeviceObject,
                        IN PIRP           pIrp);

NTSTATUS UsbCrypt_SystemCtrl(IN PDEVICE_OBJECT pDeviceObject,
                             IN PIRP           pIrp);

NTSTATUS UsbCrypt_DeviceCtrl(IN PDEVICE_OBJECT pDeviceObject,
                             IN PIRP           pIrp);


VOID UsbCrypt_Unload(IN PDRIVER_OBJECT pDriverObject);

NTSTATUS SendUSBRequest(IN PDEVICE_OBJECT pDeviceObject,
                        IN PURB  pURB,
                        IN BOOLEAN bBlockCall);

NTSTATUS SendBulkIntTransfer(IN PDEVICE_OBJECT pDevObj,
                             IN PBYTE pXferBuffer,
                             IN ULONG BufferLen,
                             IN USBD_PIPE_HANDLE hPipe,
                             IN BOOLEAN bReadFromDevice,
                             OUT PULONG pBytesXfered);

NTSTATUS StopUSBCryptDevice(IN PDEVICE_OBJECT pDevObj,
                            IN PUSB_CRYPT_EXT pCryptExt);

void DumpInterfaceInfo(IN PDEVICE_OBJECT pDeviceObject,
                       IN PUSBD_INTERFACE_INFORMATION pUsbIF);

NTSTATUS SaveInterfaceInfo(IN PUSBD_INTERFACE_INFORMATION pInterfaceInfo,
                           IN PUSBD_INTERFACE_INFORMATION *pSaveUsbIF,
                           IN PCRYPT_HANDLE_INFO pHandleInfo);

VOID GetProgress(IN PDEVICE_OBJECT pDeviceObject,
                 IN PVOID pContext);


// WMI functions
NTSTATUS UsbCrypt_WmiRequest(IN PDEVICE_OBJECT pDeviceObj,
                             IN PIRP pIrp);

NTSTATUS
UsbCrypt_QueryWmiRegInfo(IN  PDEVICE_OBJECT  pDeviceObj,
                         OUT ULONG           *pRegFlags,
                         OUT PUNICODE_STRING InstanceName,
                         OUT PUNICODE_STRING *pRegistryPath,
                         OUT PUNICODE_STRING pMofResourceName,
                         OUT PDEVICE_OBJECT  *pPdo);

NTSTATUS
UsbCrypt_SetWmiDataItem(IN PDEVICE_OBJECT pDeviceObj,
                        IN PIRP           pIrp,
                        IN ULONG          GuidIndex,
                        IN ULONG          InstanceIndex,
                        IN ULONG          DataItemId,
                        IN ULONG          BufferSize,
                        IN PUCHAR         pBuffer);

NTSTATUS
UsbCrypt_SetWmiDataBlock(IN PDEVICE_OBJECT pDeviceObj,
                         IN PIRP           pIrp,
                         IN ULONG          GuidIndex,
                         IN ULONG          InstanceIndex,
                         IN ULONG          BufferSize,
                         IN PUCHAR         pBuffer);


NTSTATUS
UsbCrypt_QueryWmiDataBlock(IN PDEVICE_OBJECT pDeviceObj,
                           IN PIRP           pIrp,
                           IN ULONG          GuidIndex,
                           IN ULONG          InstanceIndex,
                           IN ULONG          InstanceCount,
                           IN OUT PULONG     pInstanceLengthArray,
                           IN ULONG          OutBufferSize,
                           OUT PUCHAR        pBuffer);







