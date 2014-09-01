//====================================================================================
//�� �� ��: nRF2401.c
//��������: nRF2401����������
//ά����¼: 2006��10��20
//====================================================================================

#include "spce061a.h"

#define	PWR		0x0001 							// IOB0
#define CE 		0x0002 							// IOB1
#define CS		0x0004 							// IOB2
#define DR1		0x0008 							// IOB3
#define	CLK1	0x0010 							// IOB4
#define DATA	0x0020 							// IOB5

const unsigned int InitData[15] = 				// nRF2401 ������ 15 Byte
{
	0x00,										// ͨ�����������ݿ�ȣ�bit��
	0x00,										// ͨ��һ�������ݿ�ȣ�bit��
	0x00,										// ͨ������ַ��A24��
	0x00,										// ͨ������ַ��A23��
	0x00,										// ͨ������ַ��A22��
	0x00,										// ͨ������ַ��A21��
	0x00,										// ͨ������ַ��A20��
	0x00,										// ͨ��һ��ַ��A14��
	0x00,										// ͨ��һ��ַ��A13��
	0x00,										// ͨ��һ��ַ��A12��
	0x00,										// ͨ��һ��ַ��A11��
	0x00,										// ͨ��һ��ַ��A10��
	0x03,										// b7~b2:���յ�ַ���,�ͷ��Ͷ�һ��,������40bit��
												// b1~b0:CRCģʽѡ��(01-8bit;11-16bit;00/10-no)
	0x4F,										// b15:����ͨ��ѡ��(0-ͨ��1;1-ͨ��1��2)
												// b14:�շ�ģʽ(0-Directģʽ,1-ShockBurstģʽ)
												// b13:������ѡ��(0-250Kbps;1-1Mbps)
												// b12~b10:����ѡ��(000-4M;001-8M;010-12M;011-16M)
												// b9~b8:���书��(11-0db)																
	0x64										// b7~b1:����Ƶ������
												// b0:�շ�����(0-����;1-����)
};
unsigned int AddrBuffer[5];						// ��ַ�Ĵ���
unsigned int AddrByteCnt;						// ��ַByte��

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

//=============================================================
// �﷨��ʽ��	void nRF2401_Initial(void)
// ʵ�ֹ��ܣ�	nRF ��ʼ��
// ������		��
// ����ֵ��		��
//=============================================================
void nRF2401_Initial(void)
{
	*P_SystemClock = 0x98;						// ����ϵͳʱ��Ϊ49MHz
	*P_IOB_Attrib |= (CS+DATA+PWR+CLK1+CE+DR1);
	*P_IOB_Dir |= (CS+DATA+PWR+CLK1+CE);
	*P_IOB_Dir&=~DR1;
	*P_IOB_Buffer &=~(CS+DATA+CLK1+CE+DR1);		// ��ʼ��IO�˿�

	nRF2401_ON();
	Delay_Us(3000);
	nRF2401_WriteCommand();						// ��nRF2401Aд������
	Delay_Us(300);
}

//=============================================================
// �﷨��ʽ��	void nRF2401_ON(void)
// ʵ�ֹ��ܣ�	nRF �ϵ�
// ������		��
// ����ֵ��		��
//=============================================================
void nRF2401_ON(void)
{
	*P_IOB_Buffer |= PWR;
}

//=============================================================
// �﷨��ʽ��	void nRF2401_OFF(void)
// ʵ�ֹ��ܣ�	nRF ����
// ������		��
// ����ֵ��		��
//=============================================================
void nRF2401_OFF(void)
{
	*P_IOB_Buffer &= ~PWR;
}

//=============================================================
// �﷨��ʽ��	void nRF2401_WriteCommand(void)
// ʵ�ֹ��ܣ�	nRF д������
// ������		��
// ����ֵ��		��
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
// �﷨��ʽ��	void nRF2401_Mode(unsigned int uiMode)
// ʵ�ֹ��ܣ�	����nRF2401A�Ĺ�����ʽ
// ������		uiMode:0--���գ�1--����					
// ����ֵ��		��
//=============================================================
void nRF2401_Mode(unsigned int uiMode)
{
	*P_IOB_Buffer &= ~CE;
	*P_IOB_Buffer |= CS;
	if(uiMode == 0)
		nRF2401_WriteByte(InitData[14] | 0x01);			// ����
	else
		nRF2401_WriteByte(InitData[14] & 0xFE);			// ����
	*P_IOB_Buffer &= ~CS;
	*P_IOB_Buffer |= CE;
}

