					

#include<intrins.h>  //����_nop_()���������ͷ�ļ�
#include<1602.h>

unsigned char code string1[ ]= {"WELCOME TO YAN "};   //��һ����ʾ���ַ�
unsigned char code string2[ ]={"SHAN UNIVERSITY"};	  //�ڶ�����ʾ���ַ�

/*****************************************************
�������ܣ���ʱ1ms
ע����ͬ��Ƭ����ͬ������Ҫ�Դ˺��������޸�
***************************************************/
void Lcd_delay1ms()
{
   		unsigned char i,j;	
	 	for(i=0;i<25;i++)
	  	for(j=0;j<33;j++);		 
 }
 /*****************************************************
�������ܣ���ʱ���ɺ���
��ڲ�����n
***************************************************/
 void Lcd_delay(unsigned int n)
 {
   	unsigned int i;
	for(i=0;i<n;i++)
	Lcd_delay1ms();
 }
/*****************************************************
�������ܣ��ж�Һ��ģ���æµ״̬
����ֵ��result��result=1��æµ;result=0����æ
***************************************************/
 bit Lcd_BusyTest(void)
  {
    	bit result;
		RS=0;       //���ݹ涨��RSΪ�͵�ƽ��RWΪ�ߵ�ƽʱ�����Զ�״̬
    	RW=1;
    	E=1;        //E=1���������д
    	_nop_();   //�ղ���
    	_nop_();
    	_nop_(); 
   		_nop_();   //�ղ����ĸ��������ڣ���Ӳ����Ӧʱ��	
    	result=BF;  //��æµ��־��ƽ����result
		E=0;
    	return result;
  }
/*****************************************************
�������ܣ���ģʽ����ָ�����ʾ��ַд��Һ��ģ��
��ڲ�����dictate
***************************************************/
void Lcd_WriteCom (unsigned char dictate)
{   
    while(Lcd_BusyTest()==1); //���æ�͵ȴ�
	 RS=0;                  //���ݹ涨��RS��R/WͬʱΪ�͵�ƽʱ������д��ָ��
	 RW=0;   
	 E=0;                   //E�õ͵�ƽ(дָ��ʱ��
                             // ������E��0��1���������䣬����Ӧ����"0"
	 _nop_();
	 _nop_();             //�ղ��������������ڣ���Ӳ����Ӧʱ��
	 Lcd_Data=dictate;            //����������P0�ڣ���д��ָ����ַ
	 _nop_();
	 _nop_();
	 _nop_();
	 _nop_();               //�ղ����ĸ��������ڣ���Ӳ����Ӧʱ��
	 E=1;                   //E�øߵ�ƽ
	 _nop_();
	 _nop_();
	 _nop_();
	 _nop_();               //�ղ����ĸ��������ڣ���Ӳ����Ӧʱ��
	  E=0;                  //��E�ɸߵ�ƽ����ɵ͵�ƽʱ��Һ��ģ�鿪ʼִ������
 }
/*****************************************************
�������ܣ�ָ���ַ���ʾ��ʵ�ʵ�ַ
��ڲ�����x
ע���˺����Ѿ�������0x80,��ֻ��д��ʵ�ʵ�ַ����
***************************************************/
 void Lcd_WriteAddress(unsigned char x)
 {
     Lcd_WriteCom(x|0x80); //��ʾλ�õ�ȷ�������涨Ϊ"80H+��ַ��x"	
 }
/*****************************************************
�������ܣ�������(�ַ��ı�׼ASCII��)д��Һ��ģ��
��ڲ�����y(Ϊ�ַ�����)
***************************************************/
 void Lcd_WriteData(unsigned char y)
 {
    while(Lcd_BusyTest()==1);  
	  RS=1;           //RSΪ�ߵ�ƽ��RWΪ�͵�ƽʱ������д������
	  RW=0;
	  E=0;            //E�õ͵�ƽ(дָ��ʱ����
                       // ������E��0��1���������䣬����Ӧ����"0"
	  Lcd_Data=y;           //����������P0�ڣ���������д��Һ��ģ��
	  _nop_();
	  _nop_();
 	  _nop_();
    	  _nop_();       //�ղ����ĸ��������ڣ���Ӳ����Ӧʱ��
	  E=1;          //E�øߵ�ƽ
	  _nop_();
	  _nop_();
	  _nop_();
	  _nop_();        //�ղ����ĸ��������ڣ���Ӳ����Ӧʱ��
	  E=0;            //��E�ɸߵ�ƽ����ɵ͵�ƽʱ��Һ��ģ�鿪ʼִ������
 }
