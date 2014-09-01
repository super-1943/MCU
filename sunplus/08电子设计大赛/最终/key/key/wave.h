#ifndef	__WAVE_h__
#define	__WAVE_h__
//	write your header here
extern unsigned int mode,freq,vol,index,mem_freq,mem_vol;
extern unsigned int SQUR[];
extern unsigned int TRIG[];
extern unsigned int SINE[];
extern unsigned int mem_table[];
void delay_wave(int x)
{
	while(x--)
	{
		*P_Watchdog_Clear=1;
	}
}
void initwave(void)
{
	int i;
	*P_DAC_Ctrl=C_DAC1_DIRECT;
	for(i=0;i<256;i++)
	{
		SINE[i]<<=6;
		SINE[i]/=50;
		SQUR[i]/=50;
		TRIG[i]/=30;
		*P_Watchdog_Clear=1;
	}
}
void wave(void)
{
	int i;
	if(mode==0)
	{
		for(i=0;i<256;i++)
		{
			*P_DAC1=SINE[i]*vol;
			delay_wave(200-freq/100);
			*P_Watchdog_Clear=1;
		}
		return;
	}
	if(mode==1)
	{
		for(i=0;i<256;i++)
		{
			*P_DAC1=SQUR[i]*vol;
			delay_wave(200-freq/100);
			*P_Watchdog_Clear=1;
		}
		return;
	}
	if(mode==2)
	{
		for(i=0;i<256;i++)
		{
			*P_DAC1=TRIG[i]*vol;
			delay_wave(200-freq/100);
			*P_Watchdog_Clear=1;
		}
		return;
	}
	if(mode==3)
	{
		for(i=0;i<256;i++)
		{
			*P_DAC1=mem_table[i]*10;
			delay_wave(200-mem_freq/100);
			*P_Watchdog_Clear=1;
		}
		return;
	}
}
	
#endif
