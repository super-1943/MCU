#include "AT89x52.H"
#include "My_type.h"
#include "PDIUSBD12.H"


#define USB_COMMAND_ADD           1
#define USB_DATA_ADD              0

//USB芯片连接引脚
#define USB_DATA                  P0
#define USB_A0                    P3_5
#define USB_WR                    P3_6
#define USB_RD                    P3_7
#define USB_INT                   P3_2

/********************************************************************
函数功能：写USB命令。
入口参数：一字节命令。
返    回：无。
备    注：无。
********************************************************************/
void WriteUsbCommand(uint8 usb_command)
{
	USB_A0=USB_COMMAND_ADD;
	USB_DATA=usb_command;
	USB_WR=0;
	USB_WR=1;
	USB_DATA=0xFF;
}
////////////////////////End of function//////////////////////////////

/********************************************************************
函数功能：读一字节USB数据。
入口参数：无。
返    回：读回的一字节。
备    注：无。
********************************************************************/
uint8 ReadUsbData(void)
{
	uint8 temp;
	USB_A0=USB_DATA_ADD;
	USB_RD=0;
	temp=USB_DATA;
	USB_RD=1;
	return temp;
}
////////////////////////End of function//////////////////////////////

/********************************************************************
函数功能：读D12的ID。
入口参数：无。
返    回：D12的ID。
备    注：无。
********************************************************************/
uint16 ReadD12ID(void)
{
	uint16 id;
	WriteUsbCommand(Read_ID);
	((uint8*)&id)[1]=ReadUsbData();
	((uint8*)&id)[0]=ReadUsbData();
	return id;
}
////////////////////////End of function//////////////////////////////

