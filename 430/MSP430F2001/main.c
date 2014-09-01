
#include "io430.h"
void delay(void)
{
  unsigned int i;
  for(i=100;i;i--);
}
int main( void )
{
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;
  P1DIR=0xff;
  P1OUT=0x00;
  P2SEL=0x00;//默认好像不是IO口，最好设置一下
  P2DIR|=0xc0;
  P2OUT|=0xc0;
  while(1)
  {
    P1OUT^=0xff;
    P2OUT^=0xc0;
    delay();
  }

}
