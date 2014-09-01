#include "SPCE061A.H"
#include "playsound.h"
extern unsigned int hour;//存放当前的小时
extern unsigned int min;//存放当前的分钟
extern unsigned int sec;//存放当前的秒
extern unsigned int apm;//上下午标志
extern unsigned int nhour;
extern unsigned int nmin;
extern int tep;
extern unsigned char shan_flag;
unsigned int num=0;//2HZ记数单元
unsigned char adjustflag = 0;	//用于标记按键1，来表示
unsigned char nflag=0;			//用与标记按下2键时

extern unsigned char is_nao;
extern void PlayClock(unsigned char h,unsigned char m);
void DelayTime(int ii)//延时子程序
{
	unsigned int aa,bb;
	for(aa=0;aa<ii;aa++)
		for(bb=0;bb<10;bb++)
			*P_Watchdog_Clear=0x0001;
}
void clock()//时钟运算函数，入口参数，半秒，秒，分，时
{
	if(num==0x0002)//如果半秒到了2，则秒加1
	{
	   num=0x0000;
	   sec=sec++;
	   if((hour==11)&&(min==59)&&(sec==60))//12时后切换上下午
	   	apm=~apm;
	}
	if(sec==60)//如果秒到了60，则秒清零分加1
	{
		sec=0;
		min=++min;
	}
	if(min==60)//如果分到了60，则分清零小时加1
	{
		min=0;
		hour=++hour;
	}
	if(hour>12)
	{
		hour=1;
		apm=~apm;
	}
	
}


void AdjustInit()
{
	*P_IOA_Dir &= ~0x000f;      //初始化IOA0-IOA3按键为悬浮输入
	*P_IOA_Attrib |= 0x000f;
	*P_IOA_Data &= ~0x000f;
}

//----------------------------------------------
//模式选择，从左到右的按键1--调节时间；2--设置闹钟；3--语音报时；4--返回
//----------------------------------------------

void ModeSel() 
{
	if((*P_IOA_Data&0x0001) ==0)    //当按键1按下;
	{
		DelayTime(5000);
		if(nflag==0)
		{
			while((*P_IOA_Data&0x0001) ==0)
				*P_Watchdog_Clear = C_WDTCLR;
			shan_flag = (shan_flag+1)%3;
			adjustflag=(adjustflag+1)%3;
		}		
	}
	if((*P_IOA_Data & 0x0002) ==0)  	//当按键2按下
	{
		DelayTime(5000);
		
		if(adjustflag == 0)   //如果第一次不是按下第一个键
		{
			//显示学号
			DelayTime(5000);
			while((*P_IOA_Data & 0x0002) ==0)
				*P_Watchdog_Clear = C_WDTCLR;
			
	//		while((*P_IOA_Data & 0x0002) !=0)
			{
			//	disp_ID();
			    shan_flag = (shan_flag+1)%3;
			    nflag=(nflag+1)%3;
			    if(nflag==0)
			    {
			    	is_nao=1;
			    }
				*P_Watchdog_Clear = C_WDTCLR;
			}
			DelayTime(5000);
			while((*P_IOA_Data & 0x0002) ==0)
				*P_Watchdog_Clear = C_WDTCLR;
			
		}
			
	}
	if((*P_IOA_Data & 0x0004) ==0)		//当按键3按下
	{
		DelayTime(5000);
		if((adjustflag) ==0&&(nflag==0))
		{
			//播报时间；
			PlayClock(hour,min);
		}
		if(adjustflag ==1)
			hour++;
		if(adjustflag ==2)
			min++;
		
		if(nflag==1)
			nhour+=1;
		if(nflag==2)
			nmin+=1;
	}
	if((*P_IOA_Data & 0x0008)==0)		//当按键4按下
	{
		DelayTime(5000);
		if((adjustflag ==0)&&(nflag==0))
		{
			//播报温度。
			Playtemp(tep);
		}
		if(adjustflag ==1)
			hour-=1;
		if(adjustflag ==2)
			min-=1;
		if(nflag==1)
		{
			nhour-=1;
		}
		if(nflag==2)
		{
			nmin-=1;
		}
	}
	
	if(min==60)//如果分到了60，则分清零小时加1
		{
			min=0;
			hour=++hour;
		}
		if(min==-1)
		{
			min=59;
		}
		if(hour>12)
		{
			hour=1;
			apm=~apm;
		}
		if(hour<1)
		{
			hour=12;
			apm=~apm;
		}
		
		if(nmin==60)//如果分到了60，则分清零小时加1
		{
			nmin=0;
			nhour=++nhour;
		}
		if(nmin==-1)
		{
			nmin=59;
		}
		if(nhour>12)
		{
			nhour=1;
			apm=~apm;
		}
		if(nhour<1)
		{
			nhour=12;
			apm=~apm;
		}
		while((*P_IOA_Data&0x000f)!=0x000f)
			*P_Watchdog_Clear = C_WDTCLR;
}

void nclock()
{
	if((nmin==min)&&(nhour==hour)&&(is_nao==1))
	{
		while((*P_IOA_Data&0x000f)==0x000f)
		{
			PlayClock(hour,min);
			*P_Watchdog_Clear = C_WDTCLR;
			DelayTime(5000);
		}
		is_nao=0;
	}
}