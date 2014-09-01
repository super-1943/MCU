	.module lcd.c
	.area text(rom, con, rel)
	.dbfile F:\programme\RF905\lcd.c
	.dbfunc e delay _delay fV
;              i -> R20,R21
;          times -> R16,R17
	.even
_delay::
	rcall push_gset1
	.dbline -1
	.dbline 21
; ///****************************************************************//
; //液晶显示模块，采用ATmega8单片机和OCM4*8液晶，串行方式
; //采用PORTD的高三位
; //pd5---lcd_cs
; //pd7---lcd_sdat
; //pd6---lcd_sclk
; //周金广2006年7月20日整理
; ///****************************************************************//
; ///////////////////////////////////////////////////
; //lcd初始化程序
; //////////////////////////////////////////////////
; #include <stdio.h>
; #include <iom8v.h>
; #include <macros.h>
; 
; 
; ///////////////////////////////////////////////
; //
; //////////////////////////////////////////////
; void delay(unsigned int times)
; {unsigned int i;
	.dbline 22
; for(i=0;i<times;i++)
	clr R20
	clr R21
	rjmp L5
L2:
	.dbline 23
L3:
	.dbline 22
	subi R20,255  ; offset = 1
	sbci R21,255
L5:
	.dbline 22
	cp R20,R16
	cpc R21,R17
	brlo L2
	.dbline -2
L1:
	rcall pop_gset1
	.dbline 0 ; func end
	ret
	.dbsym r i 20 i
	.dbsym r times 16 i
	.dbend
	.dbfunc e lcd_send_byte _lcd_send_byte fV
;          data1 -> R20,R21
;              i -> R22,R23
;           data -> R10
	.even
_lcd_send_byte::
	rcall push_gset3
	mov R10,R16
	.dbline -1
	.dbline 27
; ;
; }
; 
; void lcd_send_byte(char data)
; {unsigned int i,data1;
	.dbline 28
; for(i=0;i<8;i++)
	clr R22
	clr R23
	rjmp L10
L7:
	.dbline 29
; {data1=data&0x80;       //test data bit7 为零则放送零，为一则放送一
	.dbline 29
	mov R20,R10
	clr R21
	andi R20,128
	andi R21,0
	.dbline 30
;  if(data1!=0)
	cpi R20,0
	cpc R20,R21
	breq L11
X0:
	.dbline 31
;  { PORTD|=BIT(PD7);
	.dbline 31
	sbi 0x12,7
	.dbline 32
;      delay(20);
	ldi R16,20
	ldi R17,0
	rcall _delay
	.dbline 33
;   }
	rjmp L12
L11:
	.dbline 34
;  else {PORTD&=~BIT(PD7);          ///当单片机速度太快时，加延时
	.dbline 34
	cbi 0x12,7
	.dbline 35
;      delay(20); }
	ldi R16,20
	ldi R17,0
	rcall _delay
	.dbline 35
L12:
	.dbline 38
	sbi 0x12,6
	.dbline 40
	cbi 0x12,6
	.dbline 41
	lsl R10
	.dbline 42
L8:
	.dbline 28
	subi R22,255  ; offset = 1
	sbci R23,255
L10:
	.dbline 28
	cpi R22,8
	ldi R30,0
	cpc R23,R30
	brlo L7
	.dbline -2
L6:
	rcall pop_gset3
	.dbline 0 ; func end
	ret
	.dbsym r data1 20 i
	.dbsym r i 22 i
	.dbsym r data 10 c
	.dbend
	.dbfunc e lcd_write_data _lcd_write_data fV
;          data2 -> R22
;          data1 -> R10
;          data3 -> R20
;           data -> R20
	.even
_lcd_write_data::
	rcall push_gset3
	mov R20,R16
	.dbline -1
	.dbline 48
; 	   
; //PORTD=PORTD&data;
; PORTD|=BIT(PD6);     // set sclk high
; 
; PORTD&=~BIT(PD6);    // set sclk low
; data=data<<1;
; }
; }
; /////////////////////////////////////////////////////////////
; ////
; ////////////////////////////////////////////////////////////
; void lcd_write_data(char data)
; {char data1=0xfa,data2,data3;
	.dbline 48
	ldi R24,250
	mov R10,R24
	.dbline 50
;     
; 	PORTD|=BIT(PD5);      //set cs high
	sbi 0x12,5
	.dbline 52
; 	
;    data2=data&0xf0;
	mov R22,R20
	andi R22,240
	.dbline 53
;    data3=data&0x0f;
	andi R20,15
	.dbline 54
;    data3=data3<<4;
	mov R24,R20
	andi R24,#0x0F
	swap R24
	mov R20,R24
	.dbline 56
;    
;    lcd_send_byte(data1);
	mov R16,R10
	rcall _lcd_send_byte
	.dbline 57
;    lcd_send_byte(data2);
	mov R16,R22
	rcall _lcd_send_byte
	.dbline 58
;    lcd_send_byte(data3);
	mov R16,R20
	rcall _lcd_send_byte
	.dbline 60
;    
;    PORTD&=~BIT(PD5);       //set cs low
	cbi 0x12,5
	.dbline -2
L13:
	rcall pop_gset3
	.dbline 0 ; func end
	ret
	.dbsym r data2 22 c
	.dbsym r data1 10 c
	.dbsym r data3 20 c
	.dbsym r data 20 c
	.dbend
	.dbfunc e lcd_write_comm _lcd_write_comm fV
;          data2 -> R22
;          data1 -> R10
;          data3 -> R20
;           data -> R20
	.even
_lcd_write_comm::
	rcall push_gset3
	mov R20,R16
	.dbline -1
	.dbline 68
; 
; }
; /////////////////////////////////////////////////////////////
; ////
; ////////////////////////////////////////////////////////////
; void lcd_write_comm(char data)
; //int data;
; {char data1=0xf8,data2,data3;
	.dbline 68
	ldi R24,248
	mov R10,R24
	.dbline 69
;    PORTD|=BIT(PD5);     //set cs high
	sbi 0x12,5
	.dbline 71
;    
;    data2=data&0xf0;
	mov R22,R20
	andi R22,240
	.dbline 72
;    data3=data&0x0f;
	andi R20,15
	.dbline 73
;    data3=data3<<4;
	mov R24,R20
	andi R24,#0x0F
	swap R24
	mov R20,R24
	.dbline 75
;    
;    lcd_send_byte(data1);
	mov R16,R10
	rcall _lcd_send_byte
	.dbline 76
;    lcd_send_byte(data2);
	mov R16,R22
	rcall _lcd_send_byte
	.dbline 77
;    lcd_send_byte(data3);
	mov R16,R20
	rcall _lcd_send_byte
	.dbline 79
;    
;    PORTD&=~BIT(PD5);     //set cs low
	cbi 0x12,5
	.dbline -2
L14:
	rcall pop_gset3
	.dbline 0 ; func end
	ret
	.dbsym r data2 22 c
	.dbsym r data1 10 c
	.dbsym r data3 20 c
	.dbsym r data 20 c
	.dbend
	.dbfunc e lcd_initial _lcd_initial fV
	.even
_lcd_initial::
	.dbline -1
	.dbline 83
; 
; }
; void lcd_initial(void)
; {
	.dbline 85
;     
;    lcd_write_comm(0x30);			//基本指令集
	ldi R16,48
	rcall _lcd_write_comm
	.dbline 86
;    lcd_write_comm(0x01);			//清除显示屏幕，把DDRAM位址计数器调整为"00H"
	ldi R16,1
	rcall _lcd_write_comm
	.dbline 87
;    lcd_write_comm(0x03);			//把DDRAM位址计数器调整为"00H"，游标回原点，该功能不影响显示DDRAM
	ldi R16,3
	rcall _lcd_write_comm
	.dbline 88
;    lcd_write_comm(0x06);			//光标右移
	ldi R16,6
	rcall _lcd_write_comm
	.dbline 89
;    lcd_write_comm(0x0c);			//显示屏打开
	ldi R16,12
	rcall _lcd_write_comm
	.dbline -2
L15:
	.dbline 0 ; func end
	ret
	.dbend
	.dbfunc e screen _screen fV
;              j -> <dead>
;              i -> R20,R21
;           data -> R22,R23
	.even
_screen::
	rcall push_gset2
	movw R22,R16
	.dbline -1
	.dbline 98
; }
; /////////////////////////////////////////////////////
; ////
; /////////////////////////////////////////////////////
; 
; void screen(data)
; char data[65];
; 
;  {         
	.dbline 100
; 	    unsigned int i,j;
; 		lcd_write_comm(0x08);
	ldi R16,8
	rcall _lcd_write_comm
	.dbline 101
; 		for (i=0;i<64;i++)
	clr R20
	clr R21
	rjmp L20
L17:
	.dbline 102
; 			{lcd_write_data(data[i]);
	.dbline 102
	movw R30,R20
	add R30,R22
	adc R31,R23
	ldd R16,z+0
	rcall _lcd_write_data
	.dbline 103
; 			if (i==15)
	cpi R20,15
	ldi R30,0
	cpc R21,R30
	brne L21
	.dbline 104
; 			lcd_write_comm(0x90);      //设定DDRAM第二行，第一列
	ldi R16,144
	rcall _lcd_write_comm
L21:
	.dbline 105
; 			if (i==31)
	cpi R20,31
	ldi R30,0
	cpc R21,R30
	brne L23
	.dbline 106
; 			lcd_write_comm(0x88);     //设定DDRAM第三行，第一列
	ldi R16,136
	rcall _lcd_write_comm
L23:
	.dbline 107
; 			if (i==47)
	cpi R20,47
	ldi R30,0
	cpc R21,R30
	brne L25
	.dbline 108
; 			lcd_write_comm(0x98);     //设定DDRAM第四行，第一列
	ldi R16,152
	rcall _lcd_write_comm
L25:
	.dbline 109
; 			if (i==63)
	cpi R20,63
	ldi R30,0
	cpc R21,R30
	brne L27
	.dbline 110
; 			lcd_write_comm(0x80);     //设定DDRAM第一行，第一列
	ldi R16,128
	rcall _lcd_write_comm
L27:
	.dbline 111
L18:
	.dbline 101
	subi R20,255  ; offset = 1
	sbci R21,255
L20:
	.dbline 101
	cpi R20,64
	ldi R30,0
	cpc R21,R30
	brlo L17
	.dbline 112
; 			}
; 		lcd_write_comm(0x0c);
	ldi R16,12
	rcall _lcd_write_comm
	.dbline -2
L16:
	rcall pop_gset2
	.dbline 0 ; func end
	ret
	.dbsym l j 1 i
	.dbsym r i 20 i
	.dbsym r data 22 pc
	.dbend
	.dbfunc e fanxian _fanxian fV
;              y -> R20
;              x -> R22
;              j -> R10
;              i -> R12
;           hang -> R14
	.even
_fanxian::
	rcall push_gset5
	mov R14,R16
	.dbline -1
	.dbline 116
; }	
; //////////////////////////////////
; void fanxian(unsigned char hang)   //  0x80-1     0x90-2   0x88-3    0x98-4
; 	{	
	.dbline 118
; 	    unsigned char x,y,i,j;
; 	     lcd_write_comm(0x34);        //开启绘图功能显示 
	ldi R16,52
	rcall _lcd_write_comm
	.dbline 119
; 		 lcd_write_comm(0x34);
	ldi R16,52
	rcall _lcd_write_comm
	.dbline 121
; 	    
; 	    y=0x80;
	ldi R20,128
	.dbline 122
;         x=0x80;
	ldi R22,128
	.dbline 123
; 		lcd_write_data(0x00);
	clr R16
	rcall _lcd_write_data
	.dbline 124
; 		lcd_write_comm(x);             //设置x 坐标 
	mov R16,R22
	rcall _lcd_write_comm
	.dbline 125
; 		lcd_write_comm(y); 
	mov R16,R20
	rcall _lcd_write_comm
	.dbline 126
; 		for (j=0;j<32;j++)
	clr R10
	rjmp L33
L30:
	.dbline 127
; 		  {for (i=0;i<16;i++)
	.dbline 127
	clr R12
	rjmp L37
L34:
	.dbline 128
	clr R16
	rcall _lcd_write_data
L35:
	.dbline 127
	inc R12
L37:
	.dbline 127
	mov R24,R12
	cpi R24,16
	brlo L34
	.dbline 131
	mov R24,R22
	subi R24,255    ; addi 1
	mov R22,R24
	mov R16,R24
	rcall _lcd_write_comm
	.dbline 132
	mov R16,R20
	rcall _lcd_write_comm
	.dbline 134
L31:
	.dbline 126
	inc R10
L33:
	.dbline 126
	mov R24,R10
	cpi R24,32
	brlo L30
	.dbline 136
; 			lcd_write_data(0x00);
; 		
; 			
; 			lcd_write_comm(++x);
; 			lcd_write_comm(y);
; 			
; 		  }
; 		
;         y=0x88; 
	ldi R20,136
	.dbline 137
; 		x=0x80;
	ldi R22,128
	.dbline 138
; 		lcd_write_data(0x00);
	clr R16
	rcall _lcd_write_data
	.dbline 139
;      	lcd_write_comm(x);
	mov R16,R22
	rcall _lcd_write_comm
	.dbline 140
; 		lcd_write_comm(y);
	mov R16,R20
	rcall _lcd_write_comm
	.dbline 141
; 		for (j=32;j<64;j++)
	ldi R24,32
	mov R10,R24
	rjmp L41
L38:
	.dbline 142
; 		  {for (i=0;i<16;i++)
	.dbline 142
	clr R12
	rjmp L45
L42:
	.dbline 143
	clr R16
	rcall _lcd_write_data
L43:
	.dbline 142
	inc R12
L45:
	.dbline 142
	mov R24,R12
	cpi R24,16
	brlo L42
	.dbline 144
	mov R24,R22
	subi R24,255    ; addi 1
	mov R22,R24
	mov R16,R24
	rcall _lcd_write_comm
	.dbline 145
	mov R16,R20
	rcall _lcd_write_comm
	.dbline 148
L39:
	.dbline 141
	inc R10
L41:
	.dbline 141
	mov R24,R10
	cpi R24,64
	brlo L38
	.dbline 150
; 			lcd_write_data(0x00);
; 			lcd_write_comm(++x);
; 			lcd_write_comm(y); 	 
; 			
; 		  
; 		  }
; 		    
; 		  lcd_write_comm(0x36);        //开启绘图功能显示 	
	ldi R16,54
	rcall _lcd_write_comm
	.dbline 152
; 		    	
; 		if(hang==1)
	mov R24,R14
	cpi R24,1
	brne L46
	.dbline 153
;     	{
	.dbline 154
;     	y=0x80; 
	ldi R20,128
	.dbline 155
; 		x=0x80;}
	ldi R22,128
	.dbline 155
	rjmp L47
L46:
	.dbline 156
; 		else if(hang==2)
	mov R24,R14
	cpi R24,2
	brne L48
	.dbline 157
; 		{
	.dbline 158
; 		y=0x80;
	ldi R20,128
	.dbline 159
; 		x=0x90;}
	ldi R22,144
	.dbline 159
	rjmp L49
L48:
	.dbline 160
; 		else if(hang==3)
	mov R24,R14
	cpi R24,3
	brne L50
	.dbline 161
; 		{y=0x88;
	.dbline 161
	ldi R20,136
	.dbline 162
; 		 x=0x80;}
	ldi R22,128
	.dbline 162
	rjmp L51
L50:
	.dbline 164
; 		else
; 		{y=0x88;
	.dbline 164
	ldi R20,136
	.dbline 165
; 		x=0x90;}
	ldi R22,144
	.dbline 165
L51:
L49:
L47:
	.dbline 167
; 		
; 		lcd_write_comm(x);             //设置x 坐标 
	mov R16,R22
	rcall _lcd_write_comm
	.dbline 168
; 		lcd_write_comm(y);             //设置y 坐标
	mov R16,R20
	rcall _lcd_write_comm
	.dbline 171
; 
; 		
; 		for (j=0;j<16;j++)
	clr R10
	rjmp L55
L52:
	.dbline 172
; 		  {for (i=0;i<16;i++)
	.dbline 172
	clr R12
	rjmp L59
L56:
	.dbline 173
	ldi R16,255
	rcall _lcd_write_data
L57:
	.dbline 172
	inc R12
L59:
	.dbline 172
	mov R24,R12
	cpi R24,16
	brlo L56
	.dbline 175
	mov R24,R22
	subi R24,255    ; addi 1
	mov R22,R24
	mov R16,R24
	rcall _lcd_write_comm
	.dbline 176
	mov R16,R20
	rcall _lcd_write_comm
	.dbline 178
L53:
	.dbline 171
	inc R10
L55:
	.dbline 171
	mov R24,R10
	cpi R24,16
	brlo L52
	.dbline -2
L29:
	rcall pop_gset5
	.dbline 0 ; func end
	ret
	.dbsym r y 20 c
	.dbsym r x 22 c
	.dbsym r j 10 c
	.dbsym r i 12 c
	.dbsym r hang 14 c
	.dbend
