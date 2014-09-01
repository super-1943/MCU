#include "msp430x14x.h"
#include "ziku12864.h"

unsigned char i,j;
unsigned char  Chinese_0[10];
unsigned char  Chinese_2[]={"燕山大学电子信息"};
unsigned char  Chinese_3[]={"赵永科07天下无协"};

int main( void )
{
  // Stop watchdog timer to prevent time out reset
    WDTCTL = WDTPW + WDTHOLD;
    init_12864();
    unsigned int count = 0;
          
      write_Chinese_12864(Chinese_2,16,0,8);
      write_Chinese_12864(Chinese_3,24,0,8);

    while(1)
    {
      IntToStr(count++,Chinese_0);
      write_Chinese_12864(Chinese_0,0,0,2);
      delay_12864(1000);
    }
}