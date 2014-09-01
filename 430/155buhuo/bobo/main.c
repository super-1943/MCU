
#include "msp430x14x.h"
#include "usart.h"
unsigned int zhouqi=100,xiangcha=50;
void delay(unsigned int i)
{
    while(i--);
}
void bobo(void)
{

  while(1)
  {

  }
}
int main( void )
{
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;
  init_usart();
  P2DIR|=0xff;
  P2OUT=0x00;
  P5DIR|=0x20;
  P5OUT=0x00;
  while(1)
  {
      P2OUT^=0xff;      
      delay(xiangcha);
      P5OUT^=0xff;
      delay(zhouqi-xiangcha);
  }
}
/************************************************
通信协议：
第一字节为'#'
第二字节  1---发送周期     0----发送相位差
第三字节  发送的数据

************************************************/
#pragma vector=USART0RX_VECTOR
__interrupt void usart0_rx(void)
{
    static unsigned char i;
    
    if(U0RXBUF=='#')
    {
        while((IFG1&URXIFG0)==0);
        i=U0RXBUF;
        while((IFG1&URXIFG0)==0);
        if(i)
        {
            zhouqi=U0RXBUF;
        }
        else
        {
            xiangcha=U0RXBUF;            
        }
    }

}