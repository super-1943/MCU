/*=================================================================
==�������ɴ��ڵ���������Ƭ������Сд��ĸl��left��r(right) u(up)  ==
== d(down)�����ĸ�����                                             ==
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
sbit    LED3    =P1^3;
sbit    LED4    =P1^4;
sbit    KEY1    =P1^2;

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

/*******************************************************************************************/
void UART_init();                          //���ڳ�ʼ������
void COM_send(unsigned char );             //���ڷ��ͺ���
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
  
		  //===============NRF905������Ӧ�İ���	  
		     SetTxMode();				// Set Tx Mode
		     TxPacket();				// Transmit Tx buffer data

			//TxBuf[0] = 0xff;
			//TxBuf[1] = 0xff;
			SetRxMode();				// Set nRF905 in Rx mode
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
	while(DR||AM)               //�ȴ�... /////////////������ղ�������ͣ�� ����׼�������Լ���ַƥ��
	;	                          //�����û��ƥ���905ģ��ʱ����һ����Ҫע�͵�
	  
	    TRX_CE=1;               //����������� ����������������������������������������������������

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
// �������ƣ� UART_init()���ڳ�ʼ������
// �������ܣ� ��ϵͳʱ��Ϊ11.059MHZʱ���趨���ڲ�����Ϊ9600bit/s
//             ���ڽ����ж����������жϽ�ֹ
//--------------------------------------------------------------------------------------------------
void UART_init()
{
                         //��ʼ�����пںͲ����ʷ�����
SCON =0x50;              //ѡ�񴮿ڹ�����ʽ1���򿪽������� sm0=0,sm1=1,sm2=0,ren=1,tb8,rb8,ti,ri
TMOD =0x20;              //��ʱ��1�����ڷ�ʽ2����ʱ��0�����ڷ�ʽ1
TH1 =(0xff-5);           //ʵ�ֲ�����9600��ϵͳʱ��11.0592MHZ��8λ�������Զ���װ
PCON = 0x80;             //SMOD=1;
TR1 =1;                  //������ʱ��T1
ET1 =0;
ES=1;                    //�����п��ж�
PS=1;                    //��ƴ��п��ж����ȼ�
EA =1;                   //��Ƭ���ж�����
}
//------------------------------------------------------------
void COM_send(unsigned char var)
{
                                            
    SBUF= var;
    while(!TI)   //�ȴ��������,������Ϻ���һ
	;
    TI=0;        //��λ�����жϱ�־   
    RECEIVR_buffer=0;

}
//--------------------------------------------------------------
//--------------------------------------------------------------------------------------------------
// �������ƣ� com_interrup()���ڽ����жϴ�����
// �������ܣ� ���հ�����ʼλ'S'���ڵ�ʮλ���ݵ����ݻ�����
//--------------------------------------------------------------------------------------------------
void com_interrupt(void) interrupt 4 using 3
{
   
   if(RI)                                   //��������ж�
   {  
      RI=0;                                 //����жϱ�־λ
   RECEIVR_buffer=SBUF;                  //���մ�������
      
    }

}
