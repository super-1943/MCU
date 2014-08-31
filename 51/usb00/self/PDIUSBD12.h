
#ifndef __PDIUSBD12_H__
#define __PDIUSBD12_H__


//PDIUSBD12.h
//PDIUSBD12的命令和数据定义
#define USB_COMMAND_ADD           1
#define USB_DATA_ADD              0

//USB芯片连接引脚
#define USB_DATA                  P0
#define USB_A0                    P3_5
#define USB_WR                    P3_6
#define USB_RD                    P3_7
#define USB_INT                   P3_2
#define D12SetPortIn()            USB_DATA=0xff
#define D12SetPortOut()

//*************************************************
//端点号定义
#define CONTROL_POINT_OUT        0x00
#define CONTROL_POINT_IN         0x80
#define POINT_1_OUT              0x01
#define POINT_1_IN               0x81
#define MAIN_POINT_OUT           0x02
#define MAIN_POINT_IN            0x82
//*************************************************
//*************************************************
//初始化命令
#define Set_Address              0xD0
#define Set_Endpoint_Enable      0xD8
#define Set_Mode                 0xF3
#define Read_ID                  0xFD
#define Set_DMA                  0xFB
//*************************************************


//*************************************************
//数据流命令
#define Read_Interrupt_Register  0xF4
#define Select_EndPoint          0X00
#define Select_Endpoint_C_OUT    0X00
#define Select_Endpoint_C_IN     0X01
#define Select_Endpoint_1_OUT    0X02
#define Select_Endpoint_1_IN     0X03
#define Select_Endpoint_2_OUT    0X04
#define Select_Endpoint_2_IN     0X05
#define Read_Last_Status         0X40
#define Read_Last_Status_C_OUT   0X40
#define Read_Last_Status_C_IN    0X41
#define Read_Last_Status_1_OUT   0X42
#define Read_Last_Status_1_IN    0X43
#define Read_Last_Status_2_OUT   0X44
#define Read_Last_Status_2_IN    0X45
#define Read_Buffer              0XF0
#define Write_Buffer              0XF0
#define Set_Endpoint_Status_C_OUT 0X40
#define Set_Endpoint_Status_C_IN  0X41
#define Set_Endpoint_Status_1_OUT 0X42
#define Set_Endpoint_Status_1_IN  0X43
#define Set_Endpoint_Status_2_OUT 0X44
#define Set_Endpoint_Status_2_IN  0X45
#define Ack_Setup                 0XF1
#define Clear_Buffer              0XF2
#define Validate_Buffer           0XFA
//*************************************************

//*************************************************
//普通命令
#define Send_Resume               0XF6
#define Read_Current_Frame_Number 0XF5
//*************************************************

//*************************************************
//一些数据的定义
#define Endpoint_Enable           0X01
#define Endpoint_Disenable        0X00

#define Mode0_and_no_connect      0X04
#define Mode1_and_no_connect      0X44
#define Mode2_and_no_connect      0X84
#define Mode3_and_no_connect      0XC4
#define Mode0_and_connect         0X14
#define Mode1_and_connect         0X54
#define Mode2_and_connect         0X94
#define Mode3_and_connect         0XD4
#define Mode_Set_secend_byte      0X8B


void D12WriteCommand(uint8);
uint8 D12ReadByte(void);
uint16 ReadD12ID(void);
void D12WriteByte(uint8 usb_data);
void DelayXms(uint16 x);
void UsbDisconnect(void);
void UsbConnect(void);
void D12SelectEndpoint(uint8 endp);
uint8 D12ReadEndpointBuffer(uint8 endp,uint8 len ,uint8 * buf);
void UsbBusSuspend();
void UsbBusReset();
void UsbEp0Out();
void UsbEp0In();
void UsbEp1Out();
void UsbEp1In();
void UsbEp2Out();
void UsbEp2In();
void D12ValidateBuffer(void);
uint8 D12WriteEndpointBuffer(uint8 Endp,uint8 Len,uint8 *Buf);
void D12SetAddress(uint8 Addr);
void UsbEp0SendData();
void D12SetEndpointEnable(uint8 Enable);
#endif
