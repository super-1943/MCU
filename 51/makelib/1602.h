#ifndef  __wl_lcd1602_H__
#define	 __wl_lcd1602_H__	
#include<reg52.h>       //������Ƭ���Ĵ�����ͷ�ļ�

/*************************************************/
sbit RS=P2^0;            //�Ĵ���ѡ��λ����RSλ����ΪP2.0����
sbit RW=P2^1;            //��дѡ��λ����RWλ����ΪP2.1����
sbit E=P2^2;             //ʹ���ź�λ����Eλ����ΪP2.2����
sbit BF=P0^7;           //æµ��־λ������BFλ����ΪP0.7����	
#define Lcd_Data    P0 
                        //P0�ڲ������ݴ���

/***************************************************/					

void Lcd_delay1ms();		                   //�������ܣ���ʱ1ms    ע����ͬ��Ƭ����ͬ������Ҫ�Դ˺��������޸�
void Lcd_delay(unsigned int n);	               //�������ܣ���ʱ���ɺ���	  
bit Lcd_BusyTest();		                   //�������ܣ��ж�Һ��ģ���æµ״̬	  
void Lcd_WriteCom (unsigned char dictate);      //�������ܣ���ģʽ����ָ�����ʾ��ַд��Һ��ģ��	   
void Lcd_WriteAddress(unsigned char x);	       //�������ܣ�ָ���ַ���ʾ��ʵ�ʵ�ַ	
void Lcd_WriteData(unsigned char y);            //�������ܣ�������(�ַ��ı�׼ASCII��)д��Һ��ģ��
void Lcd_Int();                             //�������ܣ���LCD����ʾģʽ���г�ʼ������
 void hanying_show(void);     //��ӭ����
#endif