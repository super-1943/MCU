#include <reg52.h>
#include <intrins.h>
#include "wireless.h"



sbit CE=P2^0;
sbit CSN=P2^1;
sbit SCK=P2^2;
sbit MOSI=P2^3;
sbit MISO=P2^4;
sbit IRQ=P2^5;

														//显示缓冲区
//******************************************************************************************
uint 	bdata sta;   				//NRF24L01状态标志
sbit	RX_DR	=sta^6;				
sbit	TX_DS	=sta^5;
sbit	MAX_RT	=sta^4;

uint const TX_ADDRESS[TX_ADR_WIDTH]= {0xff,0xff,0xff,0xff,0xff};	//本地地址
uint const RX_ADDRESS[RX_ADR_WIDTH]= {0xff,0xff,0xff,0xff,0xff};	//接收地址
void init_NRF24L01(void);
uint SPI_RW(uint u);
void SetRX_Mode(void);
uint SPI_RW_Reg(uchar reg, uchar value);
uint SPI_Write_Buf(uchar reg, uchar *pBuf, uchar uchars);
unsigned char nRF24L01_RxPacket(unsigned char* rx_buf);
void nRF24L01_TxPacket(unsigned char * tx_buf);

/******************************************************************************************
/*延时函数
/******************************************************************************************/
void inerDelay_us(unsigned char n)
{	
	for(;n>0;n--)
		_nop_();
}
//****************************************************************************************
/*NRF24L01初始化
//***************************************************************************************/
void init_NRF24L01(void)
{
    inerDelay_us(100);
 	CE=0;    // chip enable
 	CSN=1;   // Spi disable 
 	SCK=0;   // Spi clock line init high
	SPI_Write_Buf(WRITE_REG + TX_ADDR, TX_ADDRESS, TX_ADR_WIDTH);    // 写本地地址	
	SPI_Write_Buf(WRITE_REG + RX_ADDR_P0, RX_ADDRESS, RX_ADR_WIDTH); // 写接收端地址
	

	SPI_RW_Reg(WRITE_REG + SETUP_RETR, 0x00);      //  
	SPI_RW_Reg(WRITE_REG + EN_AA, 0x00);      //  频道0自动	ACK应答允许	
	SPI_RW_Reg(WRITE_REG + EN_RXADDR, 0x01);  //  允许接收地址只有频道0，如果需要多频道可以参考Page21  
	SPI_RW_Reg(WRITE_REG + SETUP_AW, 0x03);  //  地址宽度5字节
	SPI_RW_Reg(WRITE_REG + RF_CH, 10);        //   设置信道工作为2.4GHZ，收发必须一致
	SPI_RW_Reg(WRITE_REG + RX_PW_P0, RX_PLOAD_WIDTH); //设置接收数据长度，本次设置为8字节
	SPI_RW_Reg(WRITE_REG + RF_SETUP, 0x07);   		//设置发射速率为1Mkbps，发射功率为最大值0dB
}
/****************************************************************************************************
/*函数：uint SPI_RW(uint uchar)
/*功能：NRF24L01的SPI写时序,详细看时序图，Page19
/****************************************************************************************************/
uint SPI_RW(uint uchar)
{
	uint bit_ctr;
   	for(bit_ctr=0;bit_ctr<8;bit_ctr++) // output 8-bit
   	{
		MOSI = (uchar & 0x80);         // output 'uchar', MSB to MOSI
		uchar = (uchar << 1);           // shift next bit into MSB..
		SCK = 1;                      // Set SCK high..
		uchar |= MISO;       		  // capture current MISO bit
		SCK = 0;            		  // ..then set SCK low again
   	}
    return(uchar);           		  // return read uchar
}
/****************************************************************************************************/
/*功能：NRF24L01读写寄存器函数,
/****************************************************************************************************/
uint SPI_RW_Reg(uchar reg, uchar value)
{
	uint status;
	
	CSN = 0;                   // CSN low, init SPI transaction
	status = SPI_RW(reg);      // select register
	SPI_RW(value);             // ..and write value to it..
	CSN = 1;                   // CSN high again
	
	return(status);            // return nRF24L01 status uchar
}
/*********************************************************************************************************
/*函数：uint SPI_Write_Buf(uchar reg, uchar *pBuf, uchar uchars)
/*功能: 用于写数据：为寄存器地址，pBuf：为待写入数据地址，uchars：写入数据的个数
/*********************************************************************************************************/
uint SPI_Write_Buf(uchar reg, uchar *pBuf, uchar uchars)
{
	uint status,uchar_ctr;
	
	CSN = 0;            //SPI使能       
	status = SPI_RW(reg);   
	for(uchar_ctr=0; uchar_ctr<uchars; uchar_ctr++) //
		SPI_RW(*pBuf++);
	CSN = 1;           //关闭SPI
	return(status);    // 
}
/***********************************************************************************************************
/*函数：void nRF24L01_TxPacket(unsigned char * tx_buf)
/*功能：发送 tx_buf中数据
/**********************************************************************************************************/
void nRF24L01_TxPacket(unsigned char * tx_buf)
{
	CE=0;			//StandBy I模式	
	SPI_Write_Buf(WRITE_REG + RX_ADDR_P0, TX_ADDRESS, TX_ADR_WIDTH); // 装载接收端地址
	SPI_Write_Buf(WR_TX_PLOAD, tx_buf, TX_PLOAD_WIDTH); 			 // 装载数据	
	SPI_RW_Reg(WRITE_REG + CONFIG, 0x0e);   		 // IRQ收发完成中断响应，16位CRC，主发送
	CE=1;		 //置高CE，激发数据发送
	inerDelay_us(10);
}
