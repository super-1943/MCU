org 0000h
main:
mov a,#01h
l:
mov P1,a;
call delay;
rr a;
sjmp l;
sjmp main;
delay:
mov r1,#0ffh;
d:
mov r2,#0ffh;
djnz r2,$;
djnz r1,d;
ret;
end;
