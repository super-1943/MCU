#include "reg52modified.h"
#include "types.h"
#include "tusb2136.h"
#include "usb.h"

extern bit deviceReady;
extern WORD wBytesRemainingOnIEP0;
extern PBYTE pbIEP0Buffer;
extern BYTE bConfigurationNumber;
extern BYTE bInterfaceNumber;
extern WORD wBytesRemainingOnOEP0;
extern PBYTE pbOEP0Buffer;
extern BYTE bStatusAction;
extern BYTE code abromReportDescriptor[SIZEOF_REPORT_DESCRIPTOR];
extern BYTE code abromConfigurationDescriptorGroup[SIZEOF_BOOTCODE_CONFIG_DESC_GROUP];
extern BYTE code abromDeviceDescriptor[SIZEOF_DEVICE_DESCRIPTOR];
extern BYTE previous_crc8;


extern xdata tEDB0 tEndPoint0DescriptorBlock;
extern xdata tEDB tInputEndPointDescriptorBlock[3];
extern xdata tEDB tOutputEndPointDescriptorBlock[3];

void UsbReset(void);
void InitializeUsbData(void);
void InitializeUsbFunction(void);


/***************************************************************************
 * Function:   UsbReset                                                    *
 * Programmer: Craig Steiner (csteiner@vaultbbs.com)                       *
 * Description: This initializes or resets the USB function.               *
 ***************************************************************************/

void UsbReset(void)
{
    InitializeUsbData(); 

    wBytesRemainingOnIEP0   = NO_MORE_DATA;
    wBytesRemainingOnOEP0   = NO_MORE_DATA;
    bStatusAction           = STATUS_ACTION_NOTHING;

    pbIEP0Buffer            = (PBYTE)0x0000;
    pbOEP0Buffer            = (PBYTE)0x0000;
    bConfigurationNumber    = 0x00;         // device unconfigured
    bInterfaceNumber        = 0x00; 

    // enable endpoint 0 interrupt
    tEndPoint0DescriptorBlock.bIEPCNFG = EPCNF_USBIE | EPCNF_UBME;
    tEndPoint0DescriptorBlock.bOEPCNFG = EPCNF_USBIE | EPCNF_UBME;
    // NAK both endpoints
    tEndPoint0DescriptorBlock.bIEPBCNT  = EPBCNT_NAK;
    tEndPoint0DescriptorBlock.bOEPBCNT  = EPBCNT_NAK;


    // enable input endpoint 1 interrupt
    tInputEndPointDescriptorBlock[0].bEPCNF   = EPCNF_USBIE | EPCNF_UBME ;
    tInputEndPointDescriptorBlock[0].bEPBBAX  = (BYTE)(IEP1_X_BUFFER_ADDRESS >> 3 & 0x00ff);
    tInputEndPointDescriptorBlock[0].bEPBCTX  = EPBCT_NAK;
    tInputEndPointDescriptorBlock[0].bEPSIZXY = EP_MAX_PACKET_SIZE;
    
    
    //enable output endpoint 1 interrupt
    tOutputEndPointDescriptorBlock[0].bEPCNF   = EPCNF_USBIE | EPCNF_UBME ;
    tOutputEndPointDescriptorBlock[0].bEPBBAX  = (BYTE)(OEP1_X_BUFFER_ADDRESS >> 3 & 0x00ff);
    tOutputEndPointDescriptorBlock[0].bEPBCTX  = 0x00;
    tOutputEndPointDescriptorBlock[0].bEPSIZXY = EP_MAX_PACKET_SIZE;

    // Enable the USB-specific Interrupts; SETUP, RESET and STPOW
    bUSBMSK = USBMSK_STPOW | USBMSK_SETUP | USBMSK_RSTR | USBMSK_RESR | USBMSK_SUSR;
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
 ***************************************************************************/

void InitializeUsbData(void)
{
	deviceReady = FALSE; // Device is not currently ready

    bMCNFG = (MCNFG_48MHZ | MCNFG_OVCE | MCNFG_XINT); // Set to 48Mhz
    // Set power wait time for the hub
    bHUBPOTG = HUBPOTG_100MS;               // 100 ms from power-on to power-good

    // Set power rating for the hub
    bHUBCURT = HUBCURT_100MA;               // 100 ms from power-on to power-good
}
