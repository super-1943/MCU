CC = iccavr
CFLAGS =  -ID:\iccavr\include\ -e -DATMEGA -DATMega16  -l -g -Mavr_enhanced 
ASFLAGS = $(CFLAGS)  -Wa-g
LFLAGS =  -LD:\iccavr\lib\ -g -ucrtatmega.o -bfunc_lit:0x54.0x4000 -dram_end:0x45f -bdata:0x60.0x45f -dhwstk_size:16 -beeprom:1.512 -fihx_coff -S2
FILES = nrf905.o PTR8000.o 

PTR8000:	$(FILES)
	$(CC) -o PTR8000 $(LFLAGS) @PTR8000.lk   -lcatmega
nrf905.o: D:\IccAvr\Pei\ptr8000/config.h D:/iccavr/include/iom16v.h D:/iccavr/include/macros.h
nrf905.o:	D:\IccAvr\Pei\ptr8000\nrf905.C
	$(CC) -c $(CFLAGS) D:\IccAvr\Pei\ptr8000\nrf905.C
PTR8000.o: D:/iccavr/include/iom16v.h D:/iccavr/include/macros.h D:\IccAvr\Pei\ptr8000/config.h D:/iccavr/include/iom16v.h D:/iccavr/include/macros.h D:\IccAvr\Pei\ptr8000/nrf905.h
PTR8000.o:	D:\IccAvr\Pei\ptr8000\PTR8000.C
	$(CC) -c $(CFLAGS) D:\IccAvr\Pei\ptr8000\PTR8000.C
