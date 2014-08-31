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


sfr AUXR=0x8e;
sfr WDTD=0x85;
sfr WDTC=0xc0;
sfr SFCF=0xb1;
sfr SFCM=0xb2;
sfr SFAL=0xb3;
sfr SFAH=0xb4;
sfr SFDT=0xb5;
sfr SFST=0xb6;
#define SFCM_SE 0x0b
#define SFCM_VB 0x0c
#define SFCM_PB 0x0e



const unsigned short int BLK1_DST_ADDR=0xee00;
const unsigned char SECT_SIZE=0x80;
unsigned char ErrorCode;
unsigned char tcount=0;
void byte_program(unsigned short int dataAddr,unsigned char dataByte);
unsigned char byte_verify(unsigned short int dataAddr);
void sector_erase(unsigned short int dataAddr);
int ready();
void error();


unsigned char readcode(unsigned int addr);
#define PORTA XBYTE[0x8fff]
#define PORTB XBYTE[0x9fff]
#define PORTC XBYTE[0xafff]
#define CADDR XBYTE[0xbfff]
#define ADREAD XBYTE[0x00ff]
unsigned char code table[]={
0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71,0x00
};
/*
unsigned char code wuxie[]=
{

0x00,0x0F,0x7C,0x0C,0x7F,0x0C,0x0C,0x0F,0x1C,0xFC,0x0C,0x0F,0x3C,0x18,0x00,0x00,
0xC0,0xF0,0xD8,0xD8,0xFC,0xC0,0xD8,0xD8,0xF0,0x60,0xE6,0xB6,0x1E,0x0E,0x00,0x00, 
0X00,0X3F,0X01,0X01,0X01,0X01,0X7F,0X01,0X01,0X02,0X02,0X04,0X08,0X10,0X20,0X40,
0X00,0XFC,0X00,0X00,0X00,0X00,0XFE,0X00,0X00,0X80,0X40,0X20,0X18,0X0E,0X04,0X00,
0X00,0X3F,0X01,0X01,0X01,0X01,0X7F,0X01,0X01,0X02,0X02,0X04,0X08,0X10,0X20,0X40,
0X00,0XFC,0X00,0X00,0X00,0X00,0XFE,0X00,0X00,0X80,0X40,0X20,0X18,0X0E,0X04,0X00,
0X08,0X08,0X1F,0X10,0X20,0X4F,0X00,0X1F,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0XFE,0X00,0X00,0XF8,0X00,0XF0,0X10,0X10,0X10,0X10,0X0A,0X0A,0X06,0X02,
0X00,0X7F,0X01,0X01,0X01,0X01,0X03,0X05,0X09,0X11,0X21,0X41,0X01,0X01,0X01,0X00,
0X04,0XFE,0X80,0X00,0X00,0X00,0X60,0X30,0X18,0X0C,0X08,0X00,0X00,0X00,0X00,0X00,
0X10,0X10,0X3C,0X21,0X40,0X7C,0X93,0X10,0XFD,0X11,0X11,0X11,0X11,0X15,0X19,0X11,
0X90,0X90,0X90,0XFC,0X90,0X90,0XFE,0X00,0XFC,0X04,0X04,0XFC,0X04,0X04,0XFC,0X04,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X30,0X30,0X10,0X20,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X10,0X10,0X17,0XFD,0X11,0X12,0X1A,0X37,0XD0,0X19,0X15,0X12,0X13,0X14,0X58,0X20,
0X00,0X0E,0X70,0X10,0X10,0X10,0X7E,0X90,0X90,0X10,0X10,0X7C,0X00,0X80,0X7E,0X00,
0X00,0X1F,0X10,0X10,0X14,0X12,0X11,0X10,0X10,0X11,0X12,0X24,0X28,0X40,0X80,0X00,
0X00,0XF8,0X08,0X48,0X68,0X48,0X48,0X88,0X88,0X48,0X6A,0X2A,0X26,0X06,0X02,0X00,
0X00,0X07,0X78,0X08,0X08,0X7F,0X08,0X18,0X1C,0X2A,0X2B,0X4A,0X88,0X08,0X08,0X08,
0X00,0X00,0X00,0X7C,0X44,0X44,0X44,0X44,0X44,0X44,0X44,0X44,0X7C,0X44,0X00,0X00,
0X00,0X1F,0X10,0X10,0X10,0X10,0X1F,0X10,0X10,0X10,0X10,0X10,0X1F,0X10,0X00,0X00,
0X00,0XF0,0X10,0X10,0X10,0X10,0XF0,0X10,0X10,0X10,0X10,0X10,0XF0,0X10,0X00,0X00,
0X00,0XFF,0X00,0X00,0X7E,0X42,0X42,0X62,0X52,0X5A,0X52,0X42,0X42,0X4E,0X44,0X00,
0X00,0XFE,0X00,0X00,0XFC,0X84,0XC4,0XA4,0XB4,0XA4,0X84,0X84,0X84,0XBC,0X88,0X00,
0X10,0X10,0X20,0X7C,0X45,0X45,0X46,0X7C,0X44,0X44,0X44,0X44,0X7C,0X44,0X40,0X00,
0X80,0X80,0X80,0XFC,0X04,0X04,0X04,0X84,0X44,0X64,0X24,0X04,0X04,0X28,0X10,0X00,
0X00,0X00,0X00,0X00,0X10,0X10,0X10,0X10,0X10,0X10,0X10,0X10,0X10,0X00,0X10,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X10,0X10,0X10,0X10,0X10,0X10,0X10,0X10,0X10,0X00,0X10,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00
};
*/
unsigned char buffer[8]={0,0,0,0,0,0,0,0};
void delay(unsigned char j)
{
	unsigned char i;
	for(i=123;i;i--)
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
	PORTB=0xfe;
	PORTA=0x00;
	for(i=0;i<8;i++)
	{
		PORTA=table[buf[i]];
		delay(3);
		PORTB<<=1;
		PORTB+=1;
//		PORTC<<=1;
	}
}
void init(void)
{
	SFCF|=0x03;
}

