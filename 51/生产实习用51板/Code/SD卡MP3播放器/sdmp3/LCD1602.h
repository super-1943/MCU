
#include<intrins.h>  //����_nop_()���������ͷ�ļ�
sbit RS=P3^7;    //�Ĵ���ѡ��λ����RSλ����ΪP2.0����
sbit RW=P3^6;    //��дѡ��λ����RWλ����ΪP2.1����
sbit E=P2^7;     //ʹ���ź�λ����Eλ����ΪP2.2����
sbit BF=P0^7;    //æµ��־λ������BFλ����ΪP0.7����
unsigned char code string[ ]= {"WELCOME TO YAN "}; 
unsigned char code string1[ ]={"SHAN UNIVERSITY"};
unsigned char code string2[ ]= {"      INIT "};
unsigned char code string3[ ]= {"  PLEASE WAIT"};
/*****************************************************
�������ܣ���ʱ1ms
***************************************************/
void delay1ms()
{
   		unsigned char i,j;	
	 	for(i=0;i<10;i++)
	  	for(j=0;j<33;j++)
	   ;		 
 }
 /*****************************************************
�������ܣ���ʱ���ɺ���
��ڲ�����n
***************************************************/
 void Lcddelay(unsigned int n)
 {
   	unsigned int i;
	for(i=0;i<n;i++)
	delay1ms();
 }
