#include "SPCE061A.h"
unsigned int apm;//上下午标志
unsigned int dian=1;//用来判断显示闪烁，0.5S闪一次
unsigned char shan_flag = 0;
extern unsigned int num;
void disp_delay(int);
void disp_Init(void)//显示初始化
{
	*P_IOA_Dir|=0xffc0;//初始化IOA8-IOA15为输出口
	*P_IOA_Attrib|=0xffc0;
	*P_IOA_Data|=0x0000;
	*P_IOB_Dir|=0xff00;
	*P_IOB_Attrib|=0xff00;
	*P_IOB_Data|=0x0000;
}
void disp(int t,int h,int m,int s)//显示函数  ,当adjustflag为1的时候表示正在调整时间。显示要闪烁。
{
	int d[12]={0x3f00,0x0600,0x5b00,0x4f00,0x6600,0x6d00,0x7d00,0x0700,0x7f00,0x6f00,0x0040,0x0080};
	int dig[8]={0x0100,0x0200,0x0400,0x0800,0x1000,0x2000,0x4000,0x8000};
	int i=0,mm=0;
	float dis[8];
	
	dis[7]=t%10;//温度个位
	dis[6]=t/10;//温度十位
	dis[5]=s%10;//秒个位
	dis[4]=s/10;//秒十位
	dis[3]=m%10;//分个位
	dis[2]=m/10;//分十位
	dis[1]=h%10;//小时个位
	dis[0]=h/10;//小时十位
	
	if(shan_flag == 1)
	{
		if(num == 1)
		{
			for(i=0;i<2;i++)
			{
				*P_IOB_Data=dig[i];
				mm=dis[i];
				*P_IOA_Data=d[mm];
				disp_delay(2);
			}
		}
		for(i=2;i<4;i++)
		{
			*P_IOB_Data=dig[i];
			mm=dis[i];
			*P_IOA_Data=d[mm];
			disp_delay(2);
		}
	}
	else if(shan_flag == 2)
	{		
	
		for(i=0;i<2;i++)
		{
			*P_IOB_Data=dig[i];
			mm=dis[i];
			*P_IOA_Data=d[mm];
			disp_delay(2);
		}
		if(num ==1)
		{
			for(i=2;i<4;i++)
			{
				*P_IOB_Data=dig[i];
				mm=dis[i];
				*P_IOA_Data=d[mm];
				disp_delay(2);
			}
		}
	}
	else
		for(i=0;i<4;i++)
		{
			*P_IOB_Data=dig[i];
			mm=dis[i];
			*P_IOA_Data=d[mm];
			disp_delay(2);
		}
	for(i=4;i<8;i++)
	{
	    *P_IOB_Data=dig[i];	
	    mm=dis[i];
		*P_IOA_Data=d[mm];
		disp_delay(2);
	}
	if(apm==0)
	    *P_IOA_Data=d[10];
	else
		*P_IOA_Data=d[11];
       disp_delay(2);
    if(dian==1) 
    {
    	*P_IOB_Data=0x0800;
    	*P_IOA_Data=0x8000;
    	disp_delay(2);
    	*P_IOB_Data=0x0200;
    	*P_IOA_Data=0x8000;
    	disp_delay(2);
    } 
    *P_IOB_Data=0;
   	*P_IOA_Data=0;  
}
void disp_delay(int j)
{
	int DelayValuel=0, DelayValue2=0;
	for( DelayValuel=0; DelayValuel<j; DelayValuel++)
	{
		for( DelayValue2=0; DelayValue2<0x0f0; DelayValue2++)
			*P_Watchdog_Clear=1;
	}
}

void disp_ID(void)
{
	disp(1,04,02,01);
}