//=============================================================
// �﷨��ʽ��	void nRF2401_SetAddress(unsigned int *Address,unsigned int AddrByte)
// ʵ�ֹ��ܣ�	����Ŀ��nRF2401A�ĵ�ַ
// ������		unsigned int *Address:��ַ����
//				unsigned int AddrByte:����ĳ���					
// ����ֵ��		��
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
// �﷨��ʽ��	void nRF2401_WriteByte(unsigned int uiData)
// ʵ�ֹ��ܣ�	��nRF2401Aд��һ���ֽ�����
// ������		unsigned int uiData: ��д������
// ����ֵ��		��
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
// �﷨��ʽ��	void nRF2401_WriteWord(unsigned int uiData)
// ʵ�ֹ��ܣ�	��nRF2401Aд��һ��������
// ������		unsigned int uiData: ��д������
// ����ֵ��		��
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
// �﷨��ʽ��	void nRF2401_SendByte(unsigned int TxData)
// ʵ�ֹ��ܣ�	��Ŀ���ַ+�ֽ�����д��nRF2401A
// ������		unsigned int TxData: �������ֽ�����
// ����ֵ��		��
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
// �﷨��ʽ��	void nRF2401_SendWord(unsigned int TxData)
// ʵ�ֹ��ܣ�	��Ŀ���ַ+������д��nRF2401A
// ������		unsigned int TxData: ������������
// ����ֵ��		��
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
// �﷨��ʽ��	void nRF2401_SendBuffer_Byte(unsigned int *TxData,unsigned int DataByte)
// ʵ�ֹ��ܣ�	��nRF2401A����һ����������ݣ��ֽڷ�ʽ��
// ������		unsigned int *TxData: ����������
//				unsigned int DataByte:����ĳ���					
// ����ֵ��		��
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
// �﷨��ʽ��	void nRF2401_SendBuffer_Word(unsigned int *TxData,unsigned int DataWord)
// ʵ�ֹ��ܣ�	��nRF2401A����һ�����������(�ַ�ʽ)
// ������		unsigned int *TxData: ����������
//				unsigned int DataWord:����ĳ���					
// ����ֵ��		��
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
// �﷨��ʽ��	unsigned int nRF2401_RxStatus()
// ʵ�ֹ��ܣ�	�ж�nRF2401A�Ľ���״̬
// ������		��
// ����ֵ��		0:	û�н��յ�����
//				1:	�Ѿ����յ����ݣ��ȴ�����
//=============================================================
unsigned int nRF2401_RxStatus()
{
	if((*P_IOB_Data&DR1) == 0)
		return(0);
	else
		return(1);
}

//=============================================================
// �﷨��ʽ��	void nRF2401_ReceiveByte(unsigned int *RxData)
// ʵ�ֹ��ܣ�	��nRF2401A����һ���ֽڵ�����
// ������		unsigned int *RxData:����������
// ����ֵ��		��
//=============================================================
void nRF2401_ReceiveByte(unsigned int *RxData)
{
	unsigned int i = 0,j = 0;
	unsigned int dat = 0;

	*P_IOB_Dir &= ~DATA;			// ����
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
	*P_IOB_Dir |= DATA;			// ���
}

//=============================================================
// �﷨��ʽ��	void nRF2401_ReceiveWord(unsigned int *RxData)
// ʵ�ֹ��ܣ�	��nRF2401A����һ���ֵ�����
// ������		unsigned int *RxData:����������
// ����ֵ��		��
//=============================================================
void nRF2401_ReceiveWord(unsigned int *RxData)
{
	unsigned int i = 0,j = 0;
	unsigned int dat = 0;

	*P_IOB_Dir &= ~DATA;			// ����
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
	*P_IOB_Dir |= DATA;			// ���
}

//=============================================================
// �﷨��ʽ��	void Delay_Us(unsigned int TimeCnt)
// ʵ�ֹ��ܣ�	��ʱ��uS��
// ������		unsigned int TimeCnt:��ʱ��us��
// ����ֵ��		��
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