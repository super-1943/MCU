/***************************************************
��K1��ʱ��ֹͣ�������ʱģʽ��ͬʱ��Ļ���½���ʾyear����K2����year��month��day��hour��minute֮���л���
��K3�����е�ʱ����ʱ��Ϻ�K4��ʱ�俪ʼ
**********************************************************************************************/


#ifndef  __wl_ds1302_H__
#define  __wl_ds1302_H__

/****************************************************/
sbit SCLK=P1^0;   //λ����1302оƬ�Ľӿڣ�ʱ������˿ڶ�����P1.0����
sbit DATA=P1^1;   //λ����1302оƬ�Ľӿڣ���������˶�����P1.1����
sbit RST=P1^2;    //λ����1302оƬ�Ľӿڣ���λ�˿ڶ�����P1.2����

sbit	K1 = P3^2;			//����K1��
sbit	K2 = P3^3;			//����K2��
sbit	K3 = P3^4;			//����K3��
sbit	K4 = P3^5;			//����K4��

sbit BEEP=P3^7 ;

/*******************************************************/
void Ds1302_delaynus(unsigned char n);  //�������ܣ���ʱ����΢��
void Ds1302_delay1ms();
void Ds1302_beep();		//��������һ������
void Ds1302_Write(unsigned char dat);   //�������ܣ���1302дһ���ֽ�����
void Ds1302_WriteSet(unsigned char Cmd,unsigned char dat);  //�������ܣ����������֣���1302дһ���ֽ�����
unsigned char Ds1302_Read();	//�������ܣ���1302��һ���ֽ�����
unsigned char  Ds1302_ReadSet(unsigned char Cmd); //�������ܣ����������֣���1302��ȡһ���ֽ�����
void Ds1302_Int();	//�������ܣ� 1302���г�ʼ������
void Ds1302_DisplaySecond(unsigned char x);  //������1302���ݵ���ʾ����
void Ds1302_DisplayMinute(unsigned char x); //�������ܣ���ʾ����
void Ds1302_DisplayHour(unsigned char x); //�������ܣ���ʾСʱ
void Ds1302_DisplayDay(unsigned char x); //�������ܣ���ʾ��
void Ds1302_DisplayMonth(unsigned char x);	  //�������ܣ���ʾ��
void Ds1302_DisplayYear(unsigned char x);  //�������ܣ���ʾ��
void Ds1302_QLShow();//�ڶ�Ӧλ����ʾdate ����
void time_get_show(); //��ȡʱ��
void KeyProcess();	 //����������
#endif