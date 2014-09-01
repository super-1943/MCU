#####################################################################
#																	 
#	Created by u'nSP IDE		16:19:01	09/01/08
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

INCLUDES	= -I"F:/abc/shibieyuyin5" -I"F:/abc/aa/aa" -I"../../../Library"

BODY	= -body SPCE060A_061A -bfile "d:\Program Files\Sunplus\unSP IDE Common\Body\SPCE060A_061A.cpt"

BINFILE	= "$(OUTDIR)\Guard_SD.S37"

ARYFILE	= "$(OUTDIR)\Guard_SD.ary"

SBMFILE	= "$(OUTDIR)\Guard_SD.sbm"

OPT	= -S -gstabs -mglobal-var-iram

ASFLAGS	= -t2 -d

CASFLAGS	= -t2 

CFLAGS	= $(OPT) -B$(APPDIR)\ $(INCLUDES) 

BINTYPE	= -as

LDFLAGS	= 

EXTRAFLAGS	= 


OBJFILES	= \
	"$(OUTDIR)\S12_24K.res" \
	"$(OUTDIR)\1_48k.res" \
	"$(OUTDIR)\2_48k.res" \
	"$(OUTDIR)\3_48k.res" \
	"$(OUTDIR)\4_48k.res" \
	"$(OUTDIR)\5_48k.res" \
	"$(OUTDIR)\6_48k.res" \
	"$(OUTDIR)\7_48k.res" \
	"$(OUTDIR)\18_48k.res" \
	"$(OUTDIR)\10_48k.res" \
	"$(OUTDIR)\11_48k.res" \
	"$(OUTDIR)\12_48k.res" \
	"$(OUTDIR)\17_48k.res" \
	"$(OUTDIR)\16_48k.res" \
	"$(OUTDIR)\15_48k.res" \
	"$(OUTDIR)\InitIO.obj" \
	"$(OUTDIR)\hardware.obj" \
	"$(OUTDIR)\FIQ.obj" \
	"$(OUTDIR)\Resource.obj" \
	"$(OUTDIR)\main.obj" 

"$(OUTDIR)\S12_24K.res": "F:\abc\shibieyuyin5\voice\S12.24K"
	$(RESC) "F:\abc\shibieyuyin5\voice\S12.24K" "$(OUTDIR)\S12_24K.res" RES_S12_24K 

"$(OUTDIR)\1_48k.res": "F:\abc\shibieyuyin5\voice\1.48k"
	$(RESC) "F:\abc\shibieyuyin5\voice\1.48k" "$(OUTDIR)\1_48k.res" RES_1_48K 

"$(OUTDIR)\2_48k.res": "F:\abc\shibieyuyin5\voice\2.48k"
	$(RESC) "F:\abc\shibieyuyin5\voice\2.48k" "$(OUTDIR)\2_48k.res" RES_2_48K 

"$(OUTDIR)\3_48k.res": "F:\abc\shibieyuyin5\voice\3.48k"
	$(RESC) "F:\abc\shibieyuyin5\voice\3.48k" "$(OUTDIR)\3_48k.res" RES_3_48K 

"$(OUTDIR)\4_48k.res": "F:\abc\shibieyuyin5\voice\4.48k"
	$(RESC) "F:\abc\shibieyuyin5\voice\4.48k" "$(OUTDIR)\4_48k.res" RES_4_48K 

"$(OUTDIR)\5_48k.res": "F:\abc\shibieyuyin5\voice\5.48k"
	$(RESC) "F:\abc\shibieyuyin5\voice\5.48k" "$(OUTDIR)\5_48k.res" RES_5_48K 

"$(OUTDIR)\6_48k.res": "F:\abc\shibieyuyin5\voice\6.48k"
	$(RESC) "F:\abc\shibieyuyin5\voice\6.48k" "$(OUTDIR)\6_48k.res" RES_6_48K 

"$(OUTDIR)\7_48k.res": "F:\abc\shibieyuyin5\voice\7.48k"
	$(RESC) "F:\abc\shibieyuyin5\voice\7.48k" "$(OUTDIR)\7_48k.res" RES_7_48K 

"$(OUTDIR)\18_48k.res": "F:\abc\shibieyuyin5\voice\18.48k"
	$(RESC) "F:\abc\shibieyuyin5\voice\18.48k" "$(OUTDIR)\18_48k.res" RES_18_48K 

"$(OUTDIR)\10_48k.res": "F:\abc\shibieyuyin5\voice\10.48k"
	$(RESC) "F:\abc\shibieyuyin5\voice\10.48k" "$(OUTDIR)\10_48k.res" RES_10_48K 

"$(OUTDIR)\11_48k.res": "F:\abc\shibieyuyin5\voice\11.48k"
	$(RESC) "F:\abc\shibieyuyin5\voice\11.48k" "$(OUTDIR)\11_48k.res" RES_11_48K 

"$(OUTDIR)\12_48k.res": "F:\abc\shibieyuyin5\voice\12.48k"
	$(RESC) "F:\abc\shibieyuyin5\voice\12.48k" "$(OUTDIR)\12_48k.res" RES_12_48K 

