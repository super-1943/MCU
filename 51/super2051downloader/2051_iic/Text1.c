#include <reg51.h>
#include "uart.h"
#include "iic.h"
sbit led=P3^7;

void delay(unsigned char t)
{
	unsigned char i,j;
	while(t--)
	{
		for(i=200;i;i--)
		for(j=200;j;j--);
	}
}

void uart_isr(void) interrupt 4
{
	if(RI)    //收到数据
	{
		RI=0;   //清中断请求
		uart_putchar(SBUF);
	}
	else      //发送完一字节数据
	{
		TI=0;
	}
}
void IIC_NUM(unsigned char i)
{
	unsigned char num[]={0xfc,0x60,0xda,0xf2,0x66,0xb6,0xbe,0xe0,0xfe,0xf6};
	iic_init();	
	iic_start();
	iic_send_byte(ADDR_pca6107);
	if(iic_read_ack())
	{
		print_str("No IIC slave found!!!");
	}
	else
	{
		print_str("OK!");
		iic_send_byte(0x01);
		iic_send_byte(num[i]);//这里是显示的数字
		iic_start();
		iic_send_byte(ADDR_pca6107);
		iic_send_byte(0x03);
		iic_send_byte(0x00);
	}
	iic_stop();
}
void main(void)
{
	led=0;
	uart_init();
	print_str("Hello world!\r\n");
	iic_init();
	while(1)
	{
		IIC_NUM(led);
		led=~led;
		delay(20);
	}
}