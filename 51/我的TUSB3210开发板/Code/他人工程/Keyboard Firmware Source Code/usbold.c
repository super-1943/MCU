/******************************************************************************
 *                         VAULT INFORMATION SERVICES                         *
 *                          TEXAS INSTRUMENTS, INC.                           *
 *----------------------------------------------------------------------------*
 *                     "USB Handler for TUSB2136 Demo App"                    *
 *                                                                            * 
 * Programmed by: Craig Steiner, VIS (csteiner@vaultbbs.com)                  * 
 * Develop Date:  30/Sep/2000                                                 *  
 *----------------------------------------------------------------------------*
 * Description: This module is a component of the TUSB2136 Demo App.  It      *
 *   handles all USB-related operation functions such as USB request          *
 *   handlers, interrupts, etc.  Functions related to USB initialization      *
 *   may be found in usbinit.c                                                * 
 ******************************************************************************/

#include <io51.h>
#include "types.h"
#include "tusb2136.h"
#include "usb.h"
#include "delay.h"

/***************************************************************************
 * Section:    TUSB2136 Segment Definitions                                *
 * Programmer: Craig Steiner (csteiner@vaultbbs.com)                       *
 * Description: This section of code assigns certain variables to defined  *
 *    mapped memory addresses in the TUSB2136.  The mapped memory symbols  *
 *    used in the dataset() pragmas are found in the .XCL file for the     * 
 *    project.                                                             *  
 ***************************************************************************/

#pragma memory = dataseg(TUSB2136_SETUPPACKET_SEG)
tDEVICE_REQUEST tSetupPacket;
#pragma memory = default

#pragma memory = dataseg(TUSB2136_EP0_EDB_SEG)
tEDB0 tEndPoint0DescriptorBlock;
#pragma memory = default

#pragma memory = dataseg(TUSB2136_IEP_EDB_SEG)
tEDB tInputEndPointDescriptorBlock[3];
#pragma memory = default

#pragma memory = dataseg(TUSB2136_OEP_EDB_SEG)
tEDB tOutputEndPointDescriptorBlock[3];
#pragma memory = default

#pragma memory = dataseg(TUSB2136_IEP0BUFFER_SEG)
BYTE abIEP0Buffer[EP0_MAX_PACKET_SIZE];
#pragma memory = default

#pragma memory = dataseg(TUSB2136_OEP0BUFFER_SEG)
BYTE abOEP0Buffer[EP0_MAX_PACKET_SIZE];
#pragma memory = default

#pragma memory = dataseg(TUSB2136_DESC_SEG)             // 0xfe00
BYTE abDescriptor[SIZEOF_DEVICE_DESCRIPTOR];
//BYTE abConfigurationDescriptorGroup[SIZEOF_BOOTCODE_CONFIG_DESC_GROUP];
//BYTE abStringDescriptor[SIZEOF_BOOTCODE_STRING_DESC_GROUP];
#pragma memory = default

#pragma memory = dataseg(TUSB2136_OEP1_X_BUFFER_SEG)    // 0xfd80
BYTE pbXBufferAddress[EP_MAX_PACKET_SIZE];
#pragma memory = default

#pragma memory = dataseg(TUSB2136_OEP1_Y_BUFFER_SEG)    // 0xfdc0
BYTE pbYBufferAddress[EP_MAX_PACKET_SIZE];
#pragma memory = default

/***************************************************************************
 * Section:    Declarations                                                *
 * Programmer: Craig Steiner (csteiner@vaultbbs.com)                       *
 * Description: This section of the code declares global and external      *
 *    variables, as well as functions, etc.                                *
 ***************************************************************************/

// EXTERNAL DECLARATIONS 
extern BYTE code abromReportDescriptor[SIZEOF_REPORT_DESCRIPTOR];
extern void setLEDs(BYTE bData); // From 8255.c
extern unsigned char intFlags; // From keyboard.c
extern unsigned char otherFlags; // From keyboard.c
extern void IEP1InterruptHandler(void); // From keyboard.c
extern void UsbReset(void); // From usbinit.c
extern void OEP0SetLEDs(void);
extern BYTE bLED;
extern struct FUNCDEF_STRUCT code funcDefs[17]; // From vidpid.c
extern unsigned char fncOffset; // From vidpid.c
extern BYTE code abromReportDescriptor[SIZEOF_REPORT_DESCRIPTOR];
extern BYTE code abromConfigurationDescriptorGroup[SIZEOF_BOOTCODE_CONFIG_DESC_GROUP];
extern BYTE code abromDeviceDescriptor[SIZEOF_DEVICE_DESCRIPTOR];
extern BYTE strlen(char *string); // From support.c



// GLOBAL VARIABLE DECLARATIONS

BYTE deviceReady = FALSE;		// Indicates whether the device has been
								// properly initialized on the USB bus.
BYTE bSuspended = FALSE;		// Indicates whether the device is suspended or not
BYTE bStatusAction;				// Indicates the current state of sending
								// receiving data packets.
BYTE bUsbDeviceAddress;			// The device's USB address.
WORD wBytesRemainingOnIEP0;     // For endpoint zero transmitter only
                                // Holds count of bytes remaining to be
                                // transmitted by endpoint 0.  A value
                                // of 0 means that a 0-length data packet
                                // A value of 0xFFFF means that transfer
                                // is complete.
BOOL bHostAskMoreDataThanAvailable;
                                // If host ask more data then TUSB2136 has
                                // It will send one zero-length packet
                                // if the asked lenght is a multiple of
                                // max. size of endpoint 0
PBYTE pbIEP0Buffer;             // A buffer pointer to input end point 0
                                // Data sent back to host is copied from
                                // this pointed memory location
BYTE bConfigurationNumber = 0;  // Set to 1 when USB device has been
                                // configured, set to 0 when unconfigured
BYTE bInterfaceNumber = 0;		// The interface number selected
WORD wDeviceFeatures = 0;		// The device features
WORD wBytesRemainingOnOEP0;     // For endpoint zero transmitter only
                                // Holds count of bytes remaining to be
                                // received by endpoint 0.  A value
                                // of 0 means that a 0-length data packet
                                // A value of 0xFFFF means that transfer
