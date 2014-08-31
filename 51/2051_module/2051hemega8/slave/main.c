/*congji*/
#include <avr/io.h> 
#include <util/delay.h> 
#include <compat/twi.h> 
#include "usart.h"
#define uint unsigned int 
#define uchar unsigned char 
#define FREQ 4 
#define DS1307_ADDR 0XD0 
#define KEY 0X04 
#define TWI_ADDRESS 0X32 
#define WAITPRINTDEBUG  DelayMs(100)  //Ϊ��ģʽ��Ƭ����ӡ������Ϣ����ʱ 
#define TW_ACK  1 
#define TW_NACK 0 


 
//дһ�ֽ� 
uchar twi_writebyte(uchar c) 
{ 
  TWDR = c; 
  TWCR = _BV(TWINT) | _BV(TWEN);   
  while ((TWCR & _BV(TWINT)) == 0); 
    return TW_STATUS; 
} 
 
//��һ�ֽ� ack: true ʱ��ACK��false ʱ��NACK 
uchar twi_readbyte(uchar *c ,uchar ack) 
{ 
  uchar tmp=_BV(TWINT)|_BV(TWEN); 
   
  if(ack) 
    tmp|=_BV(TWEA);    
  TWCR=tmp; 
  while ((TWCR & _BV(TWINT)) == 0) ; 
  *c=TWDR; 
   return TW_STATUS; 
} 

void IoInit(void) 
{ 
  //ʹ�� SCL��SDA �����ڲ��������� 
  DDRC=0; 
  PORTC=0X30; 
    //TWI �ӿڳ�ʼ��,������ģʽ 
  TWAR=TWI_ADDRESS | _BV(TWGCE); 
  TWCR=_BV(TWEA) | _BV(TWEN); 
} 
 

 int main(void) 
{ 
  uchar i,j=0; 
 USART_Init(25);
  IoInit(); 
  print_str("Hello");
  while(1) 
 { 
    while ((TWCR & _BV(TWINT)) == 0); 
    i=TW_STATUS; 
      switch(i) 
	{ 
     case TW_SR_SLA_ACK: 
		print_str("START\nSLA+W\n"); 
		break; 
     case TW_SR_DATA_ACK: 
		if(j==0) 
			print_int(TWDR); 
		else 
			print_int(TWDR); 
		j++; 
		break; 
     case TW_SR_STOP: 
		print_str(";\rSTOP\r\r"); 
		j=0; 
		break; 
     default: 
		print_str("error:x"); 
     break; 
  } 
      TWCR=_BV(TWEA) | _BV(TWEN)|_BV(TWINT);  //���TWINT λ 
 } 
 
} 
