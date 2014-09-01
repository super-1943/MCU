#####################################################################
#																	 
#	Created by u'nSP IDE		16:13:22	09/01/08
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

INCLUDES	= -I"F:/abc/fudu3" -I"F:/abc/aa/aa"

BODY	= -body SPCE060A_061A -bfile "d:\Program Files\Sunplus\unSP IDE Common\Body\SPCE060A_061A.cpt"

BINFILE	= "$(OUTDIR)\Record.S37"

ARYFILE	= "$(OUTDIR)\Record.ary"

SBMFILE	= "$(OUTDIR)\Record.sbm"

OPT	= -S -gstabs -mglobal-var-iram

ASFLAGS	= -t2 -d

CASFLAGS	= -t2 

CFLAGS	= $(OPT) -B$(APPDIR)\ $(INCLUDES) 

BINTYPE	= -as

LDFLAGS	= 

EXTRAFLAGS	= 


OBJFILES	= \
	"$(OUTDIR)\system.obj" \
	"$(OUTDIR)\isr.obj" \
	"$(OUTDIR)\main.obj" \
	"$(OUTDIR)\hardware.obj" \
	"$(OUTDIR)\key.obj" \
	"$(OUTDIR)\Resource.obj" \
	"$(OUTDIR)\sram.obj" \
	"$(OUTDIR)\Flash.obj" 

"$(OUTDIR)\system.obj": "F:\abc\fudu3\system.asm" 
	$(AS) $(ASFLAGS) $(INCLUDES)  -l "$(OUTDIR)\system.lst" -o "$(OUTDIR)\system.obj" "F:\abc\fudu3\system.asm" 

"$(OUTDIR)\isr.obj": "F:\abc\fudu3\isr.asm" 
	$(AS) $(ASFLAGS) $(INCLUDES)  -l "$(OUTDIR)\isr.lst" -o "$(OUTDIR)\isr.obj" "F:\abc\fudu3\isr.asm" 

"$(OUTDIR)\main.asm": "F:\abc\fudu3\main.c" 
	$(CC) $(CFLAGS) -o "$(OUTDIR)/main.asm" "F:/abc/fudu3/main.c" 

"$(OUTDIR)\main.obj": "$(OUTDIR)\main.asm"
	$(AS) $(CASFLAGS) $(INCLUDES) -l "$(OUTDIR)\main.lst" -o "$(OUTDIR)\main.obj" "$(OUTDIR)\main.asm" 

"$(OUTDIR)\hardware.obj": "F:\abc\fudu3\hardware.asm" 
	$(AS) $(ASFLAGS) $(INCLUDES) -l "$(OUTDIR)\hardware.lst" -o "$(OUTDIR)\hardware.obj" "F:\abc\fudu3\hardware.asm" 

"$(OUTDIR)\key.obj": "F:\abc\fudu3\key.asm" 
	$(AS) $(ASFLAGS) $(INCLUDES) -l "$(OUTDIR)\key.lst" -o "$(OUTDIR)\key.obj" "F:\abc\fudu3\key.asm" 

"$(OUTDIR)\Resource.obj": "F:\abc\fudu3\Resource.asm" 
	$(AS) $(ASFLAGS) $(INCLUDES) -l "$(OUTDIR)\Resource.lst" -o "$(OUTDIR)\Resource.obj" "F:\abc\fudu3\Resource.asm" 

"$(OUTDIR)\sram.obj": "F:\abc\fudu3\sram.asm" 
	$(AS) $(ASFLAGS) $(INCLUDES) -l "$(OUTDIR)\sram.lst" -o "$(OUTDIR)\sram.obj" "F:\abc\fudu3\sram.asm" 

"$(OUTDIR)\Flash.obj": "F:\abc\fudu3\Flash.asm" 
	$(AS) $(ASFLAGS) $(INCLUDES) -l "$(OUTDIR)\Flash.lst" -o "$(OUTDIR)\Flash.obj" "F:\abc\fudu3\Flash.asm" 


.SUFFIXES : .c .asm .obj .s37 .tsk .res

all :	 "$(OUTDIR)" $(BINFILE)

"$(OUTDIR)" :
	if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

$(BINFILE) : $(OBJFILES) 
	$(LD) $(BINTYPE) $(ARYFILE) $(BINFILE) $(LDFLAGS) $(BODY) $(EXTRAFLAGS)

compile :	 $(OBJFILES)

clean :
	$(RM) "$(OUTDIR)\system.obj" 
	$(RM) "$(OUTDIR)\system.lst" 
	$(RM) "$(OUTDIR)\isr.obj" 
	$(RM) "$(OUTDIR)\isr.lst" 
	$(RM) "$(OUTDIR)\main.obj" 
	$(RM) "$(OUTDIR)\main.lst" 
	$(RM) "$(OUTDIR)\main.asm" 
	$(RM) "$(OUTDIR)\hardware.obj" 
	$(RM) "$(OUTDIR)\hardware.lst" 
	$(RM) "$(OUTDIR)\key.obj" 
	$(RM) "$(OUTDIR)\key.lst" 
	$(RM) "$(OUTDIR)\Resource.obj" 
	$(RM) "$(OUTDIR)\Resource.lst" 
	$(RM) "$(OUTDIR)\sram.obj" 
	$(RM) "$(OUTDIR)\sram.lst" 
	$(RM) "$(OUTDIR)\Flash.obj" 
	$(RM) "$(OUTDIR)\Flash.lst" 
	$(RM) $(BINFILE) $(SBMFILE) 

.c.asm:
	$(CC) $(CFLAGS) $(INCLUDES) -o "$(OUTDIR)/$@" $<

.asm.obj:
	$(AS) $(ASFLAGS) $(INCLUDES) -o "$(OUTDIR)/$@" $<

