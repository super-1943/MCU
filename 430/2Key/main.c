/***********************************************************************
��������ʵ��
���ߣ�������
���ڣ�2009-6-10 
�޸ģ�2009-7-23
���ܣ�Э���msp430f149�������ϰ���������ʾ���������
***********************************************************************/
#include "msp430x14x1.h"
#include "led.h"
#include "key.h"
unsigned char mybuffer[6]={0};//��ʾ������������Ϊ6���ֽ�
int main( void )
{
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;
  init_led();
  while(1)
  {
    key(mybuffer);//��Ӧ��ֵ�����ݸ�*mybuffer
    show(mybuffer);//��ʾmybuffer����
  }
}
