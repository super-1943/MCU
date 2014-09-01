
#include "msp430x16x.h"



unsigned char i;
/********************************************

Ó²¼þÃèÊö£º
P1-----------AD0~AD7
P2.0---------EOC
P2.1---------ALE and START
P2.2---------OE
P2.3---------C addr
P2.5---------B addr
P2.7---------A addr

********************************************/
#define DATA_IN P1IN
#define ISOK (P2IN&0x01)
#define START_0    (P2OUT&=~0x02)
#define START_1    (P2OUT|= 0x02)
#define OE_0       (P2OUT&=~0x04)
#define OE_1       (P2OUT|= 0x04)
void delay(unsigned int i)
{
  while(i--);
}
void init_port_adc0809(void)
{
  P1DIR=0x00;
  P1SEL=0x00;
  P1OUT=0xff;
  P2DIR|=0xae;
  P2SEL=0x00;
  P2OUT=0x80;
}
void start_adc0809(void)
{
  init_port_adc0809();
  START_0;
  _NOP();
  START_1;
  _NOP();
  START_0;
  delay(10);
}
unsigned char read_adc0809(void)
{
  unsigned char j;
  while(!ISOK);
  delay(10);
  OE_1;
  delay(10);
  j=DATA_IN;
  OE_0;  
  return j;
}
int main( void )
{
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;
  init_port_adc0809();
  while(1)
  {
    start_adc0809();  
    i=read_adc0809();
  }
}
