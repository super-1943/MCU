#include <msp430x15x.h>
//***********ÒÆÖ²Ê±ÐèÐÞ¸Ä*************
#define DS1867_DIR  P4DIR
#define DS1867_OUT  P4OUT
#define RST_1867    BIT1
#define CLK_1867    BIT3
#define DQ_1867     BIT5
//**************************************
#define RST_1867_1  DS1867_OUT|=RST_1867
#define RST_1867_0  DS1867_OUT&=~RST_1867
#define CLK_1867_1  DS1867_OUT|=CLK_1867
#define CLK_1867_0  DS1867_OUT&=~CLK_1867
#define DQ_1867_1  DS1867_OUT|=DQ_1867
#define DQ_1867_0  DS1867_OUT&=~DQ_1867
//****************************************
void delay_1867(unsigned int ms)
{unsigned int i,j;
for(i=0;i<ms;i++)
for(j=0;j<150;j++);
}
void init_1867_100(void)
{RST_1867_1;
CLK_1867_0;
DS1867_DIR|=RST_1867+CLK_1867+DQ_1867;
}
void send_bit_1867(unsigned char i)
{if(i)
   {DQ_1867_1;}
else  {DQ_1867_0;}
CLK_1867_0;
CLK_1867_1;
//delay_1867(1);
}
void send_1867(unsigned char stack,unsigned char W0,unsigned char W1)
{unsigned char i;
RST_1867_0;
delay_1867(1);
RST_1867_1;
send_bit_1867(stack);
for(i=0;i<8;i++)
{send_bit_1867(W1&0x80);
W1<<=1;}
for(i=0;i<8;i++)
{send_bit_1867(W0&0x80);
W0<<=1;}
RST_1867_0;
CLK_1867_0;
}