#define uchar unsigned char	//ͷ�ļ� �ڳ�������uchar����unsigned char
#define uint unsigned int
#include<reg51.h>  //Դ�ļ� Դ�ļ������˱����Լ�������ʵ��
#include<absacc.h>
#include <stdio.h> 
sbit E=P1^2; //Һ����ʹ���ź�
sbit CS1=P1^3; //Һ��������ѡͨ�ź�
sbit CS2=P1^4; //Һ��������ѡͨ�ź�
sbit DI=P1^0;
uchar code chinese[ ]={   //��������
0x00,0x20,0x3F,0xF0,0x02,0x00,0x02,0x00,0x02,0x00,0x02,0x08,0x7F,0xFC,0x02,0x80,  //��
0x02,0x80,0x04,0x80,0x04,0x80,0x08,0x80,0x08,0x82,0x10,0x82,0x20,0x7E,0x40,0x00,
0x08,0x40,0x08,0x50,0x10,0x48,0x10,0x40,0x22,0x7C,0x7F,0xC0,0x08,0x44,0x10,0x7E,  //��
0x23,0xC0,0x7C,0x48,0x00,0x50,0x00,0x20,0x1C,0x60,0xE0,0x92,0x43,0x0A,0x00,0x06,
0x02,0x00,0x02,0x00,0x02,0x10,0x7F,0xF8,0x42,0x10,0x42,0x10,0x7F,0xF0,0x42,0x10,   //��
0x42,0x10,0x7F,0xF0,0x42,0x10,0x02,0x00,0x02,0x04,0x02,0x04,0x01,0xFC,0x00,0x00,
};
uchar code start[ ]={0,1,2};
void send_command_l(uchar d) //���������ź�//
{uchar data i;
DI=0; CS1=1; CS2=0;
P0=d; E=1;
for(i=5;i!=0;i--); E=0;
for(i=5;i!=0;i--); E=1; }
void send_data_l(uchar d) //���������ź�//
{uchar data i;
DI=1; CS1=1; CS2=0;
for(i=10;i!=0;i--); P0=d;
for(i=10;i!=0;i--); E=1;
for(i=10;i!=0;i--); E=0;
for(i=5; i!=0;i--); E=1; }
void send_command_r(uchar d) //���������ź�//
{uchar data i;
DI=0; CS1=0; CS2=1;P0=d; E=1;
for(i=5;i!=0;i--); E=0;
for(i=5;i!=0;i--); E=1; }
void send_data_r(uchar d)  //���������ź�//
{uchar data i;
DI=1; CS1=0; CS2=1;P0=d; E=1;
for(i=5;i!=0;i--); E=0; 
for(i=5;i!=0;i--); E=1; }
void display_output_word(uchar x,uchar y,uchar *p1,uchar lth,bit sign)
{uchar *p2;  //ָ���ֿ���ĳ���ֵĵ�ַ
uchar idata i,j,k;  //�ּ�¼�������趨��һ���ֵ���ʼ��,���ڻ��С�
k=0;
for(j=0;j<lth;j++)
{if(*p1==255)  //�س�����
{x=x+2;  //�ƶ�����һ��
k=0;}  //�ּ�¼��ʼ��
else  //�޻س�����
{p2=&chinese;  //ȡ�ֿ��׵�ַ;������word.h������chinese
 p2=p2+(*p1*32);  //�ƶ�����Ӧ������Ӧ�ĵ�ַ
    if((y+k*16)>63)  //�Ұ���
	 {send_command_r(x+184);
	  send_command_r(y+k*16);
	  	for(i=0;i<16;i++)  //��ʾ�ϰ���
		{if(sign==1)
		 {send_data_r(*p2); p2++;}
		 else
		 { send_data_r(*p2^0xff);  //��ɫ��ʾ
		  p2++; }}
	  send_command_r(x+184+1);
	  send_command_r(y+k*16);
		for(i=0;i<16;i++)  //��ʾ�°���
		{if(sign==1)
		 {send_data_r(*p2); p2++; }
	     else
		 {send_data_r(*p2^0xff); p2++; } }
        k++; }  //�ּ�¼��һ
	else  //�����
	  {send_command_l(x+184);
	   send_command_l(y+64+k*16);
		 for(i=0;i<16;i++)  //��ʾ�ϰ���
		 {if(sign==1)
		  {send_data_l(*p2);  p2++; }
		  else
		  {send_data_l(*p2^0xff); 	p2++; }}
	   send_command_l(x+184+1);
	   send_command_l(y+64+k*16);
		 for(i=0;i<16;i++)  //��ʾ�°���
		 {if(sign==1)
		  {send_data_l(*p2); p2++; }
		  else
		  {send_data_l(*p2^0xff); p2++; }}
		k++; } }    //�ּ�¼��һ
	p1++; } }   //����ָ���������һ����
void main(void)
{ display_output_word(0,0,start,14,1);  //������ʾ����
while(1){;} 
}