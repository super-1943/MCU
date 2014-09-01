#include <spce061a.h>
#include "my7219.h"


unsigned int buffer[8]={1,1000,50,1,0x0000,0};//buffer[0]是模式，buffer【1】是频率，buffer【2】是最大电压；buffer[3]为全局变量
 

 unsigned int ZX[]=
{
	0x200,0x210,0x220,0x230,0x240,0x250,0x25f,0x26f,0x27f,0x28e,0x29e,0x2ad,0x2bc,0x2cb,0x2d9,0x2e8,0x2f6,0x304,0x312,0x31f,0x32c,0x339,0x346,0x352,0x35e,0x369,0x375,0x37f,0x38a,0x394,0x39e,0x3a7,0x3b0,0x3b8,0x3c0,0x3c8,0x3cf,0x3d5,0x3db,0x3e1,0x3e6,0x3eb,0x3ef,0x3f3,0x3f6,0x3f9,0x3fb,0x3fd,0x3fe,0x3ff,0x3ff,0x3ff,0x3ff,0x3fd,0x3fc,0x3f9,0x3f7,0x3f3,0x3f0,0x3eb,0x3e7,0x3e1,0x3dc,0x3d6,0x3cf,0x3c8,0x3c0,0x3b8,0x3b0,0x3a7,0x39e,0x394,0x38a,0x380,0x375,0x36a,0x35e,0x353,0x346,0x33a,0x32d,0x320,0x312,0x305,0x2f7,0x2e9,0x2da,0x2cb,0x2bd,0x2ae,0x29e,0x28f,0x280,0x270,0x260,0x250,0x240,0x230,0x220,0x210,0x200,0x1f0,0x1e0,0x1d0,0x1c0,0x1b0,0x1a0,0x191,0x181,0x172,0x162,0x153,0x144,0x135,0x126,0x118,0x10a,0xfc,0xee,0xe1,0xd3,0xc6,0xba,0xae,0xa2,0x96,0x8b,0x80,0x76,0x6c,0x62,0x59,0x50,0x47,0x3f,0x38,0x31,0x2a,0x24,0x1e,0x19,0x14,0x10,0xc,0x9,0x6,0x4,0x2,0x1,0x0,0x0,0x0,0x0,0x2,0x3,0x6,0x8,0xc,0xf,0x13,0x18,0x1d,0x23,0x29,0x30,0x37,0x3e,0x46,0x4e,0x57,0x60,0x6a,0x74,0x7f,0x89,0x94,0xa0,0xac,0xb8,0xc5,0xd1,0xde,0xec,0xfa,0x108,0x116,0x124,0x133,0x142,0x151,0x160,0x16f,0x17f,0x18e,0x19e,0x1ae,0x1be,0x1ce,0x1de,0x1ee     
};

unsigned int SJ[]=
{
	 0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160, 170, 180,190, 200, 210, 220, 230, 240, 250, 260, 270, 280,290 , 300, 310, 320, 330, 340, 350, 360, 370, 380,390 , 400, 410, 420, 430, 440, 450, 460, 470, 480,490 , 500, 510, 520, 530, 540, 550, 560, 570, 580,590 , 600, 610, 620, 630, 640, 650, 660, 670, 680,690 , 700, 710, 720, 730, 740, 750, 760, 770, 780,790 , 800, 810, 820, 830, 840, 850, 860, 870, 880,890 , 900, 910, 920, 930, 940, 950, 960, 970, 980,990 , 1000 , 1000, 990, 980, 970, 960, 950, 940, 930, 920,910, 900, 890, 880, 870, 860, 850, 840, 830, 820, 810, 800, 790, 780, 770, 760, 750, 740, 730,720, 710, 700, 690, 680, 670, 660, 650, 640, 630, 620, 610, 600, 590, 580, 570, 560, 550, 540, 530, 520, 510, 500, 490, 480, 470, 460, 450, 440, 430, 420, 410, 400, 390, 380,  370, 360, 350, 340, 330, 320, 310, 300, 290,  280, 270, 260, 250, 240, 230, 220, 210, 200,  190, 180, 170, 160, 150, 140, 130, 120, 110, 100,90, 80, 70, 60, 50, 40, 30, 20, 10, 0 
};
	
unsigned int JX[]=
{
	1000,1000,1000,1000,1000,1000,1000,1000,1000,1000, 	1000,1000,1000,1000,1000,1000,1000,1000,1000,1000, 	1000,1000,1000,1000,1000,1000,1000,1000,1000,1000, 	1000,1000,1000,1000,1000,1000,1000,1000,1000,1000, 	1000,1000,1000,1000,1000,1000,1000,1000,1000,1000, 	1000,1000,1000,1000,1000,1000,1000,1000,1000,1000, 	1000,1000,1000,1000,1000,1000,1000,1000,1000,1000, 	1000,1000,1000,1000,1000,1000,1000,1000,1000,1000, 	1000,1000,1000,1000,1000,1000,1000,1000,1000,1000, 	1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,  0,0,0,0,0,0,0,0,0,0,  0,0,0,0,0,0,0,0,0,0,  0,0,0,0,0,0,0,0,0,0,  0,0,0,0,0,0,0,0,0,0,  0,0,0,0,0,0,0,0,0,0,  0,0,0,0,0,0,0,0,0,0,  0,0,0,0,0,0,0,0,0,0,  0,0,0,0,0,0,0,0,0,0,  0,0,0,0,0,0,0,0,0,0,  0,0,0,0,0,0,0,0,0,0
};
unsigned int JU[]=
{
	1000,0
};
	
