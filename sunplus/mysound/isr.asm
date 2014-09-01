.include hardware.inc
.public _FIQ
.external F_FIQ_Service_SACM_A2000

.text
 _FIQ:
 
 	push r1,r5 to[sp];
 	R1=C_FIQ_TMA;
 	test R1,[P_INT_Ctrl];
 	jnz TMA;
 	R1=C_FIQ_TMB;
 	test R1,[P_INT_Ctrl];
 	jnz TMB;
 	
 PWM:
 	R1=C_FIQ_PWM;
 	[P_INT_Clear]=r1;
 	pop r1,r5 from [sp];
 	reti;
TMA:
 	[P_INT_Clear]=r1;
 	call F_FIQ_Service_SACM_A2000;
 	pop r1,r5 from [sp];
 	reti;
TMB:
 	[P_INT_Clear]=r1;
 	pop r1,r5 from [sp];
 	reti;	