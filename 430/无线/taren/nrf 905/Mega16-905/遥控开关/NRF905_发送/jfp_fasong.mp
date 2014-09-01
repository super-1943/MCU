NOTE: AVR Code addresses are word addresses
All other addresses (including ones in FLASH) are byte addresses

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                           idata   0054   000F =     15. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       0054  __idata_start
       0063  __idata_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            text   0064   0210 =    528. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       0032  __text_start
       0032  __start
       0052  _exit
       0053  _Delay
       0069  _Spi_initial
       006C  _SpiReadSpiWrite
       0071  _system_Init
       007A  _Config905
       0091  _TxPacket
       00C2  _SetTxMode
       00C8  _main
       0118  pop_gset2
       011B  push_gset5
       011D  push_gset4
       011F  push_gset3
       0121  push_gset2
       0123  push_gset1
       0126  pop_gset1
       0127  pop
       013A  __text_end

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
                             bss   006F   0004 =      4. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       006F  __bss_start
       006F  _TxRxBuf
       0073  __bss_end

Area                               Start  End    Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                          vector   0000   0004 =      4. bytes (abs,ovr,rom)

Files Linked      [ module(s) ]

C:\iccv7avr\lib\crtatmega.o	[ crtatmega.s ]
jfp_fasong.o	[ jfp_fasong.c ]
<library>	[ gpop2.s, gpush.s ]

User Global Definitions

ram_end = 0x45f
hwstk_size = 0x10

User Base Address Definitions

func_lit = 0x54
data = 0x60
eeprom:1.512

