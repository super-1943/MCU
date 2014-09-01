#include <spce061a.h>
unsigned int table[]={0,12,25,37,48,59,68,77,84,90,95,98,100,100,98,95,90,84,77,68,59,48,37,25,12,0};
//some pins
#define SCLK5_1 (*P_IOA_Data|=0x0001) //IOA0
#define SCLK5_0 (*P_IOA_Data&=~0x0001)
#define DIN5_1 (*P_IOA_Data|=0x0002)//IOA1
#define DIN5_0 (*P_IOA_Data&=~0x0002)
#define CS5_1 (*P_IOA_Data|=0x0004)//IOA2
#define CS5_0 (*P_IOA_Data&=~0x0004)
#define CL5_0 (*P_IOA_Data&=~0x0008)//IOA3
#define CL5_1 (*P_IOA_Data|=0x0008)

//some commands
#define LA 0x3000					//all DAC registers updated
#define LB 0x7000
#define LC 0xb000
#define LD 0xf000
#define Update 0x4000				//from its respective input registers
#define Update2 0x8000				//+10bit data(derectly from its shift register!)!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#define Shutdown5 0xc000				//PDL=1
#define UPO_0 0x2000
#define UPO_1 0x6000
#define Noop5 0x0000
#define Mode1 0xe000				//DOUT CLOCKED out on SCLK's rising edge,all DAC registers updated
#define Mode0 0xa000				//DOUT CLOCKED out on SCLK's falling edge,all DAC registers updated


void send525(int data)
{
	int temp,i;
	CS5_0;
	SCLK5_0;
	data&=0x0ffc;
	data|=Update2;
	*P_Watchdog_Clear=1;
	for(i=0;i<16;i++)
	{
		temp=data&0x8000;
		data<<=1;
		if(temp)
		{
			DIN5_1;
			SCLK5_0;
			SCLK5_1;
		}
		else
		{
			DIN5_0;
			SCLK5_0;
			SCLK5_1;
		}
	}
	CS5_1;
}


void init525(void)
{
	*P_IOA_Dir|=0x000f;
	*P_IOA_Attrib|=0x000f;
	*P_IOA_Data&=0xfff0;
	CL5_0;
	CL5_1;
	send525(Update2|0x00ff);
}

void delay(void)
{
	int i,j;
	for(i=0;i<10;i++)
		for(j=0;j<10;j++)
			*P_Watchdog_Clear=1;
}
int main(void)
{
	int i;
	init525();
	while(1)
	{
		for(i=0;i<25;i++)
		{
		send525(10*table[i]);
		
		*P_Watchdog_Clear=1;
		}
	
	}
}
	