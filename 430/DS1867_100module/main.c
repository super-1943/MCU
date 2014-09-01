
#include <msp430x15x.h>
#include"ds1867_100module.h"
unsigned char i=26;
void delay(unsigned int ms)
{  unsigned int i,j;
  for(i=0;i<ms;i++)
    for(j=0;j<150;j++);
}
int main( void )
{
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;
  P2DIR|=0x10;
  P2OUT|=0x10;
  init_1867_100();
  send_1867(0,170,0);
  while(1)
  {
  delay(100);
 // i+=1;
  }
}
