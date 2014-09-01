#####################################################################
#																	 
#	Created by u'nSP IDE		18:40:21	06/04/11
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

INCLUDES	= -I"E:/zhaoyongke/Demo/Receive"

BODY	= -body SPCE060A_061A -bfile "C:\Program Files\Sunplus\unSP IDE Common\Body\SPCE060A_061A.cpt"

BINFILE	= "$(OUTDIR)\Receive.S37"

ARYFILE	= "$(OUTDIR)\Receive.ary"

SBMFILE	= "$(OUTDIR)\Receive.sbm"

OPT	= -S -gstabs -Wall -mglobal-var-iram

ASFLAGS	= -t2 -d

CASFLAGS	= -t2 

CFLAGS	= $(OPT) -B$(APPDIR)\ $(INCLUDES) 

BINTYPE	= -as

LDFLAGS	= 

EXTRAFLAGS	= 


OBJFILES	= \
	"$(OUTDIR)\1_A24.res" \
	"$(OUTDIR)\2_A24.res" \
	"$(OUTDIR)\3_A24.res" \
	"$(OUTDIR)\Resource.obj" \
	"$(OUTDIR)\main.obj" \
	"$(OUTDIR)\nRF2401.obj" \
	"$(OUTDIR)\SACM_A1600.obj" \
	"$(OUTDIR)\SACM_A1600_User_C.obj" \
	"$(OUTDIR)\Snd.obj" \
	"$(OUTDIR)\led.obj" \
	"$(OUTDIR)\key.obj" 

"$(OUTDIR)\1_A24.res": "E:\zhaoyongke\Demo\Receive\Sound\1.A24"
	$(RESC) "E:\zhaoyongke\Demo\Receive\Sound\1.A24" "$(OUTDIR)\1_A24.res" RES_1_A24 

"$(OUTDIR)\2_A24.res": "E:\zhaoyongke\Demo\Receive\Sound\2.A24"
	$(RESC) "E:\zhaoyongke\Demo\Receive\Sound\2.A24" "$(OUTDIR)\2_A24.res" RES_2_A24 

"$(OUTDIR)\3_A24.res": "E:\zhaoyongke\Demo\Receive\Sound\3.A24"
	$(RESC) "E:\zhaoyongke\Demo\Receive\Sound\3.A24" "$(OUTDIR)\3_A24.res" RES_3_A24 

"$(OUTDIR)\Resource.obj": "E:\zhaoyongke\Demo\Receive\Resource.asm" 
	$(AS) $(ASFLAGS) $(INCLUDES) -o "$(OUTDIR)\Resource.obj" "E:\zhaoyongke\Demo\Receive\Resource.asm" 

"$(OUTDIR)\main.asm": "E:\zhaoyongke\Demo\Receive\main.c" ".\spce061a.h" ".\nRF2401.h" ".\Snd.h" ".\led.h" 
	$(CC) $(CFLAGS) -o "$(OUTDIR)/main.asm" "E:/zhaoyongke/Demo/Receive/main.c" 

"$(OUTDIR)\main.obj": "$(OUTDIR)\main.asm"
	$(AS) $(CASFLAGS) $(INCLUDES) -o "$(OUTDIR)\main.obj" "$(OUTDIR)\main.asm" 

"$(OUTDIR)\nRF2401.asm": "E:\zhaoyongke\Demo\Receive\nRF2401.c" ".\spce061a.h" 
	$(CC) $(CFLAGS) -o "$(OUTDIR)/nRF2401.asm" "E:/zhaoyongke/Demo/Receive/nRF2401.c" 

"$(OUTDIR)\nRF2401.obj": "$(OUTDIR)\nRF2401.asm"
	$(AS) $(CASFLAGS) $(INCLUDES) -o "$(OUTDIR)\nRF2401.obj" "$(OUTDIR)\nRF2401.asm" 

"$(OUTDIR)\SACM_A1600.obj": "E:\zhaoyongke\Demo\Receive\SACM_A1600.asm" 
	$(AS) $(ASFLAGS) $(INCLUDES) -o "$(OUTDIR)\SACM_A1600.obj" "E:\zhaoyongke\Demo\Receive\SACM_A1600.asm" 

"$(OUTDIR)\SACM_A1600_User_C.asm": "E:\zhaoyongke\Demo\Receive\SACM_A1600_User_C.c" 
	$(CC) $(CFLAGS) -o "$(OUTDIR)/SACM_A1600_User_C.asm" "E:/zhaoyongke/Demo/Receive/SACM_A1600_User_C.c" 

