//************************************************************//
//��ģ��������ʾ�������й�������Ҫ��ʾ��һЩ���ݣ��ɰ���Ҫ�Ķ�
//ע�⣺��Ҫ��ʾ��������Ϊ�ⲿ����
//�ܽ����
//**********************************************************//
#include <stdio.h>
#include <iom8v.h>
#include <macros.h>


void display4(unsigned char kk)  //��ʱ���鷳
{ 
  lcd_write_comm(0x30);
  lcd_write_comm(0x0c);
  switch(kk)
	 {case 1: 
	  case 2: 
	  case 3: 
	  case 4:
	  case 5:
	  case 6:  
	  case 7: 
	  case 8:
	  case 9: 		  
	  case 0:  lcd_write_comm(0x98); displaybyte2(kk); break;	
	  case 13: lcd_write_comm(0x98);lcd_write_data('F');lcd_write_data('1'); break;		
	  case 14: lcd_write_comm(0x98);lcd_write_data('F');lcd_write_data('2'); break; 
	  case 15: lcd_write_comm(0x98);lcd_write_data('F');lcd_write_data('2'); break;	  
	  case 16: lcd_write_comm(0x98);lcd_write_data('F');lcd_write_data('4');  break; 
	  case '*':lcd_write_comm(0x98);lcd_write_data(' ');lcd_write_data('*'); break;		
	  case '#':lcd_write_comm(0x98);lcd_write_data(' ');lcd_write_data('#');   break;
	  default: lcd_write_comm(0x98);lcd_write_data('N');lcd_write_data('O'); break;
     }  
   
}

void displaybyte(unsigned char data)
{ 
  lcd_write_data(data/100%10+0x30);
  lcd_write_data(data/10%10+0x30);
  lcd_write_data(data%10+0x30); 
}
void displayint(unsigned char address,unsigned char data)
{   lcd_write_comm(0x30);
    lcd_write_comm(address);
	displaybyte(data);
}

void displaybyte2(unsigned char data)
{ 
  lcd_write_data(data/10%10+0x30);
  lcd_write_data(data%10+0x30); 
}
//////////////////////////////////////////////////////////////////////
//*Ptr       �ַ������׵�ַ 
//address    Һ�����ĵ�ַ0x80-0x8f,0x90-0x9f֮��
//len        ��ʾ�����ݵĳ���,����������油�ո�
/////////////////////////////////////////////////////////////////////
void display_char(unsigned char *Ptr ,unsigned char address,unsigned char len)
{   unsigned char i;

    lcd_write_comm(0x30);
    lcd_write_comm(address);
    lcd_write_comm(0x0c);
	for(i=0;i<len;i++)
	{
	if(*Ptr!='/0')
	lcd_write_data(*Ptr++);
	else
	lcd_write_data(' ');
	}
}

//////////////////////////////////////////////////////////////////////
//*Ptr       �ַ������׵�ַ 
//address    Һ�����ĵ�ַ0x80-0x8f,0x90-0x9f֮��
//len        ��ʾ�����ݵĳ���,����������油�ո�
/////////////////////////////////////////////////////////////////////
void display_int(unsigned char *Ptr ,unsigned char address,unsigned char len)
{   unsigned char i;

    lcd_write_comm(0x30);
    lcd_write_comm(address);
    lcd_write_comm(0x0c);
	for(i=0;i<len;i++)
	{
	//if(*Ptr!='/0')
	//if(*Ptr!=0)
	{
	displaybyte(*Ptr);
	Ptr++ ;
	lcd_write_data(' ');
	}
	//lcd_write_data(*Ptr++);
	//else
	//lcd_write_data(' ');
	}
}
