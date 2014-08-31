org 00h
ajmp start;
start:

mov scon,#0;
mov 30h,#01h
mov 31h,#02h
mov 32h,#04h
mov 33h,#08h
mov 34h,#10h
mov 35h,#20h
mov 36h,#40h
mov 37h,#80h;

mov r0,#30h;
mov r2,#8

loop:

mov a,@r0;
mov sbuf,a;
lo:

jnb TI,lo;
clr TI
acall delay;
inc r0
djnz r2,loop
sjmp start

delay:

mov r7,#3;

dd1:

mov r6,#0ffh

dd2:

mov r5,#0ffh

djnz r5,$;
djnz r6,dd2
djnz r7,dd1
ret
end
