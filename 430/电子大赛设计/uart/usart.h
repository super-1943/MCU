#ifndef _kkk_usart_h
#define _kkk_usart_h
#include "msp430x14x.h"

/*
����Ϊ430 �ĵײ㺯������Ҫ����Ķ�
������ʵ�ʿ��Խ�ע�ͺ�������ȡ����
*/
void init_usart(void);
void delay_usart(void);
unsigned char rcv_by_usart(void);
void send_by_usart(unsigned char d);

/*
����Ϊͨ�ú��������԰�����������޸�
���Է���C++��ʽ����������ʽ��
*/
//����ַ���
void print_str(const unsigned char *d);
//���ʮ��������
void print_int(int a);
//���ʮ�������������ڵ���
void print_hex(unsigned char a);
//һЩ���ú������������ɺ�����
unsigned char strlen(unsigned char *d);
void reverse(unsigned char * d);
int char2int(unsigned char c);
void int2char(unsigned char*d,int a);
#endif