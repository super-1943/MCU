
#include "msp430x14x.h"
void send164(unsigned char a)
{
   unsigned char i;
   for(i=0;i<8;i++)
   {
     if(a&0x80)
     {
       P2OUT|=0x01;
     }
     else
     {
       P2OUT&=~0x01;
     }
     P2OUT&=~0x02;
     P2OUT|=0x02;
     a<<=1;
   }
}
void delay_led(unsigned int a)
{
  while(a--);
}
/*************************************************************************
显示函数，参数需要一个至少6字节的数组
*************************************************************************/
void show(unsigned char d)
{
  const unsigned char table[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x7e,0x71};
  send164(~table[d]);
  delay_led(450);
}
void init_led(void)
{
  P2DIR|=0x03;
}
int main( void )
{
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;
    init_led();
    show(1);
    while(1);

}
