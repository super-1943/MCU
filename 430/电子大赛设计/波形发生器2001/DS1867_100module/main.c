
#include <msp430x15x.h>
#include"ds1867_100module.h"
unsigned char i=0;
void delay(unsigned int ms)
{  unsigned int i,j;
  for(i=0;i<ms;i++)
    for(j=0;j<150;j++);
}
int main( void )
{
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;
  init_1867_100();
  while(1)
  {
  send_1867(1,100,i);
  delay(100);
  i+=1;
  }
}
