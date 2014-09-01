/*********************************************************************
声明：各函数以及参数的意思，见12864module.h
*********************************************************************/
#include <msp430x15x.h>
#include"12864module.h"
#include"ds18b20.H"
#include "key.h"
unsigned char i,keyvalue_old=1,keyvalue_new=1,count,mycount=0;//计数
int tmp[128];//从18b20读取的数据
/*****************************
数组存放转换结果，以便显示
第一字节：符号。0+，1-
第二字节：整数部分
第三字节：小数部分=data*2^(-4)
******************************/
char buffer[6]={0};
void waiting(void)
{
    show_picture2(56,4,picture_sl_1,19,32);
    delay(300);
    show_picture2(56,4,picture_sl_2,19,32);
    show_hanzi(hanzi_qingshaohou,10,5,5,0);
        delay(300);
    show_picture2(56,4,picture_sl_3,19,32);
    show_hanzi(hanzi_qingshaohou,10,5,5,0);
        delay(300);
    show_picture2(56,4,picture_sl_4,19,32);
    show_hanzi(hanzi_qingshaohou,10,5,5,0);
        delay(300);
    show_picture2(56,4,picture_sl_5,19,32);
    show_hanzi(hanzi_qingshaohou,10,5,5,0);
        delay(300);
    show_picture2(56,4,picture_sl_6,19,32);
    show_hanzi(hanzi_qingshaohou,10,5,5,0);
        delay(300);
    show_picture2(56,4,picture_sl_7,19,32);
    show_hanzi(hanzi_qingshaohou,10,5,5,0);
        delay(300);

}
void huanying(void)
{
  init_12864();
  show_hanzi(hanzi,2*16,0,4,0);
  show_hanzi(hanzi,16,2,7,4);
}
void show_temperature()
{
    show_hanzi(hanzi2,0,0,5,0);
  if(!buffer[0])
  {
      show_ascii(2,3,' ');
  }
  else
  {
      show_ascii(2,3,'-');
  }
  show_shuzi(24,3,buffer[1]/10);
  show_shuzi(32,3,buffer[1]%10);
  show_ascii(6,3,'.');
  show_shuzi(48,3,buffer[2]*5/8);
}
void History(void)
{

    unsigned char i,j=mycount+1;
    for(i=0;i<128;i++,j=(j+1)%128)
    {
        set_point(i,(tmp[j])&0x3f,1);
        delay(1);
    }
}
void Zuozhe(void)
{
    show_hanzi(hanzi_zuozhe,0,0,7,0);
    show_hanzi(hanzi_zuozhe,48,2,3,7);
    show_hanzi(hanzi_zuozhe,48,4,2,10);
}
main()
{// Stop watchdog timer to prevent time out reset
    WDTCTL = WDTPW + WDTHOLD;
    init_port();//`````````````````````````````` 
    init_device();////////////////////////
    huanying();
    while(KeyScan()==-1);
    clear();
    send_cmd(0x40);
    TACTL=TASSEL1+TACLR;
    CCR0=0;
    CCTL0=CCIE;
    TACTL|=MC1;
    _EINT();
    while(1)
    {   
        convert_t(tmp[mycount],buffer);
        keyvalue_old=keyvalue_new;
        keyvalue_new=KeyScan();
        if(keyvalue_new==0xff)
        {
            keyvalue_new=keyvalue_old;
        }
        switch(keyvalue_new)
        {
        case 1:
            clear();
            show_temperature();
            delay(100);
            break;
        case 2:
            huanying();
            delay(100);
            break;
        case 3:
            clear();
            History();
            delay(100);
            break;
        case 4:
            clear();
            Zuozhe();
            delay(100);
            break;
        case 5:
            waiting();
            break;
            //Riqi();
        
        default:
            waiting();
            break;
        
        }
        
    }
}

#pragma vector=TIMERA0_VECTOR
__interrupt void timer_a(void)
{

  CCR0=0;
  count++;
  if(count==2)
  {
    start_convert();
  }
  if(count==4)
  {
    mycount++;
    if(mycount>=128)
    {
        mycount=0;
    }
    tmp[mycount]=read_temperature();
    count=0;
  }
  
}