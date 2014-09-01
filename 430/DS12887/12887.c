#include<reg51.h>
#include<intrins.h>
#define uchar unsigned char
#define uint  unsigned int
uchar miao,fen,shi,ri,zhou,yue,nian,time_flag,key_num;
sbit DS_cs     =  P2^7;
sbit DS_as     =  P2^3;
sbit DS_rw     =  P3^6;
sbit DS_ds     =  P3^7;
sbit DS_irq    =  P3^2;
sbit LCD_rs    =  P2^0;
sbit LCD_rw    =  P2^1;
sbit LCD_en    =  P2^2;
sbit key1      =  P2^4;
sbit key2      =  P2^5;
sbit key3      =  P2^6;	
sbit beep      =  P3^7;
uchar code table1[]={"  20  -  -      "};
uchar code table2[]={"      :  :      "};
void delay(uchar z)
{
	uchar x,y;
	for(x=z;x>0;x--)
		for(y=110;y>0;y--);
}
void DS_write(uchar add,uchar date)
{
	  DS_as=1;
	  DS_ds=1;
	  DS_rw=1;
	  DS_cs=0;
	  P1=add;
	  DS_as=0;
	  DS_rw=0;
	  P1=date;
	  DS_rw=1;
	  DS_as=1;
	  DS_cs=1;

}
uchar DS_read(uchar add)
{
	  uchar  DS_read_dat;
	  DS_as=1;
	  DS_ds=1;
	  DS_rw=1;
	  DS_cs=0;
	  P1=add;
	  DS_as=0;
	  DS_ds=0;
	  P1=0xff;
	  DS_read_dat = P1;
	  DS_ds=1;
	  DS_as=1;
	  DS_cs=1;
	  return(DS_read_dat);
}
void LCD_write_com(uchar com)
{
	  LCD_rs=0;
	  LCD_rw=0;
	  LCD_en=0;
	  delay(5);
	  LCD_en=1;
	  P0= com;
	  LCD_en=0;
}
void LCD_write_data(uchar date)
{
	  LCD_rs=1;
	  LCD_rw=0;
	  LCD_en=0;
	  delay(5);
	  LCD_en=1;
	  P0= date;
	  LCD_en=0;
}
void Display_Btime(uchar add,uchar date)
{
		LCD_write_com(add);
		;
		LCD_write_data(date);
}
void Display_BCDtime(uchar add,uchar date)
{
	uchar gw,sw;
	sw=date/10;
	gw=date%10;
	LCD_write_com(0x80+add);
	LCD_write_data(0x30+sw);
	LCD_write_data(0x30+gw);
}

