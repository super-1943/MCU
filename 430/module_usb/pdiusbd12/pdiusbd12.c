#include "pdiusbd12.h"

void init_port(void)
{
  P1DIR&=~0x10;
  P2DIR|=0xff;
  P5DIR|=0x07;
  P6DIR|=0xc0;
  D12_DATA_OUT=0x00;
  D12_RST_DIS;
  D12_CS_0;
  D12_WR_1;
  D12_RD_1;
  D12_ALE_1;
}

void D12WriteCommand(uint8 command)
{
  D12_ALE_1;
  D12_WR_1;
  D12_RD_1;
  D12SetPortOut();
  D12_DATA_OUT=ByteReverse(0x01);//0x80;
  D12_ALE_0;
  _NOP();
  D12_DATA_OUT=ByteReverse(command);//0xbf;
  _NOP();
  D12_WR_0;
  _NOP();
  D12_WR_1;
  _NOP();  
}
void D12WriteByte(uint8 dat)
{
  D12_ALE_1;
  D12_WR_1;
  D12_RD_1;
  D12SetPortOut();
  D12_DATA_OUT=0x00;
  D12_ALE_0;
  _NOP();
  D12_DATA_OUT=ByteReverse(dat);
  _NOP();
  D12_WR_0;
  _NOP();
  D12_WR_1;
  _NOP(); 
}
uint8 D12ReadByte(void)
{
  uint8 temp1;
  D12SetPortIn();
  D12_RD_0;
  _NOP();
  D12_RD_1;
  temp1=D12_DATA_IN;
  _NOP();
  D12SetPortOut();
  return (ByteReverse(temp1));
}
uint16 D12ReadID(void)
{
  extern uint8 temp1,temp2;
  extern uint16 temp;
  D12WriteCommand(Read_ID);
  temp1=D12ReadByte();
  temp2=D12ReadByte();
  temp=temp1;
  temp|=(uint16)temp2<<8;
  return temp;
}

uint8 ByteReverse(uint8 x)
{
  uint8 i,t=0;
  for(i=0;i<8;i++)
  {
    if(x&0x01)
    {
      t|=0x80>>i;
    }
    x>>=1;
  }
  return t;
}

void UsbDisconnect(void)
{
  D12WriteCommand(Set_Mode);
  D12WriteByte(0x06);
  D12WriteByte(0x47);
  delay(10000);
}
void delay(uint16 t)
{
  uint8 i;
  while(t--)
  {
    for(i=244;i;i--);
  }
}

void UsbConnect(void)
{
  D12WriteCommand(Set_Mode);
  D12WriteByte(0x16);
  D12WriteByte(0x47);
  delay(1000);
}

void D12SelectEndpoint(uint8 endp)
{
  D12WriteCommand(0x00+endp);
  D12ReadByte();
}

uint8 D12ReadEndpointBuffer(uint8 endp,uint8 len ,uint8 * buf)
{
  uint8 i,j;
  D12SelectEndpoint(endp);
  D12WriteCommand(Read_Buffer);
  D12ReadByte();
  j=D12ReadByte();
  if(j>len)j=len;  
  D12SetPortIn();
  for(i=0;i<j;i++)
  {
    D12_RD_0;
    _NOP();
    D12_RD_1;
    *(buf+i)=D12_DATA_IN;
    _NOP();
    print_hex(*(buf+i));
    print_str(" ");
  }
  D12SetPortOut();
  return j;
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
uint8 D12ReadEndpointLastStatus(uint8 endp)
{
  uint8 i;
  D12WriteCommand(0x40+endp);
  i=D12ReadByte();
  return i;
}
void UsbBusSuspend()
{
  print_str("UsbBusSuspend()\r\n");
}

void UsbBusReset()
{
  print_str("UsbBusReset()\r\n");
  D12WriteCommand(Set_Endpoint_Enable);
  D12WriteByte(0x01);
}

void UsbEp0Out()
{
  print_str("UsbEp0Out()\r\n");
  extern uint8 Buffer[16];
  if(D12ReadEndpointLastStatus(0)&0x20)//D5==1,SETUP PACKET
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
}

void UsbEp0In()
{
  print_str("UsbEp0In()\r\n");
}

void UsbEp1Out()
{
  print_str("UsbEp1Out()\r\n");
}

void UsbEp1In()
{
  print_str("UsbEp1In()\r\n");
}

void UsbEp2Out()
{
  print_str("UsbEp2Out()\r\n");
}

void UsbEp2In()
{
  print_str("UsbEp2In()\r\n");
}