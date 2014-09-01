#####################################################################
#																	 
#	Created by u'nSP IDE		14:29:56	10/03/09
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

INCLUDES	= -I"E:/AllProject/sunplus/mysound"

BODY	= -body SPCE060A_061A -bfile "C:\Program Files\Sunplus\unSP IDE Common\Body\SPCE060A_061A.cpt"

BINFILE	= "$(OUTDIR)\123.S37"

ARYFILE	= "$(OUTDIR)\123.ary"

SBMFILE	= "$(OUTDIR)\123.sbm"

OPT	= -S -gstabs -Wall -mglobal-var-iram

ASFLAGS	= -t2 -d

CASFLAGS	= -t2 

CFLAGS	= $(OPT) -B$(APPDIR)\ $(INCLUDES) 

BINTYPE	= -as

LDFLAGS	= 

EXTRAFLAGS	= 


OBJFILES	= \
	"$(OUTDIR)\2_16k.res" \
	"$(OUTDIR)\Resource.obj" \
	"$(OUTDIR)\123.obj" \
	"$(OUTDIR)\hardware.obj" \
	"$(OUTDIR)\isr.obj" 

"$(OUTDIR)\2_16k.res": "E:\AllProject\sunplus\mysound\sn\2.16k"
	$(RESC) "E:\AllProject\sunplus\mysound\sn\2.16k" "$(OUTDIR)\2_16k.res" RES_2_16K 

"$(OUTDIR)\Resource.obj": "E:\AllProject\sunplus\mysound\Resource.asm" 
	$(AS) $(ASFLAGS) $(INCLUDES) -l "$(OUTDIR)\Resource.lst" -o "$(OUTDIR)\Resource.obj" "E:\AllProject\sunplus\mysound\Resource.asm" 

"$(OUTDIR)\123.asm": "E:\AllProject\sunplus\mysound\123.c" ".\spce061a.h" ".\a2000.h" 
	$(CC) $(CFLAGS) -o "$(OUTDIR)/123.asm" "E:/AllProject/sunplus/mysound/123.c" 

"$(OUTDIR)\123.obj": "$(OUTDIR)\123.asm"
	$(AS) $(CASFLAGS) $(INCLUDES) -l "$(OUTDIR)\123.lst" -o "$(OUTDIR)\123.obj" "$(OUTDIR)\123.asm" 

"$(OUTDIR)\hardware.obj": "E:\AllProject\sunplus\mysound\hardware.asm" 
	$(AS) $(ASFLAGS) $(INCLUDES) -l "$(OUTDIR)\hardware.lst" -o "$(OUTDIR)\hardware.obj" "E:\AllProject\sunplus\mysound\hardware.asm" 

"$(OUTDIR)\isr.obj": "E:\AllProject\sunplus\mysound\isr.asm" ".\hardware.inc" 
	$(AS) $(ASFLAGS) $(INCLUDES) -l "$(OUTDIR)\isr.lst" -o "$(OUTDIR)\isr.obj" "E:\AllProject\sunplus\mysound\isr.asm" 


.SUFFIXES : .c .asm .obj .s37 .tsk .res

all :	 "$(OUTDIR)" $(BINFILE)

"$(OUTDIR)" :
	if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

$(BINFILE) : $(OBJFILES) 
	$(LD) $(BINTYPE) $(ARYFILE) $(BINFILE) $(LDFLAGS) $(BODY) $(EXTRAFLAGS)

compile :	 $(OBJFILES)

clean :
	$(RM) "$(OUTDIR)\2_16k.res" 
	$(RM) "$(OUTDIR)\Resource.obj" 
	$(RM) "$(OUTDIR)\Resource.lst" 
	$(RM) "$(OUTDIR)\123.obj" 
	$(RM) "$(OUTDIR)\123.lst" 
	$(RM) "$(OUTDIR)\123.asm" 
	$(RM) "$(OUTDIR)\hardware.obj" 
	$(RM) "$(OUTDIR)\hardware.lst" 
	$(RM) "$(OUTDIR)\isr.obj" 
	$(RM) "$(OUTDIR)\isr.lst" 
	$(RM) $(BINFILE) $(SBMFILE) 

.c.asm:
	$(CC) $(CFLAGS) $(INCLUDES) -o "$(OUTDIR)/$@" $<

.asm.obj:
	$(AS) $(ASFLAGS) $(INCLUDES) -o "$(OUTDIR)/$@" $<

