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


BYTE code abromReportDescriptor[27] =
{
 0x05, 0x01, // USAGE_PAGE (Generic Desktop)
 0x09, 0x00, // USAGE (0)
 0xa1, 0x01, // COLLECTION (Application)
 0x15, 0x00, //     LOGICAL_MINIMUM (0)
 0x25, 0xff, //     LOGICAL_MAXIMUM (255)
 0x19, 0x01, //     USAGE_MINIMUM (1)
 0x29, 0x08, //     USAGE_MAXIMUM (8) 
 0x95, 0x08, //     REPORT_COUNT (8)
 0x75, 0x08, //     REPORT_SIZE (8)
 0x81, 0x02, //     INPUT (Data,Var,Abs)
 0x19, 0x01, //     USAGE_MINIMUM (1)
 0x29, 0x08, //     USAGE_MAXIMUM (8) 
 0x91, 0x02, //   OUTPUT (Data,Var,Abs)
 0xc0        // END_COLLECTION
};
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
    0x00,                	    	// Device's base class code
    0,                              // Device's sub class code
    0,                              // Device's protocol type code
    EP0_MAX_PACKET_SIZE,            // End point 0's max packet size = 8
    0x88,0x88,                      // Vendor ID: Texas Instruments
    0x06, 0x00,  		    		// Product ID: UCD9110 EVM
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

BYTE code abromConfigurationDescriptorGroup[] =
	{
    // CONFIGURATION DESCRIPTOR (9 bytes)
    SIZEOF_CONFIG_DESCRIPTOR,        // bLength
    DESC_TYPE_CONFIG,                // bDescriptorType
	9+9+9+7+7,//wTotalLength low byte
	0x00,//wTotalLength high byte
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
	0x00, 							// bInterfaceSubClass: Boot 
	0x00,							// bInterfaceProtocol: Keyboard
    0x00,                           // iInterface

    // KEYBOARD HID DESCRIPTOR (9 bytes)
    0x09,     			            // bLength of HID descriptor
    0x21,             		        // HID Descriptor Type:
    0x10,0x01,			            // HID Revision number 1.00
    0x21,			                // Target country, USA
    0x01,			                // Number of HID classes to follow 
    0x22,			                // Report descriptor type
	sizeof(abromReportDescriptor)&0xff,
	(sizeof(abromReportDescriptor)>>8)&0xff,
    // ENDPOINT #1 INPUT DESCRIPTOR, (7 bytes)
    SIZEOF_ENDPOINT_DESCRIPTOR,     // bLength
    DESC_TYPE_ENDPOINT,             // bDescriptorType
    0x81,                           // bEndpointAddress; bit7=1 for IN, bits 3-0=1 for ep1
    EP_DESC_ATTR_TYPE_INT,          // bmAttributes, interrupt transfers
    0x40, 0x00,                     // wMaxPacketSize, 64 bytes
    0x0A, 							// Polling interval: Every 10 ms
	//ENDPOINT #1 OUTPUT DESCRIPTOR,(7 bytes)
	SIZEOF_ENDPOINT_DESCRIPTOR,//bLength
	DESC_TYPE_ENDPOINT,//bDescriptorType字段。端点描述符编号为0x05。
	0x01,//bEndpointAddress; bit7=0 for OUT, bits 3-0=1 for ep1 			
	EP_DESC_ATTR_TYPE_INT,//bmAttributes字段。D1~D0为端点传输类型选择。
	0x40,0x00,//wMaxPacketSize字段。该端点的最大包长。端点1的最大包长为16字节。
	0x0A//bInterval字段。端点查询的时间，我们设置为10个帧时间，即10ms。
};




BYTE code ManufacturerStringDescriptor[]={
10,         //该描述符的长度为10字节
0x03,       //字符串描述符的类型编码为0x03
0x31, 0x72, //爱
0xfd, 0x56, //国
0x31, 0x72, //爱
0x5a, 0x51, //党
//注：请将最后一个多余的逗号删除
};
BYTE code LanguageId[4]=
{
0x04,//length
0x03,//string descriptor
0x09,//0x0409:America
0x04
};
BYTE code ProductStringDescriptor[]={
10,         //该描述符的长度为10字节
0x03,       //字符串描述符的类型编码为0x03
0x31, 0x72, //爱
0xfd, 0x56, //国
0x31, 0x72, //爱
0x5a, 0x51, //党
//注：请将最后一个多余的逗号删除
//注：请将最后一个多余的逗号删除
};
BYTE code SerialNumberStringDescriptor[]={
16,         //该描述符的长度为16字节
0x03,       //字符串描述符的类型编码为0x03
0xa0, 0x52, //加
0x65, 0x51, //入
0x2d, 0x4e, //中
0xfd, 0x56, //国
0x71, 0x51, //共
0xa7, 0x4e, //产
0x5a, 0x51, //党
//注：请将最后一个多余的逗号删除
};