void BCD_time()
{
		miao=DS_read(0x00);
		Display_BCDtime(0x4a,miao);

		fen=DS_read(0x02);
		Display_BCDtime(0x47,fen);

		shi=DS_read(0x04);
		Display_BCDtime(0x44,shi);

		ri=DS_read(0x07);
		Display_BCDtime(0x0a,ri);

		yue=DS_read(0x08);
		Display_BCDtime(0x07,yue);

		nian=DS_read(0x09);
		Display_BCDtime(0x04,nian);
		
		zhou=DS_read(0x06);
		switch(zhou)
		{
			case 1:
			{
				Display_Btime(0x80+0x0d,'M');
				Display_Btime(0x80+0x0e,'O');
				Display_Btime(0x80+0x0f,'N');
			}
			break;
			case 2:
			{
				Display_Btime(0x80+0x0d,'T');
				Display_Btime(0x80+0x0e,'U');
				Display_Btime(0x80+0x0f,'E');
			}
			break;
			case 3:
			{
				Display_Btime(0x80+0x0d,'W');
				Display_Btime(0x80+0x0e,'E');
				Display_Btime(0x80+0x0f,'D');
			}
			break;
			case 4:
			{
				Display_Btime(0x80+0x0d,'T');
				Display_Btime(0x80+0x0e,'H');
				Display_Btime(0x80+0x0f,'U');
			}
			break;
			case 5:
			{
				Display_Btime(0x80+0x0d,'F');
				Display_Btime(0x80+0x0e,'R');
				Display_Btime(0x80+0x0f,'I');
			}
			break;
			case 6:
			{
				Display_Btime(0x80+0x0d,'S');
				Display_Btime(0x80+0x0e,'A');
				Display_Btime(0x80+0x0f,'T');
			}
			break;
			case 7:
			{
				Display_Btime(0x80+0x0d,'S');
				Display_Btime(0x80+0x0e,'U');
				Display_Btime(0x80+0x0f,'N');
			}
			break;
			default :break;
	
		}	
}
void keyscan()
{
	if(key2==0)
	{
		delay(10);
		if(key2==0)
		{
			key_num++;
			time_flag=1;
			switch(key_num)
			{
					case 1:
					{	
						while(!key2);
						delay(10);
						while(!key2);
						LCD_write_com(0x80+0x40+11);
						LCD_write_com(0x0f);													
					}
					break;
					case 2 :
					{
						while(!key2);
						delay(10);
						while(!key2);
						LCD_write_com(0x80+0x40+8);
						LCD_write_com(0x0f);						
					
					} 
					break;
					case 3 :
					{					
						while(!key2);
						delay(10);
						while(!key2);
						LCD_write_com(0x80+0x40+5);
						LCD_write_com(0x0f);						
		
					}	
					break;
					case 4 :
					{
						while(!key2);
						delay(10);
						while(!key2);
						LCD_write_com(0x80+11);
						LCD_write_com(0x0f);						
		
					}
					break;
					case 5 :
					{
						while(!key2);
						delay(10);
						while(!key2);
						LCD_write_com(0x80+0x08);
						LCD_write_com(0x0f);						
		
					}
					break;
					case 6 :
					{
						while(!key2);
						delay(10);
						while(!key2);
						LCD_write_com(0x80+0x05);
						LCD_write_com(0x0f);				    	
					 }
					 break;
					 case 7 :
					{
						LCD_write_com(0x0c);
						key_num=0;
						time_flag=0;
						while(!key2);
						delay(10);
						while(!key2);
						DS_write(0x09,nian);
						DS_write(0x08,yue);
						DS_write(0x07,ri);
						//DS_write(0x06,2);
						DS_write(0x04,shi);
						DS_write(0x02,fen);
						DS_write(0x00,miao); 

					 }
					 break;
					 default :break;
			}
					
	
			}
	}
	if(key3==0)
		{
			delay(10);
			if(key3==0)
			{
				switch(key_num)
				{
					case 1:
					{
						miao++;
						if(miao==60)
						{
							miao=0;
						}
						while(!key3);
						delay(10);
						while(!key3);
						Display_BCDtime(0x4a,miao);
						LCD_write_com(0x80+0x40+11);
						LCD_write_com(0x0f);

					}
					break;
					case 2:
					{
						fen++;
						if(fen==60)
						{
							fen=0;
						}
						while(!key3);
						delay(10);
						while(!key3);
						Display_BCDtime(0x47,fen);
						LCD_write_com(0x80+0x40+8);
						LCD_write_com(0x0f);
					}
					break;
					case 3:
					{
						shi++;
						if(shi==24)
						{
							shi=0;
				 		}
						while(!key3);
						delay(10);
						while(!key3);
						Display_BCDtime(0x44,shi);
						LCD_write_com(0x80+0x40+5);
						LCD_write_com(0x0f);
					}
					break;
					case 4:
					{
						ri++;
						if(ri==32)
						{
							ri=0;
						}
						while(!key3);
						delay(10);
						while(!key3);
						Display_BCDtime(0x0a,ri);
						LCD_write_com(0x80+11);
						LCD_write_com(0x0f);
					}
					break;
					case 5:
					{
						yue++;
						if(yue==13)
						{
							yue=0;
						}
						while(!key3);
						delay(10);
						while(!key3);
						Display_BCDtime(0x07,yue);
						LCD_write_com(0x80+0x08);
						LCD_write_com(0x0f);
					}
					break;
					case 6:
					{
						nian++;
						if(nian==100)
						{
							nian=0;
						}
						while(!key3);
						delay(10);
						while(!key3);
						Display_BCDtime(0x04,nian);
						LCD_write_com(0x80+0x08);
						LCD_write_com(0x0f);
					}
					break;
					default:break;

				}
			}
		}
}

