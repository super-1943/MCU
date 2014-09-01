
#include "msp430x14x.h"
void step_motor(void);
void dc_motor(unsigned char t);


void delay(unsigned int y)
{
  unsigned int i;
  while(y--)
  for(i=50;i;i--);
}
int main( void )
{
  // Stop watchdog timer to prevent time out reset

  while(1)
  {
    step_motor();
  }
}
void step_motor(void)
{
  unsigned char table[]={0x01,0x03,0x02,0x00};
  unsigned char i;
  P2DIR=0xff;
  P2OUT=0x00;
  while(1)
  {
      P2OUT=table[i];
      delay(5);
      i=(i+1)%4;
  }
}
void dc_motor(unsigned char t)
{
  P2DIR=0xff;
  P2OUT=0x01;
  P2OUT|=0x78;
  delay(100-t);
  P2OUT&=~0x78;
  delay(t);
}