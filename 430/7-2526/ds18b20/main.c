#include "ds18b20.h"
#include "led.h"
unsigned char i,count;
int tmp;
/*****************************
数组存放转换结果，以便显示
第一字节：符号。0+，1-
第二字节：整数部分
第三字节：小数部分=data*2^(-4)
******************************/
char buffer[6]={0};
void newshow(void)
{
  unsigned char dst[6];
  const unsigned char table[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x7e,0x71,0x40,0x00};
                            /*  0    1    2     3    4   5     6    7    8    9    a    b    c    d    e    f   -    ' '*/
  dst[0]=buffer[0]?16:17;
  dst[1]=buffer[1]/100;
  dst[2]=(buffer[1]%100)/10;
  dst[3]=buffer[1]%10;
  dst[4]=buffer[2]*5/8;
  dst[5]=0;
  for(i=0;i<6;i++)
  {
    send164(~(1<<i));
    if(i==2)
    {
    send164(table[dst[5-i]]|0x80);
    }
    else
    {
      send164(table[dst[5-i]]);
    }
    delay_led(450);
  }
}
//////////\/\/\/\/\/\/\/\/\/\/\/\//\/\/\/\\//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\///////
//////////\/\/\/\/\/\/\/\/\/\/\/\//\/\/\/\\//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\///////
//////////\/\/\/\/\/\/\/\/\/\/\/\//\/\/\/\\//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\///////
//////////\/\/\/\/\/\/\/\/\/\/\/\//\/\/\/\\//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\///////
int main( void )
{
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;
  init_device();
  init_led();
  TACTL=TASSEL1+TACLR;
  CCR0=0;
  CCTL0=CCIE;
  TACTL|=MC1;
  _EINT();
  while(1)
  {
    convert_t(tmp,buffer);
    _NOP();
    newshow();
  }
}
//////////\/\/\/\/\/\/\/\/\/\/\/\//\/\/\/\\//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\///////
//////////\/\/\/\/\/\/\/\/\/\/\/\//\/\/\/\\//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\///////
//////////\/\/\/\/\/\/\/\/\/\/\/\//\/\/\/\\//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\///////
#pragma vector=TIMERA0_VECTOR
__interrupt void timer_a(void)
{
  CCR0=0;
  count++;
  if(count==14)
  {
    start_convert();
  }
  if(count==28)
  {
    tmp=read_temperature();
    count=0;
  }
  
}