

#include <reg51.h>
#include <absacc.h>

#define uint unsigned int
#define uchar unsigned char

sbit P10=P1^0;
sbit P11=P1^1;
sbit P12=P1^2;
sbit P13=P1^3;
sbit P14=P1^4;
sbit P15=P1^5;
sbit P16=P1^6;
sbit P17=P1^7;

uchar code ledcode[]={0x3f,0x06,0x5b,0x4f,
						0x66,0x6d,0x7d,0x07,
						0x7f,0x6f,0x77,0x7c,
						0x39,0x5e,0x7b,0x71,0x00,0x40};
bit key_flag=0;

void delay_10ms();
void keyscan();

void main()
{	
	IE=0X00;
	
	while(1)
	{	
		keyscan();
	}//while

}//fun


void keyscan(void)
{
	//******************扫第1列************
	  P14=0;
	  if(P10==0)
	  {
		delay_10ms();
	  	P0=ledcode[1];
		}
	  if(P11==0)
	  {delay_10ms();
	  P0=ledcode[6];
	}

	  if(P12==0)
	  {delay_10ms();
	  P0=ledcode[7];
	}
	  if(P13==0)
	  {delay_10ms();
	  P0=ledcode[16];
	}
	  P1=0xff;  
	  //**************扫第2列******************
	  P15=0;
	 	  if(P10==0)
	  {
		delay_10ms();
	  	P0=ledcode[2];
		}
	  if(P11==0)
	  {delay_10ms();
	  P0=ledcode[5];
	}

	  if(P12==0)
	  {delay_10ms();
	  P0=ledcode[8];
	}
	  if(P13==0)
	  {delay_10ms();
	  P0=ledcode[0];
	}
	  P1=0xff;     
	  //***************扫第3列*********************
	  P16=0;
	  	  if(P10==0)
	  {
		delay_10ms();
	  	P0=ledcode[3];
		}
	  if(P11==0)
	  {delay_10ms();
	  P0=ledcode[4];
	}

	  if(P12==0)
	  {delay_10ms();
	  P0=ledcode[9];
	}
	  if(P13==0)
	  {delay_10ms();
	  P0=ledcode[16];
	}
	  P1=0xff;                      
	//***************扫第4列************************
	  P17=0;
	  	  if(P10==0)
	  {
		delay_10ms();
	  	P0=ledcode[10];
		}
	  if(P11==0)
	  {delay_10ms();
	  P0=ledcode[11];
	}

	  if(P12==0)
	  {delay_10ms();
	  P0=ledcode[12];
	}
	  if(P13==0)
	  {delay_10ms();
	  P0=ledcode[13];
	}
	  P1=0xff; 	

}


void delay_10ms(void)
{
	uchar i,j;
	for(i=0;i<100;i++);
		for(j=0;j<80;j++);
}
