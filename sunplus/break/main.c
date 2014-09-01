#include <spce061a.h>
#define OS_Ctx_SW() \
						__asm("break");

unsigned char stack1[20];
unsigned char stack2[20];
unsigned char flag=1;
void fun1(void)
{
	while(1)
	{
		*P_Watchdog_Clear=1;
		flag=1;
		OS_Ctx_SW();
	}
}
void fun2(void)
{
	while(1)
	{
		*P_Watchdog_Clear=1;
		flag=2;
		OS_Ctx_SW();
	}
}
int main(void)
{
	SP=stack1[19];
	fun1();	
}