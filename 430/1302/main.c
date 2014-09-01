
#include <msp430x15x.h>
#include"164module.h"
#define DS1302_CLK1     P4OUT|=0x02    /*实时时钟时钟线引脚 */ 
#define DS1302_CLK0	P4OUT&=~0x02
#define DS1302_IO1      P4OUT|=0x08    /*实时时钟数据线引脚 */ 
#define DS1302_IO0	P4OUT&=~0x08
#define DS1302_CE1      P4OUT|=0x20    /*实时时钟复位线引脚 */
#define DS1302_CE0	P4OUT&=~0x20 
#define READPORT        P4IN

#define uchar unsigned char
#define uint unsigned int
unsigned char Setting_Time[]={0x09,0x06,0x08,0x01,0x20,0x38,0x00};
unsigned char Getting_Time[7]={0};
void delay(int ms)
{unsigned int i,j;
 for(i=0;i<ms;i++)
   for(j=0;j<150;j++);
}
void DS1302_init(void)
{P4DIR|=0x2a;
DS1302_CLK0 ; 
DS1302_CE0 ;
}
void DS1302_WRITE_BYTE(uchar ucDa) 
{  DS1302_CE1;
   P4DIR|=0x2a;
uchar i;  
for(i=0; i<8; i++)
{
  if((ucDa&0x01)==0x01)  
       {DS1302_IO1;}
  else {DS1302_IO0;}	
       DS1302_CLK0 ;
       delay(1);
       DS1302_CLK1 ;
       delay(1);
       ucDa>>=1;
} 
}
uchar DS1302_READ_BYTE(void) 
{ 
uchar i,j=0;
DS1302_CE1;
P4DIR&=~BIT3;
for(i=0; i<8; i++)
{  j>>=1;
DS1302_CLK1 ;
DS1302_CLK0 ;
if((READPORT&0x08)==0x08)//要注意先出现下降沿然后才能读
   {j|=0x80;}
} 
P4DIR|=0x2a;
return(j); 
}
void DS1302_WRITE(uchar ucAddr, uchar ucDa)
{
DS1302_WRITE_BYTE(ucAddr); /* 地址，命令 */
DS1302_WRITE_BYTE(ucDa); /* 写1Byte数据*/
DS1302_CLK0 ;            //操作完成之后释放总线
DS1302_CE0 ;
}
uchar DS1302_READ(uchar ucAddr)
{
uchar ucDa;
DS1302_WRITE_BYTE(ucAddr);// 地址，命令 
ucDa=DS1302_READ_BYTE();   //读1Byte数据 
DS1302_CLK0;
DS1302_CE0;
return(ucDa);
} 
/*void READ_time(uchar *buff)
{    
	 buff[2]=DS1302_READ(0x83);
	 buff[4]=DS1302_READ(0x85); 
	 buff[6]=DS1302_READ(0x87); 
	 buff[8]=DS1302_READ(0x89); 
	 buff[1]=buff[0]>>4;
	 buff[0]=buff[0]&0x0f;	
	 buff[3]=buff[2]>>4;
	 buff[2]=buff[2]&0x0f;
	 buff[5]=buff[4]>>4;
	 buff[4]=buff[4]&0x0f;
	 buff[7]=buff[6]>>4;
	 buff[6]=buff[6]&0x0f; 
	 buff[9]=buff[8]>>4;
	 buff[8]=buff[8]&0x0f;	  
}*/
void DS1302_SettingData(void)
{
 unsigned char temp;
 unsigned char addr = 0x8C;
 
 DS1302_WRITE(0x8E,0x00);  //写入控制命令,禁用写保护

   for(temp=0;temp<7;temp++) 
   {
    DS1302_WRITE(addr,Setting_Time[temp]);
    addr -= 2;
   }
}
 //读取DS1302时间到ReadingData中
void DS1302_GetData(unsigned char *str) 
{
 unsigned char temp;
 unsigned char addr = 0x8D;

 for(temp=0;temp<7;temp++) {
  str[temp] = DS1302_READ(addr);//年
  addr -= 2;
 }
}
int main( void )
{ uchar i;
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;
  BCSCTL1&=~XT2OFF;
  do
  {
    IFG1&=~OFIFG;
    for(i=0xff;i;i--);
  }while((IFG1&OFIFG)!=0);
  BCSCTL2|=SELM1;//MCLK=XT2;   
  P4DIR=0x05;
  DS1302_init();
  DS1302_SettingData();
 while(1)
 { Getting_Time[0]=DS1302_READ(0x81);
   show_164(8,(Getting_Time[0]&0x0f));
  Getting_Time[0]=DS1302_READ(0x81);
   show_164(7,(Getting_Time[0]>>4));
   Getting_Time[1]=DS1302_READ(0x83);
    show_164(6,(Getting_Time[1]&0x0f));
  Getting_Time[1]=DS1302_READ(0x83);
  show_164(5,(Getting_Time[1]>>4));
  Getting_Time[2]=DS1302_READ(0x85);
    show_164(3,(Getting_Time[2]&0x0f));
  Getting_Time[2]=DS1302_READ(0x85);
   show_164(2,(Getting_Time[2]>>4));
   //delay(50);
 }
 }
