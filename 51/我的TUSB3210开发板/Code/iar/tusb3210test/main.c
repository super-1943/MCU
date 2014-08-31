#include "io51.h"
#define led (P1_bit.P11)
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
	TCON_bit.TR1 = 1;			// ������ʱ��1
	IE_bit.EA=1;
}
unsigned char rs232_getchar(void)
{
	unsigned char b;
	while(!SCON_bit.RI);
	SCON_bit.RI=0;
	b=SBUF;
	return b;
}
void rs232_putchar(unsigned char txd)
{
	SBUF = txd;
	while(!SCON_bit.TI);				// �������ݴ���
	SCON_bit.TI = 0;					// ������ݴ��ͱ�־
}
void rs232_printstr(unsigned char *str)
{
	while(*str!= '\0')
	{
		SBUF =*str++;
		while(!SCON_bit.TI);				// �������ݴ���
		SCON_bit.TI = 0;					// ������ݴ��ͱ�־
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

void delay(unsigned int k)
{
	unsigned char i,j;
	for(;k;k--)
	for(i=200;i;i--)
	for(j=200;j;j--);
}

#pragma vector=4
__interrupt void serial_routine(void)
{
	if(SCON_bit.RI)
	{
		SCON_bit.RI=0;
	}
	if(SCON_bit.TI)
	{
		SCON_bit.TI=0;
	}	
}
int main( void )
{
  while(1)
  {
    led=~led;
    delay(10); 
  }
}
