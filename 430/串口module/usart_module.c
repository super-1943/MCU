/***********************************声明*********************
以下为430 的底层函数，不要随意改动
但根据实际可以将注释后的语句提取出来
void init_usart(void);
void delay_usart(void);
以下为通用函数，可以按照需求进行修改
可以仿照C++格式（数据流格式）
//输出字符串
void print_str(const unsigned char *d);
//输出十进制整数
void print_int(int a);
//输出十六进制数，便于调试
void print_hex(unsigned char a);
//一些常用函数，可以做成函数库
unsigned char strlen(unsigned char *d);
void reverse(unsigned char * d);//翻转
int char2int(unsigned char c); //字符转整形
void int2char(unsigned char*d,int a);//整形转字符
************************************************/
#include"usart_module.h"
void delay_usart(void)
{
    unsigned int i;
    for(i=400;i;i--);
}
void init_usart(void)
{ unsigned char i;
  WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT
  BCSCTL1 &= ~XT2OFF;                       // XT2on
  do
  {
  IFG1 &= ~OFIFG;                           // Clear OSCFault flag
  for (i = 0xFF; i > 0; i--);               // Time for flag to set
  }while ((IFG1 & OFIFG));                   // OSCFault flag still set?
  P3SEL |= 0x30;                            // P3.4,5 = USART0 TXD/RXD
  BCSCTL2 |= SELS;                 // MCLK = SMCLK = XT2 (safe)
  ME1 |= UTXE0 + URXE0;                     // Enable USART0 TXD/RXD
  UCTL0 |= CHAR;                            // 8-bit character
  UTCTL0 |= SSEL1;                          // UCLK = SMCLK
  UBR00 = 0x41;                             // 8MHz 9600
  UBR10 = 0x03;                             // 8MHz 9600
  UMCTL0 = 0x4A;                            // 8MHz 9600 modulation
  UCTL0 &= ~SWRST;                          // Initialize USART state machine(默认为1，在1的情况下设置串口，
                                            //                                  然后设置SWRST=0；
  IE1 |= URXIE0;                            // Enable USART0 RX interrupt
   _EINT();                                 //全局中断
}
void send_usart(unsigned char d)
{
       _DINT();                             //禁止中断
       TXBUF0=d;
       while((IFG1&UTXIFG0)==0);
       IFG1&=~UTXIFG0;                    //可以省略，因为对UTXBUF进行写操作可以复位UTXIFGX
       _EINT();
}
unsigned char rcv_usart(void)
{
    _DINT();
    while(!IFG1&URXIFG0);
    return RXBUF0;
}
//求字符串长度                           //可以考虑sizeof 
unsigned char strlen_usart(unsigned char *d)
{
	unsigned char i=0;
	while(d[i++]);
	return   --i;                  //因为在判断字符串结尾的\0时i加了一
}
//将字符串倒置
void reverse(unsigned char * d)
{
	unsigned char i,j,k;
	i=strlen_usart(d);
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
        if(!strlen_usart(buff))
         send_usart('0');
	else print_str(buff);
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