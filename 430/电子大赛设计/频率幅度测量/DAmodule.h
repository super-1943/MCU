/****************************************************************************
文件名：dac用于比较器
编写者：
描述：DAC12转换模块程序。用于15xx 16xx系列。
      MCLK：DCO   ACLK：32.768kHz
日期：
*****************************************************************************/
#include <msp430x15x.h>
/****************************************************************************
初始化DAC12
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
	ADC12CTL0 = REF2_5V +REFON; 	//打开内部参考电压源,参考电压为2.5V
	//设置DAC12通道0
	DAC12_0CTL=DAC12IR +DAC12AMP_5 + DAC12ENC+DAC12LSEL_1 ;	
	//满量程为参考电压，中速度/电流输出，12位分辨率，Vref+为参考电压，
	DAC12_0CTL |= DAC12CALON;	//自动校准DA输出
	//等待校准结束
	while(DAC12_0CTL & DAC12CALON == DAC12CALON);
        DAC12_0CTL |= DAC12ENC;//打开DAC0
        Dac12Write(4095);
        delay_DA12(50);//必须有延时，否则开中断是DA还输出零，导致比较器出零，立即进入中断！
        _EINT();
        P1IFG=0;//清楚标志，防止误进入中断
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



