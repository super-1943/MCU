#ifndef _kkk_nrf905_h
#define _kkk_nrf905_h
#include <reg51.h>
#include <intrins.h>
#define _NOP() __asm NOP
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
#define CSN_0        //PORTB&=~0x01
#define CSN_1        //PORTB|= 0x01
#define MOSI_0       //PORTB&=~0x04
#define MOSI_1       //PORTB|= 0x04
#define SCK_0        //PORTB&=~0x02
#define SCK_1        //PORTB|= 0x02
#define CE_0         //PORTB&=~0x20
#define CE_1         //PORTB|= 0x20
#define TXE_0        //PORTB&=~0x10
#define TXE_1        //PORTB|= 0x10
#define PWR_0        //PORTB&=~0x40
#define PWR_1        //PORTB|= 0x40
#define AM_IN        1//(PINE&0x80)
#define DR_IN        1//(PINE&0x40)
#define CD_IN        1//(PINE&0x20)
#define MISO_IN      1//(PINB&0x08)


#define POWER_DOWN_MODE     //(PWR_0)
#define STAND_BY_MODE       //(PWR_1,CE_0)
#define RX_MODE             //(PWR_1,CE_1,TXE_0)
#define TX_MODE             //(PWR_1,CE_1,TXE_1)


//some command:
#define WRITE_CONFIG 0x00
#define READ_CONFIG  0x10
#define WRITE_TX_DATA 0x20
#define READ_TX_DATA  0x21
#define WRITE_TX_ADDR 0x22
#define READ_TX_ADDR  0x23
#define READ_RX_DATA  0x24




typedef union 
{
  struct 
  {
    unsigned int CH_NO:9;
    unsigned int HFREQ_PLL:1;
    unsigned int PA_PWR:2;
    unsigned int RX_RED_PWR:1;
    unsigned int AUTO_RETRAN:1;
    unsigned int :2;
    unsigned char RX_AW:3;
    unsigned char :1;
    unsigned char TX_AW:3;
    unsigned char :1;
    unsigned char RX_DW:6;
    unsigned char :2;
    unsigned char TX_DW:6;
    unsigned char :2;
    unsigned char RX_ADDR[4];
    unsigned char UP_CLK_FREQ:2;
    unsigned char UP_CLK_EN:1;
    unsigned char XOF:3;
    unsigned char CRC_EN:1;
    unsigned char CRC_MODE:1;
  }DETAIL;
  unsigned char buffer[10];
}RF_CONFIG;



void delay_nrf905(unsigned int i);
void init_port_nrf905(RF_CONFIG *pa);
void send_byte_nrf905(unsigned char d);
unsigned char read_byte_nrf905(void);
void config_nrf905(RF_CONFIG * pd);
void fast_config_nrf905(unsigned int ch_no,unsigned char hfreq,unsigned char pa);
unsigned char read_status_nrf905(void);
void check_config_nrf905(RF_CONFIG * pd,unsigned char *buf);
void transmit_nrf905(unsigned char *buff);
void listen_nrf905(unsigned char * rxbuf);

#endif