void main(void)
{
	unsigned short int destAddr=0xee00;
	unsigned char byteCnt;
	unsigned int origData=0;
	unsigned char verifyData;
	unsigned char count;
//	init();

/*	for(count=0;count<4;count++)
	{
		sector_erase(destAddr+128*count);
		for(byteCnt=0;byteCnt<SECT_SIZE;byteCnt++)
		{
			byte_program(destAddr+128*count,wuxie[origData]);
			verifyData=byte_verify(destAddr);
			if(verifyData!=origData)
			{
				error();
			}
			destAddr++;
			origData++;
		}
	}
	ErrorCode=0;
*/	
	while(1)
	{
//		buffer[0]=readcode(0xee00);
//		buffer[1]=readcode(0xee01);
//		buffer[2]=readcode(0xee02);
//		buffer[3]=readcode(0xee03);
		show(buffer);
	}
}
void sector_erase(unsigned short int dataAddr)
{
	unsigned short int destAddr=dataAddr;
	SFCF|=0x40;
	SFAH=destAddr>>8;
	SFAL=destAddr;
	SFCM=SFCM_SE;
	if(!ready())
		error();
}

void byte_program(unsigned short int dataAddr,unsigned char dataByte)
{
	unsigned short int destAddr=dataAddr;
	SFCF|=0x40;
	SFAH=destAddr>>8;
	SFAL=destAddr;
	SFDT=dataByte;
	SFCM=SFCM_PB;
	if(!ready())
		error();
}

unsigned char byte_verify(unsigned int dataAddr)
{
	unsigned short int destAddr=dataAddr;
	unsigned char readByte;
	SFCF|=0x40;
	SFAH=destAddr>>8;
	SFAL=destAddr;
	SFCM=SFCM_VB;
	readByte=SFDT;
	
	SFCF&=0xbf;
	SFDT=0;
	return readByte;
}

int ready()
{
	unsigned long int TimeOut=0;
	
	while(TimeOut<100000)
	{
		if((SFST&4)==0)
		{
			SFCF&=0xbf;
			SFDT=0;
			return 1;
		}
		TimeOut++;
	}
	SFCF&=0xbf;
	SFDT=0;
	return 0;
}

void error()
{
	ErrorCode=1;
	buffer[0]=1;
	while(1)
	{
		show(buffer);
	}
}
unsigned char readcode(unsigned int addr)
{
	unsigned char code * pcode;
	pcode=(unsigned char code *)addr;
	return *pcode;
}