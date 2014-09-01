	.module timer.c
	.area text(rom, con, rel)
	.dbfile F:\programme\键盘显示学习\key\timer.c
	.dbfunc e timer0_init _timer0_init fV
	.even
_timer0_init::
	.dbline -1
	.dbline 7
; #include <stdio.h>
; #include <iom8v.h>
; #include <macros.h>
; extern unsigned char  value_T,set_data;
; 
; void timer0_init(void) //CTC模式输出1KHz/2KHz方波
; {
	.dbline 13
;  //CLI(); //disable all interrupts
;  //MCUCR = 0x00;
; // GICR  = 0x00;
; // TIMSK = 0x01; //timer interrupt sources
;  
;  TCCR0 = 0x00; //stop
	clr R2
	out 0x33,R2
	.dbline 14
;  TCNT0 = 155;       // set count
	ldi R24,155
	out 0x32,R24
	.dbline 15
;  TCCR0 = 0x01;   //start timer
	ldi R24,1
	out 0x33,R24
	.dbline -2
L1:
	.dbline 0 ; func end
	ret
	.dbend
	.area vector(rom, abs)
	.org 18
	rjmp _timer0_ovf_isr
	.area text(rom, con, rel)
	.dbfile F:\programme\键盘显示学习\key\timer.c
	.area data(ram, con, rel)
	.dbfile F:\programme\键盘显示学习\key\timer.c
L3:
	.blkb 2
	.area idata
	.word 0
	.area data(ram, con, rel)
	.dbfile F:\programme\键盘显示学习\key\timer.c
	.area text(rom, con, rel)
	.dbfile F:\programme\键盘显示学习\key\timer.c
	.dbfunc e timer0_ovf_isr _timer0_ovf_isr fV
	.dbsym s i L3 i
	.even
_timer0_ovf_isr::
	st -y,R2
	st -y,R3
	st -y,R4
	st -y,R5
	st -y,R24
	st -y,R25
	st -y,R30
	in R2,0x3f
	st -y,R2
	.dbline -1
	.dbline 24
;  //SEI();          //re-enable interrupts
; }
; 
; 
; 
; 
; #pragma interrupt_handler timer0_ovf_isr:10
; void timer0_ovf_isr(void)
; {static unsigned int i=0;
	.dbline 25
;  TCNT0 =155 ;                 //reload counter value
	ldi R24,155
	out 0x32,R24
	.dbline 27
;  
;  i++;
	lds R24,L3
	lds R25,L3+1
	adiw R24,1
	sts L3+1,R25
	sts L3,R24
	.dbline 29
;  // value_T++;
;  if(i==100)
	cpi R24,100
	ldi R30,0
	cpc R25,R30
	brne L4
	.dbline 30
;   { value_T++;
	.dbline 30
	lds R24,_value_T
	subi R24,255    ; addi 1
	sts _value_T,R24
	.dbline 31
;     i=0;
	clr R2
	clr R3
	sts L3+1,R3
	sts L3,R2
	.dbline 32
;   }
L4:
	.dbline 33
;  if(i < set_data)
	lds R2,_set_data
	clr R3
	lds R4,L3
	lds R5,L3+1
	cp R4,R2
	cpc R5,R3
	brsh L6
	.dbline 34
; 	  PORTC|=BIT(PC3);
	sbi 0x15,3
	rjmp L7
L6:
	.dbline 36
	cbi 0x15,3
L7:
	.dbline -2
L2:
	ld R2,y+
	out 0x3f,R2
	ld R30,y+
	ld R25,y+
	ld R24,y+
	ld R5,y+
	ld R4,y+
	ld R3,y+
	ld R2,y+
	.dbline 0 ; func end
	reti
	.dbend
