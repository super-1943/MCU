#include "msp430x15x.h"
void write_sega(char data1,char data2,char data3,char data4)
{
  char * Flash_ptr;
  unsigned int i;
  Flash_ptr=(char *)(0x1080);
  FCTL1=FWKEY+ERASE;
  FCTL3=FWKEY;
  *Flash_ptr=0;
  FCTL1=FWKEY+WRT;
  *Flash_ptr++=data1;
  *Flash_ptr++=data2;
  *Flash_ptr++=data3;
  *Flash_ptr++=data4;
  FCTL1=FWKEY;
  FCTL3=FWKEY+LOCK;
}