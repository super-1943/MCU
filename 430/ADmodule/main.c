
#include <msp430x15x.h>
#include"ADmodule.h"
#include"7219module.h"
int main( void )
{
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;
  init_AD();
  init_7219();
  while(1)
{
  show_7219(1,averange%10);
  show_7219(2,(averange%100)/10); 
  show_7219(3,(averange%1000)/100);
  show_7219(4,averange/1000);
  show_7219(5,15);
  show_7219(6,15);
  show_7219(7,15);
  show_7219(8,15);
_NOP();
}
}
