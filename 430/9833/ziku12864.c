#include "ziku12864.h"

/**********Һ����ʼ��***************/
void init_12864(void)
{
  DataDir_12864=0xff;
  DataOut_12864=0xff;
  P5DIR=0xFF;
  P5OUT=0xFF;
  delay_12864(100); 
  write_cmd_12864(0x30);
  write_cmd_12864(0x03);
  write_cmd_12864(0x0c);
  write_cmd_12864(0x01); 
  delay_12864(100);
  
}
/************************************************************************************
д���ֺ���
��ڲ�����
unsigned char * str;--------���������׵�ַ

unsigned char first_addr;    --------��ʾ�׵�ַ��������Ļ�ϵڼ�������λ�ô���ʼ��ʾ

unsigned char first_hanzi;    --------�ӵڼ������ֿ�ʼ��ʾ

unsigned char length;    --------ϣ����ʾ�ĺ��ָ�����һ�����ֶ�����Ӣ���ַ���
*************************************************************************************/
void write_Chinese_12864(unsigned char *str,unsigned char first_addr,unsigned char first_hanzi,unsigned char length)
{
  const unsigned char  Address[]={     
        0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,	  //��һ��
        0x90,0x91,0x92,0x93,0x94,0x95,0x96,0x97,	  //�ڶ���	����λ��
        0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,	  //������
        0x98,0x99,0x9a,0x9b,0x9c,0x9d,0x9e,0x9f,	  //������
  };
  write_cmd_12864(0x30);
  while(length--)
  {
      write_cmd_12864(Address[first_addr++]);
      write_data_12864(str[first_hanzi++]);
      write_data_12864(str[first_hanzi++]);
   }
}


void IntToStr(unsigned int t, unsigned char *str) 
{	
    *str++=(t/1000)%10+'0';                                     	
    *str++=(t/100)%10+'0';                                      	
    *str++=(t/10)%10+'0';                                       	
    *str++=(t/1)%10+'0';                                        	
    *str='\0'; 
} 

void delay_12864(unsigned int t)
{
  while(t--);
}
void write_cmd_12864(unsigned char cmd)
{
  delay_12864(100);
  IsComd_12864;
  IsWrite_12864;
  E_1_12864;
  DataOut_12864=(cmd);
  E_0_12864;
}
void write_data_12864(unsigned char d)
{
  delay_12864(100);
  IsData_12864;
  IsWrite_12864;
  E_1_12864;
  //P5OUT |= BIT7;   //rst
  DataOut_12864=(d);
  E_0_12864;
}

////////////////////

////////////////////////////
unsigned char read_stat_12864(void)
{
  unsigned char da;
  E_0_12864;
  DataDir_12864=0x00;
  DataOut_12864=0xff;
  IsComd_12864;
  IsRead_12864;
  _NOP();
  E_1_12864;
  _NOP();
  _NOP();
  _NOP();
  da=DataIn_12864;
  E_0_12864;
  DataDir_12864=0xff;
  return (da);  
}
unsigned char read_data_12864(void)
{
  unsigned char da;
  E_0_12864;
  DataDir_12864=0x00;
  DataOut_12864=0xff;
  IsData_12864;
  IsRead_12864;
  _NOP();
  E_1_12864;
  _NOP();
  _NOP();
  _NOP();
  da=DataIn_12864;
  E_0_12864;
  DataDir_12864=0xff;
  return (da); 
}  
unsigned char byte_reverse(unsigned char d)
{
    unsigned char i,t=0;
    for(i=0;i<8;i++)
    {
        t<<=1;
        if(d&0x01)
        {
            t|=0x01;
        }
        d>>=1;        
    }
    return t;
}