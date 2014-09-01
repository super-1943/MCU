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
�ϸ�Ҫ��ʱ�����ڴ˷���һ�����Ͻ��Ĵ��󣬳�ʼ����CS_1,SCLK_1
���������ݴ�λ����Ҫ��������󣬷������������롣����
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