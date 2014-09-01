#include "ziku12864.h"

/**********液晶初始化***************/
void init_12864(void)
{
#if _kkk_p_or_s==0
  P3DIR|=0xe0;
  P3OUT&=~0xe0;
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
  write_cmd_12864(0x01); 
  write_cmd_12864(0x06);
  delay_12864(100);  
}
/************************************************************************************
写汉字函数
入口参数：
unsigned char * str;--------汉字数组首地址

unsigned char first_addr;    --------显示首地址，即在屏幕上第几个汉字位置处开始显示

unsigned char first_hanzi;    --------从第几个汉字开始显示

unsigned char length;    --------希望显示的汉字个数（一个汉字顶两个英文字符）
*************************************************************************************/
void write_Chinese_12864(const unsigned char *str,unsigned char first_addr,unsigned char first_hanzi,unsigned char length)
{
  const unsigned char  Address[]={     
        0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,	  //第一行
        0x90,0x91,0x92,0x93,0x94,0x95,0x96,0x97,	  //第二行	汉字位置
        0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,	  //第三行
        0x98,0x99,0x9a,0x9b,0x9c,0x9d,0x9e,0x9f,	  //第四行
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
    *str++=(t/10000)%10+'0';
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
    SCLK_0_12864;
    _NOP();
    SCLK_1_12864;
    _NOP();
    SCLK_0_12864;
    _NOP();
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
  delay_12864(100);
#if _kkk_p_or_s==0
  CS_1_12864;
  write_byte_12864(0xf8);
  write_byte_12864(cmd&0xf0);
  write_byte_12864(cmd<<4);
  CS_0_12864;  
#else
  delay_12864(100);
  IsComd_12864;
  IsWrite_12864;
  E_1_12864;
  DataOut_12864=(cmd);
  E_0_12864;
#endif
}
void write_data_12864(unsigned char d)
{
  delay_12864(100);
#if _kkk_p_or_s==0
  CS_1_12864;
  write_byte_12864(0xfa);
  write_byte_12864(d&0xf0);
  write_byte_12864(d<<4);
  CS_0_12864;
#else
  delay_12864(100);
  IsData_12864;
  IsWrite_12864;
  E_1_12864;
  DataOut_12864=(d);
  E_0_12864;
#endif
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