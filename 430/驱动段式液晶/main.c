
#include "msp430x16x.h"
#include "fstn.h"
void delay(void)
{
	unsigned int i;
	i=1000;
	while(i--);
}
int main( void )
{
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;
//  init_fstn();
//  w_data(0x55);
  P1DIR=0xff;
  P2DIR=0xff;
  P1OUT=0x00;
  P2OUT=0xdf;
  while(1)
  {
	  P1OUT^=0xff;
	  P2OUT^=0xff;
	  delay();
  }
}