PBYTE pbOEP0Buffer;             // A buffer pointer to output end point 0
                                // Data sent from host is copied to
                                // this pointed memory location
                                // is complete.

#define usbClearOEP0ByteCount tEndPoint0DescriptorBlock.bOEPBCNT = 0x00
#define usbStallOEP0          tEndPoint0DescriptorBlock.bOEPCNFG |= EPCNF_STALL

void usbReceiveDataPacketOnEP0(PBYTE pbBuffer);
void usbStallEndpoint0(void);
void usbSendZeroLengthPacketOnIEP0(void);
void usbSendNextPacketOnIEP0(void);
void usbSendDataPacketOnEP0(PBYTE pbBuffer);




/***************************************************************************
 * Section:    USB REQUEST FUNCTIONS                                       *
 * Programmer: Craig Steiner (csteiner@vaultbbs.com) based on code by      *
 *             Lobo Tai (lobotai@ti.com)                                   *
 * Description: The functions in this section of code are called by the    *
 *    usbDecodeAndProcessUsbRequest function when a Setup packet is        *
 *    received.  Each function handles a specific USB/Class/Endpoint       *
 *    function.                                                            *
 ***************************************************************************/

// The Get/Set configuration functions allow the host to select one of various
// configurations that the keyboard may support.  This firmware only supports
// one configuration, but the following functions allow the firmware to accept
// any given configuration number.  The code, as-is, will function identically
// in any given configuration, but additional configurations may be supported
// by simply adding support for the configurations, presumably in keyboard.c.

void usbGetConfiguration(void)
{
    wBytesRemainingOnIEP0 = 1;
	usbSendDataPacketOnEP0((PBYTE) &bConfigurationNumber);
}

void usbSetConfiguration(void)
{
    usbStallOEP0;
    bConfigurationNumber = tSetupPacket.bValueL;
    usbSendZeroLengthPacketOnIEP0();
}

// The Set_Report request is sent by the host to a typical HID device,
// such as this keyboard, to update the LEDs that correspond to the
// scroll lock, caps lock, and num lock.  When the Set_Report setup
// packet is received, we initiate a "Receive Data Packet" sequence
// since the actual 1-byte data value will be in the following
// packet on OEP0.  Thus we initicate that we will receive 1 byte
// (since the LED data is contained in a single byte) and we
// instruct the receive routine to receive the data at the address
// at which the bLED variable is located.  Thus bLed will automatically
// be updated with the new value after the transfer is completed.

void usbSetReport(void)
{
    wBytesRemainingOnOEP0 = 1;
    usbReceiveDataPacketOnEP0((PBYTE) &bLED);
}

// The following functions are called at initial device enumeration, and are used
// to obtain the device, configuration, and string descriptors from the
// device.

void usbGetDeviceDescriptor(void)
{
	BYTE bTemp;
	// Copy the DEVICE DESCRIPTOR from program "ROM" to XRAM
    for(bTemp=0;bTemp<SIZEOF_DEVICE_DESCRIPTOR;bTemp++)
        abDescriptor[bTemp] = abromDeviceDescriptor[bTemp];

	// Modify the FUNCTION VID/PID and firmware version using our selected value
	abDescriptor[OFFSET_DEVICE_DESCRIPTOR_VID_L] = (funcDefs[fncOffset].fncVID & 0xFF);
	abDescriptor[OFFSET_DEVICE_DESCRIPTOR_VID_H] = ((funcDefs[fncOffset].fncVID & 0xFF00) >> 8);	
	abDescriptor[OFFSET_DEVICE_DESCRIPTOR_PID_L] = (funcDefs[fncOffset].fncPID & 0xFF);
	abDescriptor[OFFSET_DEVICE_DESCRIPTOR_PID_H] = ((funcDefs[fncOffset].fncPID & 0xFF00) >> 8);	
	abDescriptor[OFFSET_DEVICE_DESCRIPTOR_VER_L] = (funcDefs[fncOffset].fncRevision & 0xFF);
	abDescriptor[OFFSET_DEVICE_DESCRIPTOR_VER_H] = ((funcDefs[fncOffset].fncRevision & 0xFF00) >> 8);	
	if(funcDefs[fncOffset].mfgDescription == NULL )
		abDescriptor[OFFSET_DEVICE_DESCRIPTOR_IMFG] = 0x00;
	if(funcDefs[fncOffset].prodDescription == NULL )
		abDescriptor[OFFSET_DEVICE_DESCRIPTOR_IPROD] = 0x00;
	if(funcDefs[fncOffset].serialNumber == NULL )
		abDescriptor[OFFSET_DEVICE_DESCRIPTOR_ISN] = 0x00;

    usbClearOEP0ByteCount;
    wBytesRemainingOnIEP0 = SIZEOF_DEVICE_DESCRIPTOR;
    usbSendDataPacketOnEP0((PBYTE)&abDescriptor);
    
    // Once the Device Descriptor has been sent, the device can essentially
    // function.  Thus we enable the deviceReady variable so that the main
    // code in keyboard.c knows that it can begin the service loop.
	deviceReady = TRUE;    
}

void usbGetHIDDescriptor(void)
{
	BYTE bTemp;
	// Copy the DEVICE DESCRIPTOR from program "ROM" to XRAM
    for(bTemp=0;bTemp<SIZEOF_DEVICE_DESCRIPTOR;bTemp++)
        abDescriptor[bTemp] = abromConfigurationDescriptorGroup[SIZEOF_CONFIG_DESCRIPTOR+SIZEOF_INTERFACE_DESCRIPTOR + bTemp];

    usbClearOEP0ByteCount;
    wBytesRemainingOnIEP0 = SIZEOF_KEYBD_HID_DESCRIPTOR;
    usbSendDataPacketOnEP0((PBYTE)&abDescriptor);
}

void usbGetConfigurationDescriptor(void)
{
	BYTE bTemp;
	// Copy the DEVICE DESCRIPTOR from program "ROM" to XRAM
    for(bTemp=0;bTemp<SIZEOF_BOOTCODE_CONFIG_DESC_GROUP;bTemp++)
        abDescriptor[bTemp] = abromConfigurationDescriptorGroup[bTemp];

    usbClearOEP0ByteCount;
    wBytesRemainingOnIEP0 = SIZEOF_BOOTCODE_CONFIG_DESC_GROUP;
    usbSendDataPacketOnEP0((PBYTE)&abDescriptor);
}

