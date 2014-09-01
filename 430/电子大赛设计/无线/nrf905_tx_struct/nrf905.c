#include "nrf905.h"


void delay_nrf905(unsigned int i)
{
  while(i--);
}
/************************************
���IO�ڵĳ�ʼ���ͳ�ʼ���ݣ�ֻ����ʼ������д������ģ�飬
Ϊ������׼����
************************************/
void init_port_nrf905(RF_CONFIG *pa)
{
  P1DIR=0xc5;
  P1OUT=0x00;
  P2DIR=0x03;
  P2OUT=0x00;
  CSN_1;
  SCK_0;
  if(pa)
  {
    pa->DETAIL.CH_NO=1;          //����Ƶ��ѡ��
    pa->DETAIL.AUTO_RETRAN=0;    //��ֹ�Զ��ط�
    pa->DETAIL.RX_RED_PWR=0;     //����ģʽ������ڵ͹���ģʽ��
    pa->DETAIL.PA_PWR=3;         //�������+10db
    pa->DETAIL.HFREQ_PLL=0;      //433Mhz ��
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
  /*
  send_byte_nrf905(0x01);
  send_byte_nrf905(0x0c);
  send_byte_nrf905(0x44);
  send_byte_nrf905(0x20);
  send_byte_nrf905(0x20);
  send_byte_nrf905(0xcc);
  send_byte_nrf905(0xcc);
  send_byte_nrf905(0xcc);
  send_byte_nrf905(0xcc);
  send_byte_nrf905(0x58);//       0 1 011 000
  */
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
�������ã���ȡ��ǰ״ֵ̬��AM��DR��
����ֵ��  0xaa�����Ѿ����յ����ݣ��ȴ���ȡ
          0x00����������������
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
�������ã���������ģ��
����Ҫ�󣺽ṹ��ָ��pdָ����Ч����
����ǰ�ࣺ���IO�ڳ�ʼ����������
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
����˵����������������Ƶ�ʺ��������
�������ã�
        ʹCH_NO=ch_no;
        HFREQ_PLL=hreq;
        PA_PWR=pa;
����ǰ�ࣺ���IO�ڳ�ʼ����������
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
�������ã�������ã����������ֽںͷ��͵�ַ
����Ҫ�󣺽ṹ��ָ��pdָ����Ч����buf����4�ֽ�
����ǰ�ࣺ���Ѿ����úõ�����ģ����߸��ϵ��ģ�鶼���Խ���
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
�������ã���32�ֽ����ݷ��ͳ�ȥ
����Ҫ��buff����Ϊ32�ֽ�
����ֵ  : ��
����ǰ�ࣺ������ģ�����úú󼴿ɷ�������
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
�������ã�����
����Ҫ��rxbuf����32�ֽ�
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