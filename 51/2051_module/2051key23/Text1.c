#include <reg51.h>
sbit hang1=P1^7;
sbit hang2=P1^6;
sbit lie1=P1^5;
sbit lie2=P1^4;
sbit lie3=P1^3;

/**/
void send_str(unsigned char *str);
void scankey(void);
void initserial(void);
void serialint(void);
void delay(void)
{
	unsigned char i,j;
	for(i=200;i;i--)
	for(j=10;j;j--);
}
void main(void)
{
	initserial();
	send_str("Hello world\r\n");
	while(1)
	{
		scankey();
		delay();
	}
}
void scankey(void)
{
	unsigned char key;
	hang1=hang2=1;
	lie1=lie2=lie3=1;
	hang1=0;
	key=P1&0x38;
	key>>=3;
	switch(key)
	{
		case 0x6:
			send_str("round\r\n");
			break;
		case 0x5:
			send_str("down\r\n");
			break;
		case 0x3:
			send_str("right\r\n");
			break;			
	}
	hang1=1;
	hang2=0;
	key=P1&0x38;
	key>>=3;
	switch(key)
	{
		case 0x6:
			send_str("fang\r\n");
			break;
		case 0x5:
			send_str("up\r\n");
			break;
		case 0x3:
			send_str("left\r\n");
			break;			
	}		
	
}
	
void initserial(void)
{
	TMOD = 0x20;			// ��ʱ��1������8λ�Զ�����ģʽ, ���ڲ���������
	TH1 = 0xFD;				// ������9600
	TL1 = 0xFD;
	SCON = 0x50;			// �趨���пڹ�����ʽ
	PCON &= 0xef;			// �����ʲ�����
	TR1 = 1;				// ������ʱ��1
	IE = 0x0;				// ��ֹ�κ��ж�
	EA=1;
	ES=1;
}
void serialint(void)interrupt 4 using 2
{
	if(RI)
	{
		RI=0;
		SBUF=SBUF;
	}
}

void send_str(unsigned char *str)// �����ִ�
{
	unsigned char i = 0;
	ES=0;
	while(str[i] != '\0')
	{
		SBUF = str[i];
		while(!TI);				// �������ݴ���
		TI = 0;					// ������ݴ��ͱ�־
		i++;					// ��һ���ַ�
	}
	ES=1;
}