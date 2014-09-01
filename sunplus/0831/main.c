#include <spce061a.h>
int main()
{
	int Led_Flag=0;
	*P_IOA_Dir=0x0080;
	*P_IOA_Attrib=0x0080;
	*P_IOA_Data=0x0000;
	*P_TimerA_Ctrl=0x0032;
	*P_TimerA_Data=0;
	while(1)
	{
		if(*P_TimerA_Data>=9830)
		{
			*P_TimerA_Data=0;
			if(Led_Flag==0)
			{
				*P_IOA_Data=0x0080;
				Led_Flag=1;
			}
			else
			{
				*P_IOA_Data=0x0000;
				Led_Flag=0;
			}
		}
		*P_Watchdog_Clear=0x0001;
	}
}