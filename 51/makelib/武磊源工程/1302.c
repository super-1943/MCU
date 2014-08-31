#include<1602.h>
#include<1302.h>
#include<hongwai.h>
extern unsigned char a[];	  //����ֻдextern����unsigned char
unsigned char code digit[11]={"0123456789-"};     //�����ַ�������ʾ����
bit K1_FLAG=0;				//���尴����־λ��������K1��ʱ����λ��1��K1��δ����ʱ����λΪ0��
unsigned char QH_FLAG=1;//��������������ʱ���л���־
char time_buf[7] ={0,0,0,0,0,0,0};		//DS1302ʱ�仺����������롢�֡�ʱ���ա��¡����ڡ���


/*****************************************************
�������ܣ���ʱ����΢��
��ڲ�����n
***************************************************/ 
void Ds1302_delaynus(unsigned char n)
{
 unsigned char i;
 for(i=0;i<n;i++);
}
/*****************************************************
�������ܣ���ʱ1ms
***************************************************/
void Ds1302_delay1ms()
{
   		unsigned char i,j;	
	 	for(i=0;i<10;i++)
	  	for(j=0;j<33;j++)
	   ;		 
 }

/*********************************************************/
void Ds1302_beep()		//��������һ������
{
  unsigned char i;
  for (i=0;i<100;i++)
   {
   Ds1302_delay1ms();
   BEEP=!BEEP;       //BEEPȡ��
   } 
   BEEP=1;           //�رշ�����
 //  Ds1302_delay(250);       //��ʱ     
}

/*****************************************************
�������ܣ���1302дһ���ֽ�����
��ڲ�����x
***************************************************/ 
void Ds1302_Write(unsigned char dat)
{
  unsigned char i; 
  SCLK=0;            //����SCLK��Ϊ����������д����������׼��
  //Ds1302_delaynus(2);       //��΢�ȴ���ʹӲ������׼��
  for(i=0;i<8;i++)      //����д8��������λ����
    {
	     DATA=dat&0x01;    //ȡ��dat�ĵ�0λ����д��1302  ��λ��ǰ����λ�ں�
	//	 Ds1302_delaynus(2);       //��΢�ȴ���ʹӲ������׼��
		 SCLK=1;           //������д������
	//	 Ds1302_delaynus(2);      //��΢�ȴ���ʹӲ������׼��
		 SCLK=0;           //��������SCLK���γ�����
		 dat>>=1;          //��dat�ĸ�����λ����1λ��׼��д����һ������λ
	  }
	
 }
/*****************************************************
�������ܣ����������֣���1302дһ���ֽ�����
��ڲ�����Cmd�����������֣�dat�������д������
***************************************************/ 
void Ds1302_WriteSet(unsigned char Cmd,unsigned char dat)
 {	  
        RST=0;           //��ֹ���ݴ���
        SCLK=0;          //ȷ��д����ǰSCLK������
	    RST=1;           //�������ݴ���
	    Ds1302_delaynus(2);     //��΢�ȴ���ʹӲ������׼��
	    Ds1302_Write(Cmd);  //д��������
	    Ds1302_Write(dat);  //д����
	    SCLK=1;          //��ʱ�ӵ�ƽ���ڸߵ�ƽ״̬
	    RST=0;           //��ֹ���ݴ���
 }
/*****************************************************
�������ܣ���1302��һ���ֽ�����
��ڲ�����x
***************************************************/ 
 unsigned char Ds1302_Read(void)
 {
    unsigned char i,dat;
//	Ds1302_delaynus(2);       //��΢�ȴ���ʹӲ������׼��
	for(i=0;i<8;i++)   //������8��������λ����
	 {	 dat>>=1;
		 if(DATA==1)    //���������������1
		 dat|=0x80;    //��1ȡ����д��dat�����λ
		 SCLK=1;       //��SCLK���ڸߵ�ƽ��Ϊ�½��ض���
		 //Ds1302_delaynus(2);  //��΢�ȴ�
		 SCLK=0;       //����SCLK���γ������½���
		// Ds1302_delaynus(2);  //��΢�ȴ�
	  }	 
  return dat;        //�����������ݷ���
}  
/*****************************************************
�������ܣ����������֣���1302��ȡһ���ֽ�����
��ڲ�����Cmd
ע�����������ݱ��밴����ʽ��ת��������ֱ����
***************************************************/ 
unsigned char  Ds1302_ReadSet(unsigned char Cmd)
 {
  unsigned char dat;
  RST=0;                 //����RST
  SCLK=0;                //ȷ��д����ǰSCLK������
  RST=1;                 //�������ݴ���
  Ds1302_Write(Cmd);       //д��������
  dat=Ds1302_Read();       //��������
  SCLK=1;              //��ʱ�ӵ�ƽ������֪״̬
  RST=0;               //��ֹ���ݴ���
  return dat;          //�����������ݷ���
}
/*****************************************************
�������ܣ� 1302���г�ʼ������
***************************************************/ 
void Ds1302_Int(void)
{	
    unsigned char flag;
   
    flag= Ds1302_ReadSet(0x81);
	if(flag&0x80)	{      //�ж�ʱ��оƬ�Ƿ�ر�
    Ds1302_WriteSet(0x8E,0x00);                 //����д״̬�Ĵ��������֣�д�벻����ָ�� 
   	Ds1302_WriteSet(0x80,((55/10)<<4|(55%10)));   //����д��Ĵ��������֣�д����ĳ�ʼֵ
	Ds1302_WriteSet(0x82,((59/10)<<4|(59%10)));   //����д�ּĴ��������֣�д��ֵĳ�ʼֵ
	Ds1302_WriteSet(0x84,((23/10)<<4|(23%10))); //����дСʱ�Ĵ��������֣�д��Сʱ�ĳ�ʼֵ
	Ds1302_WriteSet(0x86,((30/10)<<4|(18%10))); //����д�ռĴ��������֣�д���յĳ�ʼֵ
	Ds1302_WriteSet(0x88,((3/10)<<4|(6%10))); //����д�¼Ĵ��������֣�д���µĳ�ʼֵ
	Ds1302_WriteSet(0x8c,((11/10)<<4|(9%10)));  //����д��Ĵ��������֣�д����ĳ�ʼֵ
	Ds1302_WriteSet(0x90,0xa5);                //�򿪳�繦�� ѡ��2K�����緽ʽ
	Ds1302_WriteSet(0x8E,0x80);			   //����д״̬�Ĵ��������֣�д�뱣��ָ��
  }	 

  /*--------------------����ÿ�ζ���ʼ�������-----------------*/
   
  /* Ds1302_WriteSet(0x8E,0x00);                 //����д״̬�Ĵ��������֣�д�벻����ָ��
   Ds1302_WriteSet(0x80,((55/10)<<4|(55%10)));   //����д��Ĵ��������֣�д����ĳ�ʼֵ

	Ds1302_WriteSet(0x82,((59/10)<<4|(59%10)));   //����д�ּĴ��������֣�д��ֵĳ�ʼֵ

	Ds1302_WriteSet(0x84,((23/10)<<4|(23%10))); //����дСʱ�Ĵ��������֣�д��Сʱ�ĳ�ʼֵ

	Ds1302_WriteSet(0x86,((30/10)<<4|(18%10))); //����д�ռĴ��������֣�д���յĳ�ʼֵ

	Ds1302_WriteSet(0x88,((3/10)<<4|(6%10))); //����д�¼Ĵ��������֣�д���µĳ�ʼֵ

	Ds1302_WriteSet(0x8c,((11/10)<<4|(9%10)));   //����д��Ĵ��������֣�д����ĳ�ʼֵ

	Ds1302_WriteSet(0x90,0xa5);                //�򿪳�繦�� ѡ��2K�����緽ʽ

	Ds1302_WriteSet(0x8E,0x80);              //����д״̬�Ĵ��������֣�д�뱣��ָ��	*/

						
}
 /**************************************************************
������1302���ݵ���ʾ����
**************************************************************/
/*****************************************************
�������ܣ���ʾ��
��ڲ�����x
***************************************************/ 
void Ds1302_DisplaySecond(unsigned char x)
{
 unsigned char i,j;     //j,k�ֱ𴢴�ʮλ�͸�λ
	i=x/10;//ȡʮλ
	j=x%10;//ȡ��λ     
	Lcd_WriteAddress(0x49);    //д��ʾ��ַ,���ڵ�2�е�7�п�ʼ��ʾ
	Lcd_delay(1);
	Lcd_WriteData(digit[i]);    //����λ���ֵ��ַ�����д��LCD
	Lcd_delay(1);
	Lcd_WriteData(digit[j]);    //��ʮλ���ֵ��ַ�����д��LCD
	Lcd_delay(1);			 //��ʱ1ms��Ӳ��һ�㷴Ӧʱ��            
 }

