#####################################################################
#																	 
#	Created by u'nSP IDE		15:33:17	02/23/09
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

INCLUDES	= -I"D:/hellosystem"

BODY	= -body SPCE060A_061A -bfile "C:\Program Files\Sunplus\unSP IDE Common\Body\SPCE060A_061A.cpt"

BINFILE	= "$(OUTDIR)\hellosystem.S37"

ARYFILE	= "$(OUTDIR)\hellosystem.ary"

SBMFILE	= "$(OUTDIR)\hellosystem.sbm"

OPT	= -S -gstabs -Wall -mglobal-var-iram

ASFLAGS	= -t2 -d

CASFLAGS	= -t2 

CFLAGS	= $(OPT) -B$(APPDIR)\ $(INCLUDES) 

BINTYPE	= -as

LDFLAGS	= 

EXTRAFLAGS	= 


OBJFILES	= \
	"$(OUTDIR)\Resource.obj" \
	"$(OUTDIR)\nzj.obj" \
	"$(OUTDIR)\jk.obj" 

"$(OUTDIR)\Resource.obj": "D:\hellosystem\Resource.asm" 
	$(AS) $(ASFLAGS) $(INCLUDES) -l "$(OUTDIR)\Resource.lst" -o "$(OUTDIR)\Resource.obj" "D:\hellosystem\Resource.asm" 

"$(OUTDIR)\nzj.asm": "D:\hellosystem\nzj.c" ".\SPCE061A.H" 
	$(CC) $(CFLAGS) -o "$(OUTDIR)/nzj.asm" "D:/hellosystem/nzj.c" 

"$(OUTDIR)\nzj.obj": "$(OUTDIR)\nzj.asm"
	$(AS) $(CASFLAGS) $(INCLUDES) -l "$(OUTDIR)\nzj.lst" -o "$(OUTDIR)\nzj.obj" "$(OUTDIR)\nzj.asm" 

"$(OUTDIR)\jk.obj": "D:\hellosystem\jk.asm" 
	$(AS) $(ASFLAGS) $(INCLUDES) -l "$(OUTDIR)\jk.lst" -o "$(OUTDIR)\jk.obj" "D:\hellosystem\jk.asm" 


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
	$(RM) "$(OUTDIR)\nzj.obj" 
	$(RM) "$(OUTDIR)\nzj.lst" 
	$(RM) "$(OUTDIR)\nzj.asm" 
	$(RM) "$(OUTDIR)\jk.obj" 
	$(RM) "$(OUTDIR)\jk.lst" 
	$(RM) $(BINFILE) $(SBMFILE) 

.c.asm:
	$(CC) $(CFLAGS) $(INCLUDES) -o "$(OUTDIR)/$@" $<

.asm.obj:
	$(AS) $(ASFLAGS) $(INCLUDES) -o "$(OUTDIR)/$@" $<

