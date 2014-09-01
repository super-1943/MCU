/******************************************************************
DS12887程序

作者：赵永科
日期：2009-7-22

*****************************************************************/

#include "msp430x14x.h"
#define uchar unsigned char 
#define uint unsigned int 
struct timer
{
  uchar hour;
  uchar minute;
  uchar second;
  uchar year;
  uchar month;
  uchar date;
  uchar week;
}mytimer;
uchar rega,regb,regc,regd;


/**********************************
硬件连线：

AD0~AD7:====P2.0~P2.7

CS:=========P6.5
AS:=========P6.6
RW:=========P6.7
DS:=========P1.7
*********************************/
#define DataOut P2OUT
#define DataIn  P2IN
#define CS_0 P6OUT&=~0x20
#define CS_1 P6OUT|=0x20
#define AS_0 P6OUT&=~0x40
#define AS_1 P6OUT|=0x40
#define RW_0 P6OUT&=~0x80
#define RW_1 P6OUT|=0x80
#define DS_0 P1OUT&=~0x80
#define DS_1 P1OUT|=0x80

//register
#define SECONDS 0x00
#define SECONDS_ALARM 0x01
#define MINUTES 0x02
#define MINUTES_ALARM 0x03
#define HOURS   0x04
#define HOURS_ALARM  0x05
#define WEEKS 0x06
#define DATE 0x07
#define MONTH 0x08
#define YEAR  0x09
#define RegA  0x0a
#define RegB  0x0b
#define RegC  0x0c
#define RegD  0x0d
//some data for Register A
#define OSC_ON 0x20
#define OSC_OFF 0x00
#define WAVE_NONE 0x00
#define WAVE_1_256Hz 0x01
#define WAVE_1_128Hz 0x02
#define WAVE_8192Hz  0x03
#define WAVE_4096Hz  0x04
#define WAVE_2048Hz  0x05
#define WAVE_1024Hz  0x06
#define WAVE_512Hz   0x07
#define WAVE_256Hz   0x08
#define WAVE_128Hz   0x09
#define WAVE_64Hz    0x0a
#define WAVE_32Hz    0x0b
#define WAVE_16Hz    0x0c
#define WAVE_8Hz     0x0d
#define WAVE_4Hz     0x0e
#define WAVE_2Hz     0x0f
//some data for Register B
#define SET  0x80
#define PIE  0x40
#define AIE  0x20
#define UIE  0x10
#define SQWE 0x08
#define BinaryMode 0x04
#define _24HourMode 0x02
#define DSE  0x01

void init_timer(void)
{
  P2DIR=0xff;
  P2OUT=0x00;
  P6DIR|=0xe0;
  P1DIR|=0x80;
  AS_0;
  RW_1;
  DS_1;
  CS_0;
  _NOP();
}
unsigned char  read_timer(unsigned char addr)
{
  unsigned char itsdata;
  init_timer();
  P2OUT=addr;
  _NOP();
  AS_1;
  _NOP();
  AS_0;
  P2DIR=0x00;
  P2OUT=0xff;
  DS_0;
  _NOP();
  DS_1;
  itsdata=P2IN;
  AS_1;
  P2DIR=0xff;
  return itsdata;
}
void write_timer(unsigned char addr,unsigned char dat)
{
  init_timer();
  P2OUT=addr;
  _NOP();
  AS_1;
  _NOP();
  AS_0;
  _NOP();
  P2OUT=dat;
  RW_0;
  _NOP();
  RW_1;
  AS_1;
}
  
  
int main( void )
{
  // Stop watchdog timer to prevent time out reset

  WDTCTL = WDTPW + WDTHOLD;
  write_timer(RegA,OSC_ON|WAVE_2Hz);
  write_timer(RegB,PIE|SQWE);
//  write_timer(SECONDS,0x00);
//  write_timer(MINUTES,0x52);
//  write_timer(HOURS,0x10);
//  write_timer(WEEKS,0x04);
//  write_timer(DATE,0x22);
//  write_timer(MONTH,0x07);
//  write_timer(YEAR,0x09);
  while(1)
  {
    mytimer.second=read_timer(0);
    mytimer.minute=read_timer(2);
    mytimer.hour=read_timer(4);
    mytimer.week=read_timer(6);
    mytimer.date=read_timer(7);
    mytimer.month=read_timer(8);
    mytimer.year=read_timer(9);
    rega=read_timer(10);
    regb=read_timer(11);
    regc=read_timer(12);
    regd=read_timer(13);
    _NOP();
  }
}
