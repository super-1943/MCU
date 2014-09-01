/***********************************����*********************
����Ϊ430 �ĵײ㺯������Ҫ����Ķ�
������ʵ�ʿ��Խ�ע�ͺ�������ȡ����
void init_usart(void);
void delay_usart(void);
����Ϊͨ�ú��������԰�����������޸�
���Է���C++��ʽ����������ʽ��
//����ַ���
void print_str(const unsigned char *d);
//���ʮ��������
void print_int(int a);
//���ʮ�������������ڵ���
void print_hex(unsigned char a);
//һЩ���ú������������ɺ�����
unsigned char strlen(unsigned char *d);
void reverse(unsigned char * d);//��ת
int char2int(unsigned char c); //�ַ�ת����
void int2char(unsigned char*d,int a);//����ת�ַ�
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
  UCTL0 &= ~SWRST;                          // Initialize USART state machine(Ĭ��Ϊ1����1����������ô��ڣ�
                                            //                                  Ȼ������SWRST=0��
  IE1 |= URXIE0;                            // Enable USART0 RX interrupt
   _EINT();                                 //ȫ���ж�
}
void send_usart(unsigned char d)
{
       _DINT();                             //��ֹ�ж�
       TXBUF0=d;
       while((IFG1&UTXIFG0)==0);
       IFG1&=~UTXIFG0;                    //����ʡ�ԣ���Ϊ��UTXBUF����д�������Ը�λUTXIFGX
       _EINT();
}
unsigned char rcv_usart(void)
{
    _DINT();
    while(!IFG1&URXIFG0);
    return RXBUF0;
}
//���ַ�������                           //���Կ���sizeof 
unsigned char strlen_usart(unsigned char *d)
{
	unsigned char i=0;
	while(d[i++]);
	return   --i;                  //��Ϊ���ж��ַ�����β��\0ʱi����һ
}
//���ַ�������
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
	while(*d!='\0')
	{
		send_usart(*d);
		d++;
                delay_usart();
	}
}
//�����������
void print_int(int a)
{
	unsigned char buff[10];
	int2char(buff,a);
        if(!strlen_usart(buff))
         send_usart('0');
	else print_str(buff);
}
//��16���Ƹ�ʽ�������
void print_hex(unsigned char a)
{
	unsigned char t[17]="0123456789abcdef";
//	print_str("0x");
	send_usart(t[a/16]);
        delay_usart();
	send_usart(t[a%16]);
        delay_usart();
}