#ifndef _kkk_serial_h
#define _kkk_serial_h

extern void rs232_init(void);
extern unsigned char rs232_getchar(void);
extern void rs232_putchar(unsigned char txd);
extern void rs232_printstr(unsigned char *str);
extern void rs232_printhex(unsigned char b);

#endif