#include "msp430x14x.h"

int main( void )
{
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;
    P1DIR|=0x01;
    P1IE|=0xf0;
    P1IES|=0xf0;
    P1IFG&=~0xf0;
    _EINT();
    while(1)
    {

    }
}
#pragma vector=PORT1_VECTOR
__interrupt void Port1(void)
{
    P1OUT^=0x01;
    P1IFG&=~0xf0;
}