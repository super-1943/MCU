
#include "msp430x16x.h"
#include "pga113.h"



unsigned int i;
int main( void )
{
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;
  init_pga113();
  send_data_pga113(NORMAL);
  delay_pga113(10);
  send_data_pga113(WRITEMODE+Gain(1)+CH(0));
  while(1)
  {
    i=read_data_pga113();
  }

}
