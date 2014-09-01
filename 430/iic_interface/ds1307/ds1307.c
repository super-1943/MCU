#include "msp430x14x.h"
#include "iic.h"
#include "ds1307.h"

void get_time(struct Timer * pt)
{
  unsigned char i;
  iic_start();
  iic_send_byte(0xd0);
  i=iic_read_ack();
  _NOP();
  iic_send_byte(0x00);
  _NOP();
  i=iic_read_ack();
  iic_stop();
  _NOP();
  _NOP();
  iic_start();
  iic_send_byte(0xd1);
  i=iic_read_ack();
  _NOP();
  pt->second=iic_read_byte();//second
  _NOP();
  iic_send_ack();
  _NOP();
  pt->minute=iic_read_byte();//minute
  _NOP();
  iic_send_ack();
  _NOP();
  pt->hour=iic_read_byte();//hour
  _NOP();
  iic_send_ack();
  _NOP();
  pt->week=iic_read_byte();//week
  _NOP();
  iic_send_ack();
  _NOP();
  pt->date=iic_read_byte();//date
  _NOP();
  iic_send_ack();
  _NOP();
  pt->month=iic_read_byte();//month
  _NOP();
  iic_send_ack();
  _NOP();
  pt->year=iic_read_byte();//year
  _NOP();
  iic_send_ack();
  _NOP();
  i=iic_read_byte();//control
  _NOP();
  iic_send_nack();
  iic_stop();
  
}
void set_time(struct Timer * pt)
{
  unsigned char i;
  iic_start();
  iic_send_byte(0xd0);
  i=iic_read_ack();
  _NOP();
  iic_send_byte(0x00);
  _NOP();
  i=iic_read_ack();
  iic_send_byte(pt->second);
  _NOP();
  i=iic_read_ack();
  iic_send_byte(pt->minute);
  _NOP();
  i=iic_read_ack();
  iic_send_byte(pt->hour);
  _NOP();
  i=iic_read_ack();
  iic_send_byte(pt->week);
  _NOP();
  i=iic_read_ack();
  iic_send_byte(pt->date);
  _NOP();
  i=iic_read_ack();
  iic_send_byte(pt->month);
  _NOP();
  i=iic_read_ack();
  iic_send_byte(pt->year);
  _NOP();
  i=iic_read_ack();
  iic_stop();  
}