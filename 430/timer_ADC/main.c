
#include "msp430x16x.h"

int main( void )
{
	// Stop watchdog timer to prevent time out reset
	WDTCTL = WDTPW + WDTHOLD;
	while(1)
	{
		P1OUT=0xff;
	}
	
	return 0;
}
