CC = iccavr
CFLAGS =  -ID:\icc\include\ -e -DATMega8  -l -g -Mavr_enhanced_small -Wa-W 
ASFLAGS = $(CFLAGS)  -Wa-g
LFLAGS =  -LD:\icc\lib\ -g -Wl-W -bfunc_lit:0x26.0x2000 -dram_end:0x45f -bdata:0x60.0x45f -dhwstk_size:30 -beeprom:1.512 -fihx_coff -S2
FILES = main.o display.o lcd.o nrf905config.o b20.o timer.o 

new:	$(FILES)
	$(CC) -o new $(LFLAGS) @new.lk  
main.o: D:/icc/include/stdio.h D:/icc/include/stdarg.h D:/icc/include/_const.h D:/icc/include/iom8v.h D:/icc/include/macros.h F:\programme\RF905/nrf905.h
main.o:	F:\programme\RF905\main.c
	$(CC) -c $(CFLAGS) F:\programme\RF905\main.c
display.o: D:/icc/include/stdio.h D:/icc/include/stdarg.h D:/icc/include/_const.h D:/icc/include/iom8v.h D:/icc/include/macros.h
display.o:	F:\programme\RF905\display.c
	$(CC) -c $(CFLAGS) F:\programme\RF905\display.c
lcd.o: D:/icc/include/stdio.h D:/icc/include/stdarg.h D:/icc/include/_const.h D:/icc/include/iom8v.h D:/icc/include/macros.h
lcd.o:	F:\programme\RF905\lcd.c
	$(CC) -c $(CFLAGS) F:\programme\RF905\lcd.c
nrf905config.o: F:\programme\RF905/nrf905.h D:/icc/include/iom8v.h
nrf905config.o:	F:\programme\RF905\nrf905config.c
	$(CC) -c $(CFLAGS) F:\programme\RF905\nrf905config.c
b20.o: D:/icc/include/iom8v.h D:/icc/include/macros.h
b20.o:	F:\programme\RF905\b20.c
	$(CC) -c $(CFLAGS) F:\programme\RF905\b20.c
timer.o: D:/icc/include/stdio.h D:/icc/include/stdarg.h D:/icc/include/_const.h D:/icc/include/iom8v.h D:/icc/include/macros.h
timer.o:	F:\programme\º¸≈Ãœ‘ æ—ßœ∞\key\timer.c
	$(CC) -c $(CFLAGS) F:\programme\º¸≈Ãœ‘ æ—ßœ∞\key\timer.c
