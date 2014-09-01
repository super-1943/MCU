#include"spce061a.h"
#include"ADConv.h"

unsigned long int uiData;
unsigned int i;
float fVoltage;
void ADInit()
{
	*P_ADC_MUX_Ctrl=C_ADC_CH5; //LINE_IN-------IOA4
	*P_ADC_Ctrl= C_ADCE; //ADC enable
	uiData=*P_ADC_LINEIN_Data; //ADC start
	fVoltage=0.0;
	uiData=0;
}
unsigned int AD(void)
{
	unsigned int uiData;
	while(!(*P_ADC_MUX_Ctrl&0x8000))//wait,until ADC complete
	{
		*P_Watchdog_Clear=C_WDTCLR; 
	}
	uiData=*P_ADC_LINEIN_Data;
	return(uiData&0xffc0);       //������˵�Ǹ�10λ��Ч����6λ�����塣����ֻ���ظ�10λ��
}
float ADtoVoltage()
{
	ADInit();
	for(i=0;i<8;i++)
	{
		*P_Watchdog_Clear=C_WDTCLR;
		uiData += AD();
	}
	uiData >>= 3;                //�ɼ�8�Σ�������3λ������8)�õ�ƽ��ֵ��
	fVoltage=(float)uiData/0xffc0;
	fVoltage*=2.5;    //����õ��ɼ���ѹ��
	*P_Watchdog_Clear=C_WDTCLR;
	return fVoltage;
}