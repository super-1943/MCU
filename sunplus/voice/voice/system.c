#include "SPCE061A.H"
#include "playsound.h"
extern unsigned int hour;//��ŵ�ǰ��Сʱ
extern unsigned int min;//��ŵ�ǰ�ķ���
extern unsigned int sec;//��ŵ�ǰ����
extern unsigned int apm;//�������־
extern unsigned int nhour;
extern unsigned int nmin;
extern int tep;
extern unsigned char shan_flag;
unsigned int num=0;//2HZ������Ԫ
unsigned char adjustflag = 0;	//���ڱ�ǰ���1������ʾ
unsigned char nflag=0;			//�����ǰ���2��ʱ

extern unsigned char is_nao;
extern void PlayClock(unsigned char h,unsigned char m);
void DelayTime(int ii)//��ʱ�ӳ���
{
	unsigned int aa,bb;
	for(aa=0;aa<ii;aa++)
		for(bb=0;bb<10;bb++)
			*P_Watchdog_Clear=0x0001;
}
void clock()//ʱ�����㺯������ڲ��������룬�룬�֣�ʱ
{
	if(num==0x0002)//������뵽��2�������1
	{
	   num=0x0000;
	   sec=sec++;
	   if((hour==11)&&(min==59)&&(sec==60))//12ʱ���л�������
	   	apm=~apm;
	}
	if(sec==60)//����뵽��60����������ּ�1
	{
		sec=0;
		min=++min;
	}
	if(min==60)//����ֵ���60���������Сʱ��1
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
	*P_IOA_Dir &= ~0x000f;      //��ʼ��IOA0-IOA3����Ϊ��������
	*P_IOA_Attrib |= 0x000f;
	*P_IOA_Data &= ~0x000f;
}

//----------------------------------------------
//ģʽѡ�񣬴����ҵİ���1--����ʱ�䣻2--�������ӣ�3--������ʱ��4--����
//----------------------------------------------

void ModeSel() 
{
	if((*P_IOA_Data&0x0001) ==0)    //������1����;
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
	if((*P_IOA_Data & 0x0002) ==0)  	//������2����
	{
		DelayTime(5000);
		
		if(adjustflag == 0)   //�����һ�β��ǰ��µ�һ����
		{
			//��ʾѧ��
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
	if((*P_IOA_Data & 0x0004) ==0)		//������3����
	{
		DelayTime(5000);
		if((adjustflag) ==0&&(nflag==0))
		{
			//����ʱ�䣻
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
	if((*P_IOA_Data & 0x0008)==0)		//������4����
	{
		DelayTime(5000);
		if((adjustflag ==0)&&(nflag==0))
		{
			//�����¶ȡ�
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
	
	if(min==60)//����ֵ���60���������Сʱ��1
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
		
		if(nmin==60)//����ֵ���60���������Сʱ��1
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