//ICC-AVR application builder : 2007-8-11 20:37:32
// Target : M16
// Crystal: 8.0000Mhz
#include <iom16v.h>
#include <macros.h>
#define uint  unsigned int
#define uchar unsigned char
//---------------------------------ģʽ���ƶ���---------------------------------
//#define  nrf905_TX_EN	  PB0	    //���1
#define   Hign_nrf905_TX_EN    PORTB |= (1 << PB0);   
#define   Low_nrf905_TX_EN     PORTB &= ~(1 << PB0); 
//#define  nrf905_TRX_CE  PD5 	    //���1
#define   Hign_nrf905_TRX_CE    PORTD |= (1 << PD5);   
#define   Low_nrf905_TRX_CE     PORTD &= ~(1 << PD5); 
//#define  nrf905_PWR     PB1 	    //���1
#define   Hign_nrf905_PWR    PORTB |= (1 << PB1);   
#define   Low_nrf905_PWR     PORTB &= ~(1 << PB1); 
//--------------------------------NRF905-SPI�ڽӿڶ���--------------------------
//#define  nrf905_MISO	  PB6   	//����0
//#define  nrf905_MOSI    PB5	    //���1
//#define  nrf905_SCK     PB7	    //���1
#define   Low_nrf905_SCK     PORTB &= ~(1 << PB7); 
//#define  nrf905_CSN     PB4		//���1		
#define   Hign_nrf905_CSN    PORTB |= (1 << PB4);   
#define   Low_nrf905_CSN     PORTB &= ~(1 << PB4); 						
//-------------------------------NRF905״̬�����-------------------------------
//#define  nrf905_CD      PD4	    //����0
#define   Hign_nrf905_CD    PORTD |= (1 << PD4);   
#define   Low_nrf905_CD     PORTD &= ~(1 << PD4); 
#define   Read_nrf905_CD    PINB & (1 << PD4);
//#define  nrf905_AM      PB3	    //����0
#define   Hign_nrf905_AM    PORTB |= (1 << PB3);   
#define   Low_nrf905_AM     PORTB &= ~(1 << PB3); 
#define   Read_nrf905_AM    PINB & (1 << PB3);
//#define  nrf905_DR      PB2  		//����0
#define   Hign_nrf905_DR     PORTB |= (1 << PB2);   
#define   Low_nrf905_DR     PORTB &= ~(1 << PB2); 
#define   Read_nrf905_DR    PINB & (1 << PB2);   
//------------------------------LCD״̬�����-----------------------------------
//#define LCD_CS           PC7  	//1-out
//#define   Out_LCD_CS       DDRC |= (1 << PC7);
#define   Hign_LCD_CS      PORTC |= (1 << PC7);   
#define   Low_LCD_CS       PORTC &= ~(1 << PC7); 
//#define LCD_RESET         PC6 	//1-out
//#define   Out_CD_RESET      DDRC |= (1 << PC6);
#define   Hign_LCD_RESET    PORTC |= (1 << PC6);   
#define   Low_LCD_RESET     PORTC &= ~(1 << PC6); 
//#define LCD_RS           PC5 	//1-out
//#define   Out_LCD_RS       DDRC |= (1 << PC5);
#define   Hign_LCD_RS      PORTC |= (1 << PC5);   
#define   Low_LCD_RS       PORTC &= ~(1 << PC5); 
//#define LCD_SCL        PC4 	//1-out
//#define   Out_LCD_SCL      DDRC |= (1 << PC4); 
#define   Hign_LCD_SCL     PORTC |= (1 << PC4);   
#define   Low_LCD_SCL      PORTC &= ~(1 << PC4);
//#define LCD_SI         PC3  	//1-ou
//#define   Out_LCD_SI      DDRC |= (1 << PC3); 
#define   Hign_LCD_SI    PORTC |= (1 << PC3);   
#define   Low_LCD_SI     PORTC &= ~(1 << PC3);
//-------------------------------BELL������-------------------------------------
#define   Hign_BELL  PORTD |= (1 << PD6);   
#define   Low_BELL     PORTD &= ~(1 << PD6); 
//-------------------------------JDQ�̵���--------------------------------------
#define   Hign_JDQ  PORTD |= (1 << PD7)
#define   Low_JDQ     PORTD &= ~(1 << PD7)
//------------------------LCD�ֿ�---------------------------------------------
const uchar ling16[16]= 
{0x00,0xE0,0xF0,0x08,0x08,0x18,0xF0,0xC0,0x00,0x0F,0x1F,0x20,0x20,0x30,0x1F,0x07};//0
const uchar yi16[16]= 
{0x00,0x00,0x10,0xF0,0xF8,0x00,0x00,0x00,0x00,0x00,0x20,0x3F,0x3F,0x20,0x20,0x00};//1
const uchar er16[16]= 
{0x00,0x70,0x78,0x08,0x08,0x98,0xF8,0x70,0x00,0x30,0x38,0x34,0x32,0x31,0x30,0x38};//2
const uchar san16[16]=
{0x00,0x30,0x38,0x88,0x88,0xF8,0x70,0x00,0x00,0x18,0x38,0x21,0x21,0x33,0x1E,0x0C};//3
const uchar si16[16]= 
{0x00,0x00,0x80,0x60,0x30,0xF8,0xF8,0x00,0x00,0x06,0x05,0x24,0x24,0x3F,0x3F,0x24};//4
const uchar wu16[16]= 
{0x00,0xF0,0xF8,0x88,0x88,0x88,0x08,0x00,0x00,0x19,0x39,0x20,0x20,0x31,0x1F,0x06};//5
const uchar liu16[16]= 
{0x00,0xE0,0xF0,0x88,0x88,0x98,0x98,0x00,0x00,0x0F,0x3F,0x20,0x20,0x20,0x1F,0x0E};//6
const uchar qi16[16]= 
{0x00,0x38,0x18,0x08,0x88,0xE8,0x38,0x08,0x00,0x00,0x00,0x3E,0x3F,0x00,0x00,0x00};//7
const uchar ba16[16]= 
{0x00,0x70,0xF8,0x8C,0x8C,0x8C,0xF8,0x70,0x00,0x0E,0x1F,0x31,0x31,0x33,0x1F,0x0E};//8
const uchar jiu16[16]= 
{0x00,0xF0,0xF8,0x08,0x08,0x18,0xF8,0xF0,0x00,0x19,0x33,0x32,0x32,0x3B,0x1F,0x0F};//9
const uchar xsdian[16]=
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x30,0x30,0x00};//.

