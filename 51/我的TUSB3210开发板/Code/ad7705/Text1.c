#include <reg52.h>
#include "serial.h"

sbit SCK_7705=P2^0;
sbit DIN_7705=P2^1;
sbit DOUT_7705=P2^2;
sbit DRDY_7705=P2^3;




unsigned char buffer[8]={7,8,9,3,3,2,1,0};

/***************************************
AD7705SPI�ӿ���Ϣ��
8λ��MSB���ȣ�
SCK����Ϊ�ߣ������ز���
***************************************/
unsigned char spi_rwbyte(unsigned char d)
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
		SCK_7705=0;
		(d&0x80)?(DIN_7705=1):(DIN_7705=0);
		d<<=1;		
		SCK_7705=1;
		(DOUT_7705)?(d++):(d+=0);		
	}
	return d;
}
void init_spi(void)
{
	SCK_7705=1;
	DIN_7705=1;
	DOUT_7705=1;
	DRDY_7705=1;
}

#define RESET_AD7705()	{spi_rwbyte(0xff);spi_rwbyte(0xff);spi_rwbyte(0xff);spi_rwbyte(0xff);}

void delay_ms(unsigned int k)
{
	unsigned char i,j;
	for(;k;k--)
	for(i=20;i;i--)
	for(j=100;j;j--);
}
void init_ad7705(void)
{
	init_spi();
	RESET_AD7705();
	spi_rwbyte(0x20);//дClock�Ĵ���
	spi_rwbyte(0x00);//д0��ZERO��CLKOUT��ֹ��CLKDIV=1��������100Hz
	spi_rwbyte(0x10);//дSetup�Ĵ���
	spi_rwbyte(0x22);//��ͨģʽ������16��˫���ԣ������壬�˲���ͬ��=0
}

void main(void)
{
	unsigned char tmp;
	unsigned int advalue=0;
	P0=0x55;
	rs232_init();
	rs232_printstr("Hello\r\n");
	init_ad7705();
	while(1)
	{
		while(DRDY_7705);
		spi_rwbyte(0x38);
		tmp=spi_rwbyte(0x00);
		rs232_putchar(tmp);
		tmp=spi_rwbyte(0x00);
		rs232_putchar(tmp);
		init_ad7705();
//		delay_ms(200);
	}
}