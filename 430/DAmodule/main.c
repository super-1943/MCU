
#include <msp430x15x.h>
#include"DAmodule.h"
 unsigned char i=0;
void delay(unsigned int ms)
{unsigned int i,j;
for(i=0;i<ms;i++)
 for(j=0;j<150;j++);
}
const unsigned int sintable[]=
{    1600   , 1700 ,   1750 ,   1750 ,   1800 ,   2000   , 2050   , 2150   , 2200   , 2300 ,   2350  ,  2400  ,  2500,
    2550  ,  2600  ,  2650   , 2750 ,   2850  ,  2850   , 2900  ,  2950  ,  2950   , 3000,    3050  ,  3100,    3100,
    3150 ,   3150  ,  3150  ,  3200  ,  3200  ,  3200   , 3200   , 3200   , 3200  , 3200  ,  3200  ,  3200  ,  3200,
    3100  ,  3100 ,  3050   , 3000   , 2950  ,  2950 ,   2900 ,   2850 ,   2800  ,  2800   , 2650   , 2600 ,   2550,
    2500  ,  2400  ,  2350   , 2300  ,  2200  ,  2150 ,   2050 ,   2000   , 1900   , 1850 ,   1750   , 1700 ,   1600,
    1500 ,   1450 ,   1350 ,   1300,    1200  ,  1150    ,1050 ,  1000 ,   900  ,  850  ,  800  ,  700 ,   650,
    600  ,  550 ,    450   , 400  ,   350 ,    300    , 250   , 250   ,   200 ,    150   ,  100 ,    100 ,    50,
     50   ,  50  ,   50  ,  50    , 50   ,  50     ,50 ,   50 ,   50,     50 ,    50  ,   50 ,    50,
     100   ,  150 ,  200  ,  250   ,  250   , 300  ,   350    , 400   ,  450   , 550   , 600  ,  650 ,700   ,
    800  ,  850 ,  900  ,  1000,   1050 ,   1150   , 1200  ,  1300  ,  1350  , 1450   , 1500   , 1600
};
int main( void )
{
  // Stop watchdog timer to prevent time out reset
  
WDTCTL = WDTPW + WDTHOLD;
BCSCTL1&=~XT2OFF;
  do
  {
    IFG1&=~OFIFG;
    for(i=0xff;i;i--);
  }while((IFG1&OFIFG)!=0);
  BCSCTL2|=SELM1+SELS;//MCLK=SMCLK=XT2;   
  init_DA();
  CCTL0 = CCIE;                             // CCR0 interrupt enabled
  CCR0 = 500;
  TACTL = TASSEL_2 + MC_1;                  // SMCLK, contmode
 // _EINT();
  while(1)
  {DAC12_0DAT=(sintable[i++]);   
  if(i==129)
    i=0;
  }
}
#pragma vector=TIMERA0_VECTOR
__interrupt void Timer_A (void)
{ for(i=0;i<129;i++) ;
}