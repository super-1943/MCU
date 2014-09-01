#include "ds18b20.h"


void delay_10us(unsigned int t)
{
  unsigned char i;
  while(t--)
  {
    for(i=8;i;i--);
  }
}

unsigned char reset_bus(void)
{
  DataDir|=Mask;
  OUT_1;
  _NOP();
  _NOP();
  OUT_0;
  delay_10us(49);
  DataDir&=~Mask;
  delay_10us(6);
  while(!DataIN);
  return 0;
}
void init_device(void)
{ 
  unsigned char i;
  BCSCTL1&=~XT2OFF;
  do
  {
    IFG1&=~OFIFG;
    for(i=0xff;i;i--);
  }while((IFG1&OFIFG)!=0);
  BCSCTL2|=SELM1;//MCLK=XT2;          
  DataDir|=Mask;  
}
void write_1(void)
{
  DataDir|=Mask;
  OUT_1;
  _NOP();
  _NOP();
  OUT_0;
  _NOP();
  _NOP();
  DataDir&=~Mask;
  delay_10us(6);
}
void write_0(void)
{
  DataDir|=Mask;
  OUT_1;
  _NOP();
  _NOP();
  OUT_0;
  delay_10us(7);
  DataDir&=~Mask;
}
void write_byte(unsigned char d)
{
  unsigned char i;
  for(i=0;i<8;i++)
  {
    if(d&0x01)
    {
      write_1();
    }
    else
    {
      write_0();
    }
    d>>=1;
    _NOP();
    _NOP();
  }
}
unsigned char read_bit(void)
{
  unsigned char t;
  DataDir|=Mask;
  OUT_1;
  _NOP();
  _NOP();
  OUT_0;
  _NOP();
  _NOP();
  DataDir&=~Mask;
  delay_10us(1);
  t=DataIN;
  delay_10us(6);
  return t;
}
unsigned char read_byte(void)
{
  unsigned char t=0,i;
  for(i=0;i<8;i++)
  {
    t>>=1;
    t|=(read_bit()?0x80:0x00);
    _NOP();
    _NOP();
  }
  return t;
}
/*****************************
����18b20���ݳ���
����������9��10��11��12
��Ҫ��Ϊ����ֵ��
******************************/
void set_config(unsigned char length)
{
  length+=3;
  length<<=5;
  write_byte(WRITE_SCRATCHPAD);
  _NOP();
  write_byte(0xff);
  _NOP();
  write_byte(0xff);
  _NOP();
  write_byte(length);
  _NOP();
}
/*****************************
18b20��ʼ�¶�ת������
******************************/  
void start_convert(void)
{
  reset_bus();
  delay_10us(100);
  write_byte(SKIP_ROM);
  delay_10us(100);
  write_byte(TEMPERATURE_CONVERT);
  delay_10us(100);
}
/*****************************
��18b20��ȡ�¶Ⱥ���
����18b20���¶�ֵ
******************************/
unsigned int read_temperature(void)
{
    unsigned int temperature=0x0000;
    unsigned char low,high;
    reset_bus();
    delay_10us(100);
    write_byte(SKIP_ROM);
    delay_10us(100);
    write_byte(READ_SCRATCHPAD);
    delay_10us(100);
    low=read_byte();//0
    delay_10us(100);
    high=read_byte();//1
    delay_10us(100);
   reset_bus();
   delay_10us(100);
   temperature|=(high<<8)|low;
   return temperature;
}
/*****************************
�¶���ʾת������
temp��18b20������ԭʼ����
dst[6]������ת��������Ա���ʾ
��һ�ֽڣ����š�0+��1-
�ڶ��ֽڣ���������
�����ֽڣ�С������=data*2^(-4)
******************************/
void convert_t(int temp,char dst[])
{
  dst[0]=temp&0x8000;
  dst[1]=(temp&0x0fff)>>4;
  dst[2]=temp&0x0f;
}