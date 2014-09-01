/***********************************************************
��ĿҪ��
�ⶨ��ˮ�ʣ��ٷֱȣ�
��ˮ�ʷ�Ϊ25��������(%)
0,1,3,5,10,
15,20,25,30,35,
40,45,50,55,60,
65,70,75,80,85,
90,95,97,99,100
ÿ����λ��Ӧһ��ģ���ѹֵ������ͨ�������趨��
����״̬��ʾΪ����ˮ��xx%,ģ������xxxxmV
���¡��趨���������趨��������е�ģ����ֵ
�����������л����������
************************************************************/
/******************
Լ���������ڲ�12λADC
�ο���ѹΪ����2.048V
�޸ı��������뵽19264.h���޸�
#define RATIO xxxx
xxxx=VREF/4.096

******************/
#include "msp430x14x.h"
#include "noziku12864.h"
#include "flash.h"
#include "key.h"

extern const unsigned char hzstr[];
extern const unsigned char SHUstr[];
extern const unsigned char Ezk[];
extern const unsigned char Noinput_zk[];
extern const unsigned char Sheding[];

unsigned char k,page=0,change=0,offset=0,cursoron=0;

const unsigned char Water[26]=
{
0,1,3,5,10,15,20,25,30,35,40,45,50,55,60,
65,70,75,80,85,90,95,97,99,100,100
};
int Analog[26]=
{0,49,147,246,492,737,983,1229,
1475,1720,1966,2212,2458,2703,2949,3195,
3441,3686,3932,4178,4424,4669,4768,4866,
4915,5000
};
int ADbuffer[1]={0};
int count_buffer[50];
unsigned int counter=0;

void kkk_showAD(unsigned char channel);
void kkk_setparameter(void);
void kkk_setanalog(unsigned char page,unsigned char offset);
void init_device(void);
void init_timerA(void);
#define close_timerA() TACTL=MC_0





int main( void )
{
	// Stop watchdog timer to prevent time out reset
	WDTCTL = WDTPW + WDTHOLD;
	init_device();
	InitLCM();
	WriteCom(0x3f,'L');//play on;
	WriteCom(0x3f,'R');
	ClearLCM();
	checkflash();
	
	P6SEL|=0x01;
	ADC12CTL0=ADC12ON+SHT0_2+REFON+REF2_5V;
	ADC12CTL1=SHP;
	ADC12MCTL0=SREF_1;
	
	WriteChinese(hzstr,0,0,'L');
	WriteChinese(hzstr+32,0,16,'L');
	WriteChinese(hzstr+64,0,32,'L');
	WriteChinese(hzstr+96,2,0,'L');
	WriteChinese(hzstr+128,2,16,'L');
	WriteChinese(hzstr+160,2,32,'L');
	
	WriteChar(Ezk+16*('m'-0x20),6,40,'L');
	WriteChar(Ezk+16*('V'-0x20),6,48,'L');
	
	ADC12CTL0|=ENC;
	ADC12CTL0|=ADC12SC;
	while(1)
	{
		kkk_showAD(0);
		k=keyscan();
		if(k==12)
		{
			while(k)//�ȴ���������
			{
				k=keyscan();
			}
                        close_timerA();
			ClearLCM();
			kkk_setparameter();
			ClearLCM();
			WriteChinese(hzstr,0,0,'L');
			WriteChinese(hzstr+32,0,16,'L');
			WriteChinese(hzstr+64,0,32,'L');
			WriteChinese(hzstr+96,2,0,'L');
			WriteChinese(hzstr+128,2,16,'L');
			WriteChinese(hzstr+160,2,32,'L');
			
			WriteChar(Ezk+16*('m'-0x20),6,40,'L');
			WriteChar(Ezk+16*('V'-0x20),6,48,'L');
			kkk_showAD(0);
                        init_timerA();
		}
		if(k==15)//reset
		{
			while(k)//�ȴ���������
			{
				k=keyscan();
			}
			WDTCTL =WDT_MRST_32;
			while(1);
		}
		delay(2000);
	}
}

