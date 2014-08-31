EXTRN code (WriteLCDCommand,WriteLCDData,InitLCD,ClearLCD,GotoxyLCD,DisplayLCDString);
LCDX EQU 30h
LCDY EQU 31h

org 0000h;
	ajmp main;
org 0040h;
main:
	mov sp,#40h;
	call InitLCD;
	call ClearLCD;
	mov LCDX,#1;
	mov LCDY,#0
	call GotoxyLCD;
	mov dptr,#table0;
	mov r1,#16;
	call DisplayLCDString;
	
	mov LCDX,#2;
	mov LCDY,#0
	call GotoxyLCD;
	mov dptr,#table1
	mov r1,#16;
	call DisplayLCDString;
	sjmp $;
	
table0:
	DB "Hello Keilc"
table1:
	DB "LCD Test Display"
	
END