//-------------------------------------------------------------------------------
const uchar wu[32]=															 	 //��
{0x00,0x40,0x42,0x42,0x42,0x42,0xFE,0x42,0xC2,0x42,0x43,0x42,0x60,0x40,0x00,0x00,
0x00,0x80,0x40,0x20,0x18,0x06,0x01,0x00,0x3F,0x40,0x40,0x40,0x40,0x40,0x70,0x00};
const uchar xian[32]=															 //��
{0x00,0x20,0x30,0xAC,0x63,0x20,0x30,0x20,0x20,0xFF,0x90,0x92,0x94,0xD0,0x80,0x00,
0x20,0x62,0x23,0x12,0x12,0x12,0x41,0x41,0x21,0x17,0x18,0x24,0x42,0x80,0xE0,0x00};
const uchar yao[32]=															 //ң
{0x40,0x42,0x44,0xCC,0x00,0x42,0x36,0x2A,0x22,0xFE,0x21,0x29,0x25,0x80,0x00,0x00,
0x00,0x40,0x20,0x1F,0x21,0x41,0x5D,0x49,0x49,0x4F,0x49,0x49,0x5D,0x61,0x21,0x00};
const uchar kong[32]=															 //��
{0x10,0x10,0x10,0xFF,0x90,0x50,0x0C,0x44,0x24,0x15,0x06,0x14,0x24,0x54,0x0C,0x00,
0x02,0x42,0x81,0x7F,0x00,0x40,0x42,0x42,0x42,0x42,0x7E,0x42,0x43,0x62,0x40,0x00};
const uchar xi[32]=															 	 //ϵ
{0x00,0x02,0x22,0x22,0x32,0x2E,0xA2,0x62,0x22,0x22,0x91,0x09,0x01,0x00,0x00,0x00,
0x00,0x00,0x42,0x22,0x1A,0x43,0x82,0x7E,0x02,0x02,0x0A,0x13,0x66,0x00,0x00,0x00};
const uchar tong[32]=															//ͳ
{0x20,0x30,0xAC,0x63,0x30,0x88,0xC8,0xA8,0x99,0x8E,0x88,0xA8,0xCC,0x88,0x00,0x00,
0x22,0x67,0x22,0x12,0x92,0x40,0x30,0x0F,0x00,0x00,0x3F,0x40,0x40,0x41,0x70,0x00};
const uchar ji[32]=																//��											//��
{0x20,0x30,0xAC,0x63,0x30,0x00,0xFE,0x88,0x90,0xA0,0xFF,0xA0,0x90,0x98,0x00,0x00,
0x22,0x67,0x22,0x12,0x12,0x00,0x7F,0x48,0x44,0x42,0x7F,0x42,0x44,0x6C,0x40,0x00};
const uchar dian[32]=															//��
{0x00,0xF8,0x48,0x48,0x48,0x48,0xFF,0x48,0x48,0x48,0x48,0xFC,0x08,0x00,0x00,0x00,
0x00,0x07,0x02,0x02,0x02,0x02,0x3F,0x42,0x42,0x42,0x42,0x47,0x40,0x70,0x00,0x00};
const uchar qi[32]=																//��
{0x80,0x80,0x9F,0x91,0x91,0x91,0x9F,0xE0,0x9F,0x91,0xB1,0xD1,0x9F,0xC0,0x80,0x00,
0x08,0x08,0xFC,0x8C,0x8A,0x8A,0xF9,0x00,0xF9,0x8A,0x8A,0x8C,0xFC,0x08,0x08,0x00};
const uchar kai[32]=															//��
{0x80,0x82,0x82,0x82,0xFE,0x82,0x82,0x82,0x82,0x82,0xFE,0x82,0x83,0xC2,0x80,0x00,
0x00,0x80,0x40,0x30,0x0F,0x00,0x00,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0x00,0x00};
const uchar feng[32]=															//��
{0x00,0xF0,0x10,0xFF,0x10,0xF8,0x90,0x88,0x4F,0x54,0xA4,0x54,0x4C,0xC4,0x40,0x00,
0x20,0x67,0x22,0x1F,0x12,0x3B,0x00,0x14,0x15,0x15,0xFF,0x15,0x15,0x14,0x00,0x00};
const uchar ming[32]=															//��
{0x00,0xFC,0x44,0x44,0x44,0xFE,0x04,0x00,0xFE,0x22,0x22,0x22,0x22,0xFF,0x02,0x00,
0x00,0x0F,0x04,0x04,0x04,0x8F,0x40,0x30,0x0F,0x02,0x02,0x42,0x82,0x7F,0x00,0x00};
const uchar xiang[32]=																//��
{0x00,0xFC,0x04,0x04,0xFE,0x04,0xF8,0x08,0xCC,0x4A,0x49,0xC8,0x08,0xFC,0x08,0x00,
0x00,0x1F,0x08,0x08,0x1F,0x00,0xFF,0x00,0x0F,0x08,0x08,0x4F,0x80,0x7F,0x00,0x00};
//----------------------------------NRF905-SPIָ��------------------------------
#define WC	0x00
#define RRC	0x10
#define WTP	0x20
#define RTP	0x21
#define WTA	0x22
#define RTA	0x23
#define RRP	0x24
//---------------------------------��������-------------------------------------
uchar TxRxBuffer[4];
//----------------------------------���յ�ַ------------------------------------
uchar TxAddress[4]={0xcc,0xcc,0xcc,0xcc };    
//------------------------------------------------------------------------------
uchar count1 ,count2;
//----------------------------------�Ĵ�������----------------------------------
uchar RFConf[11]=
{
  0x00,                            //��������//
  0x4c,                           //CH_NO,����Ƶ����430MHZ
  0x0C,                          //�������Ϊ10db,���ط����ڵ�Ϊ����ģʽ
  0x44,                         //��ַ������ã�Ϊ4�ֽ�
  0x04,0x04,                   //���շ�����Ч���ݳ���Ϊ32�ֽ�
  0xCC,0xCC,0xCC,0xCC,        //���յ�ַ
  0x58,                      //CRC����8λCRCУ�飬�ⲿʱ���źŲ�ʹ�ܣ�16M����
};
//----------------------------------NRF905��������------------------------------
void Delay(uint x);						       //��ʱ�ӳ���																							
void Spi_initial();                            //SPI��ʼ��
uchar SpiReadSpiWrite(unsigned char cData);    //SPI��д�ӳ���
void system_Init(void);		   				   //ϵͳ��ʼ��
void Config905(void);						   //NRF905��ʼ���ӳ���
void TxPacket(void);						
void SetTxMode(void);						   //���ݷ���
void SetRxMode(void);						   //
void TX(void);
unsigned char CheckDR(void);
void RxPacket(void);
void  RX(void);
//-------------------------------���ں�������-----------------------------------
void StartUART(void);
void R_S_Byte(uchar R_Byte);
//-------------------------------LCD��������------------------------------------
void LCD_Delay(uint time);
void Lcd_init(void);
void Lcd_Write_Data(uchar DATA) ;
void Lcd_Write_command(uchar COMMAND);
void Lcd_CURSOR(uchar add_page,uchar add_col)  ;
void Lcd_Clear(void) ;
void dis_1616hz(uchar x1,uchar x2,uchar row,const uchar hz[]);
void dis_168hz(uchar x1,uchar row,const uchar hz[]);
void LCDtime();
//----------------------------------100us��ʱ�ӳ���-----------------------------
void Delay(uint x)
{
	uint i;
	while(x--)
	for(i=0;i<80;i++);
}
//----------------------------------SPI��ʼ��-----------------------------------
void Spi_initial()
{
	SPCR   = (1<<SPE)|(1<<MSTR)|(0<<CPOL)|(0<<SPR0);// ����ģʽ��fck/16, SPI��ʽ0
}
//---------------------------------SPI��д����----------------------------------	
uchar SpiReadSpiWrite(unsigned char cData)
{
	SPDR = cData;
	while(!(SPSR & (1<<SPIF) ))  // �ȴ�SPI�������
	{};			
	return SPDR;
}
//--------------------------------ϵͳ״̬��ʼ��--------------------------------
void system_Init(void)			
{

   	Hign_nrf905_CSN;			// SPIʹ��
	Low_nrf905_SCK;				
	Low_nrf905_DR;				// DR=0
	Low_nrf905_AM;				// AM=0
	Low_nrf905_CD;				// CD=0
	Hign_nrf905_PWR;		    // PWR=1
	Low_nrf905_TRX_CE;			// nrf905_TRX_CE=0
	Low_nrf905_TX_EN ;			// nrf905_TX_EN=0
}
//--------------------------------NRF905�Ĵ�����ʼ������------------------------
void Config905(void)
{
	uchar i;
	Low_nrf905_CSN;				//SPIʹ��											
	Delay(1);				   
	for (i=0;i<11;i++)			//�NRF905������
	{
	 SpiReadSpiWrite(RFConf[i]);
	}
	Hign_nrf905_CSN;					// Disable Spi
}
//--------------------------------NRF905�������ݴ��----------------------------
void TxPacket(void)
{
	uchar i;
	Low_nrf905_CSN;		   				// ʹ��Spi�������nrf905���ж�д����
	Delay(1);
	SpiReadSpiWrite(WTP);				// д����ǰ��дд��������
	for (i=0;i<32;i++)
	{
	SpiReadSpiWrite(TxRxBuffer[i]);		// �����͵�32�ֽ�����
	}						
	Hign_nrf905_CSN;
	Delay(1);							// �ر�Spi���������nrf905���ж�д����
	Low_nrf905_CSN;						// ʹ��Spi
	SpiReadSpiWrite(WTA);				// д��ַǰ������д��ַ����
	for (i=0;i<4;i++)					// д��4 bytes ���յ�ַ
	{
	SpiReadSpiWrite(TxAddress[i]);
	}
	Hign_nrf905_CSN;					// �ر�Spi
	Hign_nrf905_TRX_CE;					// Set TRX_CE high,start Tx data transmission
	Delay(1);							// �ȴ�DR���
	Low_nrf905_TRX_CE;					// ����TRX_CE=0
}
//------------------------------���÷���ģʽ------------------------------------
void SetTxMode(void)
{
	Low_nrf905_TRX_CE;				//
	Hign_nrf905_TX_EN;				//����ʹ��
	Delay(2); 				// delay for mode change(>=650us)
}
//------------------------------���ý���ģʽ����--------------------------------
void SetRxMode(void)
{
	Low_nrf905_TX_EN;
	Hign_nrf905_TRX_CE;
	Delay(10); 					// delay for mode change(>=650us)
}
//------------------------------��������----------------------------------------
void TX(void)
{
     SetTxMode();	   // Set nRF905 in Tx mode
	 TxPacket();			   // Send data by nRF905
}
//-----------------------------�ж��Ƿ��յ�����---------------------------------
unsigned char CheckDR(void)		//����Ƿ��������ݴ��� 
{
	if (PINB & (1 << PB2))
	{
		return 1; 	 	  		//�յ�����
	}
	else
	{
		return 0;
	}
}
//-----------------------------------���������ݰ�-------------------------------
void RxPacket(void)							//������
{
	uchar i;
    Low_nrf905_TRX_CE;
	Low_nrf905_CSN;						    // ʹ��SPI
    Delay(1);
	SpiReadSpiWrite(RRP);				   // д�����ݽ��ջ�������������
	for (i = 0 ;i < 4 ;i++)
	{   
	TxRxBuffer[i]=SpiReadSpiWrite(0);	  // ��ȡ���ݽ��ջ���������       
	}
	Hign_nrf905_CSN;
    Delay(2);                            //
	Hign_nrf905_TRX_CE;							
}
//--------------------------------���ý���ģʽ----------------------------------
void  RX(void)
{
    SetRxMode();			          //����NRF905����ģʽ
    while (CheckDR()==0);	         //�ȴ��������
	RxPacket();                     //��ȡ�������ݻ�����
	Delay(10);
}
//******************************************************************************
//����ΪLCD����
//******************************************************************************
//------------------------------------------------------------------------------
void LCD_Delay(uint time)
{
	uint i;
	for(i=time;i>0;i--);
}
//---------------------------LCD��ʼ��---------------------------------------
void Lcd_init(void)
{
 	DDRC=0xF8;
	//ASSR &= ~(1 <<AS2); 
	Hign_LCD_CS;
	Low_LCD_RESET;	 	//Ӳ��λ
	LCD_Delay(50);
	Hign_LCD_RESET;			
	////////////////////////////////////////////////////////
	Lcd_Write_command(0xe2);	//��λRESet:initialize the internal functions
	LCD_Delay(100);
	Lcd_Write_command(0xae);	//DISPLAY OFF 
	Lcd_Write_command(0xa1);	//ADC SELECT ON
	Lcd_Write_command(0xc0);	//SHL SELECT COM64-COM1
	Lcd_Write_command(0xa2);	//SET LCD BIAS(1/9)
	//////////////////////////////////////////////////////
	Lcd_Write_command(0x2c);//SET POWER CONTROL(VC=1)
	Lcd_Write_command(0x2e);	//SET POWER CONTROL(VR=1)
	Lcd_Write_command(0x2f);	//SET POWER CONTROL(VF=1)
	////////////////////////////////////////////////////////
	Lcd_Write_command(0x26);	//REGULATOR RESISTOR SELECT(R2 R1 R0)=110
	Lcd_Write_command(0x81);	//SET REFERENCE VOLTAGE MODE	
	Lcd_Write_command(0x3f);	//SET REFERENCE VOLTAGE REGISTER 2ch
	//////////////////////////////////////////////////////
	Lcd_Write_command(0x7f);	//START DISPLAY LINE(COM1)  ��ʼ��
	//////////////////////////////////////////////////////
	Lcd_Write_command(0xe0);	//д������ʱ��ַ�Զ���1��������ʱ����
	//////////////////////////////////////////////////////////
	Lcd_Write_command(0xaf);	//DISPLAY ON  
}
//--------------------------------LCDд���ݺ���---------------------------------
void Lcd_Write_Data(uchar DATA)              //дһ���ֽڣ��ټ�һ�У�������һҳ
{                                            //����һҳ����һ��һ�е�д
	int i,temp;
	temp=DATA;
	Low_LCD_RS;		
	Hign_LCD_CS;
	Hign_LCD_SCL;
	LCD_Delay(1);
	Low_LCD_CS;
	Low_LCD_SCL;
	Hign_LCD_RS;		//RS=1 ʱΪд����
	LCD_Delay(1);
	for(i=0;i<8;i++)
	{
		Low_LCD_SCL;
		if(temp&0x80)
		{
		Hign_LCD_SI;
		}
		else
		{
		Low_LCD_SI;
		}
		LCD_Delay(1);
		temp=temp<<1;
		Hign_LCD_SCL;
		LCD_Delay(1);
		Low_LCD_SCL;
	}
	Low_LCD_RS;
	Hign_LCD_CS;    //��cs��0��Ȼ������ݶ��͵�����׼���ã����������أ���������ƬѡcsΪ1	
}
//---------------------------------LCDд�����--------------------------------
void Lcd_Write_command(uchar COMMAND)
{
	uchar i,temp;
	temp = COMMAND;
	Hign_LCD_RS;		
	Hign_LCD_CS;
	Hign_LCD_SCL;
	LCD_Delay(1);
	Low_LCD_RS;		//RS=0 Ϊд����
	Low_LCD_CS;
	Low_LCD_SCL;
	LCD_Delay(1);
	for(i=0;i<8;i++)
	{
		Low_LCD_SCL;
		if(temp&0x80)
		{
		Hign_LCD_SI;
		}
		else
		{
		Low_LCD_SI;
		}
		temp=temp<<1;	
		LCD_Delay(1);
		Hign_LCD_SCL;
		LCD_Delay(1);
		Low_LCD_SCL;
	}
	Hign_LCD_RS;
	Hign_LCD_CS;      //����temp��ԭ����command�ľͲ������
}
//-------------------------------LCD��꺯��------------------------------------
void Lcd_CURSOR(uchar add_page,uchar add_col)               //��궨λ	//8ҳ(<0fh)�� ��128��(>0fh)
{                                                           //ÿҳ8��
	Lcd_Write_command(0xB0+(add_page&0x0f));     //+��Ϊ�ϳ�Ϊһ���ֽڣ���ʵ���ǻ�B0+0x
	Lcd_Write_command(0x10|(add_col>>4)); //Set column address MSB(10+xx)��Y7 Y6 Y5 Y4
	Lcd_Write_command(add_col&0x0f);      //Set column address LSB(00+xx)��Y3 Y2 Y1 Y0
}
//-------------------------------LCD��������------------------------------------
void Lcd_Clear(void)                         //128x64�ֽ�,ʵ����һ��Ҫ��
{	
	uchar i,j;
	for(i=0;i<9;i++)                     //>8ҳ
	{
		 Lcd_CURSOR(i,0);		
		 for(j=0;j<132;j++)          //>128��
		 {	
		 	 Lcd_CURSOR(i,j);      //���ڱ䣬���Ҳ�ڲ�ͣ�Ļ���
		 	 Lcd_Write_Data(0); //����һҳ����һ��һ�е�д00h,���ڱ�
		 }		
	}
}	
//--------------------------------LCD����---------------------------------------
void Test_LCD(void)
{	
	uchar i,j;
	for(i=0xB0;i<0xB8;i++)		//B0-B8��8ҳ
	{
		Lcd_Write_command(i);     //+��Ϊ�ϳ�Ϊһ���ֽڣ���ʵ���ǻ�B0+0x
		Lcd_Write_command(0x10); //Set column address MSB(10+xx)��Y7 Y6 Y5 Y4
		Lcd_Write_command(0x01); 
		 Lcd_CURSOR(i,0);
		 for(j=0;j<132;j++)
		 {	                        //ÿ��дһ�Σ��л��Զ���1
		 	 Lcd_CURSOR(i,j);       //���ڱ䣬���Ҳ�ڲ�ͣ�Ļ��У����½��ж�λ
		 	 Lcd_Write_Data(0x01);  //���д��f0h������4����4�㰵
		 }
		 		
	}
}
/*
//------------------------------------------------------------------------------
void dis_biankuang()			//�߿����
{	
	uchar i,j,k;
	for(i=0xB0;i<0xB8;i++)		//2ҳ16��
	{
		Lcd_Write_command(i);     	//+��Ϊ�ϳ�Ϊһ���ֽڣ���ʵ���ǻ�B0+0x
		Lcd_Write_command(0x10); 	//Set column address MSB(10+xx)��Y7 Y6 Y5 Y4
		Lcd_Write_command(0x01); 
		Lcd_CURSOR(i,0);
		 for(j=0;j<132;j++)
		 {	                        //ÿ��дһ�Σ��л��Զ���1
		 	 Lcd_CURSOR(i,j);       //�ı���λ�ã����ڱ䣬���Ҳ�ڲ�ͣ�Ļ��У����½��ж�λ
		 	 Lcd_Write_Data(0x03);  //���д��f0h������4����4�㰵
		 }
		 for(k=0xB0;k<0xB7;k++)
		 {
		 for(j=2;j<6;j++)
		 {
		  Lcd_CURSOR(k,j);       //�ı���λ�ã����ڱ䣬���Ҳ�ڲ�ͣ�Ļ��У����½��ж�λ
		  Lcd_Write_Data(0xff);
		 }
		 for(j=130;j<132;j++)
		 {
		  Lcd_CURSOR(k,j);       //�ı���λ�ã����ڱ䣬���Ҳ�ڲ�ͣ�Ļ��У����½��ж�λ
		  Lcd_Write_Data(0xff);
		 }
		 }
		 i=i+7;
		 for(j=0;j<132;j++)      
		 {	                        //ÿ��дһ�Σ��л��Զ���1
		 	 Lcd_CURSOR(i,j);       //���ڱ䣬���Ҳ�ڲ�ͣ�Ļ��У����½��ж�λ
		 	 Lcd_Write_Data(0x03);  //���д��f0h������4����4�㰵
		 }

			
	}
}
*/
//------------------------------16*16������ʾ-----------------------------------
void dis_1616hz(uchar x1,uchar x2,uchar row,const uchar hz[])			//16*16
{	
	uchar i,j;
	for(i=x1;i<x2;i++)		//2ҳ16��
	{
		Lcd_Write_command(i);     	//+��Ϊ�ϳ�Ϊһ���ֽڣ���ʵ���ǻ�B0+0x
		Lcd_Write_command(0x10); 	//Set column address MSB(10+xx)��Y7 Y6 Y5 Y4
		Lcd_Write_command(0x01); 
		Lcd_CURSOR(i,0);
		 for(j=0;j<16;j++)
		 {	                        //ÿ��дһ�Σ��л��Զ���1
		 	 Lcd_CURSOR(i,j+row);       //�ı���λ�ã����ڱ䣬���Ҳ�ڲ�ͣ�Ļ��У����½��ж�λ
		 	 Lcd_Write_Data(hz[j]);  //���д��f0h������4����4�㰵
		 }
		 i++;
		 for(j=0;j<16;j++)      
		 {	                        //ÿ��дһ�Σ��л��Զ���1
		 	 Lcd_CURSOR(i,j+row);       //���ڱ䣬���Ҳ�ڲ�ͣ�Ļ��У����½��ж�λ
		 	 Lcd_Write_Data(hz[j+16]);  //���д��f0h������4����4�㰵
		 }		
	}
}
/*------------------------------------------------------------------------------
void Dis16x16(uchar add_page, uchar add_col,const uchar *pHZ,uchar state)
{
    uchar i;
    Lcd_CURSOR(add_page, add_col);
    for(i=0;i<16;i++) 
    {                                                //һ������2�У�16�У�32���ֽ�
    	if(state)                                    //state(ѡ������)
    	{
    		Lcd_Write_Data(pHZ[i]);              //��궨λ�������п�ʼд16�е���ģ���ݣ�����������
    	}
    //	else
    //	{
    	    	Lcd_Write_Data(~pHZ[i]);	    //����б䣬���Ҳ�᲻ͣ�Ļ��У�������ֻ��ҳ������
    //	}                                           //�ǻ���һ��һ�е�д�𣿣�����(дһ�λ��Զ���1�У�
     // }                                             //����ʱ�ڲ�ͣ�Ļ���
    Lcd_CURSOR(add_page-1, add_col);                //�ӻ�����У�ֻ��ȡģ����ͬ
    for(;i<32;i++)
    {  
    	if(state)
    	{
    		Lcd_Write_Data(pHZ[i]);
    	}
    //	else
    //	{
    	//	Lcd_Write_Data(~pHZ[i]);
    	}
    }
}
*/
//-----------------------------16*8������ʾ-------------------------------------
void dis_168hz(uchar x1,uchar row,const uchar hz[])			//16*16
{	
	uchar a,b,j;
	a=x1;
	b=x1+1;
		Lcd_Write_command(a);     	//+��Ϊ�ϳ�Ϊһ���ֽڣ���ʵ���ǻ�B0+0x
		Lcd_Write_command(0x10); 	//Set column address MSB(10+xx)��Y7 Y6 Y5 Y4
		Lcd_Write_command(0x01); 
		Lcd_CURSOR(a,0);
		 for(j=0;j<8;j++)
		 {	                        //ÿ��дһ�Σ��л��Զ���1
		 	 Lcd_CURSOR(a,j+row);       //�ı���λ�ã����ڱ䣬���Ҳ�ڲ�ͣ�Ļ��У����½��ж�λ
		 	 Lcd_Write_Data(hz[j]);  //���д��f0h������4����4�㰵
		 }
		 Lcd_Write_command(b);     	//+��Ϊ�ϳ�Ϊһ���ֽڣ���ʵ���ǻ�B0+0x
		Lcd_Write_command(0x10); 	//Set column address MSB(10+xx)��Y7 Y6 Y5 Y4
		Lcd_Write_command(0x01); 
		Lcd_CURSOR(b,0);
		 for(j=0;j<8;j++)      
		 {	                        //ÿ��дһ�Σ��л��Զ���1
		 	 Lcd_CURSOR(b,j+row);       //���ڱ䣬���Ҳ�ڲ�ͣ�Ļ��У����½��ж�λ
		 	 Lcd_Write_Data(hz[j+8]);  //���д��f0h������4����4�㰵
		 }		
	
}
void dis_shuzi(uchar x,uchar y,uchar shuzi)	
{
	switch	(shuzi)
	{
	//case 0x0f:dispaly[2]=9;break;
	//case 0x0e:dispaly[2]=9;break;
	//case 0x0d:dispaly[2]=8;break;
	//case 0x0c:dispaly[2]=8;break;
	//case 0x0b:dispaly[2]=7;break;
	//case 0x0a:dispaly[2]=6;break;
	case 0x09:dis_168hz(x,y,jiu16);break;
	case 0x08:dis_168hz(x,y,ba16);break;
	case 0x07:dis_168hz(x,y,qi16);break;
	case 0x06:dis_168hz(x,y,liu16);break;
	case 0x05:dis_168hz(x,y,wu16);break;
	case 0x04:dis_168hz(x,y,si16);break;
	case 0x03:dis_168hz(x,y,san16);break;
	case 0x02:dis_168hz(x,y,er16);break;
	case 0x01:dis_168hz(x,y,yi16);break;
	case 0x00:dis_168hz(x,y,ling16);break;
	default:break;
	}
}
//-----------------------------------------------------------------------------

