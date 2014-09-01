#include <spce061a.h>
unsigned int tb[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x40};
unsigned int dot=0x80;
unsigned int buffer[8];
void longdelay(void)
{
	int i,j;
	for(i=0;i<600;i++)
		for(j=20;j;j--)
		*P_Watchdog_Clear=1;
}
void shortdelay(void)
{
	int i;
	for(i=50;i;i--)
		*P_Watchdog_Clear=1;
}

//数码显示模块		void show（int mode，int freq，int mvol）；
//调用函数：shortdelay();
//入口参数：int mode：0代表正弦波，1代表方波，2代表三角波
//			int freq: 频率，以Hz为单位,显示在数码管上时单位为kHz;
//			int mvol: 最大幅度值；10*vmax;
//出口参数：无
void show(int mode,int freq,int mvol)
{
	unsigned int count,tmp[8],j;
	*P_IOA_Dir=0xffff;
	*P_IOA_Attrib=0xffff;
	*P_IOA_Data=0xffff;
	tmp[0]=tb[mode];
	tmp[1]=tb[10];
	if(freq<100)
	{
		return;
	}
	else if(freq<20000)
	{
		tmp[2]=tb[freq/10000];
		tmp[3]=tb[(freq%10000)/1000];
		tmp[3]|=dot;
		tmp[4]=tb[(freq/100)%10];
	}
	else
	{
		return;
	}
	tmp[5]=tb[10];
	tmp[6]=tb[mvol/10]|dot;
	tmp[7]=tb[mvol%10];
	for(j=0;j<100;j++)
	{
	for(count=0;count<8;count++)
	{
		*P_IOA_Data=((0x0100<<count)|tmp[count]);
		shortdelay();
	}
	}
}


	

int main(void)
{
	
	*P_IOA_Dir=0xffff;
	*P_IOA_Attrib=0xffff;
	*P_IOA_Data=0xffff;
	
	while(1)
	{
		show(2,10000,20);
	}
}

