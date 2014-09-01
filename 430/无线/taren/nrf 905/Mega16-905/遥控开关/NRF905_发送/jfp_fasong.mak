CC = iccavr
CFLAGS =  -IC:\iccv7avr\include -e -D__ICC_VERSION="7.00" -DATMEGA -DATMega16  -l -g -Mavr_enhanced 
ASFLAGS = $(CFLAGS)  -Wa-g
LFLAGS =  -LC:\iccv7avr\lib -g -ucrtatmega.o -bfunc_lit:0x54.0x4000 -dram_end:0x45f -bdata:0x60.0x45f -dhwstk_size:16 -beeprom:1.512 -fihx_coff -S2
FILES = jfp_fasong.o 

jfp_fasong:	$(FILES)
	$(CC) -o jfp_fasong $(LFLAGS) @jfp_fasong.lk   -lcatmega
jfp_fasong.o: C:\iccv7avr\include\iom16v.h C:\iccv7avr\include\macros.h
jfp_fasong.o:	F:\开发板配套资料\JASK3000软件开发包\遥控开关\NRF905_发送\jfp_fasong.c
	$(CC) -c $(CFLAGS) F:\开发板配套资料\JASK3000软件开发包\遥控开关\NRF905_发送\jfp_fasong.c
