
#include "msp430x15x.h"
#include"7219module.h"
#include"44Tmodule.h"
int main( void )
{
 
  //Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;
     uchar l;
       while(1)
	 {
	   if(key_press_44T())
	   {
	      l=key_scan_44T();
             
		initial_7219();//必须初始化7219，否则不显示
                send_7219(1,l%10);
                send_7219(2,l/10); 
                send_7219(3,l%10);
                send_7219(4,l/10);
                send_7219(5,l%10);
                send_7219(6,l/10);
                send_7219(7,l%10);
                send_7219(8,l/10);
  
	   }
	 }
          
  return 0;
}