void init_dis(uchar add,uchar table[])
{
	uchar *app ;
	LCD_write_com(0x80+add);
	for(app=table;app<(table+16);app++)
	{
		 LCD_write_data(*app);
	}
}
void set_time()
{
	DS_write(0x09,8);
	DS_write(0x08,6);
	DS_write(0x07,9);
	DS_write(0x06,1);
	DS_write(0x04,17);
	DS_write(0x02,30);
	DS_write(0x00,0);
}
void set_alarm()
{
	DS_read(0x0c);
	DS_write(0x01,00);
	DS_write(0x03,30);
	DS_write(0x05,20);	
}
void init()
{
	LCD_write_com(0x38);
	LCD_write_com(0x0c);
	LCD_write_com(0x06);
	LCD_write_com(0x80+0);
	init_dis(0,table1);
	init_dis(0x40,table2);
	DS_write(0x0a,0x20);
	DS_write(0x0b,0x66);
	time_flag=0;
	key_num=0;
	IT0=1;
	EA=1;
	EX0=1;
	set_alarm();
	//DS_write(0x0b,0x62);
	//set_time();
}
void main()
{
	init();
	while(1)
	{
		keyscan();
		if(time_flag==0)
		{
			BCD_time();
		}
	  
	}


}
void exint0() interrupt  0
{
	DS_read(0x0c);
	beep=0;
	time_flag=1;	
}






























asm::::::

谁能帮我用汇编写一个单片机访问时钟DS12887的程序，程序中千万不要用访问外部存储器指令：MOVX A@DPTR, 千万不要用,谢谢了.非常急用,希望哪位大侠能给我帮助! 

R/W--P2.0,DS---P2.1,CS---地,AS---P2.2,D0--D7----P0口, 显示用数码管(共阴6个,只要显示时,分,秒) 位选--P3.0-P3.5, 段码--P1口
问题补充：为什么不接P3,有原因的,我接P3口用汇编写了几个程序,也用C写了几个,就是没有任何反映,我请教了高手他们也没发现错在哪里,开始怀疑是芯片的问题,换了2块,也一样,都是新的,所以我相信是程序问题,就想请那位大侠帮我写一下已经用过的且有用的程序,小弟谢谢了先!


读取程序 
ORG 0000H 
;T_SEC: save seccond 
;T_MIN: save minute 
;T_HOUR: save hour 
;T_DAY: save day 
;T_MON: save month 
;T_YE: SAVE YEAR 
;T_CE: SAVE CENTURY 
;R0: THE FIRST DISPLAY ADDRESS 
;R1: THE START ADDRESS 
;R2: FLAG 
;R3: THE NUMBER OF DISPLAYED 
;DN: 循环次数 

T_SEC EQU 40H 
T_MIN EQU 41H 
T_HOUR EQU 42H 
T_DAY EQU 43H 
T_MON EQU 44H 
T_YE EQU 45H 
T_CE EQU 46H 
SHUH EQU 47H 
SHUL EQU 48H 
DN EQU 49H 
SJ EQU 50H 
MAIN: 
;MOV R2,#00H 
LCALL INITDS ;初始化时钟 
START: MOV R2,#25 
XH: LCALL RD12 ;读ds12c887 
MOV SJ,T_HOUR 
LCALL DISP 
MOV SJ,T_MIN 
LCALL DISP 
MOV SJ,T_SEC 
LCALL DISP 
MOV R7,#5 ;延时0.4S 
LCALL DELAY1S 
DJNZ R2,XH 
MOV R2,#20 
MOV SJ,T_YE 
LCALL DISP 
MOV SJ,T_MON 
LCALL DISP 
MOV SJ,T_DAY 
LCALL DISP 
MOV R7,#50 ;延时4S 
LCALL DELAY1S 
LCALL BENDI ;分号后为设置时间时用的 
LCALL WDDS 
AJMP START 

