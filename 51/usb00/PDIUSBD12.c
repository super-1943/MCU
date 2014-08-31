#include "AT89x52.H"
#include "My_type.h"
#include "PDIUSBD12.H"


#define USB_COMMAND_ADD           1
#define USB_DATA_ADD              0

//USBоƬ��������
#define USB_DATA                  P0
#define USB_A0                    P3_5
#define USB_WR                    P3_6
#define USB_RD                    P3_7
#define USB_INT                   P3_2

/********************************************************************
�������ܣ�дUSB���
��ڲ�����һ�ֽ����
��    �أ��ޡ�
��    ע���ޡ�
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
�������ܣ���һ�ֽ�USB���ݡ�
��ڲ������ޡ�
��    �أ����ص�һ�ֽڡ�
��    ע���ޡ�
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
�������ܣ���D12��ID��
��ڲ������ޡ�
��    �أ�D12��ID��
��    ע���ޡ�
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

