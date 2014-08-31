;电子琴程序
;功能:  按1到8号键分别发出8个基本音节
;   按9号(歌曲)键,演奏一首乐曲
    SOUD    EQU P3.5        ;
    K1  EQU P1.0        ;
    K2  EQU P1.1        ;
    K3  EQU P1.2        ;
    K4  EQU P1.3        ;
    K5  EQU P1.4        ;
    K6  EQU P1.5        ;
    K7  EQU P1.6        ;
    K8  EQU P1.7        ;
    K9  EQU P3.4        ;
ORG     0000H
        LJMP    START
ORG     000BH
        INC     20H            ;中断服务,中断计数器加1
        MOV     TH0,#0D8H
        MOV     TL0,#0EFH      ;12M晶振，形成10毫秒中断
        RETI
START:  
        MOV     SP,#50H
        MOV     TH0,#0D8H
        MOV     TL0,#0EFH
        MOV     TMOD,#01H
        MOV     IE,#82H     ;
MAIN:
    JB  K1, LOOP1   ;
    ACALL   DEL5MS      ;
    JB  K1, LOOP1   ;
    ACALL   ONE     ;
    AJMP    MAIN        ;
LOOP1:
    JB  K2, LOOP2   ;
    ACALL   DEL5MS      ;
    JB  K2, LOOP2   ;
    ACALL   TWO     ;
    AJMP    MAIN        ;
LOOP2:
    JB  K3, LOOP3   ;
    ACALL   DEL5MS      ;
    JB  K3, LOOP3   ;
    ACALL   THREE       ;
    AJMP    MAIN        ;
LOOP3:
    JB  K4, LOOP4   ;   
    ACALL   DEL5MS      ;
    JB  K4, LOOP4   ;
    ACALL   FOUR        ;
    AJMP    MAIN        ;
LOOP4:
    JB  K5, LOOP5   ;
    ACALL   DEL5MS      ;
    JB  K5, LOOP5   ;
    ACALL   FIVE        ;
    AJMP    MAIN        ;
LOOP5:
    JB  K6, LOOP6   ;
    ACALL   DEL5MS      ;
    JB  K6, LOOP6   ;
    ACALL   SIX     ;
    AJMP    MAIN        ;
LOOP6:
    JB  K7, LOOP7   ;
    ACALL   DEL5MS      ;
    JB  K7, LOOP7   ;
    ACALL   SEVEN       ;
    AJMP    MAIN        ;
LOOP7:
    JB  K8, LOOP8   ;
    ACALL   DEL5MS      ;
    JB  K8, LOOP8   ;
    ACALL   EIGHT       ;
    AJMP    MAIN        ;
LOOP8:
    JB  K9, LOOP9   ;
    ACALL   DEL5MS      ;
    JB  K9, LOOP9   ;
    ACALL   MUSIC0      ;
LOOP9:
    AJMP    MAIN        ;
;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
MUSIC0:
        NOP
        MOV     DPTR,#DAT       ;表头地址送DPTR
        MOV     20H,#00H        ;中断计数器清0
        MOV     B,#00H          ;表序号清0
MUSIC1:
        NOP
        CLR     A
        MOVC    A,@A+DPTR       ;查表取代码
        JZ      END0            ;是00H,则结束
        CJNE    A,#0FFH,MUSIC5
        LJMP    MUSIC3
MUSIC5:
        NOP
        MOV     R6,A
        INC     DPTR
        MOV     A,B
        MOVC    A,@A+DPTR       ;取节拍代码送R7
        MOV     R7,A
        SETB    TR0             ;启动计数
MUSIC2:
        NOP
        CPL     SOUD
        MOV     A,R6
        MOV     R3,A
        LCALL   DEL
        MOV     A,R7
        CJNE    A,20H,MUSIC2    ;中断计数器(20H)=R7否?
                                ;不等,则继续循环
        MOV     20H,#00H        ;等于,则取下一代码
        INC     DPTR
        LJMP    MUSIC1
MUSIC3:
        NOP
        CLR     TR0             ;休止100毫秒
        MOV     R2,#0DH
MUSIC4:
        NOP
        MOV     R3,#0FFH
        LCALL   DEL
        DJNZ    R2,MUSIC4
        INC     DPTR
        LJMP    MUSIC1
END0:
        NOP
        MOV     R2,#64H         ;
MUSIC6:
        MOV     R3,#00H
        LCALL   DEL
        DJNZ    R2,MUSIC6
        RET         ;
;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@22
DEL:
        NOP
DEL3:                  
        MOV     R4,#05H
DEL4:   
        NOP
        DJNZ    R4,DEL4
        NOP
        DJNZ    R3,DEL3
        RET
DEL5MS: 
    MOV   R4,#45
DEL5MS1:
    MOV   R3,#54
DEL5MS2:
    DJNZ  R3,DEL5MS2
        DJNZ  R4,DEL5MS1
        RET
;@@@@@@@@@@@@@@@@@@@@@@@@2
;发1音
;@@@@@@@@@@@@@@@@@@@@@@@@@
ONE:
    NOP
        CPL     SOUD
        MOV     A,  #30H
        MOV     R3, A
        LCALL   DEL
        JNB K1, ONE ;
        ACALL   DEL5MS      ;
        JNB K1, ONE ;
        RET         ;
