#ifndef	__MY7219_h__
#define	__MY7219_h__
//-,clk,din,load,+
//	write your header here
#define DIN_0 (*P_IOB_Data &=~0x8000)			//IOB15
#define DIN_1 (*P_IOB_Data |=0x8000)
#define CLK_0 (*P_IOB_Data &=~0x2000)			//IOB14
#define CLK_1 (*P_IOB_Data |=0x2000)
#define LOAD_0 (*P_IOB_Data &=~0x4000)			//IOB13
#define LOAD_1 (*P_IOB_Data |=0x4000)
//some registers:
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
void sendword(unsigned int word)
{
	int i,temp;
	LOAD_0;
	for(i=0;i<16;i++)
	{
		*P_Watchdog_Clear=1;
		temp=0x8000&word;
		word<<=1;
		if(temp)
		{
			DIN_1;
			CLK_0;
			CLK_1;
		}
		else
		{
			DIN_0;
			CLK_0;
			CLK_1;
		}
	}
	LOAD_1;
	*P_Watchdog_Clear=1;
}
void init7219(void )
{
	*P_IOB_Dir|=0xf000;
	*P_IOB_Attrib|=0xf000;
	*P_IOB_Data&=0x0fff;
	sendword(ScanLimit|ScanDight);
	sendword(DecodeMode|DecodeDight);
	sendword(Intensity|IntensityGrade);
	sendword(ShutDown|NormalOperation);
	sendword(DisplayTest|TestMode);
	sendword(DisplayTest|TestEnd);
}

//������ʾģ��		void show��int mode��int freq��int mvol����
//���ú�����shortdelay();
//��ڲ�����int mode��0�������Ҳ���1��������2�������ǲ�
//			int freq: Ƶ�ʣ���HzΪ��λ,��ʾ���������ʱ��λΪkHz;
//			int mvol: ������ֵ��10*vmax;
//���ڲ�������
void show(int mode,int freq,int mvol)
{
	int tmp[8];
	
	*P_IOB_Dir|=0xf000;
	*P_IOB_Attrib|=0xf000;
	*P_IOB_Data&=0x0fff;
	sendword(ScanLimit|ScanDight);
	sendword(DecodeMode|DecodeDight);
	sendword(Intensity|IntensityGrade);
	sendword(ShutDown|NormalOperation);
	
	tmp[0]=mode;
	tmp[2]=freq/10000;
	tmp[3]=(freq%10000)/1000;
	tmp[3]|=Dot;
	tmp[4]=(freq/100)%10;
	tmp[6]=(mvol/10)|Dot;
	tmp[7]=mvol%10;
	*P_Watchdog_Clear=1;	
	sendword(D7|tmp[0]);
	sendword(D6|Noshow);
	sendword(D5|tmp[2]);
	sendword(D4|tmp[3]);
	sendword(D3|tmp[4]);
	sendword(D2|Noshow);
	sendword(D1|tmp[6]);
	sendword(D0|tmp[7]);
}


#endif
