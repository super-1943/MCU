#include <reg52.h>
sbit seg0=P0^0;
sbit seg1=P0^1;
sbit seg2=P0^2;
sbit seg3=P0^3;
sbit seg4=P0^4;
sbit seg5=P0^6;
sbit seg6=P0^6;
sbit seg7=P0^7;
sbit seg8=P3^7;

sbit sel0=P3^0;
sbit sel1=P3^1;
sbit sel2=P3^2;
sbit sel3=P3^3;


unsigned char i;
void delay_ms(unsigned int k)
{
	unsigned char i,j;
	for(;k;k--)
	for(i=200;i;i--)
	for(j=200;j;j--);
}
void main(void)
{
	P0=0xff;
	P3=0xff;
	seg0^=1;

	while(1)
	{
		P0^=0xff;
		P3^=0xff;
		delay_ms(1);

	}
}