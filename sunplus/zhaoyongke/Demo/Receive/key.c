#include <spce061a.h>
extern unsigned int RxBuf[25];	
void getkey(void)
{
	if(!((*P_IOA_Data)&0x0001))
	{
		RxBuf[4]=1;
	}
	else if(!((*P_IOA_Data)&0x0002))
	{
		RxBuf[4]=2;
	}
	else if(!((*P_IOA_Data)&0x0004))
	{
		RxBuf[4]=3;
	}
	else if(!((*P_IOA_Data)&0x0008))
	{
		RxBuf[4]=4;
	}
	else
	{
		RxBuf[4]=0;
	}
}