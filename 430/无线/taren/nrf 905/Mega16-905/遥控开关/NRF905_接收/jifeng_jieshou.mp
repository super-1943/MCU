NOTE: AVR Code addresses are word addresses
All other addresses (including ones in FLASH) are byte addresses

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                             lit   0004   0250 =    592. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       0004  __lit_start
       0004  _ling16
       0014  _yi16
       0024  _er16
       0034  _san16
       0044  _si16
       0054  _wu16
       0064  _liu16
       0074  _qi16
       0084  _ba16
       0094  _jiu16
       00A4  _xsdian
       00B4  _wu
       00D4  _xian
       00F4  _yao
       0114  _kong
       0134  _xi
       0154  _tong
       0174  _ji
       0194  _dian
       01B4  _qi
       01D4  _kai
       01F4  _feng
       0214  _ming
       0234  _xiang
       0254  __lit_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                           idata   0254   000F =     15. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       0254  __idata_start
       0263  __idata_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            text   0264   06F0 =   1776. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       0132  __text_start
       0132  __start
       0151  _exit
       0152  _Delay
       0167  _Spi_initial
       016A  _SpiReadSpiWrite
       016F  _system_Init
       0178  _Config905
       018D  _TxPacket
       01BD  _SetTxMode
       01C3  _SetRxMode
       01C9  _TX
       01CC  _CheckDR
       01D2  _RxPacket
       01EF  _RX
       01F8  _LCD_Delay
       0203  _Lcd_init
       022B  _Lcd_Write_Data
       0257  _Lcd_Write_command
       027E  _Lcd_CURSOR
       028F  _Lcd_Clear
       02A4  _Test_LCD
       02BF  _dis_1616hz
       02FE  _dis_168hz
       0340  _dis_shuzi
       03C8  _dis_ykxt
       0401  _dis_jdql
       0428  _dis_fmqx
       044F  _StartUART
       045A  _R_S_Byte
       045C  _main
       0485  pop_gset2
       0487  pop_gset3
       0489  pop_gset5
       048B  push_gset5
       048D  push_gset4
       048F  push_gset3
       0491  push_gset2
       0493  push_gset1
       0496  pop_gset1
       0497  pop
       04AA  __text_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            data   0060   000F =     15. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0060  _TxAddress
       0060  __data_start
       0064  _RFConf
       006F  __data_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                             bss   006F   0006 =      6. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       006F  _count2
       006F  __bss_start
       0070  _count1
       0071  _TxRxBuffer
       0075  __bss_end

Area                               Start  End    Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                          vector   0000   0002 =      2. bytes (abs,ovr,rom)

Files Linked      [ module(s) ]

C:\iccv7avr\lib\crtAVR.o	[ crtavr.s ]
jifeng_jieshou.o	[ jifeng_jieshou.c ]
<library>	[ gpop2.s, gpop3.s, gpop5.s, gpush.s ]

User Global Definitions

ram_end = 0x25f
hwstk_size = 0x10

User Base Address Definitions

func_lit = 0x4
data = 0x60
eeprom:1.512

