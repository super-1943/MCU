org 0000h
setb 03;
setb c;
anl c,/03;
mov a,#0fh
mov R1,#0f0h
mov @R1,a;
ajmp $

end