void usbGetStringDescriptor(void)
{
//    WORD bIndex;
   	BYTE bTemp;
   	BYTE stringOffset = 0;

    usbClearOEP0ByteCount;

	switch(tSetupPacket.bValueL)
		{
		case 0: // LANGUAGE ID
			abDescriptor[0] = 4; // Length of language descriptor ID
			abDescriptor[1] = 3; // LANGID tag
			abDescriptor[2] = 0x09; // Low byte of 0x0409 (English)
			abDescriptor[3] = 0x04; // High byte of 0x0409 (English)
			break;
		case 1: // MANUFACTURER DESCRIPTION
			abDescriptor[stringOffset++] = strlen(funcDefs[fncOffset].mfgDescription) * 2 + 2; // Length of this string
			abDescriptor[stringOffset++] = DESC_TYPE_STRING; // String descriptor type
			for(bTemp = 0; bTemp < strlen(funcDefs[fncOffset].mfgDescription);bTemp++)
				{
				abDescriptor[stringOffset++] = funcDefs[fncOffset].mfgDescription[bTemp]; // Insert the character from the string
				abDescriptor[stringOffset++] = 0x00; // Insert a trailing 00h for Unicode representation
				}
			break;
		case 2: // PRODUCT DESCRIPTION
			abDescriptor[stringOffset++] = strlen(funcDefs[fncOffset].prodDescription) * 2 + 2;  // Length of this string
			abDescriptor[stringOffset++] = DESC_TYPE_STRING; // String descriptor type
			for(bTemp = 0; bTemp < strlen(funcDefs[fncOffset].prodDescription);bTemp++)
				{
				abDescriptor[stringOffset++] = funcDefs[fncOffset].prodDescription[bTemp]; // Insert the character from the string
				abDescriptor[stringOffset++] = 0x00; // Insert a trailing 00h for Unicode representation
				}
			break;
		case 3: // SERIAL NUMBER
			abDescriptor[stringOffset++] = strlen(funcDefs[fncOffset].serialNumber) * 2 + 2;  // Length of this string
			abDescriptor[stringOffset++] = DESC_TYPE_STRING; // String descriptor type
			for(bTemp = 0; bTemp < strlen(funcDefs[fncOffset].serialNumber);bTemp++)
				{
				abDescriptor[stringOffset++] = funcDefs[fncOffset].serialNumber[bTemp]; // Insert the character from the string	
				abDescriptor[stringOffset++] = 0x00; // Insert a trailing 00h for Unicode representation
				}
			break;
		default:
				break;
		}

#ifdef XX
    bIndex = 0x00;
    while(tSetupPacket.bValueL-- >  0x00) 
    	bIndex += abStringDescriptor[bIndex];

	// Copy the STRING DESCRIPTOR from program "ROM" to XRAM
	bStrLen = 
    for(bTemp=0;bTemp<SIZEOF_BOOTCODE_CONFIG_DESC_GROUP;bTemp++)
        abDescriptor[bTemp] = abromConfigurationDescriptorGroup[bTemp];
#endif    	
    wBytesRemainingOnIEP0 = abDescriptor[0];
    usbSendDataPacketOnEP0((PBYTE)&abDescriptor);
}

void usbGetReportDescriptor(void)
{
    usbClearOEP0ByteCount;
    wBytesRemainingOnIEP0 = SIZEOF_REPORT_DESCRIPTOR;
    usbSendDataPacketOnEP0((PBYTE)&abromReportDescriptor);
}

// Support of the following two functions is optional.  Supporting these
// features allows the host to set the Idle rate.  By default, an HID
// device should always report the current status of the keys, even
// if they haven't changed.  However, to save bandwidth, Windows will
// attempt to set the Idle rate to 0 which means the firmware should
// only report keypresses when their state changes.

void usbSetIdle(void)
{
	usbStallEndpoint0();
}

void usbGetIdle(void)
{
	usbStallEndpoint0();
}

// The Get/Set Interface, like the Get/Set Configuration, don't really
// serve any real purpose in this firmware, but they are handled so
// that modifications to the code may be made easily.  As-is, the host
// may Set any interface number, and a Get Interface request will simply
// return the value previously Set.

void usbGetInterface(void)
{
    wBytesRemainingOnIEP0 = 1;
	usbSendDataPacketOnEP0((PBYTE) &bInterfaceNumber);
}

void usbSetInterface(void)
{
    usbStallOEP0;                             // control write without data stage
    bInterfaceNumber = tSetupPacket.bIndexL;
    usbSendZeroLengthPacketOnIEP0();
}

// The GetDeviceStatus function is used to obtain the status of the
// device.  The status is essentially the Remote Wakeup status as 
// well as the "Self-powered" indicator.  The value returned by
// GetDeviceStatus is modified by the SetRemoteWakeup and
// ClearRemoteWakeup requests.

void usbGetDeviceStatus(void)
{
    wBytesRemainingOnIEP0 = 2;
	usbSendDataPacketOnEP0((PBYTE) &wDeviceFeatures);
}

void usbSetRemoteWakeup(void)
{
	bUSBCTL |= USBCTL_RWE;
	wDeviceFeatures |= 0x0200;
    usbStallOEP0;
    usbSendZeroLengthPacketOnIEP0();
}

void usbClearRemoteWakeup(void)
{
	bUSBCTL &= ~USBCTL_RWE;
	wDeviceFeatures &= ~0x0200;
    usbStallOEP0;
    usbSendZeroLengthPacketOnIEP0();
}

// The GetInterfaceStatus always returns a 0 as a 2-byte value.

void usbGetInterfaceStatus(void)
{
	WORD wStatusBuffer = 0x00;    	
    usbStallOEP0;
    wBytesRemainingOnIEP0 = 2;
	usbSendDataPacketOnEP0((PBYTE) &wStatusBuffer);
}

// The SetAddress request allows the host to assign an address to this device.
// The device starts with an address of 00h, as do all USB devices, until
// the host specifically assigns it another address.  This code handles that
// assignment.

