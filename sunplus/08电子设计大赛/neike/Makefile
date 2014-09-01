#####################################################################
#																	 
#	Created by u'nSP IDE		12:41:42	11/12/08
#
#####################################################################




APPDIR	= D:\PROGRA~1\SunPlus\UNSPID~1.0

OUTDIR	= .\Debug

CC	= $(APPDIR)\gcc

AS	= $(APPDIR)\xasm16

LD	= $(APPDIR)\xlink16

AR	= $(APPDIR)\xLib16

RESC	= $(APPDIR)\resc

RM	= $(APPDIR)\rm -f

INCLUDES	= -I"G:/neike"

BODY	= -body SPCE060A_061A -bfile "D:\Program Files\Sunplus\unSP IDE Common\Body\SPCE060A_061A.cpt"

BINFILE	= "$(OUTDIR)\neike.S37"

ARYFILE	= "$(OUTDIR)\neike.ary"

SBMFILE	= "$(OUTDIR)\neike.sbm"

OPT	= -S -gstabs -Wall -mglobal-var-iram

ASFLAGS	= -t2 -d

CASFLAGS	= -t2 

CFLAGS	= $(OPT) -B$(APPDIR)\ $(INCLUDES) 

BINTYPE	= -as

LDFLAGS	= 

EXTRAFLAGS	= 


OBJFILES	= \
	"$(OUTDIR)\Resource.obj" \
	"$(OUTDIR)\ddd.obj" 

"$(OUTDIR)\Resource.obj": "G:\neike\Resource.asm" 
	$(AS) $(ASFLAGS) $(INCLUDES) -l "$(OUTDIR)\Resource.lst" -o "$(OUTDIR)\Resource.obj" "G:\neike\Resource.asm" 

"$(OUTDIR)\ddd.asm": "G:\neike\ddd.c" ".\spce061a.h" 
	$(CC) $(CFLAGS) -o "$(OUTDIR)/ddd.asm" "G:/neike/ddd.c" 

"$(OUTDIR)\ddd.obj": "$(OUTDIR)\ddd.asm"
	$(AS) $(CASFLAGS) $(INCLUDES) -l "$(OUTDIR)\ddd.lst" -o "$(OUTDIR)\ddd.obj" "$(OUTDIR)\ddd.asm" 


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
	$(RM) "$(OUTDIR)\ddd.obj" 
	$(RM) "$(OUTDIR)\ddd.lst" 
	$(RM) "$(OUTDIR)\ddd.asm" 
	$(RM) $(BINFILE) $(SBMFILE) 

.c.asm:
	$(CC) $(CFLAGS) $(INCLUDES) -o "$(OUTDIR)/$@" $<

.asm.obj:
	$(AS) $(ASFLAGS) $(INCLUDES) -o "$(OUTDIR)/$@" $<

