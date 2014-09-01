#include <SPCE061A.H>
#include "disp.h"

__asm(".external F_FIQ_Service_SACM_S480");

extern unsigned int num;
extern unsigned int dian;
extern unsigned int hour;//��ŵ�ǰ��Сʱ
extern unsigned int min;//��ŵ�ǰ�ķ���
extern unsigned int sec;//��ŵ�ǰ����

extern unsigned char temperatureflag;


void FIQ(void) __attribute__ ((ISR));
void FIQ(void)
{
	if(*P_INT_Ctrl&0x2000) //��ʱ��A�ж�
	{
		*P_INT_Clear=C_FIQ_TMA;
		__asm("call F_FIQ_Service_SACM_S480"); //����A2000�жϷ�����
	}
	else if(*P_INT_Ctrl&0x0800) //��ʱ��B�ж�
		*P_INT_Clear=C_FIQ_TMB;
	else 						//PWM�ж�
		*P_INT_Clear=C_FIQ_PWM;
}


void IRQ5(void) __attribute__ ((ISR));
void IRQ5(void)
{
if(*P_INT_Ctrl&0x0004)
{ //IRQ5_2Hz
	num++;
	if(num>2)    //����ʱ���ʱ���ж�ʱ���ŵģ�������ʱ��ص�main�к�num�ӳ�����2������clock��ⲻ���ˡ������ڴ˴��ж����ŭ��>2������0
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