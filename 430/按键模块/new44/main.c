
#include "io430.h"

unsigned char i;
unsigned char keyscan(void)
{
/****************************************************
新4*4键盘
2009-8-17
P4.0~P4.7-------------键盘8~1
键盘5~8有上拉电阻到Vcc，注意设置对应P1.0~P1.3为输入
****************************************************/
#define KEYDIR P4DIR
#define KEYOUT	P4OUT
#define KEYIN	P4IN
	unsigned char key;
	KEYDIR=0xf0;
	KEYOUT=0xef;
	if((KEYIN&0x01)==0)
	{
	return 16;
	}
	if((KEYIN&0x02)==0)
	{
	return 15;
	}
	if((KEYIN&0x04)==0)
	{
	return 14;
	}
	if((KEYIN&0x08)==0)
	{
	return 13;
	}
	KEYOUT=0xdf;
	if((KEYIN&0x01)==0)
	{
	return 12;
	}
	if((KEYIN&0x02)==0)
	{
	return 11;
	}
	if((KEYIN&0x04)==0)
	{
	return 10;
	}
	if((KEYIN&0x08)==0)
	{
	return 9;
	}
	KEYOUT=0xbf;
	if((KEYIN&0x01)==0)
	{
	return 8;
	}
	if((KEYIN&0x02)==0)
	{
	return 7;
	}
	if((KEYIN&0x04)==0)
	{
	return 6;
	}
	if((KEYIN&0x08)==0)
	{
	return 5;
	}
	KEYOUT=0x7f;
	if((KEYIN&0x01)==0)
	{
	return 4;
	}
	if((KEYIN&0x02)==0)
	{
	return 3;
	}
	if((KEYIN&0x04)==0)
	{
	return 2;
	}
	if((KEYIN&0x08)==0)
	{
	return 1;
	}
	return 0;

}
  
int main( void )
{
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;
  
  while(1)
  {
    i=key();
  }
  return 0;
}
