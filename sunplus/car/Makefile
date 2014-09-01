#####################################################################
#																	 
#	Created by u'nSP IDE		13:07:19	08/30/08
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

INCLUDES	= -I"F:/abc/car" -I"F:/abc/aa/aa"

BODY	= -body SPCE060A_061A -bfile "d:\Program Files\Sunplus\unSP IDE Common\Body\SPCE060A_061A.cpt"

BINFILE	= "$(OUTDIR)\car.S37"

ARYFILE	= "$(OUTDIR)\car.ary"

SBMFILE	= "$(OUTDIR)\car.sbm"

OPT	= -S -gstabs -Wall -mglobal-var-iram

ASFLAGS	= -t2 -d

CASFLAGS	= -t2 

CFLAGS	= $(OPT) -B$(APPDIR)\ $(INCLUDES) 

BINTYPE	= -as

LDFLAGS	= 

EXTRAFLAGS	= 


OBJFILES	= \
	"$(OUTDIR)\Resource.obj" \
	"$(OUTDIR)\car.obj" 

"$(OUTDIR)\Resource.obj": "F:\À˚»À\yfhe\¡Ë—Ù\car\Resource.asm" 
	$(AS) $(ASFLAGS) $(INCLUDES) -l "$(OUTDIR)\Resource.lst" -o "$(OUTDIR)\Resource.obj" "F:\abc\car\Resource.asm" 

"$(OUTDIR)\car.asm": "F:\abc\car\car.c" 
	$(CC) $(CFLAGS) -o "$(OUTDIR)/car.asm" "F:/abc/car/car.c" 

"$(OUTDIR)\car.obj": "$(OUTDIR)\car.asm"
	$(AS) $(CASFLAGS) $(INCLUDES) -l "$(OUTDIR)\car.lst" -o "$(OUTDIR)\car.obj" "$(OUTDIR)\car.asm" 


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
	$(RM) "$(OUTDIR)\car.obj" 
	$(RM) "$(OUTDIR)\car.lst" 
	$(RM) "$(OUTDIR)\car.asm" 
	$(RM) $(BINFILE) $(SBMFILE) 

.c.asm:
	$(CC) $(CFLAGS) $(INCLUDES) -o "$(OUTDIR)/$@" $<

.asm.obj:
	$(AS) $(ASFLAGS) $(INCLUDES) -o "$(OUTDIR)/$@" $<

