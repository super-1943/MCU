/******************************************************************************
 *                         VAULT INFORMATION SERVICES                         *
 *                          TEXAS INSTRUMENTS, INC.                           *
 *----------------------------------------------------------------------------*
 *                "USB Initialization for TUSB2136 Demo App"                  *
 *                                                                            * 
 * Programmed by: Craig Steiner, VIS (csteiner@vaultbbs.com)                  * 
 * Develop Date:  30/Sep/2000                                                 *  
 *----------------------------------------------------------------------------*
 * Description: This module is a component of the TUSB2136 Demo App.  It      *
 *   handles the initialization phases of the USB hub and function.           *
 ******************************************************************************/

#include <io51.h>
#include "types.h"
#include "tusb2136.h"
#include "usb.h"
#include "delay.h"

extern BYTE deviceReady;
extern WORD wBytesRemainingOnIEP0;
// extern BOOL bHostAskMoreDataThanAvailable;
extern PBYTE pbIEP0Buffer;
extern BYTE bConfigurationNumber;
extern BYTE bInterfaceNumber;
extern WORD wBytesRemainingOnOEP0;
extern PBYTE pbOEP0Buffer;
extern BYTE bStatusAction;
extern struct FUNCDEF_STRUCT code funcDefs[17]; // From vidpid.c
extern unsigned char fncOffset; // From vidpid.c
extern BYTE strlen(char *string); // From support.c
extern char *iep1Buffer; // From keyboard.c
extern BYTE code abromReportDescriptor[SIZEOF_REPORT_DESCRIPTOR];
extern BYTE code abromConfigurationDescriptorGroup[SIZEOF_BOOTCODE_CONFIG_DESC_GROUP];
extern BYTE code abromDeviceDescriptor[SIZEOF_DEVICE_DESCRIPTOR];

void InitializeUsbData(void);

/***************************************************************************
 * Section:    External TUSB2136 Segment Definitions                       *
 * Programmer: Craig Steiner (csteiner@vaultbbs.com)                       *
 * Description: This section of code declares as external all the required *
 *    memory mapped segments.  The fact that they must be defined as       *
 *    external within the #pragmas seems illogical, but IAR requires the   * 
 *    #pragmas along with the external declarations in order to link.      *  
 *                                                                         *   
 * Note: The original declarations themselves are contained in "usb.c".    *    
 ***************************************************************************/

#pragma memory = dataseg(TUSB2136_EP0_EDB_SEG)
extern tEDB0 tEndPoint0DescriptorBlock;
#pragma memory=default
#pragma memory = dataseg(TUSB2136_IEP_EDB_SEG)
extern tEDB tInputEndPointDescriptorBlock[3];
#pragma memory=default
#pragma memory = dataseg(TUSB2136_OEP_EDB_SEG)
extern tEDB tOutputEndPointDescriptorBlock[3];
#pragma memory=default
#pragma memory = dataseg(TUSB2136_DESC_SEG)
extern BYTE abDeviceDescriptor[SIZEOF_DEVICE_DESCRIPTOR];
//extern BYTE abConfigurationDescriptorGroup[SIZEOF_BOOTCODE_CONFIG_DESC_GROUP];
//extern BYTE abStringDescriptor[SIZEOF_BOOTCODE_STRING_DESC_GROUP];
#pragma memory = default
#pragma memory = dataseg(TUSB2136_IEP1_X_BUFFER_SEG)
BYTE bufIEP1Buffer[8];
#pragma memory = default


/***************************************************************************
 * Function:   InitializeUsbHub                                            *
 * Programmer: Craig Steiner (csteiner@vaultbbs.com)                       *
 * Description: Initializes the HUB by assigning it a VID/PID, and connects*
 *    the Hub to the upstream port.                                        *
 ***************************************************************************/

void InitializeUsbHub(void)
{
        
	// Make sure we're disconnected from the upstream port
	bUSBCTL = 0x00;

	// Initialize the HUB VID/PID
	bHUBVIDH = (funcDefs[fncOffset].hubVID & 0xFF00) >> 8;
	bHUBVIDL = (funcDefs[fncOffset].hubVID & 0xFF);
	bHUBPIDH = (funcDefs[fncOffset].hubPID & 0xFF00) >> 8;
	bHUBPIDL = (funcDefs[fncOffset].hubPID & 0xFF);

	// Connect hub to the upstream port
//	bUSBCTL |= USBCTL_CONT; // marked by Jim 2001/01/15
}

