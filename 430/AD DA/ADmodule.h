#ifndef AD_module_h
#define DA_module_h
#define Num  4
unsigned int results[Num],averange;
void init_AD(void)
{
P6SEL|=0x01;  //ʹ��ADͨ��A0
ADC12CTL1=CONSEQ_2+SHP;//ʹ�ò���ʱ�ӣ����õ�ͨ�����ת��ģʽ
ADC12CTL0|=ADC12ON+MSC+REFON+REF2_5V+SHT0_8;//��ADC12,���ò���ʱ�ӣ�ѡ��ο���ѹ
//ADC12MCTL0|=INCH_10;//Ƭ���¶ȴ��������
ADC12IE|=0x01;//ʹ��ADC12IFG.0(��ӦADC12MEM0)
ADC12CTL0|=ENC;//ʹ��ת��
_EINT();//ȫ���ж�
ADC12CTL0|=ADC12SC;//��ʼת��
}
#pragma vector=ADC_VECTOR
__interrupt void ADC12ISR(void)
{
  static unsigned char i,index=0;
 results[index]=ADC12MEM0;//�����������IFG
 index++;
 if(index==Num)
 {index=0;
 averange=0;
 for(i=0;i<Num;i++)
   averange+=results[i]/Num;//ȡƽ��ֵ���Լ�С���
 }
}
#endif