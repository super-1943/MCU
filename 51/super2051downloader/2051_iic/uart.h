#ifndef _kkk_uart_h
#define _kkk_uart_h
#define Fclk      11059200UL		 /*使用11.0592M晶体*/
#define BitRate   9600UL		     /*波特率定义为9600*/
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
	ES=1;         //串行中断允许
	TR1=1;        //启动定时器1
	REN=1;        //允许接收 
	EA=1;         //允许中断
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