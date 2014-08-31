#include "at89x52.H"
#include "uart.h"
#include "pdiusbd12.h"
#include "usb.h"
uint8 ConfigValue=0;
uint8 Ep1InIsBusy;
uint8 *pSendData;
uint16 SendLength;
uint8 NeedZeroPacket;
uint8 idata Buffer[16];


void SendReport(void)
{
	uint8 Buf[8]={0};
	uint8 i=2;
	P1=0xff;
	if(P1==0xff)
	{
		return ;
	}
	if(!(P1&0x01))
	{
		Buf[0]|=0x02;
	}
	if(!(P1&0x02))
	{
		Buf[i++]=0x59;
	}
	if(!(P1&0x04))
	{
		Buf[i++]=0x5a;
	}
	if(!(P1&0x08))
	{
		Buf[i++]=0x5b;
	}
	if(!(P1&0x10))
	{
		Buf[i++]=0x5c;
	}
	if(!(P1&0x20))
	{
		Buf[i++]=0x5d;
	}
	if(!(P1&0x40))
	{
		Buf[i++]=0x5e;
	}
	if(!(P1&0x80))
	{
		Buf[i++]=0x5f;
	}
	print_str("·¢ËÍ±¨¸æ\r\n");
	D12WriteEndpointBuffer(3,8,Buf);
	Ep1InIsBusy=1;	
}
int main(void)
{
	uint16 i;
	uint8 InterruptSource;
	init_uart();
	UsbDisconnect();
	i=ReadD12ID();
	print_str("ID:");
	print_16hex(i);
	UsbConnect();
	while(1)
	{
		USB_INT=1;
		if(USB_INT==0)		
		{
			D12WriteCommand(Read_Interrupt_Register);			
			InterruptSource=D12ReadByte();			
			if(InterruptSource&0x80)UsbBusSuspend();			
			if(InterruptSource&0x40)UsbBusReset();			
			if(InterruptSource&0x01)UsbEp0Out();			
			if(InterruptSource&0x02)UsbEp0In();			
			if(InterruptSource&0x04)UsbEp1Out();			
			if(InterruptSource&0x08)UsbEp1In();			
			if(InterruptSource&0x10)UsbEp2Out();	
			if(InterruptSource&0x20)UsbEp2In();
		}
		if(ConfigValue!=0)
		{
			SendReport();
		}
	}
}