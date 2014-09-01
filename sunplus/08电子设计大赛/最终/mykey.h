#ifndef __KEY__
#define __KEY__
#define D0 0x0100
#define D1 0x0200
#define D2 0x0300
#define D3 0x0400
#define D4 0x0500
#define D5 0x0600
#define D6 0x0700
#define D7 0x0800
#define DecodeMode 0x0900
#define Intensity 0x0a00
#define ScanLimit 0x0b00
#define ShutDown 0x0c00
#define DisplayTest 0x0f00
//some data
#define ShutDownMode 0x00
#define NormalOperation 0x01
#define DecodeDight 0xff
#define IntensityGrade 0x0a
#define ScanDight 0x07
#define TestMode 0x01
#define TestEnd 0x00
#define Dot 0x80
#define Noshow 0x0f
/*****************************************************
键盘输入模块：  int KeyTemp,Value;
调用函数： KeyValue()
入口参数： 无

           键1代表int mode加1；
		   键2代表int freq加100Hz；
		   键3代表int freq减100Hz；
		   键4代表int mvol加0.1V；
		   键5代表int mvol减0.1V；
		   键6代表保存叠加当前数据；
		   键7代表清空已保存数据；
		   键8代表执行。		   
*****************************************************/	
extern unsigned int mode,freq,vol;	
extern void show(int mode,int freq,int vol);
extern void sendword(unsigned int word);
void key_init(void)
{
	*P_IOB_Dir &= 0xff00;
	*P_IOB_Attrib&=0xff00;	 
	*P_IOB_Data|=0x00ff;
}
void KeyScan()
{
	int temp;
	if((*P_IOB_Data&0x00ff)==0x00ff)
	{
		return ;
	}
	temp=*P_IOB_Data|0xff00;
	temp=~temp;
	switch(temp)
	{
			case 0x0080:
					mode++;
					if(mode==3)
					{
						mode=0;
					}					
					break;
			case 0x0040:
					freq+=100;
					if(freq>=9000)
					{
						freq=100;
					}
					break;
			case 0x0020:
					freq-=100;
					if(freq<200)
					{
						freq=9000;
					}
					break;
			case 0x0010:
					if(vol==50)
					{
						vol=0;
						break;
					}
					vol++;
					break;
			case 0x0008:
					if(vol==0)
					{
						vol=50;
						break;
					}
					vol--;
					break;
			case 0x0004:
					sendword(D2|0x000a);
					sendword(D6|0x000a);
					break;
			case 0x0002:
					sendword(D2|0x000f);
					sendword(D6|0x000f);
					break;
			case 0x0001:
					sendword(DisplayTest|TestMode);
					return ;
			default:
					break;
	}
		sendword(DisplayTest|TestEnd);
		show(mode,freq,vol);
}
	
#endif