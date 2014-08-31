/******************************************************************
   本程序只供学习使用，未经作者许可，不得用于其它任何用途
      我的邮箱：computer-lov@tom.com
        欢迎访问我的blog：  http://computer00.21ic.org

UART.H  file

作者：Computer-lov
建立日期: 2007.03.20
修改日期: 2007.03.22
版本：V1.1
版权所有，盗版必究。
Copyright(C) Computer-lov 2007-2017
All rights reserved            
*******************************************************************/

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
