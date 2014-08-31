#include "reg52.h"
/*****************************************************************
���㲨����ע�⣬Fclk=48MHz
��ʱ��1���÷�ʽ��
���пڲ��÷�ʽһ,�����ʱ���λSMOD��1
�����ʳ�ֵ���㹫ʽ��Baud=Fclk/(12*16*��256-x��)��xΪ��ʱ��1��ֵ
*****************************************************************/
void rs232_init(void)
{
	TMOD&=0x0f;
	TMOD|=0x20;			// ��ʱ��1������8λ�Զ�����ģʽ, ���ڲ���������
	TH1 = 243;			// ������19200
	TL1 = 243;
	PCON|=0x80;			// �����ʱ���
	SCON = 0x50;		// �趨���пڹ�����ʽ1,REN=1
	TR1 = 1;			// ������ʱ��1
	ES=1;
	EA=1;
}
unsigned char rs232_getchar(void)
{
	unsigned char b;
	while(!RI);
	RI=0;
	b=SBUF;
	return b;
}
void rs232_putchar(unsigned char txd)
{
	SBUF = txd;
	while(!TI);				// �������ݴ���
	TI = 0;					// ������ݴ��ͱ�־
}
void rs232_printstr(unsigned char *str)
{
	while(*str!= '\0')
	{
		SBUF =*str++;
		while(!TI);				// �������ݴ���
		TI = 0;					// ������ݴ��ͱ�־
	}
}
void rs232_printhex(unsigned char b)
{
	unsigned char hexvalue;
#if 1
	rs232_printstr("0x");
#endif
	hexvalue=(b&0xf0)>>4;
	if(hexvalue<10)
	{
		rs232_putchar(hexvalue+'0');
	}
	else
	{
		rs232_putchar(hexvalue+55);
	}
	hexvalue=(b&0x0f);
	if(hexvalue<10)
	{
		rs232_putchar(hexvalue+'0');
	}
	else
	{
		rs232_putchar(hexvalue+55);
	}
#if 1
	rs232_printstr(" ");
#endif
}