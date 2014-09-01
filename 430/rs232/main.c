#include "msp430x44x.h"
void init_uart(void);
void uart_start(void);
void uart_send(void);
void uart_receive(void);
unsigned char RXDATA_BUF[10],TXDATA_BUF[10]={0xbd,0x77,0x3d,0xc5,0xc6,0xf5,0x68,0x0d,0x6b,0xff};
unsigned int RX_count=0,TX_count=0,TXBUF_num=10,RXBUT_num=10,FLAG;
void main(void)
{   init_uart();
    uart_start();
    while(1)
    {_BIS_SR(CPUOFF);
    _NOP();
    }
}

void init_uart(void)                    //��ʼ��UART
{   unsigned int i;
    WDTCTL=WDTPW+WDTHOLD;
    FLL_CTL1|=XT2OFF+SELM_XT2+SELS;     //ѡ��MCLKʱ��Դ
    do                                  //�ȴ�ʱ���ȶ�
    {   IFG1&=~OFIFG;
        for(i=0;i<0xff;i++);
    }while((FLL_CTL0&XT2OF)==XT2OF);
    UCTL0|=SWRST;                       //���ƼĴ���λ
    UCTL0|=CHAR;
    UTCTL0=SSEL0+SSEL1;                 //ѡ����ʱ��Դ��λ
    UBR00=0XA0;                         //������9600
    UBR10=0X01;
    UMCTL0=0X5E;
    UCTL0&=~SWRST;                      //ѡ����ʱ��Դ��λ
    ME1|=URXE0+UTXE0;                   //ʹ��TXD  RXD
    IE1|=URXIE0;
    IFG1=0X00;
    P2SEL|=0X30;                        //ģ��ѡ��
    P2DIR|=0X10;
    for(i=0;i<10;i++) {*RXDATA_BUF=0;}//����ջ���
    _EINT();
}

void uart_start(void)                   //��������
{   IE1|=UTXIE0;
    while((UTCTL0&BIT0)!=BIT0);
    TXBUF0=TXDATA_BUF[0];
    TX_count=1;
}

void uart_receive(void)                 //����
{   RXDATA_BUF[RX_count]=RXBUF0;
    RX_count+=1;
    if(RX_count>=RXBUT_num) {RX_count=0;}
}

void uart_send(void)                    //����
{   TXBUF_num-=1;
    if(TXBUF_num>0)
      {   TXBUF0=TXDATA_BUF[TX_count];
          TX_count+=1;     
      }
    else
     {   FLAG+=1;
        if(FLAG>10)  {IE1&=~UTXIE0;}
              else  {   TXBUF_num=10;
                        TX_count=0;
                        uart_start();
                     }
     }
}

__interrupt [UART0TX_VECTOR] void uart_tx(void)//�����ж���Ӧ
{   
    uart_send();
}

__interrupt [UART0RX_VECTOR] void uart_rx(void)//�����ж���Ӧ
{
    uart_receive();
}


