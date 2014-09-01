
#include "msp430x15x.h"
#define DataBus P4OUT
#define InBus   P4IN
#define RESET  P5OUT&=~0x02;
#define NoRESET P5OUT|=0x02;
#define IsData P5OUT|=0x08;
#define IsComd P5OUT&=~0x08;
#define IsRead P5OUT|=0x20;
#define IsWrite P5OUT&=~0x20;
#define E_1 P5OUT|=0x80;
#define E_0 P5OUT&=~0x80;

#define DisplayOn 0xaf
#define DisplayOff 0xae
unsigned char StartLine=0x40;//di 0 hang


#define		M_LCD_VDD_SET	M_LCD_SETR_5		//3.3V供电时选此二项
#define		M_LCD_VDD		M_LCD_BIAS_9		//....
//#define		M_LCD_VDD_SET	M_LCD_SETR_4	//5.0V供电时选此二项
//#define		M_LCD_VDD		M_LCD_BIAS_9	//...


//LCD开关命令
#define		M_LCD_ON		0x00af
#define		M_LCD_OFF		0x00ae
//设置上电控制模式
#define		M_LCD_POWER_BC	0x002c
#define		M_LCD_POWER_VR	0x002a
#define		M_LCD_POWER_VC	0x0029
#define		M_LCD_POWER_ALL	0x002f
//V5内部电压调节电阻设置……
#define		M_LCD_SETR_0	0x0020
#define		M_LCD_SETR_1	0x0021
#define		M_LCD_SETR_2	0x0022
#define		M_LCD_SETR_3	0x0023
#define		M_LCD_SETR_4	0x0024
#define		M_LCD_SETR_5	0x0025
#define		M_LCD_SETR_6	0x0026
#define		M_LCD_SETR_7	0x0027
//...end
#define		M_LCD_ELE_VOL	0x0081		//电量设置模式（显示亮度）
//偏压设置
#define		M_LCD_BIAS_9	0x00a2		//V5时选此选项设置
#define		M_LCD_BIAS_7	0x00a1		//V3时选此选项设置
//Com 扫描方式设置命令
#define		M_LCD_COM_NOR	0x00c0		//正常方式
#define		M_LCD_COM_REV	0x00c8		//反相
//Segment方向选择
#define		M_LCD_SEG_NOR	0x00a0		//正常
#define		M_LCD_SEG_REV	0x00a1		//反向
//全屏点亮/变暗指令
#define		M_LCD_ALL_LIGNT	0x00a5		//LCD ALL paint ON
#define		M_LCD_ALL_LOW	0x00a4		//Normal Display mode
//正相反相显示控制指令，RAM中数据不变
#define		M_LCD_ALL_NOR	0x00a6		//正相
#define		M_LCD_ALL_REV	0x00a7		//反相
//静态指示器控制指令
#define		M_LCD_STATIC_ON	0x00ad		//ON
#define		M_LCD_STATIC_OFF 0x00ac		//OFF
//设置显示起始行对应RAM行号
#define		M_LCD_BEGIN_LINE 0x0040		//基数，后面可加的尾数可为0~63
//设置当前页基数
#define		M_LCD_COL_PAGE	0x00b0		//基数指令，后可加尾数0~8
//设置当前列基数
#define		M_LCD_COL_LINE_LOW	0x0004		//基数指令，低四位有效
#define		M_LCD_COL_LINE_HIG	0x0010		//基数指令，低四位有效
//========================================================================//
//API接口函数宏定义
//========================================================================//
/////-----       屏幕尺寸	    -----/////
#define SCR_MAX_COL		128	
#define SCR_MAX_ROW		64						
//#define TEXT_MAX_COL	20
//#define TEXT_MAX_ROW	4

/////-----       电源模式	    -----/////
#define PWR_ON			0x0001					
#define	PWR_OFF			0x0000
#define PWR_SLEEP		0x0002
#define PWR_STDBY		0x0003

