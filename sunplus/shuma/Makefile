#####################################################################
#																	 
#	Created by u'nSP IDE		15:51:16	10/28/08
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

INCLUDES	= -I"C:/Documents and Settings/zhangzhao.YSU-13AE14284FC/桌面/shuma"

BODY	= -body SPCE060A_061A -bfile "d:\Program Files\Sunplus\unSP IDE Common\Body\SPCE060A_061A.cpt"

BINFILE	= "$(OUTDIR)\shuma.S37"

ARYFILE	= "$(OUTDIR)\shuma.ary"

SBMFILE	= "$(OUTDIR)\shuma.sbm"

OPT	= -S -gstabs -Wall -mglobal-var-iram

ASFLAGS	= -t2 -d

CASFLAGS	= -t2 

CFLAGS	= $(OPT) -B$(APPDIR)\ $(INCLUDES) 

BINTYPE	= -as

LDFLAGS	= 

EXTRAFLAGS	= 


OBJFILES	= \
	"$(OUTDIR)\Resource.obj" \
	"$(OUTDIR)\led.obj" 

"$(OUTDIR)\Resource.obj": "C:\Documents and Settings\zhangzhao.YSU-13AE14284FC\桌面\shuma\Resource.asm" 
	$(AS) $(ASFLAGS) $(INCLUDES) -l "$(OUTDIR)\Resource.lst" -o "$(OUTDIR)\Resource.obj" "C:\Documents and Settings\zhangzhao.YSU-13AE14284FC\桌面\shuma\Resource.asm" 

"$(OUTDIR)\led.asm": "C:\Documents and Settings\zhangzhao.YSU-13AE14284FC\桌面\shuma\led.c" ".\spce061a.h" 
	$(CC) $(CFLAGS) -o "$(OUTDIR)/led.asm" "C:/Documents and Settings/zhangzhao.YSU-13AE14284FC/桌面/shuma/led.c" 

"$(OUTDIR)\led.obj": "$(OUTDIR)\led.asm"
	$(AS) $(CASFLAGS) $(INCLUDES) -l "$(OUTDIR)\led.lst" -o "$(OUTDIR)\led.obj" "$(OUTDIR)\led.asm" 


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
	$(RM) "$(OUTDIR)\led.obj" 
	$(RM) "$(OUTDIR)\led.lst" 
	$(RM) "$(OUTDIR)\led.asm" 
	$(RM) $(BINFILE) $(SBMFILE) 

.c.asm:
	$(CC) $(CFLAGS) $(INCLUDES) -o "$(OUTDIR)/$@" $<

.asm.obj:
	$(AS) $(ASFLAGS) $(INCLUDES) -o "$(OUTDIR)/$@" $<

