#include <reg51.h>

unsigned char table[20]={0x03,0x06,0x0c,0x08,0x0f,0x0e,0x06,0x02,0x01,0x11,0x00};
unsigned char i=0;
sbit clk=P3^0;
void timer0(void)interrupt 1 using 1
{
	TH0=217;
	TL0=240;
	clk=1;
	i++;
	if(i==20)
	{
		i=0;
	}
	P2=table[i];
	clk=0;
}
	
void main(void)
{
	TH0=217;
	TL0=240;
	TMOD=0x01;
	TR0=1;
	ET0=1;
	EA=1;
	while(1)
	{
	}
}