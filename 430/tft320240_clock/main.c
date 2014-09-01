
#include "msp430x14x.h"
#include "tft320240.h"
#include "clock.h"
unsigned char last_time[3]={0,0,0};
unsigned char this_time[3]={67,28,30};
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
	SPFD5408A_CPT24_Initial();

	drawclock();
	for(i=0;i<10;i++)
	{
		ShowHanzi(i*16,0,i,0xf800,0x0000);
	}
	ShowString(0,16,"Current Time:");
	ShowCharWithColor(15*8,16,':'-0x20,0xffff,0x0000);
	ShowCharWithColor(18*8,16,':'-0x20,0xffff,0x0000);	
	init_timera();
	while(1)
	{
	}
}

#pragma vector=TIMERA0_VECTOR
__interrupt void timera(void)
{
	CCR0+=32768;
	last_time[0]=this_time[0];
	last_time[1]=this_time[1];
	last_time[2]=this_time[2];
	this_time[2]++;
	if(this_time[2]==60)
	{
		this_time[2]=0;
		this_time[1]++;
		if(this_time[1]%12==0)
		{
			this_time[0]++;
			if(this_time[0]%5==0)
			{
				this_time[1]=0;
			}
			if(this_time[0]==120)
			{
				this_time[0]=0;
			}
		}
	}
	move_second(last_time[2],this_time[2]);
	move_minute(last_time[1],this_time[1]);
	move_hour(last_time[0],this_time[0]);
	
	ShowCharWithColor(13*8,16,this_time[0]/5/10+'0'-0x20,0xffff,0x0000);
	ShowCharWithColor(14*8,16,this_time[0]/5%10+'0'-0x20,0xffff,0x0000);
	ShowCharWithColor(16*8,16,this_time[1]/10+'0'-0x20,0xffff,0x0000);
	ShowCharWithColor(17*8,16,this_time[1]%10+'0'-0x20,0xffff,0x0000);
	ShowCharWithColor(19*8,16,this_time[2]/10+'0'-0x20,0xffff,0x0000);
	ShowCharWithColor(20*8,16,this_time[2]%10+'0'-0x20,0xffff,0x0000);	
}