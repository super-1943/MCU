#include <at89x51.h>
void sendadr(unsigned char adr);
unsigned char tb[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
void delay(void)
{
	unsigned char i,j;
	for(i=73;i;i--)
	for(j=83;j;j--)
	;
}

void main(void)
{
	unsigned char i=0;
	while(1)
	{
		P0=0x36;
		sendadr(0x55);
		delay();
	}
}
	
void sendadr(unsigned char adr)
{
	__asm
	{
		mov r0,adr;
		movx a,@r0;
	}
}
		
		
	