#include "reg51.h"
#include "intrins.h"
#define _NOP() 

#define SDA_Mask (1<<5)
#define SCL_Mask (1<<4)
#define SDA_Dir  P3
#define SCL_Dir  P3
#define SDA_0 P3&=~SDA_Mask
#define SDA_1 P3|=SDA_Mask
#define SCL_0 P3&=~SCL_Mask
#define SCL_1 P3|=SCL_Mask
#define DataIn P3
typedef bit uint1;
typedef unsigned char uint8, uchar, UCHAR;
typedef unsigned int uint16, uint, UINT;
typedef unsigned long uint32, ulong, ULONG;

void iic_init(void)
{
  SDA_Dir|=SDA_Mask;
  SCL_Dir|=SCL_Mask;
  SDA_1;
  SCL_1;
}
void iic_start(void)
{
//	iic_init();
	SCL_1;
	SDA_1;
	_NOP();
	SDA_0;
}
void iic_stop(void)
{
//	iic_init();
	SDA_0;
	_NOP();
	SCL_1;
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
  if(DataIn&SDA_Mask)//NACK
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
  SDA_Dir&=~SDA_Mask;
  SDA_1;
  for(i=0;i<8;i++)
  {
    t<<=1;
    SDA_1;
    _NOP();
    SCL_1;
    _NOP();
    if(DataIn&SDA_Mask)
    {
      t|=0x01;
    }
    SCL_0;
  }
  SDA_Dir|=SDA_Mask;
  return t;
}

void init_serial(void)
{
	TMOD=0x20;
	TH1=0xf3;
	TL1=0xf3;
//	PCON=0x80;//baud=19200@11059200Hz
	TR1=1;
	SM1=1;
	SM0=0;
	REN=1;
	EA=1;
//	ES=1;
}
void send_byte(uint8 b)
{
	EA=0;
	SBUF=b;
	while(!TI);
	TI=0;
	EA=1;
}
void print_str(uint8 * str)
{
	while((*str)!=0)
	{
		send_byte(*str);
		str++;
	}
}
void delay_ms(uint16 t)
{
	uint16 a;
	while(t--)
	{
		for(a=0;a<255;a++);
	}
}
void main(void)
{
	unsigned char i;
	iic_init();
	iic_start();
	iic_send_byte(0xd0);
	i=iic_read_ack();
	_NOP();
	iic_send_byte(0x00);
	_NOP();
	i=iic_read_ack();
	iic_stop();
	while(1)
	{
	
	}

}