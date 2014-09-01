#ifndef _kkk_ds18b20_h
#define _kkk_ds18b20_h
#include "msp430x15x.h"
/*
移植时需要改动
*/
#define Mask_18b20      0x20
#define DataDir_18b20   P3DIR
#define DataIN_18b20    P3IN&Mask_18b20
#define OUT_0     P3OUT&=~Mask_18b20
#define OUT_1     P3OUT|=Mask_18b20



//some data for ROM commands
#define SEARCH_ROM 0xf0
#define READ_ROM   0x33
#define MATCH_ROM  0x55
#define SKIP_ROM   0xcc
#define SEARCH_ALARM 0xec

//some data for function
#define TEMPERATURE_CONVERT 0x44
#define WRITE_SCRATCHPAD 0x4e
#define READ_SCRATCHPAD  0xbe
#define COPY_SCRATCHPAD  0x48
#define READ_SUPPLY      0xb4
#define RECALL_EEPROM    0xb8



void delay_10us(unsigned int t);
unsigned char reset_bus(void);
void init_device(void);
void write_1(void);
void write_0(void);
void write_byte(unsigned char d);
unsigned char read_bit(void);
unsigned char read_byte(void);
void start_convert(void);
unsigned int read_temperature(void);
void convert_t(int temp,char dst[]);

#endif