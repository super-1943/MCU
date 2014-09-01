
#include <at89x51.h>
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
uchar tf1,tf2,tf3,tf4;                   //��־λ
/*******************************************************************************************/
uchar bdata DATA_BUF;                    //???????????????????????????????
sbit	flag	=DATA_BUF^7;
sbit	flag1	=DATA_BUF^0;
/*******************************************************************************************/
sbit	TX_EN	=P2^0;               //����ʹ�ܣ�����Ч
sbit	TRX_CE	=P2^6;               //TRX_CE���ͽ���ʹ��  ����Ч
sbit	PWR_UP	=P2^1;               //�ϵ�     
sbit	MISO	=P3^6;               //spi���
sbit	MOSI	=P2^4;               //spi����
sbit	SCK		=P3^7;               //spiʱ��
sbit	CSN		=P2^5;               //spiƬѡ

sbit	AM		=P3^5;               //AM ��ַƥ�䣬�ܵ���Ч��ַ���ø�
sbit	DR		=P2^3;               //����׼������
sbit	CD		=P2^2;               //�ز���⣬��⵽Ƶ����ͬ���ز�ʱ���ø�

sbit    LED1    =P1^0; 
sbit    LED2    =P1^1;
sbit    KEY1    =P1^4;
sbit    KEY2    =P1^5;
sbit    KEY3    =P1^6;
sbit    KEY4    =P1^7;


/*******************************************************************************************/


void Config905(void);			// Config nRF905 module����NRF905ģʽ
void SetTxMode(void);			// Set nRF905 in Tx mode
void SetRxMode(void);			// Set nRF905 in Rx mode
void TxPacket(void);			// Send data by nRF905
void RxPacket(void);			// Recive data by nRF905
void SpiWrite(uchar);			// Write data to nRF905
uchar SpiRead(void);			// Read data to nRF905
void Delay(uchar n);			// Delay 100us

/*******************************************************************************************/
void Delay(uchar n)
{
	uint i;
	while(n--)
	for(i=0;i<80;i++);	
}

void main()
{


//================
	Config905();				  // Config nRF905 module
	LED2 = CD;
	TxBuf[0] = 1;                 //unchar
	TxBuf[1] = 1;
    TxBuf[2] = 1;
    TxBuf[3] = 1;
	SetTxMode();				  // Set Tx Mode
	TxPacket();				      // Transmit Tx buffer data  ����
	LED1 = 0;
	

	Delay(500);			    	  // delay for led light	
	LED1 = 1;
	LED2 = 1;
	TxBuf[0] = 0xff;
	TxBuf[1] = 0xff;
    TxBuf[2] = 0xff;
    TxBuf[3] = 0xff;

					            // led close
	SetRxMode();				// Set nRF905 in Rx mode
    //================NRF905��ʼ��
	CSN=1;						// Spi 	disable						
	SCK=0;						// Spi clock line init high
	DR=1;						// Init DR for input
	AM=1;						// Init AM for input
	PWR_UP=1;					// nRF905 power on
	TRX_CE=0;					// Set nRF905 in standby mode
	TX_EN=0;					// set radio in Rx mode	

	 while(1)
{         
	      
                    //	Config905();				// Config nRF905 module
           LED2=CD;
		   if(KEY1 ==0 ) {	LED1 = 0; TxBuf[0] = 1 ;tf1 = 1 ; }
		   if(KEY2 ==0 ) {	LED1 = 0; TxBuf[1] = 1 ;tf2 = 1 ; }
		   if(KEY3 ==0 ) {	LED1 = 0; TxBuf[2] = 1 ;tf3 = 1 ; }
		   if(KEY4 ==0 ) {	LED1 = 0; TxBuf[3] = 1 ;tf4 = 1 ; }


	   if (tf1==1)
	     {	
		
		                                //===============NRF905������Ӧ�İ���	  
		    SetTxMode();				// Set Tx Mode
		    TxPacket();			    	// Transmit Tx buffer data
			TxBuf[0] = 0xff;
			//TxBuf[1] = 0xff;
			SetRxMode();				// Set nRF905 in Rx mode
			tf1=0;
			Delay(500);
			LED1 = 1;
		
		  }

		  if (tf2==1)
	     {	
		
		                                //===============NRF905������Ӧ�İ���	  
		    SetTxMode();				// Set Tx Mode
		    TxPacket();			    	// Transmit Tx buffer data
			TxBuf[1] = 0xff;
			//TxBuf[1] = 0xff;
			SetRxMode();				// Set nRF905 in Rx mode
			tf2=0;
			Delay(500);
			LED1 = 1;
		
		  }

		  if (tf3==1)
	     {	
		
		                                //===============NRF905������Ӧ�İ���	  
		    SetTxMode();				// Set Tx Mode
		    TxPacket();			    	// Transmit Tx buffer data
			TxBuf[2] = 0xff;
			//TxBuf[1] = 0xff;
			SetRxMode();				// Set nRF905 in Rx mode
			tf3=0;
			Delay(500);
			LED1 = 1;
		
		  }

		  if (tf4==1)
	     {	
		
		                                //===============NRF905������Ӧ�İ���	  
		    SetTxMode();				// Set Tx Mode
		    TxPacket();			    	// Transmit Tx buffer data
			TxBuf[3] = 0xff;
			//TxBuf[1] = 0xff;
			SetRxMode();				// Set nRF905 in Rx mode
			tf4=0;
			Delay(500);
			LED1 = 1;
		
		  }


                           //=====================�ȴ�NRF905����
	   if (DR)			   // If recive data ready... 
	   RxPacket();		   // ... recive data

	  
	  

}

}
/*******************************************************************************************/
/*******************************************************************************************/
//function Config905();
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
//function SpiWrite();
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
//function SpiRead();
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
//function TxPacket();
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
	TRX_CE=1;					// Set TRX_CE high,start Tx data transmission��������
	Delay(1);					// while (DR!=1);
	TRX_CE=0;					// Set TRX_CE low
}
/*******************************************************************************************/
//function RxPacket();
/*******************************************************************************************/
void RxPacket(void)
{
	uchar i;	
	TRX_CE=0;					// Set nRF905 in standby mode	
	CSN=0;						// Spi enable for write a spi command
	SpiWrite(RRP);				// Read payload command	
	for (i=0;i<32;i++)
	{
		RxBuf[i]=SpiRead();	 	 // Read data and save to buffer		
	}
	CSN=1;						 // Disable spi
	while(DR||AM)                //�ȴ�
      ;	
                                 //	P0=	RxBuf[0];				// Buffer[0] output from P0 port...
	TRX_CE=1;
	                            //xx=(RxBuf[0]>>4)&0x0f;
	                            //TxData(xx);
	                            //=====================
	   if(RxBuf[0] == 1||RxBuf[1] == 1||RxBuf[2] == 1||RxBuf[3] == 1) LED1 = 0 ;
	   
	  
	Delay(500);					// ...light led
                                //	P0=0xff;					// Close led
      LED1 = 1 ;
	 							
}
/*******************************************************************************************/
//function SetTxMode();
/*******************************************************************************************/
void SetTxMode(void)				 //����ģʽ��ʼ��
{	
	TX_EN=1;
	TRX_CE=0;
	Delay(1); 					// delay for mode change(>=650us)
}				
/*******************************************************************************************/
//function SetRxMode();
/*******************************************************************************************/
void SetRxMode(void)
{
	TX_EN=0;
	TRX_CE=1;
	Delay(1); 					// delay for mode change(>=650us)				
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
   	LED2=~CD;         //�ز����
 	 initial_TM();
	
} 
