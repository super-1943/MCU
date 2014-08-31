/******************************************************************
   ������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
      �ҵ����䣺computer-lov@tom.com
        ��ӭ�����ҵ�blog��  http://computer00.21ic.org

UART.H  file

���ߣ�Computer-lov
��������: 2007.03.20
�޸�����: 2007.03.22
�汾��V1.1
��Ȩ���У�����ؾ���
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
