/***********************************************************************
按键控制实验
作者：赵永科
日期：2009-6-10 
修改：2009-7-23
功能：协会的msp430f149开发板上按键依次显示在数码管上
***********************************************************************/
#include "msp430x14x1.h"
#include "led.h"
#include "key.h"
unsigned char mybuffer[6]={0};//显示缓冲区，长度为6个字节
int main( void )
{
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;
  init_led();
  while(1)
  {
    key(mybuffer);//对应键值将传递给*mybuffer
    show(mybuffer);//显示mybuffer内容
  }
}
