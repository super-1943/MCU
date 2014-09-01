#ifndef _Frequence_h
#define _Frequence_h
unsigned int buff[4]={0};
double m=0,n=0;
unsigned char flag_freq=0;
unsigned int index=0;
double get_freq(double a)
{
  double t=8000.0;
  return (t/a);
}
void freq_cap(void)
{
    TACTL=TASSEL1+TACLR;//ϵͳʱ��8M
    CCTL0=CCIE+CM_1+SCS+CAP;//ѡ��CCI0A,�����ز���
    TACTL|=MC1;             //TA����ģʽ������ģʽ
    _EINT();    
    while(flag_freq<4);
    CCTL0&=~CCIE;
    _DINT();
}

double get_origfreq(void)
{
  unsigned char i;
  for(i=0;i<2;i++)
  {
    m+=buff[i];
    n+=buff[2+i];
  }
  return ((n-m)/4);
}
#endif