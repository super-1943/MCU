	.module display.c
	.area text(rom, con, rel)
	.dbfile F:\programme\RF905\display.c
	.dbfunc e display4 _display4 fV
	.area func_lit(rom, con, rel)
L14:
	.word `L5
	.word `L5
	.word `L5
	.word `L5
	.word `L5
	.word `L5
	.word `L5
	.word `L5
	.word `L5
	.word `L5
	.word `L2
	.word `L2
	.word `L2
	.word `L6
	.word `L7
	.word `L8
	.word `L9
	.area text(rom, con, rel)
	.dbfile F:\programme\RF905\display.c
;             kk -> R20
	.even
_display4::
	rcall push_gset2
	mov R20,R16
	.dbline -1
	.dbline 12
; //************************************************************//
; //本模块用于显示程序运行过程中需要显示的一些数据，可按需要改动
; //注意：将要显示的数据设为外部变量
; //周金广做
; //**********************************************************//
; #include <stdio.h>
; #include <iom8v.h>
; #include <macros.h>
; 
; 
; void display4(unsigned char kk)  //临时少麻烦
; { 
	.dbline 13
;   lcd_write_comm(0x30);
	ldi R16,48
	ldi R17,0
	rcall _lcd_write_comm
	.dbline 14
;   lcd_write_comm(0x0c);
	ldi R16,12
	ldi R17,0
	rcall _lcd_write_comm
	.dbline 15
;   switch(kk)
	mov R22,R20
	clr R23
	cpi R22,35
	ldi R30,0
	cpc R23,R30
	brne X1
	rjmp L11
X1:
	ldi R24,35
	ldi R25,0
	cp R24,R22
	cpc R25,R23
	brlt L13
L12:
	cpi R22,0
	ldi R30,0
	cpc R23,R30
	brge X2
	rjmp L2
X2:
	ldi R24,16
	ldi R25,0
	cp R24,R22
	cpc R25,R23
	brge X3
	rjmp L2
X3:
	ldi R16,2
	ldi R17,0
	movw R18,R22
	rcall empy16s
	movw R30,R16
	ldi R24,<L14
	ldi R25,>L14
	add R30,R24
	adc R31,R25
	lpm R0,Z+
	lpm R1,Z
	movw R30,R0
	ijmp
L13:
	cpi R22,42
	ldi R30,0
	cpc R23,R30
	brne X4
	rjmp L10
X4:
	rjmp L2
X0:
	.dbline 16
; 	 {case 1: 
L5:
	.dbline 25
; 	  case 2: 
; 	  case 3: 
; 	  case 4:
; 	  case 5:
; 	  case 6:  
; 	  case 7: 
; 	  case 8:
; 	  case 9: 		  
; 	  case 0:  lcd_write_comm(0x98); displaybyte2(kk); break;	
	ldi R16,152
	ldi R17,0
	rcall _lcd_write_comm
	.dbline 25
	mov R16,R20
	clr R17
	rcall _displaybyte2
	.dbline 25
	rjmp L3
L6:
	.dbline 26
; 	  case 13: lcd_write_comm(0x98);lcd_write_data('F');lcd_write_data('1'); break;		
	ldi R16,152
	ldi R17,0
	rcall _lcd_write_comm
	.dbline 26
	ldi R16,70
	ldi R17,0
	rcall _lcd_write_data
	.dbline 26
	ldi R16,49
	ldi R17,0
	rcall _lcd_write_data
	.dbline 26
	rjmp L3
L7:
	.dbline 27
; 	  case 14: lcd_write_comm(0x98);lcd_write_data('F');lcd_write_data('2'); break; 
	ldi R16,152
	ldi R17,0
	rcall _lcd_write_comm
	.dbline 27
	ldi R16,70
	ldi R17,0
	rcall _lcd_write_data
	.dbline 27
	ldi R16,50
	ldi R17,0
	rcall _lcd_write_data
	.dbline 27
	rjmp L3
L8:
	.dbline 28
; 	  case 15: lcd_write_comm(0x98);lcd_write_data('F');lcd_write_data('2'); break;	  
	ldi R16,152
	ldi R17,0
	rcall _lcd_write_comm
	.dbline 28
	ldi R16,70
	ldi R17,0
	rcall _lcd_write_data
	.dbline 28
	ldi R16,50
	ldi R17,0
	rcall _lcd_write_data
	.dbline 28
	rjmp L3
L9:
	.dbline 29
; 	  case 16: lcd_write_comm(0x98);lcd_write_data('F');lcd_write_data('4');  break; 
	ldi R16,152
	ldi R17,0
	rcall _lcd_write_comm
	.dbline 29
	ldi R16,70
	ldi R17,0
	rcall _lcd_write_data
	.dbline 29
	ldi R16,52
	ldi R17,0
	rcall _lcd_write_data
	.dbline 29
	rjmp L3
L10:
	.dbline 30
; 	  case '*':lcd_write_comm(0x98);lcd_write_data(' ');lcd_write_data('*'); break;		
	ldi R16,152
	ldi R17,0
	rcall _lcd_write_comm
	.dbline 30
	ldi R16,32
	ldi R17,0
	rcall _lcd_write_data
	.dbline 30
	ldi R16,42
	ldi R17,0
	rcall _lcd_write_data
	.dbline 30
	rjmp L3
L11:
	.dbline 31
; 	  case '#':lcd_write_comm(0x98);lcd_write_data(' ');lcd_write_data('#');   break;
	ldi R16,152
	ldi R17,0
	rcall _lcd_write_comm
	.dbline 31
	ldi R16,32
	ldi R17,0
	rcall _lcd_write_data
	.dbline 31
	ldi R16,35
	ldi R17,0
	rcall _lcd_write_data
	.dbline 31
	rjmp L3
L2:
	.dbline 32
	ldi R16,152
	ldi R17,0
	rcall _lcd_write_comm
	.dbline 32
	ldi R16,78
	ldi R17,0
	rcall _lcd_write_data
	.dbline 32
	ldi R16,79
	ldi R17,0
	rcall _lcd_write_data
	.dbline 32
L3:
	.dbline -2
L1:
	rcall pop_gset2
	.dbline 0 ; func end
	ret
	.dbsym r kk 20 c
	.dbend
	.dbfunc e displaybyte _displaybyte fV
;           data -> R20
	.even
_displaybyte::
	rcall push_gset1
	mov R20,R16
	.dbline -1
	.dbline 38
; 	  default: lcd_write_comm(0x98);lcd_write_data('N');lcd_write_data('O'); break;
;      }  
;    
; }
; 
; void displaybyte(unsigned char data)
; { 
	.dbline 39
;   lcd_write_data(data/100%10+0x30);
	ldi R18,100
	ldi R19,0
	mov R16,R20
	clr R17
	rcall div16s
	ldi R18,10
	ldi R19,0
	rcall mod16s
	subi R16,208  ; offset = 48
	sbci R17,255
	rcall _lcd_write_data
	.dbline 40
;   lcd_write_data(data/10%10+0x30);
	ldi R18,10
	ldi R19,0
	mov R16,R20
	clr R17
	rcall div16s
	ldi R18,10
	ldi R19,0
	rcall mod16s
	subi R16,208  ; offset = 48
	sbci R17,255
	rcall _lcd_write_data
	.dbline 41
;   lcd_write_data(data%10+0x30); 
	ldi R18,10
	ldi R19,0
	mov R16,R20
	clr R17
	rcall mod16s
	subi R16,208  ; offset = 48
	sbci R17,255
	rcall _lcd_write_data
	.dbline -2
L15:
	rcall pop_gset1
	.dbline 0 ; func end
	ret
	.dbsym r data 20 c
	.dbend
	.dbfunc e displayint _displayint fV
;           data -> R20
;        address -> R22
	.even
_displayint::
	rcall push_gset2
	mov R20,R18
	mov R22,R16
	.dbline -1
	.dbline 44
; }
; void displayint(unsigned char address,unsigned char data)
; {   lcd_write_comm(0x30);
	.dbline 44
	ldi R16,48
	ldi R17,0
	rcall _lcd_write_comm
	.dbline 45
;     lcd_write_comm(address);
	mov R16,R22
	clr R17
	rcall _lcd_write_comm
	.dbline 46
; 	displaybyte(data);
	mov R16,R20
	rcall _displaybyte
	.dbline -2
L16:
	rcall pop_gset2
	.dbline 0 ; func end
	ret
	.dbsym r data 20 c
	.dbsym r address 22 c
	.dbend
	.dbfunc e displaybyte2 _displaybyte2 fV
;           data -> R20
	.even
_displaybyte2::
	rcall push_gset1
	mov R20,R16
	.dbline -1
	.dbline 50
; }
; 
; void displaybyte2(unsigned char data)
; { 
	.dbline 51
;   lcd_write_data(data/10%10+0x30);
	ldi R18,10
	ldi R19,0
	mov R16,R20
	clr R17
	rcall div16s
	ldi R18,10
	ldi R19,0
	rcall mod16s
	subi R16,208  ; offset = 48
	sbci R17,255
	rcall _lcd_write_data
	.dbline 52
;   lcd_write_data(data%10+0x30); 
	ldi R18,10
	ldi R19,0
	mov R16,R20
	clr R17
	rcall mod16s
	subi R16,208  ; offset = 48
	sbci R17,255
	rcall _lcd_write_data
	.dbline -2
L17:
	rcall pop_gset1
	.dbline 0 ; func end
	ret
	.dbsym r data 20 c
	.dbend
	.dbfunc e display_char _display_char fV
;              i -> R20
;            len -> R22
;        address -> R20
;            Ptr -> R10,R11
	.even
_display_char::
	rcall push_gset3
	mov R20,R18
	movw R10,R16
	ldd R22,y+6
	.dbline -1
	.dbline 60
; }
; //////////////////////////////////////////////////////////////////////
; //*Ptr       字符串的首地址 
; //address    液晶屏的地址0x80-0x8f,0x90-0x9f之间
; //len        显示的数据的长度,如果不够后面补空格
; /////////////////////////////////////////////////////////////////////
; void display_char(unsigned char *Ptr ,unsigned char address,unsigned char len)
; {   unsigned char i;
	.dbline 62
; 
;     lcd_write_comm(0x30);
	ldi R16,48
	ldi R17,0
	rcall _lcd_write_comm
	.dbline 63
;     lcd_write_comm(address);
	mov R16,R20
	clr R17
	rcall _lcd_write_comm
	.dbline 64
;     lcd_write_comm(0x0c);
	ldi R16,12
	ldi R17,0
	rcall _lcd_write_comm
	.dbline 65
; 	for(i=0;i<len;i++)
	clr R20
	rjmp L22
L19:
	.dbline 66
; 	{
	.dbline 67
; 	if(*Ptr!='/0')
	movw R30,R10
	ldd R24,z+0
	cpi R24,47
	breq L23
	.dbline 68
; 	lcd_write_data(*Ptr++);
	ld R16,Z+
	movw R10,R30
	clr R17
	rcall _lcd_write_data
	rjmp L24
L23:
	.dbline 70
; 	else
; 	lcd_write_data(' ');
	ldi R16,32
	ldi R17,0
	rcall _lcd_write_data
L24:
	.dbline 71
L20:
	.dbline 65
	inc R20
L22:
	.dbline 65
	cp R20,R22
	brlo L19
	.dbline -2
L18:
	rcall pop_gset3
	.dbline 0 ; func end
	ret
	.dbsym r i 20 c
	.dbsym r len 22 c
	.dbsym r address 20 c
	.dbsym r Ptr 10 pc
	.dbend
	.dbfunc e display_int _display_int fV
;              i -> R20
;            len -> R22
;        address -> R20
;            Ptr -> R10,R11
	.even
_display_int::
	rcall push_gset3
	mov R20,R18
	movw R10,R16
	ldd R22,y+6
	.dbline -1
	.dbline 80
; 	}
; }
; 
; //////////////////////////////////////////////////////////////////////
; //*Ptr       字符串的首地址 
; //address    液晶屏的地址0x80-0x8f,0x90-0x9f之间
; //len        显示的数据的长度,如果不够后面补空格
; /////////////////////////////////////////////////////////////////////
; void display_int(unsigned char *Ptr ,unsigned char address,unsigned char len)
; {   unsigned char i;
	.dbline 82
; 
;     lcd_write_comm(0x30);
	ldi R16,48
	ldi R17,0
	rcall _lcd_write_comm
	.dbline 83
;     lcd_write_comm(address);
	mov R16,R20
	clr R17
	rcall _lcd_write_comm
	.dbline 84
;     lcd_write_comm(0x0c);
	ldi R16,12
	ldi R17,0
	rcall _lcd_write_comm
	.dbline 85
; 	for(i=0;i<len;i++)
	clr R20
	rjmp L29
L26:
	.dbline 86
	.dbline 89
	.dbline 90
	movw R30,R10
	ldd R16,z+0
	rcall _displaybyte
	.dbline 91
	movw R24,R10
	adiw R24,1
	movw R10,R24
	.dbline 92
	ldi R16,32
	ldi R17,0
	rcall _lcd_write_data
	.dbline 93
	.dbline 97
L27:
	.dbline 85
	inc R20
L29:
	.dbline 85
	cp R20,R22
	brlo L26
	.dbline -2
L25:
	rcall pop_gset3
	.dbline 0 ; func end
	ret
	.dbsym r i 20 c
	.dbsym r len 22 c
	.dbsym r address 20 c
	.dbsym r Ptr 10 pc
	.dbend
