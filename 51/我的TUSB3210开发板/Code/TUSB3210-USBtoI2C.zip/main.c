#include "reg52modified.h"
#include "types.h"
#include "usb.h"
#include "tusb2136.h"
#include "stdio.h"
#include "string.h"


extern void InitializeUsbFunction(void);

extern bit deviceReady;
extern bit bSuspended;
extern bit With_PEC; 
extern bit Set_400KHz; // 1 for 400KHz; 0 for 100KHz
extern tEDB xdata tInputEndPointDescriptorBlock[3];
extern BYTE xdata pbInBufferAddress[EP_MAX_PACKET_SIZE];  // ENDPOINT 1 IN X buffer
extern BYTE xdata pb48BufferAddress[EP_MAX_PACKET_SIZE];  // use ENDPOINT 1 OUT Y buffer space for buffering the 1st 
                                                          // half of 96-byte block write for UCD9110 flash programming
extern BYTE previous_crc8;

BYTE intFlags = 0x00;
BYTE otherFlags = 0x00;
BYTE modifierByte = 0x00;

void IEP1InterruptHandler(void);
void OEP0SetLEDs(void);



void main(void)
{
#ifdef SERIALDEBUG
	// Enable serial port for debug at 9600 baud, using 48.000MHZ.
	SCON = 0x52;
	TH1 = -13;
	TMOD = 0x20;
	TR1 = 1;
	TI=1;
    puts("3:11:L32 of main_c");
#endif

    With_PEC = 1; // default is with PEC on
    previous_crc8 = 0; // starts with 0
    Set_400KHz = 0; // 100KHz // 1; // default is 400KHz

	bPUR0 = 0x07;   // enable internal pull-ups for PMB_CONTROL lines only
	bPUR1 = 0xc0;   // enable all internal pull-ups except for pins P1.6 and P1.7
	bPUR2 = 0xff;   // disable internal pull-ups
	bPUR3 = 0xff;   // disable internal pull-ups
	
	P3 = 0x00; // speed-up pull-ups
	P2 = 0x00;
	P1 = 0x15; // pull-ups for SDA, SCL and ALERT are set to 2.2K by default
	P0 = 0x07; // release SMB_DATA and SMB_CLK high; configure ALERT line as input only

    P0_5 = 1;  // Set P0 Pin 5 to a 1 so that the RESET on the TAS3108 is initialized to HIGH. (JLH 4.Aug.2006)

    bI2CSTA = 0x00; // set the I2C of EEPROM to talk at 100 kHz, clear everthing else (JLH 4.Aug.2006)
	

	// Make sure we're disconnected from the upstream port
	bUSBCTL = 0x00;
	InitializeUsbFunction(); // Initialize the USB embedded function
	
	while(!deviceReady); // Wait for the setup packets to be exchanged, etc.

	while(1) { // Indefinite loop to handle keyboard scanning
		
		if(bSuspended) {
			
            EX1 = ENABLE;  // enable P2 interrupt
                        
			// Set IDLE bit in PCON to bring MCU to suspend
			PCON |= 0x01;

            // uC wakeups from suspend
			EX1 = DISABLE;
        	bPUR0 = 0x07;   // enable internal pull-ups for PMB_CONTROL lines only
	        bPUR1 = 0xc0;   // enable all internal pull-ups except for pins P1.6 and P1.7
        	bPUR2 = 0xff;   // disable internal pull-ups
        	bPUR3 = 0xff;   // disable internal pull-ups

			// Execution will stop until we wake back up, at which point
			// we then conitnue by indicating we're no longer in Suspend
			// mode.
			bSuspended = FALSE;
		} // end of if(bSuspended)
			
		if(!deviceReady)
        {
            P1_0 = 1; // turn off USB ATTACHED LED
			continue;
        }
        else P1_0 = 0; // turn on LED indicating USB attached
	}
}


void IEP1InterruptHandler(void)
{
	// Just clear the NAK bit
	bIEPDCTX_1 = EPBCT_NAK ;
}


void OEP0SetLEDs(void)
{
}
