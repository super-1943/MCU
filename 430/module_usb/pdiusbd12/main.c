
#include "pdiusbd12.h"
#include "usart.h"
uint8 temp1,temp2;
uint16 temp;
uint8 InterruptSource;
uint8 Buffer[16];
int main( void )
{
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;
  init_usart();
  print_str("Now initial...");
  init_port();
  temp=D12ReadID();
  print_int(temp);
  UsbDisconnect();
  delay(1000);
 D12WriteCommand(Set_Address);
 D12WriteByte(0x80);
 D12WriteCommand(Set_Endpoint_Enable);
 D12WriteByte(0x01);
  UsbConnect();
  while(1)
  {
      //temp=D12ReadID();
    if(D12GetIntPin()==0)
    {
      D12WriteCommand(Read_Interrupt_Register);
      Buffer[0]=D12ReadByte();
      Buffer[1]=D12ReadByte();
      InterruptSource=Buffer[0];
      if(InterruptSource&0x80){UsbBusSuspend();continue;}
      if(InterruptSource&0x40){UsbBusReset();continue;}
      if(InterruptSource&0x01){UsbEp0Out();continue;}
      if(InterruptSource&0x02){UsbEp0In();continue;}
      if(InterruptSource&0x04){UsbEp1Out();continue;}
      if(InterruptSource&0x08){UsbEp1In();continue;}
      if(InterruptSource&0x10){UsbEp2Out();continue;}
      if(InterruptSource&0x20){UsbEp2In();continue;}
    }
  }
}
