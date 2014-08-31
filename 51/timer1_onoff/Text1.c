#include <reg51.h>

void main(void)
{
	TR0=1;
	TR1=1;
	TMOD=0x23;
	while(1);
}