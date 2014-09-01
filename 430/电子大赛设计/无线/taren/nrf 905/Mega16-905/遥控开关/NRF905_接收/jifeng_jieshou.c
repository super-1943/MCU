//ICC-AVR application builder : 2007-8-11 20:37:32
// Target : M16
// Crystal: 8.0000Mhz
#include <iom16v.h>
#include <macros.h>
#define uint  unsigned int
#define uchar unsigned char
//---------------------------------模式控制定义---------------------------------
//#define  nrf905_TX_EN	  PB0	    //输出1
#define   Hign_nrf905_TX_EN    PORTB |= (1 << PB0);   
#define   Low_nrf905_TX_EN     PORTB &= ~(1 << PB0); 
//#define  nrf905_TRX_CE  PD5 	    //输出1
#define   Hign_nrf905_TRX_CE    PORTD |= (1 << PD5);   
#define   Low_nrf905_TRX_CE     PORTD &= ~(1 << PD5); 
//#define  nrf905_PWR     PB1 	    //输出1
#define   Hign_nrf905_PWR    PORTB |= (1 << PB1);   
#define   Low_nrf905_PWR     PORTB &= ~(1 << PB1); 
//--------------------------------NRF905-SPI口接口定义--------------------------
//#define  nrf905_MISO	  PB6   	//输入0
//#define  nrf905_MOSI    PB5	    //输出1
//#define  nrf905_SCK     PB7	    //输出1
#define   Low_nrf905_SCK     PORTB &= ~(1 << PB7); 
//#define  nrf905_CSN     PB4		//输出1		
#define   Hign_nrf905_CSN    PORTB |= (1 << PB4);   
#define   Low_nrf905_CSN     PORTB &= ~(1 << PB4); 						
//-------------------------------NRF905状态输出口-------------------------------
//#define  nrf905_CD      PD4	    //输入0
#define   Hign_nrf905_CD    PORTD |= (1 << PD4);   
#define   Low_nrf905_CD     PORTD &= ~(1 << PD4); 
#define   Read_nrf905_CD    PINB & (1 << PD4);
//#define  nrf905_AM      PB3	    //输入0
#define   Hign_nrf905_AM    PORTB |= (1 << PB3);   
#define   Low_nrf905_AM     PORTB &= ~(1 << PB3); 
#define   Read_nrf905_AM    PINB & (1 << PB3);
//#define  nrf905_DR      PB2  		//输入0
#define   Hign_nrf905_DR     PORTB |= (1 << PB2);   
#define   Low_nrf905_DR     PORTB &= ~(1 << PB2); 
#define   Read_nrf905_DR    PINB & (1 << PB2);   
//------------------------------LCD状态输出口-----------------------------------
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
//-------------------------------BELL蜂明器-------------------------------------
#define   Hign_BELL  PORTD |= (1 << PD6);   
#define   Low_BELL     PORTD &= ~(1 << PD6); 
//-------------------------------JDQ继电器--------------------------------------
#define   Hign_JDQ  PORTD |= (1 << PD7)
#define   Low_JDQ     PORTD &= ~(1 << PD7)
//------------------------LCD字库---------------------------------------------
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
const uchar wu[32]=															 	 //无
{0x00,0x40,0x42,0x42,0x42,0x42,0xFE,0x42,0xC2,0x42,0x43,0x42,0x60,0x40,0x00,0x00,
0x00,0x80,0x40,0x20,0x18,0x06,0x01,0x00,0x3F,0x40,0x40,0x40,0x40,0x40,0x70,0x00};
const uchar xian[32]=															 //线
{0x00,0x20,0x30,0xAC,0x63,0x20,0x30,0x20,0x20,0xFF,0x90,0x92,0x94,0xD0,0x80,0x00,
0x20,0x62,0x23,0x12,0x12,0x12,0x41,0x41,0x21,0x17,0x18,0x24,0x42,0x80,0xE0,0x00};
const uchar yao[32]=															 //遥
{0x40,0x42,0x44,0xCC,0x00,0x42,0x36,0x2A,0x22,0xFE,0x21,0x29,0x25,0x80,0x00,0x00,
0x00,0x40,0x20,0x1F,0x21,0x41,0x5D,0x49,0x49,0x4F,0x49,0x49,0x5D,0x61,0x21,0x00};
const uchar kong[32]=															 //控
{0x10,0x10,0x10,0xFF,0x90,0x50,0x0C,0x44,0x24,0x15,0x06,0x14,0x24,0x54,0x0C,0x00,
0x02,0x42,0x81,0x7F,0x00,0x40,0x42,0x42,0x42,0x42,0x7E,0x42,0x43,0x62,0x40,0x00};
const uchar xi[32]=															 	 //系
{0x00,0x02,0x22,0x22,0x32,0x2E,0xA2,0x62,0x22,0x22,0x91,0x09,0x01,0x00,0x00,0x00,
0x00,0x00,0x42,0x22,0x1A,0x43,0x82,0x7E,0x02,0x02,0x0A,0x13,0x66,0x00,0x00,0x00};
const uchar tong[32]=															//统
{0x20,0x30,0xAC,0x63,0x30,0x88,0xC8,0xA8,0x99,0x8E,0x88,0xA8,0xCC,0x88,0x00,0x00,
0x22,0x67,0x22,0x12,0x92,0x40,0x30,0x0F,0x00,0x00,0x3F,0x40,0x40,0x41,0x70,0x00};
const uchar ji[32]=																//继											//继
{0x20,0x30,0xAC,0x63,0x30,0x00,0xFE,0x88,0x90,0xA0,0xFF,0xA0,0x90,0x98,0x00,0x00,
0x22,0x67,0x22,0x12,0x12,0x00,0x7F,0x48,0x44,0x42,0x7F,0x42,0x44,0x6C,0x40,0x00};
const uchar dian[32]=															//电
{0x00,0xF8,0x48,0x48,0x48,0x48,0xFF,0x48,0x48,0x48,0x48,0xFC,0x08,0x00,0x00,0x00,
0x00,0x07,0x02,0x02,0x02,0x02,0x3F,0x42,0x42,0x42,0x42,0x47,0x40,0x70,0x00,0x00};
const uchar qi[32]=																//器
{0x80,0x80,0x9F,0x91,0x91,0x91,0x9F,0xE0,0x9F,0x91,0xB1,0xD1,0x9F,0xC0,0x80,0x00,
0x08,0x08,0xFC,0x8C,0x8A,0x8A,0xF9,0x00,0xF9,0x8A,0x8A,0x8C,0xFC,0x08,0x08,0x00};
const uchar kai[32]=															//开
{0x80,0x82,0x82,0x82,0xFE,0x82,0x82,0x82,0x82,0x82,0xFE,0x82,0x83,0xC2,0x80,0x00,
0x00,0x80,0x40,0x30,0x0F,0x00,0x00,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0x00,0x00};
const uchar feng[32]=															//蜂
{0x00,0xF0,0x10,0xFF,0x10,0xF8,0x90,0x88,0x4F,0x54,0xA4,0x54,0x4C,0xC4,0x40,0x00,
0x20,0x67,0x22,0x1F,0x12,0x3B,0x00,0x14,0x15,0x15,0xFF,0x15,0x15,0x14,0x00,0x00};
const uchar ming[32]=															//明
{0x00,0xFC,0x44,0x44,0x44,0xFE,0x04,0x00,0xFE,0x22,0x22,0x22,0x22,0xFF,0x02,0x00,
0x00,0x0F,0x04,0x04,0x04,0x8F,0x40,0x30,0x0F,0x02,0x02,0x42,0x82,0x7F,0x00,0x00};
const uchar xiang[32]=																//响
{0x00,0xFC,0x04,0x04,0xFE,0x04,0xF8,0x08,0xCC,0x4A,0x49,0xC8,0x08,0xFC,0x08,0x00,
0x00,0x1F,0x08,0x08,0x1F,0x00,0xFF,0x00,0x0F,0x08,0x08,0x4F,0x80,0x7F,0x00,0x00};
//----------------------------------NRF905-SPI指令------------------------------
#define WC	0x00
#define RRC	0x10
#define WTP	0x20
#define RTP	0x21
#define WTA	0x22
#define RTA	0x23
#define RRP	0x24
//---------------------------------发送数据-------------------------------------
uchar TxRxBuffer[4];
//----------------------------------接收地址------------------------------------
uchar TxAddress[4]={0xcc,0xcc,0xcc,0xcc };    
//------------------------------------------------------------------------------
uchar count1 ,count2;
//----------------------------------寄存器配置----------------------------------
uchar RFConf[11]=
{
  0x00,                            //配置命令//
  0x4c,                           //CH_NO,配置频段在430MHZ
  0x0C,                          //输出功率为10db,不重发，节电为正常模式
  0x44,                         //地址宽度设置，为4字节
  0x04,0x04,                   //接收发送有效数据长度为32字节
  0xCC,0xCC,0xCC,0xCC,        //接收地址
  0x58,                      //CRC充许，8位CRC校验，外部时钟信号不使能，16M晶振
};
//----------------------------------NRF905函数申明------------------------------
void Delay(uint x);						       //延时子程序																							
void Spi_initial();                            //SPI初始化
uchar SpiReadSpiWrite(unsigned char cData);    //SPI读写子程序
void system_Init(void);		   				   //系统初始化
void Config905(void);						   //NRF905初始化子程序
void TxPacket(void);						
void SetTxMode(void);						   //数据发送
void SetRxMode(void);						   //
void TX(void);
unsigned char CheckDR(void);
void RxPacket(void);
void  RX(void);
//-------------------------------串口函数申明-----------------------------------
void StartUART(void);
void R_S_Byte(uchar R_Byte);
//-------------------------------LCD函数申明------------------------------------
void LCD_Delay(uint time);
void Lcd_init(void);
void Lcd_Write_Data(uchar DATA) ;
void Lcd_Write_command(uchar COMMAND);
void Lcd_CURSOR(uchar add_page,uchar add_col)  ;
void Lcd_Clear(void) ;
void dis_1616hz(uchar x1,uchar x2,uchar row,const uchar hz[]);
void dis_168hz(uchar x1,uchar row,const uchar hz[]);
void LCDtime();
//----------------------------------100us延时子程序-----------------------------
void Delay(uint x)
{
	uint i;
	while(x--)
	for(i=0;i<80;i++);
}
//----------------------------------SPI初始化-----------------------------------
void Spi_initial()
{
	SPCR   = (1<<SPE)|(1<<MSTR)|(0<<CPOL)|(0<<SPR0);// 主机模式，fck/16, SPI方式0
}
//---------------------------------SPI读写程序----------------------------------	
uchar SpiReadSpiWrite(unsigned char cData)
{
	SPDR = cData;
	while(!(SPSR & (1<<SPIF) ))  // 等待SPI发送完毕
	{};			
	return SPDR;
}
//--------------------------------系统状态初始化--------------------------------
void system_Init(void)			
{

   	Hign_nrf905_CSN;			// SPI使能
	Low_nrf905_SCK;				
	Low_nrf905_DR;				// DR=0
	Low_nrf905_AM;				// AM=0
	Low_nrf905_CD;				// CD=0
	Hign_nrf905_PWR;		    // PWR=1
	Low_nrf905_TRX_CE;			// nrf905_TRX_CE=0
	Low_nrf905_TX_EN ;			// nrf905_TX_EN=0
}
//--------------------------------NRF905寄存器初始化函数------------------------
void Config905(void)
{
	uchar i;
	Low_nrf905_CSN;				//SPI使能											
	Delay(1);				   
	for (i=0;i<11;i++)			//碞RF905配置字
	{
	 SpiReadSpiWrite(RFConf[i]);
	}
	Hign_nrf905_CSN;					// Disable Spi
}
//--------------------------------NRF905待发数据打包----------------------------
void TxPacket(void)
{
	uchar i;
	Low_nrf905_CSN;		   				// 使能Spi，允许对nrf905进行读写操作
	Delay(1);
	SpiReadSpiWrite(WTP);				// 写数据前先写写数据命令
	for (i=0;i<32;i++)
	{
	SpiReadSpiWrite(TxRxBuffer[i]);		// 待发送的32字节数据
	}						
	Hign_nrf905_CSN;
	Delay(1);							// 关闭Spi，不允许对nrf905进行读写操作
	Low_nrf905_CSN;						// 使能Spi
	SpiReadSpiWrite(WTA);				// 写地址前首先先写地址命令
	for (i=0;i<4;i++)					// 写入4 bytes 接收地址
	{
	SpiReadSpiWrite(TxAddress[i]);
	}
	Hign_nrf905_CSN;					// 关闭Spi
	Hign_nrf905_TRX_CE;					// Set TRX_CE high,start Tx data transmission
	Delay(1);							// 等待DR变高
	Low_nrf905_TRX_CE;					// 设置TRX_CE=0
}
//------------------------------设置发送模式------------------------------------
void SetTxMode(void)
{
	Low_nrf905_TRX_CE;				//
	Hign_nrf905_TX_EN;				//发送使能
	Delay(2); 				// delay for mode change(>=650us)
}
//------------------------------设置接收模式激发--------------------------------
void SetRxMode(void)
{
	Low_nrf905_TX_EN;
	Hign_nrf905_TRX_CE;
	Delay(10); 					// delay for mode change(>=650us)
}
//------------------------------发送数据----------------------------------------
void TX(void)
{
     SetTxMode();	   // Set nRF905 in Tx mode
	 TxPacket();			   // Send data by nRF905
}
//-----------------------------判断是否收到数据---------------------------------
unsigned char CheckDR(void)		//检查是否有新数据传入 
{
	if (PINB & (1 << PB2))
	{
		return 1; 	 	  		//收到数据
	}
	else
	{
		return 0;
	}
}
//-----------------------------------读接收数据包-------------------------------
void RxPacket(void)							//读数据
{
	uchar i;
    Low_nrf905_TRX_CE;
	Low_nrf905_CSN;						    // 使能SPI
    Delay(1);
	SpiReadSpiWrite(RRP);				   // 写入数据接收缓冲区数据命令
	for (i = 0 ;i < 4 ;i++)
	{   
	TxRxBuffer[i]=SpiReadSpiWrite(0);	  // 读取数据接收缓冲区数据       
	}
	Hign_nrf905_CSN;
    Delay(2);                            //
	Hign_nrf905_TRX_CE;							
}
//--------------------------------设置接收模式----------------------------------
void  RX(void)
{
    SetRxMode();			          //设置NRF905接收模式
    while (CheckDR()==0);	         //等待接收完成
	RxPacket();                     //读取接收数据缓冲区
	Delay(10);
}
//******************************************************************************
//以下为LCD驱动
//******************************************************************************
//------------------------------------------------------------------------------
void LCD_Delay(uint time)
{
	uint i;
	for(i=time;i>0;i--);
}
//---------------------------LCD初始化---------------------------------------
void Lcd_init(void)
{
 	DDRC=0xF8;
	//ASSR &= ~(1 <<AS2); 
	Hign_LCD_CS;
	Low_LCD_RESET;	 	//硬复位
	LCD_Delay(50);
	Hign_LCD_RESET;			
	////////////////////////////////////////////////////////
	Lcd_Write_command(0xe2);	//软复位RESet:initialize the internal functions
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
	Lcd_Write_command(0x7f);	//START DISPLAY LINE(COM1)  起始行
	//////////////////////////////////////////////////////
	Lcd_Write_command(0xe0);	//写入数据时地址自动加1，读数据时不变
	//////////////////////////////////////////////////////////
	Lcd_Write_command(0xaf);	//DISPLAY ON  
}
//--------------------------------LCD写数据函数---------------------------------
void Lcd_Write_Data(uchar DATA)              //写一个字节，再加一列，正好在一页
{                                            //定好一页后，再一列一列的写
	int i,temp;
	temp=DATA;
	Low_LCD_RS;		
	Hign_LCD_CS;
	Hign_LCD_SCL;
	LCD_Delay(1);
	Low_LCD_CS;
	Low_LCD_SCL;
	Hign_LCD_RS;		//RS=1 时为写数据
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
	Hign_LCD_CS;    //先cs置0，然后把数据都送到口上准备好（产生上升沿），最后才置片选cs为1	
}
//---------------------------------LCD写命令函数--------------------------------
void Lcd_Write_command(uchar COMMAND)
{
	uchar i,temp;
	temp = COMMAND;
	Hign_LCD_RS;		
	Hign_LCD_CS;
	Hign_LCD_SCL;
	LCD_Delay(1);
	Low_LCD_RS;		//RS=0 为写命令
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
	Hign_LCD_CS;      //用了temp后，原来的command的就不会变了
}
//-------------------------------LCD光标函数------------------------------------
void Lcd_CURSOR(uchar add_page,uchar add_col)               //光标定位	//8页(<0fh)， 且128列(>0fh)
{                                                           //每页8行
	Lcd_Write_command(0xB0+(add_page&0x0f));     //+号为合成为一个字节（其实就是或）B0+0x
	Lcd_Write_command(0x10|(add_col>>4)); //Set column address MSB(10+xx)即Y7 Y6 Y5 Y4
	Lcd_Write_command(add_col&0x0f);      //Set column address LSB(00+xx)即Y3 Y2 Y1 Y0
}
//-------------------------------LCD清屏函数------------------------------------
void Lcd_Clear(void)                         //128x64字节,实际中一般要多
{	
	uchar i,j;
	for(i=0;i<9;i++)                     //>8页
	{
		 Lcd_CURSOR(i,0);		
		 for(j=0;j<132;j++)          //>128列
		 {	
		 	 Lcd_CURSOR(i,j);      //列在变，光标也在不停的换列
		 	 Lcd_Write_Data(0); //定好一页后，再一列一列的写00h,列在变
		 }		
	}
}	
//--------------------------------LCD测试---------------------------------------
void Test_LCD(void)
{	
	uchar i,j;
	for(i=0xB0;i<0xB8;i++)		//B0-B8共8页
	{
		Lcd_Write_command(i);     //+号为合成为一个字节（其实就是或）B0+0x
		Lcd_Write_command(0x10); //Set column address MSB(10+xx)即Y7 Y6 Y5 Y4
		Lcd_Write_command(0x01); 
		 Lcd_CURSOR(i,0);
		 for(j=0;j<132;j++)
		 {	                        //每读写一次，列会自动加1
		 	 Lcd_CURSOR(i,j);       //列在变，光标也在不停的换列，重新进行定位
		 	 Lcd_Write_Data(0x01);  //检测写进f0h？？？4点亮4点暗
		 }
		 		
	}
}
/*
//------------------------------------------------------------------------------
void dis_biankuang()			//边框设计
{	
	uchar i,j,k;
	for(i=0xB0;i<0xB8;i++)		//2页16行
	{
		Lcd_Write_command(i);     	//+号为合成为一个字节（其实就是或）B0+0x
		Lcd_Write_command(0x10); 	//Set column address MSB(10+xx)即Y7 Y6 Y5 Y4
		Lcd_Write_command(0x01); 
		Lcd_CURSOR(i,0);
		 for(j=0;j<132;j++)
		 {	                        //每读写一次，列会自动加1
		 	 Lcd_CURSOR(i,j);       //改变列位置，列在变，光标也在不停的换列，重新进行定位
		 	 Lcd_Write_Data(0x03);  //检测写进f0h？？？4点亮4点暗
		 }
		 for(k=0xB0;k<0xB7;k++)
		 {
		 for(j=2;j<6;j++)
		 {
		  Lcd_CURSOR(k,j);       //改变列位置，列在变，光标也在不停的换列，重新进行定位
		  Lcd_Write_Data(0xff);
		 }
		 for(j=130;j<132;j++)
		 {
		  Lcd_CURSOR(k,j);       //改变列位置，列在变，光标也在不停的换列，重新进行定位
		  Lcd_Write_Data(0xff);
		 }
		 }
		 i=i+7;
		 for(j=0;j<132;j++)      
		 {	                        //每读写一次，列会自动加1
		 	 Lcd_CURSOR(i,j);       //列在变，光标也在不停的换列，重新进行定位
		 	 Lcd_Write_Data(0x03);  //检测写进f0h？？？4点亮4点暗
		 }

			
	}
}
*/
//------------------------------16*16汉字显示-----------------------------------
void dis_1616hz(uchar x1,uchar x2,uchar row,const uchar hz[])			//16*16
{	
	uchar i,j;
	for(i=x1;i<x2;i++)		//2页16行
	{
		Lcd_Write_command(i);     	//+号为合成为一个字节（其实就是或）B0+0x
		Lcd_Write_command(0x10); 	//Set column address MSB(10+xx)即Y7 Y6 Y5 Y4
		Lcd_Write_command(0x01); 
		Lcd_CURSOR(i,0);
		 for(j=0;j<16;j++)
		 {	                        //每读写一次，列会自动加1
		 	 Lcd_CURSOR(i,j+row);       //改变列位置，列在变，光标也在不停的换列，重新进行定位
		 	 Lcd_Write_Data(hz[j]);  //检测写进f0h？？？4点亮4点暗
		 }
		 i++;
		 for(j=0;j<16;j++)      
		 {	                        //每读写一次，列会自动加1
		 	 Lcd_CURSOR(i,j+row);       //列在变，光标也在不停的换列，重新进行定位
		 	 Lcd_Write_Data(hz[j+16]);  //检测写进f0h？？？4点亮4点暗
		 }		
	}
}
/*------------------------------------------------------------------------------
void Dis16x16(uchar add_page, uchar add_col,const uchar *pHZ,uchar state)
{
    uchar i;
    Lcd_CURSOR(add_page, add_col);
    for(i=0;i<16;i++) 
    {                                                //一个汉字2行，16列，32个字节
    	if(state)                                    //state(选亮，黑)
    	{
    		Lcd_Write_Data(pHZ[i]);              //光标定位后沿着行开始写16列的字模数据？？？？？？
    	}
    //	else
    //	{
    	    	Lcd_Write_Data(~pHZ[i]);	    //如果列变，光标也会不停的换列，这里光标只换页不换列
    //	}                                           //那还是一列一列的写吗？？？？(写一次会自动加1列）
     // }                                             //而清时在不停的换列
    Lcd_CURSOR(add_page-1, add_col);                //加或减都行，只是取模方向不同
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
//-----------------------------16*8点阵显示-------------------------------------
void dis_168hz(uchar x1,uchar row,const uchar hz[])			//16*16
{	
	uchar a,b,j;
	a=x1;
	b=x1+1;
		Lcd_Write_command(a);     	//+号为合成为一个字节（其实就是或）B0+0x
		Lcd_Write_command(0x10); 	//Set column address MSB(10+xx)即Y7 Y6 Y5 Y4
		Lcd_Write_command(0x01); 
		Lcd_CURSOR(a,0);
		 for(j=0;j<8;j++)
		 {	                        //每读写一次，列会自动加1
		 	 Lcd_CURSOR(a,j+row);       //改变列位置，列在变，光标也在不停的换列，重新进行定位
		 	 Lcd_Write_Data(hz[j]);  //检测写进f0h？？？4点亮4点暗
		 }
		 Lcd_Write_command(b);     	//+号为合成为一个字节（其实就是或）B0+0x
		Lcd_Write_command(0x10); 	//Set column address MSB(10+xx)即Y7 Y6 Y5 Y4
		Lcd_Write_command(0x01); 
		Lcd_CURSOR(b,0);
		 for(j=0;j<8;j++)      
		 {	                        //每读写一次，列会自动加1
		 	 Lcd_CURSOR(b,j+row);       //列在变，光标也在不停的换列，重新进行定位
		 	 Lcd_Write_Data(hz[j+8]);  //检测写进f0h？？？4点亮4点暗
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
		     uchar fen1,uchar fen1,)    //LCD时间显示函数
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
//---------------------------第一行“无线遥控系统“-----------------------------
	dis_1616hz(0xB0,0xB1,20,wu);
	dis_1616hz(0xB0,0xB1,36,xian);
	dis_1616hz(0xB0,0xB1,52,yao);
	dis_1616hz(0xB0,0xB1,68,kong);
	dis_1616hz(0xB0,0xB1,84,xi);
	dis_1616hz(0xB0,0xB1,100,tong);
}
//----------------------------第2行“继电器开”-------------------------------------
void dis_jdql()
{
	dis_1616hz(0xB3,0xB4,35,ji);
	dis_1616hz(0xB3,0xB4,51,dian);
	dis_1616hz(0xB3,0xB4,67,qi);
	dis_1616hz(0xB3,0xB4,83,kai);
}	
//---------------------------第3行“蜂明器响“--------------------------------------
void dis_fmqx()
{
	dis_1616hz(0xB3,0xB4,35,feng);
	dis_1616hz(0xB3,0xB4,51,ming);
	dis_1616hz(0xB3,0xB4,67,qi);
	dis_1616hz(0xB3,0xB4,83,xiang);
}
//-------------------------------串口初始化-------------------------------------
void StartUART(void)
{
 	 UCSRA=0x00;	
	 UCSRB=0x18;	
	 UCSRC=0x06;	
	 UBRRL=0x33;
	 UBRRH=0x00;
	 UCSRA=UCSRA|0x08;	
}
//------------------------------串口发送----------------------------------------
void R_S_Byte(uchar R_Byte)
{	
     UDR= R_Byte;  
}
//------------------------------主函数------------------------------------------
void main(void)
{  
	uint i;
	DDRD=0xF2;						  //端口D设置											  
	DDRB=0xB3;					     //端口B设置							
//------------------------------------------------------------------------------				  			 				
	Spi_initial();	                //SPI初始化															  
	system_Init();				   //系统状态初始化												
	Config905();  				  //NRF905初始化	
//------------------------------------------------------------------------------	
	Lcd_init();					 //LCD初始化							  
//------------------------------------------------------------------------------
	StartUART();				//串口初始化9600波特率
	Delay(500);
	Lcd_Clear();				//清屏幕
	
//------------------------------------------------------------------------------
	while(1)
	{
	RX();  					//接收数据
	if(TxRxBuffer[0])
	{
	if(TxRxBuffer[0]==0x29)
	{
	Low_JDQ;			   //打开继电器
	dis_ykxt();
	dis_jdql();
	}
	if(TxRxBuffer[0]==0x30)
	{
	Low_BELL;			   //打开蜂明器
	dis_ykxt();
	dis_fmqx();
	}
	if(TxRxBuffer[0]==0x31)
	{
	Lcd_Clear();		  //清屏幕
	}
	}
	Hign_JDQ;			  //关闭继电器				
	Hign_BELL;			  //关闭蜂明器		
	}
}
