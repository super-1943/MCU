#ifndef AD_module_h
#define DA_module_h
#define Num  4
unsigned int results[Num],averange;
void init_AD(void)
{
P6SEL|=0x01;  //使能AD通道A0
ADC12CTL1=CONSEQ_2+SHP;//使用采样时钟，设置单通道多次转换模式
ADC12CTL0|=ADC12ON+MSC+REFON+REF2_5V+SHT0_8;//打开ADC12,设置采样时钟，选择参考电压
//ADC12MCTL0|=INCH_10;//片内温度传感器输出
ADC12IE|=0x01;//使能ADC12IFG.0(对应ADC12MEM0)
ADC12CTL0|=ENC;//使能转换
_EINT();//全局中断
ADC12CTL0|=ADC12SC;//开始转换
}
#pragma vector=ADC_VECTOR
__interrupt void ADC12ISR(void)
{
  static unsigned char i,index=0;
 results[index]=ADC12MEM0;//保存结果，清除IFG
 index++;
 if(index==Num)
 {index=0;
 averange=0;
 for(i=0;i<Num;i++)
   averange+=results[i]/Num;//取平均值，以减小误差
 }
}
#endif