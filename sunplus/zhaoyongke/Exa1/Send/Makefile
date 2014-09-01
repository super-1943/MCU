#####################################################################
#																	 
#	Created by u'nSP IDE		15:10:00	12/07/06
#
#####################################################################




APPDIR	= C:\PROGRA~1\Sunplus\UNSPID~2.0

OUTDIR	= .\Debug

CC	= $(APPDIR)\gcc

AS	= $(APPDIR)\xasm16

LD	= $(APPDIR)\xlink16

AR	= $(APPDIR)\xLib16

RESC	= $(APPDIR)\resc

RM	= $(APPDIR)\rm -f

INCLUDES	= -I"C:/Documents and Settings/shiju/desktop/Demo Code/Exa1/Send" -I"C:/Program Files/Sunplus/unSP IDE 2.4.0/library/include" -I"C:/Program Files/Sunplus/unSP IDE 2.4.0/library/include/sys"

BODY	= -body SPCE060A_061A -bfile "C:\Program Files\Sunplus\unSP IDE Common\Body\SPCE060A_061A.cpt"

BINFILE	= "$(OUTDIR)\Exa1_Send.S37"

ARYFILE	= "$(OUTDIR)\Exa1_Send.ary"

SBMFILE	= "$(OUTDIR)\Exa1_Send.sbm"

OPT	= -S -gstabs -Wall -mglobal-var-iram

ASFLAGS	= -t2 -d

CASFLAGS	= -t2 -wpop

CFLAGS	= $(OPT) -B$(APPDIR)\ $(INCLUDES) 

BINTYPE	= -as

LDFLAGS	= 

EXTRAFLAGS	= 


OBJFILES	= \
	"$(OUTDIR)\Resource.obj" \
	"$(OUTDIR)\main.obj" \
	"$(OUTDIR)\nRF2401.obj" 

"$(OUTDIR)\Resource.obj": "C:\Documents and Settings\shiju\desktop\Demo Code\Exa1\Send\Resource.asm" 
	$(AS) $(ASFLAGS) $(INCLUDES) -o "$(OUTDIR)\Resource.obj" "C:\Documents and Settings\shiju\desktop\Demo Code\Exa1\Send\Resource.asm" 

"$(OUTDIR)\main.asm": "C:\Documents and Settings\shiju\desktop\Demo Code\Exa1\Send\main.c" 
	$(CC) $(CFLAGS) -o "$(OUTDIR)/main.asm" "C:/Documents and Settings/shiju/desktop/Demo Code/Exa1/Send/main.c" 

"$(OUTDIR)\main.obj": "$(OUTDIR)\main.asm"
	$(AS) $(CASFLAGS) $(INCLUDES) -o "$(OUTDIR)\main.obj" "$(OUTDIR)\main.asm" 

"$(OUTDIR)\nRF2401.asm": "C:\Documents and Settings\shiju\desktop\Demo Code\Exa1\Send\nRF2401.c" 
	$(CC) $(CFLAGS) -o "$(OUTDIR)/nRF2401.asm" "C:/Documents and Settings/shiju/desktop/Demo Code/Exa1/Send/nRF2401.c" 

"$(OUTDIR)\nRF2401.obj": "$(OUTDIR)\nRF2401.asm"
	$(AS) $(CASFLAGS) $(INCLUDES) -o "$(OUTDIR)\nRF2401.obj" "$(OUTDIR)\nRF2401.asm" 


.SUFFIXES : .c .asm .obj .s37 .tsk .res

all :	 BEFOREBUILD "$(OUTDIR)" $(BINFILE)

BEFOREBUILD :

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
	$(RM) "$(OUTDIR)\nRF2401.obj" 
	$(RM) "$(OUTDIR)\nRF2401.lst" 
	$(RM) "$(OUTDIR)\nRF2401.asm" 
	$(RM) $(BINFILE) $(SBMFILE) 

.c.asm:
	$(CC) $(CFLAGS) $(INCLUDES) -o "$(OUTDIR)/$@" $<

.asm.obj:
	$(AS) $(ASFLAGS) $(INCLUDES) -o "$(OUTDIR)/$@" $<

