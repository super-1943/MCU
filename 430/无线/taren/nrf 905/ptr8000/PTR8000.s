	.module PTR8000.C
	.area text(rom, con, rel)
	.dbfile D:\IccAvr\Pei\ptr8000\PTR8000.C
	.dbfunc e port_init _port_init fV
	.even
_port_init::
	.dbline -1
	.dbline 25
; //ICC-AVR application builder : 2006-4-4 11:28:26
; // Target : M16 PTR8000模块简单测试
; // Crystal: 11.059Mhz
; 
; //最关键的是SPI的初始化，MSB首位和极性方式00，极性方式错误，数据则不正确
; 
; #include <iom16v.h>
; #include <macros.h>
; 
; #include "config.h"
; #include "nrf905.h"
; 
; #define MASTER  //编译控制是主机还是从机
; 
; #define T0N 25
; 
; //32字节数据包发送时间 
; //=650us_StartUp+200us_Preamble+(4+32+2)Byts*8Bit/50000bps*1000000us=6.6ms
; #define RFTN 10  //发送测试间隔 10*20ms
; 
; bit bTimer,bRfSend;
; uchar T0Cnt,RfCnt;
; 
; void port_init(void)
; {
	.dbline 26
;  PORTA = 0x08;
	ldi R24,8
	out 0x1b,R24
	.dbline 27
;  DDRA  = 0x37;
	ldi R24,55
	out 0x1a,R24
	.dbline 28
;  PORTB = 0x50;
	ldi R24,80
	out 0x18,R24
	.dbline 29
;  DDRB  = 0xBF;
	ldi R24,191
	out 0x17,R24
	.dbline 30
;  PORTC = 0x00; //m103 output only
	clr R2
	out 0x15,R2
	.dbline 31
;  DDRC  = 0x00;
	out 0x14,R2
	.dbline 32
;  PORTD = 0x1C;
	ldi R24,28
	out 0x12,R24
	.dbline 33
;  DDRD  = 0x80;
	ldi R24,128
	out 0x11,R24
	.dbline -2
L1:
	.dbline 0 ; func end
	ret
	.dbend
	.dbfunc e timer0_init _timer0_init fV
	.even
_timer0_init::
	.dbline -1
	.dbline 41
; }
; 
; //TIMER0 initialize - prescale:1024
; // WGM: Normal
; // desired value: 20mSec
; // actual value: 19.908mSec (0.5%)
; void timer0_init(void)
; {
	.dbline 42
;  TCCR0 = 0x00; //stop
	clr R2
	out 0x33,R2
	.dbline 43
;  TCNT0 = 0x29; //set count
	ldi R24,41
	out 0x32,R24
	.dbline 44
;  OCR0  = 0xD7;  //set compare
	ldi R24,215
	out 0x3c,R24
	.dbline 45
;  TCCR0 = 0x05; //start timer
	ldi R24,5
	out 0x33,R24
	.dbline -2
L2:
	.dbline 0 ; func end
	ret
	.dbend
	.area vector(rom, abs)
	.org 36
	jmp _timer0_ovf_isr
	.area text(rom, con, rel)
	.dbfile D:\IccAvr\Pei\ptr8000\PTR8000.C
	.dbfunc e timer0_ovf_isr _timer0_ovf_isr fV
	.even
_timer0_ovf_isr::
	st -y,R2
	st -y,R24
	in R2,0x3f
	st -y,R2
	.dbline -1
	.dbline 50
; }
; 
; #pragma interrupt_handler timer0_ovf_isr:10
; void timer0_ovf_isr(void)
; {
	.dbline 51
;  TCNT0 = 0x29; //reload counter value
	ldi R24,41
	out 0x32,R24
	.dbline 53
;  
;  if (--T0Cnt==0)
	lds R24,_T0Cnt
	subi R24,1
	mov R2,R24
	sts _T0Cnt,R2
	tst R24
	brne L4
	.dbline 54
;    {T0Cnt=T0N;
	.dbline 54
	ldi R24,25
	sts _T0Cnt,R24
	.dbline 55
;     bTimer=1;
	ldi R24,1
	sts _bTimer,R24
	.dbline 56
;     }
L4:
	.dbline 57
	lds R24,_RfCnt
	subi R24,1
	mov R2,R24
	sts _RfCnt,R2
	tst R24
	brne L6
	.dbline 58
	.dbline 58
	ldi R24,10
	sts _RfCnt,R24
	.dbline 59
	ldi R24,1
	sts _bRfSend,R24
	.dbline 60
L6:
	.dbline -2
L3:
	ld R2,y+
	out 0x3f,R2
	ld R24,y+
	ld R2,y+
	.dbline 0 ; func end
	reti
	.dbend
	.dbfunc e timer1_init _timer1_init fV
	.even
_timer1_init::
	.dbline -1
	.dbline 68
; if (--RfCnt==0)
;    {RfCnt=RFTN;
;     bRfSend=1;
;     }
; }
; 
; //TIMER1 initialize - prescale:8
; // WGM: 0) Normal, TOP=0xFFFF
; // desired value: 10mSec
; // actual value:  9.999mSec (0.0%)
; void timer1_init(void)
; {
	.dbline 69
;  TCCR1B = 0x00; //stop
	clr R2
	out 0x2e,R2
	.dbline 70
;  TCNT1H = 0xCA; //setup
	ldi R24,202
	out 0x2d,R24
	.dbline 71
;  TCNT1L = 0x01;
	ldi R24,1
	out 0x2c,R24
	.dbline 72
;  OCR1AH = 0x35;
	ldi R24,53
	out 0x2b,R24
	.dbline 73
;  OCR1AL = 0xFF;
	ldi R24,255
	out 0x2a,R24
	.dbline 74
;  OCR1BH = 0x35;
	ldi R24,53
	out 0x29,R24
	.dbline 75
;  OCR1BL = 0xFF;
	ldi R24,255
	out 0x28,R24
	.dbline 76
;  ICR1H  = 0x35;
	ldi R24,53
	out 0x27,R24
	.dbline 77
;  ICR1L  = 0xFF;
	ldi R24,255
	out 0x26,R24
	.dbline 78
;  TCCR1A = 0x00;
	out 0x2f,R2
	.dbline 79
;  TCCR1B = 0x02; //start Timer
	ldi R24,2
	out 0x2e,R24
	.dbline -2
L8:
	.dbline 0 ; func end
	ret
	.dbend
	.area vector(rom, abs)
	.org 32
	jmp _timer1_ovf_isr
	.area text(rom, con, rel)
	.dbfile D:\IccAvr\Pei\ptr8000\PTR8000.C
	.dbfunc e timer1_ovf_isr _timer1_ovf_isr fV
	.even
_timer1_ovf_isr::
	st -y,R24
	in R24,0x3f
	st -y,R24
	.dbline -1
	.dbline 84
; }
; 
; #pragma interrupt_handler timer1_ovf_isr:9
; void timer1_ovf_isr(void)
; {
	.dbline 86
;  //TIMER1 has overflowed
;  TCNT1H = 0xCA; //reload counter high value
	ldi R24,202
	out 0x2d,R24
	.dbline 87
;  TCNT1L = 0x01; //reload counter low value
	ldi R24,1
	out 0x2c,R24
	.dbline -2
L9:
	ld R24,y+
	out 0x3f,R24
	ld R24,y+
	.dbline 0 ; func end
	reti
	.dbend
	.dbfunc e spi_init _spi_init fV
;           temp -> R16
	.even
_spi_init::
	.dbline -1
	.dbline 92
; }
; 
; //SPI initialize
; void spi_init(void)
; {uchar temp;
	.dbline 95
; 
;  //SPCR = 0xD1; //SPI中断允许,SPI允许，主机模式，MSB，极性方式00，1/16系统时钟速率
;  SPCR = 0x51; //不使用SPI中断,其它同上
	ldi R24,81
	out 0xd,R24
	.dbline 96
;  SPSR = 0x00; //setup SPI
	clr R2
	out 0xe,R2
	.dbline 98
;  
;  temp = SPSR; //!!!
	in R16,0xe
	.dbline 99
;  temp = SPDR; //清空SPI，和中断标志，使SPI空闲    
	in R16,0xf
	.dbline -2
L10:
	.dbline 0 ; func end
	ret
	.dbsym r temp 16 c
	.dbend
	.area vector(rom, abs)
	.org 40
	jmp _spi_stc_isr
	.area text(rom, con, rel)
	.dbfile D:\IccAvr\Pei\ptr8000\PTR8000.C
	.dbfunc e spi_stc_isr _spi_stc_isr fV
;           data -> R0
	.even
_spi_stc_isr::
	.dbline -1
	.dbline 104
; }
; 
; #pragma interrupt_handler spi_stc_isr:11
; void spi_stc_isr(void)
; {uchar data;
	.dbline -2
L11:
	.dbline 0 ; func end
	reti
	.dbsym l data 1 c
	.dbend
	.dbfunc e uart0_init _uart0_init fV
	.even
_uart0_init::
	.dbline -1
	.dbline 116
;  //byte in SPDR has been sent/received
;  //data=SPDR;
;  //SPDR=0x66;
; }
; 
; //UART0 initialize
; // desired baud rate: 19200
; // actual: baud rate:19200 (0.0%)
; // char size: 5 bits
; // parity: Disabled
; void uart0_init(void)
; {
	.dbline 117
;  UCSRB = 0x00; //disable while setting baud rate
	clr R2
	out 0xa,R2
	.dbline 118
;  UCSRA = 0x00;
	out 0xb,R2
	.dbline 119
;  UCSRC = BIT(URSEL) | 0x00;
	ldi R24,128
	out 0x20,R24
	.dbline 120
;  UBRRL = 0x23; //set baud rate lo
	ldi R24,35
	out 0x9,R24
	.dbline 121
;  UBRRH = 0x00; //set baud rate hi
	out 0x20,R2
	.dbline 122
;  UCSRB = 0x18;
	ldi R24,24
	out 0xa,R24
	.dbline -2
L12:
	.dbline 0 ; func end
	ret
	.dbend
	.dbfunc e init_devices _init_devices fV
	.even
_init_devices::
	.dbline -1
	.dbline 127
; }
; 
; //call this routine to initialize all peripherals
; void init_devices(void)
; {
	.dbline 129
;  //stop errant interrupts until set up
;  CLI(); //disable all interrupts
	cli
	.dbline 130
;  port_init();
	xcall _port_init
	.dbline 131
;  timer0_init();
	xcall _timer0_init
	.dbline 132
;  timer1_init();
	xcall _timer1_init
	.dbline 133
;  spi_init();
	xcall _spi_init
	.dbline 134
;  uart0_init();
	xcall _uart0_init
	.dbline 136
; 
;  MCUCR = 0x00;
	clr R2
	out 0x35,R2
	.dbline 137
;  GICR  = 0x00;
	out 0x3b,R2
	.dbline 138
;  TIMSK = 0x05; //timer interrupt sources
	ldi R24,5
	out 0x39,R24
	.dbline 139
;  SEI(); //re-enable interrupts
	sei
	.dbline -2
L13:
	.dbline 0 ; func end
	ret
	.dbend
	.dbfunc e main _main fV
	.even
_main::
	.dbline -1
	.dbline 144
;  //all peripherals are now initialized
; }
; 
; void main()
; {
	.dbline 145
;    init_devices();
	xcall _init_devices
	.dbline 146
;    SystemIni();
	xcall _SystemIni
	.dbline 147
;    nrf905_Init();
	xcall _nrf905_Init
	xjmp L16
L15:
	.dbline 150
; 
;    while (1)
;    {  
	.dbline 151
;       if (bTimer) TimerFunc();
	lds R2,_bTimer
	tst R2
	breq L18
	.dbline 151
	xcall _TimerFunc
L18:
	.dbline 153
; 	  #ifdef MASTER
; 	    if (bRfSend)
	lds R2,_bRfSend
	tst R2
	breq L20
	.dbline 154
; 		{ bRfSend=0;
	.dbline 154
	clr R2
	sts _bRfSend,R2
	.dbline 155
; 		  RfSendProc();//发送测试
	xcall _RfSendProc
	.dbline 156
; 		}
L20:
	.dbline 159
	xcall _RfRecvProc
	.dbline 160
L16:
	.dbline 149
	xjmp L15
X0:
	.dbline 160
; 	  #endif
; 	  
; 	  RfRecvProc();//接收处理
;    };
	.dbline -2
L14:
	.dbline 0 ; func end
	ret
	.dbend
	.dbfunc e RfRecvProc _RfRecvProc fV
;              i -> R20
	.even
_RfRecvProc::
	xcall push_gset1
	.dbline -1
	.dbline 165
; }
; 
; //接收处理
; void RfRecvProc()
; {uchar i;
	.dbline 169
; 
;    //if ((PIND&(1<<AM))==0) return;//一般先AM=1指示地址匹配对
;    
;    if ((PIND&(1<<DR))==0) return;//DR=1时表示数据接收对而且Crc正确
	sbic 0x10,4
	rjmp L23
	.dbline 169
	xjmp L22
L23:
	.dbline 172
;    
;    //已经接收到数据
;    nrf905_ReadData();//读出...
	xcall _nrf905_ReadData
	.dbline 173
;    for (i=0;i<32;i++)
	clr R20
	xjmp L28
L25:
	.dbline 174
;    { if (RxBuf[i]!=(i+i)) 
	.dbline 174
	mov R2,R20
	add R2,R20
	ldi R24,<_RxBuf
	ldi R25,>_RxBuf
	mov R30,R20
	clr R31
	add R30,R24
	adc R31,R25
	ldd R3,z+0
	cp R3,R2
	breq L29
	.dbline 175
;         return;
	xjmp L22
L29:
	.dbline 176
L26:
	.dbline 173
	inc R20
L28:
	.dbline 173
	cpi R20,32
	brlo L25
	.dbline 179
;    }
;    
;    //数据接收正确...灯指示
;    CPL(PORTD,LED);
	ldi R24,128
	ldi R25,0
	in R2,0x12
	clr R3
	eor R2,R24
	eor R3,R25
	out 0x12,R2
	.dbline -2
L22:
	xcall pop_gset1
	.dbline 0 ; func end
	ret
	.dbsym r i 20 c
	.dbend
	.dbfunc e RfSendProc _RfSendProc fV
;              i -> R20
	.even
_RfSendProc::
	xcall push_gset1
	.dbline -1
	.dbline 189
;    
;    //从机回送数据包,这样双方都能指示是否收到有效数据包
;    #ifndef MASTER
;      RfSendProc();
;    #endif
; }
; 
; //发送测试
; void RfSendProc()
; {uchar i;
	.dbline 190
	clr R20
	xjmp L35
L32:
	.dbline 190
	mov R2,R20
	add R2,R20
	ldi R24,<_TxBuf
	ldi R25,>_TxBuf
	mov R30,R20
	clr R31
	add R30,R24
	adc R31,R25
	std z+0,R2
L33:
	.dbline 190
	inc R20
L35:
	.dbline 190
;    for (i=0;i<32;i++) TxBuf[i]=i+i;
	cpi R20,32
	brlo L32
	.dbline 191
;    nrf905_SendData();//发送测试数据
	xcall _nrf905_SendData
	.dbline 192
;    nrf905_RxOn();//重新回到接收状态
	xcall _nrf905_RxOn
	.dbline -2
L31:
	xcall pop_gset1
	.dbline 0 ; func end
	ret
	.dbsym r i 20 c
	.dbend
	.dbfunc e TimerFunc _TimerFunc fV
	.even
_TimerFunc::
	.dbline -1
	.dbline 196
; }
; 
; void TimerFunc()
; {
	.dbline 197
;    bTimer=0;
	clr R2
	sts _bTimer,R2
	.dbline 200
;    //WDR();//clear WDT
;    
;    CPL(PORTD,LED);
	ldi R24,128
	ldi R25,0
	in R2,0x12
	clr R3
	eor R2,R24
	eor R3,R25
	out 0x12,R2
	.dbline -2
L36:
	.dbline 0 ; func end
	ret
	.dbend
	.dbfunc e SystemIni _SystemIni fV
	.even
_SystemIni::
	.dbline -1
	.dbline 205
;    //SPDR=66;
; }
; 
; void SystemIni()
; {
	.dbline 206
;   T0Cnt=T0N;
	ldi R24,25
	sts _T0Cnt,R24
	.dbline 207
;   RfCnt=RFTN;
	ldi R24,10
	sts _RfCnt,R24
	.dbline -2
L37:
	.dbline 0 ; func end
	ret
	.dbend
	.dbfunc e DelayMs _DelayMs fV
;              i -> R20
;             ms -> R22
	.even
_DelayMs::
	xcall push_gset2
	mov R22,R16
	.dbline -1
	.dbline 211
; }
; 
; void DelayMs(uchar ms)
; {char i;
	.dbline 212
; for (i=0;i<ms;i++)
	clr R20
	xjmp L42
L39:
	.dbline 213
	.dbline 213
	ldi R16,1000
	ldi R17,3
	xcall _DelayUs
	.dbline 214
L40:
	.dbline 212
	inc R20
L42:
	.dbline 212
	cp R20,R22
	brlo L39
	.dbline 215
;   {DelayUs(1000);
;   }
;   return;
	.dbline -2
L38:
	xcall pop_gset2
	.dbline 0 ; func end
	ret
	.dbsym r i 20 c
	.dbsym r ms 22 c
	.dbend
	.dbfunc e DelayUs _DelayUs fV
;              i -> R20,R21
;             us -> R16,R17
	.even
_DelayUs::
	xcall push_gset1
	.dbline -1
	.dbline 219
; }
; 
; void DelayUs(uint us)
; {uint i;
	.dbline 220
;   for (i=0;i<us;i++)
	clr R20
	clr R21
	xjmp L47
L44:
	.dbline 221
	.dbline 221
	nop
	.dbline 221
	nop
	.dbline 221
	nop
	.dbline 221
	nop
	.dbline 221
	nop
	.dbline 221
	nop
	.dbline 222
L45:
	.dbline 220
	subi R20,255  ; offset = 1
	sbci R21,255
L47:
	.dbline 220
	cp R20,R16
	cpc R21,R17
	brlo L44
	.dbline -2
L43:
	xcall pop_gset1
	.dbline 0 ; func end
	ret
	.dbsym r i 20 i
	.dbsym r us 16 i
	.dbend
	.area bss(ram, con, rel)
	.dbfile D:\IccAvr\Pei\ptr8000\PTR8000.C
_RfCnt::
	.blkb 1
	.dbsym e RfCnt _RfCnt c
_T0Cnt::
	.blkb 1
	.dbsym e T0Cnt _T0Cnt c
_bRfSend::
	.blkb 1
	.dbsym e bRfSend _bRfSend c
_bTimer::
	.blkb 1
	.dbsym e bTimer _bTimer c
