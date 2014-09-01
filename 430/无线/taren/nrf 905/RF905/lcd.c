///****************************************************************//
//Һ����ʾģ�飬����ATmega8��Ƭ����OCM4*8Һ�������з�ʽ
//����PORTD�ĸ���λ
//pd5---lcd_cs
//pd7---lcd_sdat
//pd6---lcd_sclk
//�ܽ��2006��7��20������
///****************************************************************//
///////////////////////////////////////////////////
//lcd��ʼ������
//////////////////////////////////////////////////
#include <stdio.h>
#include <iom8v.h>
#include <macros.h>


///////////////////////////////////////////////
//
//////////////////////////////////////////////
void delay(unsigned int times)
{unsigned int i;
for(i=0;i<times;i++)
;
}

void lcd_send_byte(char data)
{unsigned int i,data1;
for(i=0;i<8;i++)
{data1=data&0x80;       //test data bit7 Ϊ��������㣬Ϊһ�����һ
 if(data1!=0)
 { PORTD|=BIT(PD7);
     delay(20);
  }
 else {PORTD&=~BIT(PD7);          ///����Ƭ���ٶ�̫��ʱ������ʱ
     delay(20); }
	   
//PORTD=PORTD&data;
PORTD|=BIT(PD6);     // set sclk high

PORTD&=~BIT(PD6);    // set sclk low
data=data<<1;
}
}
/////////////////////////////////////////////////////////////
////
////////////////////////////////////////////////////////////
void lcd_write_data(char data)
{char data1=0xfa,data2,data3;
    
	PORTD|=BIT(PD5);      //set cs high
	
   data2=data&0xf0;
   data3=data&0x0f;
   data3=data3<<4;
   
   lcd_send_byte(data1);
   lcd_send_byte(data2);
   lcd_send_byte(data3);
   
   PORTD&=~BIT(PD5);       //set cs low

}
/////////////////////////////////////////////////////////////
////
////////////////////////////////////////////////////////////
void lcd_write_comm(char data)
//int data;
{char data1=0xf8,data2,data3;
   PORTD|=BIT(PD5);     //set cs high
   
   data2=data&0xf0;
   data3=data&0x0f;
   data3=data3<<4;
   
   lcd_send_byte(data1);
   lcd_send_byte(data2);
   lcd_send_byte(data3);
   
   PORTD&=~BIT(PD5);     //set cs low

}
void lcd_initial(void)
{
    
   lcd_write_comm(0x30);			//����ָ�
   lcd_write_comm(0x01);			//�����ʾ��Ļ����DDRAMλַ����������Ϊ"00H"
   lcd_write_comm(0x03);			//��DDRAMλַ����������Ϊ"00H"���α��ԭ�㣬�ù��ܲ�Ӱ����ʾDDRAM
   lcd_write_comm(0x06);			//�������
   lcd_write_comm(0x0c);			//��ʾ����
}
/////////////////////////////////////////////////////
////
/////////////////////////////////////////////////////

void screen(data)
char data[65];

 {         
	    unsigned int i,j;
		lcd_write_comm(0x08);
		for (i=0;i<64;i++)
			{lcd_write_data(data[i]);
			if (i==15)
			lcd_write_comm(0x90);      //�趨DDRAM�ڶ��У���һ��
			if (i==31)
			lcd_write_comm(0x88);     //�趨DDRAM�����У���һ��
			if (i==47)
			lcd_write_comm(0x98);     //�趨DDRAM�����У���һ��
			if (i==63)
			lcd_write_comm(0x80);     //�趨DDRAM��һ�У���һ��
			}
		lcd_write_comm(0x0c);
}	
//////////////////////////////////
void fanxian(unsigned char hang)   //  0x80-1     0x90-2   0x88-3    0x98-4
	{	
	    unsigned char x,y,i,j;
	     lcd_write_comm(0x34);        //������ͼ������ʾ 
		 lcd_write_comm(0x34);
	    
	    y=0x80;
        x=0x80;
		lcd_write_data(0x00);
		lcd_write_comm(x);             //����x ���� 
		lcd_write_comm(y); 
		for (j=0;j<32;j++)
		  {for (i=0;i<16;i++)
			lcd_write_data(0x00);
		
			
			lcd_write_comm(++x);
			lcd_write_comm(y);
			
		  }
		
        y=0x88; 
		x=0x80;
		lcd_write_data(0x00);
     	lcd_write_comm(x);
		lcd_write_comm(y);
		for (j=32;j<64;j++)
		  {for (i=0;i<16;i++)
			lcd_write_data(0x00);
			lcd_write_comm(++x);
			lcd_write_comm(y); 	 
			
		  
		  }
		    
		  lcd_write_comm(0x36);        //������ͼ������ʾ 	
		    	
		if(hang==1)
    	{
    	y=0x80; 
		x=0x80;}
		else if(hang==2)
		{
		y=0x80;
		x=0x90;}
		else if(hang==3)
		{y=0x88;
		 x=0x80;}
		else
		{y=0x88;
		x=0x90;}
		
		lcd_write_comm(x);             //����x ���� 
		lcd_write_comm(y);             //����y ����

		
		for (j=0;j<16;j++)
		  {for (i=0;i<16;i++)
			lcd_write_data(0xff);
	
			lcd_write_comm(++x);
			lcd_write_comm(y);
			
		  }
		// lcd_write_comm(0x36);        //������ͼ������ʾ   
    } 
//////////////////////////////////////////////////////
///
//////////////////////////////////////////////////
/*
void fanbai(char data)
{	lcd_write_comm(0x0034);       //�رջ�ͼ��ʾ����
		
		y=data;
        x=0x0080;
		lcd_write_comm(x);             //����x ���� 
		lcd_write_comm(y); 
		for (j=0;j<32;j++)
		  {for (i=0;i<16;i++)
			lcd_write_data(0x0000);
		
			
			lcd_write_comm(++x);
			lcd_write_comm(y);
			*P_Watchdog_Clear=0x0001;
		  }
		y=0x0088; 
		x=0x0080;
	    		  
	lcd_write_comm(0x0036);        //������ͼ������ʾ 
}


*/

/*********************************************************************************
/**Һ������С���ܵ�ʵ��
//*********************************************************************************
   //  ���α�,ʹ�α�λ�õ��ֺ���������.����Ӣ��,��������ַ�.

lcd_lcd_write_comm(0x30);
lcd_lcd_write_comm(0x  );   //�˴����趨���α�λ��
lcd_lcd_write_comm(0x0d);     
*/
/***2   ���α�,ʹ�α�λ�õ��������һ����.����Ӣ��,����߿����ַ�.
lcd_lcd_write_comm(0x30);
lcd_lcd_write_comm(0x  );   //�˴����趨���α�λ��
lcd_lcd_write_comm(0x0e);
*/
/***3   ���α�,ʹ�α�λ�õ��������һ����,���������뷴����ʾ���.����Ӣ��,�������ַ�.
lcd_lcd_write_comm(0x30);
lcd_lcd_write_comm(0x  );   //�˴����趨���α�λ��
lcd_lcd_write_comm(0x0f);
*/


/*************���Գ���
lcd_lcd_write_comm(0x34);    //����ָ�����
lcd_lcd_write_comm(0x04);            //1.3�г��ַ���
lcd_lcd_write_comm(0x05);          //2,4���б仯 .����ʵ�����ѡ��.ֻ�ɿ�����,ȫ��û�仯*/