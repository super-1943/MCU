#include <spce061a.h>
#include "a2000.h"
void playsound(int index,int channel)
{
	SACM_A2000_Initial(1);//auto
	SACM_A2000_Play(index,channel,3);
	while((SACM_A2000_Status()&0x0001)!=0)
	{
		SACM_A2000_ServiceLoop();
		*P_Watchdog_Clear=1;
	}
	SACM_A2000_Stop();
}
int main(void)
{
	*P_IOA_Dir=0x0000;
	*P_IOA_Attrib=0x0000;
	*P_IOA_Data=0x0000;
	while(1)
	{
		if((*P_IOA_Data)&0x0001)
		{
			playsound(0,3);
		}
		else if((*P_IOA_Data)&0x0002)
		{
//			playsound(1,3);
		}
		else if((*P_IOA_Data)&0x0004)
		{
//			playsound(2,3);
		}
		else
			*P_Watchdog_Clear=1;
	}
}