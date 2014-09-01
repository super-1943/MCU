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
�ϸ�Ҫ��ʱ�����ڴ˷���һ�����Ͻ��Ĵ��󣬳�ʼ����CS_1,SCLK_1
���������ݴ�λ����Ҫ��������󣬷������������롣����
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
ѡ��Ƶ�ʡ�
ע��ѡ��Ƶ��ʱ�������Ҳ�����ѡ����ɺ�һ��
Ҫ�Ļ�ԭ�ȵĲ��Σ�
*********************************************/
void select_freq(unsigned int freq)
{
  unsigned int high_freq,low_freq;
  high_freq=freq/1465;
  low_freq=(freq*11+freq/10*2)%16384;
  send_freq_28(low_freq,high_freq);
}

/**********************************************
���β������ࣺ���������Ҳ������ǲ�
��Ӧ����iΪ��  0��    1��      2
����ѡ��������в��������һ����
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