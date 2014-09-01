#include "ziku12864.h"

/**********Һ����ʼ��***************/
void init_12864(void)
{
#if _kkk_p_or_s==0
  P5DIR|=0x0e;
  P5OUT&=~0x0e;
#else
  DataDir_12864=0xff;
  DataOut_12864=0xff;
  P5DIR=0xFF;
  P5OUT=0xFF;
#endif
  delay_12864(100); 
  write_cmd_12864(0x30);
  write_cmd_12864(0x03);
  write_cmd_12864(0x0c);
  write_cmd_12864(0x01); //����
  write_cmd_12864(0x06);
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
void write_chinese_12864(unsigned char *str,unsigned char first_addr,unsigned char first_hanzi,unsigned char length)
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

void delay_12864(unsigned int t)
{
  while(t--);
}

#if _kkk_p_or_s==0
void write_byte_12864(unsigned char b)
{
  unsigned char i;
  for(i=0;i<8;i++)
  {
    if(b&0x80)
    {
      SID_1_12864;
    }
    else
    {
      SID_0_12864;
    }
    _NOP();
    SCLK_0_12864;

    SCLK_1_12864;

    SCLK_0_12864;

    b<<=1;
  }
}
#endif
#if _kkk_p_or_s==0
unsigned char read_byte_12864(void)
{
  unsigned char da=0,i;
  for(i=0;i<8;i++)
  {
    da<<=1;
    SCLK_0_12864;
    _NOP();
    SCLK_1_12864;
    _NOP();
    if(SID_IN)
    {
      da|=0x01;
    }
    SCLK_0_12864;
    _NOP();
  }
  return da;
}
#endif
void write_cmd_12864(unsigned char cmd)
{

#if _kkk_p_or_s==0
  CS_1_12864;
  write_byte_12864(0xf8);
  write_byte_12864(cmd&0xf0);
  write_byte_12864(cmd<<4);
  CS_0_12864;  
#else
  wait_busy();
  IsComd_12864;
  IsWrite_12864;
  E_1_12864;
  DataOut_12864=(cmd);
  E_0_12864;
#endif
}
void write_data_12864(unsigned char d)
{
#if _kkk_p_or_s==0
  CS_1_12864;
  write_byte_12864(0xfa);
  write_byte_12864(d&0xf0);
  write_byte_12864(d<<4);
  CS_0_12864;
#else
  wait_busy();
  IsData_12864;
  IsWrite_12864;
  E_1_12864;  
  DataOut_12864=(d);
  _NOP();
  E_0_12864;
  _NOP();
#endif
}
void wait_busy(void)
{
  unsigned char i;
  i=read_stat_12864();
  while(i&0x80)
  {
    i=read_stat_12864();
    delay_12864(10);
  }
}
unsigned char read_stat_12864(void)
{
#if _kkk_p_or_s==0
  unsigned char da,i;
  delay_12864(100);
  CS_1_12864;
  write_byte_12864(0xfc);
  DataIn_12864;
  da=read_byte_12864();
  i=read_byte_12864();
  i>>=4;
  da|=i;
  CS_0_12864;
  DataOut_12864;
  return da;
#else
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
#endif
}
unsigned char read_data_12864(void)
{
#if _kkk_p_or_s==0
  unsigned char da,i;
  delay_12864(100);
  CS_1_12864;
  write_byte_12864(0xfe);
  DataIn_12864;
  da=read_byte_12864();
  i=read_byte_12864();
  i>>=4;
  da|=i;
  CS_0_12864;
  DataOut_12864;
  return da;
#else
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
#endif
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
void graph_clear(void)
{
  unsigned char i,j;
  init_12864();
  for(j=0;j<32;j++)
  {
    write_cmd_12864(0x34);
    delay_12864(10);
    write_cmd_12864(0x02);
    delay_12864(10);
    write_cmd_12864(0x80+j);
    delay_12864(10);
    write_cmd_12864(0x80);
    delay_12864(10);
    for(i=0;i<32;i++)
    {
      write_data_12864(0x00);
    }   
    delay_12864(10);
    write_cmd_12864(0x36);
    delay_12864(10);
  }

}

void graph(char * table)
{
  unsigned char i,j;
  for(j=0;j<32;j++)
  {
    write_cmd_12864(0x34);
    delay_12864(10);
    write_cmd_12864(0x02);
    delay_12864(10);
    write_cmd_12864(0x80+j);
    delay_12864(10);
    write_cmd_12864(0x80);
    delay_12864(10);
    for(i=0;i<8;i++)
    {
      write_data_12864(table[16*j+i*2]);
      delay_12864(100);
      write_data_12864(table[16*j+i*2+1]);
      delay_12864(100);
    }
    for(i=0;i<8;i++)
    {
      write_data_12864(table[512+16*j+i*2]);
      delay_12864(100);
      write_data_12864(table[512+16*j+i*2+1]);
      delay_12864(100);
    }
    write_cmd_12864(0x36);
    delay_12864(10);
  }
}
void graph_off(void)
{
  write_cmd_12864(0x30);
}
void clear(void)
{
  write_cmd_12864(0x30);
  write_cmd_12864(0x01);
}
void write_int_12864(int myint,unsigned char pos)
{
  unsigned char t=0,flag=0;
  if(myint<0)
  {
    flag=1;
    myint=-myint;
  }
  unsigned char buffer[8]={' ',' ',' ',' ',' ',' ',' ',' '};
  while(myint/10)
  {
    buffer[7-t]=myint%10+'0';
    myint/=10;
    t++;
  }
  buffer[7-t]=myint+'0';
  if(flag)
  {
    buffer[6-t]='-';
  }
  write_chinese_12864(buffer,pos,0,4);
}
/*******************************************************************************************************
��ʾ���ֺ���
unsigned char * hanzi:��������
unsigned char length:���ָ�����һ������ռ�����ֽ�λ��)
unsigned char hang:�ڵڼ�����ʾ
unsigned char align:���뷽ʽ��0������룬1���Ҷ��룬2���м����)
*******************************************************************************************************/
void write_hanzi_12864(unsigned char *hanzi,unsigned char length,unsigned char hang,unsigned char align)
{
  
}

void write_cgram(unsigned char * table)
{
  unsigned char i;
  init_12864();
  clear();
  write_cmd_12864(0x40);
  for(i=0;i<128;i++)
  {
    write_data_12864(table[i]);
    delay_12864(10);
  }
  write_cmd_12864(0x80);
  write_data_12864(0x00);
  write_data_12864(0x00);
  write_data_12864(0x00);
  write_data_12864(0x02);
  write_data_12864(0x00);
  write_data_12864(0x04);
  write_data_12864(0x00);
  write_data_12864(0x06);
}