/*****************************************************
�������ܣ���ʾ����
��ڲ�����x
***************************************************/ 
void Ds1302_DisplayMinute(unsigned char x)
{
 unsigned char i,j;     //j,kʮλ�͸�λ
	i=x/10;//ȡʮλ
	j=x%10;//ȡ��λ     
	Lcd_WriteAddress(0x46);    //д��ʾ��ַ,���ڵ�2�е�7�п�ʼ��ʾ
	Lcd_delay(1);
	Lcd_WriteData(digit[i]);    //����λ���ֵ��ַ�����д��LCD
	Lcd_delay(1);
	Lcd_WriteData(digit[j]);    //��ʮλ���ֵ��ַ�����д��LCD
	Lcd_delay(1);			 //��ʱ1ms��Ӳ��һ�㷴Ӧʱ��           
 }
/*****************************************************
�������ܣ���ʾСʱ
��ڲ�����x
***************************************************/ 
void Ds1302_DisplayHour(unsigned char x)
{
 unsigned char i,j;     //j,kʮλ�͸�λ
	i=x/10;//ȡʮλ
	j=x%10;//ȡ��λ     
	Lcd_WriteAddress(0x43);    //д��ʾ��ַ,���ڵ�2�е�7�п�ʼ��ʾ
	Lcd_delay(1);
	Lcd_WriteData(digit[i]);    //����λ���ֵ��ַ�����д��LCD
	Lcd_delay(1);
	Lcd_WriteData(digit[j]);    //��ʮλ���ֵ��ַ�����д��LCD
	Lcd_delay(1);		   //��ʱ1ms��Ӳ��һ�㷴Ӧʱ��            
 }
 /*****************************************************
�������ܣ���ʾ��
��ڲ�����x
***************************************************/ 
void Ds1302_DisplayDay(unsigned char x)
{
 	unsigned char i,j;     //j,kʮλ�͸�λ
	i=x/10;//ȡʮλ
	j=x%10;//ȡ��λ     
	Lcd_WriteAddress(0x0d);    //д��ʾ��ַ,���ڵ�2�е�7�п�ʼ��ʾ
	Lcd_delay(1);
	Lcd_WriteData(digit[i]);    //��ʮλ���ֵ��ַ�����д��LCD
	Lcd_delay(1);
	Lcd_WriteData(digit[j]);    //����λ���ֵ��ַ�����д��LCD
	Lcd_delay(1);		   //��ʱ1ms��Ӳ��һ�㷴Ӧʱ��           
 }
 /*****************************************************
�������ܣ���ʾ��
��ڲ�����x
***************************************************/ 
void Ds1302_DisplayMonth(unsigned char x)
{
 unsigned char i,j;     //j,k�ֱ𴢴�ʮλ�͸�λ
	i=x/10;//ȡʮλ
	j=x%10;//ȡ��λ     
	Lcd_WriteAddress(0x0a);    //д��ʾ��ַ,���ڵ�2�е�7�п�ʼ��ʾ
	Lcd_delay(1);
	Lcd_WriteData(digit[i]);    //��ʮλλ���ֵ��ַ�����д��LCD
	Lcd_delay(1);
	Lcd_WriteData(digit[j]);    //����λ���ֵ��ַ�����д��LCD
	Lcd_delay(1);		   //��ʱ1ms��Ӳ��һ�㷴Ӧʱ��            
 }
