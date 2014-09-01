//ICC-AVR application builder : 2006-4-4 11:28:26
// Target : M16 PTR8000模块简单测试
// Crystal: 11.059Mhz

//最关键的是SPI的初始化，MSB首位和极性方式00，极性方式错误，数据则不正确

#include <iom16v.h>
#include <macros.h>

#include "config.h"
#include "nrf905.h"

#define MASTER  //编译控制是主机还是从机

#define T0N 25

//32字节数据包发送时间 
//=650us_StartUp+200us_Preamble+(4+32+2)Byts*8Bit/50000bps*1000000us=6.6ms
#define RFTN 10  //发送测试间隔 10*20ms

bit bTimer,bRfSend;
uchar T0Cnt,RfCnt;

void port_init(void)
{
 PORTA = 0x08;
 DDRA  = 0x37;
 PORTB = 0x50;
 DDRB  = 0xBF;
 PORTC = 0x00; //m103 output only
 DDRC  = 0x00;
 PORTD = 0x1C;
 DDRD  = 0x80;
}

//TIMER0 initialize - prescale:1024
// WGM: Normal
// desired value: 20mSec
// actual value: 19.908mSec (0.5%)
void timer0_init(void)
{
 TCCR0 = 0x00; //stop
 TCNT0 = 0x29; //set count
 OCR0  = 0xD7;  //set compare
 TCCR0 = 0x05; //start timer
}

#pragma interrupt_handler timer0_ovf_isr:10
void timer0_ovf_isr(void)
{
 TCNT0 = 0x29; //reload counter value
 
 if (--T0Cnt==0)
   {T0Cnt=T0N;
    bTimer=1;
    }
if (--RfCnt==0)
   {RfCnt=RFTN;
    bRfSend=1;
    }
}

//TIMER1 initialize - prescale:8
// WGM: 0) Normal, TOP=0xFFFF
// desired value: 10mSec
// actual value:  9.999mSec (0.0%)
void timer1_init(void)
{
 TCCR1B = 0x00; //stop
 TCNT1H = 0xCA; //setup
 TCNT1L = 0x01;
 OCR1AH = 0x35;
 OCR1AL = 0xFF;
 OCR1BH = 0x35;
 OCR1BL = 0xFF;
 ICR1H  = 0x35;
 ICR1L  = 0xFF;
 TCCR1A = 0x00;
 TCCR1B = 0x02; //start Timer
}

#pragma interrupt_handler timer1_ovf_isr:9
void timer1_ovf_isr(void)
{
 //TIMER1 has overflowed
 TCNT1H = 0xCA; //reload counter high value
 TCNT1L = 0x01; //reload counter low value
}

//SPI initialize
void spi_init(void)
{uchar temp;

 //SPCR = 0xD1; //SPI中断允许,SPI允许，主机模式，MSB，极性方式00，1/16系统时钟速率
 SPCR = 0x51; //不使用SPI中断,其它同上
 SPSR = 0x00; //setup SPI
 
 temp = SPSR; //!!!
 temp = SPDR; //清空SPI，和中断标志，使SPI空闲    
}

#pragma interrupt_handler spi_stc_isr:11
void spi_stc_isr(void)
{uchar data;
 //byte in SPDR has been sent/received
 //data=SPDR;
 //SPDR=0x66;
}

//UART0 initialize
// desired baud rate: 19200
// actual: baud rate:19200 (0.0%)
// char size: 5 bits
// parity: Disabled
void uart0_init(void)
{
 UCSRB = 0x00; //disable while setting baud rate
 UCSRA = 0x00;
 UCSRC = BIT(URSEL) | 0x00;
 UBRRL = 0x23; //set baud rate lo
 UBRRH = 0x00; //set baud rate hi
 UCSRB = 0x18;
}

//call this routine to initialize all peripherals
void init_devices(void)
{
 //stop errant interrupts until set up
 CLI(); //disable all interrupts
 port_init();
 timer0_init();
 timer1_init();
 spi_init();
 uart0_init();

 MCUCR = 0x00;
 GICR  = 0x00;
 TIMSK = 0x05; //timer interrupt sources
 SEI(); //re-enable interrupts
 //all peripherals are now initialized
}

void main()
{
   init_devices();
   SystemIni();
   nrf905_Init();

   while (1)
   {  
      if (bTimer) TimerFunc();
	  #ifdef MASTER
	    if (bRfSend)
		{ bRfSend=0;
		  RfSendProc();//发送测试
		}
	  #endif
	  
	  RfRecvProc();//接收处理
   };
}

//接收处理
void RfRecvProc()
{uchar i;

   //if ((PIND&(1<<AM))==0) return;//一般先AM=1指示地址匹配对
   
   if ((PIND&(1<<DR))==0) return;//DR=1时表示数据接收对而且Crc正确
   
   //已经接收到数据
   nrf905_ReadData();//读出...
   for (i=0;i<32;i++)
   { if (RxBuf[i]!=(i+i)) 
        return;
   }
   
   //数据接收正确...灯指示
   CPL(PORTD,LED);
   
   //从机回送数据包,这样双方都能指示是否收到有效数据包
   #ifndef MASTER
     RfSendProc();
   #endif
}

//发送测试
void RfSendProc()
{uchar i;
   for (i=0;i<32;i++) TxBuf[i]=i+i;
   nrf905_SendData();//发送测试数据
   nrf905_RxOn();//重新回到接收状态
}

void TimerFunc()
{
   bTimer=0;
   //WDR();//clear WDT
   
   CPL(PORTD,LED);
   //SPDR=66;
}

void SystemIni()
{
  T0Cnt=T0N;
  RfCnt=RFTN;
}

void DelayMs(uchar ms)
{char i;
for (i=0;i<ms;i++)
  {DelayUs(1000);
  }
  return;
}

void DelayUs(uint us)
{uint i;
  for (i=0;i<us;i++)
  {NOP();NOP();NOP();NOP();NOP();NOP();
  }
}

