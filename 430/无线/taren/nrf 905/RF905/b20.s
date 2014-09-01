	.module b20.c
	.area text(rom, con, rel)
	.dbfile F:\programme\RF905\b20.c
	.dbfunc e DelayUS _DelayUS fV
;           time -> R16,R17
	.even
_DelayUS::
	.dbline -1
	.dbline 22
; /***********************************************************
; *  文件名称：18b20.c
; *  功    能：读取18B20的温度
; *  时    间：2006.8.1
; *  端口使用：PD4（DQ）
; ************************************************************/
; #include <iom8v.h>
; #include <macros.h>
; 
; 
; unsigned int delaytime;
;  
; 
; 
; /************************************************************
; *   函数名称：void DelayUS(unsigned int time)
; *   功    能：软件延时Us
; *   入口参数：time 延时时间
; *   出口参数：无
; ************************************************************/
; void DelayUS(unsigned int time)
; {
L2:
	.dbline 24
;     do 
; 	  time--;
	subi R16,1
	sbci R17,0
L3:
	.dbline 25
; 	while(time > 1);  
	ldi R24,1
	ldi R25,0
	cp R24,R16
	cpc R25,R17
	brlo L2
	.dbline -2
L1:
	.dbline 0 ; func end
	ret
	.dbsym r time 16 i
	.dbend
	.dbfunc e DelayMS _DelayMS fV
;           time -> R16,R17
	.even
_DelayMS::
	.dbline -1
	.dbline 34
; }
; /************************************************************
; *   函数名称：void DelayMS(unsigned int time)
; *   功    能：软件延时
; *   入口参数：time 延时时间 MS
; *   出口参数：无
; ************************************************************/
; void DelayMS (unsigned int time)
; {
	.dbline 37
;     //TIMSK = 0x01; //timer interrupt sources
;     //SEI();   //打开定时器中断
; 	delaytime = time;
	sts _delaytime+1,R17
	sts _delaytime,R16
L6:
	.dbline 39
L7:
	.dbline 38
; 	while(delaytime)
	lds R2,_delaytime
	lds R3,_delaytime+1
	tst R2
	brne L6
	tst R3
	brne L6
X0:
	.dbline -2
L5:
	.dbline 0 ; func end
	ret
	.dbsym r time 16 i
	.dbend
	.dbfunc e DisInit _DisInit fV
	.even
_DisInit::
	.dbline -1
	.dbline 48
; 	    ;
; }
; /***********************************************************
; *   函数名称：void DisInit(void)
; *   功    能：显示端口初始化
; *   入口参数：无
; *   出口参数：无
; **********************************************************/
; void DisInit(void)
; {
	.dbline 49
;     DDRB = 0xFF;
	ldi R24,255
	out 0x17,R24
	.dbline 51
; 	//PORTB= ~DISCODE[0];
; 	DDRC = 0x0F;
	ldi R24,15
	out 0x14,R24
	.dbline 52
; 	PORTC= 0x0F;  /* 四个数码管都显示0；*/
	out 0x15,R24
	.dbline -2
L9:
	.dbline 0 ; func end
	ret
	.dbend
	.dbfunc e Check18B20 _Check18B20 fc
;         signal -> R20
	.even
_Check18B20::
	rcall push_gset1
	.dbline -1
	.dbline 62
; }
; /***********************************************************
; *   函数名称：unsigned char Check18B20(void)
; *   功    能：检查18B20是否存在
; *   入口参数：无
; *   出口参数：检查存在是返回 1 
;                 不存在是返回 0
; **********************************************************/
; unsigned char Check18B20(void)
; {
	.dbline 65
;     unsigned char signal;
; 	
; 	DDRD |= 0x08;
	sbi 0x11,3
	.dbline 66
; 	PORTD&= 0xF7;   //PD3输出低电平 ，复位18B20
	in R24,0x12
	andi R24,247
	out 0x12,R24
	.dbline 68
; 	//DelayUS(20);   //延时500US
; 	delay(450);
	ldi R16,450
	ldi R17,1
	rcall _delay
	.dbline 70
; 	
; 	PORTD|=0x08;    //PD3输出高
	sbi 0x12,3
	.dbline 71
; 	asm("nop");
	nop
	.dbline 73
; 	
; 	DDRD &= 0xF7;   //PD3输入
	in R24,0x11
	andi R24,247
	out 0x11,R24
	.dbline 76
; 	//PORTD |= 0x08;
; 	
; 	delay(40);   
	ldi R16,40
	ldi R17,0
	rcall _delay
	.dbline 79
; 	//asm("nop");
; 	
; 	signal = PIND;  //读取PD3的值,也就是18B20输出的值
	in R20,0x10
	.dbline 81
; 	
; 	signal &= 0x08;
	andi R20,8
	.dbline 82
; 	signal =(signal>>3);
	lsr R20
	lsr R20
	lsr R20
	.dbline 84
; 	
; 	delay(200);
	ldi R16,200
	ldi R17,0
	rcall _delay
	.dbline 85
; 	return signal;
	mov R16,R20
	.dbline -2
L10:
	rcall pop_gset1
	.dbline 0 ; func end
	ret
	.dbsym r signal 20 c
	.dbend
	.dbfunc e Read18B20 _Read18B20 fc
;           data -> <dead>
;           byte -> R20,R21
;              i -> R22,R23
	.even
_Read18B20::
	rcall push_gset2
	.dbline -1
	.dbline 94
; }				
; /***********************************************************
; *   函数名称：unsigned char Read18B20(void)
; *   功    能：从18B20读一个字节的数据
; *   入口参数：无
; *   出口参数：读出的数据
; ***********************************************************/
; unsigned char Read18B20(void)
; {
	.dbline 97
;    	
; 		
; 	unsigned int byte=0,i;
	clr R20
	clr R21
	.dbline 99
; 	unsigned char data;
;     for(i=0;i<8;i++)
	clr R22
	clr R23
	rjmp L15
L12:
	.dbline 100
; 	{  
	.dbline 102
; 	   	
; 	    DDRD |= 0x08; 
	sbi 0x11,3
	.dbline 103
; 		PORTD&= 0xF7;   //总线为低电平
	in R24,0x12
	andi R24,247
	out 0x12,R24
	.dbline 104
; 		asm("nop");
	nop
	.dbline 105
; 		asm("nop");
	nop
	.dbline 106
; 		asm("nop");		
	nop
	.dbline 109
; 		
; 		
; 		DDRD &= 0xf7;   //PD3端口输入
	in R24,0x11
	andi R24,247
	out 0x11,R24
	.dbline 111
; 		//PORTD|= 0X08;
; 		asm("nop");
	nop
	.dbline 112
; 		asm("nop");
	nop
	.dbline 114
; 		
;          byte>>=1;
	lsr R21
	ror R20
	.dbline 116
; 		 
; 		if((PIND & 0x08))
	sbis 0x10,3
	rjmp L16
	.dbline 117
; 		   {    byte |= 0x80;  }  
	.dbline 117
	ori R20,128
	.dbline 117
L16:
	.dbline 119
	ldi R16,50
	ldi R17,0
	rcall _delay
	.dbline 120
L13:
	.dbline 99
	subi R22,255  ; offset = 1
	sbci R23,255
L15:
	.dbline 99
	cpi R22,8
	ldi R30,0
	cpc R23,R30
	brlo L12
	.dbline 122
; 				
; 		delay(50);	  // delay 55us
; 	}
; 	
; 	return byte;
	mov R16,R20
	.dbline -2
L11:
	rcall pop_gset2
	.dbline 0 ; func end
	ret
	.dbsym l data 1 c
	.dbsym r byte 20 i
	.dbsym r i 22 i
	.dbend
	.dbfunc e Write18B20 _Write18B20 fV
;              j -> R20
;              i -> R22
;            cmd -> R10
	.even
_Write18B20::
	rcall push_gset3
	mov R10,R16
	.dbline -1
	.dbline 131
; }
; /***********************************************************
; *   函数名称：void Write18B20(unsigned char cmd)
; *   功    能：向18B20写入一个字节的数据
; *   入口参数：要写入的数据或者是字节
; *   出口参数：无
; ***********************************************************/
; void Write18B20(unsigned char cmd)
; {
	.dbline 133
;     unsigned char i,j;
; 	DDRD |= 0x08;
	sbi 0x11,3
	.dbline 135
; 	
; 	for(i=0;i<8;i++)
	clr R22
	rjmp L22
L19:
	.dbline 136
; 	{
	.dbline 137
; 	   j = cmd & 0x01;
	mov R20,R10
	andi R20,1
	.dbline 138
; 	   if(j == 0x01)
	cpi R20,1
	brne L23
	.dbline 139
; 	   {
	.dbline 140
; 	       PORTD &= 0xF7;  // PD3输出低电平
	in R24,0x12
	andi R24,247
	out 0x12,R24
	.dbline 141
; 		   delay(5);
	ldi R16,5
	ldi R17,0
	rcall _delay
	.dbline 142
; 		   PORTD |= 0x08;
	sbi 0x12,3
	.dbline 143
; 		   delay(25);   //写入一位1
	ldi R16,25
	ldi R17,0
	rcall _delay
	.dbline 144
; 	   } 
	rjmp L24
L23:
	.dbline 146
; 	   else
; 	   {
	.dbline 147
; 	       PORTD &= 0xF7;  // PD3输出低电平
	in R24,0x12
	andi R24,247
	out 0x12,R24
	.dbline 148
; 		   delay(25);
	ldi R16,25
	ldi R17,0
	rcall _delay
	.dbline 149
; 		   PORTD |= 0x08;
	sbi 0x12,3
	.dbline 150
; 		   delay(5);    //写入一位0
	ldi R16,5
	ldi R17,0
	rcall _delay
	.dbline 152
; 	       
; 	   }
L24:
	.dbline 153
	lsr R10
	.dbline 154
L20:
	.dbline 135
	inc R22
L22:
	.dbline 135
	cpi R22,8
	brlo L19
	.dbline -2
L18:
	rcall pop_gset3
	.dbline 0 ; func end
	ret
	.dbsym r j 20 c
	.dbsym r i 22 c
	.dbsym r cmd 10 c
	.dbend
	.dbfunc e GetTemp _GetTemp fi
;   ds18b20_temp -> R20,R21
;        ds18b20 -> y+0
;              i -> R22,R23
	.even
_GetTemp::
	rcall push_gset2
	sbiw R28,2
	.dbline -1
	.dbline 158
; 	   cmd = cmd>>1; 
; 	}
; }
; /************************** main()******************************/
; unsigned int GetTemp(void)
; {
	.dbline 161
;     unsigned int i;
; 	unsigned char ds18b20[2];
; 	unsigned int ds18b20_temp=0;
	clr R20
	clr R21
L26:
	.dbline 166
L27:
	.dbline 165
; 	
;     
; 	
; 	while(0x01 == Check18B20()) //检查18b20是否存在
	rcall _Check18B20
	cpi R16,1
	breq L26
	.dbline 167
; 	    ;
;     Write18B20(0xcc);		
	ldi R16,204
	rcall _Write18B20
	.dbline 168
; 	Write18B20(0x44);           //启动转换
	ldi R16,68
	rcall _Write18B20
	.dbline 170
; 	
;      for(i=0;i<200;i++)   //每次转换需要延时200ms以上 
	clr R22
	clr R23
	rjmp L32
L29:
	.dbline 171
	ldi R16,1000
	ldi R17,3
	rcall _delay
L30:
	.dbline 170
	subi R22,255  ; offset = 1
	sbci R23,255
L32:
	.dbline 170
	cpi R22,200
	ldi R30,0
	cpc R23,R30
	brlo L29
L33:
	.dbline 174
L34:
	.dbline 173
;       delay(1000);   
; 	  
; 	while(0x01 == Check18B20()) //检查18b20是否存在
	rcall _Check18B20
	cpi R16,1
	breq L33
	.dbline 176
; 	    ;
; 		
; 	Write18B20(0xcc);
	ldi R16,204
	rcall _Write18B20
	.dbline 177
;     Write18B20(0xbe);  //读取温度值
	ldi R16,190
	rcall _Write18B20
	.dbline 179
; 	
; 	for(i=0;i<2;i++)
	clr R22
	clr R23
	rjmp L39
L36:
	.dbline 180
	.dbline 181
	rcall _Read18B20
	movw R24,R28
	movw R30,R22
	add R30,R24
	adc R31,R25
	std z+0,R16
	.dbline 182
L37:
	.dbline 179
	subi R22,255  ; offset = 1
	sbci R23,255
L39:
	.dbline 179
	cpi R22,2
	ldi R30,0
	cpc R23,R30
	brlo L36
	.dbline 183
; 	{
; 	    ds18b20[i] = Read18B20();
; 	}
; 	ds18b20_temp = (ds18b20[1]<<8);
	ldd R20,y+1
	clr R21
	mov R21,R20
	clr R20
	.dbline 184
; 	ds18b20_temp = ds18b20_temp + ds18b20[0];
	ldd R2,y+0
	clr R3
	add R20,R2
	adc R21,R3
	.dbline 186
; 	
; 	return  ds18b20_temp ;
	movw R16,R20
	.dbline -2
L25:
	adiw R28,2
	rcall pop_gset2
	.dbline 0 ; func end
	ret
	.dbsym r ds18b20_temp 20 i
	.dbsym l ds18b20 0 A[2:2]c
	.dbsym r i 22 i
	.dbend
	.area bss(ram, con, rel)
	.dbfile F:\programme\RF905\b20.c
_delaytime::
	.blkb 2
	.dbsym e delaytime _delaytime i
