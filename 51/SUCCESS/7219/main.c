#include <at89x51.h>
#include <intrins.h>
sbit DIN=P1^0;
sbit LOAD=P1^1;
sbit CLK=P1^2;

#define D0 0x01
#define D1 0x02
#define D2 0x03
#define D3 0x04
#define D4 0x05
#define D5 0x06
#define D6 0x07
#define D7 0x08

#define DecodeMode 0x09
#define Intensity 0x0a
#define ScanLimit 0x0b
#define ShutDown 0x0c
#define DisplayTest 0x0f

#define ShutDownMode 0x00
#define NormalOperation 0x01
#define DecodeDight 0xff
#define IntensityGrade 0x0a
#define ScanDight 0x07
#define TestMode 0x01
#define TestEnd 0x00
unsigned char data DisBuffer[8]={0,0,0,0,0,0,0,0};
unsigned char code display_list[]={0x7e,0x30,0x6d,0x79,0x33,0x5b,0x5f,0x70,0x7f,0x7b,
                                /* 0     1    2    3    4    5    6    7    8    9    */
								0x77,0x1f,0x4e,0x3d,0x4f,0x47,0x67,0x3e,0xff,0x00};
								/*A  B     C    D    E     F   P    U    all  none*/

void delay(unsigned char count)
{
    unsigned char j,k;
	while(count--)
	{
		for(j=43;j;j--)
		for(k=73;k;k--);
	}
}

void sendchar(unsigned char ch)
{
    unsigned char i,temp;
	_nop_();
	for(i=0;i<8;i++)
	{
		temp=ch&0x80;
		ch=ch<<1;
		if(temp)
		{
			DIN=1;
			CLK=0;
			CLK=1;
		}
		else
		{
			DIN=0;
			CLK=0;
			CLK=1;
		}
	}
}


void sendword(unsigned char addr,unsigned char num)
{
	LOAD=0;
	_nop_();
	sendchar(addr);
	_nop_();
	sendchar(num);
	_nop_();
	LOAD=1;
}

void init7219(void )
{
	sendword(ScanLimit,ScanDight);
	sendword(DecodeMode,DecodeDight);
	sendword(Intensity,IntensityGrade);
	sendword(ShutDown,NormalOperation);
}

void initmain(void)
{
	IE=0x00;
	IP=0x00;
	TH0=0xd8;TL0=0xf0;
	TMOD=0x01;
	TCON=0x11;
	PSW=0x00;
}

void main(void)
{
	initmain();
	init7219();
	sendword(DisplayTest,TestMode);
	delay(0x64);
	delay(0x64);
	sendword(DisplayTest,TestEnd);
	while(1)
	{
		unsigned char i,j;
		for(i=0;i<=9;i++)
		{
			delay(0x64);
			delay(0x64);
			init7219();
			for(j=0;j<8;j++)
			DisBuffer[j]=i;
			for(j=1;j<=8;j++)
			sendword(j,DisBuffer[j-1]);
		 }
	 }



 }




