#include "msp430x14x.h"
void init_sys(void)
{
  unsigned char i;
  P2DIR=0xff;
  P2OUT=0x00;
  BCSCTL1&=~XT2OFF;
  do
  {
    IFG1&=~OFIFG;
    for(i=0xff;i;i--);
  }while((IFG1&OFIFG)!=0);
  BCSCTL2|=SELM1;//MCLK=XT2;
}
void init_timera(void)
{
  TACTL=SSEL1+TACLR;
  CCTL0=CCIE;
  CCR0=50000;
  TACTL|=MC1;
  _EINT();
}
  

int main( void )
{
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;
  init_sys();
  init_timera();
  while(1)
  {
    
  }
}

#pragma vector=TIMERA0_VECTOR
__interrupt void timera(void)
{
  P2OUT^=0xff;
  CCR0+=50000;
}