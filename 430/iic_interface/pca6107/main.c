/************************************************************************
IICͨ��ʵ�顪�����ߵ�Э��msp430f1491ѧϰ��+PCA6107������չ
���ߣ�������
���ڣ�2009-7-24
�������ã�PCA6107������չ
************************************************************************/
#include "msp430x14x.h"
#include "iic.h"
#include "pca6107.h"
unsigned char i,j;

void delay(unsigned int i)
{
  while(i--);
}  
int main( void )
{
  // Stop watchdog timer to prevent time out reset
    WDTCTL = WDTPW + WDTHOLD;
    DDR(0x0f);
    POUT(0xf0);
    
    while(1)
    {
        i=PIN;
    }

}
