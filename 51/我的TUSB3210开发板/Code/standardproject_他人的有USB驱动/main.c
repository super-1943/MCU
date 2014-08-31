#include "reg52modified.h"
#include "types.h"
#include "usb.h"
#include "tusb2136.h"
#include "serial.h"


extern void InitializeUsbFunction(void);

extern bit deviceReady;
extern bit bSuspended;

extern tEDB xdata tInputEndPointDescriptorBlock[3];
extern BYTE xdata pbInBufferAddress[EP_MAX_PACKET_SIZE];  // ENDPOINT 1 IN X buffer
extern BYTE xdata pb48BufferAddress[EP_MAX_PACKET_SIZE];  // use ENDPOINT 1 OUT Y buffer space for buffering the 1st 
                                                          // half of 96-byte block write for UCD9110 flash programming
extern BYTE previous_crc8;
sbit key=P3^2;
sbit led=P1^1;
BYTE intFlags = 0x00;
BYTE otherFlags = 0x00;
BYTE modifierByte = 0x00;

void IEP1InterruptHandler(void);
void OEP0SetLEDs(void);
void delay(unsigned int k)
{
	unsigned char i,j;
	for(;k;k--)
	for(i=200;i;i--)
	for(j=200;j;j--);
}


void main(void)
{
	unsigned char i;
	// Make sure we're disconnected from the upstream port
	bUSBCTL = 0x00;
	rs232_init();
	rs232_printstr("Hello world!\r\n");
	InitializeUsbFunction(); // Initialize the USB embedded function
	while(1) 
	{ // Indefinite loop to handle keyboard scanning


		
	}
}


void IEP1InterruptHandler(void)
{
	// Just clear the NAK bit
	bIEPDCTX_1=EPBCT_NAK;
	pbInBufferAddress[0]=(~(P3>>2))&0x0f;
	bIEPDCTX_1=0x08;
}


void OEP0SetLEDs(void)
{
}
