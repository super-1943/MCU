CC = iccavr
CFLAGS =  -e -D__ICC_VERSION="7.00"  -l -g -Wa-W 
ASFLAGS = $(CFLAGS)  -Wa-g
LFLAGS =  -g -Wl-W -bfunc_lit:0x4.0x2000 -dram_end:0x25f -bdata:0x60.0x25f -dhwstk_size:16 -beeprom:1.512 -fihx_coff -S2
FILES = jifeng_jieshou.o 

jifeng_jieshou:	$(FILES)
	$(CC) -o jifeng_jieshou $(LFLAGS) @jifeng_jieshou.lk  
jifeng_jieshou.o: C:\iccv7avr\include\iom16v.h C:\iccv7avr\include\macros.h
jifeng_jieshou.o:	F:\开发板配套资料\JASK3000软件开发包\遥控开关\NRF905_接收\jifeng_jieshou.c
	$(CC) -c $(CFLAGS) F:\开发板配套资料\JASK3000软件开发包\遥控开关\NRF905_接收\jifeng_jieshou.c
