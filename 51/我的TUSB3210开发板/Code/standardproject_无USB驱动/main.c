#include <reg52.h>


#define FC_PORT		P3
#define FC_PIN		P3
#define FC_LATCH	0x20
#define FC_CLK		0x10
#define FC_DATA		0x08
#define FC_LATCH_0	FC_PORT&=	~FC_LATCH
#define FC_LATCH_1	FC_PORT|=    FC_LATCH
#define FC_CLK_0	FC_PORT&=	~FC_CLK
#define FC_CLK_1	FC_PORT|=    FC_CLK
#define FC_DATA_IN	(FC_PIN&FC_DATA)

void FC_Init(void)
{
	FC_PORT|=FC_LATCH|FC_CLK|FC_DATA;
	FC_PORT&=~FC_LATCH;
}
unsigned char FC_Getdata(void)
{
	unsigned char i,t=0;
	FC_LATCH_1;
	FC_LATCH_1;
	FC_LATCH_1;
	FC_LATCH_1;
	FC_LATCH_0;
	for(i=0;i<8;i++)
	{
		t>>=1;
		FC_CLK_0;
		if(FC_DATA_IN)
		{
			t|=0x80;
		}
		
		FC_CLK_1;
		
	}
	return t;
}
void main(void)
{
	unsigned char i;
	FC_Init();
	while(1)
	{
		P0=FC_Getdata();
	}
}