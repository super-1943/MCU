#include<reg51.h>
#include"intrins.h"
//**************************宏定义***********************************
#define uchar unsigned char 
#define uint unsigned int

#define L 0
#define H 1
#define NOP _nop_()

uchar date[9];
uchar time[9];
uchar temp,temph,templ;
uchar Tempx[9];


//bit d;
sbit rs=P2^2; //4
sbit rw=P2^1; //5
sbit e =P2^0; //6

sbit DQ=P2^3;

void delay(unsigned int t);

//*************************1602驱动程序**********************************
//功能：1602液晶显示
//日期: 2008.9.
//************************************************************************

//***************检测忙信号***********************
unsigned char busy()
{
	rs=0;
	rw=1;	_nop_();
	e=1;	_nop_();	
	e=0;
	return P0;		
}

//**************写命令*************************
void write_cmd(unsigned char cmd)
{
	e=0;	NOP;
	rs=L;	NOP;
	rw=L;	NOP;	
	P1=cmd;	NOP;	
	e=1;	NOP;	
	e=0;	NOP;
	busy();
}

//*************写数据**************************
void write_dat(unsigned char dat)
{
	e=0;	NOP;
	rs=H;	NOP;
	rw=L;	NOP;	
	P1=dat;	NOP;	
	e=1;	NOP;
	e=0;	NOP;
	busy();
}



//*****************写字符串**********************
void show(unsigned char * str)
{
	while(*str!='\0')
	{
		write_dat(*str);
		str++;
	}
}


void goxy(unsigned char y,unsigned char x)
{
	if(y==1)
		write_cmd(0x80|x);
	if(y==2)
		write_cmd(x-(0x40));

}

void init_1602()
{
	e=0;
	delay(15);
	write_cmd(0x38);
	delay(5);
	write_cmd(0x38);
	delay(5);
	write_cmd(0x38);	
	write_cmd(0x38);NOP;
	write_cmd(0x08);NOP;				//    open up display 
	write_cmd(0x06);NOP;				//    set up guangbiao
	write_cmd(0x0c);NOP;				//     display clear
	write_cmd(0x01);NOP;
}

//***********************1302驱动程序******************************
//功能：时间程序
//日期: 2008.9.
//****************************************************************	
void delay(unsigned int t)             //t毫秒
{
	unsigned char i;
	while(t--)
	{
    	for(i=0;i<125;i++);
	}
}








//**************************主函数********************************
void main()
{

	init_1602();

	//initDisplay();

	delay(500);

	goxy(1,0);
	write_cmd(0x01);
	show("zhaoyongke");
	goxy(2,0);
	show(" www.ysu.edu.cn ");
	delay(4000);
	while(1);
}