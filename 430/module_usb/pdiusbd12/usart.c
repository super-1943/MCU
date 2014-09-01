#include "usart.h"
void delay_usart(void)
{
    unsigned int i;
    for(i=400;i;i--);
}
void init_usart(void)
{
    unsigned char i;  
    BCSCTL1&=~XT2OFF;
    do
    {
        IFG1&=~OFIFG;
        for(i=0xff;i;i--);
    }while((IFG1&OFIFG)!=0);
    BCSCTL2|=SELM1+SELS;//MCLK=SMCLK=XT2;  
    ME1|=UTXE0+URXE0;
//    ME2|=UTXE1+URXE1;
    
    P3SEL|=0x30;//+0xc0;//别忘了这里要设为第二功能！
    U0CTL|=SWRST;
    U0CTL|=CHAR;
    U0TCTL=SSEL1;
    U0BR1=3;
    U0BR0=65;
    U0MCTL=0x24;
    
//    U1CTL|=SWRST;
//    U1CTL|=CHAR;
//    U1TCTL=SSEL1;
//    U1BR1=3;
//    U1BR0=65;
//    U1MCTL=0x24;
    
    U0CTL&=~SWRST;
//    U1CTL&=~SWRST;
    IE1|=URXIE0;
    _EINT();
}
void send_usart(unsigned char d)
{
       _DINT();
       U0TXBUF=d;
       while((IFG1&UTXIFG0)==0);
       IFG1&=~UTXIFG0;
       _EINT();
//       U1TXBUF=d;
//       while(!IFG2&UTXIFG1);
//       IFG2&=~UTXIFG1;
} 

unsigned char rcv_usart(void)
{
    _DINT();
    while(!IFG1&URXIFG0);
    return U0RXBUF;
//    while(!IFG2&UTXIFG1);
//    return U1RXBUF;
}







//求字符串长度
unsigned char strlen(unsigned char *d)
{
	unsigned char i=0;
	while(d[i++]);
	return --i;
}
//将字符串倒置
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
//将char变成int
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
//将int变成char
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
//字符串输出函数
void print_str(const unsigned char *d)
{
	while(*d!='\0')
	{
		send_usart(*d);
		d++;
                delay_usart();
	}
}
//整数输出函数
void print_int(int a)
{
	unsigned char buff[10];
	int2char(buff,a);
	print_str(buff);
}
//以16进制格式输出整数
void print_hex(unsigned char a)
{
	unsigned char t[17]="0123456789abcdef";
//	print_str("0x");
	send_usart(t[a/16]);
        delay_usart();
	send_usart(t[a%16]);
        delay_usart();
}