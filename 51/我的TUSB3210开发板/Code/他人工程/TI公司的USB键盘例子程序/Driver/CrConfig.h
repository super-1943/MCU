//
// Copyright (c) 2004 Golden Bits Software, Inc.
// All rights reserved
// www.goldenbits.com
//
//  WARNING: For sample/demonstration use only, no warranty
//           of any kind.
//
//
//  File: CrConfig.h
//


#pragma once

NTSTATUS ConfigureDriver(IN PDEVICE_OBJECT pDeviceObject);
NTSTATUS GetUSBConfigDescriptor(IN PDEVICE_OBJECT pDeviceObj);
NTSTATUS GetUSBDeviceDescripitor(IN PDEVICE_OBJECT pDeviceObject);
NTSTATUS SetupInterfaces(IN PDEVICE_OBJECT pDeviceObj);



