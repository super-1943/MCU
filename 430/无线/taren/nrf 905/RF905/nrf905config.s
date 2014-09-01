	.module nrf905config.c
	.area data(ram, con, rel)
_TxBuf::
	.blkb 2
	.area idata
	.byte 'e,'f
	.area data(ram, con, rel)
	.blkb 2
	.area idata
	.byte 'g,'h
	.area data(ram, con, rel)
	.blkb 2
	.area idata
	.byte 'i,'j
	.area data(ram, con, rel)
	.blkb 2
	.area idata
	.byte 'k,'l
	.area data(ram, con, rel)
	.blkb 2
	.area idata
	.byte 'm,'n
	.area data(ram, con, rel)
	.blkb 2
	.area idata
	.byte 'o,'p
	.area data(ram, con, rel)
	.blkb 2
	.area idata
	.byte 'q,'r
	.area data(ram, con, rel)
	.blkb 2
	.area idata
	.byte 's,'t
	.area data(ram, con, rel)
	.blkb 2
	.area idata
	.byte 'u,'v
	.area data(ram, con, rel)
	.blkb 2
	.area idata
	.byte 'w,'x
	.area data(ram, con, rel)
	.blkb 2
	.area idata
	.byte 'y,'z
	.area data(ram, con, rel)
	.blkb 2
	.area idata
	.byte 123,124
	.area data(ram, con, rel)
	.blkb 2
	.area idata
	.byte 125,126
	.area data(ram, con, rel)
	.blkb 2
	.area idata
	.byte 127,128
	.area data(ram, con, rel)
	.blkb 2
	.area idata
	.byte 129,130
	.area data(ram, con, rel)
	.blkb 2
	.area idata
	.byte 131,132
	.area data(ram, con, rel)
	.dbfile F:\programme\RF905\nrf905config.c
	.dbsym e TxBuf _TxBuf A[32:32]c
	.area text(rom, con, rel)
	.dbfile F:\programme\RF905\nrf905config.c
	.dbfunc e nrf905_Config _nrf905_Config fV
	.even
_nrf905_Config::
	rcall push_gset2
	.dbline -1
	.dbline 14
