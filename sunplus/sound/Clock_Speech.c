//======================================================
// �ļ����ƣ�	Clock_Speech.c
// ����������	�����������ں�ʱ��ĺ�����
// ά����¼��	2006-08-30	v1.0
//======================================================

#include "Clock.h"
#include "Sound.h"

//=============================================================
// �﷨��ʽ��	void PlayNum(unsigned int Num);
// ʵ�ֹ��ܣ�	����100���ڵ�����
// ������		Num - ������������
// ����ֵ��		��
//=============================================================
void PlayNum(unsigned int Num)
{
	unsigned int TempNum = Num;
	
	if(TempNum==0)									// ����Ϊ0��ֱ�Ӳ���0
		PlaySnd(S_0);
	else
	{
		if(TempNum>=20) PlaySnd(TempNum/10);		// ʮλ
		if(TempNum>=10) PlaySnd(S_10);				// "ʮ"
		TempNum = TempNum % 10;
		if(TempNum>0) PlaySnd(TempNum);				// ��λ
	}
}

//=============================================================
// �﷨��ʽ��	void PlayYear(unsigned int Year);
// ʵ�ֹ��ܣ�	������
// ������		Year - ����������
// ����ֵ��		��
//=============================================================
void PlayYear(unsigned int Year)
{
	unsigned int TempYear = Year;
	
	PlaySnd(TempYear/1000);							// ǧλ
	TempYear = TempYear % 1000;
	PlaySnd(TempYear/100);							// ��λ
	TempYear = TempYear % 100;
	PlaySnd(TempYear/10);							// ʮλ
	TempYear = TempYear % 10;
	PlaySnd(TempYear);								// ��λ
	PlaySnd(S_Nian);								// "��"
}

//=============================================================
// �﷨��ʽ��	void PlayMon(unsigned int Mon);
// ʵ�ֹ��ܣ�	������
// ������		Mon - ����������
// ����ֵ��		��
//=============================================================
void PlayMon(unsigned int Mon)
{
	PlaySnd(Mon);
	PlaySnd(S_Yue);
}

//=============================================================
// �﷨��ʽ��	void PlayDay(unsigned int Day);
// ʵ�ֹ��ܣ�	������
// ������		Day - ����������
// ����ֵ��		��
//=============================================================
void PlayDay(unsigned int Day)
{
	PlayNum(Day);
	PlaySnd(S_Ri);
}

//=============================================================
// �﷨��ʽ��	void PlayHour(unsigned int Hour);
// ʵ�ֹ��ܣ�	����Сʱ
// ������		Hour - ��������ʱ
// ����ֵ��		��
//=============================================================
void PlayHour(unsigned int Hour)
{
	if(Hour<=5) PlaySnd(S_LC);						// �賿(0~5��)
	else if(Hour<=11) PlaySnd(S_SW);				// ����(6~11��)
	else if(Hour<=17) PlaySnd(S_XW);				// ����(12~17��)
	else PlaySnd(S_WS);								// ����(18~23��)
	
	if(Hour==2 || Hour==14) PlaySnd(S_Liang);		// 2���14�㲥��"��"
	else if(Hour>12) PlaySnd(Hour-12);				// 12Сʱ��
	else PlaySnd(Hour);
	PlaySnd(S_Dian);								// "��"
}

//=============================================================
// �﷨��ʽ��	void PlayMin(unsigned int Min);
// ʵ�ֹ��ܣ�	������
// ������		Min - �������ķ�
// ����ֵ��		��
//=============================================================
void PlayMin(unsigned int Min)
{
	if(Min==0)PlaySnd(S_Zheng);						// 00�ֲ���"��"
	else
	{
		PlayNum(Min);								// ��������
		PlaySnd(S_Fen);								// "��"
	}
}

//=============================================================
// �﷨��ʽ��	void PlaySec(unsigned int Sec);
// ʵ�ֹ��ܣ�	������
// ������		Sec - ����������
// ����ֵ��		��
//=============================================================
void PlaySec(unsigned int Sec)
{
	PlayNum(Sec);
	PlaySnd(S_Miao);
}

//=============================================================
// �﷨��ʽ��	void PlayTime();
// ʵ�ֹ��ܣ�	������ǰʱ��
// ������		��
// ����ֵ��		��
//=============================================================
void PlayTime()
{
	unsigned int TempHour, TempMin;
	
	TempHour = Clock_GetHour();
	TempMin = Clock_GetMin();
	
	PlaySnd(S_DING);
	PlaySnd(S_XZSK);
	PlayHour(TempHour);
	PlayMin(TempMin);
}

//=============================================================
// �﷨��ʽ��	void PlayDate();
// ʵ�ֹ��ܣ�	������ǰ����
// ������		��
// ����ֵ��		��
//=============================================================
void PlayDate()
{
	unsigned int TempYear, TempMon, TempDay;
	
	TempYear = Clock_GetYear();
	TempMon = Clock_GetMon();
	TempDay = Clock_GetDay();
	
	PlayYear(TempYear);
	PlayMon(TempMon);
	PlayDay(TempDay);
}