/*void LCDtime(uchar x,uchar nian1,uchar nian2,uchar nian3,uchar nian4,
		     uchar yue1,uchar yue2,
		     uchar ri1,uchar ri2,
		     uchar shi1,uchar shi2,
		     uchar fen1,uchar fen1,)    //LCDʱ����ʾ����
*/
//------------------------------------------------------------------------------
/*
void LCDtime()	                         
	{
	dis_168hz(0xB6,5,er16);          	 //n1
	dis_168hz(0xB6,13,ling16);	 		 //n2
	dis_168hz(0xB6,21,ling16);	 		 //n3	
	dis_168hz(0xB6,29,qi16);	 		 //n4
	dis_168hz(0xB6,37,heng16);
	dis_168hz(0xB6,45,yi16);	 		 //y1
	dis_168hz(0xB6,53,ling16);	 		 //y2
	dis_168hz(0xB6,61,heng16);	 	
	dis_168hz(0xB6,69,yi16);	 		 //r1
	dis_168hz(0xB6,77,ling16);       	 //r2
	///////////////////////////////////////////////
	dis_168hz(0xB6,90,yi16);	 		//s1
	dis_168hz(0xB6,98,san16);           //s2
	dis_168hz(0xB6,106,maohao16);	 	//
	dis_168hz(0xB6,114,yi16);        	//f3
	dis_168hz(0xB6,122,liu16);       	//f4
	}
*/
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------

