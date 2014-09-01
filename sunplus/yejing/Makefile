#####################################################################
#																	 
#	Created by u'nSP IDE		21:23:14	10/01/09
#
#####################################################################




APPDIR	= C:\PROGRA~1\Sunplus\UNSPID~1.0

OUTDIR	= .\Debug

CC	= $(APPDIR)\gcc

AS	= $(APPDIR)\xasm16

LD	= $(APPDIR)\xlink16

AR	= $(APPDIR)\xLib16

RESC	= $(APPDIR)\resc

RM	= $(APPDIR)\rm -f

INCLUDES	= -I"E:/program/sun/yejing"

BODY	= -body SPCE060A_061A -bfile "C:\Program Files\Sunplus\unSP IDE Common\Body\SPCE060A_061A.cpt"

BINFILE	= "$(OUTDIR)\yejing.S37"

ARYFILE	= "$(OUTDIR)\yejing.ary"

SBMFILE	= "$(OUTDIR)\yejing.sbm"

OPT	= -S -gstabs -Wall -mglobal-var-iram

ASFLAGS	= -t2 -d

CASFLAGS	= -t2 

CFLAGS	= $(OPT) -B$(APPDIR)\ $(INCLUDES) 

BINTYPE	= -as

LDFLAGS	= 

EXTRAFLAGS	= 


OBJFILES	= \
	"$(OUTDIR)\who_16k.res" \
	"$(OUTDIR)\comein_16k.res" \
	"$(OUTDIR)\sorry_16k.res" \
	"$(OUTDIR)\Resource.obj" \
	"$(OUTDIR)\main.obj" \
	"$(OUTDIR)\ziku12864.obj" \
	"$(OUTDIR)\hardware.obj" \
	"$(OUTDIR)\isr.obj" 

"$(OUTDIR)\who_16k.res": "E:\program\sun\who.16k"
	$(RESC) "E:\program\sun\who.16k" "$(OUTDIR)\who_16k.res" RES_WHO_16K 

"$(OUTDIR)\comein_16k.res": "E:\program\sun\comein.16k"
	$(RESC) "E:\program\sun\comein.16k" "$(OUTDIR)\comein_16k.res" RES_COMEIN_16K 

"$(OUTDIR)\sorry_16k.res": "E:\program\sun\sorry.16k"
	$(RESC) "E:\program\sun\sorry.16k" "$(OUTDIR)\sorry_16k.res" RES_SORRY_16K 

"$(OUTDIR)\Resource.obj": "E:\program\sun\yejing\Resource.asm" 
	$(AS) $(ASFLAGS) $(INCLUDES) -l "$(OUTDIR)\Resource.lst" -o "$(OUTDIR)\Resource.obj" "E:\program\sun\yejing\Resource.asm" 

"$(OUTDIR)\main.asm": "E:\program\sun\yejing\main.c" ".\spce061a.h" ".\ziku12864.h" ".\a2000.h" 
	$(CC) $(CFLAGS) -o "$(OUTDIR)/main.asm" "E:/program/sun/yejing/main.c" 

"$(OUTDIR)\main.obj": "$(OUTDIR)\main.asm"
	$(AS) $(CASFLAGS) $(INCLUDES) -l "$(OUTDIR)\main.lst" -o "$(OUTDIR)\main.obj" "$(OUTDIR)\main.asm" 

"$(OUTDIR)\ziku12864.asm": "E:\program\sun\yejing\ziku12864.c" ".\ziku12864.h" ".\spce061a.h" 
	$(CC) $(CFLAGS) -o "$(OUTDIR)/ziku12864.asm" "E:/program/sun/yejing/ziku12864.c" 

"$(OUTDIR)\ziku12864.obj": "$(OUTDIR)\ziku12864.asm"
	$(AS) $(CASFLAGS) $(INCLUDES) -l "$(OUTDIR)\ziku12864.lst" -o "$(OUTDIR)\ziku12864.obj" "$(OUTDIR)\ziku12864.asm" 

"$(OUTDIR)\hardware.obj": "E:\program\sun\yejing\hardware.asm" 
	$(AS) $(ASFLAGS) $(INCLUDES) -l "$(OUTDIR)\hardware.lst" -o "$(OUTDIR)\hardware.obj" "E:\program\sun\yejing\hardware.asm" 

"$(OUTDIR)\isr.obj": "E:\program\sun\yejing\isr.asm" ".\hardware.inc" 
	$(AS) $(ASFLAGS) $(INCLUDES) -l "$(OUTDIR)\isr.lst" -o "$(OUTDIR)\isr.obj" "E:\program\sun\yejing\isr.asm" 


.SUFFIXES : .c .asm .obj .s37 .tsk .res

all :	 "$(OUTDIR)" $(BINFILE)

"$(OUTDIR)" :
	if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

$(BINFILE) : $(OBJFILES) 
	$(LD) $(BINTYPE) $(ARYFILE) $(BINFILE) $(LDFLAGS) $(BODY) $(EXTRAFLAGS)

compile :	 $(OBJFILES)

clean :
	$(RM) "$(OUTDIR)\who_16k.res" 
	$(RM) "$(OUTDIR)\comein_16k.res" 
	$(RM) "$(OUTDIR)\sorry_16k.res" 
	$(RM) "$(OUTDIR)\Resource.obj" 
	$(RM) "$(OUTDIR)\Resource.lst" 
	$(RM) "$(OUTDIR)\main.obj" 
	$(RM) "$(OUTDIR)\main.lst" 
	$(RM) "$(OUTDIR)\main.asm" 
	$(RM) "$(OUTDIR)\ziku12864.obj" 
	$(RM) "$(OUTDIR)\ziku12864.lst" 
	$(RM) "$(OUTDIR)\ziku12864.asm" 
	$(RM) "$(OUTDIR)\hardware.obj" 
	$(RM) "$(OUTDIR)\hardware.lst" 
	$(RM) "$(OUTDIR)\isr.obj" 
	$(RM) "$(OUTDIR)\isr.lst" 
	$(RM) $(BINFILE) $(SBMFILE) 

.c.asm:
	$(CC) $(CFLAGS) $(INCLUDES) -o "$(OUTDIR)/$@" $<

.asm.obj:
	$(AS) $(ASFLAGS) $(INCLUDES) -o "$(OUTDIR)/$@" $<

