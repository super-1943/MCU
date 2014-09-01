//
//
//	www.mcu-china.com
//      www.mcu430.com  

#include  <msp430x14x.h>
#define uchar unsigned char
#define uint unsigned int
uchar key_buffer;
uchar key_long;
uchar digit[8] = {1,2,3,4,5,6,7,8};
uint con = 0 ;

unsigned char seg[]={
        0x3f,0x06,0x5b,0x4f,
	0x66,0x6d,0x7d,0x07,
	0x7f,0x6f,0x77,0x7c,
	0x39,0x5e,0x79,0x71,
	0xbf,0x86,0xdb,0xcf,
	0xe6,0xed,0xfd,0x87,
	0xff,0xef,0xf7,0xfc,
	0xb9,0xde,0xf9,0xf1,

	0x80,0x40,0x00,0x73,0xc0};

void delay(int v)
    {
        while(v!=0)v--;
    }

void disp(void)
    {
    unsigned char i=0,j=0;
    unsigned char temp_wei=0x0,temp_duan=0;
    P4DIR  =  0x3f;
    for(i=0;i<8;i++)
      {
        P4OUT  &=  ~BIT3;
        temp_duan=seg[digit[i]] ;
        _NOP();
        for(j=0;j<8;j++)
            {
             if(temp_duan&0x80)
                P4OUT  |=   BIT5;
             else
                P4OUT  &=  ~BIT5;
             temp_duan=temp_duan<<1;
             P4OUT  &=   ~BIT4;   P4OUT  |=  BIT4;
            }
         P4OUT  =  (P4IN&0xf8) | temp_wei;
         P4OUT  |=   BIT3;
         temp_wei++;
         delay(380);
      }
     P4OUT  &=  ~BIT3;
     }


void main(void)
{
  WDTCTL = WDTPW + WDTHOLD;             // Stop watchdog timer
  P4DIR=0x1f;
  P1DIR=0x0f;
  P6DIR = 0XFF ;
  P3DIR = 0XFF ;
    P2DIR=0X0f;
    P2OUT=0X0f;
    P2IE=0Xf0;
    P2IES=0xf0;
    P2IFG=0;
  TACTL = TASSEL0 + TACLR;              // SMCLK, clear TAR
  CCTL0 = CCIE;                         // CCR0 interrupt enabled
  CCR0 = 20000;
  TACTL |= MC1;                         // Start Timer_A in continuous mode
  P4DIR = 0XFF;
        P6SEL = 0x01;                               // Enable A/D channel inputs
          ADC12CTL0 = ADC12ON+MSC+SHT0_2+ REFON  ;  //+ REFON ;           // Turn on ADC12, set sampling time
          ADC12CTL1 = SHP  ;                // Use sampling timer, single sequence
          ADC12MCTL0 = INCH_0 + SREF_1;     // ref+=1.5v, channel = A0
          ADC12CTL0 |= ENC;                 // Enable conversions
  _EINT();                              // Enable interrupts

  for (;;)
  {
      disp();
    //_BIS_SR(CPUOFF);                    // CPU off
    _NOP();                             // Required only for C-spy
  }
}

void dc_adc(void)
    {
        int i ;
        long dc_adc1=0;

        for(i=0;i<16;i++)
            {
                ADC12CTL0 |= ADC12SC;       // Start conversion
                while ((ADC12IFG & BIT0)==0);
                dc_adc1 = dc_adc1 + ADC12MEM0;
            }
          dc_adc1 = dc_adc1 >> 4 ;

        for(i=0;i<4;i++)
            {
                digit[3-i]= dc_adc1%10;
                dc_adc1 = dc_adc1 / 10 ;
            }

    }



#pragma vector=TIMERA0_VECTOR
__interrupt void Timer_A(void)
  {
  uchar i=0;
  uint temp;
  CCR0 += 60000; 
  P6OUT |= BIT4 ;
  P3OUT = 0 ;
  con ++ ;
  temp = con ;
    for(i=0;i<4;i++)
        {
            digit[7-i]=  temp%10 ;
            temp = temp / 10 ;
        }

    dc_adc();
  }




uchar key_just(void)    //00:down  0xff:no down
    {
    P2DIR=0x0f;
    char in;
    in = ~P2IN ;
    in = in&0xf0;
 
    if( in ==0)
          return(0xff);
    return(0);
    }
    
uchar key_code(void)    
    {
     uchar in=0;
     in=P2IN&0xf0;
     in = ~in ;
     in = in & 0xf0;
     if(in==0x40) return(1);
     if(in==0x10) return(2);
     if(in==0x20) return(3);
     if(in==0x80) return(4);
     }
    
uchar key(void)
    {
    uchar temp=0xff    ;
    P2IFG=0;
    if(key_just()==0)
        delay(1000);
    if(key_just()!=0)
        return(temp);
    temp=key_code();
    key_buffer=temp;
key_loop:    
    if(key_just()==0xff)
       goto  key_loop;
    else
       {
       P1IFG=0;
       return(temp);
       }
    }


//interrupt[PORT1_VECTOR] void key_p1(void)
#pragma vector=PORT2_VECTOR
__interrupt void KKK(void)
      {
      uchar key_;
      
      key_=key();
      P2IFG=0;
      switch(key_)
            {
            case 1:
                {
                P6OUT &= ~BIT4 ;
                break;
                }
            case 2:
                {
                P3OUT = 0XFF ;
                break;
                }
            case 3:
                {
                break;
                }
            case 4:
                {
                break;
                }
            }      
      }




