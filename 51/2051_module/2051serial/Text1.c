#include <reg51.h>
/*
sbit rst=P2^0;
sbit io=P2^1;
sbit sck=P2^2;
void delay(unsigned char i)
{
	unsigned char j;
	while(i--)
	{
		for(j=200;j;j--);
	}
}
*/
void initserial(void)
{
	TMOD = 0x20;			// 定时器1工作于8位自动重载模式, 用于产生波特率
	TH1 = 0xFD;				// 波特率9600
	TL1 = 0xFD;
	SCON = 0x50;			// 设定串行口工作方式
	PCON &= 0xef;			// 波特率不倍增
	TR1 = 1;				// 启动定时器1
	IE = 0x0;				// 禁止任何中断
	EA=1;
	ES=1;
}
void serialint(void)interrupt 4 using 2
{
	if(RI)
	{
		RI=0;
		SBUF=SBUF;
	}
}

void send_str(unsigned char *str)// 传送字串
{
	unsigned char i = 0;
	ES=0;
	while(str[i] != '\0')
	{
		SBUF = str[i];
		while(!TI);				// 等特数据传送
		TI = 0;					// 清除数据传送标志
		i++;					// 下一个字符
	}
	ES=1;
}
/*
void send1302(unsigned char d)
{
	unsigned char i;
	sck=0;
	for(i=0;i<8;i++)
	{
		if(d&0x01)
		{
			io=1;
		}
		else
		{
			io=0;
		}
		sck=0;
		sck=1;
		d>>=1;
	}
}

unsigned char read1302(void)
{
	unsigned char d=0,i;
	sck=0;
	for(i=0;i<8;i++)
	{
		d>>=1;
		io=1;
		sck=0;
		sck=1;
		if(io)
		{
			d|=0x80;
		}
	}
	return d;
}
*/
void main(void)
{
	initserial();
	send_str("Hello world");
	while(1);
}