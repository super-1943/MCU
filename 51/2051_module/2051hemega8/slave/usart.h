#ifndef _usart_h_kkk
#define _usart_h_kkk 1
#define BEGIN 0X55
#define END 0xaa
#define ACK 0x0f
#include <avr/io.h>
//usart��ʼ���������������ò����ʣ����㹫ʽ��������=fosc/(16*(ubrr+1));
//ubrr==25ʱ��baud=2400
void USART_Init( unsigned int baud ) 
{
	UBRRH = (unsigned char)(baud>>8);
	UBRRL = (unsigned char)baud;
	UCSRB = (1<<RXEN)|(1<<TXEN);
	UCSRC = (1<<URSEL)|(3<<UCSZ0);
}
void USART_Transmit( unsigned char data )
{
	while ( !( UCSRA & (1<<UDRE)) );
	UDR = data;
}
 unsigned char USART_Receive(void) 
{
	while ( !(UCSRA & (1<<RXC)) ); 
    return UDR; 
}


//���ַ�������
unsigned char strlen(unsigned char *d)
{
	unsigned char i=0;
	while(d[i++]);
	return --i;
}
//���ַ�������
void reverse(unsigned char * d)
{
	unsigned char i,j,k;
	i=strlen(d);
	for(j=0;j<i/2;j++)
	{
		k=d[j];
		d[j]=d[i-j-1];
		d[i-j-1]=k;
	}
}
//��char���int
int char2int(unsigned char c)
{
	if(c>='0' && c<='9')
	{
		return (int)(c-'0');
	}
	else
	{
		return -1;
	}
}
//��int���char
void int2char(unsigned char*d,int a)
{
	unsigned char *dd,t;
	dd=d;
	while(a)
	{
		t=a%10;
		*d++='0'+t;
		a/=10;
	}
	*d=0;
	reverse(dd);
}
//�ַ����������
void print_str(const unsigned char *d)
{
	while(*d)
	{
		USART_Transmit(*d);
		d++;
	}
}
//�����������
void print_int(int a)
{
	unsigned char buff[10];
	int2char(buff,a);
	print_str(buff);
}
//��16���Ƹ�ʽ�������
void print_hex(unsigned char a)
{
	unsigned char t[17]="0123456789ABCDEF";
//	print_str("0x");
	USART_Transmit(t[a/16]);
	USART_Transmit(t[a%16]);
}
void scanf_str(unsigned char * buff,unsigned char endcode)
{
	while((*buff=USART_Receive())!=endcode)
	{
		buff++;
	}
	*buff='\0';
}
int strcmp(unsigned char *s1,unsigned char *s2)
{
	while(*s1==*s2 && *s1 && *s2)
	{
		s1++;
		s2++;
	}
	return *s1-*s2;
}
	
#endif