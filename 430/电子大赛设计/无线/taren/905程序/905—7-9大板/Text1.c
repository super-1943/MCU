
#include <at89x52.h>
#include <intrins.h>
#include "7219.h"
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
uchar tf,timer=0,dig1=0,dig2=0,dig3=0,dig4=0;
/*******************************************************************************************/
uchar bdata DATA_BUF;
sbit	flag	=DATA_BUF^7;
sbit	flag1	=DATA_BUF^0;
/*******************************************************************************************/
sbit	TX_EN	=P3^5;               //����ʹ�ܣ�����Ч
sbit	TRX_CE	=P2^4;               //TRX_CE���ͽ���ʹ��  ����Ч
sbit	PWR_UP	=P3^6;               //�ϵ�     
sbit	MISO	=P2^1;               //spi���
sbit	MOSI	=P2^6;               //spi����
sbit	SCK		=P2^0;               //spiʱ��
sbit	CSN		=P2^5;               //spiƬѡ

sbit	AM		=P2^2;               //AM ��ַƥ�䣬�ܵ���Ч��ַ���ø�
sbit	DR		=P2^7;               //����׼������
sbit	CD		=P3^7;               //�ز���⣬��⵽Ƶ����ͬ���ز�ʱ���ø�

sbit    LED1    =P1^0; 
sbit    LED2    =P1^1;
sbit    KEY1    =P1^2;
sbit    KEY2    =P1^3;

/*******************************************************************************************/
void Config905(void);			// Config nRF905 module����NRF905ģʽ
void SetTxMode(void);			// Set nRF905 in Tx mode
void SetRxMode(void);			// Set nRF905 in Rx mode
void TxPacket(void);			// Send data by nRF905
void RxPacket(void);			// Recive data by nRF905
void SpiWrite(uchar);			// Write data to nRF905
uchar SpiRead(void);			// Read data to nRF905
void Delay(uchar n);			// Delay 100us
void TxData (uchar x);			// Send key_value to CRT display
void initial_IO();             //io�ڳ�ʼ��
void initial_TM() ;
/*******************************************************************************************/
void Delay(uchar n)
{
	uint i;
	while(n--)
	for(i=0;i<80;i++);	
}

void main()
{
   initial_7219();               //7219��ʼ��
   initial_IO();                  //io��ʼ��
   initial_TM();                  //ʱ�ӳ�ʼ��
    //================NRF905��ʼ��
	CSN=1;						// Spi 	disable						
	SCK=0;						// Spi clock line init high
	DR=1;						// Init DR for input
	AM=1;						// Init AM for input
	PWR_UP=1;					// nRF905 power on
	TRX_CE=0;					// Set nRF905 in standby mode
	TX_EN=0;					// set radio in Rx mode	

	//================
	Config905();				// Config nRF905 module
	TxBuf[0] = 1;
	TxBuf[1] = 1;
	SetTxMode();				// Set Tx Mode
	TxPacket();				// Transmit Tx buffer data
	LED1 = 0;
	LED2 = 0;

	Delay(500);				// delay for led light	
	LED1 = 1;
	LED2 = 1;
	TxBuf[0] = 0xff;
	TxBuf[1] = 0xff;

					// led close
	SetRxMode();				// Set nRF905 in Rx mode

while(1)
{

    send(4,dig4);
	 //=====================�Ӽ��̻������
	LED2=CD;         //�ز����

		   if(KEY1 ==0 )
		   Delay(1);
           if(KEY1 ==0 )
	      { LED1 = 0; TxBuf[0] = 1 ;tf = 1 ; }
		   

	   if (tf==1)
	     {	
		
		  //===============NRF905������Ӧ�İ���	  
		     SetTxMode();				// Set Tx Mode
		     TxPacket();				// Transmit Tx buffer data
			TxBuf[0] = 0xff;
			TxBuf[1] = 0xff;
			SetRxMode();				// Set nRF905 in Rx mode
			tf=0;
			Delay(500);
			LED1 = 1;
		
		  }

         //=====================�ȴ�NRF905����
	   if (DR)			// If recive data ready...   ����׼������
	   RxPacket();			// ... recive data

}

}
/*******************************************************************************************/
void Config905(void)
{
	uchar i;					
	CSN=0;						// Spi enable for write a spi command
	SpiWrite(WC);				// Write config commandд����������
	for (i=0;i<RxTxConf.n;i++)	// Write configration words  д��������
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
	while(DR||AM);	
	   if(RxBuf[0] == 1) 
	   {
	     LED1 = 0 ;
		 if(dig4<9)
		 dig4++;
		 else 
		 dig4=0;
		 
		}
	  
	Delay(500);					// ...light led
      LED1 = 1 ;
	  								
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

void initial_IO()
{
    EA=1;
	EX0=1;   //�ⲿ�жϿ�
	IT0=1;   //�½��ش���
	EX1=1;
	IT1=1;

	ET0=1;// ��ʱ��0�ж�
}
void initial_TM()   //ʱ�ӳ�ʼ��
{
 
  TF0=0;  //���ʼʱ�ӱ�־λ
  TR0=0;  //�ر�ʱ��
  TMOD=0x01;  //ʱ��0��������ʽ1��
  TH0=(65536-50000)/256;
  TL0=(65526-50000)%256;   //50ms
  TR0=1;
} 

void T0_inter() interrupt 1
{
   timer++;
   if(timer==20)
    if(dig1<9)
      {dig1++;timer=0;}
    	  else if(dig2<9)
	         {dig1=0;dig2++;timer=0;}
			  else if(dig3<9)
			     {dig2=0;dig3++;timer=0;}
				    else
					  {dig1=0;dig2=0;dig3=0;timer=0;}
	 send(1,dig1);
	 send(2,dig2);
	 send(3,dig3);

	initial_TM();
	
} 

void EX0_inter()  interrupt 0
{
  if  (dig4<9)
     dig4++;
	 else 
	   dig4=0;
	 send(4,dig4);
}

void EX1_inter()  interrupt 2
{
  if  (dig4>0)
     dig4--;
	 else 
	   dig4=9;
	   send(4,dig4);
}
