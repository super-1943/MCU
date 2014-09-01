#ifndef _kkk_flash_h
#define _kkk_flash_h
#include "msp430x14x.h"
#define SEG_A 0x1080
extern void flash_write_int16(unsigned int *ptr, unsigned int value);
extern void flash_clr(unsigned int *ptr);
extern void checkflash(void);
#endif