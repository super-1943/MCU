/*******************************************************
说明：数码管显示
一，二数码管显示AD输出（必须按下S4触发int0中断之后）
3位显示是否有AD输出
4，5位空闲
6位显示555的触发频率（0-F）
7，8位空闲
*******************************************************/
#include <absacc.h>
#include <reg52.h>
#include <stdarg.h>
#include <stdio.h>
sbit key1=P1^0;
sbit key2=P1^1;
sbit buz=P1^3;
unsigned char tcount=0;
#define PORTA XBYTE[0x8fff]
#define PORTB XBYTE[0x9fff]
#define PORTC XBYTE[0xafff]
#define CADDR XBYTE[0xbfff]
#define ADREAD XBYTE[0x00ff]
unsigned char table[]={
0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71,0x00
};
unsigned char buffer[8]={5,6,7,8,9,10,0,0};
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
	for(i=200;i;i--);
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
	PORTC=0xff;
	PORTB=0x01;
	PORTA=0x00;
	for(i=0;i<8;i++)
	{
		PORTA=table[buf[i]];
		delay(7);
		PORTB<<=1;
//		PORTB+=1;
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
		buffer[i]=0;
	}
	buzzer(1);
}
/*
void int1(void)interrupt 2 using 2
{
//	EX1=0;
	buffer[2]=1;
	buffer[0]=ADREAD/16;
	buffer[1]=ADREAD%16;
}
*/
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
		buffer[5]=TL0;
		TL0=0;
		tcount=0;
	}
}

void main(void)
{
	unsigned char i;
//	EX0=1;
//	ET1=1;
//	TMOD=0x16;
//	TH1=(65536-50000)/256;
//	TL1=(65536-50000)%256;
//	TR1=1;
	P1=0x00;
	
	while(1)
	{
		PORTC=0x0f;
		i=PORTC;
		show(buffer);
	}
	
}