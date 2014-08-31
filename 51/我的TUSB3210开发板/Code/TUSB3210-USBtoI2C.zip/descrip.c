/******************************************************************************
 *                         VAULT INFORMATION SERVICES                         *
 *                          TEXAS INSTRUMENTS, INC.                           *
 *----------------------------------------------------------------------------*
 *                  "USB Descriptors for TUSB2136 Demo App"                   *
 *                                                                            * 
 * Programmed by: Craig Steiner, VIS (csteiner@vaultbbs.com)                  * 
 * Develop Date:  30/Sep/2000                                                 *  
 *----------------------------------------------------------------------------*
 * Description: This module is a component of the TUSB2136 Demo App.  It      *
 *   contains all the pre-defined descriptors used by the application.        *
 *                                                                            *
 * Modified by Jim Chen 2001/01/03:                                           *
 *   1. total 102 keys                                                        *
 *   2. can work in Mac                                                       *
 *   3. use scanline8, scanline9 and return 0x40 as suspend key               *
 *   4. added usbSetIdle(void), void usbSetProtocol(void) for Mac             *
 *                                                                            *
 ******************************************************************************/

#include "types.h"
#include "tusb2136.h"
#include "usb.h"

/***************************************************************************
 * Structure: Device Descriptor Structure                                  *
 * Programmer: Craig Steiner (csteiner@vaultbbs.com)                       *
 * Description: The abromDeviceDescriptor[] structure holds the 12h (18)   *
 *    bytes that make up the device descriptor for the keyboard device.    *
 ***************************************************************************/

BYTE code abromDeviceDescriptor[SIZEOF_DEVICE_DESCRIPTOR] = 
	{
    SIZEOF_DEVICE_DESCRIPTOR,       // Length of this descriptor (12h bytes)
    DESC_TYPE_DEVICE,               // Type code of this descriptor (01h)
    0x10,0x01,                      // Release of USB spec (Rev 1.1)
    0xFF,                	    	// Device's base class code
    0,                              // Device's sub class code
    0,                              // Device's protocol type code
    EP0_MAX_PACKET_SIZE,            // End point 0's max packet size = 8
    0x51,0x04,                      // Vendor ID: Texas Instruments
    0x00, 0x5F,  		    		// Product ID: UCD9110 EVM
    0x00,0x01,                      // Revision level of device, UPDATED AT RUN-TIME
    0,                              // Index of manufacturer name string desc, UPDATED AT RUN-TIME
    0,                              // Index of product name string desc, UPDATED AT RUN-TIME
    0,                              // Index of serial number string desc, UPDATED AT RUN-TIME
    1                               // Number of configurations supported
    };

/***************************************************************************
 * Structure: Configuration Descriptor Structure                           *
 * Programmer: Craig Steiner (csteiner@vaultbbs.com)                       *
 * Description: The abromConfigurationDescriptorGroup structure holds the  *
 *    data that makes up the Configuration descriptor for the keyboard     *
 *    device.                                                              *
 ***************************************************************************/

BYTE code abromConfigurationDescriptorGroup[SIZEOF_BOOTCODE_CONFIG_DESC_GROUP] =
	{
    // CONFIGURATION DESCRIPTOR (9 bytes)
    SIZEOF_CONFIG_DESCRIPTOR,        // bLength
    DESC_TYPE_CONFIG,                // bDescriptorType
    SIZEOF_BOOTCODE_CONFIG_DESC_GROUP, 0x00, // wTotalLength
    0x01,                            // bNumInterfaces
    0x01,                            // bConfigurationValue
    0x00,                            // iConfiguration Description offset
    0x80,                            // bmAttributes, bus power, do not support remote wakeup
    0x4B,                            // Max. Power Consumption at 2mA unit = 150mA

    // INTERFACE DESCRIPTOR (9 bytes)
    SIZEOF_INTERFACE_DESCRIPTOR,    // bLength
    DESC_TYPE_INTERFACE,            // bDescriptorType
    0x00,                           // bInterfaceNumber
    0x00,                           // bAlternateSetting
	0x02,							// bNumEndPoints
	0x03,							// bInterfaceClass: 3 = HID Device
	0x00, 							// bInterfaceSubClass: no Boot Device
	0x00,							// bInterfaceProtocol: no protocol
    0x01,                           // iInterface

    // KEYBOARD HID DESCRIPTOR (9 bytes)
    0x09,     			            // bLength of HID descriptor
    0x21,             		        // HID Descriptor Type:
    0x01,0x01,			            // HID Revision number 1.00
    0x00,			                // Target country, nothing specified (00h)
    0x01,			                // Number of HID classes to follow 
    0x22,			                // Report descriptor type
    SIZEOF_REPORT_DESCRIPTOR, 0x00, // Total length of report descriptor

    // ENDPOINT #1 INPUT DESCRIPTOR, (7 bytes)
    SIZEOF_ENDPOINT_DESCRIPTOR,     // bLength
    DESC_TYPE_ENDPOINT,             // bDescriptorType
    0x81,                           // bEndpointAddress; bit7=1 for IN, bits 3-0=1 for ep1
    EP_DESC_ATTR_TYPE_INT,          // bmAttributes, interrupt transfers
    0x40, 0x00,                     // wMaxPacketSize, 64 bytes
    0x0A, 							// Polling interval: Every 10 ms

	// ENDPOINT #1 OUTPUT DESCRIPTOR (7 bytes) 
	SIZEOF_ENDPOINT_DESCRIPTOR,     // bLength
    DESC_TYPE_ENDPOINT,             // bDescriptorType
    0x01,                           // bEndpointAddress; bit7=1 for IN, bits 3-0=1 for ep1
    EP_DESC_ATTR_TYPE_INT,          // bmAttributes, interrupt transfers
    0x40, 0x00,                     // wMaxPacketSize, 64 bytes
    0x0A                            // Polling interval: Every 10 ms	
};



BYTE code abromReportDescriptor[SIZEOF_REPORT_DESCRIPTOR] =
{
	0x06, 0xA0, 0xFF,		// Usage Page(vendor defined)
	0x09, 0xA5,				// Usage (vendor defined)
 	0xA1, 0x01, 			// Collection (Application)
	0x09, 0xA6, 			// Usage (vendor defined)
	
	// The Input Report (Sends 32 bytes of data to the host)
	0x09, 0xA7,				// Usage (vendor defined)
	0x15, 0x80,				// Logical Minimum(-127)
	0x25, 0x7F, 			// Logical Maximum (128)
	0x75, 0x08, 			// Report Size (8) bits
	0x95, 0x40, 			// Report Count (64) fields
	0x81, 0x02, 			// Input (Data, Variable, Absolute)

	// The Output Report (Sends 32 bytes of data to the device)
	0x09, 0xA9, 			// Usage (vendor defined)
	0x15, 0x80,				// Logical Minimum(-127)
	0x25, 0x7F, 			// Logical Maximum (128)
	0x75, 0x08, 			// Report Size (8) bits
	0x95, 0x40, 			// Report Count (64) fields
	0x91, 0x02, 			// Output (Data, Variable, Absolute)	
	0xC0					// End Collection
};

