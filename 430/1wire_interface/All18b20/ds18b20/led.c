/**************************************************************************
发送164数据
**************************************************************************/
#include "msp430x14x1.h"
void send164(unsigned char a)
{
   unsigned char i;
   for(i=0;i<8;i++)
   {
     if(a&0x80)
     {
       P5OUT|=0x80;
     }
     else
     {
       P5OUT&=~0x80;
     }
     P5OUT&=~0x40;
     P5OUT|=0x40;
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
void show(unsigned char *d)
{
  unsigned char i;
  const unsigned char table[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x7e,0x71,0x40,0x00};
                            /*  0    1    2     3    4   5     6    7    8    9    a    b    c    d    e    f   -    ' '*/
  for(i=0;i<6;i++)
  {
    send164(~(1<<i));
    send164(table[d[5-i]]);
    delay_led(450);
  }
  
}
void init_led(void)
{
  P5DIR|=0xc0;
}