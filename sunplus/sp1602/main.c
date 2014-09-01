#include <spce061a.h>

#define rs_1 (*P_IOA_Data|=0x80)
#define rs_0 (*P_IOA_Data&=~0x80)
#define rw_1 (*P_IOA_Data|=0x40)
#define rw_0 (*P_IOA_Data&=~0x40)

#define enable (*P_IOA_Data|=0x20)
#define disable (*P_IOA_Data&=~0x20)
#define run (*P_IOA_Data|=0x20,asm("NOP"),*P_IOA_Data&=~0x20;)

void delay(unsigned int i)
{
	unsigned int x,y;
	for(;i;i--)
	for(x=200;x;x--)
		for(y=100;y;y--)
			*P_Watchdog_Clear=1;
}

void send1602(unsigned char c)
{
	
}
int main(void)
{
}
		