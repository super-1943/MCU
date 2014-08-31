#ifndef   __wl_18B20_H__
#define   __wl_18B20_H__

#define uchar unsigned char
#define uint unsigned int
#include<reg52.h>       //������Ƭ���Ĵ�����ͷ�ļ�

 /****************************************************/
sbit DQ=P1^3;			//18B20����
//sbit BEEP=P3^7;			//����������
/*****************************************************/
void Ds18B20_Delay(uint num);//��ʱ����
bit DS18B20_Init(); //��ʼ��ds1820		��ʱ30����
void Ds18B20_beep();		//��������һ������
DS18B20_ReadOneByte();//��һ���ֽ�		 ���ž��������ʱ
DS18B20_WriteOneByte(uchar dat);//дһ���ֽ�  ���ž��������ʱ
void DS18B20_display_error();	  //�������ܣ���ʾû�м�⵽DS18B20  
void DS18B20_display_explain(); //�������ܣ���ʾ˵����Ϣ
void DS18B20_display_symbol();	//�������ܣ���ʾ�¶ȷ���  
void DS18B20_display_dot(); //�������ܣ���ʾ�¶ȵ�С����  
void DS18B20_display_cent();	 //�������ܣ���ʾ�¶ȵĵ�λ(Cent)
void DS18B20_display_temp1(unsigned char x);//�������ܣ���ʾ�¶ȵ���������
void DS18B20_display_temp2(unsigned char x);  //�������ܣ���ʾ�¶ȵ�С��������
Ds18B20_GetTemperture();		   //��ȡ�¶�
void Ds18B20_TempConv();		   //ת�����ʺ���LCD����ʾ������
void Ds18B20_Display();			   //LCD��ʾ
#endif