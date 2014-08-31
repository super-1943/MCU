#include <at89x51.h>
void delay(void)
{
	unsigned char i,j;
	for(i=255;i;i--)
	for(j=20;j;j--);
}
void main(void)
{
	while(1)
	{
		P1=~P1;
		P3=~P3;
		delay();
	}
}
