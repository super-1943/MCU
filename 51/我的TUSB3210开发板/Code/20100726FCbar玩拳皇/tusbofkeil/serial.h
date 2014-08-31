#ifndef _kkk_serial_h
#define _kkk_serial_h
void rs232_init(void);
unsigned char rs232_getchar(void);
void rs232_putchar(unsigned char txd);
void rs232_printstr(unsigned char *str);
void rs232_printhex(unsigned char b);


#endif