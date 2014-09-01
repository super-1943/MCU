#ifndef	__KEYSCAN_h__
#define	__KEYSCAN_h__
//	write your header here
#include "spce061a.h"
#define uchar unsigned char
#define uint  unsigned int
static	uint result;						
void delay(uint i)	
{
	while(i--)
	{
		uint j=0;
		for(j=0;j<125;j++)
		{
			*P_Watchdog_Clear=1;
		}
	}
}
void delay1(void)	
{
	uint j=0;
	for(j=0;j<125;j++)
	{
		*P_Watchdog_Clear=1;
	}
}

int Get_KeyValue(void)
{
	int temp1,temp2 ;   
	temp1 = *P_IOA_Data;
	temp1 = temp1&0x0f;   					// 去抖
	if (temp1 == 0x0f)
		return 0;
	delay(10);
	*P_Watchdog_Clear=1;//清看门狗
	temp2=*P_IOA_Data;
	temp2=temp2 & 0x0f;
	if(temp2 == temp1)
	{
		result=~temp2;
		result=result&0x0f;
		return result;
	}
	else
	{
		return 0;
	}
}

#endif