/***************************************************************************
 * Function:   UsbReset                                                    *
 * Programmer: Craig Steiner (csteiner@vaultbbs.com)                       *
 * Description: This initializes or resets the USB function.               *
 ***************************************************************************/

void UsbReset(void)
{
    InitializeUsbData(); // ces
	
//    bFUNADR                 = 0x00;         // no device address

    wBytesRemainingOnIEP0   = NO_MORE_DATA;
    wBytesRemainingOnOEP0   = NO_MORE_DATA;
    bStatusAction           = STATUS_ACTION_NOTHING;

    pbIEP0Buffer            = (PBYTE)0x0000;
    pbOEP0Buffer            = (PBYTE)0x0000;
    bConfigurationNumber    = 0x00;         // device unconfigured
    bInterfaceNumber        = 0x00;         
//    bRemoteWakeup           = ENABLE;

    // enable endpoint 0 interrupt
    tEndPoint0DescriptorBlock.bIEPCNFG = EPCNF_USBIE | EPCNF_UBME;
    tEndPoint0DescriptorBlock.bOEPCNFG = EPCNF_USBIE | EPCNF_UBME;
    // NAK both endpoints
    tEndPoint0DescriptorBlock.bIEPBCNT  = EPBCNT_NAK;
    tEndPoint0DescriptorBlock.bOEPBCNT  = EPBCNT_NAK;


    // enable endpoint 1 interrupt
    tInputEndPointDescriptorBlock[0].bEPCNF   = EPCNF_USBIE | EPCNF_UBME ;
    tInputEndPointDescriptorBlock[0].bEPBBAX  = (BYTE)(IEP1_X_BUFFER_ADDRESS >> 3 & 0x00ff);
    tInputEndPointDescriptorBlock[0].bEPBCTX  = EPBCT_NAK; //0x0000;
    tInputEndPointDescriptorBlock[0].bEPSIZXY = EP_MAX_PACKET_SIZE;
    tInputEndPointDescriptorBlock[0].bEPBCTX = EPBCT_NAK;
    
    // Enable the USB-specific Interrupts; SETUP, RESET and STPOW
    bUSBMSK = USBMSK_STPOW | USBMSK_SETUP | USBMSK_RSTR | USBMSK_RESR | USBMSK_SUSR;
    
    // Enable port 3, which is the embedded function which is always connected.
    bHUBCNFG   |= (HUBCNFG_P3_FIXED | HUBCNFG_P1E | HUBCNFG_P2E | HUBCNFG_OCP);

	// Connect the function to the hub.
	//bUSBCTL |= 0x40;
}

/***************************************************************************
 * Function:   InitializeUsbFunction                                       *
 * Programmer: Craig Steiner (csteiner@vaultbbs.com)                       *
 * Description: Initializes the interrupts necessary to perform the user   *
 *     function, then initializes the function with UsbReset().            * 
 ***************************************************************************/

void InitializeUsbFunction(void)
{
	IT0 = 0; // Edge-triggered
	EX0 = ENABLE; // Enable external 0 interrupt (USB interrupt source)
	EA = ENABLE; // Enable global interrupts

	UsbReset(); // Reset the USB Function
	
	bUSBCTL |= USBCTL_CONT; // added by Jim 2001/01/15

}

/***************************************************************************
 * Function:   InitializeUsbData                                           *
 * Programmer: Craig Steiner (csteiner@vaultbbs.com)                       *
 * Description: Initializes the USB-related data structures, copying       *
 *    descriptors, etc. from code memory to their correct address in XRAM. *
 *    It also builds the string descriptors on-the-fly based on the        *
 *    VID/PID option that has been selected with s0123.                    *
 ***************************************************************************/

void InitializeUsbData(void)
{
//	BYTE bTemp; // Temporary working variable
	BYTE stringOffset = 4; // Used to construct string descriptors on-the-fly

	deviceReady = FALSE; // Device is not currently ready

    bMCNFG = (MCNFG_24MHZ | MCNFG_OVCE | MCNFG_XINT); // Set to 24Mhz
    // Set power wait time for the hub
    bHUBPOTG = HUBPOTG_100MS;               // 100 ms from power-on to power-good

    // Set power rating for the hub
    bHUBCURT = HUBCURT_100MA;               // 100 ms from power-on to power-good
    
    iep1Buffer = (PBYTE) bufIEP1Buffer; // &bufIEP1Buffer[0]; // abDeviceDescriptor;
}
