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
��������ģ�飺  int KeyTemp,Value;
���ú����� KeyValue()
��ڲ����� ��

           ��1����int mode��1��
		   ��2����int freq��100Hz��
		   ��3����int freq��100Hz��
		   ��4����int mvol��0.1V��
		   ��5����int mvol��0.1V��
		   ��6��������ӵ�ǰ���ݣ�
		   ��7��������ѱ������ݣ�
		   ��8����ִ�С�		   
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