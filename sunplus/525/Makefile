#####################################################################
#																	 
#	Created by u'nSP IDE		14:44:00	11/06/08
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

INCLUDES	= -I"D:/个人工程文件夹/kkk/lingyang/525"

BODY	= -body SPCE060A_061A -bfile "d:\Program Files\Sunplus\unSP IDE Common\Body\SPCE060A_061A.cpt"

BINFILE	= "$(OUTDIR)\525.S37"

ARYFILE	= "$(OUTDIR)\525.ary"

SBMFILE	= "$(OUTDIR)\525.sbm"

OPT	= -S -gstabs -Wall -mglobal-var-iram

ASFLAGS	= -t2 -d

CASFLAGS	= -t2 

CFLAGS	= $(OPT) -B$(APPDIR)\ $(INCLUDES) 

BINTYPE	= -as

LDFLAGS	= 

EXTRAFLAGS	= 


OBJFILES	= \
	"$(OUTDIR)\Resource.obj" \
	"$(OUTDIR)\my525.obj" 

"$(OUTDIR)\Resource.obj": "D:\个人工程文件夹\kkk\lingyang\525\Resource.asm" 
	$(AS) $(ASFLAGS) $(INCLUDES) -l "$(OUTDIR)\Resource.lst" -o "$(OUTDIR)\Resource.obj" "D:\个人工程文件夹\kkk\lingyang\525\Resource.asm" 

"$(OUTDIR)\my525.asm": "D:\个人工程文件夹\kkk\lingyang\525\my525.c" ".\spce061a.h" 
	$(CC) $(CFLAGS) -o "$(OUTDIR)/my525.asm" "D:/个人工程文件夹/kkk/lingyang/525/my525.c" 

"$(OUTDIR)\my525.obj": "$(OUTDIR)\my525.asm"
	$(AS) $(CASFLAGS) $(INCLUDES) -l "$(OUTDIR)\my525.lst" -o "$(OUTDIR)\my525.obj" "$(OUTDIR)\my525.asm" 


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
	$(RM) "$(OUTDIR)\my525.obj" 
	$(RM) "$(OUTDIR)\my525.lst" 
	$(RM) "$(OUTDIR)\my525.asm" 
	$(RM) $(BINFILE) $(SBMFILE) 

.c.asm:
	$(CC) $(CFLAGS) $(INCLUDES) -o "$(OUTDIR)/$@" $<

.asm.obj:
	$(AS) $(ASFLAGS) $(INCLUDES) -o "$(OUTDIR)/$@" $<

