#include "msp430x16x.h"
#include "nrf905.h"
unsigned char i;
unsigned char txbuf[32];//���ͻ���
unsigned char rxbuf[32];//���ջ���
unsigned char txaddr[4];//���͵�ַ
RF_CONFIG a;//ȫ�ֱ��������ڹ۲����üĴ���

int main( void )
{
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;
  init_port_nrf905(&a);
  STAND_BY_MODE;
  delay_nrf905(100);
  config_nrf905(&a);
  check_config_nrf905(&a,txaddr);

  for(i=0;i<32;i++)
  {
    txbuf[i]=i;
  }
  while(1)
  {
   transmit_nrf905(txbuf);
    delay_nrf905(1000);
    listen_nrf905(rxbuf);
  }
}