"$(OUTDIR)\SACM_A1600_User_C.obj": "$(OUTDIR)\SACM_A1600_User_C.asm"
	$(AS) $(CASFLAGS) $(INCLUDES) -o "$(OUTDIR)\SACM_A1600_User_C.obj" "$(OUTDIR)\SACM_A1600_User_C.asm" 

"$(OUTDIR)\Snd.asm": "E:\zhaoyongke\Demo\Receive\Snd.c" ".\spce061a.h" ".\A1600.h" 
	$(CC) $(CFLAGS) -o "$(OUTDIR)/Snd.asm" "E:/zhaoyongke/Demo/Receive/Snd.c" 

"$(OUTDIR)\Snd.obj": "$(OUTDIR)\Snd.asm"
	$(AS) $(CASFLAGS) $(INCLUDES) -o "$(OUTDIR)\Snd.obj" "$(OUTDIR)\Snd.asm" 

"$(OUTDIR)\led.asm": "E:\zhaoyongke\Demo\Receive\led.c" ".\led.h" ".\spce061a.h" 
	$(CC) $(CFLAGS) -o "$(OUTDIR)/led.asm" "E:/zhaoyongke/Demo/Receive/led.c" 

"$(OUTDIR)\led.obj": "$(OUTDIR)\led.asm"
	$(AS) $(CASFLAGS) $(INCLUDES) -o "$(OUTDIR)\led.obj" "$(OUTDIR)\led.asm" 

"$(OUTDIR)\key.asm": "E:\zhaoyongke\Demo\Receive\key.c" ".\spce061a.h" 
	$(CC) $(CFLAGS) -o "$(OUTDIR)/key.asm" "E:/zhaoyongke/Demo/Receive/key.c" 

"$(OUTDIR)\key.obj": "$(OUTDIR)\key.asm"
	$(AS) $(CASFLAGS) $(INCLUDES) -o "$(OUTDIR)\key.obj" "$(OUTDIR)\key.asm" 


.SUFFIXES : .c .asm .obj .s37 .tsk .res

all :	 "$(OUTDIR)" $(BINFILE)

"$(OUTDIR)" :
	if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

$(BINFILE) : $(OBJFILES) 
	$(LD) $(BINTYPE) $(ARYFILE) $(BINFILE) $(LDFLAGS) $(BODY) $(EXTRAFLAGS)

compile :	 $(OBJFILES)

clean :
	$(RM) "$(OUTDIR)\1_A24.res" 
	$(RM) "$(OUTDIR)\2_A24.res" 
	$(RM) "$(OUTDIR)\3_A24.res" 
	$(RM) "$(OUTDIR)\Resource.obj" 
	$(RM) "$(OUTDIR)\Resource.lst" 
	$(RM) "$(OUTDIR)\main.obj" 
	$(RM) "$(OUTDIR)\main.lst" 
	$(RM) "$(OUTDIR)\main.asm" 
	$(RM) "$(OUTDIR)\nRF2401.obj" 
	$(RM) "$(OUTDIR)\nRF2401.lst" 
	$(RM) "$(OUTDIR)\nRF2401.asm" 
	$(RM) "$(OUTDIR)\SACM_A1600.obj" 
	$(RM) "$(OUTDIR)\SACM_A1600.lst" 
	$(RM) "$(OUTDIR)\SACM_A1600_User_C.obj" 
	$(RM) "$(OUTDIR)\SACM_A1600_User_C.lst" 
	$(RM) "$(OUTDIR)\SACM_A1600_User_C.asm" 
	$(RM) "$(OUTDIR)\Snd.obj" 
	$(RM) "$(OUTDIR)\Snd.lst" 
	$(RM) "$(OUTDIR)\Snd.asm" 
	$(RM) "$(OUTDIR)\led.obj" 
	$(RM) "$(OUTDIR)\led.lst" 
	$(RM) "$(OUTDIR)\led.asm" 
	$(RM) "$(OUTDIR)\key.obj" 
	$(RM) "$(OUTDIR)\key.lst" 
	$(RM) "$(OUTDIR)\key.asm" 
	$(RM) $(BINFILE) $(SBMFILE) 

.c.asm:
	$(CC) $(CFLAGS) $(INCLUDES) -o "$(OUTDIR)/$@" $<

.asm.obj:
	$(AS) $(ASFLAGS) $(INCLUDES) -o "$(OUTDIR)/$@" $<

