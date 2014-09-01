
#include "msp430x16x.h"
#include "DAC902.h"

unsigned int temp=65535,time;
unsigned char lsb=0;
unsigned char msb=0;

void init_msp430(void)
{ 
    unsigned char i;  
    BCSCTL1&=~XT2OFF;
    do
    {
        IFG1&=~OFIFG;
        for(i=0xff;i;i--);
    }
    while((IFG1&OFIFG)!=0);
    BCSCTL2|=SELM1+SELS;//MCLK=SMCLK=XT2;
}

void main( void )
{
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;
  init_msp430();
  init_device();
  write_data(0xff,0xff);
  while(1)
  {
    /*lsb=(temp&0x00ff);
    msb=(temp&0xff00)>>8;
    
    temp--;
   
    
    for(time=6;time;time--);*/
  }
}
