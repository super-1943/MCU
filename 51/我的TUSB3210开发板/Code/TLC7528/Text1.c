#include <reg51.h>

volatile unsigned char count=0;

void delay_ms(unsigned int k)
{
	unsigned char i,j;
	for(;k;k--)
	for(i=20;i;i--)
	for(j=100;j;j--);
}

void timer_int0(void) interrupt 1 using 2
{
	if(count)
	{
		P0^=0xff;
		count=0;
	}
	else
	{
		count++;
	}
}

void main(void)
{
	
	P0=0x55;
	delay_ms(1000);
	TMOD=0x02;
	TH0=38;
	TL0=38;
	TR0=1;
	ET0=1;
	EX1=0;
	EX0=0;
	EA=1;
	while(1)
	{

	}
}