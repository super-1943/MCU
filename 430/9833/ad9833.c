#include "ad9833.h"


void init_ad9833(void)
{
  P5DIR|=0x2a;
  autoset(1,100);
}
void delay_ad9833(unsigned int i)
{
  while(i--);
}
/***********************************************************
严格要求时序，我在此犯了一个不严谨的错误，初始必须CS_1,SCLK_1
否则导致数据错位，不要犯这类错误，否则后果不堪设想。。。
***********************************************************/
void send_ad9833(unsigned int d)
{
  CS_1;
  SCLK_1;
  delay_ad9833(10);
  CS_0;
  delay_ad9833(10);
  unsigned char i;
  for(i=0;i<16;i++)
  {
    SCLK_1;
    if(d&0x8000)
    {
      SDATA_1;
    }
    else
    {
      SDATA_0;
    }
    SCLK_0;
    d<<=1;    
  }
  SCLK_1;
  delay_ad9833(100);
  CS_1;
}
void send_freq_28(unsigned int low,unsigned int high)
{
  send_ad9833(Control_Reg+B28+RST_9833);
  delay_ad9833(100);
  send_ad9833(Freq0_Reg+low);//low 14 bit
  delay_ad9833(100);
  send_ad9833(Freq0_Reg+high);//high 14 bit
  delay_ad9833(100);
}
void send_freq_14(unsigned char hl,unsigned int d)
{
  if(hl!=0)
  {
    send_ad9833(Control_Reg+HLB+RST_9833); 
  }
  else
  {
    send_ad9833(Control_Reg+RST_9833); 
  }
  delay_ad9833(100);
  send_ad9833(Freq0_Reg+d);
  delay_ad9833(100);
  send_ad9833(Control_Reg);
}
void send_phase(unsigned int ph)
{
  send_ad9833(Control_Reg+RST_9833);
  delay_ad9833(100);
  send_ad9833(Phase0_Reg+ph);
  delay_ad9833(100);
  send_ad9833(Control_Reg);
}
void DA_sleep(void)
{
  send_ad9833(Control_Reg+SLEEP2);
}
void MCLK_sleep(void)
{
  send_ad9833(Control_Reg+SLEEP1);
}
/*********************************************
选择频率。
注意选择频率时会变成正弦波，故选择完成后，一定
要改回原先的波形！
*********************************************/
void select_freq(unsigned int freq)
{
  unsigned int high_freq,low_freq;
  high_freq=freq/1465;
  low_freq=(freq*11+freq/10*2)%16384;
  send_freq_28(low_freq,high_freq);
}

/**********************************************
波形产生种类：方波，正弦波，三角波
对应参数i为：  0，    1，      2
波形选择放在所有操作的最后一步！
**********************************************/
void wave_select(unsigned char i)
{
  send_ad9833(Control_Reg+B28+RST_9833);
  delay_ad9833(100);
  switch(i)
  {
  case 0:
    send_ad9833(Control_Reg+OPT_9833+DIV2);
    break;
  case 1:
    send_ad9833(Control_Reg);
    break;
  case 2:
    send_ad9833(Control_Reg+MODE);
    break;
  default:
    break;
  }
}

void autoset(unsigned char bo,unsigned int freq)
{
  select_freq(freq);
  wave_select(bo);
}