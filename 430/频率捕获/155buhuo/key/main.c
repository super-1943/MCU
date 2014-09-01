
#include "msp430x15x.h"
unsigned int i;
unsigned char key(void)
{
    P5DIR&=~0xaa;
    P5OUT|=0xaa;
    if((P5IN & 0x02)==0x00)
    {
        return 4;
    }
    if((P5IN & 0x08)==0)
    {
        return 3;
    }
    if((P5IN & 0x20)==0)
    {
        return 2;
    }
    if((P5IN & 0x80)==0)
    {
        return 1;
    }
    return 0;
}
int main( void )
{
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;
    while(1)
    {
        i=key();
    }

}
