#ifndef __KEY__
#define __KEY__
/*****************************************************
键盘输入模块：  int temp;
调用函数： KeyValue()
入口参数： 无

           键1代表int mode加1；
		   键2代表int freq加100Hz；
		   键3代表int freq减100Hz；
		   键4代表int vol加0.1V；
		   键5代表int vol减0.1V；
		   键6代表保存叠加当前数据；
		   键7代表清空已保存数据；
		   键8代表执行.
*****************************************************/	

extern unsigned int mode,freq,vol;
extern unsigned int SQUR[];
extern unsigned int TRIG[];
extern unsigned int SINE[];
extern unsigned int mem_table[];
extern void show(int mode,int freq,int vol);
void delay(int x)
{
	
	while(x--)
	{
		
			*P_Watchdog_Clear=1;
	}
}
void storemem(void)
{
	int i;
	if(mode==0)
	{
		for(i=0;i<256;i++)
		{
			*P_Watchdog_Clear=1;
			mem_table[i]+=SINE[i];
		}
	}
	if(mode==1)
	{
		for(i=0;i<256;i++)
		{
			*P_Watchdog_Clear=1;
			mem_table[i]+=SQUR[i];
		}
	}
	if(mode==2)
	{
		for(i=0;i<256;i++)
		{
			*P_Watchdog_Clear=1;
			mem_table[i]+=TRIG[i];
		}
	}
	if(mode==3)
	{
		for(i=0;i<256;i++)
		{
			*P_Watchdog_Clear=1;
			mem_table[i]*=2;
		}
	}
}
void clearmem(void)
{
	int i;
	for(i=0;i<256;i++)
		{
			*P_Watchdog_Clear=1;
			mem_table[i]=0;
		}
}
void initkey(void)
{
	*P_IOB_Dir &= 0xff00;
	*P_IOB_Attrib&=0xff00;	 
	*P_IOB_Data|=0x00ff;
}
void KeyScan()
{
	
	int temp,value;
	value=*P_IOB_Data&0x00ff;
	if(value==0x00ff)
		return;
	temp=~(*P_IOB_Data|0xff00);
	switch(temp)
	{
			case 0x0080:
				
					break;
			case 0x0040:
					freq+=100;
					if(freq>=20000)
					{
						freq=100;
					}
					delay(0xff);
					break;
			case 0x0020:
					freq-=100;
					if(freq==0)
					{
						freq=20000;
					}
					delay(0xff);
					break;
			case 0x0010:
					if(vol==50)
					{
						vol=0;
						break;
					}
					delay(0xff);
					vol++;
					break;
			case 0x0008:
					if(vol==0)
					{
						vol=50;
						break;
					}
					vol--;
					delay(0xff);
					break;
			case 0x0004:
					storemem();
					delay(0xff);
					break;
			case 0x0002:
					clearmem();
					delay(0xff);
					break;
			case 0x0001:
					mode++;
					if(mode==4)
					{
						mode=0;
					}
					delay(0xfff);
					break;
			default:
					break;
	}
		show(mode,freq,vol);
}
	
#endif