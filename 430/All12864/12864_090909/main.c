#include <msp430x15x.h>
#include"ziku12864.h"
#include "dianzhen.h"
#include "system.h"

int av1=0;
int i=0;
unsigned char daikuan=0;
unsigned char buffer[6];
///////////////////
unsigned char test;
//////////////////
void test12864(void)
{
  test=read_stat_12864();
  test=read_data_12864();
  test=read_stat_12864();
  test=read_data_12864();
}

void show_int(int myint,unsigned char x_pos,unsigned char y_pos);
void start(void);
void zuozhe(void);
void current_stat(void);
void delay_ms(unsigned int ms);
void menu(void);



int main( void )
{
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;
  P3DIR=0xff;
  P3OUT=0xff;

  init_12864();
  start();
  graph_off();
  write_cmd_12864(0x01);
  menu();
  current_stat();
  while(1)
  {
    i=key();
    switch(i)
    {
    case 1:
      av1++;
      if(av1>40)
      {
        av1=40;
      }
      current_stat();
      break;
    case 2:
      av1--;
      if(av1<0)
      {
        av1=0;
      }
      current_stat();
      break;
    case 3:
      av1+=5;
      if(av1>40)
      {
        av1=40;
      }
      current_stat();
      break;
    case 4:
      av1-=5;
      if(av1<(0))
      {
        av1=(0);
      }
      current_stat();
      break;
    case 5:
      daikuan^=0x01;
      current_stat();
      break;
    case 6:
      daikuan=0;
      av1=0;
      current_stat();
      break;
    case 15:
      WDTCTL = WDT_MRST_32; 
      while(1);
      break;
    case 16:
      menu();
      current_stat();
      break;
    case 8:
      zuozhe();
      clear();
      break;
    default:
      break;
    }    
    delay_ms(10);
  }

}

void start(void)
{
//  unsigned char offset=0;
  init_12864();
  clear();
  graph_clear();

  graph((void*)(nectable+1520));
  delay_ms(300);
    graph_off();
    write_cmd_12864(0x01);
    write_chinese_12864("  温馨提示      ",0,0,8);
    delay_ms(50);
    write_chinese_12864("按1 进入数控模式",8,0,8);
    while(key()!=1)
    {
    }
}

void menu(void)
{
loop:
    graph_off();
    write_cmd_12864(0x01);
    write_chinese_12864("  温馨提示      ",0,0,8);
    delay_ms(50);
    write_chinese_12864("键1   增益加1   ",8,0,8);
    delay_ms(50);
    write_chinese_12864("键2   增益减1   ",16,0,8);
    delay_ms(50);
    write_chinese_12864("键3   增益加5   ",24,0,8);

    delay_ms(100);
    write_chinese_12864("                ",8,0,8);
    write_chinese_12864("                ",16,0,8);
    write_chinese_12864("                ",24,0,8);
    delay_ms(50);
    write_chinese_12864("键4   增益减5   ",8,0,8);
    delay_ms(50);
    write_chinese_12864("键5   带宽切换  ",16,0,8);
    delay_ms(50);
    write_chinese_12864("键6   回初始值  ",24,0,8);
    delay_ms(100);
    write_chinese_12864("                ",8,0,8);
    write_chinese_12864("                ",16,0,8);
    write_chinese_12864("                ",24,0,8);
    delay_ms(50);
    write_chinese_12864("键7   进入      ",8,0,8);  
    delay_ms(50);
    write_chinese_12864("键8   返回首页  ",16,0,8);  
    delay_ms(50);
    write_chinese_12864("  燕山大学作品  ",24,0,8); 

    while(key()!=7)
    {
      if(key()==8)
      {
        goto loop;
      }
    }
    write_cmd_12864(0x01);
}

void zuozhe(void)
{
  write_cmd_12864(0x01);
  graph_clear();
  graph((void*)(nectable+2544));
  delay_ms(500);  
}




void delay_ms(unsigned int ms)
{
  while(ms--)
  {
    delay_12864(1000);
  }
}

void current_stat(void)
{
    unsigned char tmp;
    write_chinese_12864("现在增益为：",0,0,6);
    write_int_12864(av1,9);
    write_chinese_12864("dB",13,0,1);
    write_chinese_12864("现在带宽为：",16,0,6);
    if(daikuan==1)
    {
      write_chinese_12864("10M ",28,0,2);
    }
    else
    {
      write_chinese_12864(" 5M ",28,0,2);
    }
    for(tmp=0;tmp<254;tmp++)
    {
      if(dashuzu[tmp-1]<=av1 && dashuzu[tmp+1]>=av1)
        {
          P3OUT=tmp;
          break;
        }
    }
}

