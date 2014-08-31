#include "reg52modified.h"
/*****************************************************************
计算波特率注意，Fclk=48MHz
定时器1采用方式二
串行口采用方式一,波特率倍增位SMOD置1
波特率初值计算公式：Baud=Fclk/(12*16*（256-x）)，x为定时器1初值
*****************************************************************/
void rs232_init(void)
{
	TMOD&=0x0f;
	TMOD|=0x20;			// 定时器1工作于8位自动重载模式, 用于产生波特率
	TH1 = 243;			// 波特率19200
	TL1 = 243;
	PCON|=0x80;			// 波特率倍增
	SCON = 0x50;		// 设定串行口工作方式1,REN=1
	TR1 = 1;			// 启动定时器1
	EA=1;
}
unsigned char rs232_getchar(void)
{
	unsigned char b;
	while(!RI);
	RI=0;
	b=SBUF;
	return b;
}
void rs232_putchar(unsigned char txd)
{
	SBUF = txd;
	while(!TI);				// 等特数据传送
	TI = 0;					// 清除数据传送标志
}
void rs232_printstr(unsigned char *str)
{

	while(*str!= '\0')
	{
		SBUF =*str++;
		while(!TI);				// 等特数据传送
		TI = 0;					// 清除数据传送标志
	}
	
}
void rs232_printhex(unsigned char b)
{

	unsigned char hexvalue;
#if 1
	rs232_printstr("0x");
#endif
	hexvalue=(b&0xf0)>>4;
	if(hexvalue<10)
	{
		rs232_putchar(hexvalue+'0');
	}
	else
	{
		rs232_putchar(hexvalue+55);
	}
	hexvalue=(b&0x0f);
	if(hexvalue<10)
	{
		rs232_putchar(hexvalue+'0');
	}
	else
	{
		rs232_putchar(hexvalue+55);
	}
#if 1
	rs232_printstr(" ");
#endif

}