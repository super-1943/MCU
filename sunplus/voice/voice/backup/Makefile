#####################################################################
#																	 
#	Created by u'nSP IDE		09:46:37	12/17/10
#
#####################################################################




APPDIR	= D:\PROGRA~1\Sunplus\UNSPID~1.2D

OUTDIR	= .\Debug

CC	= $(APPDIR)\toolchain\gcc

AS	= $(APPDIR)\toolchain\xasm16

LD	= $(APPDIR)\toolchain\xlink16

AR	= $(APPDIR)\toolchain\xlib16

RESC	= $(APPDIR)\toolchain\resc

RM	= $(APPDIR)\toolchain\rm -f

INCLUDES	= -I"D:/sunplus/voice" -I"D:/Program Files/Sunplus/unSP IDE 2.6.2D/library/include" -I"D:/Program Files/Sunplus/unSP IDE 2.6.2D/library/include/sys"

BODY	= -body SPCE060A_061A -bfile "D:\Program Files\Sunplus\unSP IDE Common\Body\SPCE060A_061A.cpt"

BINFILE	= "$(OUTDIR)\voice.S37"

ARYFILE	= "$(OUTDIR)\voice.ary"

SBMFILE	= "$(OUTDIR)\voice.sbm"

OPT	= -S -gstabs -Wall -mglobal-var-iram

ASFLAGS	= -t2 -d

CASFLAGS	= -t2 -wpop

CFLAGS	= $(OPT) -B$(APPDIR)\toolchain\ $(INCLUDES) 

BINTYPE	= -as

LDFLAGS	= -listfile

EXTRAFLAGS	= 


OBJFILES	= \
	"$(OUTDIR)\0_48k.res" \
	"$(OUTDIR)\1_48k.res" \
	"$(OUTDIR)\2_48k.res" \
	"$(OUTDIR)\3_48k.res" \
	"$(OUTDIR)\4_48k.res" \
	"$(OUTDIR)\5_48k.res" \
	"$(OUTDIR)\6_48k.res" \
	"$(OUTDIR)\7_48k.res" \
	"$(OUTDIR)\8_48k.res" \
	"$(OUTDIR)\9_48k.res" \
	"$(OUTDIR)\10_48k.res" \
	"$(OUTDIR)\11_72k.res" \
	"$(OUTDIR)\hjwd_48k.res" \
	"$(OUTDIR)\shd_48k.res" \
	"$(OUTDIR)\T064_48k.res" \
	"$(OUTDIR)\GX_48k.res" \
	"$(OUTDIR)\Resource.obj" \
	"$(OUTDIR)\hardware.obj" \
	"$(OUTDIR)\isr.obj" \
	"$(OUTDIR)\main.obj" \
	"$(OUTDIR)\playsound.obj" \
	"$(OUTDIR)\system.obj" \
	"$(OUTDIR)\disp.obj" 

"$(OUTDIR)\0_48k.res": "D:\sunplus\voice\source\0.48k"
	$(RESC) "D:\sunplus\voice\source\0.48k" "$(OUTDIR)\0_48k.res" RES_0_48K 

"$(OUTDIR)\1_48k.res": "D:\sunplus\voice\source\1.48k"
	$(RESC) "D:\sunplus\voice\source\1.48k" "$(OUTDIR)\1_48k.res" RES_1_48K 

"$(OUTDIR)\2_48k.res": "D:\sunplus\voice\source\2.48k"
	$(RESC) "D:\sunplus\voice\source\2.48k" "$(OUTDIR)\2_48k.res" RES_2_48K 

"$(OUTDIR)\3_48k.res": "D:\sunplus\voice\source\3.48k"
	$(RESC) "D:\sunplus\voice\source\3.48k" "$(OUTDIR)\3_48k.res" RES_3_48K 

"$(OUTDIR)\4_48k.res": "D:\sunplus\voice\source\4.48k"
	$(RESC) "D:\sunplus\voice\source\4.48k" "$(OUTDIR)\4_48k.res" RES_4_48K 

"$(OUTDIR)\5_48k.res": "D:\sunplus\voice\source\5.48k"
	$(RESC) "D:\sunplus\voice\source\5.48k" "$(OUTDIR)\5_48k.res" RES_5_48K 

"$(OUTDIR)\6_48k.res": "D:\sunplus\voice\source\6.48k"
	$(RESC) "D:\sunplus\voice\source\6.48k" "$(OUTDIR)\6_48k.res" RES_6_48K 

