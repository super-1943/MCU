#include "msp430x16x.h"
#include "ad9833.h"
  
int main( void )
{
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;  
  init_ad9833();
  while(1)
  {
    scan_freq(100,10000,100,2);
    _NOP();
  }

}
