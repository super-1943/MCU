/****************************************************************************
�ļ�����dac���ڱȽ���
��д�ߣ�
������DAC12ת��ģ���������15xx 16xxϵ�С�
      MCLK��DCO   ACLK��32.768kHz
���ڣ�
*****************************************************************************/
#include <msp430x15x.h>
/****************************************************************************
��ʼ��DAC12
****************************************************************************/
#ifndef _DA_module_h
#define _DA_module_h
void  Dac12Write(unsigned int dat);
void delay_DA12(int ms)
{int i,j;
for(i=0;i<ms;i++)
for(j=0;j<700;j++);
}
void Init_FF()
{ unsigned int k;
   P1DIR&=~0x01;
   P1IES|=0x01;
   P1SEL|=0x02;
  BCSCTL1&=~XT2OFF;
  do
  {
    IFG1&=~OFIFG;
    for(k=0xff;k;k--);
  }while((IFG1&OFIFG)!=0);
  BCSCTL2|=SELM1+SELS;//MCLK=SMCLK=XT2;
}
void InitDac12()
{
	ADC12CTL0 = REF2_5V +REFON; 	//���ڲ��ο���ѹԴ,�ο���ѹΪ2.5V
	//����DAC12ͨ��0
	DAC12_0CTL=DAC12IR +DAC12AMP_5 + DAC12ENC+DAC12LSEL_1 ;	
	//������Ϊ�ο���ѹ�����ٶ�/���������12λ�ֱ��ʣ�Vref+Ϊ�ο���ѹ��
	DAC12_0CTL |= DAC12CALON;	//�Զ�У׼DA���
	//�ȴ�У׼����
	while(DAC12_0CTL & DAC12CALON == DAC12CALON);
        DAC12_0CTL |= DAC12ENC;//��DAC0
        Dac12Write(4095);
        delay_DA12(50);//��������ʱ�������ж���DA������㣬���±Ƚ������㣬���������жϣ�
        _EINT();
        P1IFG=0;//�����־����ֹ������ж�
        P1IE|=0x01;
}
/*****************************************************************************
*****************************************************************************/
void  Dac12Write(unsigned int dat)
{
		DAC12_0DAT = dat;
}
double get_fudu_xiuzheng(double x,double k)
{ double f;
  f=((x*2.6)/2048)/(1.0-k/2400);
  return f;
}
double get_fudu(double x)
{ double f;
  f=((x*2.6)/2048);
  return f;
}
#endif



