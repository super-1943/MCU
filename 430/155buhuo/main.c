#include "msp430x15x.h"
//两路信号输入：P1.1和P1.2，
//其中P1.1测量频率，相位差为P1.1-P1.2值

#define data_1  P4OUT|=0x02;
#define data_0  P4OUT&=~0x02;
#define SCLK_1  P4OUT|=0x08;
#define SCLK_0  P4OUT&=~0x08;


unsigned char mykey=0;//获取键值
unsigned int myfreq=0,myphase=0;//获取频率
unsigned int firstphase=0,origfreq=0;
unsigned char flag_freq=0,count=0,flag_phase=0;
unsigned char Isfreq=1;

unsigned char buffer[6]={0};
unsigned char key(void)
{
    P5DIR&=~0xaa;
    P5OUT|=0xaa;
    if((P5IN & 0x02)==0x00)
    {
        return 4;
    }
    if((P5IN & 0x08)==0)
    {
        return 3;
    }
    if((P5IN & 0x20)==0)
    {
        return 2;
    }
    if((P5IN & 0x80)==0)
    {
        return 1;
    }
    return 0;
}
unsigned int get_freq(unsigned int a)
{
  unsigned long t=8000000;
  origfreq=a;
  return (t/a);
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
    P1SEL|=0x06;
}
void freq_cap(void)
{
    init_device();
    TACTL=TASSEL1+TACLR;//系统时钟8M
    CCTL0=CCIE+CM_1+SCS+CAP;//选择CCI0A,上升沿捕获
    TACTL|=MC1;             //TA计数模式：连续模式
    _EINT();    
    while(flag_freq<2);
    CCTL0&=~CCIE;
    _DINT();
}
void phase_cap(void)
{
    if(flag_phase==1)
    {
        TACTL=TASSEL1+TACLR;//系统时钟8M
        CCTL0=CCIE+CM_1+SCS+CAP;//选择CCI0A,上升沿捕获
        CCTL1=CCIE+CM_1+SCS+CAP;//选择CCI1A,上升沿捕获 
        TACTL|=MC1;             //TA计数模式：连续模式
        _EINT();
        while(flag_phase<3);
        CCTL1&=~CCIE;
        _DINT();
    }       
}
void clear(void)
{
    mykey=0;
    myfreq=0,myphase=0;
    firstphase=0,origfreq=0;
    flag_freq=0,count=0,flag_phase=0;
    buffer[0]=buffer[1]=buffer[2]=buffer[3]=buffer[4]=buffer[5]=0;
}
void send_bit_164(unsigned char i)
{
     if(i)
     {
        data_1;
     }
     else
     {
        data_0;
     }
     SCLK_0;
     SCLK_1;
}
void send_byte_164(unsigned char i)
{
    unsigned char j;
    for(j=0;j<8;j++)
    {
        send_bit_164(i&0x80);
        i<<=1;
    }
}
void delay_164(unsigned int ms)
{ 
    unsigned int i,j;
    for(i=0;i<ms;i++)
        for(j=0;j<130;j++);
}
void show(void)
{
    P4DIR|=0x0a;
    const unsigned char dig[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
    unsigned char i;
    for(i=0;i<6;i++)
    {
        send_byte_164(1<<i); 
        send_byte_164(dig[buffer[i]]); 
        delay_164(3);
    }    
}
int main( void )
{
  // Stop watchdog timer to prevent time out reset
    WDTCTL = WDTPW + WDTHOLD;
    while(1)
    {
        mykey=key();
        switch(mykey)
        {
        case 1:
            freq_cap();
            break;
        case 2:
            clear();
            break;
        case 3:
            if(flag_freq>=2)
            {
                flag_phase=1;
            }
            phase_cap();
            break;
        case 4:
            show();
            break;
        default:
            show();
            break;
        }
    }
             
}

#pragma vector=TIMERA0_VECTOR
__interrupt void timer_a0(void)
{
  static unsigned int a=0;
  if(flag_freq==0)
  {
    a=CCR0;
    flag_freq++;
  }
  else if(flag_freq==1)
  {
      if(CCR0<a)
        a=CCR0+(65535-a);
      else
      a=CCR0-a;
    myfreq=get_freq(a);
    buffer[5]=myfreq%10;
    buffer[4]=myfreq%100/10;
    buffer[3]=myfreq%1000/100;
    buffer[2]=myfreq%10000/1000;
    buffer[1]=myfreq/10000;
    buffer[0]=0;
    flag_freq++;
  }
  else
  {
     if(flag_phase==1)
     {
         firstphase=CCR0;
         flag_phase++;
     }
  }  
}

#pragma vector=TIMERA1_VECTOR
__interrupt void timer_a1(void)
{
    if(TAIV==2)
    {
      if(flag_phase==2)
      {
        if(CCR1<firstphase)
            myphase=CCR1+(65535-firstphase);
        else
        {
            myphase=CCR1-firstphase-21;//软件引起相位差
            unsigned int dushu;
            double mydushu=(double)myphase/origfreq;
                dushu=(unsigned int)(mydushu*360);
                buffer[5]=dushu%10;
                buffer[4]=dushu%100/10;
                buffer[3]=dushu%1000/100;
                buffer[2]=0;
                buffer[1]=0;
                buffer[0]=0;
        }
        flag_phase++;
      }
    }
}