#ifndef _595he164_H
#define _595he164_H
#include <at89x51.h>
#define uchar unsigned char 

sbit Din=P1^0;
sbit Sclk=P1^2;
sbit Rclk=P1^3;


uchar number[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
uchar bits[]={0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};
uchar buffer[8]={0,2,4,6,8,7,5,1};
void delay_1ms(uchar a)
{
	uchar b,c;
	while(a--)
		for(b=45;b;b--)
			for(c=34;c;c--);
}

void senddata(uchar a,uchar b)
{
	uchar t,i;
	Din=0;
	Sclk=0;
	Rclk=0;
	for(i=0;i<8;i++)
	{
		t=a&0x80;
		if(t)
		{
			Din=1;
		}
		else
		{
			Din=0;
		}
		Sclk=0;
		;
		Sclk=1;
		;
		a<<=1;
	}
	for(i=0;i<8;i++)
	{
		t=b&0x80;
		if(t)
		{
			Din=1;
		}
		else
		{
			Din=0;
		}
		Sclk=0;
		;
		Sclk=1;
		;
		b<<=1;
	}
	Rclk=0;
	;
	Rclk=1;
	;
}

void showbuffer(void)
{
	uchar i;
	for(i=0;i<8;i++)
	{
		senddata(bits[i],number[buffer[i]]);
		delay_1ms(1);
	}
}
#endif
void main(void)
{
	
	while(1)
	{
		showbuffer();
	}
}