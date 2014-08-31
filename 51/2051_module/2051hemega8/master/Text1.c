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

	start_iic();
	if(send1byte(0xd0)==ACK)
	{
		send1byte(0x31);
		send1byte(0x32);
	}
	stop_iic();

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
