/************************************************************************
IICͨ��ʵ�顪�����ߵ�Э��msp430f1491ѧϰ��
���ߣ�������
���ڣ�2009-7-23
�������ã�ʵ�ֻ���iicͨ��
************************************************************************/
#include "msp430x14x.h"
#include "iic.h"
#include "ds1307.h"
unsigned char i,j;
struct Timer mytimer;
void delay(unsigned int i)
{
  while(i--);
}  
int main( void )
{
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;
  /*
  mytimer.second=0x00;
  mytimer.minute=0x18;
  mytimer.hour=0x11;
  mytimer.week=0x04;
  mytimer.date=0x23;
  mytimer.month=0x07;
  mytimer.year=0x09;
  set_time(&mytimer);
  */
  while(1)
  {
    delay(1000);
    get_time(&mytimer);
  }

}
