/***************************************************************************
���ߣ�������
���ڣ�2009-6-10
���ܣ�ʹ430�������������ʾ���֣������ҡ�
***************************************************************************/
#include "msp430x14x1.h"
#include "led.h"
unsigned char buffer[6]={0,1,2,3,4,9};/*�Դ棬���ڳ����и���*/
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
