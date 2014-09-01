#include <spce061a.h>
int main()
{
	while(1)
	{
		*P_IOA_Dir=0x0001;
		*P_IOA_Attrib=0x00001;
		*P_IOA_Data=0x0003;
		if((*P_IOA_Data & 0x0002)==0)
		{
			*P_SystemClock=C_Sleep;
		}
			
	}
}