#include "AT89x52.H"
#include "My_type.h"
#include "PDIUSBD12.H"
#include "uart.h"

extern code uint8 DeviceDescriptor[18];
extern code uint8 ConfigurationDescriptor[];
extern code uint8 LanguageId[4];
extern code uint8 ManufacturerStringDescriptor[52];
extern code uint8 ProductStringDescriptor[28];
extern code uint8 SerialNumberStringDescriptor[22];
extern code uint8 ReportDescriptor[52];
extern uint8 Ep1InIsBusy;
extern uint8 *pSendData;
extern uint16 SendLength;
extern uint8 NeedZeroPacket;
extern uint8 ConfigValue;
#define GET_STATUS         0
#define CLEAR_FEATURE      1
#define SET_FEATURE        3
#define SET_ADDRESS        5
#define GET_DESCRIPTOR     6
#define SET_DESCRIPTOR     7
#define GET_CONFIGURATION  8
#define SET_CONFIGURATION  9
#define GET_INTERFACE      10
#define SET_INTERFACE      11
#define SYNCH_FRAME        12
/********************************************************************
函数功能：写USB命令。
入口参数：一字节命令。
返    回：无。
备    注：无。
********************************************************************/
void D12WriteCommand(uint8 usb_command)
{
	USB_A0=USB_COMMAND_ADD;
	USB_DATA=usb_command;
	USB_WR=0;
	USB_WR=1;
	USB_DATA=0xFF;
}
void D12WriteByte(uint8 usb_data)
{
	USB_A0=USB_DATA_ADD;
	USB_DATA=usb_data;
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
uint8 D12ReadByte(void)
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
	D12WriteCommand(Read_ID);
	((uint8*)&id)[1]=D12ReadByte();
	((uint8*)&id)[0]=D12ReadByte();
	return id;
}

void DelayXms(uint16 x)
{
	uint16 i,j;
	for(i=0;i<x;i++)
	{
		for(j=0;j<227;j++)
		;
	}
}

void UsbDisconnect(void)
{
	print_str("断开usb连接.\r\n");
	D12WriteCommand(Set_Mode);
	D12WriteByte(0x06);
	D12WriteByte(0x47);
	DelayXms(1000);	
}

void UsbConnect(void)
{
	print_str("连接usb.\r\n");
	D12WriteCommand(Set_Mode);
	D12WriteByte(0x16);
	D12WriteByte(0x47);	
}

void D12SelectEndpoint(uint8 endp)
{

	D12WriteCommand(0x00+endp);

}
void D12SetEndpointEnable(uint8 Enable)
{
	D12WriteCommand(Set_Endpoint_Enable);
	if(Enable!=0)
	{
		D12WriteByte(0x01);
	}
	else
	{
		D12WriteByte(0x00);
	}
}

uint8 D12ReadEndpointBuffer(uint8 endp,uint8 len ,uint8 * buf)
{

	uint8 i,j;	
	D12SelectEndpoint(endp);	
	D12WriteCommand(Read_Buffer);	
	D12ReadByte();	
	j=D12ReadByte();
	if(j>len)j=len; 
	for(i=0;i<j;i++)	
	{
		USB_A0=USB_DATA_ADD;
		USB_DATA=0xff;
		USB_RD=0;	
		*(buf+i)=USB_DATA;			
		USB_RD=1;		
		print_hex(*(buf+i));		
		print_str(" ");	
	}

	D12SetPortOut();	
	return j;
}

void UsbBusSuspend()
{

	print_str("UsbBusSuspend()\r\n");

}