#pragma vector=TIMERA0_VECTOR
__interrupt void timera_comp(void)
{
    unsigned char i;
    float aver;
    TACCR0+=512;//f=64Hz
    counter++;
    
    if(ADC12IFG&BIT0)
    {
        count_buffer[counter]=ADC12MEM0;
        counter++;
        if(counter>=32)
        {
          counter=0;
          aver=count_buffer[0];          
          for(i=1;i<32;i++)
          {
            aver+=(count_buffer[i]-aver)/(float)(i+1);
          }
          ADbuffer[0]=(int)aver;
        }
        ADC12CTL0|=ADC12SC;
    }
}
/****************************
8M�����ٶȿ죡
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
    init_timerA();

}
void init_timerA(void)
{
    //timerA
    TACTL=TASSEL_1|MC_2|TACLR;
    TACCTL0=CCIE;
    TACCR0=512;
    _EINT();  
}

void kkk_showAD(unsigned char channel)
{
	unsigned int temp,kkk_temp,shui,shui_xiaoshu=0;
	unsigned char i;
	temp=ADbuffer[channel];
	kkk_temp=temp*RATIO;
	for(i=1;i<=25;i++)
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
			else//���Բ�ֵ
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
				WriteChar(Ezk+16*('1'-0x20),2,0,'L');
				WriteChar(Ezk+16*('0'-0x20),2,8,'L');
				WriteChar(Ezk+16*('0'-0x20),2,16,'L');
				WriteChar(Ezk+16*('.'-0x20),2,24,'L');
				WriteChar(Ezk+16*(shui_xiaoshu+'0'-0x20),2,32,'L');
				WriteChar(Ezk+16*('%'-0x20),2,40,'L');
			}
			else if(shui%100/10)
			{
				WriteChar(Ezk+16*(0),2,0,'L');//space
				WriteChar(Ezk+16*(shui%100/10+'0'-0x20),2,8,'L');
				WriteChar(Ezk+16*(shui%10+'0'-0x20),2,16,'L');
				WriteChar(Ezk+16*('.'-0x20),2,24,'L');
				WriteChar(Ezk+16*(shui_xiaoshu+'0'-0x20),2,32,'L');
				WriteChar(Ezk+16*('%'-0x20),2,40,'L');
			}
			else
			{
				WriteChar(Ezk+16*(0),2,0,'L');//space
				WriteChar(Ezk+16*(0),2,8,'L');
				WriteChar(Ezk+16*(shui%10+'0'-0x20),2,16,'L');
				WriteChar(Ezk+16*('.'-0x20),2,24,'L');
				WriteChar(Ezk+16*(shui_xiaoshu+'0'-0x20),2,32,'L');
				WriteChar(Ezk+16*('%'-0x20),2,40,'L');
			}
			//temp*=RATIO;//�洢ֵ����ϵ���õ�ʵ��ģ����
			temp=kkk_temp;
			if(temp%10000/1000)
			{
				WriteChar(Ezk+16*(temp%10000/1000+'0'-0x20),6,0,'L');
			}
			else
			{
				WriteChar(Ezk+16*(0),6,0,'L');
			}
			if((temp%1000/100)||(temp%10000/1000))
			{
				WriteChar(Ezk+16*(temp%1000/100+'0'-0x20),6,8,'L');
			}
			else
			{
				WriteChar(Ezk+16*(0),6,8,'L');
			}
			if((temp%1000/100)||(temp%10000/1000)||(temp%100/10))
			{
				WriteChar(Ezk+16*(temp%100/10+'0'-0x20),6,16,'L');
			}
			else
			{
				WriteChar(Ezk+16*(0),6,16,'L');
			}
			if((temp%1000/100)||(temp%10000/1000)||(temp%100/10)||(temp%10))
			{
				WriteChar(Ezk+16*(temp%10+'0'-0x20),6,24,'L');	
			}
			else
			{
				WriteChar(Ezk+16*('0'-0x20),6,24,'L');
			}
		}

	}

}


void kkk_setparameter(void)
{
        
	page=0;
	offset=0;
	kkk_12864_show(page,offset);
	while(1)
	{
		k=keyscan();
		switch(k)
		{
		case 11://cursor
			break;
		case 12://set
			while(k)//�ȴ���������
			{
				k=keyscan();
			}
			delay(20000);
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
			delay(20000);
			break;
			
		case 14://down

			if(offset==2)
			{				
				page=(page+1)%25;
				change=1;
			}
			else
			{
				offset++;
				change=1;
			}
			delay(20000);
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
			kkk_12864_show(page,offset);
			change=0;
		}
		delay(20000);
	}
	
}
void kkk_setanalog(unsigned char page,unsigned char offset)
{
	unsigned char mykey=0,i,buffer[4];
	unsigned int temp;
	unsigned int *p=(unsigned int*)SEG_A;
	WriteChinese(Sheding,0,16,'R');
	WriteChinese(Sheding+32,0,32,'R');
	
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
			WriteChar(Ezk+16*(mykey-1+'0'-0x20),2*(offset+1),8*i,'R');
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
	{
		flash_write_int16(p++,Analog[i]);
	}
}