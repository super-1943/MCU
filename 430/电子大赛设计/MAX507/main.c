#include <msp430x16x.h>
#include "max507.h"
void main( void )
{
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;
  init_device();
  write_data_input(0xff,0x0f);
  write_data_DAC();
  while(1)
  {}
}