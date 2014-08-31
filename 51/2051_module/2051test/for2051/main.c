#include <at89x51.h>
sbit buzzer=P3^7;
sbit led1=P3^1;
sbit led2=P3^3;
sbit led3=P3^4;
sbit led4=P3^5;
sbit key1=P1^7;
sbit key2=P1^6;
sbit key3=P1^5;
void delay(void)
{
	unsigned char i,j;
	for(i=200;i;i--)for(j=2;j;j--);
}

void main(void)
{

	while(1)
	{
		key1=1;
		key2=1;
		key3=1;
		if(key1==0)
		{
			led1=led2=led3=led4=0;
		}
		if(key2==0)
		{
			led1=led2=led3=led4=1;
		}
		if(key3==0)
		{
			buzzer=1;
			delay();
			buzzer=0;
			delay();
		}

	}
}
