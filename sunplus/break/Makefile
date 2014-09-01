#####################################################################
#																	 
#	Created by u'nSP IDE		13:33:11	02/23/09
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

INCLUDES	= -I"D:/My Documents/MyProject/sunplus/break"

BODY	= -body SPCE060A_061A -bfile "d:\Program Files\Sunplus\unSP IDE Common\Body\SPCE060A_061A.cpt"

BINFILE	= "$(OUTDIR)\break.S37"

ARYFILE	= "$(OUTDIR)\break.ary"

SBMFILE	= "$(OUTDIR)\break.sbm"

OPT	= -S -gstabs -Wall -mglobal-var-iram

ASFLAGS	= -t2 -d

CASFLAGS	= -t2 

CFLAGS	= $(OPT) -B$(APPDIR)\ $(INCLUDES) 

BINTYPE	= -as

LDFLAGS	= 

EXTRAFLAGS	= 


OBJFILES	= \
	"$(OUTDIR)\Resource.obj" \
	"$(OUTDIR)\main.obj" \
	"$(OUTDIR)\int.obj" 

"$(OUTDIR)\Resource.obj": "D:\My Documents\MyProject\sunplus\break\Resource.asm" 
	$(AS) $(ASFLAGS) $(INCLUDES) -l "$(OUTDIR)\Resource.lst" -o "$(OUTDIR)\Resource.obj" "D:\My Documents\MyProject\sunplus\break\Resource.asm" 

"$(OUTDIR)\main.asm": "D:\My Documents\MyProject\sunplus\break\main.c" ".\spce061a.h" 
	$(CC) $(CFLAGS) -o "$(OUTDIR)/main.asm" "D:/My Documents/MyProject/sunplus/break/main.c" 

"$(OUTDIR)\main.obj": "$(OUTDIR)\main.asm"
	$(AS) $(CASFLAGS) $(INCLUDES) -l "$(OUTDIR)\main.lst" -o "$(OUTDIR)\main.obj" "$(OUTDIR)\main.asm" 

"$(OUTDIR)\int.obj": "D:\My Documents\MyProject\sunplus\break\int.asm" 
	$(AS) $(ASFLAGS) $(INCLUDES) -l "$(OUTDIR)\int.lst" -o "$(OUTDIR)\int.obj" "D:\My Documents\MyProject\sunplus\break\int.asm" 


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
	$(RM) "$(OUTDIR)\main.obj" 
	$(RM) "$(OUTDIR)\main.lst" 
	$(RM) "$(OUTDIR)\main.asm" 
	$(RM) "$(OUTDIR)\int.obj" 
	$(RM) "$(OUTDIR)\int.lst" 
	$(RM) $(BINFILE) $(SBMFILE) 

.c.asm:
	$(CC) $(CFLAGS) $(INCLUDES) -o "$(OUTDIR)/$@" $<

.asm.obj:
	$(AS) $(ASFLAGS) $(INCLUDES) -o "$(OUTDIR)/$@" $<