void  dis_ykxt()
{
//---------------------------��һ�С�����ң��ϵͳ��-----------------------------
	dis_1616hz(0xB0,0xB1,20,wu);
	dis_1616hz(0xB0,0xB1,36,xian);
	dis_1616hz(0xB0,0xB1,52,yao);
	dis_1616hz(0xB0,0xB1,68,kong);
	dis_1616hz(0xB0,0xB1,84,xi);
	dis_1616hz(0xB0,0xB1,100,tong);
}
//----------------------------��2�С��̵�������-------------------------------------
void dis_jdql()
{
	dis_1616hz(0xB3,0xB4,35,ji);
	dis_1616hz(0xB3,0xB4,51,dian);
	dis_1616hz(0xB3,0xB4,67,qi);
	dis_1616hz(0xB3,0xB4,83,kai);
}	
//---------------------------��3�С��������조--------------------------------------
void dis_fmqx()
{
	dis_1616hz(0xB3,0xB4,35,feng);
	dis_1616hz(0xB3,0xB4,51,ming);
	dis_1616hz(0xB3,0xB4,67,qi);
	dis_1616hz(0xB3,0xB4,83,xiang);
}
//-------------------------------���ڳ�ʼ��-------------------------------------
void StartUART(void)
{
 	 UCSRA=0x00;	
	 UCSRB=0x18;	
	 UCSRC=0x06;	
	 UBRRL=0x33;
	 UBRRH=0x00;
	 UCSRA=UCSRA|0x08;	
}
//------------------------------���ڷ���----------------------------------------
void R_S_Byte(uchar R_Byte)
{	
     UDR= R_Byte;  
}
//------------------------------������------------------------------------------
void main(void)
{  
	uint i;
	DDRD=0xF2;						  //�˿�D����											  
	DDRB=0xB3;					     //�˿�B����							
//------------------------------------------------------------------------------				  			 				
	Spi_initial();	                //SPI��ʼ��															  
	system_Init();				   //ϵͳ״̬��ʼ��												
	Config905();  				  //NRF905��ʼ��	
//------------------------------------------------------------------------------	
	Lcd_init();					 //LCD��ʼ��							  
//------------------------------------------------------------------------------
	StartUART();				//���ڳ�ʼ��9600������
	Delay(500);
	Lcd_Clear();				//����Ļ
	
//------------------------------------------------------------------------------
	while(1)
	{
	RX();  					//��������
	if(TxRxBuffer[0])
	{
	if(TxRxBuffer[0]==0x29)
	{
	Low_JDQ;			   //�򿪼̵���
	dis_ykxt();
	dis_jdql();
	}
	if(TxRxBuffer[0]==0x30)
	{
	Low_BELL;			   //�򿪷�����
	dis_ykxt();
	dis_fmqx();
	}
	if(TxRxBuffer[0]==0x31)
	{
	Lcd_Clear();		  //����Ļ
	}
	}
	Hign_JDQ;			  //�رռ̵���				
	Hign_BELL;			  //�رշ�����		
	}
}
