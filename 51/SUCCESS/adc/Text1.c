#include <at89x51.h>

sbit st=P3^2;
sbit oe=P3^0;
sbit eoc=P3^1;
sbit aa=P3^4;
sbit ab=P3^5;
sbit ac=P3^6;
sbit l0=P2^7;
sbit l1=P2^6;
sbit l2=P2^5;

unsigned char data adc;
unsigned char buff[3]={0,0,0};
unsigned char code tab[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
void delay()
{
	unsigned char i,j;
	for(i=10;i;i--)
	for(j=250;j;j--);
}
void disp(void)
{
	unsigned char i;
	l2=0;
	i=adc/100;
	P1=tab[i];
	delay();
	l2=1;
	l1=0;
	i=adc/10;
	i%=10;
	P1=tab[i];
	delay();
	l1=1;
	l0=0;
	i=adc%10;
	P1=tab[i];
	delay();
	l0=1;
}
	

void main()
{
	
	aa=1;
	ab=1;
	ac=0;
	while(1)
	{
		st=0;
		st=1;
		st=0;
		while(eoc==0);
		oe=1;
		adc=P0;
		oe=0;
		disp();


		
	}
}
