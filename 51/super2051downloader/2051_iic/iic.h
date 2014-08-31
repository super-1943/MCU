#ifndef _kkk_iic_h
#define _kkk_iic_h
#include <reg51.h>
#include <intrins.h>

#define ADDR_pca6107 0xd0
/********************************
为了方便操作，写了三个常用宏
DDR(x)  和AVR一样，对应位为1代表输出，为0代表输入
PIN     得到引脚输入
POUT(x) 和AVR一样，对应位为1代表高电平输出，为0代表低电平输出
*********************************/
#define DDR(x) set_reg_6107(3,~(x))
#define PIN     get_reg_6107(0)
#define POUT(x) set_reg_6107(1,(x))
void set_reg_6107(unsigned char reg,unsigned char da);
unsigned char get_reg_6107(unsigned char reg);
/************************************************
IIC通信实验基于2051
作者：赵永科
日期：2009-12-12
函数作用：实现基本iic通信

硬件连接：
2051
P3.5----SCL
P3.4----SDA
************************************************/
void iic_init(void);
void iic_start(void);
void iic_stop(void);
void iic_send_byte(unsigned char d);
void iic_send_ack(void);
void iic_send_nack(void);
unsigned char iic_read_ack(void);
unsigned char iic_read_byte(void);

sbit SCL=P3^5;
sbit SDA=P3^4;
#define SDA_Mask 
#define SCL_Mask 
#define SDA_Dir  
#define SCL_Dir  
#define SDA_0 SDA=0
#define SDA_1 SDA=1
#define SCL_0 SCL=0
#define SCL_1 SCL=1
#define DataIn SDA
#define _NOP() 


void iic_init(void)
{
  SDA_1;
  SCL_1;
}
void iic_start(void)
{
  iic_init();
  SCL_1;
  SDA_1;
  _NOP();
  SDA_0;
}
void iic_stop(void)
{
  iic_init();
  SCL_1;
  SDA_0;
  _NOP();
  SDA_1;
}
void iic_send_byte(unsigned char d)
{
  unsigned char i;
  SCL_0;
  for(i=0;i<8;i++)
  {
    if(d&0x80)
    {
      SDA_1;
    }
    else
    {
      SDA_0;
    }
    SCL_1;
    d<<=1;
    _NOP();
    SCL_0;
  }
}
void iic_send_ack(void)
{
  SCL_0;
  _NOP();
  SDA_0;
  _NOP();
  SCL_1;
  _NOP();
  _NOP();
  SCL_0;
}
void iic_send_nack(void)
{
  SCL_0;
  _NOP();
  SDA_1;
  _NOP();
  SCL_1;
  _NOP();
  _NOP();
  SCL_0;  
}
unsigned char iic_read_ack(void)
{
  unsigned char t;
  SCL_0;
  _NOP();
  SDA_1;
  _NOP();
  SCL_1;
  if(SDA)//NACK
  {
    t=1;
  }
  else//ACK
  {
    t=0;
  }
  SCL_0;
  return t;
}
  
unsigned char iic_read_byte(void)
{
  unsigned char t=0,i;
  SCL_0;
  SDA_1;
  for(i=0;i<8;i++)
  {
    t<<=1;
    SDA_1;
    _NOP();
    SCL_1;
    _NOP();
    if(SDA)
    {
      t|=0x01;
    }
    SCL_0;
  }

  return t;
}
void set_reg_6107(unsigned char reg,unsigned char da)
{  
    iic_start();
    iic_send_byte(ADDR_pca6107);
    if(iic_read_ack());
    iic_send_byte(reg);
    if(iic_read_ack());
    iic_send_byte(da);
    if(iic_read_ack());
    iic_stop();
}
unsigned char get_reg_6107(unsigned char reg)
{
    unsigned char i;
    iic_start();
    iic_send_byte(ADDR_pca6107);
    if(iic_read_ack());
    iic_send_byte(reg);
    if(iic_read_ack());
    iic_start();
    iic_send_byte(ADDR_pca6107+1);
    if(iic_read_ack());
    i=iic_read_byte();
    iic_stop();
    return i;
}

#endif