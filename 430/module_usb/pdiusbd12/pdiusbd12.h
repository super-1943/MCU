#ifndef __PDIUSBD12_H__
#define __PDIUSBD12_H__

#include <msp430x14x.h>
#include "My_Type.h"
#include "usart.h"
#define D12_COMMAND_ADD 1
#define D12_DATA_ADD    0

/************************
P6.7-----WR
P6.6-----RD
P5.1-----ALE
P5.2-----CS
P5.3-----SUSP
P5.0-----RST
P1.4-----INT
P2fanxu---DATA
************************/
#define D12_DATA_OUT  P2OUT
#define D12_DATA_IN   P2IN 
#define D12_ALE_1     P5OUT|= 0x02
#define D12_ALE_0     P5OUT&=~0x02
#define D12_WR_1      P6OUT|= 0x80
#define D12_WR_0      P6OUT&=~0x80
#define D12_RD_1      P6OUT|= 0x40
#define D12_RD_0      P6OUT&=~0x40
#define D12_INT       (P1IN&0x10)
#define D12_RST_EN    P5OUT&=~0x01
#define D12_RST_DIS   P5OUT|= 0x01
#define D12_CS_1      P5OUT|= 0x04
#define D12_CS_0      P5OUT&=~0x04

#define D12SetCommandAddr()
#define D12SetDataAddr()

#define D12SetWr()
#define D12ClrWr()

#define D12SetRd()
#define D12ClrRd()

#define D12GetIntPin() D12_INT


#define D12GetData() D12_DATA_IN
#define D12SetData(Value) D12_DATA_OUT=Value

#define D12SetPortIn()  P2DIR&=0x00
#define D12SetPortOut() P2DIR|=0xff

#define Read_ID 0xfd

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


void init_port(void);

void D12WriteCommand(uint8);

void D12WriteByte(uint8);

uint8 D12ReadByte(void);

uint16 D12ReadID(void);

void D12SelectEndpoint(uint8 endp);

uint8 D12ReadEndpointBuffer(uint8 endp,uint8 len, uint8 * buf);

void D12AcknowledgeSetup(void);

void D12ClearBuffer(void);

uint8 ByteReverse(uint8 x);

uint8 D12ReadEndpointLastStatus(uint8 endp);

void UsbDisconnect(void);

void delay(uint16 t);

void UsbConnect(void);

void UsbBusSuspend();

void UsbBusReset();

void UsbEp0Out();

void UsbEp0In();

void UsbEp1Out();

void UsbEp1In();

void UsbEp2Out();

void UsbEp2In();
#endif
