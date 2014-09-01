#####################################################################
#																	 
#	Created by u'nSP IDE		14:16:06	08/31/08
#
#####################################################################




APPDIR	= D:\PROGRA~1\Sunplus\UNSPID~1.0

OUTDIR	= .\Debug

CC	= $(APPDIR)\gcc

AS	= $(APPDIR)\xasm16

LD	= $(APPDIR)\xlink16

AR	= $(APPDIR)\xLib16

RESC	= $(APPDIR)\resc

RM	= $(APPDIR)\rm -f

INCLUDES	= -I"F:/abc/guardSD" -I"F:/abc/aa/aa"

BODY	= -body SPCE060A_061A -bfile "d:\Program Files\Sunplus\unSP IDE Common\Body\SPCE060A_061A.cpt"

BINFILE	= "$(OUTDIR)\guardSD.S37"

ARYFILE	= "$(OUTDIR)\guardSD.ary"

SBMFILE	= "$(OUTDIR)\guardSD.sbm"

OPT	= -S -gstabs -mglobal-var-iram

ASFLAGS	= -t2 -d

CASFLAGS	= -t2 

CFLAGS	= $(OPT) -B$(APPDIR)\ $(INCLUDES) 

BINTYPE	= -as

LDFLAGS	= 

EXTRAFLAGS	= 


OBJFILES	= \
	"$(OUTDIR)\1_48k.res" \
	"$(OUTDIR)\12_48k.res" \
	"$(OUTDIR)\15_48k.res" \
	"$(OUTDIR)\2_48k.res" \
	"$(OUTDIR)\3_48k.res" \
	"$(OUTDIR)\7_48k.res" \
	"$(OUTDIR)\6_48k.res" \
	"$(OUTDIR)\5_48k.res" \
	"$(OUTDIR)\18_48k.res" \
	"$(OUTDIR)\17_48k.res" \
	"$(OUTDIR)\16_48k.res" \
	"$(OUTDIR)\4_48k.res" \
	"$(OUTDIR)\4com_48k.res" \
	"$(OUTDIR)\3Com_48k.res" \
	"$(OUTDIR)\Resource.obj" \
	"$(OUTDIR)\main.obj" \
	"$(OUTDIR)\initIO.obj" \
	"$(OUTDIR)\fiq.obj" \
	"$(OUTDIR)\hardware.obj" 

"$(OUTDIR)\1_48k.res": "F:\abc\guardSD\voice\1.48k"
	$(RESC) "F:\abc\guardSD\voice\1.48k" "$(OUTDIR)\1_48k.res" RES_1_48K 

"$(OUTDIR)\12_48k.res": "F:\abc\guardSD\voice\12.48k"
	$(RESC) "F:\abc\guardSD\voice\12.48k" "$(OUTDIR)\12_48k.res" RES_12_48K 

"$(OUTDIR)\15_48k.res": "F:\abc\guardSD\voice\15.48k"
	$(RESC) "F:\abc\guardSD\voice\15.48k" "$(OUTDIR)\15_48k.res" RES_15_48K 

"$(OUTDIR)\2_48k.res": "F:\abc\guardSD\voice\2.48k"
	$(RESC) "F:\abc\guardSD\voice\2.48k" "$(OUTDIR)\2_48k.res" RES_2_48K 

"$(OUTDIR)\3_48k.res": "F:\abc\guardSD\voice\3.48k"
	$(RESC) "F:\abc\guardSD\voice\3.48k" "$(OUTDIR)\3_48k.res" RES_3_48K 

"$(OUTDIR)\7_48k.res": "F:\abc\guardSD\voice\7.48k"
	$(RESC) "F:\abc\guardSD\voice\7.48k" "$(OUTDIR)\7_48k.res" RES_7_48K 

"$(OUTDIR)\6_48k.res": "F:\abc\guardSD\voice\6.48k"
	$(RESC) "F:\abc\guardSD\voice\6.48k" "$(OUTDIR)\6_48k.res" RES_6_48K 

"$(OUTDIR)\5_48k.res": "F:\abc\guardSD\voice\5.48k"
	$(RESC) "F:\abc\guardSD\voice\5.48k" "$(OUTDIR)\5_48k.res" RES_5_48K 

"$(OUTDIR)\18_48k.res": "F:\abc\guardSD\voice\18.48k"
	$(RESC) "F:\abc\guardSD\voice\18.48k" "$(OUTDIR)\18_48k.res" RES_18_48K 

"$(OUTDIR)\17_48k.res": "F:\abc\guardSD\voice\17.48k"
	$(RESC) "F:\abc\guardSD\voice\17.48k" "$(OUTDIR)\17_48k.res" RES_17_48K 

"$(OUTDIR)\16_48k.res": "F:\abc\guardSD\voice\16.48k"
	$(RESC) "F:\abc\guardSD\voice\16.48k" "$(OUTDIR)\16_48k.res" RES_16_48K 