void usbSetAddress(void)
{
    if(tSetupPacket.bValueL < 128)
    	{
        bFUNADR = tSetupPacket.bValueL;
        bUsbDeviceAddress = tSetupPacket.bValueL;
        bStatusAction = STATUS_ACTION_SET_ADDRESS;
        usbSendZeroLengthPacketOnIEP0();
    	}
    else 
    	usbStallEndpoint0();
}

// The SetEndpointHalt allows the USB host to instruct the device to stop sending
// information on IEP1, which is how the firmware delivers keystrokes to the host.
// This is used mostly if a device goes crazy and starts sending too much data,
// this allows the host to shut the endpoint down.  All we do is set or clear
// the endpoint enable bit appropriately.  The GetEndpointStatus request reports
// the status of the endpoint which is affected by Set/Clear EndpointHalt requests.

void usbSetEndpointHalt(void)
{
	tInputEndPointDescriptorBlock[0].bEPCNF &= ~EPCNF_UBME;
    usbSendZeroLengthPacketOnIEP0();
}

void usbClearEndpointHalt(void)
{
	tInputEndPointDescriptorBlock[0].bEPCNF |= EPCNF_UBME;	
    usbSendZeroLengthPacketOnIEP0();
}

void usbGetEndpointStatus(void)
{
	WORD wEndpointStatus = 0x0100;
	if(tInputEndPointDescriptorBlock[0].bEPCNF & EPCNF_UBME)
		wEndpointStatus = 0x0000;

    wBytesRemainingOnIEP0 = 2;
	usbSendDataPacketOnEP0((PBYTE) &wEndpointStatus);
}

// Any non-standard or unrecognized request will arrive at the following
// function by default.  We automatically stall the endpoint to indicate
// it's an invalid or unrecognized request.

void usbNonStandardRequest(void)
{
	usbStallEndpoint0();
}

/***************************************************************************
 * Section:    REQUEST STRUCTURE                                           *
 * Programmer: Lobo Tai (lobotai@ti.com)                                   *
 * Description: This section of code defines the structure of the lookup   *
 *    table which determines which 'C' function should be called for each  *
 *    supported USB request.                                               * 
 ***************************************************************************/

typedef struct _tDEVICE_REQUEST_COMPARE
{
    BYTE    bmRequestType;              // See bit definitions below
    BYTE    bRequest;                   // See value definitions below
    BYTE    bValueL;                    // Meaning varies with request type
    BYTE    bValueH;                    // Meaning varies with request type
    BYTE    bIndexL;                    // Meaning varies with request type
    BYTE    bIndexH;                    // Meaning varies with request type
    BYTE    bLengthL;                   // Number of bytes of data to transfer (LSByte)
    BYTE    bLengthH;                   // Number of bytes of data to transfer (MSByte)
    BYTE    bCompareMask;               // MSB is bRequest, if set 1, bRequest should be matched, LSB is bLengthH
    VOID    (*pUsbFunction)(VOID);      // function pointer
} tDEVICE_REQUEST_COMPARE, *ptDEVICE_REQUEST_COMPARE;

/***************************************************************************
 * Section:    USB REQUEST TABLE                                           *
 * Programmer: Craig Steiner (csteiner@vaultbbs.com) based on code by      *
 *             Lobo Tai (lobotai@ti.com)                                   *
 * Description: This section of code defines the lookup table, using the   *
 *    structure defined in the previous section of code.  The values of    *
 *    the constants used in this structure are defined in usb.h.           * 
 * Structure of Table:                                                     * 
 *    bmRequestType: Indicates the type of request.  This is a bit-mapped  * 
 *          variable defined in the USB spec.  The bits of this variable   * 
 *          have the following purpose, and are defined in usb.h.          * 
 *          Bit 7: Data Direction (0=Host to Device, 1=Device to Host)     * 
 *          Bit 6-5: Type of request (00=Standard, 01=Class, 10=Vendor)    * 
 *          Bit 4-0: Recipient (00000=Device, 00001=Interface,             *
 *                              00010=Endpoint, 00011=Other                *
 *    bRequest: Indicates the request ID (Get descriptor, Get Status, Get  *
 *              feature, etc.).  These are defined in the USB and HID spec *
 *              and are declared in usb.h.                                 *
 *    bValueL/H: Additional values, purpose varies with request.           *
 *    bIndexL/H: Additional values, purpose varies with request.           *
 *    bLengthL/H: Number of bytes to transfer to or from host.             *
 *    bCompareMask: Indicates which of the above bytes should be compared  *
 *               to determine the function to call.  For example, the mask *
 *               0x80 means only bmRequestType must match. 0xC0 means      *
 *               both bmRequestType and bRequest must match.  If this      *
 *               variable is 0x00, as is the case in the last entry in the *
 *               table, then no bytes are compared and, thus, ANY packet   *
 *               will pass the comparsion stage.  This technique is used   *
 *               in the last entry of the table as an "else" condition     *
 *               so that any requests that haven't been handled by that    *
 *               point are handled by the usbNonStandardRequest function.  *
 ***************************************************************************/

