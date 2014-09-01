#include "msp430x15x.h"
#include "ziku12864.h"

unsigned char i,j;
unsigned char  Chinese_0[10];
unsigned char  Chinese_2[]={"abcdefg"};
unsigned char  Chinese_3[]={"¿ØæÊ≥…ª“¿· º∏…°£"};

int main( void )
{
  // Stop watchdog timer to prevent time out reset
    WDTCTL = WDTPW + WDTHOLD;
    init_12864();
    unsigned int count = 0;
    while(1)
    {
      IntToStr(count++,Chinese_0);
      write_Chinese_12864(Chinese_0,0,0,2);
      write_Chinese_12864(Chinese_2,16,0,4);
      write_Chinese_12864(Chinese_3,24,0,8);
      delay_12864(1000);
    }
}