/*****************************************************
�������ܣ��ж�Һ��ģ���æµ״̬
����ֵ��result��result=1��æµ;result=0����æ
***************************************************/
 bit BusyTest(void)
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
void Write_com (unsigned char dictate)
{   
    while(BusyTest()==1); //���æ�͵ȴ�
	 RS=0;                  //���ݹ涨��RS��R/WͬʱΪ�͵�ƽʱ������д��ָ��
	 RW=0;   
	 E=0;                   //E�õ͵�ƽ(дָ��ʱ��
                             // ������E��0��1���������䣬����Ӧ����"0"
	 _nop_();
	 _nop_();             //�ղ��������������ڣ���Ӳ����Ӧʱ��
	 P0=dictate;            //����������P0�ڣ���д��ָ����ַ
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
***************************************************/
 void WriteAddress(unsigned char x)
 {
     Write_com(x|0x80); //��ʾλ�õ�ȷ�������涨Ϊ"80H+��ַ��x"	
 }
/*****************************************************
�������ܣ�������(�ַ��ı�׼ASCII��)д��Һ��ģ��
��ڲ�����y(Ϊ�ַ�����)
***************************************************/
 void WriteData(unsigned char y)
 {
    while(BusyTest()==1);  
	  RS=1;           //RSΪ�ߵ�ƽ��RWΪ�͵�ƽʱ������д������
	  RW=0;
	  E=0;            //E�õ͵�ƽ(дָ��ʱ����
                       // ������E��0��1���������䣬����Ӧ����"0"
	  P0=y;           //����������P0�ڣ���������д��Һ��ģ��
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
void LcdInt(void)
{
   	Lcddelay(15);             //��ʱ15ms���״�дָ��ʱӦ��LCDһ�νϳ��ķ�Ӧʱ��
   	Write_com(0x38);  //��ʾģʽ���ã�16��2��ʾ��5��7����8λ���ݽӿ�
	Lcddelay(5);   //��ʱ5ms��
	Write_com(0x38);
	Lcddelay(5);
	Write_com(0x38); //3��д ����ģʽ
	Lcddelay(5);
	Write_com(0x0C);  //��ʾģʽ���ã���ʾ�����й�꣬�����˸
	Lcddelay(5);
	Write_com(0x06);  //��ʾģʽ���ã�������ƣ��ַ�����
	Lcddelay(5);											  
	Write_com(0x01);  //����Ļָ�����ǰ����ʾ�������
	Lcddelay(5);
 }
 /**************************************************
 �������ܣ�ֱ�ӵ��øú������������Ӧ����ʾ
 ************************************************/
 void LcdShow(void)
 {unsigned char Lcd_i,Lcd_j;
    LcdInt();         //����LCD��ʼ������  
    Lcddelay(10);
    Write_com(0x01);//����ʾ������Ļָ��
    Lcddelay(5);
    WriteAddress(0x00);  // ������ʾλ��Ϊ��һ�еĵ�1����
    Lcddelay(5);
    Lcd_i = 0;
	     while(string[Lcd_i] != '\0')    //'\0'�����������־ 
			{						// ��ʾ�ַ�WELCOM TO YAN
					WriteData(string[Lcd_i]);
					Lcd_i++;
					Lcddelay(650);
			}			  

			 WriteAddress(0x40);  // ������ʾλ��Ϊ�ڶ��еĵ�1����
	  	     Lcd_i = 0;
		while(string1[Lcd_i] != '\0')   //'\0'�����������־
			{						// ��ʾ�ַ�	SHAN UNIVERSITY
					WriteData(string1[Lcd_i]);
					Lcd_i++;
					Lcddelay(650);
			}  
		Lcddelay(3000);	
			    

					//�Ҳ���λ����
				 	Write_com(0x01);//����ʾ������Ļָ��
				 	Lcddelay(30);
		 			WriteAddress(0x10);  // ������ʾλ��Ϊ���Ҳ�
					Lcddelay(30);
	  	     		Lcd_i = 0;
		while(string[Lcd_i] != '\0')    //'\0'�����������־ 
			{						// ��ʾ�ַ�	WELCOM TO YAN
					WriteData(string[Lcd_i]);
					Lcd_i++;	
					Lcddelay(10);
			}
			
			 WriteAddress(0x50);  // ������ʾλ��Ϊ�ڶ��еĵ�1����
	  	     Lcd_i = 0;
		while(string[Lcd_i] != '\0')   //'\0'�����������־
			{						// ��ʾ�ַ�	HAN UNIVERSITY
					WriteData(string1[Lcd_i]);
					Lcd_i++;
					Lcddelay(10);
			}
			for(Lcd_j=0;Lcd_j<16;Lcd_j++ ) 
			{
				Write_com(0x18); //����ָ��
				for(Lcd_i=0;Lcd_i<10;Lcd_i++)
        		Lcddelay(100);	   
					  
			}				
        	Lcddelay(3000);	
 } 
void LcdShow_init(void)
{ 	unsigned char Lcd_i;
 Write_com(0x01);//����ʾ������Ļָ��
    Lcddelay(5);
    WriteAddress(0x00);  // ������ʾλ��Ϊ��һ�еĵ�1����
    Lcddelay(5);
    Lcd_i = 0;
	     while(string2[Lcd_i] != '\0')    //'\0'�����������־ 
			{						// ��ʾ�ַ�WELCOM TO YAN
					WriteData(string2[Lcd_i]);
					Lcd_i++;
					Lcddelay(150);
			}			  

			 WriteAddress(0x40);  // ������ʾλ��Ϊ�ڶ��еĵ�1����
	  	     Lcd_i = 0;
		while(string3[Lcd_i] != '\0')   //'\0'�����������־
			{						// ��ʾ�ַ�	SHAN UNIVERSITY
					WriteData(string3[Lcd_i]);
					Lcd_i++;
					Lcddelay(150);
			}  
}
void UART_Send_Str1(char *s)
{  unsigned char Lcd_j;
Write_com(0x01);//����ʾ������Ļָ��
    Lcddelay(5);
    WriteAddress(0x00);  // ������ʾλ��Ϊ��һ�еĵ�1����
    Lcddelay(5);
    Lcd_j = 0;
	     while(s[Lcd_j] != '\0')    //'\0'�����������־ 
			{						// ��ʾ�ַ�WELCOM TO YAN
					WriteData(s[Lcd_j]);
					Lcd_j++;
					Lcddelay(150);
			}	
}