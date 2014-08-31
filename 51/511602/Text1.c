#include<at89x51.h>

void delay(unsigned char i)
{
	unsigned char x,y;
	for(;i;i--)
	for(x=100;x;x--)
	for(y=50;y;y--);
}

int main(void)
{
	
}
