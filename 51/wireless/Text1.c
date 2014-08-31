/*=================================================================
==本程序由串口调试助手向单片机发送小写字母l（left）r(right) u(up)  ==
== d(down)代表四个命令                                             ==
======================================================================*/
#include <at89x52.h>
#include <intrins.h>
#define uchar unsigned char 
#define uint  unsigned int

#define WC		0x00			// Write configuration register command
#define RC		0x10 			// Read  configuration register command
#define WTP		0x20 			// Write TX Payload  command
#define RTP		0x21			// Read  TX Payload  command
#define WTA		0x22			// Write TX Address  command
#define RTA		0x23			// Read  TX Address  command
#define RRP		0x24			// Read  RX Payload  command
/*******************************************************************************************/
typedef struct RFConfig
{
	uchar n;
	uchar buf[10];
}RFConfig;

code RFConfig RxTxConf =
{
	10,
	0x01, 0x0c, 0x44, 0x20, 0x20, 0xcc, 0xcc, 0xcc,0xcc, 0x58	
};

/*******************************************************************************************/
uchar data TxBuf[32];
uchar data RxBuf[32];

/*******************************************************************************************/
uchar bdata DATA_BUF;
sbit	flag	=DATA_BUF^7;
sbit	flag1	=DATA_BUF^0;
/*******************************************************************************************/
sbit	TX_EN	=P3^5;               //发射使能，高有效
sbit	TRX_CE	=P2^4;               //TRX_CE发送接收使能  高有效
sbit	PWR_UP	=P3^6;               //上电     
sbit	MISO	=P2^1;               //spi输出
sbit	MOSI	=P2^6;               //spi输入
sbit	SCK		=P2^0;               //spi时钟
sbit	CSN		=P2^5;               //spi片选

sbit	AM		=P2^2;               //AM 地址匹配，受到有效地址被置高
sbit	DR		=P2^7;               //数据准备就绪
sbit	CD		=P3^7;               //载波检测，检测到频率相同的载波时，置高

sbit    LED1    =P1^0; 
sbit    LED2    =P1^1;
sbit    LED3    =P1^3;
sbit    LED4    =P1^4;
sbit    KEY1    =P1^2;

/*******************************************************************************************/
void Config905(void);			// Config nRF905 module配置NRF905模式
void SetTxMode(void);			// Set nRF905 in Tx mode
void SetRxMode(void);			// Set nRF905 in Rx mode
void TxPacket(void);			// Send data by nRF905
void RxPacket(void);			// Recive data by nRF905
void SpiWrite(uchar);			// Write data to nRF905
uchar SpiRead(void);			// Read data to nRF905
void Delay(uchar n);			// Delay 100us
void TxData (uchar x);			// Send key_value to CRT display

/*******************************************************************************************/
void UART_init();                          //串口初始化函数
void COM_send(unsigned char );             //串口发送函数
 //unsigned char str[]=" <please input r  OR l!> " ;
unsigned char RECEIVR_buffer ;


void Delay(uchar n)
{
	uint i;
	while(n--)
	for(i=0;i<80;i++);	
}

void main()
{
   
   UART_init();
    //================NRF905初始化
	CSN=1;						// Spi 	disable						
	SCK=0;						// Spi clock line init high
	DR=1;						// Init DR for input
	AM=1;						// Init AM for input
	PWR_UP=1;					// nRF905 power on
	TRX_CE=0;					// Set nRF905 in standby mode
	TX_EN=0;					// set radio in Rx mode	

	//================
	Config905();				// Config nRF905 module

    LED2=CD;
	TxBuf[0] = 1;
	TxBuf[1] = 1;
    TxBuf[2] = 1;
    TxBuf[3] = 1;
	SetTxMode();				// Set Tx Mode
	TxPacket();				// Transmit Tx buffer data
	LED1 = 0;


	Delay(500);				// delay for led light	
	LED1 =1;
	TxBuf[0] = 0xff;
	TxBuf[1] = 0xff;
    TxBuf[2] = 0xff;
    TxBuf[3] = 0xff;

					// led close
	SetRxMode();				// Set nRF905 in Rx mode

while(1)
{

           if(RECEIVR_buffer=='l'||RECEIVR_buffer=='r'||RECEIVR_buffer=='f'||RECEIVR_buffer=='b'||KEY1==0)
         //if(KEY1 ==0 )
	       { LED1 = 0; 
            TxBuf[0] = RECEIVR_buffer ; 
            COM_send(RECEIVR_buffer);
  
		  //===============NRF905发送相应的按键	  
		     SetTxMode();				// Set Tx Mode
		     TxPacket();				// Transmit Tx buffer data

			//TxBuf[0] = 0xff;
			//TxBuf[1] = 0xff;
			SetRxMode();				// Set nRF905 in Rx mode
			Delay(500);
			LED1 = 1;
		
		  }

		 
         //=====================等待NRF905接收
	   if (DR)			// If recive data ready...   数据准备就绪
	   RxPacket();			// ... recive data

}

}
/*******************************************************************************************/
void Config905(void)
{
	uchar i;					
	CSN=0;						// Spi enable for write a spi command
	SpiWrite(WC);				// Write config command写放配置命令
	for (i=0;i<RxTxConf.n;i++)	// Write configration words  写放配置字
	{
		SpiWrite(RxTxConf.buf[i]);
	}
	CSN=1;						// Disable Spi
}

