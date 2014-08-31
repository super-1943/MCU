/*
*         ��Ƭ����������������,Ȼ�����ݴ��͵�P0��, �����ظ�����;             *
*         ������K1=P3.2 ʱ, ��Ƭ��������www.hificat.com" ������       *                                                   *
*                                                                              *
*/   

#include <reg51.h>
#include <intrins.h>

unsigned char key_s, key_v, tmp;

char code str[] = "www.hificat.com";


void send_str();
bit	scan_key();
void proc_key();
void delayms(unsigned char ms);
void send_char(unsigned char txd);

sbit	K1 = P3^2;

main()
{
	TMOD = 0x20;			// ��ʱ��1������8λ�Զ�����ģʽ, ���ڲ���������
	TH1 = 0xFD;				// ������9600
	TL1 = 0xFD;
	
	SCON = 0x50;			// �趨���пڹ�����ʽ
	PCON &= 0xef;			// �����ʲ�����
		
	TR1 = 1;				// ������ʱ��1
	IE = 0x0;				// ��ֹ�κ��ж�
	send_str();
	while(1)
	{
		if(RI)						// �Ƿ������ݵ���
		{
			RI = 0;
			tmp = SBUF;				// �ݴ���յ�������
			P0 = tmp;				// ���ݴ��͵�P0��
			send_char(tmp);			// �ش����յ�������
		}		
	}
}

bit scan_key()	
// ɨ�谴��
{
	key_s = 0x00;
	key_s |= K1;
	return(key_s ^ key_v);	
}

void proc_key()
// ������
{
	if((key_v & 0x01) == 0)
	{			// K1����
		send_str();				// �����ִ�"welcome!...
	}
}

void send_char(unsigned char txd)
// ����һ���ַ�
{
	SBUF = txd;
	while(!TI);				// �������ݴ���
	TI = 0;					// ������ݴ��ͱ�־
}

void send_str()
// �����ִ�
{
	unsigned char i = 0;
	while(str[i] != '\0')
	{
		SBUF = str[i];
		while(!TI);				// �������ݴ���
		TI = 0;					// ������ݴ��ͱ�־
		i++;					// ��һ���ַ�
	}	
}

void delayms(unsigned char ms)	
// ��ʱ�ӳ���
{						
	unsigned char i;
	while(ms--)
	{
		for(i = 0; i < 120; i++);
	}
}