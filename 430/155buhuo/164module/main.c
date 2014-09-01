#include"164module.h"
#include <msp430x15x.h>
unsigned char buffer[]={0,9,0,7,3,1};
int main( void )
{ 
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;
  P4DIR=0xff;
   while(1)
   {
       show_164(buffer);    
   }
}
