#include <msp430x15x.h>
#include"DAmodule.h"
#include"Frequence.h"
#include"ds1867_100module.h"
unsigned char FF_flag=0;
unsigned int g=4095,s=0;
double f,f1,f2;
/******************************************************/
double myfreq=0;//»ñÈ¡ÆµÂÊ
double origfreq=0;
int main( void )
{  
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;
  Init_FF();
  InitDac12();
  init_1867_100();
  for(;;)
  {
  Dac12Write(g);
  g--; 
  delay_DA12(1);
  if(FF_flag==1)
      { P1IE&=~0x01;
      break;
      }
  }
  f1=get_fudu(g);
 s=(128*f1)/(5.0-f1/2);
  send_1867(0,s,0);
  freq_cap();
  origfreq=get_origfreq()/2;
  myfreq=get_freq(origfreq);
  f2=get_fudu_xiuzheng(g,myfreq);
  f=(f1+f2)/2;
}
#pragma vector=PORT1_VECTOR
__interrupt void PORT1()
{P1IFG=0;
 FF_flag=1;
}
#pragma vector=TIMERA0_VECTOR
__interrupt void timer_a0(void)
{
  buff[index++]=CCR0;
  flag_freq++;
}