code tDEVICE_REQUEST_COMPARE tUsbRequestList[] =
{
    // SET ENDPOINT FEATURE
    USB_REQ_TYPE_OUTPUT | USB_REQ_TYPE_STANDARD | USB_REQ_TYPE_ENDPOINT,
    USB_REQ_SET_FEATURE,
    FEATURE_ENDPOINT_STALL,0x00,
    0xff,0x00,
    0x00,0x00,
    0xf7,&usbSetEndpointHalt,

    // CLEAR ENDPOINT FEATURE
    USB_REQ_TYPE_OUTPUT | USB_REQ_TYPE_STANDARD | USB_REQ_TYPE_ENDPOINT,
    USB_REQ_CLEAR_FEATURE,
    FEATURE_ENDPOINT_STALL,0x00,
    0xff,0x00,
    0x00,0x00,
    0xf7,&usbClearEndpointHalt,

    // GET CONFIGURATION
    USB_REQ_TYPE_INPUT | USB_REQ_TYPE_STANDARD | USB_REQ_TYPE_DEVICE,
    USB_REQ_GET_CONFIGURATION,
    0x00,0x00,
    0x00,0x00,
    0x01,0x00,
    0xff,&usbGetConfiguration,

    // SET CONFIGURATION
    USB_REQ_TYPE_OUTPUT | USB_REQ_TYPE_STANDARD | USB_REQ_TYPE_DEVICE,
    USB_REQ_SET_CONFIGURATION,
    0xff,0x00,
    0x00,0x00,
    0x00,0x00,
    0xdf,&usbSetConfiguration,

    // GET DEVICE DESCRIPTOR
    USB_REQ_TYPE_INPUT | USB_REQ_TYPE_STANDARD | USB_REQ_TYPE_DEVICE,
    USB_REQ_GET_DESCRIPTOR,
    0xff,DESC_TYPE_DEVICE,                  // bValueL is index and bValueH is type
    0xff,0xff,
    0xff,0xff,
    0xd0,&usbGetDeviceDescriptor,

    // GET CONFIGURATION DESCRIPTOR
    USB_REQ_TYPE_INPUT | USB_REQ_TYPE_STANDARD | USB_REQ_TYPE_DEVICE,
    USB_REQ_GET_DESCRIPTOR,
    0xff,DESC_TYPE_CONFIG,                  // bValueL is index and bValueH is type
    0xff,0xff,
    0xff,0xff,
    0xd0,&usbGetConfigurationDescriptor,

    // GET HID DESCRIPTOR
    USB_REQ_TYPE_INPUT | USB_REQ_TYPE_STANDARD | USB_REQ_TYPE_INTERFACE,
    USB_REQ_GET_DESCRIPTOR,
    0xff,DESC_TYPE_HID,                  // bValueL is index and bValueH is type
    0xff,0xff,
    0xff,0xff,
    0xd0,&usbGetHIDDescriptor,

    // GET STRING DESCRIPTOR
    USB_REQ_TYPE_INPUT | USB_REQ_TYPE_STANDARD | USB_REQ_TYPE_DEVICE,
    USB_REQ_GET_DESCRIPTOR,
    0xff,DESC_TYPE_STRING,                  // bValueL is index and bValueH is type
    0xff,0xff,
    0xff,0xff,
    0xd0,&usbGetStringDescriptor,

    // GET REPORT DESCRIPTOR
    USB_REQ_TYPE_INPUT | USB_REQ_TYPE_STANDARD | USB_REQ_TYPE_INTERFACE,
    USB_REQ_GET_DESCRIPTOR,
    0xff,DESC_TYPE_REPORT,                 // bValueL is index and bValueH is type
    0xff,0xff,
    0xff,0xff,
    0xd0,&usbGetReportDescriptor,

    // SET REPORT
    USB_REQ_TYPE_OUTPUT | USB_REQ_TYPE_CLASS | USB_REQ_TYPE_INTERFACE,
    USB_REQ_SET_REPORT,
    0xff,0xFF,                 // bValueL is index and bValueH is type
    0xff,0xff,
    0xff,0xff,
    0xC0,&usbSetReport,

    // SET IDLE
    USB_REQ_TYPE_OUTPUT | USB_REQ_TYPE_CLASS | USB_REQ_TYPE_INTERFACE,
    USB_REQ_SET_IDLE,
    0xff,0xFF,                  // bValueL is index and bValueH is type
    0xff,0xff,
    0x00,0x00,
    0xc3,&usbSetIdle,

    // GET IDLE
    USB_REQ_TYPE_INPUT | USB_REQ_TYPE_CLASS | USB_REQ_TYPE_INTERFACE,
    USB_REQ_GET_IDLE,
    0xff,0xFF,                  // bValueL is index and bValueH is type
    0xff,0xff,
    0x00,0x00,
    0xc3,&usbGetIdle,

    // GET INTERFACE
    USB_REQ_TYPE_INPUT | USB_REQ_TYPE_STANDARD | USB_REQ_TYPE_INTERFACE,
    USB_REQ_GET_INTERFACE,
    0x00,0x00,
    0xff,0xff,
    0x01,0x00,
    0xf3,&usbGetInterface,

    // GET DEVICE STATUS
    USB_REQ_TYPE_INPUT | USB_REQ_TYPE_STANDARD | USB_REQ_TYPE_DEVICE,
    USB_REQ_GET_STATUS,
    0x00,0x00,
    0x00,0x00,
    0x02,0x00,
    0xff,&usbGetDeviceStatus,

    // GET INTERFACE STATUS
    USB_REQ_TYPE_INPUT | USB_REQ_TYPE_STANDARD | USB_REQ_TYPE_INTERFACE,
    USB_REQ_GET_STATUS,
    0x00,0x00,
    0xff,0x00,
    0x02,0x00,
    0xf7,&usbGetInterfaceStatus,

    // GET ENDPOINT STATUS
    USB_REQ_TYPE_INPUT | USB_REQ_TYPE_STANDARD | USB_REQ_TYPE_ENDPOINT,
    USB_REQ_GET_STATUS,
    0x00,0x00,
    0xff,0x00,
    0x02,0x00,
    0xf7,&usbGetEndpointStatus,

    // SET ADDRESS
    USB_REQ_TYPE_OUTPUT | USB_REQ_TYPE_STANDARD | USB_REQ_TYPE_DEVICE,
    USB_REQ_SET_ADDRESS,
    0xff,0x00,
    0x00,0x00,
    0x00,0x00,
    0xdf,&usbSetAddress,

    // SET DEVICE FEATURE
    USB_REQ_TYPE_OUTPUT | USB_REQ_TYPE_STANDARD | USB_REQ_TYPE_DEVICE,
    USB_REQ_SET_FEATURE,
    FEATURE_REMOTE_WAKEUP,0x00,           // feature selector
    0x00,0x00,
    0x00,0x00,
    0xff,&usbSetRemoteWakeup, // df, setDeviceFeature
    
	// CLEAR DEVICE FEATURE
    USB_REQ_TYPE_OUTPUT | USB_REQ_TYPE_STANDARD | USB_REQ_TYPE_DEVICE,
    USB_REQ_CLEAR_FEATURE,
    FEATURE_REMOTE_WAKEUP,0x00,
    0x00,0x00,
    0x00,0x00,
    0xff,&usbClearRemoteWakeup,

    // SET INTERFACE FEATURE
    USB_REQ_TYPE_OUTPUT | USB_REQ_TYPE_STANDARD | USB_REQ_TYPE_INTERFACE,
    USB_REQ_SET_FEATURE,
    0xff,0x00,                      // alternative setting
    0xff,0x00,                      // interface number
    0x00,0x00,
    0xd7,&usbSetInterface,

	// END OF LIST CATCH-ALL REQUEST: 
	// This will match any USB request sicne bCompareMask is 0x00.
    0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
    0x00,&usbNonStandardRequest
};

