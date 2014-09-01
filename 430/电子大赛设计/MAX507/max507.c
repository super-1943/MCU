#include <msp430x16x.h>
#include "max507.h"

void delay(unsigned int ms)
{
  unsigned int i,j;
  for(i=0;i<ms;i++)
    for(j=0;j<150;j++);
}

void init_device(void)
{
  CONTROL_DIR|=0x0f;
  CONTROL_OUT|=0x0f;
  DAT_LSB_DIR=0xff;
  DAT_MSB_DIR|=0x0f;
  DAT_LSB_OUT=0x00;
  DAT_MSB_OUT&=~(0x0f);
}

void write_data_input(unsigned char lsb,unsigned char msb)
{
  CS_0;
  _NOP();
  WR_0;
  _NOP();
  DAT_LSB_OUT=lsb;
  DAT_MSB_OUT=(0x0f&msb);
  _NOP();
  WR_1;
}
void write_data_DAC(void)
{WR_0;
CS_0;
LDAC_0;
delay(1000);
LDAC_1;
delay(1000);
}