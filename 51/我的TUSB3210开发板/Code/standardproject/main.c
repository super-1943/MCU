#include <reg52.h>
void delay_ms(unsigned int k)
{
	unsigned char i,j;
	for(;k;k--)
	for(i=200;i;i--)
	for(j=200;j;j--);
}

void main(void)
{
	unsigned char i;
	delay_ms(100);
	while(1)
	{
		for(i=0;i<8;i++)
		{
			P0=~(1<<i);
			delay_ms(50);
		}
	}
}