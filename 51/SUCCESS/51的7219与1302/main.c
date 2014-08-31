#include <at89x51.h>
#include <intrins.h>
sbit CLK=P1^0;
sbit DIN=P1^1;
sbit LOAD=P1^2;
sbit _RST=P1^6;
sbit SCLK=P1^4;
sbit IO_DATA=P1^5;
unsigned char buff[8];


#define SecondReadCommand 0x81        //�뵥Ԫ����
#define SecondWriteCommand 0x80       //�뵥Ԫ��д
#define MinuteReadCommand 0x83		  //�ֵ�Ԫ����
#define MinuteWriteCommand 0x82		  //�ֵ�Ԫ��д
#define HourReadCommand 0x85			//ʱ��Ԫ����
#define HourWriteCommand 0x84			//ʱ��Ԫ��д
#define DateReadCommand 0x87			//�յ�Ԫ����
#define DateWriteCommand 0x86			//�յ�Ԫ��д
#define MonthReadCommand 0x89			//�µ�Ԫ����
#define MonthWriteCommand 0x88			//�µ�Ԫ��д
#define WeekReadCommand 0x8b			//�ܵ�Ԫ����
#define WeekWriteCommand 0x8a			//�ܵ�Ԫ��д
#define YearReadCommand 0x8d			//�굥Ԫ����
#define YearWriteCommand 0x8c			//�굥Ԫ��д
#define CtrlReadCommand 0x8f			//���Ƶ�Ԫ����
#define CtrlWriteCommand 0x8e			//���Ƶ�Ԫ��д
#define ChargeReadCommand 0x91			//��絥Ԫ����
#define ChargeWriteCommand 0x90			//��絥Ԫ��д
#define BatModeReadCommand 0xbf			//����ģʽ��Ԫ����
#define BatModeWriteCommand 0xbe		//����ģʽ��Ԫ��д
#define RamBatReadCommand 0xff			//RAM������
#define RamBatWriteCommand 0xfe			//RAM����д
//special data
#define HoldClock 0x80			//SecondWriteCommand 0x80 
#define GoClock 0x00			//SecondWriteCommand 0x80 
#define WriteEnable 0x00			//CtrlWriteCommand 0x8e		���Ƶ�Ԫ��д
#define WriteForbidden 0x80			//CtrlWriteCommand 0x8e		���Ƶ�Ԫ��д
#define ChargeEnable 0xa0
#define ChargeDiodes1 0x04			//1 diode
#define ChargeDiodes2 0x08			//2 diodes
#define ChargeResistors0 0x00			
#define ChargeResistors2 0x01
#define ChargeResistors4 0x02
#define ChargeResistors8 0x03
#define NoCharge 0x00




#define D0 0x01
#define D1 0x02
#define D2 0x03
#define D3 0x04
#define D4 0x05
#define D5 0x06
#define D6 0x07
#define D7 0x08

#define DecodeMode 0x09
#define Intensity 0x0a
#define ScanLimit 0x0b
#define ShutDown 0x0c
#define DisplayTest 0x0f

#define ShutDownMode 0x00
#define NormalOperation 0x01
#define DecodeDight 0xff
#define IntensityGrade 0x0a
#define ScanDight 0x07
#define TestMode 0x01
#define TestEnd 0x00
unsigned char data DisBuffer[8]={0,0,0,0,0,0,0,0};
unsigned char code display_list[]={0x7e,0x30,0x6d,0x79,0x33,0x5b,0x5f,0x70,0x7f,0x7b,
                                /* 0     1    2    3    4    5    6    7    8    9    */
								0x77,0x1f,0x4e,0x3d,0x4f,0x47,0x67,0x3e,0xff,0x00};
								/*A  B     C    D    E     F   P    U    all  none*/

void delay(unsigned char count)
{
    unsigned char j,k;
	while(count--)
	{
		for(j=43;j;j--)
		for(k=73;k;k--);
	}
}

void sendchar(unsigned char ch)
{
    unsigned char i,temp;
	_nop_();
	for(i=0;i<8;i++)
	{
		temp=ch&0x80;
		ch=ch<<1;
		if(temp)
		{
			DIN=1;
			CLK=0;
			CLK=1;
		}
		else
		{
			DIN=0;
			CLK=0;
			CLK=1;
		}
	}
}


void sendword(unsigned char addr,unsigned char num)
{
	LOAD=0;
	_nop_();
	sendchar(addr);
	_nop_();
	sendchar(num);
	_nop_();
	LOAD=1;
}

void init7219(void )
{
	sendword(ScanLimit,ScanDight);
	sendword(DecodeMode,DecodeDight);
	sendword(Intensity,IntensityGrade);
	sendword(ShutDown,NormalOperation);
}

void initmain(void)
{
	IE=0x00;
	IP=0x00;
	TH0=0xd8;TL0=0xf0;
	TMOD=0x01;
	TCON=0x11;
	PSW=0x00;
}
void init1302(void)
{
	_RST=0;
	_nop_();
	SCLK=0;
	_nop_();
	
}
//��ds1302д��
void putchar(unsigned char d)
{
	unsigned char i,t;
	for(i=0;i<8;i++)
	{
		t=d&0x01;
		d>>=1;
		if(t)
		{
			IO_DATA=1;
			SCLK=0;
			SCLK=1;
		}
		else
		{
			IO_DATA=0;
			SCLK=0;
			SCLK=1;
		}
	}
}
void getchar(unsigned char *d)
{
	unsigned char i,t=0;
	bit s;
	*d=0;
	for(i=0;i<8;i++)
	{
		t>>=1;
		SCLK=1;
		SCLK=0;
		_nop_();
		s=IO_DATA;
		if(s)
		{
			t|=0x80;
		}
		else
		{
			t&=0x7f;
		}
	}
	*d=t;
}

void write1302(unsigned char com,unsigned char d)
{
	init1302();
	_RST=1;
	_nop_();
	putchar(com);
	_nop_();
	putchar(d);
	_nop_();
	_RST=0;

}
unsigned char read1302(unsigned char com)
{
	unsigned char s;	
	init1302();

	_RST=1;
	_nop_();
	putchar(com);
	_nop_();
	getchar(&s);
	_nop_();
	_RST=0;
	return s;
}
void show(void)
{
	unsigned char i,j;
	for(i=0;i<8;i++)
	{
		sendword(i+1,buff[i]);
	}
}
void main(void)
{
	initmain();
	init7219();
	init1302();
	sendword(DisplayTest,TestMode);
	delay(0x64);
	delay(0x64);
	sendword(DisplayTest,TestEnd);
	write1302(SecondWriteCommand,0x00);
	write1302(MinuteWriteCommand,0x23);
	show();
	while(1)
	{
		
	buff[0]=read1302(SecondReadCommand)%16;
	buff[1]=read1302(SecondReadCommand)/16;
	buff[2]=0x0f;
	buff[3]=read1302(MinuteReadCommand)%16;
	buff[4]=read1302(MinuteReadCommand)/16;
	buff[5]=0x0f;
	buff[7]=1;
	buff[6]=1;
	show();
	delay(0x55);

	}



 }