void UsbBusReset()
{

	print_str("UsbBusReset()\r\n");
	Ep1InIsBusy=0;

}
uint8 D12ReadEndpointLastStatus(uint8 endp)
{
	D12WriteCommand(0x40+endp);
	return D12ReadByte();
}
void D12ClearBuffer(void)
{
	D12WriteCommand(Clear_Buffer);
}
void D12AcknowledgeSetup(void)
{
	D12SelectEndpoint(1);
	D12WriteCommand(Ack_Setup);
	D12SelectEndpoint(0);
	D12WriteCommand(Ack_Setup);	
}
void UsbEp0Out()
{
	extern uint8 idata Buffer[16];
	print_str("UsbEp0Out()\r\n");
	if(D12ReadEndpointLastStatus(0)&0x20)
	{
		D12ReadEndpointBuffer(0,16,Buffer);
		D12AcknowledgeSetup();
		D12ClearBuffer();
	}
	else
	{
		D12ReadEndpointBuffer(0,16,Buffer);
		D12ClearBuffer();
	}
	if((Buffer[0]&0x80)==0x80)
	{
		switch((Buffer[0]>>5)&0x03)
		{
			case 0:
				print_str("USB标准输入请求,");
				switch(Buffer[1])
				{
					case GET_CONFIGURATION:
						print_str("获取配置\r\n");
						break;
					case GET_DESCRIPTOR:
						print_str("获取描述符----");
						switch(Buffer[3])
						{
							case 0x01:
								print_str("设备描述符\r\n");
								pSendData=DeviceDescriptor;
								SendLength=18;
								NeedZeroPacket=0;
								UsbEp0SendData();
								break;
							case 0x02:
								print_str("配置描述符\r\n");
								pSendData=ConfigurationDescriptor;
								SendLength=ConfigurationDescriptor[3];
								SendLength=SendLength*256+ConfigurationDescriptor[2];	
								SendLength=Buffer[6];
								UsbEp0SendData();							;
								break;
							case 0x03:
								print_str("字符串描述符\r\n");
								switch(Buffer[2])
								{
									case 0:
										print_str("语言ID\r\n");
										
										pSendData=LanguageId;
										SendLength=LanguageId[0];
										break;
									case 1:
										print_str("厂商描述\r\n");
										pSendData=ManufacturerStringDescriptor;
										SendLength=ManufacturerStringDescriptor[0];
										break;
									case 2:
										print_str("产品描述\r\n");
										pSendData=ProductStringDescriptor;
										SendLength=ProductStringDescriptor[0];
										break;
									case 3:
										print_str("产品序列号\r\n");
										pSendData=SerialNumberStringDescriptor;
										SendLength=SerialNumberStringDescriptor[0];
										break;
									default:
										print_str("未知的索引值\r\n");
										SendLength=0;
										NeedZeroPacket=1;
										break;
										
								}
								if(Buffer[6]>SendLength)
								{
									if(SendLength%DeviceDescriptor[7]==0)
									{
										NeedZeroPacket=1;
									}
								}
								else
								{
									SendLength=Buffer[6];
								}
								UsbEp0SendData();
								break;	
							case 0x22://report descriptor
								print_str("报告描述符\r\n");	
								pSendData=ReportDescriptor;
								SendLength=sizeof(ReportDescriptor);
								if(Buffer[6]>SendLength)
								{
									if(SendLength%DeviceDescriptor[7]==0)
									{
										NeedZeroPacket=1;
									}
								}
								else
								{
									SendLength=Buffer[6];
								}
								UsbEp0SendData();
								break;
							default:
								print_str("其他描述符，描述符代码：");
								print_hex(Buffer[3]);
								print_str("\r\n");
								break;
						}
						break;			
					case GET_INTERFACE:
						print_str("获取接口\r\n");
						break;
					case GET_STATUS:
						print_str("获取状态\r\n");
						break;	
					case SYNCH_FRAME:
						print_str("同步帧\r\n");
						break;
					default:
						print_str("错误：未定义的标准输入请求。\r\n");
						break;				
				}
				break;
			case 1:
				print_str("USB类输入请求\r\n");
				break;
			case 2:
				print_str("USB厂商输入请求\r\n");
				break;
			default:
				print_str("错误：未定义的输入请求\r\n");
				break;
			}
	}
	else
	{
		switch(((Buffer[0]>>5)&0x03))
		{
			case 0:
				print_str("USB标准输出请求：");
				switch(Buffer[1])
				{					
					case CLEAR_FEATURE:
						print_str("清除特性\r\n");
						break;
					case SET_ADDRESS:
						print_str("设置地址.地址为：");
						print_hex(Buffer[2]);
						print_str("\r\n");
						D12SetAddress(Buffer[2]);
						SendLength=0;
						NeedZeroPacket=1;
						UsbEp0SendData();
						break;
					case SET_CONFIGURATION:
						print_str("设置配置\r\n");
						ConfigValue=Buffer[2];
						D12SetEndpointEnable(Buffer[2]);
						SendLength=0;
						NeedZeroPacket=1;
						UsbEp0SendData();
						break;
					case SET_DESCRIPTOR:
						print_str("设置描述符\r\n");
						break;
					case SET_FEATURE:
						print_str("设置特性\r\n");
						break;	
					case SET_INTERFACE:
						print_str("设置接口\r\n");
						break;
					default:
						print_str("错误：未定义的标准输出请求\r\n");
						break;
					}
				break;
			case 1:
				print_str("USB类输出请求：\r\n");
				switch(Buffer[1])
				{
					case 0x0a://Set_Idle
						print_str("设置空闲\r\n");
						SendLength=0;
						NeedZeroPacket=1;
						UsbEp0SendData();
						break;
					default:
						print_str("未知请求\r\n");
						break;
				}						
				break;
			case 2:
				print_str("USB厂商输出请求");
				break;
			default:
				print_str("错误：未定义的输出请求\r\n");
				break;							
		}
	}
}

