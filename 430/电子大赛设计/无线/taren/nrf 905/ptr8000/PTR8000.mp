NOTE: AVR Code addresses are word addresses
All other addresses (including ones in FLASH) are byte addresses

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            text   0054   03F4 =   1012. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       002A  __text_start
       002A  __start
       004A  _exit
       004B  _nrf905_Config
       007B  _nrf905_SpiRW
       0085  _nrf905_StandBy
       0089  _nrf905_Off
       008B  _nrf905_TxOn
       008F  _nrf905_TxSend
       0096  _nrf905_RxOn
       009A  _nrf905_Init
       00A2  _nrf905_SpiTest
       00B9  _nrf905_SetTxAddr
       00C6  _nrf905_SetData
       00DC  _nrf905_WaitSended
       00DF  _nrf905_SendData
       00E5  _nrf905_SendAgain
       00E9  _nrf905_ReadData
       0100  _port_init
       0110  _timer0_init
       0119  _timer0_ovf_isr
       0140  _timer1_init
       0156  _timer1_ovf_isr
       0161  _spi_init
       0168  _spi_stc_isr
       0169  _uart0_init
       0174  _init_devices
       0181  _main
       0196  _RfRecvProc
       01B8  _RfSendProc
       01CF  _TimerFunc
       01DA  _SystemIni
       01E1  _DelayMs
       01EF  _DelayUs
       0202  pop_gset2
       0205  push_gset5
       0207  push_gset4
       0209  push_gset3
       020B  push_gset2
       020D  push_gset1
       0210  pop_gset1
       0211  pop
       0224  __text_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                             bss   0060   0044 =     68. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0060  _RxBuf
       0060  __bss_start
       0080  _TxBuf
       00A0  _RfCnt
       00A1  _T0Cnt
       00A2  _bRfSend
       00A3  _bTimer
       00A4  __bss_end

Area                               Start  End    Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                          vector   0000   002C =     44. bytes (abs,ovr,rom)

Files Linked      [ module(s) ]

D:\iccavr\lib\crtatmega.o	[ crtatmega.s ]
nrf905.o	[ nrf905.C ]
PTR8000.o	[ PTR8000.C ]
<library>	[ gpop2.s, gpush.s ]

User Global Definitions

ram_end = 0x45f
hwstk_size = 0x10

User Base Address Definitions

func_lit = 0x54
data = 0x60
eeprom:1.512

