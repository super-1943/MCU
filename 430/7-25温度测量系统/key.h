#ifndef _msp430_yujie_key
#define _msp430_yujie_key 100
#include "msp430x15x.h"
void init_port();
int KeyScan();
int KeyProcess();
void delay_key();
//定义行线输入输出方向
#define keyH1DIR P6DIR|=BIT0
#define keyH2DIR P6DIR|=BIT1
#define keyH3DIR P6DIR|=BIT2
#define keyH4DIR P6DIR|=BIT3

#define keyH1Lo P6OUT=~(BIT0)
#define keyH2Lo P6OUT=~(BIT1)
#define keyH3Lo P6OUT=~(BIT2)
#define keyH4Lo P6OUT=~(BIT3)

#define keyL1In (P5IN&BIT0)>>0
#define keyL2In (P5IN&BIT2)>>2
#define keyL3In (P5IN&BIT4)>>4
#define keyL4In (P5IN&BIT6)>>6

/*void delay();
int KeyScan();
int KeyProcess();
void init_port();*/

void delay_key()
{
  int i;
  for(i=100;i>0;i--);
}
void init_port()
{
  P6DIR=0x00;
  P6SEL=0x00;
  keyH1DIR;
  keyH2DIR;
  keyH3DIR;
  keyH4DIR;
  P6OUT=0x00;
}
int KeyScan()
{
  int nRes;
  int nop1,nop2,nop3,nop4;

  nop1=keyL1In;
  nop2=keyL2In;
  nop3=keyL3In;
  nop4=keyL4In;
  if(nop1==0||nop2==0||nop3==0||nop4==0)
  {
      delay_key();
      nop1=keyL1In;
      nop2=keyL2In;
      nop3=keyL3In;
      nop4=keyL4In;
      if(nop1==0||nop2==0||nop3==0||nop4==0)
      {
        nRes=KeyProcess();
      }
  }
  else
    return -1;
  return nRes;
}
int KeyProcess()
{
  int nRes=0;
  int nop1,nop2,nop3,nop4;
  keyH1Lo;
  nop1=keyL1In;
  if(nop1==0)
    nRes=4;
  nop2=keyL2In;
  if(nop2==0)
    nRes=8;
  nop3=keyL3In;
  if(nop3==0)
    nRes=12;
  nop4=keyL4In;
  if(nop4==0)
    nRes=16;
  
  keyH2Lo;
  nop1=keyL1In;
  if(nop1==0)
    nRes=3;
  nop2=keyL2In;
  if(nop2==0)
    nRes=7;
  nop3=keyL3In;
  if(nop3==0)
    nRes=11;
  nop4=keyL4In;
  if(nop4==0)
    nRes=15;
  
  keyH3Lo;
  nop1=keyL1In;
  if(nop1==0)
    nRes=2;
  nop2=keyL2In;
  if(nop2==0)
    nRes=6;
  nop3=keyL3In;
  if(nop3==0)
    nRes=10;
  nop4=keyL4In;
  if(nop4==0)
    nRes=14;
  
  keyH4Lo;
  nop1=keyL1In;
  if(nop1==0)
    nRes=1;
  nop2=keyL2In;
  if(nop2==0)
    nRes=5;
  nop3=keyL3In;
  if(nop3==0)
    nRes=9;
  nop4=keyL4In;
  if(nop4==0)
    nRes=13;
  
  P6OUT=0x00;
  nop1=keyL1In;
  nop2=keyL2In;
  nop3=keyL3In;
  nop4=keyL4In;
 /* while(1)
  {
    if(nop1==1&&nop2==1&&nop3==1&&nop4==1)
      break;
  }*/
  return nRes;
}

#endif