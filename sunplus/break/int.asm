.TEXT
.external _fun
.public _BREAK,_FIQ,_IRQ0,_IRQ1,_IRQ2,_IRQ3,_IRQ4,_IRQ5,_IRQ6,_IRQ7
_BREAK:
	pop r1,r2 from [sp];
	R1=0x0000;//PC 'S  VALUE
	R2=_fun;
	push r1,r2 to [sp];
	reti;
_FIQ:
	RETI
_IRQ0:
	RETI;
_IRQ1:
	RETI;
_IRQ2:
	RETI;
_IRQ3:
	RETI;
_IRQ4:
	RETI;
_IRQ5:
	RETI;
_IRQ6:
	RETI;
_IRQ7:
	RETI;
	
