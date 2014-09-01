#include "usart.h"
#include "led.h"
#include "ziku12864.h"
unsigned char flag=0,i;
const unsigned char hanzi[256]={"大家注意了，协会一直没有比较好的示波器，现在协会有一定资金，准备买台60M 数字示波器，价格1750元，保修三年，不知大家都有什么意见没？"};
unsigned char buffer[64]={0};
void delay_ms(unsigned int i)
{
    while(i--)
    {
        unsigned int t;
        for(t=1000;t;t--);
    }
}
void delay_s(unsigned int i)
{
    while(i--)
    {
        delay_ms(1000);
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
    init_12864();
    delay_s(1);
    write_Chinese_12864(hanzi,0,0,32);
    delay_s(10);
    write_Chinese_12864(hanzi,0,16,32);
        delay_s(10);
    write_Chinese_12864(hanzi,0,32,32);
        delay_s(10);
    write_Chinese_12864(hanzi,0,48,32);
    while(1)
    {
        _EINT();
        delay_12864(60000);
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
    if(U0RXBUF=='@')
    {
      write_Chinese_12864(buffer,0,0,32);
    }
    if(U0RXBUF=='!')
    {
      for(i=0;i<64;i++)
      {
        buffer[i]=' ';
      }
      write_Chinese_12864(buffer,0,0,32);
    }
    else
    {
        return;
    }
}
