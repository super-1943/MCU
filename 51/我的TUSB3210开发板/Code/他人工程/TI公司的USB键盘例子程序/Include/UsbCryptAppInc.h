//
// Copyright (c) 2004 Golden Bits Software, Inc.
// All rights reserved
// www.goldenbits.com
//
//  WARNING: For sample/demonstration use only, no warranty
//           of any kind.
//
//  File: UsbCryptAppInc.h
//  Desc: Contains includes used by applications to talk to the
//        USB driver.


#pragma once


#include <initguid.h>


// {41B98849-DF1B-4f12-8699-646C2F7D1B9A}
DEFINE_GUID(GUID_CLASS_USBCRYPT, 
0x41b98849, 0xdf1b, 0x4f12, 0x86, 0x99, 0x64, 0x6c, 0x2f, 0x7d, 0x1b, 0x9a);




#define CRYPT_IOCTL_INDEX            0x0000

#define CRYPT_FUNCTION_ENCRYPTION    0x100
#define CRYPT_FUNCTION_DECRYPTION    0x200


#define IOCTL_CRYPT_GET_CONFIG_DESCRIPTOR       CTL_CODE(FILE_DEVICE_UNKNOWN,      \
                                                         CRYPT_IOCTL_INDEX + 0x01, \
                                                         METHOD_BUFFERED,          \
                                                         FILE_ANY_ACCESS)


#define IOCTL_CRYPT_SET_FUNCTION               CTL_CODE(FILE_DEVICE_UNKNOWN,       \
                                                         CRYPT_IOCTL_INDEX + 0x02, \
                                                         METHOD_BUFFERED,          \
                                                         FILE_ANY_ACCESS)


#define IOCTL_CRYPT_GET_FUNCTION               CTL_CODE(FILE_DEVICE_UNKNOWN,       \
                                                         CRYPT_IOCTL_INDEX + 0x03, \
                                                         METHOD_BUFFERED,          \
                                                         FILE_ANY_ACCESS)