; #include "nrf905.h"
; #include <iom8v.h>
; extern void DelayMs(uchar ms);
; extern void DelayUs(uint us);
; 
; #define SIZE 32
; 
; uchar TxBuf[SIZE]={101,102,103,104,105,106,107,108,109,110,
;                    111,112,113,114,115,116,117,118,119,120,
;                    121,122,123,124,125,126,127,128,129,130,
; 				    131,132};
; uchar RxBuf[SIZE];
; void nrf905_Config(void)
; {
	.dbline 15
;   CLR(PORTB,CSN);                                // Spi 片选开
	cbi 0x18,2
	.dbline 16
;   nrf905_SpiRW(WC);                              // Write config command
	clr R16
	clr R17
	rcall _nrf905_SpiRW
	.dbline 17
;   nrf905_SpiRW(CH_NO_BYTE);                      //中心频率低8位
	ldi R16,76
	ldi R17,0
	rcall _nrf905_SpiRW
	.dbline 18
;   nrf905_SpiRW(PA_PWR_10dBm | HFREQ_PLL_433MHz); //发射+10dBm,发射频率433MHz,中心频率第9位=0
	ldi R16,12
	ldi R17,0
	rcall _nrf905_SpiRW
	.dbline 19
;   nrf905_SpiRW(TX_AFW_4BYTE | RX_AFW_4BYTE);     //接收地址宽度4字节,发送地址宽度4字节
	ldi R16,68
	ldi R17,0
	rcall _nrf905_SpiRW
	.dbline 20
;   nrf905_SpiRW(RX_PW_32BYTE);                    //接收数据宽度32字节
	ldi R16,32
	ldi R17,0
	rcall _nrf905_SpiRW
	.dbline 21
;   nrf905_SpiRW(TX_PW_32BYTE);                    //发送数据宽度32字节
	ldi R16,32
	ldi R17,0
	rcall _nrf905_SpiRW
	.dbline 22
;   nrf905_SpiRW(RX_ADDRESS_0);                    //接收有效地址第1字节
	ldi R16,18
	ldi R17,0
	ldi R18,0
	ldi R19,0
	rcall _nrf905_SpiRW
	.dbline 23
;   nrf905_SpiRW(RX_ADDRESS_1);                    //接收有效地址第2字节
	ldi R16,52
	ldi R17,0
	ldi R18,0
	ldi R19,0
	rcall _nrf905_SpiRW
	.dbline 24
;   nrf905_SpiRW(RX_ADDRESS_2);                    //接收有效地址第3字节
	ldi R16,86
	ldi R17,0
	ldi R18,0
	ldi R19,0
	rcall _nrf905_SpiRW
	.dbline 25
;   nrf905_SpiRW(RX_ADDRESS_3);                    //接收有效地址第4字节
	ldi R16,120
	ldi R17,0
	ldi R18,0
	ldi R19,0
	rcall _nrf905_SpiRW
	.dbline 26
;   nrf905_SpiRW(CRC16_EN | XOF_16MHz);            //CRC16模式使能,晶体振荡器频率16MHz
	ldi R16,216
	ldi R17,0
	rcall _nrf905_SpiRW
	.dbline 27
;   SET(PORTB,CSN);                                // Disable Spi
	sbi 0x18,2
	.dbline -2
L1:
	rcall pop_gset2
	.dbline 0 ; func end
	ret
	.dbend
	.dbfunc e nrf905_SpiRW _nrf905_SpiRW fc
;           temp -> R20
;            val -> R16
	.even
_nrf905_SpiRW::
	rcall push_gset1
	.dbline -1
	.dbline 31
; }
; 
; uchar nrf905_SpiRW(uchar val) 
; {   uchar temp;
	.dbline 33
; 
;     SPDR=val;
	out 0xf,R16
L3:
	.dbline 35
L4:
	.dbline 34
; 	while ((SPSR&(1<<SPIF))==0)
	sbis 0xe,7
	rjmp L3
	.dbline 36
; 	;
; 	temp=SPDR;
	in R20,0xf
	.dbline 37
; 	return temp;
	mov R16,R20
	.dbline -2
L2:
	rcall pop_gset1
	.dbline 0 ; func end
	ret
	.dbsym r temp 20 c
	.dbsym r val 16 c
	.dbend
	.dbfunc e nrf905_StandBy _nrf905_StandBy fV
	.even
_nrf905_StandBy::
	.dbline -1
	.dbline 42
; }
; 
; //PwrDown->StandBy
; void nrf905_StandBy()
; {
	.dbline 43
;    SET(PORTB,PWRUP);
	sbi 0x18,0
	.dbline 44
;    CLR(PORTB,TRXCE);
	cbi 0x18,1
	.dbline 45
;    CLR(PORTB,TX_EN);
	cbi 0x18,6
	.dbline -2
L6:
	.dbline 0 ; func end
	ret
	.dbend
	.dbfunc e nrf905_Off _nrf905_Off fV
	.even
_nrf905_Off::
	.dbline -1
	.dbline 50
; }
; 
; //->PwrDown
; void nrf905_Off()
; {
	.dbline 51
;   CLR(PORTB,PWRUP);
	cbi 0x18,0
	.dbline -2
L7:
	.dbline 0 ; func end
	ret
	.dbend
	.dbfunc e nrf905_TxOn _nrf905_TxOn fV
	.even
_nrf905_TxOn::
	.dbline -1
	.dbline 56
; }
; 
; //->ShockBurst Send
; void nrf905_TxOn()
; {
	.dbline 57
;   SET(PORTB,PWRUP);
	sbi 0x18,0
	.dbline 58
;   SET(PORTB,TX_EN);
	sbi 0x18,6
	.dbline 59
;   CLR(PORTB,TRXCE);
	cbi 0x18,1
	.dbline -2
L8:
	.dbline 0 ; func end
	ret
	.dbend
	.dbfunc e nrf905_TxSend _nrf905_TxSend fV
	.even
_nrf905_TxSend::
	.dbline -1
	.dbline 64
; }
; 
; //->ShockBurst Send
; void nrf905_TxSend()
; {
	.dbline 65
;   SET(PORTB,TRXCE);
	sbi 0x18,1
	.dbline 66
;   DelayUs(20);//>10us
	ldi R16,20
	ldi R17,0
	rcall _DelayUs
	.dbline 67
;   CLR(PORTB,TRXCE);//只发送一次
	cbi 0x18,1
	.dbline -2
L9:
	.dbline 0 ; func end
	ret
	.dbend
	.dbfunc e nrf905_RxOn _nrf905_RxOn fV
	.even
_nrf905_RxOn::
	.dbline -1
	.dbline 72
; }
; 
; //->ShockBurst Recv
; void nrf905_RxOn()
; {
	.dbline 73
;   SET(PORTB,PWRUP);
	sbi 0x18,0
	.dbline 74
;   CLR(PORTB,TX_EN);      //maybe first
	cbi 0x18,6
	.dbline 75
;   SET(PORTB,TRXCE);
	sbi 0x18,1
	.dbline -2
L10:
	.dbline 0 ; func end
	ret
	.dbend
	.dbfunc e nrf905_Init _nrf905_Init fV
	.even
_nrf905_Init::
	.dbline -1
	.dbline 80
; }
; 
; //初始化nrf905
; void nrf905_Init()
; {
	.dbline 81
;    nrf905_StandBy();
	rcall _nrf905_StandBy
	.dbline 82
;    DelayMs(10);//!!!must >3ms
	ldi R16,10
	rcall _DelayMs
	.dbline 83
;    nrf905_Config();
	rcall _nrf905_Config
	.dbline 85
;    
;    nrf905_SpiTest();//test...
	rcall _nrf905_SpiTest
	.dbline 86
;    nrf905_RxOn();
	rcall _nrf905_RxOn
	.dbline -2
L11:
	.dbline 0 ; func end
	ret
	.dbend
	.dbfunc e nrf905_SpiTest _nrf905_SpiTest fV
;              i -> R20
	.even
_nrf905_SpiTest::
	rcall push_gset1
	.dbline -1
	.dbline 91
; }
; 
; //测试：通过读配置，判断SPI操作是否正确
; void nrf905_SpiTest()
; {uchar i;
	.dbline 92
;   CLR(PORTB,CSN);                   
	cbi 0x18,2
	.dbline 93
;   nrf905_SpiRW(RC);  //读配置
	ldi R16,16
	rcall _nrf905_SpiRW
	.dbline 94
;   for (i=0;i<10;i++)
	clr R20
	rjmp L16
L13:
	.dbline 95
	.dbline 96
	clr R16
	rcall _nrf905_SpiRW
	ldi R24,<_RxBuf
	ldi R25,>_RxBuf
	mov R30,R20
	clr R31
	add R30,R24
	adc R31,R25
	std z+0,R16
	.dbline 97
L14:
	.dbline 94
	inc R20
L16:
	.dbline 94
	cpi R20,10
	brlo L13
	.dbline 98
;   { 
;     RxBuf[i]=  nrf905_SpiRW(0);//read from nrf905
;   }
;   SET(PORTB,CSN);  
	sbi 0x18,2
	.dbline -2
L12:
	rcall pop_gset1
	.dbline 0 ; func end
	ret
	.dbsym r i 20 c
	.dbend
	.dbfunc e nrf905_SetTxAddr _nrf905_SetTxAddr fV
	.even
_nrf905_SetTxAddr::
	.dbline -1
	.dbline 103
; }
; 
; //写Tx地址
; void nrf905_SetTxAddr()
; {
	.dbline 104
;   CLR(PORTB,CSN);                   
	cbi 0x18,2
	.dbline 105
;   nrf905_SpiRW(WTA);  //写Tx地址  
	ldi R16,34
	rcall _nrf905_SpiRW
	.dbline 106
;   nrf905_SpiRW(TX_ADDRESS_0);
	ldi R16,18
	rcall _nrf905_SpiRW
	.dbline 107
;   nrf905_SpiRW(TX_ADDRESS_1);
	ldi R16,52
	rcall _nrf905_SpiRW
	.dbline 108
;   nrf905_SpiRW(TX_ADDRESS_2);
	ldi R16,86
	rcall _nrf905_SpiRW
	.dbline 109
;   nrf905_SpiRW(TX_ADDRESS_3);
	ldi R16,120
	rcall _nrf905_SpiRW
	.dbline 110
;   SET(PORTB,CSN);  
	sbi 0x18,2
	.dbline -2
L17:
	.dbline 0 ; func end
	ret
	.dbend
	.dbfunc e nrf905_SetData _nrf905_SetData fV
;              i -> R20
	.even
_nrf905_SetData::
	rcall push_gset1
	.dbline -1
	.dbline 115
; }
; 
; //写Tx数据
; void nrf905_SetData()
; {uchar i;
	.dbline 117
; 
;   CLR(PORTB,CSN);                   
	cbi 0x18,2
	.dbline 118
;   nrf905_SpiRW(WTP);  //写TxPayload 
	ldi R16,32
	rcall _nrf905_SpiRW
	.dbline 119
;   for (i=0;i<SIZE;i++)
	clr R20
	rjmp L22
L19:
	.dbline 120
	.dbline 121
	ldi R24,<_TxBuf
	ldi R25,>_TxBuf
	mov R30,R20
	clr R31
	add R30,R24
	adc R31,R25
	ldd R16,z+0
	rcall _nrf905_SpiRW
	.dbline 122
L20:
	.dbline 119
	inc R20
L22:
	.dbline 119
	cpi R20,32
	brlo L19
	.dbline 124
;   { 
;     nrf905_SpiRW(TxBuf[i]);
;   }
;   
;   SET(PORTB,CSN);  
	sbi 0x18,2
	.dbline -2
L18:
	rcall pop_gset1
	.dbline 0 ; func end
	ret
	.dbsym r i 20 c
	.dbend
	.dbfunc e nrf905_WaitSended _nrf905_WaitSended fV
	.even
_nrf905_WaitSended::
	.dbline -1
	.dbline 129
; }
; 
; //等待发送结束
; void nrf905_WaitSended()
; {
L24:
	.dbline 130
L25:
	.dbline 130
;    while ((PINC&(1<<DR))==0);
	sbis 0x13,2
	rjmp L24
	.dbline -2
L23:
	.dbline 0 ; func end
	ret
	.dbend
	.dbfunc e nrf905_SendData _nrf905_SendData fV
	.even
_nrf905_SendData::
	.dbline -1
	.dbline 135
; }
; 
; //发送TxBuf中的数据
; void nrf905_SendData()
; {
	.dbline 136
;    nrf905_TxOn();      //切换到发送模式
	rcall _nrf905_TxOn
	.dbline 137
;    nrf905_SetTxAddr(); //写发送地址
	rcall _nrf905_SetTxAddr
	.dbline 138
;    nrf905_SetData();   //写数据
	rcall _nrf905_SetData
	.dbline 139
;    nrf905_TxSend();    //启动发送
	rcall _nrf905_TxSend
	.dbline 141
;   // nrf905_WaitSended();//等待发送结束   有改动
;    DelayMs(10);
	ldi R16,10
	rcall _DelayMs
	.dbline -2
L27:
	.dbline 0 ; func end
	ret
	.dbend
	.dbfunc e nrf905_SendAgain _nrf905_SendAgain fV
	.even
_nrf905_SendAgain::
	.dbline -1
	.dbline 147
;    
; }
; 
; //测试直接重新发送上次写入的数据
; void nrf905_SendAgain()
; {
	.dbline 148
;    nrf905_TxOn();
	rcall _nrf905_TxOn
	.dbline 149
;    nrf905_TxSend();
	rcall _nrf905_TxSend
	.dbline 151
;   // nrf905_WaitSended();
;    DelayMs(20);
	ldi R16,20
	rcall _DelayMs
	.dbline -2
L28:
	.dbline 0 ; func end
	ret
	.dbend
	.dbfunc e nrf905_ReadData _nrf905_ReadData fV
;              i -> R20
	.even
_nrf905_ReadData::
	rcall push_gset1
	.dbline -1
	.dbline 156
; }
; 
; //读出接收到的数据
; void nrf905_ReadData()
; {
	.dbline 159
;   uchar i;
; 
;   CLR(PORTB,CSN);                   
	cbi 0x18,2
	.dbline 160
;   nrf905_SpiRW(RRP);  //读RxPayload 
	ldi R16,36
	rcall _nrf905_SpiRW
	.dbline 161
;   for (i=0;i<SIZE;i++)
	clr R20
	rjmp L33
L30:
	.dbline 162
	.dbline 163
	clr R16
	rcall _nrf905_SpiRW
	ldi R24,<_RxBuf
	ldi R25,>_RxBuf
	mov R30,R20
	clr R31
	add R30,R24
	adc R31,R25
	std z+0,R16
	.dbline 164
L31:
	.dbline 161
	inc R20
L33:
	.dbline 161
	cpi R20,32
	brlo L30
	.dbline 166
;   { 
;     RxBuf[i]=nrf905_SpiRW(0);//read...
;   }
;   
;   SET(PORTB,CSN);  
	sbi 0x18,2
	.dbline -2
L29:
	rcall pop_gset1
	.dbline 0 ; func end
	ret
	.dbsym r i 20 c
	.dbend
	.dbfunc e RfRecvProc _RfRecvProc fc
;              i -> <dead>
	.even
_RfRecvProc::
	.dbline -1
	.dbline 174
; 
; }
; 
; 
; 
; //接收处理
; uchar  RfRecvProc()
; {uchar i;
	.dbline 179
;    //if((PINC&(1<<CD))==0)  return 'C';
; 	
;   // if ((PINC&(1<<AM))==0) return 'A';//一般先AM=1指示地址匹配对
;    
;    if ((PINC&(1<<DR))==0) return 'N';//DR=1时表示数据接收对而且Crc正确
	sbic 0x13,2
	rjmp L35
	.dbline 179
	ldi R16,78
	rjmp L34
L35:
	.dbline 182
;    
;    //已经接收到数据
;    nrf905_ReadData();//读出...
	rcall _nrf905_ReadData
	.dbline 183
;    return 'y';
	ldi R16,121
	.dbline -2
L34:
	.dbline 0 ; func end
	ret
	.dbsym l i 1 c
	.dbend
	.dbfunc e RfSendProc _RfSendProc fV
;              i -> <dead>
	.even
_RfSendProc::
	.dbline -1
	.dbline 200
;   /* for (i=0;i<32;i++)
;    { if (RxBuf[i]!=(i+i)) 
;         return;
;    }*/
;    
;    //数据接收正确...灯指示
;     //    CPL(PORTD,LED);
;    
;    //从机回送数据包,这样双方都能指示是否收到有效数据包
;   /* #ifndef MASTER
;      RfSendProc();
;    #endif*/
; }
; 
; //发送测试
; void RfSendProc()
; {uchar i;
	.dbline 203
;   // for (i=0;i<32;i++) 
;   // TxBuf[i]=i+i;
;    nrf905_SendData();  //发送测试数据
	rcall _nrf905_SendData
	.dbline 204
;    nrf905_RxOn();      //重新回到接收状态
	rcall _nrf905_RxOn
	.dbline -2
L37:
	.dbline 0 ; func end
	ret
	.dbsym l i 1 c
	.dbend
	.dbfunc e DelayMs _DelayMs fV
;              i -> R20
;             ms -> R22
	.even
_DelayMs::
	rcall push_gset2
	mov R22,R16
	.dbline -1
	.dbline 212
; }
; 
; 
; 
; 
; 
; void DelayMs(uchar ms)
; {char i;
	.dbline 213
; for (i=0;i<ms;i++)
	clr R20
	rjmp L42
L39:
	.dbline 214
	.dbline 214
	ldi R16,1000
	ldi R17,3
	rcall _DelayUs
	.dbline 215
L40:
	.dbline 213
	inc R20
L42:
	.dbline 213
	cp R20,R22
	brlo L39
	.dbline 216
;   {DelayUs(1000);
;   }
;   return;
	.dbline -2
L38:
	rcall pop_gset2
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
	rcall push_gset1
	.dbline -1
	.dbline 220
; }
; 
; void DelayUs(uint us)
; {uint i;
	.dbline 221
;   for (i=0;i<us;i++)
	clr R20
	clr R21
	rjmp L47
L44:
	.dbline 222
L45:
	.dbline 221
	subi R20,255  ; offset = 1
	sbci R21,255
L47:
	.dbline 221
	cp R20,R16
	cpc R21,R17
	brlo L44
	.dbline -2
L43:
	rcall pop_gset1
	.dbline 0 ; func end
	ret
	.dbsym r i 20 i
	.dbsym r us 16 i
	.dbend
	.area bss(ram, con, rel)
	.dbfile F:\programme\RF905\nrf905config.c
_RxBuf::
	.blkb 32
	.dbsym e RxBuf _RxBuf A[32:32]c
