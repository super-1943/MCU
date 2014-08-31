#include <at89x51.h>
#include <intrins.h>
sbit DIN=P1^0;
sbit LOAD=P1^1;
sbit CLK=P1^2;
sbit _RST= P2^0;
sbit SCLK= P2^1;
sbit IO_DATA= P2^2;
typedef unsigned int uint;
sbit Flag=P3^2;

//1302 Command define
#define SecondReadCommand 0x81        //秒单元，读
#define SecondWriteCommand 0x80       //秒单元，写
#define MinuteReadCommand 0x83		  //分单元，读
#define MinuteWriteCommand 0x82		  //分单元，写
#define HourReadCommand 0x85			//时单元，读
#define HourWriteCommand 0x84			//时单元，写
#define DateReadCommand 0x87			//日单元，读
#define DateWriteCommand 0x86			//日单元，写
#define MonthReadCommand 0x89			//月单元，读
#define MonthWriteCommand 0x88			//月单元，写
#define WeekReadCommand 0x8b			//周单元，读
#define WeekWriteCommand 0x8a			//周单元，写
#define YearReadCommand 0x8d			//年单元，读
#define YearWriteCommand 0x8c			//年单元，写
#define CtrlReadCommand 0x8f			//控制单元，读
#define CtrlWriteCommand 0x8e			//控制单元，写
#define ChargeReadCommand 0x91			//充电单元，读
#define ChargeWriteCommand 0x90			//充电单元，写
#define BatModeReadCommand 0xbf			//批量模式单元，读
#define BatModeWriteCommand 0xbe		//批量模式单元，写
#define RamBatReadCommand 0xff			//RAM批量读
#define RamBatWriteCommand 0xfe			//RAM批量写
//special data
#define HoldClock 0x80			//SecondWriteCommand 0x80 
#define GoClock 0x00			//SecondWriteCommand 0x80 
#define WriteEnable 0x00			//CtrlWriteCommand 0x8e		控制单元，写
#define WriteForbidden 0x80			//CtrlWriteCommand 0x8e		控制单元，写
#define ChargeEnable 0xa0
#define ChargeDiodes1 0x04			//1 diode
#define ChargeDiodes2 0x08			//2 diodes
#define ChargeResistors0 0x00			
#define ChargeResistors2 0x01
#define ChargeResistors4 0x02
#define ChargeResistors8 0x03
#define NoCharge 0x00



void init1302(void)
{
	_RST=0;
	_nop_();
	SCLK=0;
	_nop_();
	
}
//向ds1302写入
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
		

//7219 registers
#define Dight0 0x01
#define Dight1 0x02
#define Dight2 0x03
#define Dight3 0x04
#define Dight4 0x05
#define Dight5 0x06
#define Dight6 0x07
#define Dight7 0x08
#define DecodeMode 0x09
#define Intensity 0x0a
#define ScanLimit 0x0b
#define ShutDown 0x0c
#define DisplayTest 0x0f

//7219 special data
#define ShutDownMode 0x00
#define NormalOperation 0x01
#define DecodeDight 0xdb
#define IntensityGrade 0x0a
#define ScanDight 0x07
#define TestMode 0x01
#define TestEnd 0x00
unsigned char data DisBuffer[8]={0,0,0,0,0,0,0,0};
unsigned char code display_list[]={0x7e,0x30,0x6d,0x79,0x33,0x5b,0x5f,0x70,0x7f,0x7b,
                                /* 0     1    2    3    4    5    6    7    8    9    */
								0x77,0x1f,0x4e,0x3d,0x4f,0x47,0x67,0x3e,0xff,0x00};
								/*A    B    C    D    E     F   P    U    all  none*/

void delay(unsigned char count)//delay 10ms
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

void message(void) interrupt 0 using 1
{
	Flag=~Flag;
	delay(100);delay(100);
}
void initmain(void)
{
	IE=0x00;
	IP=0x00;
	TH0=0xd8;TL0=0xf0;
	TMOD=0x01;
	TCON=0x11;
	PSW=0x00;
	EA=1;
	EX0=1;
	IT0=0;
}
  	
void main()
{
	unsigned char dat,temp;
	initmain();
	init7219();
	init1302();
	sendword(DisplayTest,TestMode);
	delay(0x64);
	delay(0x64);
	sendword(DisplayTest,TestEnd);
	while(1)
	{
		if(Flag==0){
		delay(0x64);
		delay(0x64);
		dat=read1302(YearReadCommand);
		temp=dat&0x0f;
		sendword(Dight1,temp);
		temp=dat&0xf0;
		temp>>=4;
		sendword(Dight0,temp);
		dat=read1302(MonthReadCommand);
		temp=dat&0x0f;
		sendword(Dight4,temp);
		temp=dat&0xf0;
		temp>>=4;
		sendword(Dight3,temp);
		dat=read1302(DateReadCommand);
		temp=dat&0x0f;
		sendword(Dight7,temp);
		temp=dat&0xf0;
		temp>>=4;
		sendword(Dight6,temp);
		sendword(Dight5,0x00);
		sendword(Dight2,0x00);}

		else{
		delay(0x64);
		delay(0x64);
		dat=read1302(HourReadCommand);
		temp=dat&0x0f;
		sendword(Dight1,temp);
		temp=dat&0xf0;
		temp>>=4;
		sendword(Dight0,temp);
		dat=read1302(MinuteReadCommand);
		temp=dat&0x0f;
		sendword(Dight4,temp);
		temp=dat&0xf0;
		temp>>=4;
		sendword(Dight3,temp);
		dat=read1302(SecondReadCommand);
		temp=dat&0x0f;
		sendword(Dight7,temp);
		temp=dat&0xf0;
		temp>>=4;
		sendword(Dight6,temp);
		sendword(Dight5,0x00);
		sendword(Dight2,0x00);}

	 }
}
    

