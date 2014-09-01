
#include "msp430x15x.h"
#include"7219module.h"
int main( void )
{unsigned char i=0;
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;
  init_7219();
  /*show_7219(1,1);
  show_7219(2,2); 
  show_7219(3,3);
  show_7219(4,4);
  show_7219(5,5);
  show_7219(6,6);
  show_7219(7,7);
  show_7219(8,8);*/
  while(1)
  {
    show_7219(1,i%10);
  show_7219(2,(i+1)%10); 
  show_7219(3,(i+2)%10);
  show_7219(4,(i+3)%10);
  show_7219(5,(i+4)%10);
  show_7219(6,(i+5)%10);
  show_7219(7,(i+6)%10);
  show_7219(8,(i+7)%10);
  i++;
  delay_7219(300);
  if(i==10)
    i=0;
  }
  return 0;
}
