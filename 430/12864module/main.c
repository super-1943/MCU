/*********************************************************************
声明：各函数以及参数的意思，见12864module.h
*********************************************************************/
#include <msp430x15x.h>
#include"12864module.h"
main()
{// Stop watchdog timer to prevent time out reset
 unsigned char i;
  WDTCTL = WDTPW + WDTHOLD;
  init_12864();
  send_cmd(0x40);
  while(1)
  {clear();
  for(i=0;i<128;i++)
  {set_point(i,(sintable[i]-1)%64,1);
  delay(100);}
  } 
}