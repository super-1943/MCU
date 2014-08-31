SO BIT P1.0
CS BIT P1.1
SCK BIT P1.2

DATAH  DATA 30H
DATAL  DATA 31H
TDATAH DATA 32H
TDATAL DATA 33H

 ORG 0000H
 ajmp start
 org 00a0h
 
 start:MOV SP,#50H
 
 LCALL MAX0;调用初始化7219函数
 
 LOOP:LCALL DISP;调用显示函数
 
 SJMP LOOP 
 
 MAX0:MOV A,#0BH;设置扫描位数
 
 MOV R2,#03H ;显示4位
 
 LCALL YW
 
 MOV A,#0AH;设置亮度
 
 MOV R2,#05H
 
 LCALL YW
 
 MOV A,#09H;设置译码格式
 
 MOV R2,#0FFH ;设置BCD码
 
 LCALL YW
 
 MOV A,#0CH;设置正常工作
 
 MOV R2,#01H
 
 LCALL YW
 
 RET
 
 DISP:MOV R0,#40H;要显示的数据存储地址
 
 MOV R1,#01H;数码管的地址寄存器01h~08h
 
 MOV R3,#08H
 
 LOOP1:MOV A,@R0
 
 MOV R2,A
 
 MOV A,R1
 
 LCALL YW
 
 INC R0
 
 INC R1
 
 DJNZ R3,LOOP1
 
 RET
 
 YW:LCALL SEND;调用发送函数，一位一位的从din送入7219
 
 MOV A,R2
 
 LCALL SEND
 
 CLR P1.4;load 信号上升沿对其锁存
 
 NOP
 
 NOP
 
 SETB P2.2;复位
 
 RET
 
 SEND:MOV R4,#08H;对其字节向左循环移8位
 
 LOOP2:CLR P2.1;clk上升沿对每一位数据锁存
 
 RLC A
 
 MOV P2.0,C
 
 NOP
 
 NOP
 
 NOP
 
 SETB P2.1
 
 DJNZ R4,LOOP2
 
 RET
READT: CLR CS
        CLR SCK
        MOV R2,#08H
 READH: MOV C,SO
        RLC A
        SETB SCK
        NOP
        CLR SCK
        DJNZ R2,READH
        MOV DATAH,A
        MOV R2,#08H
 READL: MOV C,SO
        RLC A
        SETB SCK
        NOP
        CLR SCK
        DJNZ R2,READL
        MOV DATAL,A
        SETB CS
        RET
 D16T12:MOV A,DATAL
        RLC A
        MOV DATAL,A
        MOV A,DATAH
        RLC A
        SWAP A
        MOV B,A
        MOV A,#0FH
        MOV TDATAH,A
        MOV A,B
        ANL A,#0F0H
        MOV B,A
        MOV A,DATAL
        ANL A,#0F0H
        SWAP A
        ORL A,B
        MOV TDATAL,A
                RET
end