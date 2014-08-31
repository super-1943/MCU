#ifndef _kkk_iic_h
#define _kkk_iic_h
#include <reg52.h>
#include "serial.h"

/******������Ҫ�Ķ���**********/
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
�������ã��ȴ�д��
����ֵ��0�����޴���1�����д���
************************************************/
unsigned char iic_waitforwrite(void)
{
	while(!(bI2CSTA&I2CSTA_TXE))
	{
		if(bI2CSTA&I2CSTA_ERR)//ERR bit Ϊ1��˵���д�����
		{
			bI2CSTA|=I2CSTA_ERR;//clear this bit
			return 1;
		}
	}
	return 0;
}
/**********************************************
�������ã��ȴ���ȡ
����ֵ��0�����޴���1�����д���
************************************************/
unsigned char iic_waitforread(void)
{
	while(!(bI2CSTA&I2CSTA_RXF))
	{
		if(bI2CSTA&I2CSTA_ERR)//ERR bit Ϊ1��˵���д�����
		{
			bI2CSTA|=I2CSTA_ERR;//clear this bit
			return 1;
		}
	}
	return 0;
}
/**************************************************************************
�������ã���ȡAT24CXX������
**************************************************************************/
unsigned char read_content(
	unsigned char bDevAddr,//�豸��ַ��bI2CADR�е����У�AT24C01-AT24C16Ϊ0xa0
	unsigned int wAddr,//�ֽڵ�ַ������AT24C08Ϊ0x000-0x3ff
	unsigned int wNum,//��ȡ���ֽ���
	unsigned char *pbDataArray//��ȡ�����ݻ�����
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
		rs232_printstr("�趨��ַʱ��������\r\n");
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
				rs232_printstr("��ȡ����ʱ��������\r\n");
				return 1;
			}
			*pbDataArray++=bI2CDAI;
			wNum--;
		}
	}
	bI2CSTA|=I2CSTA_SRD;
	if(iic_waitforread())//ERR
	{
		rs232_printstr("��ȡ����ʱ��������\r\n");
		return 1;
	}
	*pbDataArray=bI2CDAI;
	return 0;	

}
/**************************************************************************
�������ã���AT24CXXд������
**************************************************************************/
unsigned char write_content(
	unsigned char bDevAddr,//�豸��ַ��bI2CADR�е����У�AT24C01-AT24C16Ϊ0xa0
	unsigned int wAddr,//�ֽڵ�ַ������AT24C08Ϊ0x000-0x3ff
	unsigned int wNum,//д����ֽ���
	unsigned char *pbDataArray//д������ݻ�����
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
		rs232_printstr("�趨��ַʱ��������\r\n");
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
				rs232_printstr("д������ʱ��������\r\n");
				return 1;
			}
		}
	}
	bI2CSTA|=I2CSTA_SWR;
	bI2CDAO=*pbDataArray++;
	if(iic_waitforwrite())//ERR
	{
		rs232_printstr("д������ʱ��������\r\n");
		return 1;
	}
	return 0;
}

#endif