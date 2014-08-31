#ifndef _kkk_iic_h
#define _kkk_iic_h
#include <reg52.h>
#include "serial.h"

/******这里需要改动！**********/
#define DEV_ADDR		0xa0

// I2C Registers
#define bI2CSTA                 (* (unsigned char xdata *)0xFFF0)    // I2C Status and Control Register
#define bI2CDAO                 (* (unsigned char xdata *)0xFFF1)    // I2C Data Out Register
#define bI2CDAI                 (* (unsigned char xdata *)0xFFF2)    // I2C Data In Register
#define bI2CADR                 (* (unsigned char xdata *)0xFFF3)    // I2C Address Register

//I2C Register bit map
#define I2CSTA_SWR          0x01        // Stop Write Enable
                                        // 0:disable, 1:enable
#define I2CSTA_SRD          0x02        // Stop Read Enable
                                        // 0:disable, 1:enable
#define I2CSTA_TIE          0x04        // I2C Transmitter Empty Interrupt Enable
                                        // 0:disable, 1:enable
#define I2CSTA_TXE          0x08        // I2C Transmitter Empty
                                        // 0:full, 1:empty
#define I2CSTA_400K         0x10        // I2C Speed Select
                                        // 0:100kHz, 1:400kHz
#define I2CSTA_ERR          0x20        // Bus Error Condition
                                        // 0:no bus error, 1:bus error
#define I2CSTA_RIE          0x40        // I2C Receiver Ready Interrupt Enable
                                        // 0:disable, 1:enable
#define I2CSTA_RXF          0x80        // I2C Receiver Full
                                        // 0:empty, 1:full
#define I2CADR_READ         0x01        // Read Write Command Bit
                                        // 0:write, 1:read
/**********************************************
函数作用：等待写入
返回值：0代表无错误，1代表有错误
************************************************/
unsigned char iic_waitforwrite(void)
{
	while(!(bI2CSTA&I2CSTA_TXE))
	{
		if(bI2CSTA&I2CSTA_ERR)//ERR bit 为1，说明有错误发生
		{
			bI2CSTA|=I2CSTA_ERR;//clear this bit
			return 1;
		}
	}
	return 0;
}
/**********************************************
函数作用：等待读取
返回值：0代表无错误，1代表有错误
************************************************/
unsigned char iic_waitforread(void)
{
	while(!(bI2CSTA&I2CSTA_RXF))
	{
		if(bI2CSTA&I2CSTA_ERR)//ERR bit 为1，说明有错误发生
		{
			bI2CSTA|=I2CSTA_ERR;//clear this bit
			return 1;
		}
	}
	return 0;
}
/**************************************************************************
函数作用：读取AT24CXX的内容
**************************************************************************/
unsigned char read_content(
	unsigned char bDevAddr,//设备地址在bI2CADR中的排列，AT24C01-AT24C16为0xa0
	unsigned int wAddr,//字节地址，对于AT24C08为0x000-0x3ff
	unsigned int wNum,//读取的字节数
	unsigned char *pbDataArray//读取的内容缓冲区
)
{
	unsigned char btemp;
	bI2CSTA&=~(I2CSTA_SRD|I2CSTA_SWR);
	btemp=wAddr>>8;
	btemp&=0x03;
	btemp<<=1;
	bI2CADR=bDevAddr+btemp;
	bI2CDAO=wAddr&0xff;
	if(iic_waitforwrite())
	{
		rs232_printstr("设定地址时发生错误\r\n");
		return 1;
	}
	bI2CADR=bDevAddr+btemp+1;//////////////////////////////////////////////
	bI2CDAO=0x00;//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	if(wNum>1)
	{
		while(wNum>1)
		{
			if(iic_waitforread())//ERR
			{
				rs232_printstr("读取数据时发生错误\r\n");
				return 1;
			}
			*pbDataArray++=bI2CDAI;
			wNum--;
		}
	}
	bI2CSTA|=I2CSTA_SRD;
	if(iic_waitforread())//ERR
	{
		rs232_printstr("读取数据时发生错误\r\n");
		return 1;
	}
	*pbDataArray=bI2CDAI;
	return 0;	

}
/**************************************************************************
函数作用：向AT24CXX写入内容
**************************************************************************/
unsigned char write_content(
	unsigned char bDevAddr,//设备地址在bI2CADR中的排列，AT24C01-AT24C16为0xa0
	unsigned int wAddr,//字节地址，对于AT24C08为0x000-0x3ff
	unsigned int wNum,//写入的字节数
	unsigned char *pbDataArray//写入的内容缓冲区
)
{
	unsigned char btemp;
	bI2CSTA&=~(I2CSTA_SRD|I2CSTA_SWR);
	btemp=wAddr>>8;
	btemp&=0x03;
	btemp<<=1;
	bI2CADR=bDevAddr+btemp;
	bI2CDAO=wAddr&0xff;
	if(iic_waitforwrite())
	{
		rs232_printstr("设定地址时发生错误\r\n");
		return 1;
	}
	if(wNum>1)
	{
		while(wNum>1)
		{
			bI2CDAO=*pbDataArray++;
			wNum--;
			if(iic_waitforwrite())//ERR
			{
				rs232_printstr("写入数据时发生错误\r\n");
				return 1;
			}
		}
	}
	bI2CSTA|=I2CSTA_SWR;
	bI2CDAO=*pbDataArray++;
	if(iic_waitforwrite())//ERR
	{
		rs232_printstr("写入数据时发生错误\r\n");
		return 1;
	}
	return 0;
}

#endif