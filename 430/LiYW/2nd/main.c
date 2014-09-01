/***********************************************************
项目要求：
测定含水率（百分比）
含水率分为25档，如下(%)
0,1,3,5,10,
15,20,25,30,35,
40,45,50,55,60,
65,70,75,80,85,
90,95,97,99,100
每个档位对应一个模拟电压值，可以通过键盘设定。
正常状态显示为：含水率xx%,模拟量：xxxxmV
按下“设定”键可以设定光标所在行的模拟量值
上下屏可以切换光标所在行
************************************************************/
/******************
约定：采用内部12位ADC
参考电压为外置2.048V
修改比例因子请到19264.h中修改
#define RATIO xxxx
xxxx=VREF/4.096

******************/
#include "msp430x14x.h"
#include "19264.h"
#include "flash.h"
#include "key.h"

extern const unsigned char hzstr[];
extern const unsigned char SHUstr[];
extern const unsigned char Ezk[];
extern const unsigned char Noinput_zk[];
extern const unsigned char Sheding[];

unsigned char k,page=0,change=0,offset=0,cursoron=0;

const unsigned char Water[25]=
{
0,1,3,5,10,15,20,25,30,35,40,45,50,55,60,
65,70,75,80,85,90,95,97,99,100
};
unsigned int Analog[25]=
{
0,100,300,500,1000,1500,2000,2500,3000,4000,4500,5000
};
unsigned int ADbuffer[4]={200,24,50,1222};

void kkk_showAD(unsigned char channel);
void kkk_setparameter(void);
void kkk_setanalog(unsigned char page,unsigned char offset);
void init_device(void);






int main( void )
{
	// Stop watchdog timer to prevent time out reset
	WDTCTL = WDTPW + WDTHOLD;
	init_device();
	InitLCM();
	WriteCom(0x3f,'L');//play on;
	WriteCom(0x3f,'M');
	WriteCom(0x3f,'R');
	ClearLCM();
	checkflash();
	

	ClearLCM();
	WriteChinese(hzstr,1,0,'L');
	WriteChinese(hzstr+32,1,16,'L');
	WriteChinese(hzstr+64,1,32,'L');
	WriteChinese(hzstr+96,2,0,'L');
	WriteChinese(hzstr+128,2,16,'L');
	WriteChinese(hzstr+160,2,32,'L');	
	WriteChar(Ezk+16*('m'-0x20),4,48,'M');
	WriteChar(Ezk+16*('V'-0x20),4,56,'M');
	kkk_showAD(0);
	while(1)
	{
		
		k=keyscan();
		if(k==12)
		{
			while(k)//等待按键弹起
			{
				k=keyscan();
			}
			kkk_setparameter();
			ClearLCM();
			WriteChinese(hzstr,1,0,'L');
			WriteChinese(hzstr+32,1,16,'L');
			WriteChinese(hzstr+64,1,32,'L');
			WriteChinese(hzstr+96,2,0,'L');
			WriteChinese(hzstr+128,2,16,'L');
			WriteChinese(hzstr+160,2,32,'L');	
			WriteChar(Ezk+16*('m'-0x20),4,48,'M');
			WriteChar(Ezk+16*('V'-0x20),4,56,'M');
			kkk_showAD(0);
		}
		if(k==15)//reset
		{
			while(k)//等待按键弹起
			{
				k=keyscan();
			}
			WDTCTL =WDT_MRST_32;
			while(1);
		}
		delay(2000);
	}
}

/****************************
8M晶振，速度快！
****************************/
void init_device(void)
{ 
    unsigned char i;  
    BCSCTL1&=~XT2OFF;
    do
    {
        IFG1&=~OFIFG;
        for(i=0xff;i;i--);
    }
    while((IFG1&OFIFG)!=0);
    BCSCTL2|=SELM1+SELS;//MCLK=SMCLK=XT2;
}

