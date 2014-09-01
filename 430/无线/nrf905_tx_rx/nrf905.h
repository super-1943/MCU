#ifndef _kkk_nrf905_h
#define _kkk_nrf905_h
#include "msp430x16x.h"

/***********************************************************
Ó²¼þÃèÊö£º
CSN--------P1.7         o
SCK--------P1.0         o
MISO-------P1.1         i
MOSI-------P1.2         o
AM---------P1.3         i
DR---------P1.4         i
CD---------P1.5         i
CE---------P1.6         o
TXE--------P2.0         o
PWR--------P2.1         o
***********************************************************/
#define CSN_0        P1OUT&=~0x80
#define CSN_1        P1OUT|= 0x80
#define MOSI_0       P1OUT&=~0x04
#define MOSI_1       P1OUT|= 0x04
#define SCK_0        P1OUT&=~0x01
#define SCK_1        P1OUT|= 0x01
#define CE_0         P1OUT&=~0x40
#define CE_1         P1OUT|= 0x40
#define TXE_0        P2OUT&=~0x01
#define TXE_1        P2OUT|= 0x01
#define PWR_0        P2OUT&=~0x02
#define PWR_1        P2OUT|= 0x02
#define AM_IN        (P1IN&0x08)
#define DR_IN        (P1IN&0x10)
#define CD_IN        (P1IN&0x20)
#define MISO_IN      (P1IN&0x02)


#define POWER_DOWN_MODE     (PWR_0)
#define STAND_BY_MODE       (PWR_1,CE_0)
#define RX_MODE             (PWR_1,CE_1,TXE_0)
#define TX_MODE             (PWR_1,CE_1,TXE_1)


//some command:
#define WRITE_CONFIG 0x00
#define READ_CONFIG  0x10
#define WRITE_TX_DATA 0x20
#define READ_TX_DATA  0x21
#define WRITE_TX_ADDR 0x22
#define READ_TX_ADDR  0x23
#define READ_RX_DATA  0x24










void delay_nrf905(unsigned int i);
void init_port_nrf905(void);
void send_byte_nrf905(unsigned char d);
unsigned char read_byte_nrf905(void);
void config_nrf905(void);
void fast_config_nrf905(unsigned int ch_no,unsigned char hfreq,unsigned char pa);
unsigned char read_status_nrf905(void);
#endif