"$(OUTDIR)\7_48k.res": "D:\sunplus\voice\source\7.48k"
	$(RESC) "D:\sunplus\voice\source\7.48k" "$(OUTDIR)\7_48k.res" RES_7_48K 

"$(OUTDIR)\8_48k.res": "D:\sunplus\voice\source\8.48k"
	$(RESC) "D:\sunplus\voice\source\8.48k" "$(OUTDIR)\8_48k.res" RES_8_48K 

"$(OUTDIR)\9_48k.res": "D:\sunplus\voice\source\9.48k"
	$(RESC) "D:\sunplus\voice\source\9.48k" "$(OUTDIR)\9_48k.res" RES_9_48K 

"$(OUTDIR)\10_48k.res": "D:\sunplus\voice\source\10.48k"
	$(RESC) "D:\sunplus\voice\source\10.48k" "$(OUTDIR)\10_48k.res" RES_10_48K 

"$(OUTDIR)\11_72k.res": "D:\sunplus\voice\source\11.72k"
	$(RESC) "D:\sunplus\voice\source\11.72k" "$(OUTDIR)\11_72k.res" RES_11_72K 

"$(OUTDIR)\hjwd_48k.res": "D:\sunplus\voice\source\hjwd.48k"
	$(RESC) "D:\sunplus\voice\source\hjwd.48k" "$(OUTDIR)\hjwd_48k.res" RES_HJWD_48K 

"$(OUTDIR)\shd_48k.res": "D:\sunplus\voice\source\shd.48k"
	$(RESC) "D:\sunplus\voice\source\shd.48k" "$(OUTDIR)\shd_48k.res" RES_SHD_48K 

"$(OUTDIR)\T064_48k.res": "D:\sunplus\voice\source\T064.48k"
	$(RESC) "D:\sunplus\voice\source\T064.48k" "$(OUTDIR)\T064_48k.res" RES_T064_48K 

"$(OUTDIR)\GX_48k.res": "D:\sunplus\voice\source\GX.48k"
	$(RESC) "D:\sunplus\voice\source\GX.48k" "$(OUTDIR)\GX_48k.res" RES_GX_48K 

"$(OUTDIR)\Resource.obj": "D:\sunplus\voice\Resource.asm" 
	$(AS) $(ASFLAGS) $(INCLUDES) -l "$(OUTDIR)\Resource.lst" -o "$(OUTDIR)\Resource.obj" "D:\sunplus\voice\Resource.asm" 

"$(OUTDIR)\hardware.obj": "D:\sunplus\voice\hardware.asm" 
	$(AS) $(ASFLAGS) $(INCLUDES) -l "$(OUTDIR)\hardware.lst" -o "$(OUTDIR)\hardware.obj" "D:\sunplus\voice\hardware.asm" 

"$(OUTDIR)\isr.asm": "D:\sunplus\voice\isr.c" ".\SPCE061A.H" ".\disp.h" 
	set PATH="$(APPDIR)\toolchain\";%PATH% & \
	$(CC) $(CFLAGS) -o "$(OUTDIR)/isr.asm" "D:/sunplus/voice/isr.c" 

"$(OUTDIR)\isr.obj": "$(OUTDIR)\isr.asm"
	$(AS) $(CASFLAGS) $(INCLUDES) -l "$(OUTDIR)\isr.lst" -o "$(OUTDIR)\isr.obj" "$(OUTDIR)\isr.asm" 

"$(OUTDIR)\main.asm": "D:\sunplus\voice\main.c" ".\SPCE061A.H" ".\system.h" ".\disp.h" 
	set PATH="$(APPDIR)\toolchain\";%PATH% & \
	$(CC) $(CFLAGS) -o "$(OUTDIR)/main.asm" "D:/sunplus/voice/main.c" 

"$(OUTDIR)\main.obj": "$(OUTDIR)\main.asm"
	$(AS) $(CASFLAGS) $(INCLUDES) -l "$(OUTDIR)\main.lst" -o "$(OUTDIR)\main.obj" "$(OUTDIR)\main.asm" 

"$(OUTDIR)\playsound.asm": "D:\sunplus\voice\playsound.c" ".\spce061a.h" 
	set PATH="$(APPDIR)\toolchain\";%PATH% & \
	$(CC) $(CFLAGS) -o "$(OUTDIR)/playsound.asm" "D:/sunplus/voice/playsound.c" 

