#ifndef DAC902_2009
#define DAC902_2009

#define CLK_DIR P1DIR
#define CLK_OUT P1OUT
#define CLK BIT0
#define CLK_0 P1OUT&=~(0x01)
#define CLK_1 P1OUT|=0x01
#define DAT_LSB_DIR P5DIR
#define DAT_LSB_OUT P5OUT
#define DAT_MSB_DIR P6DIR
#define DAT_MSB_OUT P6OUT

void delay(unsigned int i);
void init_device(void);
void write_data(unsigned char lsb,unsigned char msb);

#endif