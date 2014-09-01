#include "msp430x15x.h"
//some functions
void init_dac();
void delay();
void square(void);
void sanjiao(void);
//main function
int main( void )
{
  WDTCTL = WDTPW + WDTHOLD;
  sanjiao();
}

//initialization
void init_dac(void)
{
  ADC12CTL0=REF2_5V + REFON;
  DAC12_0CTL=DAC12IR+DAC12AMP_5+DAC12ENC;
}
//delay
void delay(unsigned int i)
{
  while(i--);
}
//square wave output
void square(void)
{
  init_dac();
  while(1)
  {
    DAC12_0DAT=0x0000;
    delay(8000);
    DAC12_0DAT=0x0fff;
    delay(4000);
  }
}
void sanjiao(void)
{
  init_dac();
  DAC12_0DAT=0x0000;
  while(1)
  {
    DAC12_0DAT++;
  }
}