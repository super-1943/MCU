
#include "msp430x14x.h"
#include "tft320240.h"
#include "clock.h"

double temper=0.0;
extern const unsigned char gImage_image[];
void delay(unsigned int t)
{
	unsigned char i,j;
	while(t--)
	{
		for(i=200;i;i--)
			for(j=20;j;j--);
	}
}
void init_timera(void)
{
	TACTL=TASSEL_1+TACLR;
	CCTL0=CCIE;
	CCR0=32768;
	TACTL|=MC1;
	_EINT();
}
int main( void )
{
	// Stop watchdog timer to prevent time out reset
	unsigned int i;
	WDTCTL = WDTPW + WDTHOLD;
	BCSCTL1 &= ~XT2OFF;                       // XT2on
	do
	{
	IFG1 &= ~OFIFG;                           // Clear OSCFault flag
	for (i = 0xFF; i > 0; i--);               // Time for flag to set
	}while ((IFG1 & OFIFG));                   // OSCFault flag still set?
//	P6SEL|=0x01;
//	ADC12CTL0=ADC12ON+SHT0_2+REFON+REF2_5V;
//	ADC12CTL1=SHP;
//	ADC12MCTL0=SREF_1+INCH_0;//inter temperature
//	ADC12IE|=BIT0;
//	_EINT();
//	for(i=0;i<0x3600;i++)
//	{}
//	ADC12CTL0|=ENC;
//	ADC12CTL0|=ADC12SC;
	SPFD5408A_CPT24_Initial();
	Clear();
	show_pic_ext(gImage_image,0,0,144,200);
	while(1)
	{
	}
}

#pragma vector=ADC12_VECTOR
__interrupt void adc12_int(void)
{
	temper=(double)ADC12MEM0*2500.0;
	temper=temper/4096.0;
	temper-=0.986;
	temper/=0.00355;
    ADC12CTL0|=ADC12SC;
}