;@@@@@@@@@@@@@@@@@@@@@@@@2
;发2音
;@@@@@@@@@@@@@@@@@@@@@@@@@
TWO:
    NOP
        CPL     SOUD
        MOV     A,  #2CH
        MOV     R3, A
        LCALL   DEL
        JNB K2, TWO ;
        ACALL   DEL5MS      ;
        JNB K2, TWO ;
        RET         ;
;@@@@@@@@@@@@@@@@@@@@@@@@2
;发3音
;@@@@@@@@@@@@@@@@@@@@@@@@@
THREE:
    NOP
        CPL     SOUD
        MOV     A,  #28H
        MOV     R3, A
        LCALL   DEL
        JNB K3, THREE   ;
        ACALL   DEL5MS      ;
        JNB K3, THREE   ;
        RET         ;
;@@@@@@@@@@@@@@@@@@@@@@@@2
;发4音
;@@@@@@@@@@@@@@@@@@@@@@@@@
FOUR:
    NOP
        CPL     SOUD
        MOV     A,  #24H
        MOV     R3, A
        LCALL   DEL
        JNB K4, FOUR    ;
        ACALL   DEL5MS      ;
        JNB K4, FOUR    ;
        RET         ;
;@@@@@@@@@@@@@@@@@@@@@@@@2
;发5音
;@@@@@@@@@@@@@@@@@@@@@@@@@
FIVE:
    NOP
        CPL     SOUD
        MOV     A,  #20H
        MOV     R3, A
        LCALL   DEL
        JNB K5, FIVE    ;
        ACALL   DEL5MS      ;
        JNB K5, FIVE    ;
        RET         ;
;@@@@@@@@@@@@@@@@@@@@@@@@2
;发6音
;@@@@@@@@@@@@@@@@@@@@@@@@@
SIX:
    NOP
        CPL     SOUD
        MOV     A,  #1CH
        MOV     R3, A
        LCALL   DEL
        JNB K6, SIX ;
        ACALL   DEL5MS      ;
        JNB K6, SIX ;
        RET         ;
;@@@@@@@@@@@@@@@@@@@@@@@@2
;发7音
;@@@@@@@@@@@@@@@@@@@@@@@@@
SEVEN:
    NOP
        CPL     SOUD
        MOV     A,  #1AH
        MOV     R3, A
        LCALL   DEL
        JNB K7, SEVEN   ;
        ACALL   DEL5MS      ;
        JNB K7, SEVEN   ;
        RET         ;
;@@@@@@@@@@@@@@@@@@@@@@@@2
;发8音
;@@@@@@@@@@@@@@@@@@@@@@@@@
EIGHT:
    NOP
        CPL     SOUD
        MOV     A,  #18H
        MOV     R3, A
        LCALL   DEL
        JNB K8, EIGHT   ;
        ACALL   DEL5MS      ;
        JNB K8, EIGHT   ;
        RET         ;

;       NOP
;曲谱编码表
DAT:   
        DB      18H,     30H,     1CH,     10H
        DB      20H,     40H,     1CH,     10H     
        DB      18H,     10H,     20H,     10H
        DB      1CH,     10H,     18H,     40H
        DB      1CH,     20H,     20H,     20H
        DB      1CH,     20H,     18H,     20H     
        DB      20H,     80H,     0FFH,    20H
        DB      30H,     1CH,     10H ,   18H
        DB      20H,     15H,     20H ,    1CH
        DB      20H,     20H,     20H ,    26H
        DB      40H,     20H ,    20H ,    2BH
        DB      20H,     26H,     20H ,    20H     
        DB      20H,     30H ,    80H ,    0FFH
        DB      20H,     20H,     1CH ,    10H
        DB      18H,     10H,     20H ,    20H
        DB      26H,     20H ,    2BH ,    20H
        DB      30H,     20H ,    2BH ,    40H
        DB      20H,     20H  ,   1CH  ,   10H
        DB      18H,     10H,     20H,     20H
        DB      26H,     20H ,    2BH,     20H
        DB      30H,     20H,     2BH ,    40H
        DB      20H,     30H,     1CH ,    10H
        DB      18H,     20H ,    15H ,    20H
        DB      1CH,     20H ,    20H ,    20H
        DB      26H,     40H,     20H ,    20H     
        DB      2BH,     20H,     26H ,    20H     
        DB      20H,     20H,     30H ,    80H
        DB      20H,     30H,     1CH ,    10H
        DB      20H,     10H,     1CH ,    10H
        DB      20H,     20H,     26H  ,   20H
        DB      2BH,     20H,     30H  ,   20H
        DB      2BH,     40H,     20H   ,  15H
        DB      1FH,     05H,     20H    , 10H
        DB      1CH,     10H,     20H ,    20H
        DB      26H,     20H,     2BH ,    20H
        DB      30H,     20H,     2BH ,    40H
        DB      20H,     30H,     1CH  ,   10H
        DB      18H,     20H ,    15H  ,   20H
        DB      1CH,     20H ,    20H  ,   20H
        DB      26H,     40H,     20H  ,   20H
        DB      2BH,     20H,     26H   ,  20H
        DB      20H,     20H,     30H,     30H      
        DB      20H,     30H,     1CH,     10H
        DB      18H,     40H,     1CH,     20H
        DB      20H,     20H,     26H,     40H
        DB      13H,     60H,     18H ,    20H
        DB      15H,     40H,     13H ,    40H
        DB      18H,     80H,     00H
END

