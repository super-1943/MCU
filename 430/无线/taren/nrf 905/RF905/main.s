	.module main.c
	.area data(ram, con, rel)
_hz0::
	.blkb 65
	.area idata
	.byte 214,199,196,220,188,210,181,231,191,216,214,198,207,181,205,179
	.byte 32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32
	.byte 202,228,200,235,32,32,32,32,32,32,32,32,32,32,32,32
	.byte 32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32
	.byte 0
	.area data(ram, con, rel)
	.dbfile F:\programme\RF905\main.c
	.dbsym e hz0 _hz0 A[65:65]c
_times::
	.blkb 1
	.area idata
	.byte 0
	.area data(ram, con, rel)
	.dbfile F:\programme\RF905\main.c
	.dbsym e times _times c
	.area text(rom, con, rel)
	.dbfile F:\programme\RF905\main.c
	.dbfunc e spi_init _spi_init fV
	.even
_spi_init::
	.dbline -1
	.dbline 15
; #include <stdio.h>
; #include <iom8v.h>
; #include <macros.h>
; #include "nrf905.h"
; 
; unsigned char hz0[65]={"智能家电控制系统                输入                            "};
; unsigned char KeyV,KeyFlag;
; extern uchar TxBuf[],RxBuf[];
; unsigned char  value_T,set_data;
; unsigned char times=0;
; //unsigned char KeyD[5];
; //unsigned char KeyI=0;
; 
; void spi_init(void)
; {
	.dbline 16
;  SPCR = 0x51;    //setup SPI
	ldi R24,81
	out 0xd,R24
	.dbline -2
L1:
	.dbline 0 ; func end
	ret
	.dbend
	.dbfunc e print_temp _print_temp fV
;          wendu -> y+4
;           temp -> y+0
;        address -> R10
	.even
_print_temp::
	rcall push_gset3
	mov R10,R16
	sbiw R28,16
	.dbline -1
	.dbline 21
;  //SPSR = 0x00; //setup SPI
; }
; 
; void  print_temp(unsigned char address)
; {
	.dbline 25
; 
;    float  wendu;
;    unsigned long int temp;
;    wendu=GetTemp()*0.0625;
	rcall _GetTemp
	movw R2,R16
	ldi R16,<L3
	ldi R17,>L3
	rcall lpm32
	st -y,R19
	st -y,R18
	st -y,R17
	st -y,R16
	movw R16,R2
	rcall int2fp
	st -y,R19
	st -y,R18
	st -y,R17
	st -y,R16
	rcall empy32f
	movw R30,R28
	std z+4,R16
	std z+5,R17
	std z+6,R18
	std z+7,R19
	.dbline 26
;    temp=wendu*10000;
	ldi R16,<L6
	ldi R17,>L6
	rcall lpm32
	st -y,R19
	st -y,R18
	st -y,R17
	st -y,R16
	movw R30,R28
 ; stack offset 4
	ldd R2,z+8
	ldd R3,z+9
	ldd R4,z+10
	ldd R5,z+11
	st -y,R5
	st -y,R4
	st -y,R3
	st -y,R2
	rcall empy32f
	movw R30,R28
	std z+12,R16
	std z+13,R17
	std z+14,R18
	std z+15,R19
	movw R30,R28
	ldd R2,z+12
	ldd R3,z+13
	ldd R4,z+14
	ldd R5,z+15
	st -y,R5
	st -y,R4
	st -y,R3
	st -y,R2
	ldi R16,<L7
	ldi R17,>L7
	rcall lpm32
	st -y,R19
	st -y,R18
	st -y,R17
	st -y,R16
	rcall cmp32f
	brlt L4
	movw R30,R28
	ldd R2,z+12
	ldd R3,z+13
	ldd R4,z+14
	ldd R5,z+15
	st -y,R5
	st -y,R4
	st -y,R3
	st -y,R2
	ldi R16,<L7
	ldi R17,>L7
	rcall lpm32
	st -y,R19
	st -y,R18
	st -y,R17
	st -y,R16
	rcall sub32f
	rcall fp2long
	movw R2,R16
	movw R4,R18
	ldi R20,0
	ldi R21,0
	ldi R22,0
	ldi R23,128
	add R2,R20
	adc R3,R21
	adc R4,R22
	adc R5,R23
	movw R30,R28
	std z+8,R2
	std z+9,R3
	std z+10,R4
	std z+11,R5
	rjmp L5
L4:
	movw R30,R28
	ldd R16,z+12
	ldd R17,z+13
	ldd R18,z+14
	ldd R19,z+15
	rcall fp2long
	movw R30,R28
	std z+8,R16
	std z+9,R17
	std z+10,R18
	std z+11,R19
L5:
	movw R30,R28
	ldd R2,z+8
	ldd R3,z+9
	ldd R4,z+10
	ldd R5,z+11
	movw R30,R28
	std z+0,R2
	std z+1,R3
	std z+2,R4
	std z+3,R5
	.dbline 28
; 
;  lcd_write_comm(0x30);
	ldi R16,48
	ldi R17,0
	rcall _lcd_write_comm
	.dbline 29
;  lcd_write_comm(address);	
	mov R16,R10
	clr R17
	rcall _lcd_write_comm
	.dbline 30
;  lcd_write_data((temp/1000000)%10+0x30);	
	ldi R20,64
	ldi R21,66
	ldi R22,15
	ldi R23,0
	movw R30,R28
	ldd R2,z+0
	ldd R3,z+1
	ldd R4,z+2
	ldd R5,z+3
	st -y,R23
	st -y,R22
	st -y,R21
	st -y,R20
	movw R16,R2
	movw R18,R4
	rcall div32u
	ldi R20,10
	ldi R21,0
	ldi R22,0
	ldi R23,0
	st -y,R23
	st -y,R22
	st -y,R21
	st -y,R20
	rcall mod32u
	movw R2,R16
	movw R4,R18
	ldi R20,48
	ldi R21,0
	ldi R22,0
	ldi R23,0
	add R2,R20
	adc R3,R21
	adc R4,R22
	adc R5,R23
	movw R16,R2
	movw R18,R4
	rcall _lcd_write_data
	.dbline 31
;  lcd_write_data((temp/100000)%10+0x30);
	ldi R20,160
	ldi R21,134
	ldi R22,1
	ldi R23,0
	movw R30,R28
	ldd R2,z+0
	ldd R3,z+1
	ldd R4,z+2
	ldd R5,z+3
	st -y,R23
	st -y,R22
	st -y,R21
	st -y,R20
	movw R16,R2
	movw R18,R4
	rcall div32u
	ldi R20,10
	ldi R21,0
	ldi R22,0
	ldi R23,0
	st -y,R23
	st -y,R22
	st -y,R21
	st -y,R20
	rcall mod32u
	movw R2,R16
	movw R4,R18
	ldi R20,48
	ldi R21,0
	ldi R22,0
	ldi R23,0
	add R2,R20
	adc R3,R21
	adc R4,R22
	adc R5,R23
	movw R16,R2
	movw R18,R4
	rcall _lcd_write_data
	.dbline 32
;  lcd_write_data((temp/10000)%10+0x30);
	ldi R20,16
	ldi R21,39
	ldi R22,0
	ldi R23,0
	movw R30,R28
	ldd R2,z+0
	ldd R3,z+1
	ldd R4,z+2
	ldd R5,z+3
	st -y,R23
	st -y,R22
	st -y,R21
	st -y,R20
	movw R16,R2
	movw R18,R4
	rcall div32u
	ldi R20,10
	ldi R21,0
	ldi R22,0
	ldi R23,0
	st -y,R23
	st -y,R22
	st -y,R21
	st -y,R20
	rcall mod32u
	movw R2,R16
	movw R4,R18
	ldi R20,48
	ldi R21,0
	ldi R22,0
	ldi R23,0
	add R2,R20
	adc R3,R21
	adc R4,R22
	adc R5,R23
	movw R16,R2
	movw R18,R4
	rcall _lcd_write_data
	.dbline 33
;  lcd_write_data('.');    
	ldi R16,46
	ldi R17,0
	rcall _lcd_write_data
	.dbline 34
;  lcd_write_data((temp/1000)%10+0x30);
	ldi R20,232
	ldi R21,3
	ldi R22,0
	ldi R23,0
	movw R30,R28
	ldd R2,z+0
	ldd R3,z+1
	ldd R4,z+2
	ldd R5,z+3
	st -y,R23
	st -y,R22
	st -y,R21
	st -y,R20
	movw R16,R2
	movw R18,R4
	rcall div32u
	ldi R20,10
	ldi R21,0
	ldi R22,0
	ldi R23,0
	st -y,R23
	st -y,R22
	st -y,R21
	st -y,R20
	rcall mod32u
	movw R2,R16
	movw R4,R18
	ldi R20,48
	ldi R21,0
	ldi R22,0
	ldi R23,0
	add R2,R20
	adc R3,R21
	adc R4,R22
	adc R5,R23
	movw R16,R2
	movw R18,R4
	rcall _lcd_write_data
	.dbline 35
;  lcd_write_data((temp/100)%10+0x30);
	ldi R20,100
	ldi R21,0
	ldi R22,0
	ldi R23,0
	movw R30,R28
	ldd R2,z+0
	ldd R3,z+1
	ldd R4,z+2
	ldd R5,z+3
	st -y,R23
	st -y,R22
	st -y,R21
	st -y,R20
	movw R16,R2
	movw R18,R4
	rcall div32u
	ldi R20,10
	ldi R21,0
	ldi R22,0
	ldi R23,0
	st -y,R23
	st -y,R22
	st -y,R21
	st -y,R20
	rcall mod32u
	movw R2,R16
	movw R4,R18
	ldi R20,48
	ldi R21,0
	ldi R22,0
	ldi R23,0
	add R2,R20
	adc R3,R21
	adc R4,R22
	adc R5,R23
	movw R16,R2
	movw R18,R4
	rcall _lcd_write_data
	.dbline 36
;  lcd_write_data((temp/10)%10+0x30);    
	ldi R20,10
	ldi R21,0
	ldi R22,0
	ldi R23,0
	movw R30,R28
	ldd R2,z+0
	ldd R3,z+1
	ldd R4,z+2
	ldd R5,z+3
	st -y,R23
	st -y,R22
	st -y,R21
	st -y,R20
	movw R16,R2
	movw R18,R4
	rcall div32u
	ldi R20,10
	ldi R21,0
	ldi R22,0
	ldi R23,0
	st -y,R23
	st -y,R22
	st -y,R21
	st -y,R20
	rcall mod32u
	movw R2,R16
	movw R4,R18
	ldi R20,48
	ldi R21,0
	ldi R22,0
	ldi R23,0
	add R2,R20
	adc R3,R21
	adc R4,R22
	adc R5,R23
	movw R16,R2
	movw R18,R4
	rcall _lcd_write_data
	.dbline 37
;  lcd_write_data(temp%10+0x30);
	ldi R20,10
	ldi R21,0
	ldi R22,0
	ldi R23,0
	movw R30,R28
	ldd R2,z+0
	ldd R3,z+1
	ldd R4,z+2
	ldd R5,z+3
	st -y,R23
	st -y,R22
	st -y,R21
	st -y,R20
	movw R16,R2
	movw R18,R4
	rcall mod32u
	movw R2,R16
	movw R4,R18
	ldi R20,48
	ldi R21,0
	ldi R22,0
	ldi R23,0
	add R2,R20
	adc R3,R21
	adc R4,R22
	adc R5,R23
	movw R16,R2
	movw R18,R4
	rcall _lcd_write_data
	.dbline -2
L2:
	adiw R28,16
	rcall pop_gset3
	.dbline 0 ; func end
	ret
	.dbsym l wendu 4 D
	.dbsym l temp 0 l
	.dbsym r address 10 c
	.dbend
	.dbfunc e main _main fV
;         detect -> <dead>
;             kk -> R22
;       KeyValue -> R10
	.even
_main::
	sbiw R28,2
	.dbline -1
	.dbline 41
; }
; 
; void main(void)
; { unsigned char KeyValue,kk,detect;
	.dbline 42
;    CLI();                     //disable all interrupts
	cli
	.dbline 44
;   
;   spi_init();
	rcall _spi_init
	.dbline 47
;  
;      
;   DDRB=0x6f;                //0110 1111b
	ldi R24,111
	out 0x17,R24
	.dbline 48
;   PORTB=0xd4;               //1101 0100b
	ldi R24,212
	out 0x18,R24
	.dbline 51
;   //SET(PORTB,CSN);
;   
;   DDRC=0x00;
	clr R2
	out 0x14,R2
	.dbline 52
;   PORTC=0x00;
	out 0x15,R2
	.dbline 54
;   
;   DDRD=0xf8;               //1111 1000b
	ldi R24,248
	out 0x11,R24
	.dbline 55
;   PORTD=0xfc;              //1111 1100b
	ldi R24,252
	out 0x12,R24
	.dbline 57
;   
;   timer0_init();
	rcall _timer0_init
	.dbline 59
;   
;   MCUCR = 0x02;
	ldi R24,2
	out 0x35,R24
	.dbline 60
;   GICR  = 0x40;
	ldi R24,64
	out 0x3b,R24
	.dbline 61
;   TIMSK = 0x01; //timer interrupt sources
	ldi R24,1
	out 0x39,R24
	.dbline 72
;  
;   
;  // DDRD=0xff;
;   // PORTD=0xf8;
;   
;  // MCUCR = 0x02;
;  // GICR  = 0x40;
;   //TIMSK = 0x00; //timer interrupt sources
;   
;  // nrf905_Init();
;   SEI(); //re-enable interrupts
	sei
	.dbline 73
;   screen(hz0);
	ldi R16,<_hz0
	ldi R17,>_hz0
	rcall _screen
	rjmp L10
L9:
	.dbline 76
;    
;    while(1)
;   {
	.dbline 83
;    
;   //  nrf905_RxOn(); 
;    // detect=RfRecvProc();
; 	
;    // lcd_write_comm(0x9f);
;    // lcd_write_data(detect);
;     displayint(0x8a,value_T);
	lds R18,_value_T
	clr R19
	ldi R16,138
	ldi R17,0
	rcall _displayint
	.dbline 84
; 	displayint(0x8c,times);
	lds R18,_times
	clr R19
	ldi R16,140
	ldi R17,0
	rcall _displayint
	.dbline 85
; 	print_temp(0x90);
	ldi R16,144
	rcall _print_temp
	.dbline 89
; 	//if(detect=='Y')
; 	//{detect=='N';	}
; 	
;     if(KeyFlag==1)
	lds R24,_KeyFlag
	cpi R24,1
	brne L12
	.dbline 90
; 	{
	.dbline 91
; 	 KeyValue=KeyV;
	lds R10,_KeyV
	.dbline 92
; 	 KeyFlag=0;
	clr R2
	sts _KeyFlag,R2
	.dbline 93
; 	}
L12:
	.dbline 94
;    switch(KeyValue)        //此时相当按一次键处理两次程序
	mov R20,R10
	clr R21
	cpi R20,105
	ldi R30,0
	cpc R21,R30
	brne X2
	rjmp L18
X2:
	cpi R20,107
	ldi R30,0
	cpc R21,R30
	brne X3
	rjmp L21
X3:
	cpi R20,108
	ldi R30,0
	cpc R21,R30
	brne X4
	rjmp L24
X4:
	cpi R20,112
	ldi R30,0
	cpc R21,R30
	breq L17
	cpi R20,114
	ldi R30,0
	cpc R21,R30
	brne X5
	rjmp L19
X5:
	cpi R20,115
	ldi R30,0
	cpc R21,R30
	brne X6
	rjmp L22
X6:
	cpi R20,116
	ldi R30,0
	cpc R21,R30
	brne X7
	rjmp L23
X7:
	cpi R20,117
	ldi R30,0
	cpc R21,R30
	brne X8
	rjmp L25
X8:
	cpi R20,122
	ldi R30,0
	cpc R21,R30
	brne X9
	rjmp L20
X9:
	ldi R24,122
	ldi R25,0
	cp R24,R20
	cpc R25,R21
	brlt L31
L30:
	cpi R20,90
	ldi R30,0
	cpc R21,R30
	brne X10
	rjmp L29
X10:
	rjmp L15
L31:
	cpi R20,125
	ldi R30,0
	cpc R21,R30
	brne X11
	rjmp L27
X11:
	rjmp L15
X0:
	.dbline 95
;    {
L17:
	.dbline 96
;     case 112:kk=0;displayint(0x98,kk);
	clr R22
	.dbline 96
	mov R18,R22
	clr R19
	ldi R16,152
	ldi R17,0
	rcall _displayint
	.dbline 97
; 	              nrf905_SpiTest();
	rcall _nrf905_SpiTest
	.dbline 98
; 	              display_int(RxBuf,0x80,10);
	ldi R24,10
	ldi R25,0
	std y+1,R25
	std y+0,R24
	ldi R18,128
	ldi R19,0
	ldi R16,<_RxBuf
	ldi R17,>_RxBuf
	rcall _display_int
	.dbline 99
; 	              KeyValue=0;   break;
	clr R10
	.dbline 99
	rjmp L15
L18:
	.dbline 100
;     case 105:kk=1;displayint(0x98,kk);KeyValue=0;break;
	ldi R22,1
	.dbline 100
	mov R18,R22
	clr R19
	ldi R16,152
	ldi R17,0
	rcall _displayint
	.dbline 100
	clr R10
	.dbline 100
	rjmp L15
L19:
	.dbline 101
; 	case 114:kk=2;displayint(0x98,kk);KeyValue=0;break;
	ldi R22,2
	.dbline 101
	mov R18,R22
	clr R19
	ldi R16,152
	ldi R17,0
	rcall _displayint
	.dbline 101
	clr R10
	.dbline 101
	rjmp L15
L20:
	.dbline 102
; 	case 122:kk=3;displayint(0x98,kk);print_temp(0x9a);KeyValue=0;break;
	ldi R22,3
	.dbline 102
	mov R18,R22
	clr R19
	ldi R16,152
	ldi R17,0
	rcall _displayint
	.dbline 102
	ldi R16,154
	rcall _print_temp
	.dbline 102
	clr R10
	.dbline 102
	rjmp L15
L21:
	.dbline 103
; 	case 107:kk=4;displayint(0x98,kk);//RfSendProc();1122445645633312345
	ldi R22,4
	.dbline 103
	mov R18,R22
	clr R19
	ldi R16,152
	ldi R17,0
	rcall _displayint
	.dbline 104
; 	                                  KeyValue=0;break;
	clr R10
	.dbline 104
	rjmp L15
L22:
	.dbline 105
; 	case 115:kk=5;displayint(0x98,kk);nrf905_SendData();KeyValue=0;break;
	ldi R22,5
	.dbline 105
	mov R18,R22
	clr R19
	ldi R16,152
	ldi R17,0
	rcall _displayint
	.dbline 105
	rcall _nrf905_SendData
	.dbline 105
	clr R10
	.dbline 105
	rjmp L15
L23:
	.dbline 106
; 	case 116:kk=6;displayint(0x98,kk);nrf905_ReadData();KeyValue=0;break;
	ldi R22,6
	.dbline 106
	mov R18,R22
	clr R19
	ldi R16,152
	ldi R17,0
	rcall _displayint
	.dbline 106
	rcall _nrf905_ReadData
	.dbline 106
	clr R10
	.dbline 106
	rjmp L15
L24:
	.dbline 107
; 	case 108:kk=7;displayint(0x98,kk);display_int(RxBuf,0x80,12);KeyValue=0;break;
	ldi R22,7
	.dbline 107
	mov R18,R22
	clr R19
	ldi R16,152
	ldi R17,0
	rcall _displayint
	.dbline 107
	ldi R24,12
	ldi R25,0
	std y+1,R25
	std y+0,R24
	ldi R18,128
	ldi R19,0
	ldi R16,<_RxBuf
	ldi R17,>_RxBuf
	rcall _display_int
	.dbline 107
	clr R10
	.dbline 107
	rjmp L15
L25:
	.dbline 108
; 	case 117:kk=8;displayint(0x98,kk);display_int(RxBuf+12,0x80,12);KeyValue=0;break;
	ldi R22,8
	.dbline 108
	mov R18,R22
	clr R19
	ldi R16,152
	ldi R17,0
	rcall _displayint
	.dbline 108
	ldi R24,12
	ldi R25,0
	std y+1,R25
	std y+0,R24
	ldi R18,128
	ldi R19,0
	ldi R16,<_RxBuf+12
	ldi R17,>_RxBuf+12
	rcall _display_int
	.dbline 108
	clr R10
	.dbline 108
	rjmp L15
L27:
	.dbline 109
; 	case 125:kk=9;displayint(0x98,kk);display_int(RxBuf+24,0x80,8);KeyValue=0;break;
	ldi R22,9
	.dbline 109
	mov R18,R22
	clr R19
	ldi R16,152
	ldi R17,0
	rcall _displayint
	.dbline 109
	ldi R24,8
	ldi R25,0
	std y+1,R25
	std y+0,R24
	ldi R18,128
	ldi R19,0
	ldi R16,<_RxBuf+24
	ldi R17,>_RxBuf+24
	rcall _display_int
	.dbline 109
	clr R10
	.dbline 109
	rjmp L15
L29:
	.dbline 110
; 	case 90: kk='k'; KeyValue=0;
	ldi R22,107
	.dbline 110
	clr R10
	.dbline 112
; 	                 //display_int(RxBuf,0x80,12);
; 	                 lcd_write_comm(0x98);
	ldi R16,152
	ldi R17,0
	rcall _lcd_write_comm
	.dbline 113
; 	                 lcd_write_data('k');
	ldi R16,107
	ldi R17,0
	rcall _lcd_write_data
	.dbline 114
; 	               break;
	.dbline 115
; 	default :break;
L15:
	.dbline 119
L10:
	.dbline 75
	rjmp L9
X1:
	.dbline -2
L8:
	adiw R28,2
	.dbline 0 ; func end
	ret
	.dbsym l detect 3 c
	.dbsym r kk 22 c
	.dbsym r KeyValue 10 c
	.dbend
	.area vector(rom, abs)
	.org 2
	rjmp _int0_isr
	.area text(rom, con, rel)
	.dbfile F:\programme\RF905\main.c
	.area bss(ram, con, rel)
	.dbfile F:\programme\RF905\main.c
L33:
	.blkb 1
	.area text(rom, con, rel)
	.dbfile F:\programme\RF905\main.c
	.dbfunc e int0_isr _int0_isr fV
	.dbsym s IntNum L33 c
	.even
_int0_isr::
	st -y,R2
	st -y,R3
	st -y,R24
	st -y,R25
	in R2,0x3f
	st -y,R2
	.dbline -1
	.dbline 125
;    }  
;   
;   
;   }
; }
;   
;   
; #pragma interrupt_handler int0_isr:2
; void int0_isr(void)
; {
	.dbline 127
;  static unsigned char IntNum;
;  times++;
	lds R24,_times
	subi R24,255    ; addi 1
	sts _times,R24
	.dbline 128
;    if((IntNum>0)&&(IntNum<9))
	clr R2
	lds R3,L33
	cp R2,R3
	brsh L34
	mov R24,R3
	cpi R24,9
	brsh L34
	.dbline 129
;       {
	.dbline 130
;        KeyV>>=1;
	lds R2,_KeyV
	lsr R2
	sts _KeyV,R2
	.dbline 131
;        if(PINB&0x80)
	sbis 0x16,7
	rjmp L36
	.dbline 132
;        KeyV|=0x80;     
	mov R24,R2
	ori R24,128
	sts _KeyV,R24
L36:
	.dbline 133
;        }
L34:
	.dbline 135
	lds R24,L33
	subi R24,255    ; addi 1
	sts L33,R24
	.dbline 137
	ldi R24,10
	lds R2,L33
	cp R24,R2
	brsh L38
	.dbline 138
	.dbline 139
	clr R2
	sts L33,R2
	.dbline 140
	ldi R24,1
	sts _KeyFlag,R24
	.dbline 141
L38:
	.dbline -2
L32:
	ld R2,y+
	out 0x3f,R2
	ld R25,y+
	ld R24,y+
	ld R3,y+
	ld R2,y+
	.dbline 0 ; func end
	reti
	.dbend
	.area bss(ram, con, rel)
	.dbfile F:\programme\RF905\main.c
_set_data::
	.blkb 1
	.dbsym e set_data _set_data c
_value_T::
	.blkb 1
	.dbsym e value_T _value_T c
_KeyFlag::
	.blkb 1
	.dbsym e KeyFlag _KeyFlag c
_KeyV::
	.blkb 1
	.dbsym e KeyV _KeyV c
	.area lit(rom, con, rel)
L7:
	.word 0x0,0x4f00
L6:
	.word 0x4000,0x461c
L3:
	.word 0x0,0x3d80
