#include "msp430x14x.h"
#include"led.h"
#include "key.h"
unsigned int guancha=0;
unsigned char mykey=0;
unsigned char flag=0,count=0;
unsigned char buffer[6]={0};
void show_int(unsigned int a)
{
  buffer[0]=17;
  buffer[1]=a/10000;
  buffer[2]=(a%10000/1000);
  buffer[3]=(a%1000)/100;
  buffer[4]=(a%100)/10;
  buffer[5]=a%10;
}
void init_device(void)
{ 
    unsigned char i;
  
    BCSCTL1&=~XT2OFF;
    do
    {
        IFG1&=~OFIFG;
        for(i=0xff;i;i--);
    }while((IFG1&OFIFG)!=0);
    BCSCTL2|=SELM1+SELS;//MCLK=SMCLK=XT2;    
    P5SEL|=0x20;
    P2DIR=0x01;
    P2OUT=0xff;
    P2SEL|=0x04;
}
int main( void )
{
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;
    
    init_device();
    init_led();
    delay_led(500);
    while(1)
    {
        key(&mykey);
        switch(mykey)
        {
        case 0:
            break;
        case 1:
            if(flag==0)
            {
                TACTL=TASSEL1+TACLR;//ÏµÍ³Ê±ÖÓ8M
                CCTL0=CCIE+CM_1+SCS+CCIS0+CAP;
                TACTL|=MC1;
                _EINT();
            }
            if(flag==2)
            {
            }
            if(flag>=3)
            {
                TACTL|=TACLR;
                _DINT();
            }
           break;
        case 2:
           _DINT();
           flag=0;
           buffer[0]=buffer[1]=buffer[2]=buffer[3]=buffer[4]=buffer[5]=0;
           break;
        }
        show(buffer);
    }
}
#pragma vector=TIMERA0_VECTOR
__interrupt void timer_a(void)
{
  static unsigned int a=0;
  if(flag==0)
  {
    a=CCR0;
  }
  if(flag==1)
  {
      if(CCR0<a)
        a=CCR0+(65535-a);
      else
      a=CCR0-a;
      show_int(a);
      if(a<7000)
        guancha=CCR0;
  }
  flag++;
}