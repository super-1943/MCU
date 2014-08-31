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

BYTE intFlags = 0x00;
BYTE otherFlags = 0x00;
BYTE modifierByte = 0x00;

unsigned char FC_flag=0;
#define FC_PORT		P3
#define FC_PIN		P3
#define FC_LATCH	0x20
#define FC_CLK		0x10
#define FC_DATA		0x08
#define FC_LATCH_0	FC_PORT&=	~FC_LATCH
#define FC_LATCH_1	FC_PORT|=    FC_LATCH
#define FC_CLK_0	FC_PORT&=	~FC_CLK
#define FC_CLK_1	FC_PORT|=    FC_CLK
#define FC_DATA_IN	(FC_PIN&FC_DATA)

void FC_Init(void)
{
	FC_PORT|=FC_LATCH|FC_CLK|FC_DATA;
	FC_PORT&=~FC_LATCH;
}
unsigned char FC_Getdata(void)
{
	unsigned char i,t=0;
	FC_LATCH_1;
	FC_LATCH_1;
	FC_LATCH_1;
	FC_LATCH_1;
	FC_LATCH_0;
	for(i=0;i<8;i++)
	{
		t>>=1;
		FC_CLK_0;
		if(FC_DATA_IN)
		{
			t|=0x80;
		}
		
		FC_CLK_1;
		
	}
	return t;
}

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
	unsigned char key;
	// Make sure we're disconnected from the upstream port
	bUSBCTL = 0x00;
	FC_Init();
	rs232_init();
	rs232_printstr("Hello world!\r\n");
	InitializeUsbFunction(); // Initialize the USB embedded function
	while(1) 
	{ // Indefinite loop to handle keyboard scanning
		key=FC_Getdata();
		P0=key;
		if(FC_flag)
		{
			FC_flag=0;
			pbInBufferAddress[0]=0x00;
			pbInBufferAddress[1]=0x00;			
			pbInBufferAddress[2]=(key&0x10)?0x00:0x1a;//w
			pbInBufferAddress[3]=(key&0x20)?0x00:0x16;//s
			pbInBufferAddress[4]=(key&0x40)?0x00:0x04;//a
			pbInBufferAddress[5]=(key&0x80)?0x00:0x07;//d
			pbInBufferAddress[6]=(key&0x01)?0x00:0x0e;//k
			pbInBufferAddress[7]=(key&0x02)?0x00:0x0d;//j
			if(!(key&0x04))
			{
				pbInBufferAddress[6]=0x09;//f
			}
			if(!(key&0x08))
			{
				pbInBufferAddress[7]=0x0a;//g
			}
			
			bIEPDCTX_1=0x08;			
		}
		
	}
}


void IEP1InterruptHandler(void)
{
	// Just clear the NAK bit
	bIEPDCTX_1=EPBCT_NAK;
	FC_flag=1;
}


void OEP0SetLEDs(void)
{
}
