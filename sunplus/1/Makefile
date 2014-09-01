#####################################################################
#																	 
#	Created by u'nSP IDE		15:07:22	01/17/09
#
#####################################################################




APPDIR	= C:\Elecs\Sunplus\UNSPID~1.0

OUTDIR	= .\Debug

CC	= $(APPDIR)\gcc

AS	= $(APPDIR)\xasm16

LD	= $(APPDIR)\xlink16

AR	= $(APPDIR)\xLib16

RESC	= $(APPDIR)\resc

RM	= $(APPDIR)\rm -f

INCLUDES	= -I"C:/Documents and Settings/zhaoyongke/My Documents/myproject/Sunplus/1"

BODY	= -body SPCE060A_061A -bfile "C:\Elecs\Sunplus\Commen\Body\SPCE060A_061A.cpt"

BINFILE	= "$(OUTDIR)\1.S37"

ARYFILE	= "$(OUTDIR)\1.ary"

SBMFILE	= "$(OUTDIR)\1.sbm"

OPT	= -S -gstabs -Wall -mglobal-var-iram

ASFLAGS	= -t2 -d

CASFLAGS	= -t2 

CFLAGS	= $(OPT) -B$(APPDIR)\ $(INCLUDES) 

BINTYPE	= -as

LDFLAGS	= 

EXTRAFLAGS	= 


OBJFILES	= \
	"$(OUTDIR)\Resource.obj" \
	"$(OUTDIR)\1.obj" 

"$(OUTDIR)\Resource.obj": "C:\Documents and Settings\zhaoyongke\My Documents\myproject\Sunplus\1\Resource.asm" 
	$(AS) $(ASFLAGS) $(INCLUDES) -l "$(OUTDIR)\Resource.lst" -o "$(OUTDIR)\Resource.obj" "C:\Documents and Settings\zhaoyongke\My Documents\myproject\Sunplus\1\Resource.asm" 

"$(OUTDIR)\1.asm": "C:\Documents and Settings\zhaoyongke\My Documents\myproject\Sunplus\1\1.c" ".\spce061a.h" 
	$(CC) $(CFLAGS) -o "$(OUTDIR)/1.asm" "C:/Documents and Settings/zhaoyongke/My Documents/myproject/Sunplus/1/1.c" 

"$(OUTDIR)\1.obj": "$(OUTDIR)\1.asm"
	$(AS) $(CASFLAGS) $(INCLUDES) -l "$(OUTDIR)\1.lst" -o "$(OUTDIR)\1.obj" "$(OUTDIR)\1.asm" 


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
	$(RM) "$(OUTDIR)\1.obj" 
	$(RM) "$(OUTDIR)\1.lst" 
	$(RM) "$(OUTDIR)\1.asm" 
	$(RM) $(BINFILE) $(SBMFILE) 

.c.asm:
	$(CC) $(CFLAGS) $(INCLUDES) -o "$(OUTDIR)/$@" $<

.asm.obj:
	$(AS) $(ASFLAGS) $(INCLUDES) -o "$(OUTDIR)/$@" $<

