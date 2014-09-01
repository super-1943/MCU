#####################################################################
#																	 
#	Created by u'nSP IDE		13:36:07	10/01/09
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

INCLUDES	= -I"F:/myproject/lingyang/123"

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
	"$(OUTDIR)\s1_24k.res" \
	"$(OUTDIR)\Resource.obj" \
	"$(OUTDIR)\123.obj" \
	"$(OUTDIR)\hardware.obj" \
	"$(OUTDIR)\isr.obj" 

"$(OUTDIR)\s1_24k.res": "F:\myproject\lingyang\123\s1.24k"
	$(RESC) "F:\myproject\lingyang\123\s1.24k" "$(OUTDIR)\s1_24k.res" RES_S1_24K 

"$(OUTDIR)\Resource.obj": "F:\myproject\lingyang\123\Resource.asm" 
	$(AS) $(ASFLAGS) $(INCLUDES) -l "$(OUTDIR)\Resource.lst" -o "$(OUTDIR)\Resource.obj" "F:\myproject\lingyang\123\Resource.asm" 

"$(OUTDIR)\123.asm": "F:\myproject\lingyang\123\123.c" ".\spce061a.h" 
	$(CC) $(CFLAGS) -o "$(OUTDIR)/123.asm" "F:/myproject/lingyang/123/123.c" 

"$(OUTDIR)\123.obj": "$(OUTDIR)\123.asm"
	$(AS) $(CASFLAGS) $(INCLUDES) -l "$(OUTDIR)\123.lst" -o "$(OUTDIR)\123.obj" "$(OUTDIR)\123.asm" 

"$(OUTDIR)\hardware.obj": "F:\myproject\lingyang\123\hardware.asm" 
	$(AS) $(ASFLAGS) $(INCLUDES) -l "$(OUTDIR)\hardware.lst" -o "$(OUTDIR)\hardware.obj" "F:\myproject\lingyang\123\hardware.asm" 

"$(OUTDIR)\isr.obj": "F:\myproject\lingyang\123\isr.asm" 
	$(AS) $(ASFLAGS) $(INCLUDES) -l "$(OUTDIR)\isr.lst" -o "$(OUTDIR)\isr.obj" "F:\myproject\lingyang\123\isr.asm" 


.SUFFIXES : .c .asm .obj .s37 .tsk .res

all :	 "$(OUTDIR)" $(BINFILE)

"$(OUTDIR)" :
	if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

$(BINFILE) : $(OBJFILES) 
	$(LD) $(BINTYPE) $(ARYFILE) $(BINFILE) $(LDFLAGS) $(BODY) $(EXTRAFLAGS)

compile :	 $(OBJFILES)

clean :
	$(RM) "$(OUTDIR)\s1_24k.res" 
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

