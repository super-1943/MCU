#include <spce061a.h>
unsigned int i=0;
void IRQ1(void)__attribute__((ISR));
void IRQ1(void)
{
	i+=10;
	*P_DAC1=i<<6;
	if(i==800)
		i=0;
	*P_INT_Clear=1;
}
void delay(int i)
{
	
	while(i--)
	{
		*P_Watchdog_Clear=1;
	}
}
int main(void)
{
	*P_SystemClock=C_Fosc_49M;
	*P_INT_Ctrl=C_IRQ1_TMA;
	*P_TimerA_Ctrl=C_TMA1_FOSC_2|C_TMA2_1;
	*P_TimerA_Data=0xffff;
	*P_DAC_Ctrl=C_DAC1_DIRECT;
	*P_IOA_Dir=0xffff;
	*P_IOA_Attrib=0xffff;
	*P_IOA_Data=0xffff;
//	__asm("INT IRQ");
	while(1)
	{
		*P_DAC1=0xffff;
//		delay(1);
		*P_DAC1=0x0000;
//		delay(1);
		*P_Watchdog_Clear=1;
	}
}