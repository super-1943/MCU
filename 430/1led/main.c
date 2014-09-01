/***************************************************************************
作者：赵永科
日期：2009-6-10
功能：使430板子上数码管显示数字，从左到右。
***************************************************************************/
#include "msp430x14x1.h"
#include "led.h"
unsigned char buffer[6]={0,1,2,3,4,9};/*显存，可在程序中更改*/
int main( void )
{
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;
  init_led();
  while(1)
  {
    show(buffer);
  }

}