/*****************************************************
�������ܣ���ʾ��
��ڲ�����x
***************************************************/ 
void Ds1302_DisplayYear(unsigned char x)
{
 unsigned char i,j;     //j,k�ֱ𴢴�ʮλ�͸�λ
	i=x/10;//ȡʮλ
	j=x%10;//ȡ��λ     
	Lcd_WriteAddress(0x07);    //д��ʾ��ַ,���ڵ�2�е�7�п�ʼ��ʾ
	Lcd_delay(1);
	Lcd_WriteData(digit[i]);    //��ʮλλ���ֵ��ַ�����д��LCD
	Lcd_delay(1);
	Lcd_WriteData(digit[j]);    //����λ���ֵ��ַ�����д��LCD
	Lcd_delay(1);			//��ʱ1ms��Ӳ��һ�㷴Ӧʱ��           
 }
/**********************************************************
�������ܣ��ڶ�Ӧλ����ʾdate ����
*********************************************************/
void Ds1302_QLShow(void)
{ Lcd_WriteAddress(0x00);  //дDate����ʾ��ַ,���ڵ�1�е�2�п�ʼ��ʾ
  Lcd_delay(1);
  Lcd_WriteData('D');      //���ַ�����д��LCD
   Lcd_delay(1);
  Lcd_WriteData('a');      //���ַ�����д��LCD
   Lcd_delay(1);
  Lcd_WriteData('t');      //���ַ�����д��LCD
   Lcd_delay(1);
  Lcd_WriteData('e');      //���ַ�����д��LCD
   Lcd_delay(1);
  Lcd_WriteData(':');      //���ַ�����д��LCD
   Lcd_delay(1);
   Lcd_WriteData('2');      //���ַ�����д��LCD
   Lcd_delay(1);
  Lcd_WriteData('0');      //���ַ�����д��LCD
   Lcd_delay(1);
  Lcd_WriteAddress(0x09);  //д���·ָ�������ʾ��ַ�� ��ʾ�ڵ�1�е�9��
   Lcd_delay(1);
  Lcd_WriteData('-');      //���ַ�����д��LCD
   Lcd_delay(1);
  Lcd_WriteAddress(0x0c);  //д���շָ�������ʾ��ַ�� ��ʾ�ڵ�1�е�12��
   Lcd_delay(1);
  Lcd_WriteData('-');      //���ַ�����д��LCD
   Lcd_delay(1);
 Lcd_WriteAddress(0x0f);  //д���շָ�������ʾ��ַ�� ��ʾ�ڵ�1�е�12��
   Lcd_delay(1);
  Lcd_WriteData(' ');      //���ַ�����д��LCD 	  //д��ո��ֹ��Ļ��ʾ����
   Lcd_delay(1);
  Lcd_WriteAddress(0x45);  //дСʱ����ӷָ�������ʾ��ַ�� ��ʾ�ڵ�2�е�6��
   Lcd_delay(1);
  Lcd_WriteData(':');      //���ַ�����д��LCD
   Lcd_delay(1);
  Lcd_WriteAddress(0x48);  //д��������ָ�������ʾ��ַ�� ��ʾ�ڵ�2�е�9��
   Lcd_delay(1);
  Lcd_WriteData(':');      //���ַ�����д��LCD
   Lcd_delay(1);
}
/**********************************************************************************
�������ܣ���ȡʱ��
**********************************************************************************/
 void time_get_show(void)
{ unsigned char second,minute,hour,day,month,year;      //�ֱ𴢴��硢�֡�Сʱ���գ��£���
  unsigned char ReadValue;   //�����1302��ȡ������
  if(K1_FLAG==0)
  {
   if(K1==0)				//��K1������
	{
			Lcd_delay(10);		//��ʱ10msȥ��
			if(K1==0)
			{
				while(!K1);		//�ȴ�K1���ͷ�
				Ds1302_beep();		//��������һ��
				K1_FLAG=1;		//K1����־λ��1���Ա����ʱ�ӵ���
				ReadValue=Ds1302_ReadSet(0x8d);
				time_buf[6]=((ReadValue&0xf0)>>4)*10 + (ReadValue&0x0F);//����������ת��
				ReadValue=Ds1302_ReadSet(0x89);
				time_buf[4]=((ReadValue&0x70)>>4)*10 + (ReadValue&0x0F);//����������ת��
		        ReadValue=Ds1302_ReadSet(0x87);
				time_buf[3]=((ReadValue&0x70)>>4)*10 + (ReadValue&0x0F);//����������ת��
				ReadValue=Ds1302_ReadSet(0x85);
				time_buf[2]=((ReadValue&0x70)>>4)*10 + (ReadValue&0x0F);//����������ת��
		        ReadValue=Ds1302_ReadSet(0x83);
				time_buf[1]=((ReadValue&0x70)>>4)*10 + (ReadValue&0x0F);//����������ת��
				Lcd_WriteAddress(0x4d);  // ������ʾλ��Ϊ��һ�еĵ�1����
                Lcd_delay(5);
				Lcd_WriteData('Y');
				Lcd_delay(5); 
				QH_FLAG=1; //��K1��Ҫ�����㡱
			}
	}
	      if(a[2]==wl2)            //������⹦��
		{  		
		        K1_FLAG=1;		//K1����־λ��1���Ա����ʱ�ӵ���
				ReadValue=Ds1302_ReadSet(0x8d);
				time_buf[6]=((ReadValue&0xf0)>>4)*10 + (ReadValue&0x0F);//����������ת��
				ReadValue=Ds1302_ReadSet(0x89);
				time_buf[4]=((ReadValue&0x70)>>4)*10 + (ReadValue&0x0F);//����������ת��
		        ReadValue=Ds1302_ReadSet(0x87);
				time_buf[3]=((ReadValue&0x70)>>4)*10 + (ReadValue&0x0F);//����������ת��
				ReadValue=Ds1302_ReadSet(0x85);
				time_buf[2]=((ReadValue&0x70)>>4)*10 + (ReadValue&0x0F);//����������ת��
		        ReadValue=Ds1302_ReadSet(0x83);
				time_buf[1]=((ReadValue&0x70)>>4)*10 + (ReadValue&0x0F);//����������ת��
				Lcd_WriteAddress(0x4d);  // ������ʾλ��Ϊ��һ�еĵ�1����
                Lcd_delay(1);
				Lcd_WriteData('Y');
				Lcd_delay(1); 
				QH_FLAG=1; //��K1��Ҫ�����㡱
			    a[2]=0;	
		}
	}

  if(K1_FLAG==1)
		{ 
		KeyProcess();		//��K1_FLAGΪ1���������ʱ����
		}
  else{
  Lcd_WriteAddress(0x40);    //��ʾ�����ո��ֹ����
	Lcd_delay(1);
	Lcd_WriteData(' ');    
	Lcd_delay(1);
	Lcd_WriteData(' ');    
	Lcd_delay(1);		   
	Lcd_WriteData(' ');    
	Lcd_delay(1);        //��ʱ1ms��Ӳ��һ�㷴Ӧʱ�� 

    ReadValue = Ds1302_ReadSet(0x81);   //����Ĵ���������
     second=((ReadValue&0x70)>>4)*10 + (ReadValue&0x0F);//����������ת��
	  Ds1302_DisplaySecond(second);          //��ʾ��
	  ReadValue = Ds1302_ReadSet(0x83);  //�ӷּĴ�����
     minute=((ReadValue&0x70)>>4)*10 + (ReadValue&0x0F); //����������ת��
	  Ds1302_DisplayMinute(minute);	       //��ʾ��
     ReadValue = Ds1302_ReadSet(0x85);  //��ʱ�Ĵ�����
     hour=((ReadValue&0x70)>>4)*10 + (ReadValue&0x0F); //����������ת��
	  Ds1302_DisplayHour(hour);	             //��ʾСʱ
     ReadValue = Ds1302_ReadSet(0x87);  //�ӷּĴ�����
     day=((ReadValue&0x70)>>4)*10 + (ReadValue&0x0F); //����������ת��
	  Ds1302_DisplayDay(day);                //��ʾ��
	  ReadValue = Ds1302_ReadSet(0x89);  //�ӷּĴ�����
     month=((ReadValue&0x70)>>4)*10 + (ReadValue&0x0F); //����������ת��
	  Ds1302_DisplayMonth(month);            //��ʾ��
	  ReadValue = Ds1302_ReadSet(0x8d);  //�ӷּĴ�����
     year=((ReadValue&0xf0)>>4)*10 + (ReadValue&0x0F); //����������ת��
	  Ds1302_DisplayYear(year);              //��ʾ��

	  Lcd_WriteAddress(0x4b);    //��ʾ�ĸ��ո��ֹ����
	Lcd_delay(1);
	Lcd_WriteData(' ');    
	Lcd_delay(1);
	Lcd_WriteData(' ');
	Lcd_delay(1);
	Lcd_WriteData(' ');    
	Lcd_delay(1);		   
	Lcd_WriteData(' ');    
	Lcd_delay(1);        //��ʱ1ms��Ӳ��һ�㷴Ӧʱ��

	    }
}
/********�����ǰ���������********/
void KeyProcess()
{
  unsigned char min16,hour16,day16,month16,year16;				//����16���Ƶķ��Ӻ�Сʱ����
  Ds1302_WriteSet(0x8e,0x00);  			//DS1302д���������֣�����д
  Ds1302_WriteSet(0x80,0x80);                   //ʱ��ֹͣ����
   if(K2==0)                               //K2��������Сʱ���м�1����
  {
  	Lcd_delay(10);				//��ʱȥ��
  	if(K2==0)
  	{
			while(!K2);						//�ȴ�K2���ͷ�
			Ds1302_beep();	  
			QH_FLAG++;
			if(QH_FLAG>5)
			{ QH_FLAG=1;
			}	
			  
	   switch(QH_FLAG)
		{case 1:
		        Lcd_WriteAddress(0x4d);  // ������ʾλ��Ϊ��һ�еĵ�1����
                Lcd_delay(1);
				Lcd_WriteData('Y');
				Lcd_delay(1); break;
		 case 2:
		        Lcd_WriteAddress(0x4d);  // ������ʾλ��Ϊ��һ�еĵ�1����
                Lcd_delay(1);
				Lcd_WriteData('M');
				Lcd_delay(1);  break;
	     case 3:
		        Lcd_WriteAddress(0x4d);  // ������ʾλ��Ϊ��һ�еĵ�1����
                Lcd_delay(1);
				Lcd_WriteData('D');
				Lcd_delay(1);  break;
		  case 4:
		        Lcd_WriteAddress(0x4d);  // ������ʾλ��Ϊ��һ�еĵ�1����
                Lcd_delay(1);
				Lcd_WriteData('H');
				Lcd_delay(1);  break;
		  case 5:
		        Lcd_WriteAddress(0x4d);  // ������ʾλ��Ϊ��һ�еĵ�1����
                Lcd_delay(1);
				Lcd_WriteData('F');
				Lcd_delay(1);  break;
		}		                       
        }
		}

		if(a[2]==wl6)                              // ����K2��	   �����л�������
 	{
			 QH_FLAG++;
			if(QH_FLAG>5)
			{ QH_FLAG=1;
			    }	
			  
	   switch(QH_FLAG)
		{case 1:
		        Lcd_WriteAddress(0x4d);  // ������ʾλ��Ϊ��һ�еĵ�1����
                Lcd_delay(1);
				Lcd_WriteData('Y');
				Lcd_delay(1); break;
		 case 2:
		        Lcd_WriteAddress(0x4d);  // ������ʾλ��Ϊ��һ�еĵ�1����
                Lcd_delay(1);
				Lcd_WriteData('M');
				Lcd_delay(1);  break;
	     case 3:
		        Lcd_WriteAddress(0x4d);  // ������ʾλ��Ϊ��һ�еĵ�1����
                Lcd_delay(1);
				Lcd_WriteData('D');
				Lcd_delay(1);  break;
		  case 4:
		        Lcd_WriteAddress(0x4d);  // ������ʾλ��Ϊ��һ�еĵ�1����
                Lcd_delay(1);
				Lcd_WriteData('H');
				Lcd_delay(1);  break;
		  case 5:
		        Lcd_WriteAddress(0x4d);  // ������ʾλ��Ϊ��һ�еĵ�1����
                Lcd_delay(1);
				Lcd_WriteData('F');
				Lcd_delay(1);  break;
		}		                       
			 a[2]=0;

   	  }
	  if(a[2]==wl7)                              // ����K2��	   �����л�������
 	{
			 QH_FLAG--;
			if(QH_FLAG<1)
			{ QH_FLAG=5;
			    }	
			  
	   switch(QH_FLAG)
		{case 1:
		        Lcd_WriteAddress(0x4d);  // ������ʾλ��Ϊ��һ�еĵ�1����
                Lcd_delay(1);
				Lcd_WriteData('Y');
				Lcd_delay(1); break;
		 case 2:
		        Lcd_WriteAddress(0x4d);  // ������ʾλ��Ϊ��һ�еĵ�1����
                Lcd_delay(1);
				Lcd_WriteData('M');
				Lcd_delay(1);  break;
	     case 3:
		        Lcd_WriteAddress(0x4d);  // ������ʾλ��Ϊ��һ�еĵ�1����
                Lcd_delay(1);
				Lcd_WriteData('D');
				Lcd_delay(1);  break;
		  case 4:
		        Lcd_WriteAddress(0x4d);  // ������ʾλ��Ϊ��һ�еĵ�1����
                Lcd_delay(1);
				Lcd_WriteData('H');
				Lcd_delay(1);  break;
		  case 5:
		        Lcd_WriteAddress(0x4d);  // ������ʾλ��Ϊ��һ�еĵ�1����
                Lcd_delay(1);
				Lcd_WriteData('F');
				Lcd_delay(1);  break;
		}		                       
			 a[2]=0;

   	  }

	if(K3==0)                              // K3���������м�1����
 	{
 		Lcd_delay(10);                      //��ʱȥ��
      	if(K3==0)                                
 		{
			while(!K3);						//�ȴ�K3���ͷ�
			Ds1302_beep();
			switch(QH_FLAG)
		{	case 1:       
			time_buf[6]=time_buf[6]+1;       		//���1
       		if(time_buf[6]>99) time_buf[6]=0; 		//�����Ӽӵ�60ʱ��ʼ��Ϊ0
          	year16=time_buf[6]/10*16+time_buf[6]%10;  //�����õķ�������ת���16��������
			Ds1302_WriteSet(0x8c,year16);                //��������ķ�������д��DS1302	reak
			Lcd_WriteAddress(0x07);    //д��ʾ��ַ,���ڵ�2�е�7�п�ʼ��ʾ
	        Lcd_delay(1);
	        Lcd_WriteData(digit[time_buf[6]/10]);    //����λ���ֵ��ַ�����д��LCD,����ֱ��д�룬����ת��
	        Lcd_delay(1);
	        Lcd_WriteData(digit[time_buf[6]%10]);    //��ʮλ���ֵ��ַ�����д��LCD
	        Lcd_delay(1);
			break;

			case 2:        
			time_buf[4]=time_buf[4]+1;       		//�¼�1
       		if(time_buf[4]>12) time_buf[4]=1; 		//�����Ӽӵ�60ʱ��ʼ��Ϊ0
          	month16=time_buf[4]/10*16+time_buf[4]%10;  //�����õķ�������ת���16��������
			Ds1302_WriteSet(0x88,month16);                //��������ķ�������д��DS1302	reak
            Lcd_WriteAddress(0x0a);    //д��ʾ��ַ,���ڵ�2�е�7�п�ʼ��ʾ
	        Lcd_delay(1);
	        Lcd_WriteData(digit[time_buf[4]/10]);    //����λ���ֵ��ַ�����д��LCD
	        Lcd_delay(1);
	        Lcd_WriteData(digit[time_buf[4]%10]);    //��ʮλ���ֵ��ַ�����д��LCD
	        Lcd_delay(1);
			break;

			case 3:        
			time_buf[3]=time_buf[3]+1;         //�ռ�1  	
			 if((time_buf[4]==1)||(time_buf[4]==3)||(time_buf[4]==5)||(time_buf[4]==7)||(time_buf[4]==8)||(time_buf[4]==10)||(time_buf[4]==12))
			   {if(time_buf[3]>31)
				    time_buf[3]=1;  
				}
			if((time_buf[4]==4)||(time_buf[4]==6)||(time_buf[4]==9)||(time_buf[4]==11))
			   {if(time_buf[3]>30)
				    time_buf[3]=1;  
				}
			 if(time_buf[4]==2)
			 {	if((time_buf[6]%4)&&(time_buf[3]>28)) time_buf[3]=1;
			    if(!(time_buf[6]%4)&&(time_buf[3]>29)) time_buf[3]=1;
			 }
			 day16=time_buf[3]/10*16+time_buf[3]%10;
			 Ds1302_WriteSet(0x86,day16);                //��������ķ�������д��DS1302	reak
		     Lcd_WriteAddress(0x0d);    //д��ʾ��ַ,���ڵ�2�е�7�п�ʼ��ʾ
	         Lcd_delay(1);
	         Lcd_WriteData(digit[time_buf[3]/10]);    //����λ���ֵ��ַ�����д��LCD
	         Lcd_delay(1);
	         Lcd_WriteData(digit[time_buf[3]%10]);    //��ʮλ���ֵ��ַ�����д��LCD
	         Lcd_delay(1);
			 break;

			 case 4:        
			 time_buf[2]=time_buf[2]+1;       		//Сʱ��1
       		 if(time_buf[2]>23) time_buf[2]=0; 		//�����Ӽӵ�60ʱ��ʼ��Ϊ0
          	 hour16=time_buf[2]/10*16+time_buf[2]%10;  //�����õķ�������ת���16��������
			 Ds1302_WriteSet(0x84,hour16);                //��������ķ�������д��DS1302	reak
			 Lcd_WriteAddress(0x43);    //д��ʾ��ַ,���ڵ�2�е�7�п�ʼ��ʾ
	         Lcd_delay(1);
	         Lcd_WriteData(digit[time_buf[2]/10]);    //����λ���ֵ��ַ�����д��LCD
	         Lcd_delay(1);
	         Lcd_WriteData(digit[time_buf[2]%10]);    //��ʮλ���ֵ��ַ�����д��LCD
	         Lcd_delay(1);
       		 break;

			 case 5:        
			time_buf[1]=time_buf[1]+1;       		//Сʱ��1
       		if(time_buf[1]>59) time_buf[1]=0; 		//�����Ӽӵ�60ʱ��ʼ��Ϊ0
          	min16=time_buf[1]/10*16+time_buf[1]%10;  //�����õķ�������ת���16��������
			Ds1302_WriteSet(0x82,min16);                //��������ķ�������д��DS1302	reak
			Lcd_WriteAddress(0x46);    //д��ʾ��ַ,���ڵ�2�е�7�п�ʼ��ʾ
	        Lcd_delay(1);
	        Lcd_WriteData(digit[time_buf[1]/10]);    //����λ���ֵ��ַ�����д��LCD
	        Lcd_delay(1);
	        Lcd_WriteData(digit[time_buf[1]%10]);    //��ʮλ���ֵ��ַ�����д��LCD
	        Lcd_delay(1);
       		 break;
			 }

   	  }
 	}

		if(a[2]==wl4)   							//���� ��
		{  
		switch(QH_FLAG)
		{	case 1:       
			time_buf[6]=time_buf[6]+1;       		//���1
       		if(time_buf[6]>99) time_buf[6]=0; 		//�����Ӽӵ�60ʱ��ʼ��Ϊ0
          	year16=time_buf[6]/10*16+time_buf[6]%10;  //�����õķ�������ת���16��������
			Ds1302_WriteSet(0x8c,year16);                //��������ķ�������д��DS1302	reak
			Lcd_WriteAddress(0x07);    //д��ʾ��ַ,���ڵ�2�е�7�п�ʼ��ʾ
	        Lcd_delay(1);
	        Lcd_WriteData(digit[time_buf[6]/10]);    //����λ���ֵ��ַ�����д��LCD,����ֱ��д�룬����ת��
	        Lcd_delay(1);
	        Lcd_WriteData(digit[time_buf[6]%10]);    //��ʮλ���ֵ��ַ�����д��LCD
	        Lcd_delay(1);
			break;

			case 2:        
			time_buf[4]=time_buf[4]+1;       		//�¼�1
       		if(time_buf[4]>12) time_buf[4]=1; 		//�����Ӽӵ�60ʱ��ʼ��Ϊ0
          	month16=time_buf[4]/10*16+time_buf[4]%10;  //�����õķ�������ת���16��������
			Ds1302_WriteSet(0x88,month16);                //��������ķ�������д��DS1302	reak
            Lcd_WriteAddress(0x0a);    //д��ʾ��ַ,���ڵ�2�е�7�п�ʼ��ʾ
	        Lcd_delay(1);
	        Lcd_WriteData(digit[time_buf[4]/10]);    //����λ���ֵ��ַ�����д��LCD
	        Lcd_delay(1);
	        Lcd_WriteData(digit[time_buf[4]%10]);    //��ʮλ���ֵ��ַ�����д��LCD
	        Lcd_delay(1);
			break;

			case 3:        
			time_buf[3]=time_buf[3]+1;         //�ռ�1	�������� �·�
			if((time_buf[4]==1)||(time_buf[4]==3)||(time_buf[4]==5)||(time_buf[4]==7)||(time_buf[4]==8)||(time_buf[4]==10)||(time_buf[4]==12))
			   {if(time_buf[3]>31)
				    time_buf[3]=1;  
				}
			if((time_buf[4]==4)||(time_buf[4]==6)||(time_buf[4]==9)||(time_buf[4]==11))
			   {if(time_buf[3]>30)
				    time_buf[3]=1;  
				}
			 if(time_buf[4]==2)
			 {	if((time_buf[6]%4)&&(time_buf[3]>28)) time_buf[3]=1;
			    if(!(time_buf[6]%4)&&(time_buf[3]>29)) time_buf[3]=1;
			 }
			 day16=time_buf[3]/10*16+time_buf[3]%10;
			 Ds1302_WriteSet(0x86,day16);                //��������ķ�������д��DS1302	reak
		     Lcd_WriteAddress(0x0d);    //д��ʾ��ַ,���ڵ�2�е�7�п�ʼ��ʾ
	         Lcd_delay(1);
	         Lcd_WriteData(digit[time_buf[3]/10]);    //����λ���ֵ��ַ�����д��LCD
	         Lcd_delay(1);
	         Lcd_WriteData(digit[time_buf[3]%10]);    //��ʮλ���ֵ��ַ�����д��LCD
	         Lcd_delay(1);
			 break;

			 case 4:        
			 time_buf[2]=time_buf[2]+1;       		//Сʱ��1
       		 if(time_buf[2]>23) time_buf[2]=0; 		//�����Ӽӵ�60ʱ��ʼ��Ϊ0
          	 hour16=time_buf[2]/10*16+time_buf[2]%10;  //�����õķ�������ת���16��������
			 Ds1302_WriteSet(0x84,hour16);                //��������ķ�������д��DS1302	reak
			 Lcd_WriteAddress(0x43);    //д��ʾ��ַ,���ڵ�2�е�7�п�ʼ��ʾ
	         Lcd_delay(1);
	         Lcd_WriteData(digit[time_buf[2]/10]);    //����λ���ֵ��ַ�����д��LCD
	         Lcd_delay(1);
	         Lcd_WriteData(digit[time_buf[2]%10]);    //��ʮλ���ֵ��ַ�����д��LCD
	         Lcd_delay(1);
       		 break;

			 case 5:        
			time_buf[1]=time_buf[1]+1;       		//Сʱ��1
       		if(time_buf[1]>59) time_buf[1]=0; 		//�����Ӽӵ�60ʱ��ʼ��Ϊ0
          	min16=time_buf[1]/10*16+time_buf[1]%10;  //�����õķ�������ת���16��������
			Ds1302_WriteSet(0x82,min16);                //��������ķ�������д��DS1302	reak
			Lcd_WriteAddress(0x46);    //д��ʾ��ַ,���ڵ�2�е�7�п�ʼ��ʾ
	        Lcd_delay(1);
	        Lcd_WriteData(digit[time_buf[1]/10]);    //����λ���ֵ��ַ�����д��LCD
	        Lcd_delay(1);
	        Lcd_WriteData(digit[time_buf[1]%10]);    //��ʮλ���ֵ��ַ�����д��LCD
	        Lcd_delay(1);
       		 break;
			 }
			a[2]=0;
   	  }


	   if(K4==0)                              // ��
 	{		Lcd_delay(10);                      //��ʱȥ��
      	if(K4==0)                                
 		 {
			while(!K4);						//�ȴ�K4���ͷ�
			Ds1302_beep();
			switch(QH_FLAG)
		   {	
		    case 1:       
			time_buf[6]=time_buf[6]-1;       		//���1
       		if(time_buf[6]<0) time_buf[6]=99; 		//���굽60ʱ��ʼ��Ϊ0
          	year16=time_buf[6]/10*16+time_buf[6]%10;  //�����õķ�������ת���16��������
			Ds1302_WriteSet(0x8c,year16);                //��������ķ�������д��DS1302	reak
			Lcd_WriteAddress(0x07);    //д��ʾ��ַ,���ڵ�2�е�7�п�ʼ��ʾ
	        Lcd_delay(1);
	        Lcd_WriteData(digit[time_buf[6]/10]);    //����λ���ֵ��ַ�����д��LCD,����ֱ��д�룬����ת��
	        Lcd_delay(1);
	        Lcd_WriteData(digit[time_buf[6]%10]);    //��ʮλ���ֵ��ַ�����д��LCD
	        Lcd_delay(1);
			break;
			case 2:        
			time_buf[4]=time_buf[4]-1;       		//���1
       		if(time_buf[4]<1) time_buf[4]=12; 		//�����Ӽӵ�60ʱ��ʼ��Ϊ0
          	month16=time_buf[4]/10*16+time_buf[4]%10;  //�����õķ�������ת���16��������
			Ds1302_WriteSet(0x88,month16);                //��������ķ�������д��DS1302	reak
			Lcd_WriteAddress(0x0a);    //д��ʾ��ַ,���ڵ�2�е�7�п�ʼ��ʾ
	        Lcd_delay(1);
	        Lcd_WriteData(digit[time_buf[4]/10]);    //����λ���ֵ��ַ�����д��LCD,����ֱ��д�룬����ת��
	        Lcd_delay(1);
	        Lcd_WriteData(digit[time_buf[4]%10]);    //��ʮλ���ֵ��ַ�����д��LCD
	        Lcd_delay(1);
			break;
			case 3:        
			time_buf[3]=time_buf[3]-1;       		//���1
       		if((time_buf[4]==1)||(time_buf[4]==3)||(time_buf[4]==5)||(time_buf[4]==7)||(time_buf[4]==8)||(time_buf[4]==10)||(time_buf[4]==12))
			   {if(time_buf[3]<1)
				    time_buf[3]=31;  
				}
			if((time_buf[4]==4)||(time_buf[4]==6)||(time_buf[4]==9)||(time_buf[4]==11))
			   {if(time_buf[3]<1)
				    time_buf[3]=30;  
				}
			 if(time_buf[4]==2)
			 {	if((time_buf[6]%4)&&(time_buf[3]<1)) time_buf[3]=28;
			    if(!(time_buf[6]%4)&&(time_buf[3]<1)) time_buf[3]=29;
			 }
          	day16=time_buf[3]/10*16+time_buf[3]%10;  //�����õķ�������ת���16��������
			Ds1302_WriteSet(0x86,day16);                //��������ķ�������д��DS1302	reak
			Lcd_WriteAddress(0x0d);    //д��ʾ��ַ,���ڵ�2�е�7�п�ʼ��ʾ
	        Lcd_delay(1);
	        Lcd_WriteData(digit[time_buf[3]/10]);    //����λ���ֵ��ַ�����д��LCD,����ֱ��д�룬����ת��
	        Lcd_delay(1);
	        Lcd_WriteData(digit[time_buf[3]%10]);    //��ʮλ���ֵ��ַ�����д��LCD
	        Lcd_delay(1);
			break;
			 case 4:        
			time_buf[2]=time_buf[2]-1;       		//���1
       		if(time_buf[2]<0) time_buf[2]=23; 		//�����Ӽӵ�60ʱ��ʼ��Ϊ0
          	hour16=time_buf[2]/10*16+time_buf[2]%10;  //�����õķ�������ת���16��������
			Ds1302_WriteSet(0x84,hour16);                //��������ķ�������д��DS1302	reak
			Lcd_WriteAddress(0x43);    //д��ʾ��ַ,���ڵ�2�е�7�п�ʼ��ʾ
	        Lcd_delay(1);
	        Lcd_WriteData(digit[time_buf[2]/10]);    //����λ���ֵ��ַ�����д��LCD,����ֱ��д�룬����ת��
	        Lcd_delay(1);
	        Lcd_WriteData(digit[time_buf[2]%10]);    //��ʮλ���ֵ��ַ�����д��LCD
	        Lcd_delay(1);
			break;

			 case 5:        
			time_buf[1]=time_buf[1]-1;       		//���1
       		if(time_buf[1]<0) time_buf[1]=59; 		//�����Ӽӵ�60ʱ��ʼ��Ϊ0
          	min16=time_buf[1]/10*16+time_buf[1]%10;  //�����õķ�������ת���16��������
			Ds1302_WriteSet(0x82,min16);                //��������ķ�������д��DS1302	reak
			Lcd_WriteAddress(0x46);    //д��ʾ��ַ,���ڵ�2�е�7�п�ʼ��ʾ
	        Lcd_delay(1);
	        Lcd_WriteData(digit[time_buf[1]/10]);    //����λ���ֵ��ַ�����д��LCD,����ֱ��д�룬����ת��
	        Lcd_delay(1);
	        Lcd_WriteData(digit[time_buf[1]%10]);    //��ʮλ���ֵ��ַ�����д��LCD
	        Lcd_delay(1);
			break;
	}
	}

   	}
	  if(a[2]==wl5)                              // �����
 	{
			switch(QH_FLAG)
		   {	
		    case 1:       
			time_buf[6]=time_buf[6]-1;       		//���1
       		if(time_buf[6]<0) time_buf[6]=99; 		//���굽60ʱ��ʼ��Ϊ0
          	year16=time_buf[6]/10*16+time_buf[6]%10;  //�����õķ�������ת���16��������
			Ds1302_WriteSet(0x8c,year16);                //��������ķ�������д��DS1302	reak
			Lcd_WriteAddress(0x07);    //д��ʾ��ַ,���ڵ�2�е�7�п�ʼ��ʾ
	        Lcd_delay(1);
	        Lcd_WriteData(digit[time_buf[6]/10]);    //����λ���ֵ��ַ�����д��LCD,����ֱ��д�룬����ת��
	        Lcd_delay(1);
	        Lcd_WriteData(digit[time_buf[6]%10]);    //��ʮλ���ֵ��ַ�����д��LCD
	        Lcd_delay(1);
			break;
			case 2:        
			time_buf[4]=time_buf[4]-1;       		//�¼�1
       		if(time_buf[4]<1) time_buf[4]=12; 		//�����Ӽӵ�60ʱ��ʼ��Ϊ0
          	month16=time_buf[4]/10*16+time_buf[4]%10;  //�����õķ�������ת���16��������
			Ds1302_WriteSet(0x88,month16);                //��������ķ�������д��DS1302	reak
			Lcd_WriteAddress(0x0a);    //д��ʾ��ַ,���ڵ�2�е�7�п�ʼ��ʾ
	        Lcd_delay(1);
	        Lcd_WriteData(digit[time_buf[4]/10]);    //����λ���ֵ��ַ�����д��LCD,����ֱ��д�룬����ת��
	        Lcd_delay(1);
	        Lcd_WriteData(digit[time_buf[4]%10]);    //��ʮλ���ֵ��ַ�����д��LCD
	        Lcd_delay(1);
			break;
			case 3:        
			time_buf[3]=time_buf[3]-1;       		//�ռ�1
       		if((time_buf[4]==1)||(time_buf[4]==3)||(time_buf[4]==5)||(time_buf[4]==7)||(time_buf[4]==8)||(time_buf[4]==10)||(time_buf[4]==12))
			   {if(time_buf[3]<1)
				    time_buf[3]=31;  
				}
			if((time_buf[4]==4)||(time_buf[4]==6)||(time_buf[4]==9)||(time_buf[4]==11))
			   {if(time_buf[3]<1)
				    time_buf[3]=30;  
				}
			 if(time_buf[4]==2)
			 {	if((time_buf[6]%4)&&(time_buf[3]<1)) time_buf[3]=28;
			    if(!(time_buf[6]%4)&&(time_buf[3]<1)) time_buf[3]=29;
			 }
          	day16=time_buf[3]/10*16+time_buf[3]%10;  //�����õķ�������ת���16��������
			Ds1302_WriteSet(0x86,day16);                //��������ķ�������д��DS1302	reak
			Lcd_WriteAddress(0x0d);    //д��ʾ��ַ,���ڵ�2�е�7�п�ʼ��ʾ
	        Lcd_delay(1);
	        Lcd_WriteData(digit[time_buf[3]/10]);    //����λ���ֵ��ַ�����д��LCD,����ֱ��д�룬����ת��
	        Lcd_delay(1);
	        Lcd_WriteData(digit[time_buf[3]%10]);    //��ʮλ���ֵ��ַ�����д��LCD
	        Lcd_delay(1);
			break;
			 case 4:        
			time_buf[2]=time_buf[2]-1;       		//���1
       		if(time_buf[2]<0) time_buf[2]=23; 		//�����Ӽӵ�60ʱ��ʼ��Ϊ0
          	hour16=time_buf[2]/10*16+time_buf[2]%10;  //�����õķ�������ת���16��������
			Ds1302_WriteSet(0x84,hour16);                //��������ķ�������д��DS1302	reak
			Lcd_WriteAddress(0x43);    //д��ʾ��ַ,���ڵ�2�е�7�п�ʼ��ʾ
	        Lcd_delay(1);
	        Lcd_WriteData(digit[time_buf[2]/10]);    //����λ���ֵ��ַ�����д��LCD,����ֱ��д�룬����ת��
	        Lcd_delay(1);
	        Lcd_WriteData(digit[time_buf[2]%10]);    //��ʮλ���ֵ��ַ�����д��LCD
	        Lcd_delay(1);
			break;

			 case 5:        
			time_buf[1]=time_buf[1]-1;       		//���1
       		if(time_buf[1]<0) time_buf[1]=59; 		//�����Ӽӵ�60ʱ��ʼ��Ϊ0
          	min16=time_buf[1]/10*16+time_buf[1]%10;  //�����õķ�������ת���16��������
			Ds1302_WriteSet(0x82,min16);                //��������ķ�������д��DS1302	reak
			Lcd_WriteAddress(0x46);    //д��ʾ��ַ,���ڵ�2�е�7�п�ʼ��ʾ
	        Lcd_delay(1);
	        Lcd_WriteData(digit[time_buf[1]/10]);    //����λ���ֵ��ַ�����д��LCD,����ֱ��д�룬����ת��
	        Lcd_delay(1);
	        Lcd_WriteData(digit[time_buf[1]%10]);    //��ʮλ���ֵ��ַ�����д��LCD
	        Lcd_delay(1);
			break;
	}
			 a[2]=0;

   	}

 	if(K1==0)				//K1����ȷ�ϼ�
	{
		Lcd_delay(10);		//��ʱȥ��
		if(K1==0)
		{
			while(!K1);			//�ȴ�K4���ͷ�
			Ds1302_beep();
			Ds1302_WriteSet(0x80,0x00);  //������Ϻ�����ʱ������
 			Ds1302_WriteSet(0x8e,0x80);  //д���������֣���ֹд
			K1_FLAG=0;			//��K1�����±�־λ���� 
			Lcd_WriteAddress(0x4d);  // ������ʾλ��Ϊ��һ�еĵ�1����
            Lcd_delay(1);
		    Lcd_WriteData(' ');
		    Lcd_delay(1 );  
		}
	}
	if(a[2]==wl2)				//K4����ȷ�ϼ�
	{
		
			
			Ds1302_WriteSet(0x80,0x00);  //������Ϻ�����ʱ������
 			Ds1302_WriteSet(0x8e,0x80);  //д���������֣���ֹд
			K1_FLAG=0;			//��K1�����±�־λ���� 
			 Lcd_WriteAddress(0x4d);  // ������ʾλ��Ϊ��һ�еĵ�1����
                Lcd_delay(1);
				Lcd_WriteData(' ');
				Lcd_delay(1); 
				a[2]=0; 
	}
}