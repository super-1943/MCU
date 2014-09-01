#ifndef _kkk_system_h
#define _kkk_system_h
#define _4_4_key 1
#define DAC_1_2V 0x7cd
void init_dac(void)
{
  ADC12CTL0=REF2_5V + REFON;
  DAC12_0CTL=DAC12IR+DAC12AMP_5+DAC12ENC;
  DAC12_1CTL=DAC12IR+DAC12AMP_5+DAC12ENC;
  DAC12_0DAT=DAC_1_2V;
  DAC12_1DAT=DAC_1_2V;
}
void init_device(void)
{ 
    unsigned char i;  
    BCSCTL1&=~XT2OFF;
    do
    {
        IFG1&=~OFIFG;
        for(i=0xff;i;i--);
    }
    while((IFG1&OFIFG)!=0);
    BCSCTL2|=SELM1+SELS;//MCLK=SMCLK=XT2;
}
/****************************************************
新4*4键盘
2009-8-17
P1.0~P1.7-------------键盘8~1
键盘5~8有上拉电阻到Vcc，注意设置对应P1.0~P1.3为输入
****************************************************/
unsigned char key(void)
{
#ifdef _4_4_key
  P1DIR=0xf0;
  P1OUT=0xef;
  if((P1IN&0x01)==0)
  {
    while((P1IN&0x01)==0);
    return 16;
  }
  if((P1IN&0x02)==0)
  {
    while((P1IN&0x02)==0);
    return 15;
  }
  if((P1IN&0x04)==0)
  {
    while((P1IN&0x04)==0);
    return 14;
  }
  if((P1IN&0x08)==0)
  {
    while((P1IN&0x08)==0);
    return 13;
  }
  P1OUT=0xdf;
  if((P1IN&0x01)==0)
  {
    while((P1IN&0x01)==0);
    return 12;
  }
  if((P1IN&0x02)==0)
  {
    while((P1IN&0x02)==0);
    return 11;
  }
  if((P1IN&0x04)==0)
  {
    while((P1IN&0x04)==0);
    return 10;
  }
  if((P1IN&0x08)==0)
  {
    while((P1IN&0x08)==0);
    return 9;
  }
  P1OUT=0xbf;
  if((P1IN&0x01)==0)
  {
    while((P1IN&0x01)==0);
    return 8;
  }
  if((P1IN&0x02)==0)
  {
    while((P1IN&0x02)==0);
    return 7;
  }
  if((P1IN&0x04)==0)
  {
    while((P1IN&0x04)==0);
    return 6;
  }
  if((P1IN&0x08)==0)
  {
    while((P1IN&0x08)==0);
    return 5;
  }
  P1OUT=0x7f;
  if((P1IN&0x01)==0)
  {
    while((P1IN&0x01)==0);
    return 4;
  }
  if((P1IN&0x02)==0)
  {
    while((P1IN&0x02)==0);
    return 3;
  }
  if((P1IN&0x04)==0)
  {
    while((P1IN&0x04)==0);
    return 2;
  }
  if((P1IN&0x08)==0)
  {
    while((P1IN&0x08)==0);
    return 1;
  }
  return 0;
#else
  unsigned char i=P4IN;
  if(!(i&0x01))//key1
  {    
    while(!(P4IN&0x01));
    return 1;
  }
  if(!(i&0x04))
  {   
    while(!(P4IN&0x04));
    return 2;
  }
  if(!(i&0x10))
  {
    while(!(P4IN&0x10));
    return 3;
  }
  if(!(i&0x40))
  {
    while(!(P4IN&0x40));
    return 7;
  }
  else
    return 0;

#endif
}

#endif