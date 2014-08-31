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
 *    Note that this is just a "template" and that a number of the fields  *
 *    in the structure (flagged with "Updated at Run-Time") are actually   *
 *    modified on-the-fly at runtime in the InitializeUsbData function     *
 *    based on the VID/PID that was selected on s0123.                     *
 ***************************************************************************/

BYTE code abromDeviceDescriptor[SIZEOF_DEVICE_DESCRIPTOR] = 
	{
    SIZEOF_DEVICE_DESCRIPTOR,       // Length of this descriptor (12h bytes)
    DESC_TYPE_DEVICE,               // Type code of this descriptor (01h)
    0x10,0x01,                      // Release of USB spec (Rev 1.1)
    0x00,                	    // Device's base class code
    0,                              // Device's sub class code
    0,                              // Device's protocol type code
    EP0_MAX_PACKET_SIZE,            // End point 0's max packet size = 8
    0xFF,0xFF,                      // Vendor ID, UPDATED AT RUN-TIME
    0xFF, 0xFF,  		    // Product ID, UPDATED AT RUN-TIME
    0x00,0x01,                      // Revision level of device, UPDATED AT RUN-TIME
    1,                              // Index of manufacturer name string desc, UPDATED AT RUN-TIME
    2,                              // Index of product name string desc, UPDATED AT RUN-TIME
    3,                              // Index of serial number string desc, UPDATED AT RUN-TIME
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
    0xa0,                            // bmAttributes, bus power, support remote wakeup
    0x32,                            // Max. Power Consumption at 2mA unit

    // INTERFACE DESCRIPTOR (9 bytes)
    SIZEOF_INTERFACE_DESCRIPTOR,    // bLength
    DESC_TYPE_INTERFACE,            // bDescriptorType
    0x00,                           // bInterfaceNumber
    0x00,                           // bAlternateSetting
    1,                              // bNumEndpoints
    0x03,                           // bInterfaceClass: 3 = HID Device
    1,                              // bInterfaceSubClass: 1 = Boot Device
    1,                              // bInterfaceProtocol: 1 = Keyboard
    0x01,                           // iInterface

    // KEYBOARD HID DESCRIPTOR (9 bytes)
    0x09,     			    // bLength of HID descriptor
    0x21,             		    // HID Descriptor Type: 0x21 = Keyboard
    0x00,0x01,			    // HID Revision number 1.00
    0x00,			    // Target country, nothing specified (00h)
    0x01,			    // Number of HID classes to follow 
    0x22,			    // Report descriptor type
    SIZEOF_REPORT_DESCRIPTOR, 0x00, // Total length of report descriptor

    // ENDPOINT #1 INPUT DESCRIPTOR, (7 bytes)
    SIZEOF_ENDPOINT_DESCRIPTOR,     // bLength
    DESC_TYPE_ENDPOINT,             // bDescriptorType
    0x81,                           // bEndpointAddress; bit7=1 for IN, bits 3-0=1 for ep1
    EP_DESC_ATTR_TYPE_INT,          // bmAttributes, interrupt transfers
    0x08, 0x00,                     // wMaxPacketSize, 8 bytes
    0x0A,                           // Polling interval: Every 10 ms

	};

/***************************************************************************
 * Structure: Report Descriptor Structure                                  *
 * Programmer: Craig Steiner (csteiner@vaultbbs.com)                       *
 * Description: The abromConfigurationDescriptorGroup structure holds the  *
 *    data that makes up the Configuration descriptor for the keyboard     *
 *    device.                                                              *
 *                                                                         *
 * summary:                                                                *
 *   Report descriptor: 1. Main 2. Global 3. Local                         *
 *     Main: 1. Input 2. Output 3. Feature 4. Collection 5. End Collection *
 *     Global: influence all subsequent data field                         *
 *     Local : describe data fileds definded by next Main item             *
 *                                                                         *
 *   Collection: a meaningful grouping of Input, Output, Feature items     *
 *                                                                         *
 *   Application: A group of Main items that might be familiar to          *
 *   applications. It could also be used to identify item groups serving   *
 *   different purposes in a single device. Common examples are a          *
 *   keyboard or mouse. A keyboard with an integrated pointing device      *
 *   could be defined as two different application collections. Data       *
 *   reports are usually (but not necessarily) associated with             *
 *   application collections (one report ID per application).              *
 *                                                                         *
 *   Usage Page: Unsigned integer specifying the current Usage Page.       *
 *   Since a usage are 32 bit values, Usage Page items can be used to      *
 *   conserve space in a report descriptor by setting the high order       *
 *   16 bits of a subsequent usages. Any usage that follows which is       *
 *   defines 16 bits or less is interpreted as a Usage ID and              *
 *   concatenated with the Usage Page to form a 32 bit Usage.              *
 *                                                                         *
 ***************************************************************************/

BYTE code abromReportDescriptor[SIZEOF_REPORT_DESCRIPTOR] =
	{
	0x05, 0x01, 	        // Usage Page (Generic Desktop)
	0x09, 0x06,		// Usage (Keyboard)
	0xA1, 0x01,		// Collection (Application)

	0x05, 0x07,		// Usage Page (Key Codes)
	0x19, 0xE0,		// Usage Minimum (224)
	0x29, 0xE7,		// Usage Maximum (231)
	0x15, 0x00,		// Logical Minimum (0)
	0x25, 0x01,		// Logical Maximum (1)
	0x75, 0x01,		// Report Size (1)
	0x95, 0x08,		// Report Count (8)
	0x81, 0x02,		// Input (Data, Variable, Absolute) -- Modifier byte
	0x95, 0x01,		// Report Count (1)
	0x75, 0x08,		// Report Size (8)
	0x81, 0x03,		// (81 01) Input (Constant) -- Reserved byte
	
	0x95, 0x05,		// Report Count (5)
	0x75, 0x01,		// Report Size (1)
	0x05, 0x08,		// Usage Page (Page# for LEDs)
	0x19, 0x01,		// Usage Minimum (1)
	0x29, 0x05,		// Usage Maximum (5)
	0x91, 0x02,		// Output (Data, Variable, Absolute) -- LED report
	0x95, 0x01,		// Report Count (1)
	0x75, 0x03,		// Report Size (3)
	0x91, 0x03,		// (91 03) Output (Constant) -- LED report padding
	
	0x95, 0x06,		// Report Count (6)
	0x75, 0x08,		// Report Size (8)
	0x15, 0x00,		// Logical Minimum (0)
	0x25, 0x66,		// Logical Maximum(102)  // was 0x65

	0x05, 0x07,		// Usage Page (Key Codes)
	0x19, 0x00,		// Usage Minimum (0)
	0x29, 0x66,		// Usage Maximum (102) // was 0x65
	0x81, 0x00,		// Input (Data, Array) -- Key arrays (6 bytes)
	0xC0			// End Collection
	};
