#include "msp430x15x.h"
#include "ad9833.h"
#include "key.h"
#include "ds1867_100module.h"
#include "ziku12864.h"



unsigned char itswave=1,itsvol=10;
unsigned int itsfreq=100;
unsigned char buffer[10]={0};

void write_sega(char data1,char data2,char data3,char data4);

void change_vol(unsigned char vol);
void key_action(void);
void save();
void load();
void exit();
void thanks();
void menu();
void delay_s(unsigned char i);
int main( void )
{
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;
  init_12864();
  write_Chinese_12864("你好！123456",0,0,6);
//  menu();
  init_1867_100();
  change_vol(itsvol);
  init_ad9833();
  while(1)
  {
    key_action();
//    menu();
    delay_s(1);
  }
}

void key_action(void)
{
  unsigned char i;
  i=init_key();
  delay_ad9833(50000);
  switch(i)
  {
  case 0:
    break;
  case 1://选择方波
    itswave=0;
    change_vol(itsvol);
    autoset(itswave,itsfreq);
    break;
  case 2://选择正弦波
    itswave=1;
    change_vol(itsvol);
    autoset(itswave,itsfreq);
    break;
  case 3://选择三角波
    itswave=2;
    change_vol(itsvol);
    autoset(itswave,itsfreq);
    break;
  case 4://恢复初始值
    itswave=1,itsfreq=100,itsvol=10;
    change_vol(itsvol);
    autoset(itswave,itsfreq);
    break;
  case 5://频率加（50hz）
    itsfreq+=50;
    if(itsfreq>=20000)
    {
      itsfreq=20000;
    }
    autoset(itswave,itsfreq);
    break;
  case 6://频率减（50hz）
    itsfreq-=50;
    if(itsfreq<=50)
    {
      itsfreq=50;
    }
    autoset(itswave,itsfreq);
    break;
  case 7://频率加（100hz）
    itsfreq+=100;
    if(itsfreq>=20000)
    {
      itsfreq=20000;
    }
    autoset(itswave,itsfreq);
    break;
  case 8://频率减（100hz）
    itsfreq-=100;
    if(itsfreq<=100)
    {
      itsfreq=100;
    }
    autoset(itswave,itsfreq);
    break;
    
  case 9://幅度加（0.1V）
    itsvol+=1;
    if(itsvol>=50)
    {
      itsvol=50;      
    }
    change_vol(itsvol);
    break;
  case 10://幅度减（0.1V)
    itsvol-=1;
    if(itsvol<=1)
    {
      itsvol=1;
    }
    change_vol(itsvol);
    break;
  case 11://幅度加（1V）
    itsvol+=10;
    if(itsvol>=50)
    {
      itsvol=50;      
    }
    change_vol(itsvol);
    break;   
  case 12://幅度减（1V)
    itsvol-=10;
    if(itsvol<=10)
    {
      itsvol=10;
    }
    change_vol(itsvol);
    break;  
  case 13:
    save();
    break;
  case 14:
    load();
    break;
  case 15:
    exit();
    break;
  case 16://频率加（1000hz）
    autoset_test(itswave,itsfreq/10);
//    break;
//    thanks();
    break;
  default:
    break;
  }
}


void delay_s(unsigned char i)
{
  while(i--)
  {
    delay_12864(60000);
  }
}
void menu(void)
{
  write_Chinese_12864("    欢迎使用！",0,0,7);
  write_Chinese_12864("现在波形：",8,0,5);
  if(itswave==0)
  {
    write_Chinese_12864("方波  ",13,0,3);
  }
  if(itswave==1)
  {
    write_Chinese_12864("正弦波",13,0,3);
  }
  if(itswave==2)
  {
    write_Chinese_12864("三角波",13,0,3);
  }
  write_Chinese_12864("频率：(Hz)",16,0,5);
  IntToStr(itsfreq,buffer);
  write_Chinese_12864(buffer,21,0,3);
  write_Chinese_12864("幅度：(V)",24,0,5);
  buffer[0]=itsvol/100+'0';
  buffer[1]=(itsvol/10)%10+'0';
  buffer[2]='.';
  buffer[3]=itsvol%10+'0';
  buffer[4]=0;
  write_Chinese_12864(buffer,29,0,2);  
}
void change_vol(unsigned char vol)
{
  if(itswave)//不是方波时
  {
    send_1867(1,100,2*vol);
  }
  else
  {
    send_1867(1,100,2*vol/10);
  }
}

void save()
{
  write_cmd_12864(0x01);
  write_Chinese_12864("请按  键保存，按  键取消！",0,0,12);
  write_Chinese_12864("1.",2,0,1);
  write_Chinese_12864("2.",8,0,1);
  unsigned char key=init_key();
  while((key!=1) && (key!=2))
  {
    delay_12864(10000);
    key=init_key();
  }
  if(key==1)
  {
    write_cmd_12864(0x01);
    write_sega(itswave,itsvol,itsfreq&0xff,itsfreq>>8);
    write_Chinese_12864("保存成功！",10,0,5);
    delay_s(5);
  }
}
void load()
{
  write_cmd_12864(0x01);
  write_Chinese_12864("正在载入。。。",0,0,7);
  char * pflash=(char *)0x1080;
  char temp[4];
  temp[0]=itswave;
  temp[1]=itsvol;
  temp[2]=itsfreq&0xff;
  temp[3]=itsfreq>>8;
  itswave=*pflash++;
  itsvol=*pflash++;
  itsfreq=((*pflash)|(*(pflash+1))<<8);
  delay_s(2);
  write_cmd_12864(0x01);
  if((itswave>2)|(itsfreq>20000)|(itsvol>50))
  {
    write_Chinese_12864("无数据！",0,0,4);
    itswave=temp[0];
    itsvol=temp[1];
    itsfreq=((temp[2])|(temp[3]<<8));
  }
  else
  {
    write_Chinese_12864("载入成功！",0,0,4);
  }
  change_vol(itsvol);
  autoset(itswave,itsfreq);  
  delay_s(2);
}
void exit()
{
  write_cmd_12864(0x01);
  write_Chinese_12864("正在退出。。。",0,0,7);
  delay_s(2);
  thanks();
}
void thanks()
{
  write_cmd_12864(0x01);
  write_Chinese_12864("作者：  赵永科，武磊，于杰",0,0,14);
  write_Chinese_12864("谢谢！",26,0,3);
  delay_s(10);
}