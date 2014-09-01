#include "io430.h"
void delay(unsigned int t)
{
	while(t--);
}
int main( void )
{
	// Stop watchdog timer to prevent time out reset
	WDTCTL = WDTPW + WDTHOLD;
	P1DIR|=0x41;
	
	while(1)
	{
		if(!(P1IN&0x08))//如果S2按下
		{
			P1OUT|=0x40;
			P1OUT&=~0x01;
			delay(15000);
			P1OUT|=0x01;
			P1OUT&=~0x40;
			delay(15000);
		}
	}
	return 0;
}
