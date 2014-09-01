#ifndef	__NRF2401_USER_h__
#define	__NRF2401_USER_h__
//	write your header here

void nRF2401_ON();								// nRF2401A�ϵ�
void nRF2401_OFF();								// nRF2401A����
void nRF2401_Initial();							// nRF2401A��ʼ��
void nRF2401_WriteCommand();					// nRF2401Aд������
void nRF2401_WriteByte(unsigned int uiData);	// ��nRF2401Aд��һ��Byte
void nRF2401_WriteWord(unsigned int uiData);	// ��nRF2401Aд��һ��Word
void nRF2401_Mode(unsigned int uiMode);			// �л�nRF2401A��/��ģʽ
void nRF2401_SendByte(unsigned int TxData);	
												// ���ֽ�����д��nRF2401A
void nRF2401_SendWord(unsigned int TxData);	
												// ��������д��nRF2401A
void nRF2401_SendBuffer_Byte(unsigned int TxData[],unsigned int DataByte);	
												// ����������д��nRF2401A
void nRF2401_SendBuffer_Word(unsigned int TxData[],unsigned int DataWord);	
												// ����������д��nRF2401A
unsigned int  nRF2401_RxStatus();				// �ж�nRF2401A�Ƿ������ݽ���
void nRF2401_ReceiveByte(unsigned int RxData[]);// ��Byte��ʽ��nRF2401A������
void nRF2401_ReceiveWord(unsigned int RxData[]);// ��Word��ʽ��nRF2401A������
void nRF2401_SetAddress(unsigned int Address[],unsigned int AddrByte);
												// ����Ŀ��nRF2401A�ĵ�ַ
void Delay_Us();								// ��ʱ��uS��


#endif
