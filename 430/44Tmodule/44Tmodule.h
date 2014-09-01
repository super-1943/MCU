//����:����  2009.7.19
//����:�ĳ��İ�������
#ifndef _44T_module_h
#define _44T_module_h
#include<msp430x15x.h>
//***********************************************************
//����:��ʱ����
//����:��ʱ
//����:ms(����)
//ע��:����ʱ����û�о�������,���ܻ��нϴ����
//***********************************************************
void delay_44T(uint ms)
{
        uint i,j;
	for(i=0;i<ms;i++)
	   {
	   for(j=0;j<1141;j++);
       }
}
//************************************************************
//����:������⺯��
//����:�ж��Ƿ��м�������
//����:��
//************************************************************
uchar key_press_44T()
{
         uchar i;
         P5DIR=0XFF;
	 P5OUT=0X0F;
	 P5DIR=0XF0;
	 i=P5IN;
	 if(i==0X0F)//�ж����ŵ�ֵ�Ƿ��б仯���о����м�������
	 { 
	   return 0;
	 }
	 else
	 {
	   return 1;
	 }
}
//***************************************************************
//����:����ɨ�躯��
//����:�����һ����������
//����:��
//*****************************************************************
uchar key_scan_44T()
{
     uchar key,i=0,j;
     delay_44T(2);//һ��Ҫ�ɰ���ȥ��,��Ҳ����ʱ��̫��������ͼ�ⲻ����
	 if(key_press_44T())
               {
                  do
                      {
                       
                       P5OUT=~(1<<i);
                       P5DIR=0X0F;
                       key=P5IN;
                       j=key&0XF0;
                       i++;
                  }while(j==0XF0);//ѭ����⣬ֱ����⵽
                      
                 while(key_press_44T());//�ȴ������ɿ�
                 switch(key)
                      {
                 case 0xEE:
                              key=0x0;
                              break;
                 case 0xDE:
                              key=0x1;
                              break; 
                 case 0xBE:
                              key=0x2;
                              break;
                 case 0x7E:
                              key=0x3;
                              break;
                 case 0xED:
                              key=0x4;
                              break;
                 case 0xDD:
                              key=0x5;
                              break;
                 case 0xBD:
                              key=0x6;
                              break;
                 case 0x7D:
                              key=0x7;
                              break;
                 case 0xEB:
                              key=0x8;
                              break;
                 case 0xDB:
                              key=0x9;
                              break;
                 case 0xBB:
                              key=0xA;
                              break;
                 case 0x7B:
                              key=0xB;
                              break;
                 case 0xE7:
                              key=0xC;
                              break;
                 case 0xD7:
                              key=0xD;
                              break;
                 case 0xB7:
                              key=0xE;
                              break;
                 case 0x77:
                              key=0xF;
                              break;
                 default:
                      key=16;		
                      }
               }
	 else //�ٴμ��ʱû�м������£�����һ�ΰ�����⵽�İ��������Ƕ���
	 {
	    key=17;
	 }
	 return key;
}
#endif