/******************************************************************************
 *                         VAULT INFORMATION SERVICES                         *
 *                          TEXAS INSTRUMENTS, INC.                           *
 *                                                                            *
 *                              USB Header File                               *
 *                                                                            *
 *----------------------------------------------------------------------------*
 * Programmed by: Lobo Tai (lobotai@ti.com)                                   *
 * Develop Date:  30/Sep/2000                                                 *
 *----------------------------------------------------------------------------*
 * Description: This header file defines constants that relate to the         *
 *   USB standard, such as request values, descriptor types, etc.  Constants  *
 *   that are specific to the TUSB2136 architecture are contained in          *
 *   tusb2136.h.                                                              *
 ******************************************************************************/

#ifndef _USB_H_
#define _USB_H_

#ifdef __cplusplus
extern "C"
{
#endif

// DEVICE_REQUEST Structure
typedef struct _tDEVICE_REQUEST
{
    BYTE    bmRequestType;              // See bit definitions below
    BYTE    bRequest;                   // See value definitions below
    BYTE    bValueL;                    // Meaning varies with request type
    BYTE    bValueH;                    // Meaning varies with request type
    BYTE    bIndexL;                    // Meaning varies with request type
    BYTE    bIndexH;                    // Meaning varies with request type
    BYTE    bLengthL;                   // Number of bytes of data to transfer (LSByte)
    BYTE    bLengthH;                   // Number of bytes of data to transfer (MSByte)
} tDEVICE_REQUEST, *ptDEVICE_REQUEST;

// device descriptor structure
typedef struct _tDEVICE_DESCRIPTOR
{
    BYTE    bLength;                // Length of this descriptor (12h bytes)
    BYTE    bDescriptorType;        // Type code of this descriptor (01h)
    WORD    bcdUsb;                 // Release of USB spec (0210h = rev 2.10)
    BYTE    bDeviceClass;           // Device's base class code
    BYTE    bDeviceSubClass;        // Device's sub class code
    BYTE    bDeviceProtocol;        // Device's protocol type code
    BYTE    bMaxPacketSize0;        // End point 0's max packet size (8/16/32/64)
    WORD    wIdVendor;              // Vendor ID for device
    WORD    wIdProduct;             // Product ID for device
    WORD    wBcdDevice;             // Revision level of device
    BYTE    wManufacturer;          // Index of manufacturer name string desc
    BYTE    wProduct;               // Index of product name string desc
    BYTE    wSerialNumber;          // Index of serial number string desc
    BYTE    bNumConfigurations;     // Number of configurations supported
} tDEVICE_DESCRIPTOR, *ptDEVICE_DESCRIPTOR;

// configuration descriptor structure
typedef struct _tCONFIG_DESCRIPTOR
{
    BYTE    bLength;                // Length of this descriptor (9h bytes)
    BYTE    bDescriptorType;        // Type code of this descriptor (02h)
    WORD    wTotalLength;           // Size of this config desc plus all interface,
                                    // endpoint, class, and vendor descriptors
    BYTE    bNumInterfaces;         // Number of interfaces in this config
    BYTE    bConfigurationValue;    // Value to use in SetConfiguration command
    BYTE    bConfiguration;         // Index of string desc describing this config
    BYTE    bAttributes;            // See CFG_DESC_ATTR_xxx values below
    BYTE    bMaxPower;              // Power used by this config in 2mA units
} tCONFIG_DESCRIPTOR, *ptCONFIG_DESCRIPTOR;

// interface descriptor structure
typedef struct _tINTERFACE_DESCRIPTOR
{
    BYTE    bLength;                // Length of this descriptor (9h bytes)
    BYTE    bDescriptorType;        // Type code of this descriptor (04h)
    BYTE    bInterfaceNumber;       // Zero based index of interface in the configuration
    BYTE    bAlternateSetting;      // Alternate setting number of this interface
    BYTE    bNumEndpoints;          // Number of endpoints in this interface
    BYTE    bInterfaceClass;        // Interface's base class code
    BYTE    bInterfaceSubClass;     // Interface's sub class code
    BYTE    bInterfaceProtocol;     // Interface's protocol type code
    BYTE    bInterface;             // Index of string desc describing this interface
} tINTERFACE_DESCRIPTOR, *ptINTERFACE_DESCRIPTOR;

// endpoint descriptor structure
typedef struct _tENDPOINT_DESCRIPTOR
{
    BYTE    bLength;                // Length of this descriptor (7h bytes)
    BYTE    bDescriptorType;        // Type code of this descriptor (05h)
    BYTE    bEndpointAddress;       // See EP_DESC_ADDR_xxx values below
    BYTE    bAttributes;            // See EP_DESC_ATTR_xxx value below
    WORD    wMaxPacketSize;         // Max packet size of endpoint
    BYTE    bInterval;              // Polling interval of endpoint in milliseconds
} tENDPOINT_DESCRIPTOR, *tpENDPOINT_DESCRIPTOR;


/*----------------------------------------------------------------------------+
| Constant Definition                                                         |
+----------------------------------------------------------------------------*/
#define  	FNC_VID          0x0451
#define     FNC_PID			 0x5f01
#define     FNC_REVISION     0x0100 // revision 1.00
// #define 	MFG_DESCRIPTION   "Texas Instruments"
// #define 	PROD_DESCRIPTION  "Texas Instruments UCD9110 EVM"
// #define 	SERIAL_NUMBER     "Texas Instruments UCD9110 EVM Engineering"

#define USB_SPEC_REV_BCD        0x0101  /*BCD coded rev level of USB spec*/
#define SIZEOF_DEVICE_REQUEST   0x08

//  Bit definitions for DEVICE_REQUEST.bmRequestType
//  Bit 7:   Data direction
#define USB_REQ_TYPE_OUTPUT     0x00    // 0 = Host sending data to device
#define USB_REQ_TYPE_INPUT      0x80    // 1 = Device sending data to host

//  Bit 6-5: Type
#define USB_REQ_TYPE_MASK       0x60    // Mask value for bits 6-5
#define USB_REQ_TYPE_STANDARD   0x00    // 00 = Standard USB request
#define USB_REQ_TYPE_CLASS      0x20    // 01 = Class specific
#define USB_REQ_TYPE_VENDOR     0x40    // 10 = Vendor specific

//  Bit 4-0: Recipient
#define USB_REQ_TYPE_RECIP_MASK 0x1F    // Mask value for bits 4-0
#define USB_REQ_TYPE_DEVICE     0x00    // 00000 = Device
#define USB_REQ_TYPE_INTERFACE  0x01    // 00001 = Interface
#define USB_REQ_TYPE_ENDPOINT   0x02    // 00010 = Endpoint
#define USB_REQ_TYPE_OTHER      0x03    // 00011 = Other

//  Values for DEVICE_REQUEST.bRequest
// Standard Device Requests
#define USB_REQ_GET_STATUS              0
#define USB_REQ_CLEAR_FEATURE           1
#define USB_REQ_SET_FEATURE             3
#define USB_REQ_SET_ADDRESS             5
#define USB_REQ_GET_DESCRIPTOR          6
#define USB_REQ_SET_DESCRIPTOR          7
#define USB_REQ_GET_CONFIGURATION       8
#define USB_REQ_SET_CONFIGURATION       9
#define USB_REQ_GET_INTERFACE           10
#define USB_REQ_SET_INTERFACE           11
#define USB_REQ_SYNCH_FRAME             12

// HID CLASS Requests
#define USB_REQ_GET_REPORT				0x01
#define USB_REQ_GET_IDLE				0x02
#define USB_REQ_SET_REPORT				0x09
#define USB_REQ_SET_IDLE				0x0A
#define USB_REQ_SET_PROTOCOL            0x0B
#define USB_REQ_GET_PROTOCOL            0x03

//  Descriptor Type Values
#define DESC_TYPE_DEVICE                1       // Device Descriptor (Type 1)
#define DESC_TYPE_CONFIG                2       // Configuration Descriptor (Type 2)
#define DESC_TYPE_STRING                3       // String Descriptor (Type 3)
#define DESC_TYPE_INTERFACE             4       // Interface Descriptor (Type 4)
#define DESC_TYPE_ENDPOINT              5       // Endpoint Descriptor (Type 5)
#define DESC_TYPE_HID					0x21    // HID Descriptor (Type 0x21)
#define DESC_TYPE_REPORT				0x22    // Report Descriptor (Type 0x22)
#define DESC_TYPE_PHYSICAL				0x23	// Physical Descriptor (Type 0x23)

#define DESC_TYPE_HUB                   0x29    // Hub Descriptor (Type 6)

//  Feature Selector Values
#define FEATURE_REMOTE_WAKEUP           1       // Remote wakeup (Type 1)
#define FEATURE_ENDPOINT_STALL          0       // Endpoint stall (Type 0)

// Device Status Values
#define DEVICE_STATUS_REMOTE_WAKEUP     0x02
#define DEVICE_STATUS_SELF_POWER        0x01

//  DEVICE_DESCRIPTOR structure
#define SIZEOF_DEVICE_DESCRIPTOR        0x12
#define OFFSET_DEVICE_DESCRIPTOR_VID_L  0x08
#define OFFSET_DEVICE_DESCRIPTOR_VID_H  0x09
#define OFFSET_DEVICE_DESCRIPTOR_PID_L  0x0A
#define OFFSET_DEVICE_DESCRIPTOR_PID_H  0x0B
#define OFFSET_DEVICE_DESCRIPTOR_VER_L 	0x0C
#define OFFSET_DEVICE_DESCRIPTOR_VER_H 	0x0D
#define OFFSET_CONFIG_DESCRIPTOR_POWER  0x07
#define OFFSET_CONFIG_DESCRIPTOR_CURT   0x08
#define OFFSET_DEVICE_DESCRIPTOR_IMFG   0x0E
#define OFFSET_DEVICE_DESCRIPTOR_IPROD  0x0F
#define OFFSET_DEVICE_DESCRIPTOR_ISN    0x10

//  CONFIG_DESCRIPTOR structure
#define SIZEOF_CONFIG_DESCRIPTOR 0x09

//  Bit definitions for CONFIG_DESCRIPTOR.bmAttributes
#define CFG_DESC_ATTR_SELF_POWERED  0x40    // Bit 6: If set, device is self powered
#define CFG_DESC_ATTR_BUS_POWERED   0x80    // Bit 7: If set, device is bus powered
#define CFG_DESC_ATTR_REMOTE_WAKE   0x20    // Bit 5: If set, device supports remote wakeup

//  INTERFACE_DESCRIPTOR structure
#define SIZEOF_INTERFACE_DESCRIPTOR 0x09

//  KEYBOARD HID DESCRIPTOR structure
#define SIZEOF_KEYBD_HID_DESCRIPTOR 0x09

//  ENDPOINT_DESCRIPTOR structure
#define SIZEOF_ENDPOINT_DESCRIPTOR 0x07


#define SIZEOF_REPORT_DESCRIPTOR 	63


//  Bit definitions for EndpointDescriptor.EndpointAddr
#define EP_DESC_ADDR_EP_NUM     0x0F    // Bit 3-0: Endpoint number
#define EP_DESC_ADDR_DIR_IN     0x80    // Bit 7: Direction of endpoint, 1/0 = In/Out

//  Bit definitions for EndpointDescriptor.EndpointFlags
#define EP_DESC_ATTR_TYPE_MASK  0x03    // Mask value for bits 1-0
#define EP_DESC_ATTR_TYPE_CONT  0x00    // Bit 1-0: 00 = Endpoint does control transfers
#define EP_DESC_ATTR_TYPE_ISOC  0x01    // Bit 1-0: 01 = Endpoint does isochronous transfers
#define EP_DESC_ATTR_TYPE_BULK  0x02    // Bit 1-0: 10 = Endpoint does bulk transfers
#define EP_DESC_ATTR_TYPE_INT   0x03    // Bit 1-0: 11 = Endpoint does interrupt transfers

// The following section defines the HID Usage codes for each defined key on the
// keyboard.  These are defined in the HID "Usage Tag" (HUT) specification.

#define usbUsageReserved			0x00
#define usbUsageErrorRollOver		0x01
#define usbUsagePOSTFail			0x02
#define usbUsageErrorUndefined		0x03
#define usbUsageA					0x04
#define usbUsageB					0x05
#define usbUsageC					0x06
#define	usbUsageD					0x07
#define usbUsageE					0x08
#define usbUsageF					0x09
#define usbUsageG					0x0A
#define usbUsageH					0x0B
#define usbUsageI					0x0C
#define usbUsageJ					0x0D
#define usbUsageK					0x0E
#define usbUsageL					0x0F
#define usbUsageM					0x10
#define usbUsageN					0x11
#define usbUsageO					0x12
#define usbUsageP					0x13
#define usbUsageQ					0x14
#define usbUsageR					0x15
#define usbUsageS					0x16
#define usbUsageT					0x17
#define usbUsageU					0x18
#define usbUsageV					0x19
#define usbUsageW					0x1A
#define usbUsageX					0x1B
#define usbUsageY					0x1C
#define usbUsageZ					0x1D
#define usbUsage1					0x1E
#define usbUsage2					0x1F
#define usbUsage3					0x20
#define usbUsage4					0x21
#define usbUsage5					0x22
#define usbUsage6					0x23
#define usbUsage7					0x24
#define usbUsage8					0x25
#define usbUsage9					0x26
#define usbUsage0					0x27
#define usbUsageEnter				0x28
#define usbUsageEscape				0x29
#define usbUsageBackspace			0x2A
#define usbUsageTab					0x2B
#define usbUsageSpacebar			0x2C
#define usbUsageMinus				0x2D
#define usbUsageEqual				0x2E
#define usbUsageLeftBracket			0x2F
#define usbUsageRightBracket		0x30
#define usbUsageBackslash			0x31
#define usbUsageVerticalBar			0x32
#define usbUsageSemicolon			0x33
#define usbUsageApostrophe			0x34
#define usbUsageTilde				0x35
#define usbUsageComma				0x36
#define usbUsagePeriod				0x37
#define usbUsageSlash				0x38
#define usbUsageCapsLock			0x39
#define usbUsageF1					0x3A
#define usbUsageF2					0x3B
#define usbUsageF3					0x3C
#define usbUsageF4					0x3D
#define usbUsageF5					0x3E
#define usbUsageF6					0x3F
#define usbUsageF7					0x40
#define usbUsageF8					0x41
#define usbUsageF9					0x42
#define usbUsageF10					0x43
#define usbUsageF11					0x44
#define usbUsageF12					0x45
#define usbUsagePrintScreen			0x46
#define usbUsageScrollLock			0x47
#define usbUsagePause				0x48
#define usbUsageInsert				0x49
#define usbUsageHome				0x4A
#define usbUsagePageUp				0x4B
#define usbUsageDeleteForward		0x4C
#define usbUsageEnd					0x4D
#define usbUsagePageDown			0x4E
#define usbUsageRightArrow			0x4F
#define usbUsageLeftArrow			0x50
#define usbUsageDownArrow			0x51
#define usbUsageUpArrow				0x52
#define usbUsageKeypadNumlock		0x53
#define usbUsageKeypadSlash			0x54
#define usbUsageKeypadAsterisk		0x55
#define usbUsageKeypadMinus			0x56
#define usbUsageKeypadPlus			0x57
#define usbUsageKeypadEnter			0x58
#define usbUsageKeypad1				0x59
#define usbUsageKeypad2				0x5A
#define usbUsageKeypad3				0x5B
#define usbUsageKeypad4				0x5C
#define usbUsageKeypad5				0x5D
#define usbUsageKeypad6				0x5E
#define usbUsageKeypad7				0x5F
#define usbUsageKeypad8				0x60
#define usbUsageKeypad9				0x61
#define usbUsageKeypad0				0x62
#define usbUsageKeypadPeriod		0x63
#define usbUsageNonUsBackslash		0x64
#define usbUsageWindowsKey			0x65
#define usbUsagePower				0x66
#define usbUsageKeypadEqual			0x67
#define usbUsageF13					0x68
#define usbUsageF14					0x69
#define usbUsageF15					0x6A
#define usbUsageF16					0x6B
#define usbUsageF17					0x6C
#define usbUsageF18					0x6D
#define usbUsageF19					0x6E
#define usbUsageF20					0x6F
#define usbUsageF21					0x70
#define usbUsageF22					0x71
#define usbUsageF23					0x72
#define usbUsageF24					0x73
#define usbUsageExecute				0x74
#define usbUsageHelp				0x75
#define usbUsageMenu				0x76
#define usbUsageSelect				0x77
#define usbUsageStop				0x78
#define usbUsageAgain				0x79
#define usbUsageUndo				0x7A
#define usbUsageCut					0x7B
#define usbUsageCopy				0x7C
#define usbUsagePaste				0x7D
#define usbUsageFind				0x7E
#define usbUsageMute				0x7F
#define usbUsageVolumeUp			0x80
#define usbUsageVolumneDown			0x81
#define usbUsageLockingCapsLock		0x82
#define usbUsageLockingNumLock		0x83
#define usbUsageLockingScrollLock	0x84
#define usbUsageKeypadComma			0x85
#define usbUsageAS400KeypadEqual	0x86
#define usbUsageInternational1		0x87
#define usbUsageInternational2		0x88
#define usbUsageInternational3		0x89
#define usbUsageInternational4		0x8A
#define usbUsageInternational5		0x8B
#define usbUsageInternational6		0x8C
#define usbUsageInternational7		0x8D
#define usbUsageInternational8		0x8E
#define usbUsageInternational9		0x8F
#define usbUsageLang1				0x90
#define usbUsageLang2				0x91
#define usbUsageLang3				0x92
#define usbUsageLang4				0x93
#define usbUsageLang5				0x94
#define usbUsageLang6				0x95
#define usbUsageLang7				0x96
#define usbUsageLang8				0x97
#define usbUsageLang9				0x98
#define usbUsageAlternateErase		0x99
#define usbUsageSysReq				0x9A
#define usbUsageCancel				0x9B
#define usbUsageClear				0x9C
#define usbUsagePrior				0x9D
#define usbUsageReturn				0x9E
#define usbUsageSeparator			0x9F
#define usbUsageOut					0xA0
#define usbUsageOper				0xA1
#define usbUsageClearAgain			0xA2
#define usbUsageCrSelProps			0xA3
#define usbUsageExSel				0xA4
#define usbUsageLeftControl			0xE0
#define usbUsageLeftShift			0xE1
#define usbUsageLeftAlt				0xE2
#define usbUsageLeftGUI				0xE3
#define usbUsageRightControl		0xE4
#define usbUsageRightShift			0xE5
#define usbUsageRightAlt			0xE6
#define usbUsageRightGUI			0xE7


#ifdef __cplusplus
}
#endif
#endif /* _USB_H */



