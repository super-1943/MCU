#ifndef	__NRF2401_USER_h__
#define	__NRF2401_USER_h__
//	write your header here

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


#endif
