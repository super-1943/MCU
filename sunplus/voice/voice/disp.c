#include "SPCE061A.h"
unsigned int apm;//�������־
unsigned int dian=1;//�����ж���ʾ��˸��0.5S��һ��
unsigned char shan_flag = 0;
extern unsigned int num;
void disp_delay(int);
void disp_Init(void)//��ʾ��ʼ��
{
	*P_IOA_Dir|=0xffc0;//��ʼ��IOA8-IOA15Ϊ�����
	*P_IOA_Attrib|=0xffc0;
	*P_IOA_Data|=0x0000;
	*P_IOB_Dir|=0xff00;
	*P_IOB_Attrib|=0xff00;
	*P_IOB_Data|=0x0000;
}
void disp(int t,int h,int m,int s)//��ʾ����  ,��adjustflagΪ1��ʱ���ʾ���ڵ���ʱ�䡣��ʾҪ��˸��
{
	int d[12]={0x3f00,0x0600,0x5b00,0x4f00,0x6600,0x6d00,0x7d00,0x0700,0x7f00,0x6f00,0x0040,0x0080};
	int dig[8]={0x0100,0x0200,0x0400,0x0800,0x1000,0x2000,0x4000,0x8000};
	int i=0,mm=0;
	float dis[8];
	
	dis[7]=t%10;//�¶ȸ�λ
	dis[6]=t/10;//�¶�ʮλ
	dis[5]=s%10;//���λ
	dis[4]=s/10;//��ʮλ
	dis[3]=m%10;//�ָ�λ
	dis[2]=m/10;//��ʮλ
	dis[1]=h%10;//Сʱ��λ
	dis[0]=h/10;//Сʱʮλ
	
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