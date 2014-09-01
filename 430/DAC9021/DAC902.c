#include "msp430x16x.h"
#include "DAC902.h"

void delay(unsigned int i)
{
  while(i--);
}

void init_device(void)
{
  CLK_DIR=CLK;
  DAT_LSB_DIR=0xff;
  DAT_MSB_DIR=0xff;
  DAT_LSB_OUT=0x00;
  DAT_MSB_OUT=0x00;
  CLK_0;
}

void write_data(unsigned char lsb,unsigned char msb)
{
  CLK_0;
  DAT_LSB_OUT=lsb;
  DAT_MSB_OUT=msb;
  CLK_1;
  _NOP();
  _NOP();
  CLK_0;
  _NOP();
  _NOP();
}