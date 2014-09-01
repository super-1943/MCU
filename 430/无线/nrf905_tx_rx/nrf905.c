#include "nrf905.h"


void delay_nrf905(unsigned int i)
{
  while(i--);
}
void init_port_nrf905(void)
{
  P1DIR=0xc5;
  P1OUT=0x00;
  P2DIR=0x03;
  P2OUT=0x00;
  CSN_1;
  SCK_0;
}

void send_byte_nrf905(unsigned char d)
{
  unsigned char i;
  SCK_0;
  for(i=0;i<8;i++)
  {
    if(d&0x80)
    {
      MOSI_1;
    }
    else
    {
      MOSI_0;
    }
    SCK_1;
    _NOP();
    SCK_0;
    d<<=1;
  }
  
}
unsigned char read_byte_nrf905(void)
{
  unsigned char i,t=0;
  SCK_0;
  for(i=0;i<8;i++)
  {
    SCK_1;
    t<<=1;
    if(MISO_IN)
    {
      t|=0x01;
    }
    SCK_0;
    _NOP();
  }
  return t;
}
unsigned char read_status_nrf905(void)
{
  unsigned char i,t=0;
  
  MOSI_0;
  SCK_0;
  CSN_0;
  for(i=0;i<8;i++)
  {
    SCK_1;
    t<<=1;
    if(MISO_IN)
    {
      t|=0x01;
    }
    SCK_0;
    _NOP();
  }
  CSN_1;
  return t;
}
void config_nrf905(void)
{
  init_port_nrf905();
  STAND_BY_MODE;  
  delay_nrf905(100);
  CSN_0;
  send_byte_nrf905(0x00);  //config
  
  send_byte_nrf905(0x01);
  send_byte_nrf905(0x0c);
  send_byte_nrf905(0x44);
  send_byte_nrf905(0x20);
  send_byte_nrf905(0x20);
  send_byte_nrf905(0xcc);
  send_byte_nrf905(0xcc);
  send_byte_nrf905(0xcc);
  send_byte_nrf905(0xcc);
  send_byte_nrf905(0x58);//       0 1 011 000
  CSN_1;
  CSN_0;
  send_byte_nrf905(WRITE_TX_ADDR);
  send_byte_nrf905(0xcc);
  send_byte_nrf905(0xcc);
  send_byte_nrf905(0xcc);
  send_byte_nrf905(0xcc);
  CSN_1;
  
}
/***********************************************************************
快速配置中心频率和输出功率
作用：使CH_NO=ch_no;
        HFREQ_PLL=hreq;
        PA_PWR=pa;
***********************************************************************/
void fast_config_nrf905(unsigned int ch_no,unsigned char hfreq,unsigned char pa)
{
  unsigned char i,j;
  init_port_nrf905();
  STAND_BY_MODE;  
  i=ch_no&0xff;
  j=(ch_no>>8)+((hfreq&0x01)<<1)+((pa&0x03)<<2)+0x80;
  CSN_0;
  send_byte_nrf905(j);  
  send_byte_nrf905(i);
  CSN_1;
}  