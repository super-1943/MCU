#####################################################################
#																	 
#	Created by u'nSP IDE		16:25:44	11/09/08
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

INCLUDES	= -I"F:/abc/kkk/yejing"

BODY	= -body SPCE060A_061A -bfile "d:\Program Files\Sunplus\unSP IDE Common\Body\SPCE060A_061A.cpt"

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
	"$(OUTDIR)\Resource.obj" \
	"$(OUTDIR)\23.obj" 

"$(OUTDIR)\Resource.obj": "F:\abc\kkk\yejing\Resource.asm" 
	$(AS) $(ASFLAGS) $(INCLUDES) -l "$(OUTDIR)\Resource.lst" -o "$(OUTDIR)\Resource.obj" "F:\abc\kkk\yejing\Resource.asm" 

"$(OUTDIR)\23.asm": "F:\abc\kkk\yejing\23.c" ".\spce061a.h" 
	$(CC) $(CFLAGS) -o "$(OUTDIR)/23.asm" "F:/abc/kkk/yejing/23.c" 

"$(OUTDIR)\23.obj": "$(OUTDIR)\23.asm"
	$(AS) $(CASFLAGS) $(INCLUDES) -l "$(OUTDIR)\23.lst" -o "$(OUTDIR)\23.obj" "$(OUTDIR)\23.asm" 


.SUFFIXES : .c .asm .obj .s37 .tsk .res

all :	 "$(OUTDIR)" $(BINFILE)

"$(OUTDIR)" :
	if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

$(BINFILE) : $(OBJFILES) 
	$(LD) $(BINTYPE) $(ARYFILE) $(BINFILE) $(LDFLAGS) $(BODY) $(EXTRAFLAGS)

compile :	 $(OBJFILES)

clean :
	$(RM) "$(OUTDIR)\Resource.obj" 
	$(RM) "$(OUTDIR)\Resource.lst" 
	$(RM) "$(OUTDIR)\23.obj" 
	$(RM) "$(OUTDIR)\23.lst" 
	$(RM) "$(OUTDIR)\23.asm" 
	$(RM) $(BINFILE) $(SBMFILE) 

.c.asm:
	$(CC) $(CFLAGS) $(INCLUDES) -o "$(OUTDIR)/$@" $<

.asm.obj:
	$(AS) $(ASFLAGS) $(INCLUDES) -o "$(OUTDIR)/$@" $<