void UsbEp0In()
{
	print_str("UsbEp0In()\r\n");
	D12ReadEndpointLastStatus(1);
	UsbEp0SendData();
}

void UsbEp1Out()
{
	uint8 Buf[1];
	print_str("UsbEp1Out()\r\n");
	D12ReadEndpointLastStatus(2);
	D12ReadEndpointBuffer(2,1,Buf);
	D12ClearBuffer();
	P1=~Buf[0];
}

void UsbEp1In()
{

	print_str("UsbEp1In()\r\n");
	D12ReadEndpointLastStatus(3);
	Ep1InIsBusy=0;
}

void UsbEp2Out()
{

	print_str("UsbEp2Out()\r\n");

}

void UsbEp2In()
{

	print_str("UsbEp2In()\r\n");

}



void D12ValidateBuffer(void)
{
	D12WriteCommand(Validate_Buffer);
}
uint8 D12WriteEndpointBuffer(uint8 Endp,uint8 Len,uint8 *Buf)
{
	uint8 i;
	D12SelectEndpoint(Endp);
	D12WriteCommand(Write_Buffer);
	D12WriteByte(0);
	D12WriteByte(Len);
	print_str("写端点");
	print_longint(Endp/2);
	print_str("缓冲区");
	print_longint(Len);
	print_str("字节.\r\n");
	
	D12SetPortOut()
	USB_A0=USB_DATA_ADD;
	for(i=0;i<Len;i++)
	{
		USB_DATA=*(Buf+i);
		USB_WR=0;
		USB_WR=1;
	}
	D12SetPortIn();
	D12ValidateBuffer();
	return Len;
}


void UsbEp0SendData()
{

	if(SendLength>DeviceDescriptor[7])
	{
		D12WriteEndpointBuffer(1,DeviceDescriptor[7],pSendData);
		SendLength-=DeviceDescriptor[7];
		pSendData+=DeviceDescriptor[7];
	}
	else
	{
		if(SendLength!=0)
		{
			D12WriteEndpointBuffer(1,SendLength,pSendData);
			SendLength=0;
		}
		else
		{
			if(NeedZeroPacket==1)
			{
				D12WriteEndpointBuffer(1,0,pSendData);
				NeedZeroPacket=0;
			}
		}
	}
}

void D12SetAddress(uint8 Addr)
{
	D12WriteCommand(Set_Address);
	D12WriteByte(0x80|Addr);
}
////////////////////////End of function//////////////////////////////

