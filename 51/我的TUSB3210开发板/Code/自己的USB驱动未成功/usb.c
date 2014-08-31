#include <reg52.h>
#include "types.h"
#include "tusb3210.h"
#include "usb.h"
#include "serial.h"

uint8 *pSendData;
uint8 SendLength;
uint8 NeedZeroPacket;
enum STATEMACHINE kkkstate;

void hardware_init(void)
{
	USB_DISCONNECT;
	bMCNFG=0x01;//SDW=1;XINT=0;
	bPUR3=0x00;
	bPUR2=0x00;
	bPUR1=0x00;
	bPUR0=0x00;//all pull up are connected to pins
	bWDCSR=0x00;
	
	bUSBCTL=0x00;
	bUSBMSK=USBMSK_STPOW|USBMSK_RWUP|USBMSK_SETUP|USBMSK_RESR|USBMSK_SUSR|USBMSK_RSTR;
	bFUNADR=0x00;
	bIEPCNFG_0=EPCNF_UBME|EPCNF_USBIE;
	bIEPBCNT_0=EPBCT_NAK;
	bOEPCNFG_0=EPCNF_UBME|EPCNF_USBIE;
	bOEPBCNT_0=EPBCT_NAK;
	
	
	kkkstate=STATE_IDLE;
	
	
	EX0=1;
	ES=1;
	PS=1;
	IT0=0;
	USB_CONNECT;
	EA=1;
}
uint8 EP0_put(uint8 len)
{
	uint8 i;
	if(len>8)
	{
		for(i=0;i<8;i++)
		{
			*(pbIEP0_BUFFER_ADDRESS+i)=*pSendData++;
		}
		return 8;
	}
	else
	{
		for(i=0;i<len;i++)
		{
			*(pbIEP0_BUFFER_ADDRESS+i)=*pSendData++;
		}
		return len;
	}
}
void EP0_senddata(void)
{
	unsigned char i;
	if(kkkstate==STATE_GETDSC)
	{
		i=EP0_put(SendLength);
		SendLength-=i;
		pSendData+=i;
		bIEPBCNT_0=i;
		SETUP_IN;
		if(SendLength==0)
		{
			kkkstate=STATE_IDLE;
		}
	}
	else if(kkkstate==STATE_IDLE)
	{
		SETUP_OUT;
		bOEPBCNT_0=0;		
	}
	else if(kkkstate==STATE_SETADDR)
	{
		SETUP_OUT;
		bOEPBCNT_0=0;
		kkkstate=STATE_IDLE;
	}
	else
	{
		
	}

}
void setup_handler(void)
{
	unsigned char i,buffer[8];
	ENTER_SETUP;
	rs232_printstr("\r\n");
	for(i=0;i<8;i++)
	{
		buffer[i]=pbEP0_SETUP_ADDRESS[i];
	}
	for(i=0;i<8;i++)
	{
		rs232_printhex(buffer[i]);
		rs232_printstr(" ");
	}
	rs232_printstr("\r\n");
	if(bmRequestType&0x80)//in
	{
		SETUP_IN;//tusb3210 to host
		switch(bRequest)
		{
		case GET_CONFIGURATION:
			rs232_printstr("GET CFG;\r\n");
			break;
		case GET_DESCRIPTOR:
			rs232_printstr("Get Desc->");
			kkkstate=STATE_GETDSC;
			switch(bValueH)
			{
			case 1:
				rs232_printstr("Dev\r\n");
				pSendData=DeviceDescriptor;
				SendLength=18;
				EP0_senddata();
				bOEPBCNT_0=0;
				break;
			case 0x02:
				rs232_printstr("Cfg\r\n");
			//	pSendData=ConfigurationDescriptor;
				SendLength=0;
				EP0_senddata();
				bOEPBCNT_0=0;
				break;
			case 0x03:
				rs232_printstr("Str->\r\n");
				switch(bValueL)
				{
				case 0:
					rs232_printstr("LangID\r\n");
					pSendData=LanguageId;
					SendLength=LanguageId[0];
					break;
				case 1:
					rs232_printstr("Vendor\r\n");
					pSendData=ManufacturerStringDescriptor;
					SendLength=ManufacturerStringDescriptor[0];
					break;
				case 2:
					rs232_printstr("Prod\r\n");
					pSendData=ProductStringDescriptor;
					SendLength=ProductStringDescriptor[0];
					break;
				case 3:
					rs232_printstr("Ser\r\n");
					pSendData=SerialNumberStringDescriptor;
					SendLength=SerialNumberStringDescriptor[0];
					break;
				default:
					rs232_printstr("Unkn\r\n");
					SendLength=0;
					break;
				}
				if(bLengthL<SendLength)
				{
					SendLength=bLengthL;
				}
				EP0_senddata();
				bOEPBCNT_0=0;
				break;	
			case 0x22://report descriptor
				rs232_printstr("Repo\r\n");	
				pSendData=ReportDescriptor;
				SendLength=sizeof(ReportDescriptor);
				if(bLengthL<SendLength)
				{
					SendLength=bLengthL;
				}
				EP0_senddata();
				break;
			default:
				rs232_printstr("Other：");
				rs232_printhex(bValueH);
				rs232_printstr("\r\n");
				break;
			}
			break;			

		default:
			rs232_printstr("Error\r\n");
			break;				
		}
	}
	else
	{
		SETUP_OUT;
		switch(bRequest)
		{
		case CLEAR_FEATURE:
			rs232_printstr("CLFE\r\n");
			break;
		case SET_ADDRESS:
			rs232_printstr("SA:");
			rs232_printhex(bValueL);
			rs232_printstr("\r\n");
			kkkstate=STATE_SETADDR;
			bFUNADR=bValueL;
			SETUP_IN;//期待IN数据包
			bIEPBCNT_0=0;
			break;
		case SET_CONFIGURATION:
			rs232_printstr("SC\r\n");
			SendLength=0;
			bIEPCNFG_0&=~EPCNF_TOGLE;
			bIEPBCNT_0=0;
			bOEPBCNT_0=0;
			break;
		case 0x0a://Set_Idle
			rs232_printstr("SetIdle\r\n");
			bIEPBCNT_0=0;
			bOEPBCNT_0=0;
			break;
		default:
			rs232_printstr("Unkn\r\n");
			break;
		}
	}
}