"$(OUTDIR)\playsound.obj": "$(OUTDIR)\playsound.asm"
	$(AS) $(CASFLAGS) $(INCLUDES) -l "$(OUTDIR)\playsound.lst" -o "$(OUTDIR)\playsound.obj" "$(OUTDIR)\playsound.asm" 

"$(OUTDIR)\system.asm": "D:\sunplus\voice\system.c" ".\SPCE061A.H" 
	set PATH="$(APPDIR)\toolchain\";%PATH% & \
	$(CC) $(CFLAGS) -o "$(OUTDIR)/system.asm" "D:/sunplus/voice/system.c" 

"$(OUTDIR)\system.obj": "$(OUTDIR)\system.asm"
	$(AS) $(CASFLAGS) $(INCLUDES) -l "$(OUTDIR)\system.lst" -o "$(OUTDIR)\system.obj" "$(OUTDIR)\system.asm" 

"$(OUTDIR)\disp.asm": "D:\sunplus\voice\disp.c" ".\SPCE061A.h" 
	set PATH="$(APPDIR)\toolchain\";%PATH% & \
	$(CC) $(CFLAGS) -o "$(OUTDIR)/disp.asm" "D:/sunplus/voice/disp.c" 

"$(OUTDIR)\disp.obj": "$(OUTDIR)\disp.asm"
	$(AS) $(CASFLAGS) $(INCLUDES) -l "$(OUTDIR)\disp.lst" -o "$(OUTDIR)\disp.obj" "$(OUTDIR)\disp.asm" 


.SUFFIXES : .c .asm .obj .s37 .tsk .res

all :	 BEFOREBUILD "$(OUTDIR)" $(BINFILE)

BEFOREBUILD :

"$(OUTDIR)" :
	if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

$(BINFILE) : $(OBJFILES) 
	$(LD) $(BINTYPE) $(ARYFILE) $(BINFILE) $(LDFLAGS) $(BODY) $(EXTRAFLAGS)

compile :	 $(OBJFILES)

clean :
	$(RM) "$(OUTDIR)\0_48k.res" 
	$(RM) "$(OUTDIR)\1_48k.res" 
	$(RM) "$(OUTDIR)\2_48k.res" 
	$(RM) "$(OUTDIR)\3_48k.res" 
	$(RM) "$(OUTDIR)\4_48k.res" 
	$(RM) "$(OUTDIR)\5_48k.res" 
	$(RM) "$(OUTDIR)\6_48k.res" 
	$(RM) "$(OUTDIR)\7_48k.res" 
	$(RM) "$(OUTDIR)\8_48k.res" 
	$(RM) "$(OUTDIR)\9_48k.res" 
	$(RM) "$(OUTDIR)\10_48k.res" 
	$(RM) "$(OUTDIR)\11_72k.res" 
	$(RM) "$(OUTDIR)\hjwd_48k.res" 
	$(RM) "$(OUTDIR)\shd_48k.res" 
	$(RM) "$(OUTDIR)\T064_48k.res" 
	$(RM) "$(OUTDIR)\GX_48k.res" 
	$(RM) "$(OUTDIR)\Resource.obj" 
	$(RM) "$(OUTDIR)\Resource.lst" 
	$(RM) "$(OUTDIR)\hardware.obj" 
	$(RM) "$(OUTDIR)\hardware.lst" 
	$(RM) "$(OUTDIR)\isr.obj" 
	$(RM) "$(OUTDIR)\isr.lst" 
	$(RM) "$(OUTDIR)\isr.asm" 
	$(RM) "$(OUTDIR)\main.obj" 
	$(RM) "$(OUTDIR)\main.lst" 
	$(RM) "$(OUTDIR)\main.asm" 
	$(RM) "$(OUTDIR)\playsound.obj" 
	$(RM) "$(OUTDIR)\playsound.lst" 
	$(RM) "$(OUTDIR)\playsound.asm" 
	$(RM) "$(OUTDIR)\system.obj" 
	$(RM) "$(OUTDIR)\system.lst" 
	$(RM) "$(OUTDIR)\system.asm" 
	$(RM) "$(OUTDIR)\disp.obj" 
	$(RM) "$(OUTDIR)\disp.lst" 
	$(RM) "$(OUTDIR)\disp.asm" 
	$(RM) $(BINFILE) $(SBMFILE) 

.c.asm:
	$(CC) $(CFLAGS) $(INCLUDES) -o "$(OUTDIR)/$@" $<

.asm.obj:
	$(AS) $(ASFLAGS) $(INCLUDES) -o "$(OUTDIR)/$@" $<

