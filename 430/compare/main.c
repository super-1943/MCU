
#include "msp430x16x.h"
unsigned char stat;

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
void delay(unsigned int i)
{
  unsigned char j;
  while(i--)
  {
    for(j=200;j;j--);
  }
}

void init_dac(void)
{
  ADC12CTL0=REF2_5V + REFON;
  DAC12_0CTL=DAC12IR+DAC12AMP_5+DAC12ENC;
  DAC12_1CTL=DAC12IR+DAC12AMP_5+DAC12ENC;
}
int main( void )
{
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;
  init_device();
  init_dac();
  P1DIR=0x10;
  P1OUT|=0x10;
  P2SEL|=0x18;
  delay(10);
  DAC12_1DAT=0;  
  delay(10);
  CACTL1=CAON+CAREF_2+CARSEL+CAIE;
  CACTL2=P2CA1+P2CA0;
  CAPD|=0xff;
  _EINT();
  while(1)
  {
    DAC12_1DAT+=1000;
    delay(100);
  }
}

#pragma vector=COMPARATORA_VECTOR
__interrupt void cp(void)
{
    if((CACTL2&CAOUT)==0)
    {
      P1OUT|=0x10;
    }
    else
    {
      P1OUT&=~0x10;
    }
}