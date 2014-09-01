//====================================================================================
//文 件 名: nRF2401.c
//功能描述: nRF2401的驱动程序
//维护记录: 2006年10月20
//====================================================================================

#include "spce061a.h"

#define	PWR		0x0001 							// IOB0
#define CE 		0x0002 							// IOB1
#define CS		0x0004 							// IOB2
#define DR1		0x0008 							// IOB3
#define	CLK1	0x0010 							// IOB4
#define DATA	0x0020 							// IOB5

const unsigned int InitData[15] = 				// nRF2401 控制字 15 Byte
{
	0x08,										// 通道二接收数据宽度（bit）
	0x08,										// 通道一接收数据宽度（bit）
	0x00,										// 通道二地址（A24）
	0x00,										// 通道二地址（A23）
	0x00,										// 通道二地址（A22）
	0x00,										// 通道二地址（A21）
	0x01,										// 通道二地址（A20）
	0x00,										// 通道一地址（A14）
	0x00,										// 通道一地址（A13）
	0x00,										// 通道一地址（A12）
	0x00,										// 通道一地址（A11）
	0x01,										// 通道一地址（A10）
	0xA3,										// b7~b2:接收地址宽度,和发送端一致,不超过40bit；
												// b1~b0:CRC模式选择(01-8bit;11-16bit;00/10-no)
	0x4f,										// b15:接收通道选择(0-通道1;1-通道1和2)
												// b14:收发模式(0-Direct模式,1-ShockBurst模式)
												// b13:波特率选择(0-250Kbps;1-1Mbps)
												// b12~b10:晶振选择(000-4M;001-8M;010-12M;011-16M)
												// b9~b8:发射功率(11-0db)																
	0x05										// b7~b1:发射频率配置
												// b0:收发控制(0-发送;1-接收)
};
unsigned int AddrBuffer[5];						// 地址寄存器
unsigned int AddrByteCnt;						// 地址Byte数

void nRF2401_ON();								// nRF2401A上电
void nRF2401_OFF();								// nRF2401A掉电
void nRF2401_Initial();							// nRF2401A初始化
void nRF2401_WriteCommand();					// nRF2401A写命令字
void nRF2401_WriteByte(unsigned int uiData);	// 向nRF2401A写入一个Byte
void nRF2401_WriteWord(unsigned int uiData);	// 向nRF2401A写入一个Word
void nRF2401_Mode(unsigned int uiMode);			// 切换nRF2401A收/发模式
void nRF2401_SendByte(unsigned int TxData);	
												// 将字节数据写入nRF2401A
void nRF2401_SendWord(unsigned int TxData);	
												// 将字数据写入nRF2401A
void nRF2401_SendBuffer_Byte(unsigned int TxData[],unsigned int DataByte);	
												// 将数组数据写入nRF2401A
void nRF2401_SendBuffer_Word(unsigned int TxData[],unsigned int DataWord);	
												// 将数组数据写入nRF2401A
unsigned int  nRF2401_RxStatus();				// 判断nRF2401A是否有数据接收
void nRF2401_ReceiveByte(unsigned int RxData[]);// 以Byte格式从nRF2401A读数据
void nRF2401_ReceiveWord(unsigned int RxData[]);// 以Word格式从nRF2401A读数据
void nRF2401_SetAddress(unsigned int Address[],unsigned int AddrByte);
												// 设置目标nRF2401A的地址
void Delay_Us();								// 延时（uS）

//=============================================================
// 语法格式：	void nRF2401_Initial(void)
// 实现功能：	nRF 初始化
// 参数：		无
// 返回值：		无
//=============================================================
void nRF2401_Initial(void)
{
	*P_SystemClock = 0x98;						// 设置系统时钟为49MHz
	*P_IOB_Attrib |= (CS+DATA+PWR+CLK1+CE+DR1);
	*P_IOB_Dir |= (CS+DATA+PWR+CLK1+CE);
	*P_IOB_Dir&=~DR1;
	*P_IOB_Buffer &=~(CS+DATA+CLK1+CE+DR1);		// 初始化IO端口

	nRF2401_ON();
	Delay_Us(3000);
	nRF2401_WriteCommand();						// 向nRF2401A写命令字
	Delay_Us(300);
}

//=============================================================
// 语法格式：	void nRF2401_ON(void)
// 实现功能：	nRF 上电
// 参数：		无
// 返回值：		无
//=============================================================
void nRF2401_ON(void)
{
	*P_IOB_Buffer |= PWR;
}

//=============================================================
// 语法格式：	void nRF2401_OFF(void)
// 实现功能：	nRF 掉电
// 参数：		无
// 返回值：		无
//=============================================================
void nRF2401_OFF(void)
{
	*P_IOB_Buffer &= ~PWR;
}