"$(OUTDIR)\4_48k.res": "F:\abc\guardSD\voice\4.48k"
	$(RESC) "F:\abc\guardSD\voice\4.48k" "$(OUTDIR)\4_48k.res" RES_4_48K 

"$(OUTDIR)\4com_48k.res": "F:\abc\guardSD\voice\4com.48k"
	$(RESC) "F:\abc\guardSD\voice\4com.48k" "$(OUTDIR)\4com_48k.res" RES_4COM_48K 

"$(OUTDIR)\3Com_48k.res": "F:\abc\guardSD\voice\3Com.48k"
	$(RESC) "F:\abc\guardSD\voice\3Com.48k" "$(OUTDIR)\3Com_48k.res" RES_3COM_48K 

"$(OUTDIR)\Resource.obj": "F:\abc\guardSD\Resource.asm" 
	$(AS) $(ASFLAGS) $(INCLUDES) -l "$(OUTDIR)\Resource.lst" -o "$(OUTDIR)\Resource.obj" "F:\abc\guardSD\Resource.asm" 

"$(OUTDIR)\main.asm": "F:\abc\guardSD\main.c" 
	$(CC) $(CFLAGS) -o "$(OUTDIR)/main.asm" "F:/abc/guardSD/main.c" 

"$(OUTDIR)\main.obj": "$(OUTDIR)\main.asm"
	$(AS) $(CASFLAGS) $(INCLUDES) -l "$(OUTDIR)\main.lst" -o "$(OUTDIR)\main.obj" "$(OUTDIR)\main.asm" 

"$(OUTDIR)\initIO.obj": "F:\abc\guardSD\initIO.asm" 
	$(AS) $(ASFLAGS) $(INCLUDES) -l "$(OUTDIR)\initIO.lst" -o "$(OUTDIR)\initIO.obj" "F:\abc\guardSD\initIO.asm" 

"$(OUTDIR)\fiq.obj": "F:\abc\guardSD\fiq.asm" 
	$(AS) $(ASFLAGS) $(INCLUDES) -l "$(OUTDIR)\fiq.lst" -o "$(OUTDIR)\fiq.obj" "F:\abc\guardSD\fiq.asm" 

"$(OUTDIR)\hardware.obj": "F:\abc\guardSD\hardware.asm" 
	$(AS) $(ASFLAGS) $(INCLUDES) -l "$(OUTDIR)\hardware.lst" -o "$(OUTDIR)\hardware.obj" "F:\abc\guardSD\hardware.asm" 


.SUFFIXES : .c .asm .obj .s37 .tsk .res

all :	 "$(OUTDIR)" $(BINFILE)

"$(OUTDIR)" :
	if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

$(BINFILE) : $(OBJFILES) 
	$(LD) $(BINTYPE) $(ARYFILE) $(BINFILE) $(LDFLAGS) $(BODY) $(EXTRAFLAGS)

compile :	 $(OBJFILES)

clean :
	$(RM) "$(OUTDIR)\1_48k.res" 
	$(RM) "$(OUTDIR)\12_48k.res" 
	$(RM) "$(OUTDIR)\15_48k.res" 
	$(RM) "$(OUTDIR)\2_48k.res" 
	$(RM) "$(OUTDIR)\3_48k.res" 
	$(RM) "$(OUTDIR)\7_48k.res" 
	$(RM) "$(OUTDIR)\6_48k.res" 
	$(RM) "$(OUTDIR)\5_48k.res" 
	$(RM) "$(OUTDIR)\18_48k.res" 
	$(RM) "$(OUTDIR)\17_48k.res" 
	$(RM) "$(OUTDIR)\16_48k.res" 
	$(RM) "$(OUTDIR)\4_48k.res" 
	$(RM) "$(OUTDIR)\4com_48k.res" 
	$(RM) "$(OUTDIR)\3Com_48k.res" 
	$(RM) "$(OUTDIR)\Resource.obj" 
	$(RM) "$(OUTDIR)\Resource.lst" 
	$(RM) "$(OUTDIR)\main.obj" 
	$(RM) "$(OUTDIR)\main.lst" 
	$(RM) "$(OUTDIR)\main.asm" 
	$(RM) "$(OUTDIR)\initIO.obj" 
	$(RM) "$(OUTDIR)\initIO.lst" 
	$(RM) "$(OUTDIR)\fiq.obj" 
	$(RM) "$(OUTDIR)\fiq.lst" 
	$(RM) "$(OUTDIR)\hardware.obj" 
	$(RM) "$(OUTDIR)\hardware.lst" 
	$(RM) $(BINFILE) $(SBMFILE) 

.c.asm:
	$(CC) $(CFLAGS) $(INCLUDES) -o "$(OUTDIR)/$@" $<

.asm.obj:
	$(AS) $(ASFLAGS) $(INCLUDES) -o "$(OUTDIR)/$@" $<

