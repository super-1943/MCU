#include "SPCE061A.H"
#include "system.h"
#include "disp.h"
#include "ADConv.h"
unsigned int hour=11;//存放当前的小时
 int min=59;//存放当前的分钟
unsigned int sec=55;//存放当前的秒
unsigned int nhour=12;
 int nmin=0;

unsigned char is_nao=0;
extern unsigned int nflag;
int tep = 0;

unsigned char temperatureflag = 0;


extern void PlaySnd_Auto(unsigned int uiSndIndex,unsigned int uiDAC_Chanl);

void isrInit()
{
	asm("IRQ OFF");
	*P_INT_Ctrl |= C_IRQ5_2Hz;   //Setup interrupt IRQ5_2Hz
	 
	asm("INT IRQ");
}

void MeatureTemp()
{
	if(temperatureflag==2)
	{
		float temperature = 0.0;
		int shownum=0;
		temperatureflag = 0;
		temperature=ADtoVoltage();
		temperature=temperature*100;
		shownum= (140-temperature)/2;	
		tep =shownum;	
	}
}
void main()
{
	*P_SystemClock=0x98;//设置系统时钟为49MHZ
	DelayTime(100);		//延时等待系统稳定。

	isrInit();			//初始化中断。
	disp_Init();        //显示初始化。显示函数在定时器A中断里执行。
	ADInit();
	while((*P_IOA_Data&0x000f)==0x000f)
	{
		disp_ID();
		*P_Watchdog_Clear = C_WDTCLR;
	}
	DelayTime(100);
	while((*P_IOA_Data&0x000f)!=0x000f)
		*P_Watchdog_Clear = C_WDTCLR;
	while(1)
	{
		ModeSel();
		clock();
		MeatureTemp();
		if(nflag==0)
			disp(tep,hour,min,sec);
		else 
		{
			disp(tep,nhour,nmin,sec);
		}
		nclock();
		*P_Watchdog_Clear = C_WDTCLR;
	}
	
	
}



