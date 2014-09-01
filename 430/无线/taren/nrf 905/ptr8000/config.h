#include <iom16v.h>
#include <macros.h>

#define SET(a,b) a|=(1<<b) 
#define CLR(a,b) a&=~(1<<b)
#define CPL(a,b) a^=(1<<b)
#define CHK(a,b) (a&(1<<b))

#define SBUF UDR
#define uint unsigned int
#define uchar char
#define bit char

//PORTA
#define PWR2   0
#define CE     1
#define CS	   2
#define DR2    3
#define CLK	   4	   
#define DATA   5

//PORTB
#define PWR	   0
#define TRXCE  1
#define TX_EN   2
#define CSN	   4
#define MOSI   5
#define MISO   6
#define SCK	   7

//PORTD 
#define CD     2
#define AM	   3
#define DR	   4
#define LED	   7

