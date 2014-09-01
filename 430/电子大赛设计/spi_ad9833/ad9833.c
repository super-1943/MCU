#include "ad9833.h"
/******************************************************************************
AD9833��������
���ߣ�������
���ڣ�
�޸����ڣ�2009-08-26
�޸����ݣ�������Ӳ��SPI������ɨƵ���
******************************************************************************/
void init_ad9833(void)
{
  
#if hard_ware_en < 1  
  
  P5DIR|=0x2a;
  
#else  
  
  P5DIR|=0x02;
  U0CTL=CHAR+SYNC+MM+SWRST;                   /*����Ϊͬ��SPIģʽ��������8λ*/
  U0TCTL=CKPH+CKPL+SSEL1+STC;  /*AD9833Ӧ������Ϊʱ���½����������ݣ�3�߽ӿڣ�ʹ��SMCLK��Ϊʱ��Դ*/
  U0BR1=0x00;
  U0BR0=0x04;                                 /*����������*/
  P3SEL=0x0e;
                                              //P3.1----SIMO
                                              //P3.2----SOMI
                                              //P3.3----UCLK
  ME1=USPIE0;
  U0CTL&=~SWRST;
#endif
  autoset(2,100);
}
void delay_ad9833(unsigned int i)
{
  while(i--);
}
/***********************************************************
����ѡ�����SPI��ʽ��Ӳ��SPI��ʽ
***********************************************************/
void send_ad9833(unsigned int d)
{
  CS_1_9833;
  delay_ad9833(10);
  CS_0_9833;
  delay_ad9833(10);
#if hard_ware_en<1
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
#else
    TXBUF0=d>>8;
    while((IFG1&UTXIFG0)==0);  
    TXBUF0=d&0xff;
    while((IFG1&UTXIFG0)==0);  
#endif
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
void scan_freq(unsigned int start_freq,unsigned int end_freq,unsigned int step,unsigned char bo)
{
  for(;start_freq<end_freq-step;start_freq+=step)
  {
    select_freq(start_freq);
    wave_select(bo);
    delay_ad9833(50000);
  }
}