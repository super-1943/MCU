#include "ad9833.h"
void init_ad9833(void)
{
  P5DIR|=0x2a;
  autoset(2,100);
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
  CS_1_9833;
  SCLK_1_9833;
  delay_ad9833(10);
  CS_0_9833;
  delay_ad9833(10);
  unsigned char i;
  for(i=0;i<16;i++)
  {
    SCLK_1_9833;
    if(d&0x8000)
    {
      SDATA_1_9833;
    }
    else
    {
      SDATA_0_9833;
    }
    SCLK_0_9833;
    d<<=1;    
  }
  SCLK_1_9833;
  delay_ad9833(100);
  CS_1_9833;
}
void send_freq_28(unsigned int low,unsigned int high)
{
  send_ad9833(Control_Reg_9833+B28_9833+RST_9833);
  delay_ad9833(100);
  send_ad9833(Freq0_Reg_9833+low);//low 14 bit
  delay_ad9833(100);
  send_ad9833(Freq0_Reg_9833+high);//high 14 bit
  delay_ad9833(100);
}
void send_freq_14(unsigned char hl,unsigned int d)
{
  if(hl!=0)
  {
    send_ad9833(Control_Reg_9833+HLB_9833+RST_9833); 
  }
  else
  {
    send_ad9833(Control_Reg_9833+RST_9833); 
  }
  delay_ad9833(100);
  send_ad9833(Freq0_Reg_9833+d);
  delay_ad9833(100);
  send_ad9833(Control_Reg_9833);
}
void send_phase(unsigned int ph)
{
  send_ad9833(Control_Reg_9833+RST_9833);
  delay_ad9833(100);
  send_ad9833(Phase0_Reg_9833+ph);
  delay_ad9833(100);
  send_ad9833(Control_Reg_9833);
}
void DA_sleep(void)
{
  send_ad9833(Control_Reg_9833+SLEEP2_9833);
}
void MCLK_sleep(void)
{
  send_ad9833(Control_Reg_9833+SLEEP1_9833);
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
  send_ad9833(Control_Reg_9833+B28_9833+RST_9833);
  delay_ad9833(100);
  switch(i)
  {
  case 0:
    send_ad9833(Control_Reg_9833+OPT_9833+DIV2_9833);
    break;
  case 1:
    send_ad9833(Control_Reg_9833);
    break;
  case 2:
    send_ad9833(Control_Reg_9833+MODE_9833);
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
void autoset_test(unsigned char bo,unsigned int freq)
{
  unsigned int high_freq,low_freq;
  high_freq=freq/4;
  low_freq=(freq*11+freq/10*2)%16384;
  send_freq_28(low_freq,high_freq);
  wave_select(bo);
}