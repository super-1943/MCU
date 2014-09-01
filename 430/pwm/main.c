#include "msp430x16x.h"
unsigned int mydata;
void delay(unsigned int i)
{
  while(i--);
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
    
  P6SEL|=0x01;
  ADC12CTL0=ADC12ON+SHT0_2+REFON+REF2_5V;
  ADC12CTL1=SHP;
  ADC12MCTL0=SREF_1;
  ADC12IE|=BIT0;
  _EINT();
}
int main( void )
{
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;
  init_device();
  TACTL=TASSEL1+TACLR;
  CCR0=4000;
  CCTL1=OUTMOD_7;
  CCR1=800;
  P1DIR|=0x04;
  P1SEL|=0x04;
  TACTL|=MC0;


  ADC12CTL0|=ENC;
  ADC12CTL0|=ADC12SC;
  while(1)
  {
    _BIS_SR(LPM1_bits);
  }
}

#pragma vector=ADC12_VECTOR
__interrupt void adc12_int(void)
{
    mydata=ADC12MEM0;
//    delay(60000);
    ADC12CTL0|=ADC12SC;
}