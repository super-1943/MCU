
#include "msp430x15x.h"
void delay(unsigned int i)
{
  while(i--);
}
int main( void )
{
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;
  P6SEL|=0x01;
  ADC12CTL0=ADC12ON+SHT0_2+REF2_5V + REFON;
  DAC12_0CTL=DAC12IR+DAC12AMP_5+DAC12ENC;
  DAC12_0DAT=0x0000;
  ADC12CTL1=SHP;
  ADC12CTL0|=ENC;
  while(1)
  {
    DAC12_0DAT++;
    delay(20);
    ADC12CTL0|=ADC12SC;
    while((ADC12IFG&BIT0)==0);
    _NOP();
  }
}
