NOTE: AVR Code addresses are word addresses
All other addresses (including ones in FLASH) are byte addresses

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                        func_lit   0026   0022 =     34. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       0026  __func_lit_start
       0048  __func_lit_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                             lit   0048   0016 =     22. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       0048  __lit_start
       005E  __lit_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                           idata   005E   0064 =    100. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       005E  __idata_start
       00C2  __idata_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            text   00C2   1286 =   4742. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       0061  __start
       0061  __text_start
       0080  _exit
       0081  _spi_init
       0084  _print_temp
       0208  _main
       02FC  _int0_isr
       0331  _display4
       03B1  _displaybyte
       03D3  _displayint
       03E0  _displaybyte2
       03F7  _display_char
       0417  _display_int
       0434  _delay
       043F  _lcd_send_byte
       045F  _lcd_write_data
       0474  _lcd_write_comm
       0489  _lcd_initial
       0494  _screen
       04C2  _fanxian
       0534  _nrf905_Config
       0562  _nrf905_SpiRW
       056A  _nrf905_StandBy
       056E  _nrf905_Off
       0570  _nrf905_TxOn
       0574  _nrf905_TxSend
       057A  _nrf905_RxOn
       057E  _nrf905_Init
       0585  _nrf905_SpiTest
       059A  _nrf905_SetTxAddr
       05A7  _nrf905_SetData
       05BB  _nrf905_WaitSended
       05BE  _nrf905_SendData
       05C5  _nrf905_SendAgain
       05CA  _nrf905_ReadData
       05DF  _RfRecvProc
       05E6  _RfSendProc
       05E9  _DelayMs
       05F5  _DelayUs
       0600  _DelayUS
       0608  _DelayMS
       0615  _DisInit
       061B  _Check18B20
       0636  _Read18B20
       0659  _Write18B20
       067D  _GetTemp
       06B6  _timer0_init
       06BD  _timer0_ovf_isr
       06F7  push_arg4
       06F9  push_arg2
       06FC  mod16s
       0700  div16s
       0719  mod16u
       071B  div16u
       071C  xdiv16u
       0735  div32u
       0737  mod32u
       073B  div32s
       073D  mod32s
       0768  long_div_prolog
       077B  long_div_epilog
       078A  tst_R16_R19
       078F  tst_R24_R27
       0794  neg_R16_R19
       079D  neg_R24_R27
       07A6  empy16s
       07B6  pop_gset2
       07B8  pop_gset3
       07BA  pop_gset5
       07BC  push_gset5
       07BE  push_gset4
       07C0  push_gset3
       07C2  push_gset2
       07C4  push_gset1
       07C7  pop_gset1
       07C8  pop
       07DB  neg32
       07E4  lpm32
       07F8  fp2int
       07FF  nojump1
       0803  fp2long
       0808  nojump2
       0809  FTOI
       080B  FTOL
       0836  int2fp
       083C  long2fp
       083F  ITOF
       0851  itof2
       0853  itof3
       0861  save_floatregs
       086C  restore_floatregs
       0877  stk2arg1
       087C  stk2arg0
       0881  float_epilog
       0888  float_prolog
       088B  add32fs
       088D  add32f
       0890  sub32fs
       0892  sub32f
       0895  fret2
       089B  FSUB
       089C  FADD
       08DB  usub24
       08DF  cmp32f
       08E2  FLTCP
       090E  empy32fs
       0910  empy32f
       0917  eFMUL
       092D  eumul24
       0956  savfacc1
       0959  restorefacc1
       095C  unpackfacc1
       0965  negmant
       096B  maxres
       0972  minres
       0978  ac1toac2
       097E  swapacc
       098A  unpack
       099C  repack
       09A4  __text_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            data   0060   0064 =    100. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0060  _hz0
       0060  __data_start
       00A1  _times
       00A2  _TxBuf
       00C4  __data_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                             bss   00C4   0027 =     39. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       00C4  __bss_start
       00C5  _set_data
       00C6  _value_T
       00C7  _KeyFlag
       00C8  _KeyV
       00C9  _RxBuf
       00E9  _delaytime
       00EB  __bss_end

Area                               Start  End    Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                          vector   0000   0014 =     20. bytes (abs,ovr,rom)

Files Linked      [ module(s) ]

D:\icc\lib\crtAVR.o	[ crtavr.s ]
main.o	[ main.c ]
display.o	[ display.c ]
lcd.o	[ lcd.c ]
nrf905config.o	[ nrf905config.c ]
b20.o	[ b20.c ]
timer.o	[ timer.c ]
<library>	[ asave.s, div16s.s, div16u.s, div32.s, emul16s.s, gpop2.s, gpop3.s, gpop5.s, gpush.s, lneg.s, lpm32.s ]
[ fp2int.s, fpint2fp.s, fputil.s, fpadd.s, fpcmp.s, fpemul.s, fputil2.s, fputil3.s ]

User Global Definitions

ram_end = 0x45f
hwstk_size = 0x1e

User Base Address Definitions

func_lit = 0x26
data = 0x60
eeprom:1.512

