#include <at89x51.h>
unsigned char t[]={0x01,0x03,0x02,0x06,0x04,0x0c,0x08,0x09};
void delay(void)
{
	unsigned char i,j;
	for(i=255;i;i--)
		for(j=20;j;j--);
}

void main(void)
{
	unsigned char i=0;
	while(1)
	{
		P2=t[i++];
		delay();
		delay();
		i%=8;
	}
}
