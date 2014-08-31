org 0000h
ajmp main;
org 000bh
ajmp timer0;
org 0030h
main:
	mov a,#0ffh;
	mov P1,a;
	mov a,P1;
	mov 30h,a;
	mov a,#01h;
	mov TMOD,a;
	mov TH0,#39;
	mov TL0,#16;
	setb ET0;
	setb EA;
	setb TR0;
	ajmp $;

timer0:
	setb P3.7;
	mov TH0,#39;
	mov TL0,#16;
	mov a,30h;
	rr a;
	mov 30h,a;
	mov P2,a;
	clr P3.7;
	reti;
	end