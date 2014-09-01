#include <spce061a.h>

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
	while(1)
	{

	}
}