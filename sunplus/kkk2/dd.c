#include <spce061a.h>
void delay()
{
	int i;
	for(i=100;i;i--);
	*P_Watchdog_Clear=0x0001;
}
int main()
{
	unsigned int buff;
	*P_SystemClock=C_Fosc_49M|C_Fosc_Div_16;//0x80|0x4=0x84;
	*P_IOA_Dir=0xffff;
	*P_IOA_Attrib=0xffff;
	*P_IOA_Data=0xffff;
	while(1)
	{
		*P_Watchdog_Clear=0x0001;
		buff=~*P_IOA_Data;
		*P_IOA_Data=buff;
		delay();
	}
}
		
	