/*******************************************************************************************/
void SpiWrite(uchar  byte)
{
	uchar i;	
	DATA_BUF=byte;				// Put function's parameter into a bdata variable		
	for (i=0;i<8;i++)			// Setup byte circulation bits
	{	
		
		if (flag)				// Put DATA_BUF.7 on data line
			MOSI=1;
		else
			MOSI=0;
		SCK=1;					// Set clock line high
		DATA_BUF=DATA_BUF<<1;	// Shift DATA_BUF
		SCK=0;					// Set clock line low 
	}	
}

/*******************************************************************************************/
uchar SpiRead(void)
{
	uchar i;	
	for (i=0;i<8;i++)			// Setup byte circulation bits
	{	
		DATA_BUF=DATA_BUF<<1;	// Right shift DATA_BUF
		SCK=1;					// Set clock line high
		if (MISO)
			flag1=1;			// Read data
		else
			flag1=0;
							
		
		SCK=0;					// Set clock line low
	}
	return DATA_BUF;			// Return function parameter
}

/*******************************************************************************************/
void TxPacket(void)
{
	uchar i;
	//Config905();				
	CSN=0;						// Spi enable for write a spi command	
	SpiWrite(WTP);				// Write payload command
	for (i=0;i<32;i++)
	{
		SpiWrite(TxBuf[i]);		// Write 32 bytes Tx data
	}
	CSN=1;						// Spi disable						
	Delay(1);
	CSN=0;						// Spi enable for write a spi command	
	SpiWrite(WTA);				// Write address command
	for (i=0;i<4;i++)			// Write 4 bytes address
	{
		SpiWrite(RxTxConf.buf[i+5]);
	}	
	CSN=1;						// Spi disable

	TRX_CE=1;					// Set TRX_CE high,start Tx data transmission
	Delay(1);					// while (DR!=1);
	TRX_CE=0;					// Set TRX_CE low
}

/*******************************************************************************************/
void RxPacket(void)
{
	uchar i;	
	TRX_CE=0;					// Set nRF905 in standby mode	
	CSN=0;						// Spi enable for write a spi command
	SpiWrite(RRP);				// Read payload command	
	for (i=0;i<32;i++)
	{
		RxBuf[i]=SpiRead();		// Read data and save to buffer		
	}
	CSN=1;						// Disable spi
	while(DR||AM)               //等待... /////////////如果接收不到程序将停滞 数据准备就绪以及地址匹配
	;	                          //即如果没有匹配的905模块时，这一句需要注释掉
	  
	    TRX_CE=1;               //允许发生或接收 ？？？？？？？？？？？？？？？？？？？？？？？？？？

        if(RxBuf[0] == 1) 
	    {	  
		 LED1 = 0 ;
	    }
      /* if(RxBuf[1] == 1) 
	   {
	   		 LED2 = 0 ;
		}
         if(RxBuf[2] == 1) 
	   {
	   		 LED3 = 0 ;
		}
		if(RxBuf[3] == 1) 
	   {
	   		 LED4 = 0 ;
		}*/
	  
	Delay(500);					// ...light led
      LED1 = 1 ;
	  LED2 = 1 ;
	   LED3 = 1 ;
	    LED4 = 1 ;
	  								
}
/*******************************************************************************************/

void SetTxMode(void)				
{	
	TX_EN=1;
	TRX_CE=0;
	Delay(1); 					// delay for mode change(>=650us)
}				
/*******************************************************************************************/
void SetRxMode(void)
{
	TX_EN=0;
	TRX_CE=1;
	Delay(1); 					// delay for mode change(>=650us)				
}

//==============================================
//-------------------------------------------------------------
//--------------------------------------------------------------------------------------------------
// 函数名称： UART_init()串口初始化函数
// 函数功能： 在系统时钟为11.059MHZ时，设定串口波特率为9600bit/s
//             串口接收中断允许，发送中断禁止
//--------------------------------------------------------------------------------------------------
void UART_init()
{
                         //初始化串行口和波特率发生器
SCON =0x50;              //选择串口工作方式1，打开接收允许 sm0=0,sm1=1,sm2=0,ren=1,tb8,rb8,ti,ri
TMOD =0x20;              //定时器1工作在方式2，定时器0工作在方式1
TH1 =(0xff-5);           //实现波特率9600（系统时钟11.0592MHZ）8位计数器自动重装
PCON = 0x80;             //SMOD=1;
TR1 =1;                  //启动定时器T1
ET1 =0;
ES=1;                    //允许串行口中断
PS=1;                    //设计串行口中断优先级
EA =1;                   //单片机中断允许
}
//------------------------------------------------------------
void COM_send(unsigned char var)
{
                                            
    SBUF= var;
    while(!TI)   //等待发送完毕,发送完毕后置一
	;
    TI=0;        //复位发送中断标志   
    RECEIVR_buffer=0;

}
//--------------------------------------------------------------
//--------------------------------------------------------------------------------------------------
// 函数名称： com_interrup()串口接收中断处理函数
// 函数功能： 接收包括起始位'S'在内的十位数据到数据缓冲区
//--------------------------------------------------------------------------------------------------
void com_interrupt(void) interrupt 4 using 3
{
   
   if(RI)                                   //处理接收中断
   {  
      RI=0;                                 //清除中断标志位
   RECEIVR_buffer=SBUF;                  //接收串口数据
      
    }

}
