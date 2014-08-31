#include <reg51.h>

#include "nrf905.h"
/********************
/OE---PG4
DIR---PE4

CSN--------PB0         o
SCK--------PB1         o
MOSI-------PB2         o
MISO-------PB3         i
TXE--------PB4         o
CE---------PB5         o
PWR--------PB6         o
AM---------PE7         i
DR---------PE6         i
CD---------PE5         i
********************/
unsigned char i,j;
unsigned char txbuf[32];//发送缓存
unsigned char rxbuf[32];//接收缓存
unsigned char txaddr[4];//发送地址
unsigned char rxaddr[4];//接收地址
unsigned char state;//当前状态：0空闲；1接收；2发射
RF_CONFIG a;//全局变量，便于观察配置寄存器
void main(void)
{

	init_port_nrf905(&a);
	STAND_BY_MODE;
	delay_nrf905(100);
	config_nrf905(&a);
	check_config_nrf905(&a,txaddr);
	while(1)
	{
		transmit_nrf905(txbuf);
		delay_nrf905(1000);
		listen_nrf905(rxbuf);
	}
}