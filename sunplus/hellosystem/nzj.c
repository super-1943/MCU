#include <SPCE061A.H>
#define SW() \
			__asm("break");
unsigned char stack1[20];
unsigned char stack2[20];
unsigned char *pstack;
unsigned char flag=1;
void taskcreate(void (*fun)(void))
{
	*pstack--=(unsigned char)fun;
	*pstack--=0x0000;
	*pstack--=0x0000;
	__asm("sp=_pstack");
}

void fun1(void)
{
	while(1)
	{
		*P_Watchdog_Clear=1;
		flag=1;
		SW();
	}
}
void fun2(void)
{
	while(1)
	{
		*P_Watchdog_Clear=1;
		flag=2;
		SW();
	}
}
int main(void)
{
	pstack=stack1+19;
	taskcreate(fun1);
}