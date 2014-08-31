#ifndef _kkk_uart_h
#define _kkk_uart_h
#define Fclk      11059200UL		 /*ʹ��11.0592M����*/
#define BitRate   9600UL		     /*�����ʶ���Ϊ9600*/
#define uint8 unsigned char
#define uint16 unsigned int
void uart_init(void)
{
	EA=0;
	TMOD&=0x0F;
	TMOD|=0x20;    //timer1:mode 2
	SCON=0x50;     //serial:mode 1
	TCON=0x05;
	TH1=256-Fclk/(BitRate*12*16);
	TL1=256-Fclk/(BitRate*12*16); 
	PCON=0x80;    //baudrate double
	ES=1;         //�����ж�����
	TR1=1;        //������ʱ��1
	REN=1;        //������� 
	EA=1;         //�����ж�
}
void uart_putchar(uint8 d)
{
	ES=0;
	SBUF=d;
	while(!TI);
	TI=0;
	ES=1;
}
void print_str(uint8 * pd)
{
	while((*pd)!='\0')
	{
		uart_putchar(*pd);
		pd++;
	}
}
#endif