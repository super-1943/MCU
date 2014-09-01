#include "msp430x15x.h"
#include "ad9833.h"
#include "key.h"

unsigned char itswave=1,itsvol=1;
unsigned int itsfreq=100;

void key_action(void);
int main( void )
{
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;
  init_ad9833();
  while(1)
  {
    key_action();
  }
}

void key_action(void)
{
  unsigned char i;
  i=init_key();
  delay_ad9833(50000);
  switch(i)
  {
  case 0:
    break;
  case 1://选择方波
    itswave=0;
    autoset(itswave,itsfreq);
    break;
  case 2://选择正弦波
    itswave=1;
    autoset(itswave,itsfreq);
    break;
  case 3://选择三角波
    itswave=2;
    autoset(itswave,itsfreq);
    break;
  case 4://频率加（50hz）
    itsfreq+=50;
    if(itsfreq>=20000)
    {
      itsfreq=20000;
    }
    autoset(itswave,itsfreq);
    break;
  case 5://频率减（50hz）
    itsfreq-=50;
    if(itsfreq<=50)
    {
      itsfreq=50;
    }
    autoset(itswave,itsfreq);
    break;
  case 6://恢复初始值
    itswave=1,itsfreq=100;
    autoset(itswave,itsfreq);
    itsvol=1;
    break;
  case 7:
    itsvol+=1;
    if(itsvol>=50)
    {
      itsvol=50;
    }
    break;
  case 8:
    itsvol-=1;
    if(itsvol<=1)
    {
      itsvol=1;
    }
    break;
  case 9:
    itsfreq+=100;
    if(itsfreq>=20000)
    {
      itsfreq=20000;
    }
    autoset(itswave,itsfreq);
    break;
  case 10://频率减（50hz）
    itsfreq-=100;
    if(itsfreq<=100)
    {
      itsfreq=100;
    }
    autoset(itswave,itsfreq);
    break;
  case 11:    
  case 12:    
  case 13:
  case 14:
  case 15:
  case 16:
  default:
    break;
  }
}