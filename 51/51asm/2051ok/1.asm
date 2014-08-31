SCL bit P3.4
SDA bit P3.5

org 0000h
ljmp reset;
org 0023h
jb RI,rec;
clr TI;
reti;
rec:
clr RI;
mov A,SBUF;
mov SBUF,A;
reti;
org 0100h
reset:
	mov SP,#53H;
	mov TMOD,#20h;T1:mode 2
	mov TH1,#0FDH
	mov TL1,#0FDH
	mov PCON,#80H;baudrate=19200@11059200Hz
	setb TR1;
	setb SM1;
	clr  SM0;mode 1,8bit,baud=2^SMOD/32*T1_overflow_rate
	setb REN;
	setb EA;
	setb ES;
	mov P1,#55h;
	acall iic_init;
	acall iic_start;
	acall iic_stop;
	sjmp $;

iic_init:
	setb SCL;
	setb SDA;
	ret;
iic_start:
	acall iic_init;
	clr SDA;
	ret;
iic_stop:
	setb SCL;
	setb SDA;
	ret;
end