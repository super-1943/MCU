 /*************************************************************************
�ļ����ƣ�I2C2.H 
�� �ߣ�   ������
�� ����   2008 7 25
˵ ����   ��ͷ�ļ���Ҫ���ڶ�I2C�����ĸ��ֲ���.(�ɶ�����а��ֽ�,����ַ,����,����,��
          д����.ʮ�ֺ���.
�޸ļ�¼��
  ע��:ע��: �����ǲ��������ʱ�ķ�������SCL����,�̶Ը߾���Ƶ��Ҫ�� 
һ�����޸�....(������1us��������,������Ƶ��ҪС��12MHZ).

**************************************************************************/

/**************************************************************************
�޸�1:�Խ��պ��������޸�,ԭ�ļ�ʱ��д��.
����:    2008-7-27
  bit IRecByte(uchar sla,uchar *ch)
{
  Start_I2c();
  SendByte(sla);
  if(ACK==0)    return 0;
  *ch=RecByte();
  Ack_I2c(1);
  Stop_I2c();
                return 1;
}
 bit IRecStr(uchar sla,uchar suba,uchar *ch,uchar n)
 {	uchar i;
    Start_I2c();
 	SendByte(sla);
       if(ACK==0)    return 0;
 	SendByte(suba);
        if(ACK==0)    return 0;
 	for(i=0;i<n;i++)
	{
	  *ch=RecByte();
	      Ack_I2c(1);
	   ch++;
     }
      Stop_I2c();
                return 1;
   }


****************************************************************************/
#ifndef __I2C2_H__
#define __I2C2_H__
/*************************************************************************/
#include "xuxiuliang.h"
/*************************************************************/
#define  _NOP _nop_()

sbit SCL=P1^6 ;
sbit SDA=P1^7 ;

