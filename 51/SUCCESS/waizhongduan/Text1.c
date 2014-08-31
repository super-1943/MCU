#include <at89x51.h>
void delay()
{
	unsigned char i,j;
	for(i=0;i<200;i++)for(j=0;j<50;j++);
}
void int0(void) interrupt 0 using 1
{
	P1=(P1+1)%10;
	delay();
	

	
}
void main(void)
{
	EA=1;
	EX0=1;
	IT0=1;
	P1=0x00;
	while(1);
}
