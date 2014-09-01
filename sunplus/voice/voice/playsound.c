#include"spce061a.h"
#include "s480.h"

void PlaySnd_Auto(unsigned int uiSndIndex,unsigned int uiDAC_Chanl)
{

	SACM_S480_Initial(1);                  // 初始化为自动播放。
	SACM_S480_Play(uiSndIndex,uiDAC_Chanl,3);
	while((SACM_S480_Status()&0x0001) != 0)
	{
		SACM_S480_ServiceLoop();
		*P_Watchdog_Clear = 0x0001;
	}
	SACM_S480_Stop();
	__asm("FIQ OFF");

}


void PlayClock(unsigned char h,unsigned char m)
{
	unsigned char hhour = h/10;
	unsigned char lhour = h%10;
	unsigned char hmin = m/10;
	unsigned char lmin = m%10;
	
	if(h<10)
		PlaySnd_Auto(h,1+2);  		//
	else if(lhour == 0)	
	{
		PlaySnd_Auto(hhour,1+2);  		//		
		PlaySnd_Auto(10,1+2);			//播放语音十;
	}
	else
	{
		PlaySnd_Auto(hhour,1+2);  		//		
		PlaySnd_Auto(10,1+2);			//播放语音十;
		PlaySnd_Auto(lhour,1+2);
	}

	PlaySnd_Auto(14,1+2);			//点

	if(m==0)
	{
		*P_Watchdog_Clear = C_WDTCLR;
	}
	else if(lmin==0)
	{
		PlaySnd_Auto(hmin,1+2);
		PlaySnd_Auto(10,1+2);
	}
	else if(hmin ==0)
	{
		PlaySnd_Auto(lmin,1+2);
	}
	else 
	{
		PlaySnd_Auto(hmin,1+2);
		PlaySnd_Auto(10,1+2);
		PlaySnd_Auto(lmin,1+2);
	}	
}

void Playtemp(unsigned char temperature)
{
	unsigned char htemp=temperature/10;
	unsigned char ltemp=temperature%10;
	PlaySnd_Auto(12,1+2);			//环境温度
	if(temperature<10)
	{
		PlaySnd_Auto(temperature,1+2);
	}
	else if(ltemp==0)
	{
		PlaySnd_Auto(htemp,1+2);
		PlaySnd_Auto(10,1+2);
	}
	else
	{
		PlaySnd_Auto(htemp,1+2);
		PlaySnd_Auto(10,1+2);
		PlaySnd_Auto(ltemp,1+2);
	}
	PlaySnd_Auto(13,1+2);			//摄氏度。
	
}

