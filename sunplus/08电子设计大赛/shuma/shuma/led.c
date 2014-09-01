#include <spce061a.h>
unsigned int tb[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x40};
unsigned int dot=0x80;
unsigned int buffer[8];//buffer[0]是模式，buffer【1】是频率，buffer【2】是最大电压；buffer[3]为全局变量
void longdelay(void)
{
	int i,j;
	for(i=0;i<600;i++)
		for(j=0;j;j--)
		*P_Watchdog_Clear=1;
}
void shortdelay(void)
{
	int i;
	for(i=20;i;i--)
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
//	*P_IOA_Dir=0xffff;
//	*P_IOA_Attrib=0xffff;
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
	for(j=0;j<1;j++)
	{
	for(count=0;count<8;count++)
	{
		*P_IOA_Data=((0x0100<<count)|tmp[count]);
		shortdelay();
		
		*P_IOA_Data=0x0000;	
	}
	}
}

/*****************************************************
键盘输入模块：  int KeyTemp,Value;
调用函数： KeyValue()
入口参数： 无

           键1代表int mode加1；
		   键2代表int freq加100Hz；
		   键3代表int freq减100Hz；
		   键4代表int mvol加0.1V；
		   键5代表int mvol减0.1V；
		   键6，7 暂无定义；
		   键8代表执行。		   
*****************************************************/			 
void KeyScan()
{
	 int KeyTemp,Value;
	*P_Watchdog_Clear = 0x0001;
	*P_IOB_Dir = 0xff00;
	*P_IOB_Attrib = 0xff00;
	KeyTemp=*P_IOB_Data;

	Value=KeyTemp^0x00ff;	

	switch(Value)
	{
			case 0x0080:
					buffer[0]++;
					if(buffer[0]==3)
						buffer[0]=0;
					break;
			case 0x0040:
					buffer[1]+=100;
					break;
			case 0x0020:
					buffer[1]-=100;
					break;
			case 0x0010:
					if(buffer[2]==50)
					{
						buffer[2]=0;
						break;
					}
					buffer[2]++;
					break;
			case 0x0008:
					if(buffer[2]==0)
					{
						buffer[2]=50;
						break;
					}
					buffer[2]--;
					break;
			default:
					break;
	}
}
	

int main(void)
{
	
	*P_IOA_Dir=0xffff;
	*P_IOA_Attrib=0xffff;
	*P_IOA_Data=0xffff;
	buffer[0]=0;
	buffer[1]=100;
	buffer[2]=20;
	while(1)
	{
		KeyScan();
		show(buffer[0],buffer[1],buffer[2]);
		*P_Watchdog_Clear=1;
	}
}

