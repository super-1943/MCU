#include "msp430x14x.h"
#include "iic.h"
unsigned char i;
#define ADDR_24c01 0x6e

int main( void )
{
    // Stop watchdog timer to prevent time out reset
    WDTCTL = WDTPW + WDTHOLD;
    iic_start();
    iic_send_byte(ADDR_24c01);
    i=iic_read_ack();
    iic_send_byte(0x00);
    i=iic_read_ack();
    iic_send_byte(0x05);
    i=iic_read_ack();
        iic_send_byte(0x06);
    i=iic_read_ack();
        iic_send_byte(0x07);
    i=iic_read_ack();
        iic_send_byte(0x08);
    i=iic_read_ack();
    iic_stop();
    while(1)
    {
      iic_start();
      iic_send_byte(ADDR_24c01);
      i=iic_read_ack();
      iic_send_byte(0x00);
      i=iic_read_ack();
      iic_start();
      iic_send_byte(ADDR_24c01+1);
      i=iic_read_ack();
      i=iic_read_byte();
      iic_send_nack();
      iic_stop();
    }
}
