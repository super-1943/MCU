/*******************************************************
说明：数码管显示
一，二数码管显示AD输出（必须按下S4触发int0中断之后）

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
unsigned char buffer[8]={0,0,0,0,0,0,0,0};
void delay(unsigned char j)
{
	unsigned char i,k;
	for(i=123;i;i--)
	for(k=5;k;k--)
	for(;j;j--);
}
void show(unsigned char *buf)
{
	unsigned char i;
	CADDR=0x80;
	PORTC=0xff;
	PORTB=0xfe;
	PORTA=0x00;
	for(i=0;i<8;i++)
	{
		PORTA=table[buf[i]];
		delay(7);
		PORTB<<=1;
		PORTB+=1;
	}
}
void int0(void)interrupt 0 using 1
{

}

void int1(void)interrupt 2 using 2
{
}
void t1(void)interrupt 3 using 2
{
	TH1=0xff;
	TL1=0xff;
	buffer[7]=0;
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
void main(void)
{
	unsigned char i;
	EX0=1;
	ET1=1;
	TMOD=0x56;
	TH1=0xff;
	TL1=0xff;
	TR1=1;
//	EA=1;

	for(i=0;i<8;i++)
	{
		buffer[i]=1;
	}
	while(1)
	{
		show(buffer);
	}
	
}