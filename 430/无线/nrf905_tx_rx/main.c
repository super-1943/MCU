
#include "msp430x16x.h"
#include "nrf905.h"
unsigned char i;
unsigned char txbuf[32];
unsigned char rxbuf[32];
void check_config_nrf905(void)
{

  CSN_0;
  send_byte_nrf905(READ_CONFIG);
  i=read_byte_nrf905();//0
  i=read_byte_nrf905();//1
  i=read_byte_nrf905();//2
  i=read_byte_nrf905();//3
  i=read_byte_nrf905();//4
  i=read_byte_nrf905();//5
  i=read_byte_nrf905();//6
  i=read_byte_nrf905();//7
  i=read_byte_nrf905();//8
  i=read_byte_nrf905();//9
  CSN_1;  
  CSN_0;
  send_byte_nrf905(READ_TX_ADDR);
  i=read_byte_nrf905();//6
  i=read_byte_nrf905();//7
  i=read_byte_nrf905();//8
  i=read_byte_nrf905();//9
  CSN_1; 
  i=i;
}
void transmit_nrf905(void)
{
  STAND_BY_MODE;
  CSN_0;
  send_byte_nrf905(WRITE_TX_DATA);
  for(i=0;i<32;i++)
  {
    send_byte_nrf905(txbuf[i]);
  }
  CSN_1;
  delay_nrf905(100);
  TX_MODE;  
}
void listen_nrf905(void)
{
  unsigned char ii;
  RX_MODE;  
  delay_nrf905(1000);
  while(CD_IN==0)i=read_status_nrf905();
  while(AM_IN==0)i=read_status_nrf905();
  while(DR_IN==0)i=read_status_nrf905();
  STAND_BY_MODE;
  _NOP();
  CSN_0;
  send_byte_nrf905(READ_RX_DATA);
  for(ii=0;ii<32;ii++)
  {
    rxbuf[ii]=read_byte_nrf905();
  }
  CSN_1;						// Disable spi
  while(DR_IN||AM_IN)i=read_status_nrf905();	
}
int main( void )
{
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;
  init_port_nrf905();
  STAND_BY_MODE;
  delay_nrf905(100);
  config_nrf905();
  check_config_nrf905();

  for(i=0;i<32;i++)
  {
    txbuf[i]=i;
  }
  while(1)
  {
    transmit_nrf905();
    delay_nrf905(1000);
    listen_nrf905();
  }
}
