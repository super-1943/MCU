#include <spce061a.h>
void IRQ3()__attribute__((ISR));
void IRQ3()
{
	unsigned int i=0x0000;
	
	*P_INT_Clear=0x0100;
	i=*P_IOB_Data;
	i&=0x00f0;
	if(i==0x00f0)
	{
		i=0xff0f;
		*P_IOB_Data&=i;
	}
	else
	{
		*P_IOB_Data|=0x00f0;
	}
}
int main()
{
	asm("INT OFF");
	*P_Feedback=0x0000;
	*P_IOB_Dir=0xf0;
	*P_IOB_Attrib=0xf0;
	*P_IOB_Data=0x0f;			//IOB:低四位上拉输入，
	*P_INT_Ctrl=0x0100;
	*P_INT_Ctrl_New=0x0100;
	asm("INT IRQ");
	while(1)
	{
		*P_Watchdog_Clear=1;
	}
}