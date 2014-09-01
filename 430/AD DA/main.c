
#include <msp430x15x.h>
#include"DAmodule.h"
#include"ADmodule.h"
#include"7219module.h"
int main( void )
{unsigned int data;
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;
  init_AD();
  init_DA();
  init_7219();
  data=0x0666;
  send_DA(data);
  while(1)
{
  show_7219(1,averange%10);
  show_7219(2,(averange%100)/10); 
  show_7219(3,(averange%1000)/100);
  show_7219(4,averange/1000);
  show_7219(5,data%10);
  show_7219(6,(data%100)/10);
  show_7219(7,(data%1000)/100);
  show_7219(8,data/1000);
_NOP();
}
}