//=============================================================
// 语法格式：	void nRF2401_WriteCommand(void)
// 实现功能：	nRF 写命令字
// 参数：		无
// 返回值：		无
//=============================================================
void nRF2401_WriteCommand(void)
{
	unsigned int i;
	*P_IOB_Buffer &= ~CE;
	*P_IOB_Buffer |= CS;
	Delay_Us(5);
	for(i=0; i<15; i++)
	{
		nRF2401_WriteByte(InitData[i]);
	}
	*P_IOB_Buffer &= ~CS;
	*P_IOB_Buffer |= CE;
}

//=============================================================
// 语法格式：	void nRF2401_Mode(unsigned int uiMode)
// 实现功能：	设置nRF2401A的工作方式
// 参数：		uiMode:0--接收；1--发送					
// 返回值：		无
//=============================================================
void nRF2401_Mode(unsigned int uiMode)
{
	*P_IOB_Buffer &= ~CE;
	*P_IOB_Buffer |= CS;
	if(uiMode == 0)
		nRF2401_WriteByte(InitData[14] | 0x01);			// 接收
	else
		nRF2401_WriteByte(InitData[14] & 0xFE);			// 发送
	*P_IOB_Buffer &= ~CS;
	*P_IOB_Buffer |= CE;
}

//=============================================================
// 语法格式：	void nRF2401_SetAddress(unsigned int *Address,unsigned int AddrByte)
// 实现功能：	设置目标nRF2401A的地址
// 参数：		unsigned int *Address:地址数组
//				unsigned int AddrByte:数组的长度					
// 返回值：		无
//=============================================================
void nRF2401_SetAddress(unsigned int *Address,unsigned int AddrByte)
{
	unsigned int i;
	for(i=0; i<AddrByte; i++)
	{
		AddrBuffer[i] = Address[i];
	}
	AddrByteCnt = AddrByte;
}

//=============================================================
// 语法格式：	void nRF2401_WriteByte(unsigned int uiData)
// 实现功能：	向nRF2401A写入一个字节数据
// 参数：		unsigned int uiData: 待写入数据
// 返回值：		无
//=============================================================
void nRF2401_WriteByte(unsigned int uiData)
{
	unsigned int i;
	for(i=0; i<8; i++)
	{
		*P_IOB_Buffer &= ~CLK1;
		if(uiData&0x80)
			*P_IOB_Buffer |= DATA;
		else
			*P_IOB_Buffer &= ~DATA;
			Delay_Us(1);
			*P_IOB_Buffer |= CLK1;
			Delay_Us(1);
			*P_IOB_Buffer &= ~CLK1;
			uiData = uiData<<1;
	}
}

//=============================================================
// 语法格式：	void nRF2401_WriteWord(unsigned int uiData)
// 实现功能：	向nRF2401A写入一个字数据
// 参数：		unsigned int uiData: 待写入数据
// 返回值：		无
//=============================================================
void nRF2401_WriteWord(unsigned int uiData)
{
	unsigned int i;
	for(i=0; i<16; i++)
	{
		*P_IOB_Buffer &= ~CLK1;
		if(uiData&0x8000)
			*P_IOB_Buffer |= DATA;
		else
			*P_IOB_Buffer &= ~DATA;
			Delay_Us(1);
			*P_IOB_Buffer |= CLK1;
			Delay_Us(1);
			*P_IOB_Buffer &=~CLK1;
			uiData = uiData<<1;
	}
}

//=============================================================
// 语法格式：	void nRF2401_SendByte(unsigned int TxData)
// 实现功能：	将目标地址+字节数据写入nRF2401A
// 参数：		unsigned int TxData: 待发送字节数据
// 返回值：		无
//=============================================================
void nRF2401_SendByte(unsigned int TxData)
{
	unsigned int i;
	
//	*P_IOB_Dir |= DATA;
	*P_IOB_Buffer |= CE;
	Delay_Us(10);					//
	for(i=0; i<AddrByteCnt; i++)
	{
		nRF2401_WriteByte(AddrBuffer[i]);
	}
	nRF2401_WriteByte(TxData);
	*P_IOB_Buffer &= ~CE;
	*P_IOB_Buffer &= ~DATA;
	Delay_Us(200);
}

//=============================================================
// 语法格式：	void nRF2401_SendWord(unsigned int TxData)
// 实现功能：	将目标地址+字数据写入nRF2401A
// 参数：		unsigned int TxData: 待发送字数据
// 返回值：		无
//=============================================================
void nRF2401_SendWord(unsigned int TxData)
{
	unsigned int i;
	
//	*P_IOB_Dir |= DATA;
	*P_IOB_Buffer |= CE;
	Delay_Us(10);					//
	for(i=0; i<AddrByteCnt; i++)
	{
		nRF2401_WriteByte(AddrBuffer[i]);
	}
	nRF2401_WriteWord(TxData);
	*P_IOB_Buffer &= ~CE;
	*P_IOB_Buffer &= ~DATA;
	Delay_Us(200);
}

