#include "led.h"
void delay(unsigned int t)
{
	while(t--);		
}
void show(unsigned int * buffer,unsigned int size)
{
	const unsigned char segtable[]={0x3f00,0x0600,0x5b00,0x4f00,0x6600,0x6d00,0x7d00,0x0700,0x7f00,0x6f00,0x4000};
	int i;
	for(i=0;i<size;i++)
	{
		delay(150);
		*P_IOB_Data&=0x00ff;
		*P_IOA_Data&=0x00ff;
		*P_IOA_Data|=segtable[buffer[i]];
		*P_IOB_Data|=(0x0100<<i);
	}	
}