/***************************************************************************
 * Function:   UsbDecodeAndProcessUsbRequest()                             *
 * Programmer: Lobo Tai (lobotai@ti.com)                                   *
 * Description: This function is called when a USB request has been        *
 *    received.  It searches the tUsbRequestList[] structure defined in    * 
 *    the previous section for a request that matches a given entry in     * 
 *    the table and, when matched, executes the corresponding function.    *  
 ***************************************************************************/

VOID usbDecodeAndProcessUsbRequest(VOID)
{
    BYTE bMask,bResult,bTemp;
    BYTE *pbUsbRequestList;                 // save code space


	// We initialize the pbUsbRequestList pointer to the beginning of the
	// tUsbRequestList[] so that we can subsequently traverse the table
	// by incrementing the pbUsbRequestList pointer.
    pbUsbRequestList = (PBYTE) &tUsbRequestList[0];

	// Cycle indefinitely until we've found an entry in the tUsbRequestList[]
	// table.  Since the last entry in the table has a 0x00 mask, we'll
	// *always* find a match, so this cycle will always exit.
    while(1)
    	{
        bResult = 0x00;
        bMask   = 0x80;

        // We cycle through fields 0 through 7, which correspond to the 8 fields
        // in each entry of tUsbRequestList.  If the given byte in the packet
        // we just receive is equal to the corresponding byte in the table, we
        // set that bit in the result, indicating a byte which matched.  Otherwise,
        // we don't set the bit which means that byte didn't match.
        for(bTemp = 0; bTemp < 8; bTemp++)
        	{
            if(*(pbEP0_SETUP_ADDRESS+bTemp) == *(pbUsbRequestList+bTemp)) 
            	bResult |= bMask;
			bMask = bMask >> 1;
	        }

        // At this point, bResult holds 8 bits which indicate whether each of the
        // bytes in the packet matched the corresponding bytes in the tUsbRequestList[]
        // table.  We then AND the mask value in the table with the result so that
        // we only are comparing the bits required in the mask.  If the resulting
        // value is equal to the mask, that means that all significant bytes match.
        // This is done since any bit that is clear in the mask is a "don't care", so
        // the AND makes sure we don't reject a "valid" comparison beause a don't 
        // care bit actually matched.
        if((*(pbUsbRequestList+bTemp) & bResult) == *(pbUsbRequestList+bTemp)) 
        	break;

        // If we haven't found a matching entry yet, we advenced the pointer to point
        // to the next entry in the table, and keep looking.
        pbUsbRequestList += sizeof(tDEVICE_REQUEST_COMPARE);
    	}

    // We check to see if any more setup packet(s) have been received and, if so, we
    // anbandon this one to hanlde the next one.
    if(bUSBSTA & (USBSTA_SETUP | USBSTA_STPOW) != 0x00) 
    	return;

	// If we've reached this point of the function, we've found the function that should
	// be called given the current request.  So we call it...
	((ptDEVICE_REQUEST_COMPARE)pbUsbRequestList)->pUsbFunction();
}

/***************************************************************************
 * Function:   usbStallEndpoint0()                                         *
 * Programmer: Lobo Tai (lobotai@ti.com)                                   *
 * Description: Sets the STALL flag on both IEP0 and OEP0.  Often called   *
 *    to reflect an error condition.                                       *
 ***************************************************************************/

void usbStallEndpoint0(void)
{
    tEndPoint0DescriptorBlock.bIEPCNFG |= EPCNF_STALL;
    tEndPoint0DescriptorBlock.bOEPCNFG |= EPCNF_STALL;
}

/***************************************************************************
 * Function:   usbReceiveDataPacketOnEP0 / ReceiveNextPacket               *
 * Programmer: Lobo Tai (lobotai@ti.com)                                   *
 * Description: These two functions, together, are used to receive a data  *
 *    payload on the OEP0 endpoint.  The reception is first initiated by   *
 *    calling usbReceiveDataPacketOnEP0 and indicating the address that the*
 *    received data should be placed in.  As each data packet is received, *
 *    the usbReceiveNextPacketOnOEP0 will be called to process the packet  *
 *    and determine if the packet received was the last packet, or if there*
 *    are more packets coming.                                             * 
 ***************************************************************************/

void usbReceiveDataPacketOnEP0(PBYTE pbBuffer)
{
    pbOEP0Buffer = pbBuffer;
    wBytesRemainingOnOEP0 = (WORD)(tSetupPacket.bLengthH << 8) | (WORD)tSetupPacket.bLengthL;
    bStatusAction = STATUS_ACTION_DATA_OUT;
    usbClearOEP0ByteCount;            
}

void usbReceiveNextPacketOnOEP0(void)
{
    BYTE bIndex,bByte;

	// First we must determine how many bytes were received in this data
	// packet.  We AND it with EPBCT_BYTECNT_MASK so that a NAK condition
	// will return "0 bytes."
    bByte = tEndPoint0DescriptorBlock.bOEPBCNT & EPBCT_BYTECNT_MASK;

	// If the number of bytes remaining to be received is greater than
	// or equal to the number of bytes received in this packet then
	// we handle the packet.  However, if we received more bytes than
	// we had expected we simply ignore the packet since it is
	// presumably erroneous.
    if(wBytesRemainingOnOEP0 >= (WORD)bByte)
    	{
		// For each of the bytes received, we copy the value received to the
		// next position in the buffer we set aside for the OEP0 data.
        for(bIndex=0;bIndex<bByte;bIndex++)
            *pbOEP0Buffer++ = abOEP0Buffer[bIndex];

		// We now reduce the number of bytes remaining by the number of bytes
		// received in this packet.                              
        wBytesRemainingOnOEP0 -= (WORD)bByte;

        // If there are still more bytes to be received in additional packets (i.e.,
		// wBytesRemainingOnOEP0 is greater than zero), we clear the byte count and
		// reestablish bStatusAction to indicate that we are still in a DATA_OUT
		// condition.
        if(wBytesRemainingOnOEP0 > 0)
        	{
            usbClearOEP0ByteCount;        
            bStatusAction = STATUS_ACTION_DATA_OUT;
        	}
        else
        	{
        	// If we aren't expecting any more data bytes, we terminate the OEP0
        	// transaction by stalling OEP0 and setting the bStatusAction condition
        	// to "Nothing."  Since in this firmware the only USB function that
        	// includes a subsequent data payload is the Set_Report function, we
        	// automatically update the keyboard LEDs with the new value.  If
        	// additional features are added that expect data payloads, calling
        	// the OEP0SetLeds() function when a Set_Report request was not
        	// received will cause no harm.
            usbStallOEP0;
            bStatusAction = STATUS_ACTION_NOTHING;        
			OEP0SetLEDs();
        	}
    	}
    else
    	{
    	// If the packet we received include more data than we expected, we ignore
    	// the entire packet and abort the transfer.  This is accomplished by
    	// stalling OEP0 and resetting the bStatusAction condition to "Nothing."
        usbStallOEP0;
        bStatusAction = STATUS_ACTION_NOTHING;
    	}
}

