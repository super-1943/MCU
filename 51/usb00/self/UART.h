#ifndef __UART_C__
#define __UART_C__

#include "my_type.H"

void init_uart(void);
void uart_putchar(uint8);
void print_str(uint8 *);
void print_longint(uint32);
void print_16hex(uint16 x);
void print_32hex(uint32);
void print_hex(uint8 x);

#endif
