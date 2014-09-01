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
	return(uiData&0xffc0);       //资料上说是高10位有效，低6位无意义。所以只返回高10位。
}
float ADtoVoltage()
{
	ADInit();
	for(i=0;i<8;i++)
	{
		*P_Watchdog_Clear=C_WDTCLR;
		uiData += AD();
	}
	uiData >>= 3;                //采集8次，再右移3位（除以8)得到平均值。
	fVoltage=(float)uiData/0xffc0;
	fVoltage*=2.5;    //计算得到采集电压。
	*P_Watchdog_Clear=C_WDTCLR;
	return fVoltage;
}