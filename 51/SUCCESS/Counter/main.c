#include <at89x51.h>
unsigned char code table[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
unsigned char count;
sbit a=P3^7;
sbit b=P3^6;


void delay(unsigned char i)
{
	unsigned char x;
	for(;i;i--)
	for(x=200;x;x--)
	;
}
void int0(void) interrupt 0 using 1
{
	unsigned char i;
	count++;
	for(i=10;i;i--)delay(73);
}

void main()
{

	EA=1;
	EX0=1;
	IT0=1;

	while(1)
	{
		P2=table[count/10];
		b=0;
		a=1;
		delay(150);		//不加delay（）将会出现重影，不信试试
		P2=table[count%10];
		a=0;
		b=1;
		delay(150);		//不加delay（）将会出现重影，不信试试

	}
}
