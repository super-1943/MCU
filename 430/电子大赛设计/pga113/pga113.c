#include "pga113.h"
void delay_pga113(unsigned int i)
{
  while(i--);
}
void send_data_pga113(unsigned int d)
{
  CS_1_pga113;
  SCLK_0_pga113;
  delay_pga113(10);
  CS_0_pga113;
  delay_pga113(10);
  unsigned char i;
  for(i=0;i<16;i++)
  {
    SCLK_0_pga113;
    if(d&0x8000)
    {
      SDATA_1_pga113;
    }
    else
    {
      SDATA_0_pga113;
    }
    SCLK_1_pga113;
    d<<=1;    
  }
  SCLK_0_pga113;
  delay_pga113(10);
  CS_1_pga113;
}
unsigned int read_data_pga113(void)
{
  unsigned int i,d=0;
  init_pga113();
  send_data_pga113(READMODE);
  DIR_IN_pga113;
  CS_0_pga113;
  for(i=0;i<16;i++)
  {
    d<<=1;
    SCLK_0_pga113;
    _NOP();
    SCLK_1_pga113;
    _NOP();
    if(DATA_IN_pga113)
    {
      d|=0x0001;
    }
  }
  SCLK_0_pga113;
  delay_pga113(10);
  CS_1_pga113;
  return d;
}
void init_pga113(void)
{
  INIT_pga113;
  CS_1_pga113;
  SCLK_0_pga113;
}