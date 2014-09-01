#include "usart.h"
#include "led.h"
unsigned char flag=0,i;
unsigned char buffer[6]={0};
void delay_ms(unsigned int i)
{
    while(i--)
    {
        unsigned int t;
        for(t=1000;t;t--);
    }
}
void read_buffer(void)
{
    unsigned char i;
    print_str("buffer :\t");
    for(i=0;i<6;i++)
    {
        print_hex(buffer[i]);
        print_str("\t");
    }
    print_str("\r\n");
}
int main( void )
{
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;
    init_usart();
    init_led();
    while(1)
    {
        _EINT();
        show(buffer);
    }

}
#pragma vector=USART0RX_VECTOR
__interrupt void usart0_rx(void)
{
    if(U0RXBUF=='#')
    {
        while((IFG1&URXIFG0)==0);
        i=U0RXBUF;
        while((IFG1&URXIFG0)==0);
        buffer[i]=U0RXBUF;
    }
    else
    {
        return;
    }
}
