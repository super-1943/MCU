
#include "msp430x15x.h"
#include"7219module.h"
int main( void )
{
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;
  initial_7219();
  send_7219(1,8);
  send_7219(2,7); 
  send_7219(3,6);
  send_7219(4,5);
  send_7219(5,4);
  send_7219(6,3);
  send_7219(7,2);
  send_7219(8,1);
  while(1)
  {
  }
  return 0;
}