/***************************************************************************
 * Function:   usbSendZeroLengthPacketOnIEP0()                             *
 * Programmer: Lobo Tai (lobotai@ti.com)                                   *
 * Description: Sends a 0-lengthg packet back to the host on IEP0. Often   *
 *    called to acknowledge a packet received from the host that requires  *
 *    no data in the reply, just an acknowledgement of receipt.            *
 ***************************************************************************/

void usbSendZeroLengthPacketOnIEP0(void)
{
    wBytesRemainingOnIEP0 = NO_MORE_DATA;
    bStatusAction = STATUS_ACTION_NOTHING;
    tEndPoint0DescriptorBlock.bIEPBCNT = 0x00;
}

/***************************************************************************
 * Function:   usbSendDataPacketOnEPO / SendNext                           *
 * Programmer: Lobo Tai (lobotai@ti.com)                                   *
 * Description: These two functions, together, are responsible for sending *
 *    data packets back to the host on IEPO.  The transfer is initiated by *
 *    first calling usbSendDataPacketOnEP0 and indicating the address of   *
 *    the buffer to send.  This initiates the transfer and sends the first *
 *    packet of data.  If there is more data than can be sent in the first *
 *    packet, the usbSendNextPacketOnIEP0 function is called to send       *
 *    subsequent packets of data when an interrupt indicates the previous  *
 *    packet has been sent.                                                *
 ***************************************************************************/

void usbSendDataPacketOnEP0(PBYTE pbBuffer)
{
    WORD wTemp;

    pbIEP0Buffer = pbBuffer;

    wTemp = (WORD)(tSetupPacket.bLengthH << 8) | (WORD)tSetupPacket.bLengthL;

    // Limit transfer size to wLength if needed
    // this prevent USB device sending 'more than require' data back to host
    if(wBytesRemainingOnIEP0 >= wTemp)
    	{
        wBytesRemainingOnIEP0 = wTemp;
        bHostAskMoreDataThanAvailable = FALSE;
        }
	else
		{ 
		bHostAskMoreDataThanAvailable = TRUE;
		}

    usbSendNextPacketOnIEP0();
}

void usbSendNextPacketOnIEP0(void)
{
    BYTE bPacketSize,bIndex;

    // First check if there are bytes remaining to be transferred
    if(wBytesRemainingOnIEP0 != NO_MORE_DATA)
    	{
        if(wBytesRemainingOnIEP0 > EP0_MAX_PACKET_SIZE)
        	{
            // More bytes are remaining than will fit in one packet
            // there will be More IN Stage
            bPacketSize = EP0_MAX_PACKET_SIZE;
            wBytesRemainingOnIEP0 -= EP0_MAX_PACKET_SIZE;
            bStatusAction = STATUS_ACTION_DATA_IN;
        	}
        else if (wBytesRemainingOnIEP0 < EP0_MAX_PACKET_SIZE)
        	{
            // The remaining data will fit in one packet.
            // This case will properly handle wBytesRemainingOnIEP0 == 0
            bPacketSize = (BYTE)wBytesRemainingOnIEP0;
            wBytesRemainingOnIEP0 = NO_MORE_DATA;        // No more data need to be Txed
            bStatusAction = STATUS_ACTION_NOTHING;
        	}
        else
        	{
            // wBytesRemainingOnIEP0 == EP0_MAX_PACKET_SIZE
            bPacketSize = EP0_MAX_PACKET_SIZE;
            if(bHostAskMoreDataThanAvailable == TRUE)
            	{
                wBytesRemainingOnIEP0 = 0;
                bStatusAction = STATUS_ACTION_DATA_IN;
            	}
            else
            	{ 
                wBytesRemainingOnIEP0 = NO_MORE_DATA;
                bStatusAction = STATUS_ACTION_NOTHING;
            	}
        	}

        for(bIndex=0; bIndex<bPacketSize; bIndex++) 
            abIEP0Buffer[bIndex] = *pbIEP0Buffer++;

        tEndPoint0DescriptorBlock.bIEPBCNT = bPacketSize;   // & EPBCT_BYTECNT_MASK;
	  	}
    else
    	{
    	bStatusAction = STATUS_ACTION_NOTHING;
    	}
}

/***************************************************************************
 * Function:   SetupPacketInterruptHandler()                               *
 * Programmer: Lobo Tai (lobotai@ti.com)                                   *
 * Description: This function is called by the UsbInterrupt function when  *
 *    a setup packet is received.  This function immediately sets both     * 
 *    OEP0 and IEP0 to a NAK state, sets the bUSBCTL to send/receive based *
 *    on the direction of the request, then proceeds to call  the          *
 *    usbDecodeAndProcessUsbRequest() function which determines which      *
 *    function should be called to handle the given USB request.           *  
 ***************************************************************************/

