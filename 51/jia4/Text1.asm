;begin

public WriteLCDCommand,WriteLCDData,InitLCD,ClearLCD,GotoxyLCD,DisplayLCDString

E bit P2.2
RW bit P2.1
RS bit P2.0

LCDPORT EQU P1
LCDX EQU 30H
LCDY EQU 31H
;
DE segment code ;	定义DE段为再定位程序段

RSEG DE;			选择DE段为当前段

WriteLCDCommand:
	clr RW;
	clr RS;
	SETB E
	mov LCDPORT,A;
	setb E;
	call Delay;
	clr E;
	RET
	
WriteLCDData:
	clr RW;
	setb RS;
	setb E;
	mov LCDPORT,A;
	setb E;
	call Delay;
	clr E;
	ret;
	
InitLCD:
	mov a,#38H;
	call WriteLCDCommand;
	mov a,#00CH;
	call WriteLCDCommand;
	mov a,#06h
	call WriteLCDCommand;
	ret;
	
	
ClearLCD:
	mov a,#01h
	call WriteLCDCommand;
	mov a,#02h;
	call WriteLCDCommand;
	ret;

GotoxyLCD:
	mov a,LCDX;
	cjne a,#1,NextLine;
	mov a,#80h;
	add a,LCDY;
	call WriteLCDCommand;
	sjmp RETU
NextLine:
	mov a,#0c0h;
	add a,LCDY;
	call WriteLCDCommand;

RETU:
	ret;
	
DisplayLCDString:
	mov r0,#0;
NextData:
	mov a,r0;
	movc a,@a+dptr;
	call WriteLCDData
	inc r0;
	djnz r1,NextData;
	ret;


Delay:
	mov r4,#20;
	loop:
		mov r5,#48;
		djnz r5,$;
		djnz r4,loop;
	ret;
	
END

