#include "nrf905.h"


void delay_nrf905(unsigned int i)
{
  while(i--);
}
/************************************
完成IO口的初始化和初始数据（只做初始化但不写入无线模块，
为后面做准备）
************************************/
void init_port_nrf905(RF_CONFIG *pa)
{

  CSN_1;
  SCK_0;
  if(pa)
  {
    pa->DETAIL.CH_NO=1;          //中心频率选择
    pa->DETAIL.AUTO_RETRAN=0;    //禁止自动重发
    pa->DETAIL.RX_RED_PWR=0;     //正常模式（相对于低功耗模式）
    pa->DETAIL.PA_PWR=3;         //输出功率+10db
    pa->DETAIL.HFREQ_PLL=0;      //433Mhz 段
    pa->DETAIL.RX_AW=4;
    pa->DETAIL.TX_AW=4;
    pa->DETAIL.RX_DW=32;
    pa->DETAIL.TX_DW=32;
    pa->DETAIL.RX_ADDR[0]=0xcc;
    pa->DETAIL.RX_ADDR[1]=0xcc;
    pa->DETAIL.RX_ADDR[2]=0xcc;
    pa->DETAIL.RX_ADDR[3]=0xcc;
    pa->DETAIL.CRC_MODE=0;       //8bit CRC
    pa->DETAIL.CRC_EN=1;         //Enable CRC check
    pa->DETAIL.XOF=3;            //16MHz
  }
}

void send_byte_nrf905(unsigned char d)
{
  unsigned char i;
  SCK_0;
  for(i=0;i<8;i++)
  {
    if(d&0x80)
    {
      MOSI_1;
    }
    else
    {
      MOSI_0;
    }
    SCK_1;
    _NOP();
    SCK_0;
    d<<=1;
  }
  
}
unsigned char read_byte_nrf905(void)
{
  unsigned char i,t=0;
  SCK_0;
  for(i=0;i<8;i++)
  {
    SCK_1;
    t<<=1;
    if(MISO_IN)
    {
      t|=0x01;
    }
    SCK_0;
    _NOP();
  }
  return t;
}
/*************************************
函数作用：读取当前状态值（AM和DR）
返回值：  0xaa代表已经接收到数据，等待读取
          0x00……………………
*************************************/
unsigned char read_status_nrf905(void)
{
  unsigned char i,t=0;  
  MOSI_0;
  SCK_0;
  CSN_0;
  for(i=0;i<8;i++)
  {
    SCK_1;
    t<<=1;
    if(MISO_IN)
    {
      t|=0x01;
    }
    SCK_0;
    _NOP();
  }
  CSN_1;
  return t;
}
/*********************************
函数作用：配置无线模块
参数要求：结构体指针pd指向有效数据
函数前奏：完成IO口初始化即可配置
*********************************/
void config_nrf905(RF_CONFIG * pd)
{
  unsigned char x;
  STAND_BY_MODE;  
  delay_nrf905(100);
  CSN_0;
  send_byte_nrf905(0x00);  //config
  for(x=0;x<10;x++)
  {
    send_byte_nrf905(pd->buffer[x]);
  }
  CSN_1;
  CSN_0;
  send_byte_nrf905(WRITE_TX_ADDR);
  send_byte_nrf905(0xcc);
  send_byte_nrf905(0xcc);
  send_byte_nrf905(0xcc);
  send_byte_nrf905(0xcc);
  CSN_1;
  
}
/***********************************************************************
函数说明：快速配置中心频率和输出功率
最终作用：
        使CH_NO=ch_no;
        HFREQ_PLL=hreq;
        PA_PWR=pa;
函数前奏：完成IO口初始化即可配置
***********************************************************************/
void fast_config_nrf905(unsigned int ch_no,unsigned char hfreq,unsigned char pa)
{
  unsigned char i,j;
  STAND_BY_MODE;  
  i=ch_no&0xff;
  j=(ch_no>>8)+((hfreq&0x01)<<1)+((pa&0x03)<<2)+0x80;
  CSN_0;
  send_byte_nrf905(j);  
  send_byte_nrf905(i);
  CSN_1;
}  
/**********************************************************
函数作用：检查配置，包括配置字节和发送地址
参数要求：结构体指针pd指向有效区域，buf长度4字节
函数前奏：对已经配置好的无线模块或者刚上电的模块都可以进行
**********************************************************/
void check_config_nrf905(RF_CONFIG * pd,unsigned char *buf)
{
  unsigned char i;
  CSN_0;
  send_byte_nrf905(READ_CONFIG);
  for(i=0;i<10;i++)
  {
    pd->buffer[i]=read_byte_nrf905();
  }
  CSN_1;  
  CSN_0;
  send_byte_nrf905(READ_TX_ADDR);
  for(i=0;i<4;i++)
  {
    buf[i]=read_byte_nrf905();
  }
  CSN_1; 
}
/****************************************
函数作用：将32字节数据发送出去
参数要求：buff长度为32字节
返回值  : 无
函数前奏：将无线模块配置好后即可发送数据
****************************************/
void transmit_nrf905(unsigned char *buff)
{
  unsigned char i;
  STAND_BY_MODE;
  CSN_0;
  send_byte_nrf905(WRITE_TX_DATA);
  for(i=0;i<32;i++)
  {
    send_byte_nrf905(buff[i]);
  }
  CSN_1;
  delay_nrf905(100);
  TX_MODE;  
}
/*************************************
函数作用：监听
参数要求：rxbuf长度32字节
*************************************/
void listen_nrf905(unsigned char * rxbuf)
{
  unsigned char ii;
  RX_MODE;  
  delay_nrf905(1000);
  while(CD_IN==0);
  while(AM_IN==0);
  while(DR_IN==0);
  STAND_BY_MODE;
  _NOP();
  CSN_0;
  send_byte_nrf905(READ_RX_DATA);
  for(ii=0;ii<32;ii++)
  {
    rxbuf[ii]=read_byte_nrf905();
  }
  CSN_1;// Disable spi
  while(DR_IN||AM_IN);
}