void delay()
{	
	unsigned int x=0x0f00;
	while(x--)
	*P_Watchdog_Clear=1;
}
void shortdelay(int x)
{	
	while(x--)
	{
		char i;
		for(i=20;i;i--);
	}
	*P_Watchdog_Clear=1;
}
 void IRQ1(void)__attribute__((ISR));
void IRQ1(void)
{
		buffer[6]++;

		if(buffer[6]==200)
		{
			buffer[6]=0;
		}
	switch(buffer[0])
	{
			*P_Watchdog_Clear=1;
		case 0:
				buffer[4]=JX[buffer[6]]*buffer[2];
			break;
		case 1:
			buffer[4]=SJ[buffer[6]]*buffer[2];
			break;
		case 2:
			buffer[4]=ZX[buffer[6]]*buffer[2];
			break;
		case 3:
			buffer[4]=((SJ[buffer[6]]+JX[buffer[6]])/2)*buffer[2];
		case 4:
			buffer[4]=((ZX[buffer[6]]+JX[buffer[6]])/2)*buffer[2];
		case 5:
			buffer[4]=((ZX[buffer[6]]+SJ[buffer[6]])/2)*buffer[2];
		case 6:
			buffer[4]=((ZX[buffer[6]]+SJ[buffer[6]]+JX[buffer[6]])/3)*buffer[2];
		default:
			break;
	}
		
	
	
	
		*P_INT_Clear=C_IRQ1_TMA;
	
}

void KeyScan()
{
	 int KeyTemp,Value;

	*P_Watchdog_Clear = 0x0001;
	*P_IOB_Dir&= 0xff00;
	*P_IOB_Attrib&= 0xff00;
	*P_IOA_Data&=0xff00;
	KeyTemp=*P_IOB_Data;

	Value=~KeyTemp;	
	Value&=0x00ff;
if(Value)
{
	switch(Value)
	{
			case 0x0080:
					buffer[0]++;
					if(buffer[0]==7)
						buffer[0]=0;
					break;
			case 0x0040:
					buffer[1]+=1000;
					break;
			case 0x0020:
					buffer[1]-=1000;
					if(buffer[1]<=0)
						buffer[1]=0;
					break;
			case 0x0010:
					buffer[1]+=100;
					break;
			case 0x0008:
					buffer[1]-=100;
					if(buffer[1]<=0)
						buffer[1]=0;
					break;
			case 0x0004:
					if(buffer[2]==50)
					{
						buffer[2]=0;
						break;
					}
					buffer[2]++;
					break;
			case 0x0002:
					if(buffer[2]==0)
					{
						buffer[2]=50;
						break;
					}
					buffer[2]--;
					break;
			case 0x0001:
					buffer[3]++;
			default:
					break;
	}		
	
	}
}
void UNDO()
{
		KeyScan();
		delay();
		show(buffer[0],buffer[1],buffer[2]);
		
		
		switch(buffer[1])
		{
				*P_Watchdog_Clear=1;
			case 100:
			*P_TimerA_Data=0xfffb;
				break;
		
				case 200:
			*P_TimerA_Data=0xfffc;
				break;
			case 300:
			*P_TimerA_Data=0xfffd;
				break;
			case 500:
			*P_TimerA_Data=0xfffe;
				break;			
			default:
			*P_TimerA_Data=0xffff;
				break;
		}								
}
void Juxing()
{
	
	buffer[5]++;
	__asm("INT IRQ");


}
void Sanjiao()
{
		buffer[5]++;
		__asm("INT IRQ");

}
void Zhengxian()
{	buffer[5]++;
		__asm("INT IRQ");
	
}
void Tiejia()
{
			__asm("INT IRQ");
}
/*void Tiejiayi()
{
			__asm("INT IRQ");
}

void Tiejiaer()
{
			__asm("INT IRQ");
}

void Tiejiasan()
{
			__asm("INT IRQ");
}*/
void Boxing()
{
	switch(buffer[0])
	{
			*P_Watchdog_Clear=1;
		case 0:
			Juxing();
			break;
		case 1:
			Sanjiao();
			break;
		case 2:
			Zhengxian();
			break;
		
		default:
			Tiejia();
			break;
	}
}		

int main()
 {

	__asm("INT OFF");

	
	*P_INT_Ctrl = 	C_IRQ1_TMA	; 
	*P_TimerA_Ctrl=	C_TMA1_FOSC_256	|C_TMA2_1;

	init7219();
	*P_DAC_Ctrl=C_DA1_Direct;

	while(1)
	{
		
		if((buffer[3])%2)
		{
			*P_SystemClock=C_Fosc_Div_64;
			UNDO();
		}
		else
		{
			*P_SystemClock =C_Fosc_49M;
			Boxing();
		

			*P_DAC1=buffer[4]; //output
	
		}
		*P_Watchdog_Clear=1;	

	}
}