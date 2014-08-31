#ifndef _kkk_1302_h
#define _kkk_1302_h
#include <intrins.h>
sbit _RST_1302=P1^4;
sbit SCLK_1302=P1^6;
sbit IO_DATA_1302=P1^5;


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
	_RST_1302=0;
	_nop_();
	SCLK_1302=0;
	_nop_();
	
}
//向ds1302写入
void putchar_1302(unsigned char d)
{
	unsigned char i,t;
	for(i=0;i<8;i++)
	{
		t=d&0x01;
		d>>=1;
		if(t)
		{
			IO_DATA_1302=1;
			SCLK_1302=0;
			SCLK_1302=1;
		}
		else
		{
			IO_DATA_1302=0;
			SCLK_1302=0;
			SCLK_1302=1;
		}
	}
}
void getchar_1302(unsigned char *d)
{
	unsigned char i,t=0;
	bit s;
	*d=0;
	for(i=0;i<8;i++)
	{
		t>>=1;
		SCLK_1302=1;
		SCLK_1302=0;
		_nop_();
		s=IO_DATA_1302;
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
	_RST_1302=1;
	_nop_();
	putchar_1302(com);
	_nop_();
	putchar_1302(d);
	_nop_();
	_RST_1302=0;

}
unsigned char read1302(unsigned char com)
{
	unsigned char s;	
	init1302();

	_RST_1302=1;
	_nop_();
	putchar_1302(com);
	_nop_();
	getchar_1302(&s);
	_nop_();
	_RST_1302=0;
	return s;
}
#endif