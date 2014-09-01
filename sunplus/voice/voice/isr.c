#include <SPCE061A.H>
#include "disp.h"

__asm(".external F_FIQ_Service_SACM_S480");

extern unsigned int num;
extern unsigned int dian;
extern unsigned int hour;//存放当前的小时
extern unsigned int min;//存放当前的分钟
extern unsigned int sec;//存放当前的秒

extern unsigned char temperatureflag;


void FIQ(void) __attribute__ ((ISR));
void FIQ(void)
{
	if(*P_INT_Ctrl&0x2000) //定时器A中断
	{
		*P_INT_Clear=C_FIQ_TMA;
		__asm("call F_FIQ_Service_SACM_S480"); //调用A2000中断服务函数
	}
	else if(*P_INT_Ctrl&0x0800) //定时器B中断
		*P_INT_Clear=C_FIQ_TMB;
	else 						//PWM中断
		*P_INT_Clear=C_FIQ_PWM;
}


void IRQ5(void) __attribute__ ((ISR));
void IRQ5(void)
{
if(*P_INT_Ctrl&0x0004)
{ //IRQ5_2Hz
	num++;
	if(num>2)    //调节时间的时候中断时开着的，调节完时间回到main中后num加超过了2，所以clock检测不到了。所以在此处判断如果怒骂>2，就置0
		num = 0;
	dian=~dian;
	temperatureflag++;
	if(temperatureflag >=3)
		temperatureflag =0;
	*P_INT_Clear = 0x0004;
}
else
{ //IRQ5_4Hz
	*P_INT_Clear = 0x0008;
}
}