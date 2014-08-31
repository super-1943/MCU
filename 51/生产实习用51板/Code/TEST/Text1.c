#include <reg52.h>
sbit LED1=P3^4;
sbit LED2=P3^5;
sbit BUZZER=P2^4;

void delay(unsigned int t)
{
	unsigned char i,j;
	while(t--)
	{
		for(i=200;i;i--)
			for(j=20;j;j--);
	}
}
void main(void)
{
	LED1=0;
	LED2=1;
	BUZZER=0;
	while(1)
	{
		LED1=~LED1;
		LED2=~LED2;
		BUZZER=~BUZZER;
		delay(100);
	}

}