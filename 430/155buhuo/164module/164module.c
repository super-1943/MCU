#include"164module.h"
#include <msp430x15x.h>
#define data_1  P4OUT|=0x02;
#define data_0  P4OUT&=~0x02;
#define SCLK_1  P4OUT|=0x08;
#define SCLK_0  P4OUT&=~0x08;
unsigned char dig[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
void send_bit_164(unsigned char i)
{
  if(i)
  {
   data_1;
  }
 else
 {
    data_0;
 }
 SCLK_0;
 SCLK_1;
}
void send_byte_164(unsigned char i)
{unsigned char j;
for(j=0;j<8;j++)
 {send_bit_164(i&0x80);
 i<<=1;
 }
}
void delay_164(unsigned int ms)
{ unsigned int i,j;
  for(i=0;i<ms;i++)
    for(j=0;j<130;j++);
}
void show_164(unsigned char buffer[])
{unsigned char i;
 for(i=0;i<6;i++)
 {send_byte_164(1<<i);
 send_byte_164(dig[buffer[i]]);
 delay_164(3);
 }
}