void kkk_showAD(unsigned char channel)
{
	unsigned int temp,kkk_temp,shui,shui_xiaoshu=0;
	unsigned char i;
	temp=ADbuffer[channel];
	kkk_temp=temp*RATIO;
	for(i=1;i<25;i++)
	{
		if((Analog[i-1]<=temp)&&(Analog[i]>=temp))
		{
			if(Analog[i-1]==temp)
			{
				shui=Water[i-1];
			}
			else if(Analog[i]==temp)
			{
				shui=Water[i];
			}
			else//线性插值
			{
				shui_xiaoshu=(Water[i]-Water[i-1])*(temp-Analog[i-1]);
				shui=Water[i-1];
				shui+=shui_xiaoshu/(Analog[i]-Analog[i-1]);
				shui_xiaoshu*=10;
				shui_xiaoshu/=(Analog[i]-Analog[i-1]);
				shui_xiaoshu%=10;
			}
			
			if(shui>=100)
			{
				WriteChar(Ezk+16*('1'-0x20),2,48,'L');
				WriteChar(Ezk+16*('0'-0x20),2,56,'L');
				WriteChar(Ezk+16*('0'-0x20),2,0,'M');
				WriteChar(Ezk+16*('.'-0x20),2,8,'M');
				WriteChar(Ezk+16*(shui_xiaoshu+'0'-0x20),2,16,'M');
				WriteChar(Ezk+16*('%'-0x20),2,24,'M');
			}
			else if(shui%100/10)
			{
				WriteChar(Ezk+16*(0),2,48,'L');//space
				WriteChar(Ezk+16*(shui%100/10+'0'-0x20),2,56,'L');
				WriteChar(Ezk+16*(shui%10+'0'-0x20),2,0,'M');
				WriteChar(Ezk+16*('.'-0x20),2,8,'M');
				WriteChar(Ezk+16*(shui_xiaoshu+'0'-0x20),2,16,'M');
				WriteChar(Ezk+16*('%'-0x20),2,24,'M');
			}
			else
			{
				WriteChar(Ezk+16*(0),2,48,'L');//space
				WriteChar(Ezk+16*(0),2,56,'L');
				WriteChar(Ezk+16*(shui%10+'0'-0x20),2,0,'M');
				WriteChar(Ezk+16*('.'-0x20),2,8,'M');
				WriteChar(Ezk+16*(shui_xiaoshu+'0'-0x20),2,16,'M');
				WriteChar(Ezk+16*('%'-0x20),2,24,'M');
			}
			//temp*=RATIO;//存储值乘上系数得到实际模拟量
			temp=kkk_temp;
			if(temp%10000/1000)
			{
				WriteChar(Ezk+16*(temp%10000/1000+'0'-0x20),4,48,'L');
			}
			else
			{
				WriteChar(Ezk+16*(0),4,48,'L');
			}
			if((temp%1000/100)||(temp%10000/1000))
			{
				WriteChar(Ezk+16*(temp%1000/100+'0'-0x20),4,56,'L');
			}
			else
			{
				WriteChar(Ezk+16*(0),4,56,'L');
			}
			if((temp%1000/100)||(temp%10000/1000)||(temp%100/10))
			{
				WriteChar(Ezk+16*(temp%100/10+'0'-0x20),4,0,'M');
			}
			else
			{
				WriteChar(Ezk+16*(0),4,0,'M');
			}
			if((temp%1000/100)||(temp%10000/1000)||(temp%100/10)||(temp%10))
			{
				WriteChar(Ezk+16*(temp%10+'0'-0x20),4,8,'M');	
			}
			else
			{
				WriteChar(Ezk+16*('0'-0x20),4,8,'M');
			}
		}

	}

}


void kkk_setparameter(void)
{
	page=0;
	offset=0;
	kkk_19264_show(page,offset);
	while(1)
	{
		k=keyscan();
		switch(k)
		{
		case 11://cursor
			break;
		case 12://set
			while(k)//等待按键弹起
			{
				k=keyscan();
			}
			delay(200);
			kkk_setanalog(page,offset);
			change=1;
			break;
		case 13://up
			if(offset==0)
			{				
				page=(page)?(page-1):(24);
				change=1;
			}
			else
			{
				offset--;
				change=1;
			}
			break;
			
		case 14://down

			if(offset==3)
			{				
				page=(page+1)%25;
				change=1;
			}
			else
			{
				offset++;
				change=1;
			}
			break;
			
		case 15://reset
			WDTCTL =WDT_MRST_32;
			while(1);
		case 16://quit
			return;
		default:break;	
		}
		if(change==1)
		{
			kkk_19264_show(page,offset);
			change=0;
		}
		delay(200);
	}
	
}
void kkk_setanalog(unsigned char page,unsigned char offset)
{
	unsigned char mykey=0,i,buffer[4];
	unsigned int temp;
	unsigned int *p=(unsigned int*)SEG_A;
	WriteChinese(Sheding,offset,16,'M');
	WriteChinese(Sheding+32,offset,32,'M');
	
	temp=Analog[(page+offset)%25]*RATIO;
	buffer[0]=temp/1000;
	buffer[1]=temp%1000/100;
	buffer[2]=temp%100/10;
	buffer[3]=temp%10;
	for(i=0;i<4;)
	{
		mykey=keyscan();
		switch(mykey)
		{
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
		case 10:
			buffer[i]=mykey-1;
			WriteChar(Ezk+16*(mykey-1+'0'-0x20),2*offset,8*i,'R');
			break;
		case 11:break;
		case 12:
			i++;
			while(mykey==12)
			{
				mykey=keyscan();
			}
			break;
		case 13:break;
		case 14:break;
		case 15:break;
		case 16:return;
		}
		delay(500);
	}
	temp=(buffer[0]*1000+buffer[1]*100+buffer[2]*10+buffer[3]);
	Analog[(page+offset)%25]=temp/RATIO;
	flash_clr(p);
	flash_write_int16(p++,0x55);
	for(i=0;i<25;i++)
	{//这里有错！2010-6-13
		flash_write_int16(p++,Analog[i-1]);
	}
}