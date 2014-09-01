#include "msp430x14x1.h"
#include "iic.h"



void iic_init(void)
{
  SDA_Dir|=SDA_Mask;
  SCL_Dir|=SCL_Mask;
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
  SDA_Dir&=~SDA_Mask;
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
  SDA_Dir|=SDA_Mask;
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