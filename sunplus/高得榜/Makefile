#####################################################################
#																	 
#	Created by u'nSP IDE		05:47:25	11/15/08
#
#####################################################################




APPDIR	= D:\PROGRA~1\Sunplus

OUTDIR	= .\Debug

CC	= $(APPDIR)\gcc

AS	= $(APPDIR)\xasm16

LD	= $(APPDIR)\xlink16

AR	= $(APPDIR)\xLib16

RESC	= $(APPDIR)\resc

RM	= $(APPDIR)\rm -f

INCLUDES	= -I"F:/gao/dingshiqi"

BODY	= -body SPCE060A_061A -bfile "D:\Program Files\Sunplus\Body\SPCE060A_061A.cpt"

BINFILE	= "$(OUTDIR)\diyici.S37"

ARYFILE	= "$(OUTDIR)\diyici.ary"

SBMFILE	= "$(OUTDIR)\diyici.sbm"

OPT	= -S -gstabs -Wall -mglobal-var-iram

ASFLAGS	= -t2 -d

CASFLAGS	= -t2 

CFLAGS	= $(OPT) -B$(APPDIR)\ $(INCLUDES) 

BINTYPE	= -as

LDFLAGS	= 

EXTRAFLAGS	= 


OBJFILES	= \
	"$(OUTDIR)\Resource.obj" \
	"$(OUTDIR)\mian.obj" 

"$(OUTDIR)\Resource.obj": "F:\gao\dingshiqi\Resource.asm" 
	$(AS) $(ASFLAGS) $(INCLUDES) -l "$(OUTDIR)\Resource.lst" -o "$(OUTDIR)\Resource.obj" "F:\gao\dingshiqi\Resource.asm" 

"$(OUTDIR)\mian.asm": "F:\gao\dingshiqi\mian.c" ".\spce061a.h" ".\my7219.h" 
	$(CC) $(CFLAGS) -o "$(OUTDIR)/mian.asm" "F:/gao/dingshiqi/mian.c" 

"$(OUTDIR)\mian.obj": "$(OUTDIR)\mian.asm"
	$(AS) $(CASFLAGS) $(INCLUDES) -l "$(OUTDIR)\mian.lst" -o "$(OUTDIR)\mian.obj" "$(OUTDIR)\mian.asm" 


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
	$(RM) "$(OUTDIR)\mian.obj" 
	$(RM) "$(OUTDIR)\mian.lst" 
	$(RM) "$(OUTDIR)\mian.asm" 
	$(RM) $(BINFILE) $(SBMFILE) 

.c.asm:
	$(CC) $(CFLAGS) $(INCLUDES) -o "$(OUTDIR)/$@" $<

.asm.obj:
	$(AS) $(ASFLAGS) $(INCLUDES) -o "$(OUTDIR)/$@" $<

