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
  DataDir_18b20|=Mask_18b20;
  OUT_1;
  _NOP();
  _NOP();
  OUT_0;
  delay_10us(49);
  DataDir_18b20&=~Mask_18b20;
  delay_10us(6);
  while(!DataIN_18b20);
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
  DataDir_18b20|=Mask_18b20;  
}
void write_1(void)
{
  DataDir_18b20|=Mask_18b20;
  OUT_1;
  _NOP();
  _NOP();
  OUT_0;
  _NOP();
  _NOP();
  DataDir_18b20&=~Mask_18b20;
  delay_10us(6);
}
void write_0(void)
{
  DataDir_18b20|=Mask_18b20;
  OUT_1;
  _NOP();
  _NOP();
  OUT_0;
  delay_10us(7);
  DataDir_18b20&=~Mask_18b20;
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
  DataDir_18b20|=Mask_18b20;
  OUT_1;
  _NOP();
  _NOP();
  OUT_0;
  _NOP();
  _NOP();
  DataDir_18b20&=~Mask_18b20;
  delay_10us(1);
  t=DataIN_18b20;
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
设置18b20数据长度
参数可以是9，10，11，12
不要设为其它值！
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
18b20开始温度转换函数
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
从18b20读取温度函数
返回18b20的温度值
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
温度显示转换函数
temp：18b20传来的原始数据
dst[6]数组存放转换结果，以便显示
第一字节：符号。0+，1-
第二字节：整数部分
第三字节：小数部分=data*2^(-4)
******************************/
void convert_t(int temp,char dst[])
{
  dst[0]=temp&0x8000;
  dst[1]=(temp&0x0fff)>>4;
  dst[2]=temp&0x0f;
}