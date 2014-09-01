
#include "msp430x16x.h"
#include "ad7705.h"

unsigned char i;
unsigned int result[10];
unsigned char index=0;
void init_dac(void)
{
  ADC12CTL0=REF2_5V + REFON;
  DAC12_0CTL=DAC12IR+DAC12AMP_5+DAC12ENC;
}


int main( void )
{
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;
  init_dac();
  AD7705_Initsss();
  delay_ms(100);
  DAC12_0DAT=0x0450;  
  while(1)
  {
    DAC12_0DAT+=0x0100;
    result[index++]=AD7705_Result();
    delay_ms(10);
    if(index==10)
    {
      while(1);
    }
  }

}
