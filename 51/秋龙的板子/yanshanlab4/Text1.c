#include <reg51.h>
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

#include<stdio.h>

#define uchar unsigned char
#define uint  unsigned int
#define LOWBYTE(v)  ((unsigned char)(v))
#define HIGHBYTE(v)  ((unsigned char)(((unsigned int)(v))>>8))
/**************************************************************************************************************************
数码管控制：P0.0~P0.3控制位选，低电平有效；
			P2.0~P2.7控制段选，低电平有效；
			注意P2口线序反向，即数据0b10111100------》0b00111101
**************************************************************************************************************************/
unsigned char code tab[]={0xfc,0x60,0xda,0xf2,0x66,0xb6,0xbe,0xe0,0xfe,0xf6,0xee,0x3e,0x9c,0x7a,0x9e,0x8e};
unsigned char buffer[4]={0,0,0,0};

void delay(unsigned char i);
void show(void);
void byte_program(unsigned short int dataAddr,unsigned char dataByte);
unsigned char byte_verify(unsigned short int dataAddr);
void sector_erase(unsigned short int dataAddr);
int ready();
void error();
void main(void)
{
	unsigned int destAddr=BLK1_DST_ADDR;
	unsigned char byteCnt;
	unsigned char origData;
	unsigned char verifyData;
//	SFCF|=0x03;
	delay(100);
/*	sector_erase(destAddr);
	origData=0;
	for(byteCnt=0;byteCnt<SECT_SIZE;byteCnt++)
	{
		byte_program(destAddr,origData);
		verifyData=byte_verify(destAddr);
		if(verifyData!=origData)
		{
			error();
		}
		destAddr++;
		origData++;
	}
	ErrorCode=0;
*/
	while(1)
	{
		buffer[2]=1;
		buffer[3]=1;
		show();
	}
}
void delay(unsigned char i)
{
	unsigned char j,k;
	while(i--)
	{
		for(j=20;j;j--)
		for(k=10;k;k--);
	}
}


void show(void)
{
	P0=0xfe;
	P2=~tab[buffer[0]];
	delay(10);
	P0=0xfd;
	P2=~tab[buffer[1]];
	delay(10);
	P0=0xfb;
	P2=~tab[buffer[2]];
	delay(10);
	P0=0xf7;
	P2=~tab[buffer[3]];
	delay(10);
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
//	while((SFST&0x04)!=0);
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
//	while((SFST&0X04)!=0);
}

uchar byte_verify(uint dataAddr)
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
		show();
	}
}