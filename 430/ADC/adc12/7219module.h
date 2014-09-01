#ifndef _7219_module_h
#define _7219_module_h
#include "msp430x15x.h"
#define uchar unsigned char
#define uint unsigned int
#define DIN_1_7219    P4OUT|=0x20 
#define DIN_0_7219    P4OUT&=~0x20      
#define LOAD_1_7219   P4OUT|=0x08
#define LOAD_0_7219   P4OUT&=~0x08  
#define CLK_1_7219    P4OUT|=0x02  
#define CLK_0_7219    P4OUT&=~0x02
#define Stop  0x0c    //ͣ������λ�� 0ͣ����1����            0000 1100
#define Code  0x09     //������ƣ�0�����룬1 bcd8421��      0000 1001
#define Light 0x0a     //���ȵ���00~0f  16��                 0000 1010
#define  Bit  0x0b     //ɨ��λ��                            0000 1011
#define  Test 0x0f     //��ʾ����0�����ԣ�1����
void delay_7219(uint ms)
{uint i,j;
for(i=0;i<ms;i++)
for(j=0;j<500;j++);
}
void send_bit_7219(uchar i)
{
    
    uchar j=0;
    for(j=0;j<8;j++)
   {
      if(i&((0x80)>>j))//�������λ
           DIN_1_7219;
     else
        DIN_0_7219;
        CLK_0_7219;
        _NOP();
        CLK_1_7219;
    }
}     
void send_7219(uchar add,uchar dat)//��������
{  LOAD_0_7219;
  _NOP();
   send_bit_7219(add);
   send_bit_7219(dat);
   LOAD_1_7219;
}
void initial_7219()
{      P4DIR|=0x2a;
        P4OUT&=~0x2a;
	send_7219(Stop,1);
	delay_7219(10);
	send_7219(Light,0x0f);
	delay_7219(10);
	send_7219(Bit,0x07);
	delay_7219(10);
        send_7219(Test,0);
	delay_7219(10);
        send_7219(Code,0Xff);
        
}
void show_7219(unsigned int moni)
{
  unsigned char t1,t2,t3;
  send_7219(5,15);
  send_7219(6,15);
  send_7219(7,15);
  send_7219(8,15);
  t1=moni/1000;
  moni%=1000;
  send_7219(4,t1);
  t2=moni/100;
  moni%=100;
  send_7219(3,t2);
  t3=moni/10;
  moni%=10;
  send_7219(2,t3);
  send_7219(1,moni);
}
  
#endif