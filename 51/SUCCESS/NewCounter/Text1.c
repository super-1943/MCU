#include <at89x51.h>
unsigned char code table[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
static unsigned char count;
sbit a=P3^7;
sbit b=P3^6;
unsigned char i;
unsigned char x,y;
void delay();
void int0(void) interrupt 0 using 1
{
	count++;
	for(i=10;i;i--)delay();
}
void delay()
{
	unsigned char x,y,z;
	for(x=5;x;x--)
	for(y=73;y;y--)
	for(z=43;z;z--);
}
void main()
{

	EA=1;
	EX0=1;
	IT0=0;

	while(1)
	{
		x=count/10;
		P2=table[x];
		b=0;
		a=1;
		delay();
		x=count%10;
		P2=table[x];
		a=0;b=1;
		delay();

	}
}
