
#include "msp430x14x1.h"
const unsigned char table[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};
unsigned char buffer[6]={0};
unsigned int count=0;
void send164(unsigned char a)
{
   unsigned char i;
   for(i=0;i<8;i++)
   {
     if(a&0x80)
     {
       P5OUT|=0x80;
     }
     else
     {
       P5OUT&=~0x80;
     }
     P5OUT&=~0x40;
     P5OUT|=0x40;
     a<<=1;
   }
}
void delay(unsigned int a)
{
  while(a--);
}
void show(unsigned char *d)
{
  unsigned char i;
  for(i=0;i<6;i++)
  {
    send164(~(1<<i));
    send164(table[d[5-i]]);
    delay(450);
  }
}
#define KW1 0x01
#define KW2 0x02
#define KW3 0x04
#define KW4 0x08
void key(void)
{
  unsigned char t[]={0x01,0x02,0x04,0x08};
  /////////////////////////////
 
  P1DIR=0x0f;
  P1OUT=t[0];
  P1DIR=t[0];
  if(P1IN&KW2)
  {
    buffer[0]=9;
  }
  if(P1IN&KW4)
  {
    buffer[0]=7;
  }
  if(P1IN&KW3)
  {
    buffer[0]=8;
  }
  P1OUT=0x00;

  P1DIR=0x0f;
  P1OUT=t[1];
  P1DIR=t[1];
  if(P1IN&KW1)
  {
    buffer[0]=6;
  }
  if(P1IN&KW3)
  {
    buffer[0]=5;
  }
  if(P1IN&KW4)
  {
    buffer[0]=4;
  }  
  P1OUT=0x00;
  P1DIR=0x0f;
  P1OUT=t[2];
  P1DIR=t[2];
  if(P1IN&KW1)
  {
    buffer[0]=3;
  }
  if(P1IN&KW2)
  {
    buffer[0]=2;
  }
  if(P1IN&KW4)
  {
    buffer[0]=1;
  }
    P1OUT=0x00;

  P1DIR=0x0f;
  P1OUT=t[3];
  P1DIR=t[3];
  if(P1IN&KW1)
  {
    buffer[0]=11;
  }
  if(P1IN&KW2)
  {
    buffer[0]=10;
  }
  if(P1IN&KW3)
  {
    buffer[0]=0;
  }
    P1OUT=0x00;
  P1DIR=0x00;
  P1DIR=0x00;

}
int main( void )
{
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTHOLD|WDTPW;
  TACTL=TASSEL1+TACLR;
  CCR0=0;
  CCTL0=CCIE;
  TACTL|=MC1;
  _EINT();
  P5DIR=0xff;
  while(1)
  {
    show(buffer);
  }
}


#pragma vector=TIMERA0_VECTOR
__interrupt void timer_a(void)
{
  CCR0=0;
  count++;
  if(count==14)
  {
    count=0;
    buffer[0]=(buffer[0]+1)%16;
  }
  
}