void SetupPacketInterruptHandler(void)
{
    // Hardware clears STALL in both data endpoints once valid setup packet is
    // received.  NAK both data endpoints.
    tEndPoint0DescriptorBlock.bIEPBCNT  = EPBCNT_NAK;
    tEndPoint0DescriptorBlock.bOEPBCNT  = EPBCNT_NAK;

    // Copy the MSB of bmRequestType to DIR bit of USBCTL to indicate the
    // direction of the transfer.
    if((tSetupPacket.bmRequestType & USB_REQ_TYPE_INPUT) == USB_REQ_TYPE_INPUT)
        bUSBCTL |= USBCTL_DIR;
    else 
    	bUSBCTL &= ~USBCTL_DIR;

	// Clear the bStatusAction to indicate that, at this point, nothing is 
	// happening (it may be set to DATA_OUT by specific functions that
	// expect a DATA packet following the setup packet).
    bStatusAction = STATUS_ACTION_NOTHING;

	// Call the function that determines which function should be called to
	// handle the specific USB request.
    usbDecodeAndProcessUsbRequest();
}

/***************************************************************************
 * Function:   OEP0InterruptHandler()                                      *
 * Programmer: Lobo Tai (lobotai@ti.com)                                   *
 * Description: This function is called by the UsbInterrupt function when  *
 *    a USB interrupt is called by OEP0.  This will happen once a data     *
 *    transfer has been initialized by a USB function handler by calling   *
 *    usbReceiveDataPacketOnEP0.                                           *
 ***************************************************************************/

void OEP0InterruptHandler(void)
{
	// We clear the IEP0 byte count since we have nothing to send out.
    tEndPoint0DescriptorBlock.bIEPBCNT = 0x00;

	// We now handle the interrupt based on the bStatusAction condition.
	// If we are in a DATA_OUT condition, we call the usbReceiveNextPacketOnEP0
	// function to copy the data payload to its correct buffer.  If we are
	// not expecting any data on OEP0, we set the stall flag to stall the
	// endpoint and abort any additional data that may otherwise be
	// sent.
    if(bStatusAction == STATUS_ACTION_DATA_OUT) 
    	usbReceiveNextPacketOnOEP0(); // Handle this data packet
    else 
    	tEndPoint0DescriptorBlock.bOEPCNFG |= EPCNF_STALL; // We weren't expecting data
}

/***************************************************************************
 * Function:   IEP0InterruptHandler()                                      *
 * Programmer: Lobo Tai (lobotai@ti.com)                                   *
 * Description: This function is called by the UsbInterrupt function when  *
 *    a USB interrupt is caused by IEP0.  This will happen once the data   *
 *    sent by calling usbSendNextPacketOnIEP0 and means the previous data  *
 *    packet has been sent.  At that point, there are two conditions:      *
 *    either there is more data to send or there isn't.  If there is, we   *
 *    call usbSendNextPacketOnIEP0 to send the next packet of data.  If    *
 *    there isn't anymore data, we stall.  However, if the bStatusAction   *
 *    condition indicates that we were changing the devices address, we    *
 *    do so at this point.                                                 *
 ***************************************************************************/

void IEP0InterruptHandler(void)
{
	// We clear the OEP0 byte count since we are not expecting any data.
    tEndPoint0DescriptorBlock.bOEPBCNT = 0x00;

	// We now handle the interrupt based on the bStatusAction condition.
	// If we are in a DATA_IN condition, we call the usbSendNextPacketOnIEP0  
	// function to send the next data payload packet.  If we are in a
	// Set Address mode, we modify the address.  In any other case, we've
	// sent all teh data we had to send, so we stall the endpoint to indicate
	// there is no more data to send.
    if(bStatusAction == STATUS_ACTION_DATA_IN) 
    	usbSendNextPacketOnIEP0(); // Send the next data packet
    else if(bStatusAction == STATUS_ACTION_SET_ADDRESS) 
    	bFUNADR = bUsbDeviceAddress; // Set the device's address
    else 
    	tEndPoint0DescriptorBlock.bIEPCNFG |= EPCNF_STALL; // No more data to send
}

/***************************************************************************
 * Function:   USBInterrupt                                                *
 * Programmer: Craig Steiner (csteiner@vaultbbs.com)                       *
 * Description: Handles the USB interrupts generated by the USB sectiob of *
 *    the part.  This is actually External 0 interrupt on the 8051 at      *
 *    0x0003 in memory, but is used exclusively for USB interrupts on the  *
 *    TUSB2136.                                                            * 
 *                                                                         * 
 * Note: VECINT is cleared after being handled successfully so that the    * 
 *       next USB-related interrupt is made available to the handler.      *  
 ***************************************************************************/

interrupt [0x0003] void USBInterrupt(void)
{
	// Disable all interrupts because this is critical code
	EA = DISABLE;

	// Select the appropriate interrupt handler depending on the VECINT value
    switch (bVECINT)
    	{
		case VECINT_OUTPUT_ENDPOINT0:
			bVECINT  = 0x00;
			OEP0InterruptHandler();
			break;

                case VECINT_INPUT_ENDPOINT0:
			bVECINT  = 0x00;
			IEP0InterruptHandler();
			break;

		case VECINT_INPUT_ENDPOINT1:
		case 0x12:
			bVECINT = 0x00;
			IEP1InterruptHandler();
			break;

            case VECINT_STPOW_PACKET_RECEIVED:
			bVECINT  = 0x00;
			bUSBSTA = USBSTA_STPOW;
			SetupPacketInterruptHandler();
			break;

            case VECINT_SETUP_PACKET_RECEIVED:
			bVECINT  = 0x00;
			bUSBSTA = USBSTA_SETUP;
			SetupPacketInterruptHandler();
			break;

            case VECINT_RSTR_INTERRUPT:
			bVECINT  = 0x00;
			bUSBSTA = USBSTA_RSTR;
			UsbReset();
			break;
		
		case VECINT_RESR_INTERRUPT:
			bVECINT = 0x00;
			bUSBSTA = USBSTA_RESR;
			bSuspended = FALSE;
			break;
		
		case VECINT_SUSR_INTERRUPT:
			bVECINT = 0x00;
			bUSBSTA = USBSTA_SUSR;
			bSuspended = TRUE;
			break;

		default:
			bVECINT  = 0x00;
			break;
		}

	// End of ciritical code section, reenable interrupts
    EA = ENABLE;
}

interrupt [0x0013] void P33Interrupt(void)
{
	// Disable all interrupts because this is critical code

	bUSBCTL |= USBCTL_RWUP;
	bSuspended = FALSE;
}
