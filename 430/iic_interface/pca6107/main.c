/************************************************************************
IIC通信实验——无线电协会msp430f1491学习板+PCA6107并口扩展
作者：赵永科
日期：2009-7-24
函数作用：PCA6107并口扩展
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
