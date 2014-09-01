#####################################################################
#																	 
#	Created by u'nSP IDE		20:03:45	11/07/08
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

INCLUDES	= -I"C:/Documents and Settings/a/My Documents/1602"

BODY	= -body SPCE060A_061A -bfile "D:\Program Files\Sunplus\unSP IDE Common\Body\SPCE060A_061A.cpt"

BINFILE	= "$(OUTDIR)\1602.S37"

ARYFILE	= "$(OUTDIR)\1602.ary"

SBMFILE	= "$(OUTDIR)\1602.sbm"

OPT	= -S -gstabs -Wall -mglobal-var-iram

ASFLAGS	= -t2 -d

CASFLAGS	= -t2 

CFLAGS	= $(OPT) -B$(APPDIR)\ $(INCLUDES) 

BINTYPE	= -as

LDFLAGS	= 

EXTRAFLAGS	= 


OBJFILES	= \
	"$(OUTDIR)\Resource.obj" \
	"$(OUTDIR)\1602.obj" 

"$(OUTDIR)\Resource.obj": "C:\Documents and Settings\a\My Documents\1602\Resource.asm" 
	$(AS) $(ASFLAGS) $(INCLUDES) -l "$(OUTDIR)\Resource.lst" -o "$(OUTDIR)\Resource.obj" "C:\Documents and Settings\a\My Documents\1602\Resource.asm" 

"$(OUTDIR)\1602.asm": "C:\Documents and Settings\a\My Documents\1602\1602.c" ".\spce061a.h" 
	$(CC) $(CFLAGS) -o "$(OUTDIR)/1602.asm" "C:/Documents and Settings/a/My Documents/1602/1602.c" 

"$(OUTDIR)\1602.obj": "$(OUTDIR)\1602.asm"
	$(AS) $(CASFLAGS) $(INCLUDES) -l "$(OUTDIR)\1602.lst" -o "$(OUTDIR)\1602.obj" "$(OUTDIR)\1602.asm" 


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
	$(RM) "$(OUTDIR)\1602.obj" 
	$(RM) "$(OUTDIR)\1602.lst" 
	$(RM) "$(OUTDIR)\1602.asm" 
	$(RM) $(BINFILE) $(SBMFILE) 

.c.asm:
	$(CC) $(CFLAGS) $(INCLUDES) -o "$(OUTDIR)/$@" $<

.asm.obj:
	$(AS) $(ASFLAGS) $(INCLUDES) -o "$(OUTDIR)/$@" $<

