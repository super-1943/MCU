#include <stdio.h>
#include <iom8v.h>
#include <macros.h>
extern unsigned char  value_T,set_data;

void timer0_init(void) //CTCģʽ���1KHz/2KHz����
{
 //CLI(); //disable all interrupts
 //MCUCR = 0x00;
 //GICR  = 0x00;
 //TIMSK = 0x01; //timer interrupt sources
 
 TCCR0 = 0x00; //stop
 TCNT0 = 155;       // set count
 TCCR0 = 0x01;   //start timer
 //SEI();          //re-enable interrupts
}




#pragma interrupt_handler timer0_ovf_isr:10
void timer0_ovf_isr(void)
{static unsigned int i=0;
 TCNT0 =155 ;                 //reload counter value
 
 i++;
 // value_T++;
 if(i==100)
  { value_T++;
    i=0;
  }
 if(i < set_data)
	  PORTC|=BIT(PC3);
 else
	 PORTC&=~BIT(PC3);
}