//=============================================================
// 语法格式：	void nRF2401_SendBuffer_Byte(unsigned int *TxData,unsigned int DataByte)
// 实现功能：	向nRF2401A发送一个数组的数据（字节方式）
// 参数：		unsigned int *TxData: 待发送数组
//				unsigned int DataByte:数组的长度					
// 返回值：		无
//=============================================================
void nRF2401_SendBuffer_Byte(unsigned int *TxData,unsigned int DataByte)
{
	unsigned int i;
	
//	*P_IOB_Dir |= DATA;
	*P_IOB_Buffer |= CE;
	Delay_Us(10);					//
	for(i=0; i<AddrByteCnt; i++)
	{
		nRF2401_WriteByte(AddrBuffer[i]);
	}
	for(i=0; i<DataByte; i++)
	{
		nRF2401_WriteByte(TxData[i]);
	}
	*P_IOB_Buffer &= ~CE;
	*P_IOB_Buffer &= ~DATA;
	Delay_Us(200);
}

//=============================================================
// 语法格式：	void nRF2401_SendBuffer_Word(unsigned int *TxData,unsigned int DataWord)
// 实现功能：	向nRF2401A发送一个数组的数据(字方式)
// 参数：		unsigned int *TxData: 待发送数组
//				unsigned int DataWord:数组的长度					
// 返回值：		无
//=============================================================
void nRF2401_SendBuffer_Word(unsigned int *TxData,unsigned int DataWord)
{
	unsigned int i;
	
//	*P_IOB_Dir |= DATA;
	*P_IOB_Buffer |= CE;
	Delay_Us(10);					//
	for(i=0; i<AddrByteCnt; i++)
	{
		nRF2401_WriteByte(AddrBuffer[i]);
	}
	for(i=0; i<DataWord; i++)
	{
		nRF2401_WriteWord(TxData[i]);
	}
	*P_IOB_Buffer &= ~CE;
	*P_IOB_Buffer &= ~DATA;
	Delay_Us(200);
}

//=============================================================
// 语法格式：	unsigned int nRF2401_RxStatus()
// 实现功能：	判断nRF2401A的接收状态
// 参数：		无
// 返回值：		0:	没有接收到数据
//				1:	已经接收到数据，等待读出
//=============================================================
unsigned int nRF2401_RxStatus()
{
	if((*P_IOB_Data&DR1) == 0)
		return(0);
	else
		return(1);
}

//=============================================================
// 语法格式：	void nRF2401_ReceiveByte(unsigned int *RxData)
// 实现功能：	从nRF2401A读出一个字节的数据
// 参数：		unsigned int *RxData:读出的数据
// 返回值：		无
//=============================================================
void nRF2401_ReceiveByte(unsigned int *RxData)
{
	unsigned int i = 0,j = 0;
	unsigned int dat = 0;

	*P_IOB_Dir &= ~DATA;			// 输入
	while(*P_IOB_Data&DR1)
	{
		dat <<= 1;
		*P_IOB_Buffer &= ~CLK1;
		if(*P_IOB_Data&DATA)
			dat |= 0x01;
		i++;
		*P_IOB_Buffer |= CLK1;
		Delay_Us(1);
		if(i>7)
		{
			i = 0;
			RxData[j] = dat;
			dat = 0;
			j++;
		}
		*P_IOB_Buffer &= ~CLK1;
	}
	*P_IOB_Dir |= DATA;			// 输出
}

//=============================================================
// 语法格式：	void nRF2401_ReceiveWord(unsigned int *RxData)
// 实现功能：	从nRF2401A读出一个字的数据
// 参数：		unsigned int *RxData:读出的数据
// 返回值：		无
//=============================================================
void nRF2401_ReceiveWord(unsigned int *RxData)
{
	unsigned int i = 0,j = 0;
	unsigned int dat = 0;

	*P_IOB_Dir &= ~DATA;			// 输入
	while(*P_IOB_Data&DR1)
	{
		dat <<= 1;
		*P_IOB_Buffer &= ~CLK1;
		if(*P_IOB_Data&DATA)
			dat |= 0x01;
		i++;
		*P_IOB_Buffer |= CLK1;
		Delay_Us(1);
		if(i>15)
		{
			i = 0;
			RxData[j] = dat;
			dat = 0;
			j++;
		}
		*P_IOB_Buffer &= ~CLK1;
	}
	*P_IOB_Dir |= DATA;			// 输出
}

//=============================================================
// 语法格式：	void Delay_Us(unsigned int TimeCnt)
// 实现功能：	延时（uS）
// 参数：		unsigned int TimeCnt:延时的us数
// 返回值：		无
//=============================================================
void Delay_Us(unsigned int TimeCnt)
{
	int i;
	*P_SystemClock = 0x98;
	for(i = 0; i < TimeCnt; i++)
	{
		*P_Watchdog_Clear = 0x0001;
	}
}


//******************************** END *************************************