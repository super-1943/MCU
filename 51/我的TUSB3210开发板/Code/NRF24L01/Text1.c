#include <reg52.h>
#include "serial.h"
#include "wireless.h"
extern void init_NRF24L01(void);
extern uint SPI_RW(uint u);
extern void SetRX_Mode(void);
extern uint SPI_RW_Reg(uchar reg, uchar value);
extern uint SPI_Write_Buf(uchar reg, uchar *pBuf, uchar uchars);
extern unsigned char nRF24L01_RxPacket(unsigned char* rx_buf);
extern void nRF24L01_TxPacket(unsigned char * tx_buf);

sbit CE=P2^0;
sbit CSN=P2^1;
sbit SCK=P2^2;
sbit MOSI=P2^3;
sbit MISO=P2^4;
sbit IRQ=P2^5;

unsigned char buffer[8]={7,8,9,3,3,2,1,0};
/*
sbit W_CE=P2^0;
sbit W_CSN=P2^1;
sbit W_SCK=P2^2;
sbit W_MOSI=P2^3;
sbit W_MISO=P2^4;
sbit W_IRQ=P2^5;

#define CMD_R_REG(r)	(r&0x1f)	
#define CMD_W_REG(r)	(0x20+(r&0x1f))
#define CMD_R_RX		0x61
#define CMD_W_TX		0xa0
#define FLUSH_TX		0xe1
#define FLUSH_RX		0xe2
#define REUSE_TX		0xe3
#define ACTIVATE		0x50
#define R_RX_WID		0x60
#define W_ACK(p)		(0xa8+(p&0x7))
#define W_TX_NAK		0xb0
#define NOP				0xff

volatile unsigned char count=0;

void init_io(void)
{
	W_CE=0;
	W_CSN=1;
	W_MISO=1;
	W_IRQ=1;
	W_CE=0;
	W_SCK=0;
}


unsigned char spi_byte(unsigned char b)
{
	unsigned char i;
	unsigned char ret=0;
	for(i=0;i<8;i++)
	{
		ret<<=1;
		if(b&0x80)
		{
			W_MOSI=1;
		}
		else
		{
			W_MOSI=0;
		}
		W_SCK=1;
		if(W_MISO)
		{
			ret|=0x01;
		}
		W_SCK=0;

		

		b<<=1;
	}
}

unsigned char read_status(void)
{
	unsigned char t;
	W_CSN=0;
	t=spi_byte(NOP);
	W_CSN=1;
	return t;
}
unsigned char get_tx_addr(unsigned char *buf)
{
	unsigned char i,ret;
	W_CSN=0;
	ret=spi_byte(CMD_R_REG(0x10));
	for(i=0;i<5;i++)
	{
		buf[i]=spi_byte(NOP);
	}	
	W_CSN=1;
	
}*/
void delay_ms(unsigned int k)
{
	unsigned char i,j;
	for(;k;k--)
	for(i=20;i;i--)
	for(j=100;j;j--);
}


void main(void)
{
	unsigned char tmp;
	P0=0x55;
	init_NRF24L01() ;				 //NRF24L01初始化配置
//	init_io();
	rs232_init();
	rs232_printstr("Hello world!\r\n");
	delay_ms(1000);
//	get_tx_addr(buffer);
//	for(tmp=0;tmp<5;tmp++)
	{
//		rs232_printhex(buffer[tmp]);
	}
	CE=0;			//StandBy I模式	
	SPI_RW_Reg(WRITE_REG + CONFIG, 0x0f); //接收
	CE=1;		 //置高CE，激发数据接收
	delay_ms(500);
	CSN=0;
	tmp=SPI_RW(0xff);
	CSN=1;
	rs232_printhex(tmp);
	while(1)
	{
		P0^=0xff;
		IRQ=1;
		CSN=0;
		SPI_RW(CD);      // select register
		tmp=SPI_RW(0);             // ..and write value to it..
		CSN=1;
		rs232_printstr("载波检测：");
		rs232_printhex(tmp);
		rs232_printstr("\r\n");
//		nRF24L01_TxPacket(buffer);	// Transmit Tx buffer data
//		delay_ms(500);
//		while(IRQ);
		CSN=0;
		tmp=SPI_RW(0xff);
		CSN=1;
		rs232_printstr("状态检测：");
		rs232_printhex(tmp);
		rs232_printstr("\r\n");
		SPI_RW_Reg(WRITE_REG+STATUS,0XFF);
//		while(!IRQ);
//		delay_ms(1000);
	}
}