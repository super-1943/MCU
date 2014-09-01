
#include<msp430x15x.h>
#include"usart_module.h"
int main( void )
{
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;
  init_usart();
  print_str("Hello");
  while(1);
}
#pragma vector=USART0RX_VECTOR
__interrupt void usart0_rx (void)
{
    TXBUF0=RXBUF0;    //将接收到的值返回
  
}
