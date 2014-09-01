#ifndef __KEY__
#define __KEY__
/*****************************************************
��������ģ�飺  int temp;
���ú����� KeyValue()
��ڲ����� ��

           ��1����int mode��1��
		   ��2����int freq��100Hz��
		   ��3����int freq��100Hz��
		   ��4����int vol��0.1V��
		   ��5����int vol��0.1V��
		   ��6��������ӵ�ǰ���ݣ�
		   ��7��������ѱ������ݣ�
		   ��8����ִ��.
*****************************************************/	

extern unsigned int mode,freq,vol,mem_freq,mem_vol;
extern unsigned int SQUR[];
extern unsigned int TRIG[];
extern unsigned int SINE[];
extern unsigned int mem_table[];
extern void show(int mode,int freq,int vol);
void delay(int x)
{
	int i;
	
	while(x--)
	{
		for(i=0;i<2;i++)
			*P_Watchdog_Clear=1;
	}
}
void storemem(void)
{
	int i;
	mem_freq=freq;
	mem_vol=vol;
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
	mem_freq=0;
	mem_vol=0;
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
					while(1);				//wait for watchdog and reset
					break;
			case 0x0040:
					freq+=100;
					if(freq>=20000)
					{
						freq=100;
					}
					delay(0xfff);
					break;
			case 0x0020:
					freq-=100;
					if(freq==0)
					{
						freq=20000;
					}
					delay(0xfff);
					break;
			case 0x0010:
					if(vol==50)
					{
						vol=0;
						break;
					}
					delay(0xfff);
					vol++;
					break;
			case 0x0008:
					if(vol==0)
					{
						vol=50;
						break;
					}
					vol--;
					delay(0xfff);
					break;
			case 0x0004:
					storemem();
					delay(0xfff);
					break;
			case 0x0002:
					clearmem();
					delay(0xfff);
					break;
			case 0x0001:
					mode++;
					if(mode==4)
					{
						mode=0;
					}
					delay(0xffff);
					break;
			default:
					break;
	}
		show(mode,freq,vol);
}
	
#endif