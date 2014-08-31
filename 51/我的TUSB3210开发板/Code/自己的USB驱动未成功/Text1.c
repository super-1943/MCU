#include <reg52.h>
#include "types.h"
#include "tusb3210.h"
#include "serial.h"
#include "usb.h"
sbit led=P0^0;


extern uint8 usbstate;

void delay(unsigned int k);

void main(void)
{
	unsigned char t;
	EX0=0;
	led=0;
	rs232_init();
	rs232_printstr("Hello world!\r\n");
	hardware_init();
	
	while(1)
	{
		led=~led;
		delay(10);
	}
}
void serial_routine(void) interrupt 4 using 2
{
	char xdata *p;
	unsigned char i;
	if(RI)
	{/*
		switch(SBUF)
		{
		case '#':
			rs232_printstr("EP0IN buffer:");
			p=&bIEP0_BUFFER_ADDRESS;
			for(i=0;i<8;i++)
			{
				rs232_printhex(p[i]);
			}
			rs232_printstr("\r\n");
			break;
		case '$':
			rs232_printstr("EP0OUT buffer:");
			p=&bOEP0_BUFFER_ADDRESS;
			for(i=0;i<8;i++)
			{
				rs232_printhex(p[i]);
			}
			rs232_printstr("\r\n");	
			break;
		case 'w':
			rs232_printstr("SETUP buffer:");
			p=&bEP0_SETUP_ADDRESS;
			for(i=0;i<8;i++)
			{
				rs232_printhex(p[i]);
			}
			rs232_printstr("\r\n");	
			break;
		case 'q':
			rs232_printstr("\r\nbIEPBCNT_0:");
			rs232_printhex(bIEPBCNT_0);
			rs232_printstr("\r\nbOEPBCNT_0:");
			rs232_printhex(bOEPBCNT_0);
			rs232_printstr("\r\nbIEPCNFG_0:");
			rs232_printhex(bIEPCNFG_0);
			rs232_printstr("\r\nbOEPCNFG_0:");
			rs232_printhex(bOEPCNFG_0);
			rs232_printstr("\r\nbFUNADR:");
			rs232_printhex(bFUNADR);
			rs232_printstr("\r\nbWDCSR:");
			rs232_printhex(bWDCSR);
			break;
		case 'e':
			bUSBCTL|=0x80;
			break;
		default:
			rs232_printstr("no way!\r\n");
			break;
		}*/
		
		SBUF=SBUF;
		RI=0;
	}
	if(TI)
	{
		TI=0;
	}	
}




void usb_isr(void) interrupt 0 using 2
{
	EA=0;
	switch(bVECINT)
	{
	case VECINT_OUTPUT_ENDPOINT0://端点0输出中断
		bVECINT  = 0x00;
		rs232_printstr("EP0Out\r\n");			
		break;
    case VECINT_INPUT_ENDPOINT0://端点0输入中断
		bVECINT  = 0x00;
		rs232_printstr("EP0IN\r\n");
		EP0_senddata();
		break;
	case VECINT_INPUT_ENDPOINT1:
		bVECINT = 0x00;
		rs232_printstr("EP1In\r\n");
		break;

    case VECINT_STPOW_PACKET_RECEIVED:
		bVECINT  = 0x00;
		bUSBSTA = USBSTA_STPOW;
		rs232_printstr("Setup overflow\r\n");
		setup_handler();
		break;

    case VECINT_SETUP_PACKET_RECEIVED:
		bVECINT  = 0x00;
		bUSBSTA = USBSTA_SETUP;//加上这一条，就能保证下一次不会发生SETUP溢出
		rs232_printstr("\r\nSetup-");
		setup_handler();
		break;

    case VECINT_RSTR_INTERRUPT:
		bVECINT  = 0x00;
		bUSBSTA = USBSTA_RSTR;
		rs232_printstr("USB reset!\r\n");
		break;
	
	case VECINT_RESR_INTERRUPT:
		bVECINT = 0x00;
		bUSBSTA = USBSTA_RESR;
		rs232_printstr("USB resume!\r\n");
		break;
	
	case VECINT_SUSR_INTERRUPT:
		bVECINT = 0x00;
		bUSBSTA = USBSTA_SUSR;
		rs232_printstr("USB suspend!\r\n");
		break;
	default:
		rs232_printstr(" Unknown!\r\n");
		rs232_printhex(bVECINT);
		bVECINT  = 0x00;
		break;
	}
	EA=1;
}



void delay(unsigned int k)
{
	unsigned char i,j;
	for(;k;k--)
	for(i=200;i;i--)
	for(j=200;j;j--);
}