bit  ACK      ;
/************************************************************
 �������ƣ�void Start_I2c(void) 
 �������ܣ� ��I2c����
 ��ڲ�����  ��
 ���ڲ�����  ��
 �� ע�� 

*************************************************************/
 void Start_I2c(void)
{
  SDA=1;
   _NOP;
  SCL=1;
  _NOP;             //��ʼ�źŽ���ʱ��Tsu:sta>=4.7us
  _NOP;			    
  _NOP;
  _NOP;
  _NOP;
  SDA=0;		    //������ʼ�ź�
  _NOP;			    //��ʼ�źű���ʱ��Thd:dat>=4us
  _NOP;
  _NOP;
  _NOP;
  SCL=0; 		    //ǯסI2C����׼�����ͻ��������
  _NOP;
  _NOP;        
}
/***************************************************************
�������ƣ�void Stop_I2c(void) 
�������ܣ�ֹͣI2c���� 
��ڲ����� ��
���ڲ����� ��
�� ע�� 


***************************************************************/
 void Stop_I2c(void)
{ 
 SDA=0;
 _NOP;
 SCL=1;
 _NOP;           //ֹͣ�źŽ���ʱ��Thd:sto>=4us
 _NOP;
 _NOP;
 _NOP;  
 SDA=1;			//����ֹͣ�ź�
 _NOP;			//�µ����ݿ�ʼǰ���߿���ʱ��Tbuf>=4.7us
 _NOP;
 _NOP;
 _NOP;
 _NOP;
 _NOP;
 }

 /***************************************************************
�������ƣ� 	void SendByte(uchar ch)
�������ܣ� 	����һ�ֽ�����(���ݻ��ַ,ָ�����)
��ڲ����� 	uchar ch     Ҫ���͵�1�ֽ�����
���ڲ����� 	��.  
�� ע�� 	 ��������ACK Ӧ��λ��Ӱ��,����Ӧ����Ϊ1,����Ϊ0


 *****************************************************************/
  void SendByte(uchar ch)
{
   uchar BitShift;        //��λ����
   for(BitShift=0;BitShift<8;BitShift++)
   {
     if((ch<<BitShift)&0x80)	  //�ж�����λ
	     SDA=1;
	 else SDA=0;			  //Thd:dat�������뱣��ʱ��0ns
	 SCL=1;					  //ʱ�Ӹߵ�ƽʱ��Thigh >4us
	 _NOP;
	 _NOP;
	 _NOP;
	 _NOP;
	 SCL=0;					  //ʱ�ӵ͵�ƽʱ��Tlow >4.7us
	}
	 _NOP;
	 _NOP;  
  	 SDA=1;                   //�ͷ��������� ����Ӧ���ź�
	 _NOP;
	 _NOP;
	 SCL=1;
	 _NOP;
	 _NOP;
	 _NOP;
	 if(SDA==0) 
	          ACK=1;		 //��Ӧ����Ϊ1
	 else     ACK=0;		 //��Ӧ�����������Ϊ0 
	 SCL=0;
	 _NOP;
	 _NOP;
}
/************************************************************
�������ƣ� uchar RecByte(void) 
�������ܣ� ����I2c�ӻ���������
��ڲ����� ��
���ڲ����� uchar RecByte()      �������ض���������
�� ע�� 
*************************************************************/
  uchar RecByte(void)
{
 uchar rec;					//���������
 uchar BitShift;
 rec=0;
 SDA=1;						//�ͷ���������
 for(BitShift=0;BitShift<8;BitShift++)
 { _NOP;
   SCL=0;					//ʱ�ӵ͵�ƽ����Tlow>4.7us
   _NOP;
   _NOP;
   _NOP;
   _NOP;
   SCL=1;				    //�ȴ������ź�
   _NOP;				   //ʱ�Ӹߵ�ƽ����Thigh>4us
   _NOP;
   rec=rec<<1;
   if(SDA==1) rec++;
   _NOP;
   _NOP;
  }
   SCL=0;
   _NOP;
   _NOP;
   return rec;
}
  /**********************************************
�������ƣ� void Ack_I2c(bit a)
�������ܣ� ����Ӧ����(���������մӻ����ݺ�ı�ҪӦ��)
��ڲ����� bit a
���ڲ����� ��
�� ע�� 

  ************************************************/
  void Ack_I2c(bit a)
{
  if(a==0) SDA=0;
       else     SDA=1;  
  _NOP;
  _NOP;
  _NOP;
  SCL=1;
  _NOP;						 //ʱ�Ӹߵ�ƽ����>4us
  _NOP;
  _NOP;
  _NOP;
  _NOP;
  SCL=0;					//��ʱ����,ǯסʱ��,�Ա��������
   _NOP;
   _NOP;
}
/************************************************************
               �����ӵ�ַ��������һ�ֽ����ݺ���
�������ƣ� bit ISendByte(uchar sla,uchar ch)
�������ܣ� ������������,������������ַsla,����ch��ȫ����.���ͳɹ�����1,���򷵻�0 
��ڲ�����  uchar sla ������ַ.uchar ch ����������
���ڲ����� 	bit ISendByte
�� ע�� 	ʹ��ǰ�����ѽ�������

***************************************************************/
bit ISendByte(uchar sla,uchar ch)
{
 Start_I2c();
 SendByte(sla);
 if(ACK==0) return 0;        // ��Ӧ��,��������,����0
 SendByte(ch);
 if(ACK==0) return 0;
 Stop_I2c();
            return 1;        //���ͳɹ�����1 
}
/********************************************************************
				  �����ӵ�ַ�������Ͷ��ֽ����ݺ���  

�������ƣ�bit ISendStr(uchar sla,uchar suba,uchar *ch,uchar n)
�������ܣ� �����ӵ�ַI2C�ӻ����ӵ�ַΪsuba�Ĵ洢��Ԫ����n������
��ڲ�����uchar sla ������ַ      uchar *ch �����͵������׵�ַ     
          uchar suba �����ӵ�ַ	  uchar n	�����͵����ݵĸ���
���ڲ�����bit ISendStr(uchar sla,uchar suba,uchar *ch,uchar n) 
�� ע��    ���ͳɹ����� 1,���ɹ�����0
*********************************************************************/
 bit ISendStr(uchar sla,uchar suba,uchar *ch,uchar n)
{
  uchar i;
  Start_I2c();
  SendByte(sla);
  if(ACK==0)     return 0;
  SendByte(suba); 
   if(ACK==0)    return 0;
  for(i=0;i<n;i++)
  {
   SendByte(*ch);
   if(ACK==0)    return 0;
   ch++;
   }
   Stop_I2c();
   return 1;
}
/********************************************************************
			 �����ӵ�ַ�������ֽ����ݺ���
�������ƣ� 	bit IRecByte(uchar sla,uchar *ch)
�������ܣ� 	��û���ӵ�ַ�Ĵӻ���ȡ����,����ָ��chָ��ĵ�ַ�ռ�
��ڲ����� 	uchar sla  �ӻ���ַ uchar *ch ����������ռʱ��ŵĵط�
���ڲ�����   bit IRecByte(uchar sla,uchar *ch)  ��������1���ʱ�����ɹ�,0Ϊʧ��
�� ע�� 
*******************************************************************/
  bit IRecByte(uchar sla,uchar *ch)
{
  Start_I2c();
     SendByte(sla+1);
  if(ACK==0)    return 0;
  *ch=RecByte();
  Ack_I2c(1);
  Stop_I2c();
                return 1;
}
/*******************************************************************************
         	 �����ӵ�ַ������ȡ���ֽ����ݺ���
�������ƣ� bit IRecStr(uchar sla,uchar suba,uchar *ch,uchar n)
�������ܣ� ���е�ַ������ȡ
��ڲ����� uchar sla �ӻ���ַ 	   uchar *ch  ָ��ָ���ȡ����
           uchar suba �ӻ��ӻ�ַ   uchar n    ��ȡ���ݵĸ���
���ڲ�����  bit IRecByte(uchar sla,uchar *ch)  ��������1���ʱ�����ɹ�,0Ϊʧ��
�� ע�� 


******************************************************************************/
 bit IRecStr(uchar sla,uchar suba,uchar *ch,uchar n)
 {	uchar i;
    Start_I2c();
 	SendByte(sla);
       if(ACK==0)    return 0;
 	SendByte(suba);
        if(ACK==0)    return 0;
	Start_I2c();			  // ����������,���͵�ַ,������.
	SendByte(sla+1);
	       if(ACK==0)    return 0;
 	for(i=0;i<n-1;i++)
	{
	  *ch=RecByte();
	      Ack_I2c(0);
	   ch++;
     }
	  *ch=RecByte();
            Ack_I2c(1);    
      Stop_I2c();
                return 1;
   }


 /* *****************************************************************************/
 #endif 