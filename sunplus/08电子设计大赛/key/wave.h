#ifndef	__WAVE_h__
#define	__WAVE_h__
//	write your header here
extern unsigned int mode,freq,vol;
extern unsigned int SINE[];
void wave_init(void)
{
	*P_DAC_Ctrl=C_DAC1_DIRECT;
}
void wave(void)
{
	int i;
	if(mode==0)
	{
		for(i=0;i<256;i++)
		{
			*P_DAC1=(SINE[i]<<1)*vol;
			*P_Watchdog_Clear=1;
		}
	}
	if(mode==1)
	{
		for(i=0;i<100;i++)
		{
			*P_DAC1=(20*vol)<<6;
			*P_Watchdog_Clear=1;
		}
		for(i=100;i<200;i++)
		{
			*P_DAC1=0;
			*P_Watchdog_Clear=1;
		}
	}
	if(mode==2)
	{
		for(i=0;i<100;i++)
		{
			*P_DAC1=(i*vol/5)<<6;
			*P_Watchdog_Clear=1;
		}
		for(i=100;i>0;i--)
		{
			*P_DAC1=(i*vol/5)<<6;
			*P_Watchdog_Clear=1;
		}
	}
}
	
#endif