/////-----       图形显示模式	    -----/////
#define PAINT_COVER		0
#define PAINT_SET		1
#define PAINT_CLR		2
#define PAINT_REV		3
#define PAINT_RECO		4

#define PAINT_HOLLOW	0
#define PAINT_SOLID		1	
unsigned int i,j,stat;
const unsigned char table[]=
{
  0x00,0x00,0x0c,0x30,0xc0,0x20,0x10,0x08,
  0x40,0x48,0x48,0xff,0x48,0x48,0x48,0x40,
  0x00,0x40,0x4c,0x43,0x40,0x43,0x44,0x48,
  0x42,0x42,0x42,0x3f,0x10,0x0f,0x30,0x40
};
void init_lcd(void);
void send_cmd(unsigned char cmd);
void send_data(unsigned char d);
void delay(unsigned int t);
unsigned char read_stat(void);
unsigned char read_data(void);
void set_pos(unsigned char x,unsigned char y);
void clear(void);
int main( void )
{
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;
  RESET;
  delay(10000);
  NoRESET;
  init_lcd();
  delay(60000);
//  clear();
  while(1)
  {
    delay(5000);
    send_cmd(StartLine++);
    if(StartLine>=0x80)
    {
      StartLine=0x40;
    }
  }

}
void send_cmd(unsigned char cmd)
{
  E_0;
  _NOP();
  IsWrite;
  IsComd;
  _NOP();  
  E_1;
  delay(1);
  DataBus=cmd;
  delay(1);
  E_0;
  
}
void send_data(unsigned char d)
{
  E_0;
  _NOP();
  IsWrite;
  IsData;
  _NOP();  
  E_1;
  _NOP();
  DataBus=d;
  _NOP();
  _NOP();
  E_0;
}
void init_lcd(void)
{

  P4DIR=0xff;
  P4OUT=0x0f;
  P2DIR=0x10;
  P5DIR=0xaa;
  delay(3000);
  send_cmd(M_LCD_ON);
  stat=read_stat();
  send_cmd(M_LCD_POWER_ALL);  
  stat=read_stat();
  send_cmd(M_LCD_ELE_VOL);  
  stat=read_stat();
  send_cmd(0x12);
  stat=read_stat();
  send_cmd(M_LCD_VDD_SET);
  stat=read_stat();
  send_cmd(M_LCD_COM_NOR);
  stat=read_stat();  
  send_cmd(StartLine);
  stat=read_stat();
  set_pos(64,1);
  stat=read_stat();
  for(i=0;i<16;i++)
  {
   send_data(table[i]);
   stat=read_stat();
  }
  set_pos(64,2);
  for(i=16;i<32;i++)
  {
    send_data(table[i]);
    stat=read_stat();
  }
}

void delay(unsigned int t)
{
  while(t--);
}
unsigned char read_stat(void)
{
  unsigned char t;
  P4DIR=0x00;
  P4OUT=0xff;
  E_0;
  IsComd;
  IsRead;
  _NOP();
  E_1;
  _NOP();
  E_0;
  t=P4IN;
  P4DIR=0xff;
  return t;
}
unsigned char read_data(void)
{
  unsigned char t;
  P4DIR=0x00;
  P4OUT=0xff;
  E_0;
  IsData;
  IsRead;
  _NOP();
  E_1;
  _NOP();
  E_0;
  t=P4IN;
  P4DIR=0xff;
  return t;
}
void set_pos(unsigned char x,unsigned char y)
{
  unsigned char tmp;
  y&=0x0f;
  tmp=0xb0;
  tmp|=y;
  send_cmd(tmp);
  stat=read_stat();
  tmp=0x10;
  tmp|=(x>>4);
  send_cmd(tmp);
  stat=read_stat();
  x&=0x0f;
  send_cmd(x);
  stat=read_stat();
}
void clear(void)
{
  unsigned char x,y;
  for(y=0;y<8;y++)
  {
    set_pos(0,y);
    stat=read_stat();
    for(x=0;x<128;x++)
    {
      send_data(0x00);
      stat=read_stat();
    }
  }
} 