/*****************************************************
�������ܣ���LCD����ʾģʽ���г�ʼ������
***************************************************/
void Lcd_Int(void)
{
   	Lcd_delay(15);             //��ʱ15ms���״�дָ��ʱӦ��LCDһ�νϳ��ķ�Ӧʱ��
   	Lcd_WriteCom(0x38);  //��ʾģʽ���ã�16��2��ʾ��5��7����8λ���ݽӿ�
	Lcd_delay(5);   //��ʱ5ms��
	Lcd_WriteCom(0x38);
	Lcd_delay(5);
	Lcd_WriteCom(0x38); //3��д ����ģʽ
	Lcd_delay(5);
	Lcd_WriteCom(0x0C);  //��ʾģʽ���ã���ʾ�����й�꣬�����˸
	Lcd_delay(5);
	Lcd_WriteCom(0x06);  //��ʾģʽ���ã�������ƣ��ַ�����
	Lcd_delay(5);											  
	Lcd_WriteCom(0x01);  //����Ļָ�����ǰ����ʾ�������
	Lcd_delay(5);
 }
 void hanying_show(void)
 {  unsigned char Lcd_i;
 Lcd_WriteCom(0x01);//����ʾ������Ļָ��
	Lcd_delay(5);
	Lcd_WriteAddress(0x00);  // ������ʾλ��Ϊ��һ�еĵ�1����
    Lcd_delay(5);
	Lcd_i=0;
	while(string1[Lcd_i] != '\0')    //'\0'�����������־   // ��ʾ�ַ�WELCOM TO YAN
	  {						
		  Lcd_WriteData(string1[Lcd_i]);
		  Lcd_i++;
		  Lcd_delay(150);
	   }			  
								 
	Lcd_WriteAddress(0x40);  // ������ʾλ��Ϊ�ڶ��еĵ�1����
	 Lcd_i = 0;
	while(string2[Lcd_i] != '\0')   //'\0'�����������־
	  {						// ��ʾ�ַ�	SHAN UNIVERSITY
		  Lcd_WriteData(string2[Lcd_i]);
		  Lcd_i++;
		  Lcd_delay(150);
	   }  
	 Lcd_delay(1500);	
			    
      //�Ҳ���λ����
	Lcd_WriteCom(0x01);//����ʾ������Ļָ��
	Lcd_delay(5);
	Lcd_WriteAddress(0x10);  // ������ʾλ��Ϊ���Ҳ�
	Lcd_delay(5);
	Lcd_i = 0;
	while(string1[Lcd_i] != '\0')    //'\0'�����������־   	  ���Ƚ��ַ�����
	{						
	    Lcd_WriteData(string1[Lcd_i]);	 // ��ʾ�ַ�	WELCOM TO YAN
	    Lcd_i++;	
	    Lcd_delay(5);
	}
	Lcd_WriteAddress(0x50);  // ������ʾλ��Ϊ�ڶ��еĵ�1����
	Lcd_i = 0;
	while(string2[Lcd_i] != '\0')   //'\0'�����������־
		{						// ��ʾ�ַ�	HAN UNIVERSITY
	    	Lcd_WriteData(string2[Lcd_i]);
			Lcd_i++;
			Lcd_delay(5);
		}
	for(Lcd_i=0;Lcd_i<16;Lcd_i++ )  //��ʼ����
		{
			Lcd_WriteCom(0x18); //����ָ��
        	Lcd_delay(500);	   
					  
		}				
     Lcd_delay(1000);
	 Lcd_WriteCom(0x08);
	 Lcd_delay(400);
	 Lcd_WriteCom(0x0c);
	 Lcd_delay(400);
	 Lcd_WriteCom(0x08);
	 Lcd_delay(400);
	 Lcd_WriteCom(0x0c);
	 Lcd_delay(400);
	 Lcd_WriteCom(0x08);
	 Lcd_delay(400);
	 Lcd_WriteCom(0x0c);
	 Lcd_delay(400);
	 Lcd_WriteCom(0x08);
	 Lcd_delay(400);
	 Lcd_WriteCom(0x0c);
	 Lcd_delay(1);
	 Lcd_WriteCom(0x01);
	  Lcd_delay(1);

	 
   } 