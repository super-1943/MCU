#include <reg51.h>
/*
sbit SCL=P1^6;
sbit SDA=P1^7;
#define ADREAD 0xd1
#define ADWRITE 0xd0
void delay(void)
{
	;
}

void iic_start(void)
{
	SCL=1;
	delay();
	SDA=0;
	delay();
	SCL=0;
	delay();
}

void iic_stop(void)
{
	SDA=0;
	delay();
	SCL=1;
	delay();
	SDA=1;
	delay();
	SCL=0;
	delay();
}

void init(void)
{
	SCL=0;
	iic_stop();
}

bit iic_clock(void)
{
	bit sample;
	SCL=1;
	delay();
	sample=SDA;
	SCL=0;
	delay();
	return (sample);
}

bit iic_send(unsigned char d)
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
		SDA=(bit)(d&0x80);
		d<<=1;
		iic_clock();
	}
	SDA=1;
	return(~iic_clock());
}

unsigned char iic_receive(void)
{
	unsigned char d=0;
	register unsigned char i;
	for(i=0;i<8;i++)
	{
		d*=2;
		if(iic_clock())
		d++;
	}
	return d;
}

void iic_ack(void)
{
	SDA=0;
	iic_clock();
	SDA=1;
}*/
#include <reg51.h>
#include <intrins.h>

#define ACK 0x00
#define NACK 0x01
#define ADREAD 0xd1
#define ADWRITE 0xd0
sbit SCL=P1^6;
sbit SDA=P1^7;
unsigned char tab[10];
void start_iic(void);
void stop_iic(void);
unsigned char send1byte(unsigned char b);
void readnbyte(unsigned char *d,unsigned char n);
void delay(unsigned char i);
void main(void)
{
	unsigned char i=0x01;
	delay(10);
	start_iic();
	if(send1byte(0xd1)==ACK)
	{
		readnbyte(tab,9);
	}
	stop_iic();
	start_iic();
//	if(send1byte(0xd0)==ACK)
	{
//		for(i=0;i<55 && !send1byte(i);i++);
	}
//	stop_iic();
//	start_iic();
	if(send1byte(0xd0)==ACK)
	{
//		send1byte(0x00);
		send1byte(0x07);
		send1byte(0x10);
	}
	stop_iic();
//	start_iic();
//	if(send1byte(0xd1)==ACK)
//	{
//		readnbyte(tab,9);
//	}
///	stop_iic();
	while(1)
	{


	}
}
void start_iic(void)
{
	SCL=0;
	SCL=1;
	SDA=1;
	_nop_();
	SDA=0;
}
void stop_iic(void)
{
	SCL=0;
	SCL=1;
	SDA=0;
	_nop_();
	SDA=1;
}
unsigned char send1byte(unsigned char b)
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
		SCL=0;
		if(b&0x80)
		{
			SDA=1;
		}
		else
		{
			SDA=0;
		}
		SCL=1;
		_nop_();
		b<<=1;
	}
	SCL=0;
	_nop_();
	SDA=1;
	_nop_();
	SCL=1;
	if(SDA==1)
	{
		return NACK;
	}
	else
		return ACK;
}
void readnbyte(unsigned char * d,unsigned char n)
{
	unsigned char i,t;
	while(n--)
	{
		t=0x00;
		for(i=0;i<8;i++)
		{
			t<<=1;
			SCL=0;
			_nop_();
			SCL=1;
			_nop_();
			if(SDA)
			{
				t|=0x01;
			}
		}
		*d++=t;
		if(n==0)
		{
			SCL=0;
			SDA=1;
			SCL=1;
			SCL=0;
			SDA=1;
		}
		else
		{
			SCL=0;
			SDA=0;
			SCL=1;
			SCL=0;
			SDA=1;
		}
	}


}

void delay(unsigned char i)
{
	unsigned char j,k;
	while(i--)
	{
		for(j=200;j;j--)
		for(k=155;k;k--);
	}
}
