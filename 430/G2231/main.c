
#include "io430.h"
void delay(unsigned int t)
{
	while(t--);
}
int main( void )
{
	// Stop watchdog timer to prevent time out reset
	WDTCTL = WDTPW + WDTHOLD;
	P1DIR=0x01;
	P1OUT=0x01;
	while(1)
	{
		P1OUT^=0x01;
		delay(5000);
	}
	return 0;
}
