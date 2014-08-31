/*******************************************************
说明：数码管显示
一，二数码管显示AD输出（必须按下S4触发int0中断之后）
3位显示是否有AD输出    1 yes   0 no
4位空闲
5,6位显示555的触发频率（好像最小为6，最大为19）
7，8位时间
*******************************************************/
#include <absacc.h>
#include <reg52.h>
#include <stdarg.h>
#include <stdio.h>
#include "ds1302.h"
sbit key1=P1^0;
sbit key2=P1^1;
sbit buz=P1^3;
unsigned char tcount=0,time=0;
#define PORTA XBYTE[0x8fff]
#define PORTB XBYTE[0x9fff]
#define PORTC XBYTE[0xafff]
#define CADDR XBYTE[0xbfff]
#define ADREAD XBYTE[0x00ff]
unsigned char code table[]={
0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71,0x00
};
unsigned char buffer[8]={0,0,0,0,0,16,16,16};
void delay(unsigned char j)
{
	unsigned char i,k;
	for(i=123;i;i--)
	for(k=5;k;k--)
	for(;j;j--);
}
void shortdelay(void)
{
	unsigned char i;
	for(i=100;i;i--);
}
void buzzer(unsigned char i)
{
	buz=0;
	delay(i);
	buz=1;
	shortdelay();
}
void show(unsigned char *buf)
{
	unsigned char i;
	CADDR=0x80;
	PORTC=0x00;
	PORTB=0x01;
	PORTA=0x00;
	for(i=0;i<8;i++)
	{
		PORTA=table[buf[i]];
		delay(2);
		PORTB<<=1;
	}
}
void myint0(void)interrupt 0 using 1
{
	unsigned char i;
	IT1=1;
	EX1=1;
	ADREAD=0;
	for(i=0;i<8;i++)
	{
		buffer[i]=16;
	}
	buzzer(1);
}

void int1(void)interrupt 2 using 2
{
	EX1=0;
	buffer[2]=1;
	buffer[0]=ADREAD/16;
	buffer[1]=ADREAD%16;
}

void myt1(void)interrupt 3 using 2
{
	if(tcount==0)
	{
		TR0=1;
	}
	TH1=(65536-50000)/256;
	TL1=(65536-50000)%256;
	tcount++;
	if(tcount==20)
	{
		TR0=0;
		buffer[5]=TL0%10;
		buffer[4]=TL0/10;
		time++;
		buffer[6]=time/10;
		buffer[7]=time%10;
		if(time>99)
		time=0;
		TL0=0;
		tcount=0;
	}
}

void main(void)
{
	init1302();
	write1302(SecondWriteCommand,0x00);
	write1302(MinuteWriteCommand,0x23);
	P1=0x0f;
	EX0=1;
	ET1=1;
	TMOD=0x16;
	TH1=(65536-50000)/256;
	TL1=(65536-50000)%256;
	TR1=1;
	while(1)
	{
/*		buffer[0]=read1302(SecondReadCommand)%16;
		buffer[1]=read1302(SecondReadCommand)/16;
		buffer[2]=16;
		buffer[3]=read1302(MinuteReadCommand)%16;
		buffer[4]=read1302(MinuteReadCommand)/16;
		buffer[5]=16;
		buffer[7]=1;
		buffer[6]=1;*/
		show(buffer);
	}
	
}