/******************************************************************

#include<reg52.h>       //������Ƭ���Ĵ�����ͷ�ļ�
#include<1602.h>
#include<1302.h>
#include<18b20.h>
#include<hongwai.h>
unsigned char code string[ ]= {"1602IR-CODE TEST"};
extern unsigned char keyflag;
void main()
{  unsigned char Hw_i;
Ds1302_Int();       //��1302��ʼ��
 Lcd_Int();			 //1602��ʼ��
 Hw_Int();
 //hanying_show();
 while(1)
 {   if(!keyflag)			//��ʾʱ��
     {
	 Ds1302_QLShow();	 //�ڶ�Ӧλ����ʾdata����
      time_get_show(); //��ȡʱ��
	  }
	  if(keyflag==1)
	  {	if(DS18B20_Init()==1)	  //���жϵ�ͬʱ�ֽ����˳�ʼ��
	  DS18B20_display_error();	
	  else{DS18B20_display_explain();	  //��ʾ�¶�˵��
   	   DS18B20_display_symbol();     //��ʾ�¶ȷ���
       DS18B20_display_dot();       //��ʾ�¶ȵ�С����
       DS18B20_display_cent();      //��ʾ�¶ȵĵ�λ
	   Ds18B20_GetTemperture();		//��ȡ�¶�ֵ
	   Ds18B20_TempConv();			//���¶�ת��Ϊ�ʺ�LCD��ʾ������
	   Ds18B20_Display();	  
	      }
	  }
	  if(keyflag==2)
	  {Lcd_WriteAddress(0x00);  // ������ʾλ��Ϊ��һ�еĵ�1����
	  Hw_delay(5);
	  Hw_i = 0;
		while(string[Hw_i] != '\0')    //'\0'�����������־ 
			{						// ��ʾ�ַ�	WWW.RICHMCU.COM
				Lcd_WriteData(string[Hw_i]);
				Hw_i++;
				Hw_delay(5);	
			}
			Hw_Disp();	 
        }
   }
   }

 ���ߣ�����
 ʱ�䣺2011-3-30
 ���ܣ�������ʱ�䣬�¶ȣ��������֮���л���ʱ��ĵ����ȿ����ð���Ҳ������ң����
*****************************************************************/