#ifndef usart_module_h
#define usart_module_h
#include<msp430x15x.h>
/*
����Ϊ430 �ĵײ㺯������Ҫ����Ķ�
������ʵ�ʿ��Խ�ע�ͺ�������ȡ����
*/
void init_usart(void);
void delay_usart(void);
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
void reverse(unsigned char * d);//��ת
int char2int(unsigned char c);//�ַ�ת����
void int2char(unsigned char*d,int a);//����ת�ַ�
#endif