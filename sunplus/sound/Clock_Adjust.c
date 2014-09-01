//======================================================
// �ļ����ƣ�	Clock_Adjust.c
// ����������	�������ں�ʱ��ĺ�����
// ά����¼��	2006-08-30	v1.0
//======================================================

#include "spce061a.h"
#include "Sound.h"
#include "Clock.h"
#include "Clock_Speech.h"
#include "Key.h"

//=============================================================
// �﷨��ʽ��	unsigned int AdjustYear(unsigned int Year);
// ʵ�ֹ��ܣ�	������
// ������		Year - ����ǰ����
// ����ֵ��		���������
//=============================================================
unsigned int AdjustYear(unsigned int Year)
{
	unsigned int KeyCode;
	unsigned int TempYear = Year;
	
	PlayYear(TempYear);								// ���ŵ�ǰ��
	while(1)
	{
		*P_Watchdog_Clear = 0x01;
		KeyCode = Key_Get();						// ��ȡ����
		switch(KeyCode)
		{
			case KEY_1:
				return TempYear;					// ��Key1�����ص��������
			case KEY_2:
				TempYear++;							// ��Key2����������1
				PlayYear(TempYear);
				break;
			case KEY_3:
				TempYear--;							// ��Key3����������1
				PlayYear(TempYear);
				break;
			default:
				break;
		}
	}
}

//=============================================================
// �﷨��ʽ��	unsigned int AdjustMon(unsigned int Mon);
// ʵ�ֹ��ܣ�	������
// ������		Mon - ����ǰ����
// ����ֵ��		���������
//=============================================================
unsigned int AdjustMon(unsigned int Mon)
{
	unsigned int KeyCode;
	unsigned int TempMon = Mon;
	
	PlayMon(TempMon);								// ��������ǰ����
	while(1)
	{
		*P_Watchdog_Clear = 0x01;
		KeyCode = Key_Get();
		switch(KeyCode)
		{
			case KEY_1:								// Key1�����ص��������
				return TempMon;
			case KEY_2:
				TempMon++;							// Key2��������1����12��ظ�Ϊ1
				if(TempMon>12) TempMon = 1;	
				PlayMon(TempMon);
				break;
			case KEY_3:
				TempMon--;							// Key3��������1����1���Ϊ12
				if(TempMon<1) TempMon = 12;
				PlayMon(TempMon);
				break;
			default:
				break;
		}
	}	
}

//=============================================================
// �﷨��ʽ��	unsigned int AdjustDay(unsigned int Year, unsigned int Mon, unsigned int Day);
// ʵ�ֹ��ܣ�	������
// ������		Year - ���������
//				Mon - ���������
//				Day - ����ǰ����
// ����ֵ��		���������
//=============================================================
unsigned int AdjustDay(unsigned int Year, unsigned int Mon, unsigned int Day)
{
	unsigned int KeyCode;
	unsigned int TempDay = Day;
	
	if(TempDay > Month_Day[Mon-1])					// �����ǰ�������Ѿ������������µ����������������Ϊ1
	{
		if(TempDay==29)								// ��������
		{
			if((Year&0x03)!=0) TempDay = 1;
		}
		else TempDay = 1;
	}
		
	PlayDay(TempDay);								// ���ŵ���ǰ��
	while(1)
	{
		*P_Watchdog_Clear = 0x01;
		KeyCode = Key_Get();
		switch(KeyCode)
		{
			case KEY_1:
				return TempDay;						// Key1�����ص�������
			case KEY_2:
				TempDay++;							// Key2��������1���ﵽ���������֮��ظ�Ϊ1
				if(TempDay > Month_Day[Mon-1])
				{
					if(TempDay==29)					// ��������
					{
						if((Year&0x03)!=0) TempDay = 1;
					}
					else TempDay = 1;
				}
				PlayDay(TempDay);
				break;
			case KEY_3:
				TempDay--;							// Key3��������1������0ʱתΪ���������
				if(TempDay<1)
				{
					 if(Mon==2 && (Year&0x03)==0) TempDay = 29;					 	
					 else TempDay = Month_Day[Mon-1];
				}
				PlayDay(TempDay);
				break;
			default:
				break;
		}
	}	
}

