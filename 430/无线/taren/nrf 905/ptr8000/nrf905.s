	.module nrf905.C
	.area text(rom, con, rel)
	.dbfile D:\IccAvr\Pei\ptr8000\nrf905.C
	.dbfunc e nrf905_Config _nrf905_Config fV
	.even
_nrf905_Config::
	xcall push_gset2
	.dbline -1
	.dbline 122
; #include "config.h"
; 
; extern void DelayMs(uchar ms);
; extern void DelayUs(uint us);
; 
; #define SIZE 32
; 
; uchar TxBuf[SIZE],RxBuf[SIZE];
; 
; /*-------------------------------------------------------------------------------------------
; nrf905配置寄存器宏定义 author:HotPower
;         nrf905配置寄存器(10Byte)
; 工作频率f=(422.4+CH_NO/10)*(1+HFREQ_PLL)MHz
; -------------------------------------------------------------------------------------------*/
; #define RX_ADDRESS           0x12345678               //接收有效地址(本方)
; #define TX_ADDRESS           0x12345678               //发送有效地址(对方)
; 
; #define CH_NO_FREQ_422_4MHz  0x000                     //工作频率422.4MHz(433MHz频段最低频率)
; #define CH_NO_FREQ_422_5MHz  0x001                     //工作频率422.5MHz
; #define CH_NO_FREQ_425_0MHz  0x01a                     //工作频率425.0MHz
; #define CH_NO_FREQ_427_5MHz  0x033                     //工作频率427.5MHz
; 
; #define CH_NO_FREQ_430_0MHz  0x04c                     //工作频率430.0MHz
; #define CH_NO_FREQ_433_0MHz  0x06a                     //工作频率433.0MHz(433MHz频段基准频率)
; #define CH_NO_FREQ_433_1MHz  0x06b                     //工作频率433.1MHz
; #define CH_NO_FREQ_433_2MHz  0x06c                     //工作频率433.2MHz
; #define CH_NO_FREQ_434_7MHz  0x07b                     //工作频率434.7MHz
; #define CH_NO_FREQ_473_5MHz  0x1ff                     //工作频率473.5MHz(433MHz频段最高频率)
; 
; #define CH_NO_FREQ_844_8MHz  0x000                     //工作频率844.8MHz(868MHz频段最低频率)
; 
; #define CH_NO_FREQ_862_0MHz  0x056                     //工作频率862.0MHz
; #define CH_NO_FREQ_868_0MHz  0x074                     //工作频率868.0MHz(868MHz频段基准频率)
; #define CH_NO_FREQ_868_2MHz  0x075                     //工作频率868.2MHz
; #define CH_NO_FREQ_868_4MHz  0x076                     //工作频率868.4MHz
; #define CH_NO_FREQ_869_8MHz  0x07d                     //工作频率869.8MHz
; #define CH_NO_FREQ_895_8MHz  0x0ff                     //工作频率895.8MHz
; #define CH_NO_FREQ_896_0MHz  0x100                     //工作频率896.0MHz
; #define CH_NO_FREQ_900_0MHz  0x114                     //工作频率900.0MHz
; #define CH_NO_FREQ_902_2MHz  0x11f                     //工作频率902.2MHz
; #define CH_NO_FREQ_902_4MHz  0x120                     //工作频率902.4MHz
; #define CH_NO_FREQ_915_0MHz  0x15f                     //工作频率915.0MHz(915MHz频段基准频率)
; #define CH_NO_FREQ_927_8MHz  0x19f                     //工作频率927.8MHz
; 
; #define CH_NO_FREQ_947_0MHz  0x1ff                     //工作频率947.0MHz(915MHz频段最高频率)
; 
; #define CH_NO_FREQ           CH_NO_FREQ_430_0MHz       //工作频率433.0MHz
; 
; 
; #define CH_NO_BYTE           CH_NO_FREQ & 0xff         //工作频率低8位       Byte0       01101100
; 
; #define AUTO_RETRAN          0x20                      //重发数据包          Byte1.5     0
; #define RX_RED_PWR           0x10                      //接收低功耗模式      Byte1.4     0
; #define PA_PWR__10dBm        0x00                      //输出功率-10dBm      Byte1.3~2   00
; #define PA_PWR_2dBm          0x04                      //输出功率+2dBm       Byte1.3~2
; #define PA_PWR_6dBm          0x08                      //输出功率+6dBm       Byte1.3~2
; #define PA_PWR_10dBm         0x0c                      //输出功率+10dBm      Byte1.3~2   
; #define HFREQ_PLL_433MHz     0x00                      //工作在433MHz频段    Byte1.1     0
; #define HFREQ_PLL_868MHz     0x02                      //工作在868MHz频段    Byte1.1
; #define HFREQ_PLL_915MHz     0x02                      //工作在915MHz频段    Byte1.1
; #define CH_NO_BIT8           CH_NO_FREQ >> 8           //工作频率第9位       Byte1.0     0
; 
; #define TX_AFW_1BYTE         1 * 16                    //发送地址宽度1字节   Byte2.7~4
; #define TX_AFW_2BYTE         2 * 16                    //发送地址宽度2字节   Byte2.7~4
; #define TX_AFW_3BYTE         3 * 16                    //发送地址宽度3字节   Byte2.7~4
; #define TX_AFW_4BYTE         4 * 16                    //发送地址宽度4字节   Byte2.7~4   100
; #define RX_AFW_1BYTE         1                         //接收地址宽度1字节   Byte2.3~0
; #define RX_AFW_2BYTE         2                         //接收地址宽度2字节   Byte2.3~0
; #define RX_AFW_3BYTE         3                         //接收地址宽度3字节   Byte2.3~0
; #define RX_AFW_4BYTE         4                         //接收地址宽度4字节   Byte2.3~0   100
; 
; #define RX_PW_1BYTE          1                         //接收数据宽度1字节   Byte3.5~0
; #define RX_PW_32BYTE         32                        //接收数据宽度32字节  Byte3.5~0   00100000
; #define TX_PW_1BYTE          1                         //发送数据宽度1字节   Byte4.5~0 
; #define TX_PW_32BYTE         32                        //发送数据宽度32字节  Byte4.5~0   00100000
; 
; #define RX_ADDRESS_0         RX_ADDRESS >> 24          //接收有效地址第1字节 Byte5       11100111
; #define RX_ADDRESS_1         (RX_ADDRESS >> 16) & 0xff //接收有效地址第2字节 Byte6       11100111 
; #define RX_ADDRESS_2         (RX_ADDRESS >> 8) & 0xff  //接收有效地址第3字节 Byte7       11100111
; #define RX_ADDRESS_3         RX_ADDRESS & 0xff         //接收有效地址第4字节 Byte8       11100111
;        
; #define CRC_MODE_16BIT       0x80                      //CRC16模式           Byte9.7     1
; #define CRC_MODE_8BIT        0x00                      //CRC8模式            Byte9.7     
; #define CRC_EN               0x40                      //CRC使能             Byte9.6     1
; #define CRC16_EN             0xc0                      //CRC16模式使能       Byte9.7~6   11
; #define CRC8_EN              0x40                      //CRC8模式使能        Byte9.7~6
; #define XOF_20MHz            0x20                      //晶体振荡器频率20MHz Byte9.5~3
; #define XOF_16MHz            0x18                      //晶体振荡器频率16MHz Byte9.5~3   100
; #define XOF_12MHz            0x10                      //晶体振荡器频率12MHz Byte9.5~3
; #define XOF_8MHz             0x08                      //晶体振荡器频率8MHz  Byte9.5~3
; #define XOF_4MHz             0x00                      //晶体振荡器频率4MHz  Byte9.5~3
; #define UP_CLK_EN            0x40                      //输出时钟使能        Byte9.2     1
; #define UP_CLK_FREQ_500kHz   0x03                      //输出时钟频率500kHz  Byte9.1~0   11
; #define UP_CLK_FREQ_1MHz     0x02                      //输出时钟频率1MHz    Byte9.1~0
; #define UP_CLK_FREQ_2MHz     0x01                      //输出时钟频率2MHz    Byte9.1~0
; #define UP_CLK_FREQ_4MHz     0x00                      //输出时钟频率4MHz    Byte9.1~0
; 
; #define UP_CLK_EN_500kHz     0x43                      //输出时钟频率500kHz  Byte9.2~0   111
; #define UP_CLK_EN_1MHz       0x42                      //输出时钟频率1MHz    Byte9.2~0
; #define UP_CLK_EN_2MHz       0x41                      //输出时钟频率2MHz    Byte9.2~0
; #define UP_CLK_EN_4MHz       0x40                      //输出时钟频率4MHz    Byte9.2~0
; 
; #define TX_ADDRESS_0         TX_ADDRESS >> 24          //发送有效地址第1字节
; #define TX_ADDRESS_1         (TX_ADDRESS >> 16) & 0xff //发送有效地址第2字节
; #define TX_ADDRESS_2         (TX_ADDRESS >> 8) & 0xff  //发送有效地址第3字节
; #define TX_ADDRESS_3         TX_ADDRESS & 0xff         //发送有效地址第4字节
; 
; /*-----------------------------------------------
;         nrf905命令控制字 author:HotPower
; ------------------------------------------------*/
; #define WC        0x00            // Write configuration register command
; #define RC        0x10            // Read  configuration register command
; #define WTP       0x20            // Write TX Payload  command
; #define RTP       0x21            // Read  TX Payload  command
; #define WTA       0x22            // Write TX Address  command
; #define RTA       0x23            // Read  TX Address  command
; #define RRP       0x24            // Read  RX Payload  command
;  
; 
; //配置nRF905
; void nrf905_Config(void)
; {
	.dbline 123
;   CLR(PORTB,CSN);                   // Spi 片选开
	cbi 0x18,4
	.dbline 124
;   nrf905_SpiRW(WC);                // Write config command
	clr R16
	clr R17
	xcall _nrf905_SpiRW
	.dbline 125
;   nrf905_SpiRW(CH_NO_BYTE);                      //中心频率低8位
	ldi R16,76
	ldi R17,0
	xcall _nrf905_SpiRW
	.dbline 126
;   nrf905_SpiRW(PA_PWR_10dBm | HFREQ_PLL_433MHz); //发射+10dBm,发射频率433MHz,中心频率第9位=0
	ldi R16,12
	ldi R17,0
	xcall _nrf905_SpiRW
	.dbline 127
;   nrf905_SpiRW(TX_AFW_4BYTE | RX_AFW_4BYTE);     //接收地址宽度4字节,发送地址宽度4字节
	ldi R16,68
	ldi R17,0
	xcall _nrf905_SpiRW
	.dbline 128
;   nrf905_SpiRW(RX_PW_32BYTE);                    //接收数据宽度32字节
	ldi R16,32
	ldi R17,0
	xcall _nrf905_SpiRW
	.dbline 129
;   nrf905_SpiRW(TX_PW_32BYTE);                    //发送数据宽度32字节
	ldi R16,32
	ldi R17,0
	xcall _nrf905_SpiRW
	.dbline 130
;   nrf905_SpiRW(RX_ADDRESS_0);                    //接收有效地址第1字节
	ldi R16,18
	ldi R17,0
	ldi R18,0
	ldi R19,0
	xcall _nrf905_SpiRW
	.dbline 131
;   nrf905_SpiRW(RX_ADDRESS_1);                    //接收有效地址第2字节
	ldi R16,52
	ldi R17,0
	ldi R18,0
	ldi R19,0
	xcall _nrf905_SpiRW
	.dbline 132
;   nrf905_SpiRW(RX_ADDRESS_2);                    //接收有效地址第3字节
	ldi R16,86
	ldi R17,0
	ldi R18,0
	ldi R19,0
	xcall _nrf905_SpiRW
	.dbline 133
;   nrf905_SpiRW(RX_ADDRESS_3);                    //接收有效地址第4字节
	ldi R16,120
	ldi R17,0
	ldi R18,0
	ldi R19,0
	xcall _nrf905_SpiRW
	.dbline 134
;   nrf905_SpiRW(CRC16_EN | XOF_16MHz);            //CRC16模式使能,晶体振荡器频率16MHz
	ldi R16,216
	ldi R17,0
	xcall _nrf905_SpiRW
	.dbline 135
;   SET(PORTB,CSN);                 // Disable Spi
	sbi 0x18,4
	.dbline -2
L1:
	xcall pop_gset2
	.dbline 0 ; func end
	ret
	.dbend
	.dbfunc e nrf905_SpiRW _nrf905_SpiRW fc
;           temp -> R20
;            val -> R16
	.even
_nrf905_SpiRW::
	xcall push_gset1
	.dbline -1
	.dbline 139
; }
; 
; uchar nrf905_SpiRW(uchar val) 
; {uchar temp;
	.dbline 141
; 
;     SPDR=val;
	out 0xf,R16
L3:
	.dbline 142
L4:
	.dbline 142
; 	while ((SPSR&(1<<SPIF))==0);
	sbis 0xe,7
	rjmp L3
	.dbline 143
; 	temp=SPDR;
	in R20,0xf
	.dbline 144
; 	return temp;
	mov R16,R20
	.dbline -2
L2:
	xcall pop_gset1
	.dbline 0 ; func end
	ret
	.dbsym r temp 20 c
	.dbsym r val 16 c
	.dbend
	.dbfunc e nrf905_StandBy _nrf905_StandBy fV
	.even
_nrf905_StandBy::
	.dbline -1
	.dbline 149
; }
; 
; //PwrDown->StandBy
; void nrf905_StandBy()
; {
	.dbline 150
;    SET(PORTB,PWR);
	sbi 0x18,0
	.dbline 151
;    CLR(PORTB,TRXCE);
	cbi 0x18,1
	.dbline 152
;    CLR(PORTB,TX_EN);
	cbi 0x18,2
	.dbline -2
L6:
	.dbline 0 ; func end
	ret
	.dbend
	.dbfunc e nrf905_Off _nrf905_Off fV
	.even
_nrf905_Off::
	.dbline -1
	.dbline 157
; }
; 
; //->PwrDown
; void nrf905_Off()
; {
	.dbline 158
;   CLR(PORTB,PWR);
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
	.dbline 163
; }
; 
; //->ShockBurst Send
; void nrf905_TxOn()
; {
	.dbline 164
;   SET(PORTB,PWR);
	sbi 0x18,0
	.dbline 165
;   SET(PORTB,TX_EN);
	sbi 0x18,2
	.dbline 166
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
	.dbline 171
; }
; 
; //->ShockBurst Send
; void nrf905_TxSend()
; {
	.dbline 172
;   SET(PORTB,TRXCE);
	sbi 0x18,1
	.dbline 173
;   DelayUs(20);//>10us
	ldi R16,20
	ldi R17,0
	xcall _DelayUs
	.dbline 174
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
	.dbline 179
; }
; 
; //->ShockBurst Recv
; void nrf905_RxOn()
; {
	.dbline 180
;   SET(PORTB,PWR);
	sbi 0x18,0
	.dbline 181
;   CLR(PORTB,TX_EN);//maybe first
	cbi 0x18,2
	.dbline 182
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
	.dbline 187
; }
; 
; //初始化nrf905
; void nrf905_Init()
; {
	.dbline 188
;    nrf905_StandBy();
	xcall _nrf905_StandBy
	.dbline 189
;    DelayMs(10);//!!!must >3ms
	ldi R16,10
	xcall _DelayMs
	.dbline 190
;    nrf905_Config();
	xcall _nrf905_Config
	.dbline 192
;    
;    nrf905_SpiTest();//test...
	xcall _nrf905_SpiTest
	.dbline 193
;    nrf905_RxOn();
	xcall _nrf905_RxOn
	.dbline -2
L11:
	.dbline 0 ; func end
	ret
	.dbend
	.dbfunc e nrf905_SpiTest _nrf905_SpiTest fV
;              i -> R20
	.even
_nrf905_SpiTest::
	xcall push_gset1
	.dbline -1
	.dbline 198
; }
; 
; //测试：通过读配置，判断SPI操作是否正确
; void nrf905_SpiTest()
; {uchar i;
	.dbline 199
;   CLR(PORTB,CSN);                   
	cbi 0x18,4
	.dbline 200
;   nrf905_SpiRW(RC);  //读配置
	ldi R16,16
	xcall _nrf905_SpiRW
	.dbline 201
;   for (i=0;i<10;i++)
	clr R20
	xjmp L16
L13:
	.dbline 202
	.dbline 203
	clr R16
	xcall _nrf905_SpiRW
	ldi R24,<_RxBuf
	ldi R25,>_RxBuf
	mov R30,R20
	clr R31
	add R30,R24
	adc R31,R25
	std z+0,R16
	.dbline 204
L14:
	.dbline 201
	inc R20
L16:
	.dbline 201
	cpi R20,10
	brlo L13
	.dbline 205
;   { 
;     RxBuf[i]=  nrf905_SpiRW(0);//read from nrf905
;   }
;   SET(PORTB,CSN);  
	sbi 0x18,4
	.dbline -2
L12:
	xcall pop_gset1
	.dbline 0 ; func end
	ret
	.dbsym r i 20 c
	.dbend
	.dbfunc e nrf905_SetTxAddr _nrf905_SetTxAddr fV
	.even
_nrf905_SetTxAddr::
	.dbline -1
	.dbline 210
; }
; 
; //写Tx地址
; void nrf905_SetTxAddr()
; {
	.dbline 211
;   CLR(PORTB,CSN);                   
	cbi 0x18,4
	.dbline 212
;   nrf905_SpiRW(WTA);  //写Tx地址  
	ldi R16,34
	xcall _nrf905_SpiRW
	.dbline 213
;   nrf905_SpiRW(TX_ADDRESS_0);
	ldi R16,18
	xcall _nrf905_SpiRW
	.dbline 214
;   nrf905_SpiRW(TX_ADDRESS_1);
	ldi R16,52
	xcall _nrf905_SpiRW
	.dbline 215
;   nrf905_SpiRW(TX_ADDRESS_2);
	ldi R16,86
	xcall _nrf905_SpiRW
	.dbline 216
;   nrf905_SpiRW(TX_ADDRESS_3);
	ldi R16,120
	xcall _nrf905_SpiRW
	.dbline 217
;   SET(PORTB,CSN);  
	sbi 0x18,4
	.dbline -2
L17:
	.dbline 0 ; func end
	ret
	.dbend
	.dbfunc e nrf905_SetData _nrf905_SetData fV
;              i -> R20
	.even
_nrf905_SetData::
	xcall push_gset1
	.dbline -1
	.dbline 222
; }
; 
; //写Tx数据
; void nrf905_SetData()
; {uchar i;
	.dbline 224
; 
;   CLR(PORTB,CSN);                   
	cbi 0x18,4
	.dbline 225
;   nrf905_SpiRW(WTP);  //写TxPayload 
	ldi R16,32
	xcall _nrf905_SpiRW
	.dbline 226
;   for (i=0;i<SIZE;i++)
	clr R20
	xjmp L22
L19:
	.dbline 227
	.dbline 228
	ldi R24,<_TxBuf
	ldi R25,>_TxBuf
	mov R30,R20
	clr R31
	add R30,R24
	adc R31,R25
	ldd R16,z+0
	xcall _nrf905_SpiRW
	.dbline 229
L20:
	.dbline 226
	inc R20
L22:
	.dbline 226
	cpi R20,32
	brlo L19
	.dbline 231
;   { 
;     nrf905_SpiRW(TxBuf[i]);
;   }
;   
;   SET(PORTB,CSN);  
	sbi 0x18,4
	.dbline -2
L18:
	xcall pop_gset1
	.dbline 0 ; func end
	ret
	.dbsym r i 20 c
	.dbend
	.dbfunc e nrf905_WaitSended _nrf905_WaitSended fV
	.even
_nrf905_WaitSended::
	.dbline -1
	.dbline 236
; }
; 
; //等待发送结束
; void nrf905_WaitSended()
; {
L24:
	.dbline 237
L25:
	.dbline 237
;    while ((PIND&(1<<DR))==0);
	sbis 0x10,4
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
	.dbline 242
; }
; 
; //发送TxBuf中的数据
; void nrf905_SendData()
; {
	.dbline 243
;    nrf905_TxOn();//切换到发送模式
	xcall _nrf905_TxOn
	.dbline 244
;    nrf905_SetTxAddr();//写发送地址
	xcall _nrf905_SetTxAddr
	.dbline 245
;    nrf905_SetData();//写数据
	xcall _nrf905_SetData
	.dbline 246
;    nrf905_TxSend();//启动发送
	xcall _nrf905_TxSend
	.dbline 247
;    nrf905_WaitSended();//等待发送结束
	xcall _nrf905_WaitSended
	.dbline -2
L27:
	.dbline 0 ; func end
	ret
	.dbend
	.dbfunc e nrf905_SendAgain _nrf905_SendAgain fV
	.even
_nrf905_SendAgain::
	.dbline -1
	.dbline 253
;    
; }
; 
; //测试直接重新发送上次写入的数据
; void nrf905_SendAgain()
; {
	.dbline 254
;    nrf905_TxOn();
	xcall _nrf905_TxOn
	.dbline 255
;    nrf905_TxSend();
	xcall _nrf905_TxSend
	.dbline 256
;    nrf905_WaitSended();
	xcall _nrf905_WaitSended
	.dbline -2
L28:
	.dbline 0 ; func end
	ret
	.dbend
	.dbfunc e nrf905_ReadData _nrf905_ReadData fV
;              i -> R20
	.even
_nrf905_ReadData::
	xcall push_gset1
	.dbline -1
	.dbline 262
;    
; }
; 
; //读出接收到的数据
; void nrf905_ReadData()
; {
	.dbline 265
;   uchar i;
; 
;   CLR(PORTB,CSN);                   
	cbi 0x18,4
	.dbline 266
;   nrf905_SpiRW(RRP);  //读RxPayload 
	ldi R16,36
	xcall _nrf905_SpiRW
	.dbline 267
;   for (i=0;i<SIZE;i++)
	clr R20
	xjmp L33
L30:
	.dbline 268
	.dbline 269
	clr R16
	xcall _nrf905_SpiRW
	ldi R24,<_RxBuf
	ldi R25,>_RxBuf
	mov R30,R20
	clr R31
	add R30,R24
	adc R31,R25
	std z+0,R16
	.dbline 270
L31:
	.dbline 267
	inc R20
L33:
	.dbline 267
	cpi R20,32
	brlo L30
	.dbline 272
;   { 
;     RxBuf[i]=nrf905_SpiRW(0);//read...
;   }
;   
;   SET(PORTB,CSN);  
	sbi 0x18,4
	.dbline -2
L29:
	xcall pop_gset1
	.dbline 0 ; func end
	ret
	.dbsym r i 20 c
	.dbend
	.area bss(ram, con, rel)
	.dbfile D:\IccAvr\Pei\ptr8000\nrf905.C
_RxBuf::
	.blkb 32
	.dbsym e RxBuf _RxBuf A[32:32]c
_TxBuf::
	.blkb 32
	.dbsym e TxBuf _TxBuf A[32:32]c