DISP: 
LCALL SJQL 
MOV SCON,#00H 
MOV DPTR,#SHU 
MOV A,SHUH 
MOVC A,@A+DPTR 
MOV SBUF,A 
JNB TI,$ 
CLR TI 
MOV A,SHUL 
MOVC A,@A+DPTR 
MOV SBUF,A 
JNB TI,$ 
CLR TI 
RET 

SJQL: 
MOV A,SJ 
MOV B,#10H 
DIV AB 
MOV SHUH,A 
MOV SHUL,B 
RET 
RD12: ;读12887 
CLR P2.7 
NOP 
NOP 
MOV DPTR,#200AH 
MOVX A,@DPTR 
ANL A,#80H 
JNZ NEXT0 
MOV DPTR,#2000H 
MOVX A,@DPTR 
MOV T_SEC,A 
MOV DPTR,#2002H 
MOVX A,@DPTR 
MOV T_MIN,A 
MOV DPTR,#2004H 
MOVX A,@DPTR 
MOV T_HOUR,A 
MOV DPTR,#2007H 
MOVX A,@DPTR 
MOV T_DAY,A 
MOV DPTR,#2008H 
MOVX A,@DPTR 
MOV T_MON,A 
MOV DPTR,#2009H 
MOVX A,@DPTR 
MOV T_YE,A 
MOV DPTR,#2032H 
MOVX A,@DPTR 
MOV T_CE,A 
NEXT0: RET 

INITDS: 

MOV A,#20H ;开启时钟 
MOV DPTR,#200AH 
MOVX @DPTR,A 
MOV A,#02H ;BCD码模式,24小时制 
MOV DPTR,#200BH 
MOVX @DPTR,A 
RET 
WDDS: ;写入时间 
MOV A,#70H 
MOV DPTR,#200AH 
MOVX @DPTR,A 
MOV R7,#1 
LCALL DELAY1S 
MOV DPTR,#2000H 
MOV A,T_SEC 
MOVX @DPTR,A 
MOV DPTR,#2002H 
MOV A,T_MIN 
MOVX @DPTR,A 
MOV DPTR,#2004H 
MOV A,T_HOUR 
MOVX @DPTR,A 
MOV DPTR,#2007H 
MOV A,T_DAY 
MOVX @DPTR,A 
MOV DPTR,#2008H 
MOV A,T_MON 
MOVX @DPTR,A 
MOV DPTR,#2009H 
MOV A,T_YE 
MOVX @DPTR,A 
MOV DPTR,#2032H 
MOV A,T_CE 
MOVX @DPTR,A 
MOV A,#20H 
MOV DPTR,#200AH 
MOVX @DPTR,A 
RET 
BENDI: ;设置时间 
MOV T_SEC,#00H 
MOV T_MIN,#17H 
MOV T_HOUR,#19H 
MOV T_DAY,#11H 
MOV T_MON,#08H 
MOV T_YE,#07H 
MOV T_CE,#21H 
RET 
DELAY1S: ;延时80MS 
D1: MOV R6,#200 
D2: MOV R5,#200 
DJNZ R5,$ 
DJNZ R6,D2 
DJNZ R7,D1 
RET 
SHU: DB FCH,60H,DAH,F2H,66H,B6H,BEH,E0H,FEH,F6H,EEH,3EH,9CH,7AH,9EH,8EH 
END 