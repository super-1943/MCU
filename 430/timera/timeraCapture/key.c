#include "msp430x14x1.h"
#define KW1 0x01
#define KW2 0x02
#define KW3 0x04
#define KW4 0x08
void key(unsigned char *buffer)
{
  unsigned char t[]={0x01,0x02,0x04,0x08};
  /////////////////////////////
 
  P1DIR|=0x0f;
  P1OUT=t[0];
  P1DIR=t[0];
  if(P1IN&KW2)
  {
    *buffer=9;
  }
  if(P1IN&KW4)
  {
    *buffer=7;
  }
  if(P1IN&KW3)
  {
    *buffer=8;
  }
  P1OUT=0x00;

  P1DIR=0x0f;
  P1OUT=t[1];
  P1DIR=t[1];
  if(P1IN&KW1)
  {
    *buffer=6;
  }
  if(P1IN&KW3)
  {
    *buffer=5;
  }
  if(P1IN&KW4)
  {
    *buffer=4;
  }  
  P1OUT=0x00;
  P1DIR=0x0f;
  P1OUT=t[2];
  P1DIR=t[2];
  if(P1IN&KW1)
  {
    *buffer=3;
  }
  if(P1IN&KW2)
  {
    *buffer=2;
  }
  if(P1IN&KW4)
  {
    *buffer=1;
  }
    P1OUT=0x00;

  P1DIR=0x0f;
  P1OUT=t[3];
  P1DIR=t[3];
  if(P1IN&KW1)
  {
    *buffer=11;
  }
  if(P1IN&KW2)
  {
    *buffer=10;
  }
  if(P1IN&KW3)
  {
    *buffer=0;
  }
  P1OUT=0x00;
  P1DIR&=~0x0f;
}