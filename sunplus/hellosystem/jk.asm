.external _fun1,_fun2,_flag
.text
.public _BREAK

_BREAK:
	pop r1,r2 from [sp];
	r1=0x0000;
	r2=_fun2;
	push r1,r2 to [sp];
	reti;	



