#include <spce061a.h>
unsigned int Flag=0;
void IRQ5(void) __attribute__((ISR));
void IRQ5(void)
{
	*P_INT_Clear=0x0008;
	if(Flag==0)
	{
		Flag=1;
		*P_IOB_Data=0x0000;
	}
	else
	{
		Flag=0;
		*P_IOB_Data=0xffff;
	}
}

int main()
{
	*P_IOA_Dir=0xffff;
	*P_IOA_Attrib=0xffff;
	*P_IOA_Data=0xffff;
	*P_IOB_Dir=0xffff;
	*P_IOB_Attrib=0xffff;
	*P_IOB_Data=0xffff;
	*P_INT_Ctrl=0x0008;
	*P_INT_Ctrl_New=0x0008;
	
	asm("INT IRQ");
	
	
	while(1)
	{
		*P_Watchdog_Clear=1;
	}
}