"$(OUTDIR)\17_48k.res": "F:\abc\shibieyuyin5\voice\17.48k"
	$(RESC) "F:\abc\shibieyuyin5\voice\17.48k" "$(OUTDIR)\17_48k.res" RES_17_48K 

"$(OUTDIR)\16_48k.res": "F:\abc\shibieyuyin5\voice\16.48k"
	$(RESC) "F:\abc\shibieyuyin5\voice\16.48k" "$(OUTDIR)\16_48k.res" RES_16_48K 

"$(OUTDIR)\15_48k.res": "F:\abc\shibieyuyin5\voice\15.48k"
	$(RESC) "F:\abc\shibieyuyin5\voice\15.48k" "$(OUTDIR)\15_48k.res" RES_15_48K 

"$(OUTDIR)\InitIO.obj": "F:\abc\shibieyuyin5\InitIO.asm" 
	$(AS) $(ASFLAGS) $(INCLUDES) -l "$(OUTDIR)\InitIO.lst" -o "$(OUTDIR)\InitIO.obj" "F:\abc\shibieyuyin5\InitIO.asm" 

"$(OUTDIR)\hardware.obj": "F:\abc\shibieyuyin5\hardware.asm" 
	$(AS) $(ASFLAGS) $(INCLUDES) -l "$(OUTDIR)\hardware.lst" -o "$(OUTDIR)\hardware.obj" "F:\abc\shibieyuyin5\hardware.asm" 

"$(OUTDIR)\FIQ.obj": "F:\abc\shibieyuyin5\FIQ.asm" 
	$(AS) $(ASFLAGS) $(INCLUDES) -l "$(OUTDIR)\FIQ.lst" -o "$(OUTDIR)\FIQ.obj" "F:\abc\shibieyuyin5\FIQ.asm" 

"$(OUTDIR)\Resource.obj": "F:\abc\shibieyuyin5\Resource.asm" 
	$(AS) $(ASFLAGS) $(INCLUDES) -l "$(OUTDIR)\Resource.lst" -o "$(OUTDIR)\Resource.obj" "F:\abc\shibieyuyin5\Resource.asm" 

"$(OUTDIR)\main.asm": "F:\abc\shibieyuyin5\main.c" 
	$(CC) $(CFLAGS) -o "$(OUTDIR)/main.asm" "F:/abc/shibieyuyin5/main.c" 

"$(OUTDIR)\main.obj": "$(OUTDIR)\main.asm"
	$(AS) $(CASFLAGS) $(INCLUDES) -l "$(OUTDIR)\main.lst" -o "$(OUTDIR)\main.obj" "$(OUTDIR)\main.asm" 


.SUFFIXES : .c .asm .obj .s37 .tsk .res

all :	 "$(OUTDIR)" $(BINFILE)

"$(OUTDIR)" :
	if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

$(BINFILE) : $(OBJFILES) 
	$(LD) $(BINTYPE) $(ARYFILE) $(BINFILE) $(LDFLAGS) $(BODY) $(EXTRAFLAGS)

compile :	 $(OBJFILES)

clean :
	$(RM) "$(OUTDIR)\S12_24K.res" 
	$(RM) "$(OUTDIR)\1_48k.res" 
	$(RM) "$(OUTDIR)\2_48k.res" 
	$(RM) "$(OUTDIR)\3_48k.res" 
	$(RM) "$(OUTDIR)\4_48k.res" 
	$(RM) "$(OUTDIR)\5_48k.res" 
	$(RM) "$(OUTDIR)\6_48k.res" 
	$(RM) "$(OUTDIR)\7_48k.res" 
	$(RM) "$(OUTDIR)\18_48k.res" 
	$(RM) "$(OUTDIR)\10_48k.res" 
	$(RM) "$(OUTDIR)\11_48k.res" 
	$(RM) "$(OUTDIR)\12_48k.res" 
	$(RM) "$(OUTDIR)\17_48k.res" 
	$(RM) "$(OUTDIR)\16_48k.res" 
	$(RM) "$(OUTDIR)\15_48k.res" 
	$(RM) "$(OUTDIR)\InitIO.obj" 
	$(RM) "$(OUTDIR)\InitIO.lst" 
	$(RM) "$(OUTDIR)\hardware.obj" 
	$(RM) "$(OUTDIR)\hardware.lst" 
	$(RM) "$(OUTDIR)\FIQ.obj" 
	$(RM) "$(OUTDIR)\FIQ.lst" 
	$(RM) "$(OUTDIR)\Resource.obj" 
	$(RM) "$(OUTDIR)\Resource.lst" 
	$(RM) "$(OUTDIR)\main.obj" 
	$(RM) "$(OUTDIR)\main.lst" 
	$(RM) "$(OUTDIR)\main.asm" 
	$(RM) $(BINFILE) $(SBMFILE) 

.c.asm:
	$(CC) $(CFLAGS) $(INCLUDES) -o "$(OUTDIR)/$@" $<

.asm.obj:
	$(AS) $(ASFLAGS) $(INCLUDES) -o "$(OUTDIR)/$@" $<

