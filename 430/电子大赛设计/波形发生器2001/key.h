#ifndef _key_kkk_h
#define _key_kkk_h
unsigned char init_key(void)
{
  P4DIR|=0xaa;
  P4OUT=0xfd;
  if((P4IN&0x01)==0)
    return 13;
  if((P4IN&0x04)==0)
    return 9;
  if((P4IN&0x10)==0)
    return 5;
  if((P4IN&0x40)==0)
    return 1;
  P4OUT=0xf7;
  if((P4IN&0x01)==0)
    return 14;
  if((P4IN&0x04)==0)
    return 10;
  if((P4IN&0x10)==0)
    return 6;
  if((P4IN&0x40)==0)
    return 2; 
  P4OUT=0xdf;
  if((P4IN&0x01)==0)
    return 15;
  if((P4IN&0x04)==0)
    return 11;
  if((P4IN&0x10)==0)
    return 7;
  if((P4IN&0x40)==0)
    return 3;
  P4OUT=0x7f;
  if((P4IN&0x01)==0)
    return 16;
  if((P4IN&0x04)==0)
    return 12;
  if((P4IN&0x10)==0)
    return 8;
  if((P4IN&0x40)==0)
    return 4;
  return 0;
}

#endif