//=============================================================
// �﷨��ʽ��	unsigned int AdjustHour(unsigned int Hour);
// ʵ�ֹ��ܣ�	����Сʱ
// ������		Hour - ����ǰ��ʱ
// ����ֵ��		�������ʱ
//=============================================================
unsigned int AdjustHour(unsigned int Hour)
{
	unsigned int KeyCode;
	unsigned int TempHour = Hour;
	
	PlayHour(TempHour);								// ������ǰСʱ��
	while(1)
	{
		*P_Watchdog_Clear = 0x01;
		KeyCode = Key_Get();
		switch(KeyCode)
		{
			case KEY_1:
				return TempHour;					// Key1�����ص������Сʱ
			case KEY_2:
				TempHour++;							// Key2��ʱ����1����23��ظ�Ϊ0
				if(TempHour>23) TempHour = 0;
				PlayHour(TempHour);
				break;
			case KEY_3:
				if(TempHour==0) TempHour = 23;		// Key3��ʱ����1����0��ظ�Ϊ23
				else TempHour--;
				PlayHour(TempHour);
				break;
			default:
				break;
		}
	}	
}

//=============================================================
// �﷨��ʽ��	unsigned int AdjustMin(unsigned int Min);
// ʵ�ֹ��ܣ�	������
// ������		Min - ����ǰ�ķ�
// ����ֵ��		������ķ�
//=============================================================
unsigned int AdjustMin(unsigned int Min)
{
	unsigned int KeyCode;
	unsigned int TempMin = Min;
	
	PlayNum(TempMin);								// ��������ǰ�ķ�����
	PlaySnd(S_Fen);
	while(1)
	{
		*P_Watchdog_Clear = 0x01;
		KeyCode = Key_Get();
		switch(KeyCode)
		{
			case KEY_1:
				return TempMin;						// Key1�����ص�����ķ�
			case KEY_2:
				TempMin++;							// Key2����������1����59���Ϊ0
				if(TempMin>59) TempMin = 0;
				PlayNum(TempMin);
				PlaySnd(S_Fen);
				break;
			case KEY_3:
				if(TempMin==0) TempMin = 59;		// Key3����������1����0���Ϊ59
				else TempMin--;
				PlayNum(TempMin);
				PlaySnd(S_Fen);
				break;
			default:
				break;
		}
	}	
}

//=============================================================
// �﷨��ʽ��	unsigned int AdjustSec(unsigned int Sec);
// ʵ�ֹ��ܣ�	������
// ������		Sec - ����ǰ����
// ����ֵ��		���������
//=============================================================
unsigned int AdjustSec(unsigned int Sec)
{
	unsigned int KeyCode;
	unsigned int TempSec = Sec;
	
	PlaySec(TempSec);								// ��������ǰ������
	while(1)
	{
		*P_Watchdog_Clear = 0x01;
		KeyCode = Key_Get();
		switch(KeyCode)
		{
			case KEY_1:
				return TempSec;						// Key1�����ص��������
			case KEY_2:
				TempSec++;							// Key2�����1����59���Ϊ0
				if(TempSec>59) TempSec = 0;
				PlaySec(TempSec);
				break;
			case KEY_3:
				if(TempSec==0) TempSec = 59;		// Key3�����1����0���Ϊ59
				else TempSec--;
				PlaySec(TempSec);
				break;
			default:
				break;
		}
	}	
}

//=============================================================
// �﷨��ʽ��	void Adjust(void);
// ʵ�ֹ��ܣ�	��������ʱ��
// ������		��
// ����ֵ��		��
//=============================================================
void Adjust()
{
	unsigned int TempYear, TempMon, TempDay, TempHour, TempMin, TempSec;
	
	TempYear = AdjustYear(Clock_GetYear());			// ������
	TempMon = AdjustMon(Clock_GetMon());			// ������
	TempDay = AdjustDay(TempYear, TempMon, Clock_GetDay());	// ������
	TempHour = AdjustHour(Clock_GetHour());			// ����ʱ
	TempMin = AdjustMin(Clock_GetMin());			// ������
	TempSec = AdjustSec(Clock_GetSec());			// ������
	
	Clock_SetYear(TempYear);						// ��������������ʱ��
	Clock_SetMon(TempMon);
	Clock_SetDay(TempDay);
	Clock_SetHour(TempHour);
	Clock_SetMin(TempMin);
	Clock_SetSec(TempSec);

	PlaySnd(S_DING);								// ���������������ʱ��
	PlayYear(TempYear);
	PlayMon(TempMon);
	PlayDay(TempDay);
	PlayHour(TempHour);
	PlayMin(TempMin);	
}
