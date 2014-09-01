#include <spce061a.h>
int main()
{
	*P_IOA_Data=0xffff;
	*P_IOA_Attrib=0x0000;
	*P_IOA_Dir=0xffff;
	while(1)
		*P_Watchdog_Clear=0x0001;
}