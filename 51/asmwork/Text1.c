#include <reg51.h>
unsigned char i;
bit i0;
void main(void)
{
	#pragma asm
		mov a,#0x01;
	#pragma endasm
	while(1)
	{
		#pragma asm
			rr a;
		#pragma endasm	
		i=ACC;
		i0=i&0x01;
	}
}
