#line 1 "E:\\AllProject\\430\\G2231_Self\\main.c"
#line 1 "D:\\Program Files\\IAR Systems\\Embedded Workbench 6.0 Evaluation\\430\\inc\\io430.h"

/********************************************************************
 *
 * This file is a generic include file controlled by 
 * compiler/assembler IDE generated defines
 *
 * Copyright 1996-2011 IAR Systems AB.
 * $Revision: 7792 $
 *
 ********************************************************************/

/********************************************************************
 *  msp430x1xx family 
 ********************************************************************/





#pragma system_include


#line 1 "D:\\Program Files\\IAR Systems\\Embedded Workbench 6.0 Evaluation\\430\\inc\\io430G2231.h"
/********************************************************************
 *
 * Standard register and bit definitions for the Texas Instruments
 * MSP430 microcontroller.
 *
 * This file supports assembler and C/EC++ development for
 * msp430g2231 devices.
 *
 * Copyright 2010-2011 IAR Systems AB.
 *
 *
 *
 ********************************************************************/






#line 1 "D:\\Program Files\\IAR Systems\\Embedded Workbench 6.0 Evaluation\\430\\inc\\intrinsics.h"
/**************************************************
 *
 * Intrinsic functions for the IAR Embedded Workbench for MSP430.
 *
 * Copyright © 2002-2008 IAR Systems AB.
 *
 * $Revision: 5178 $
 *
 **************************************************/





  #pragma system_include


#pragma language=save
#pragma language=extended


/*
 * The return value of "__get_interrupt_state".
 */

typedef unsigned short istate_t;






  __intrinsic void __no_operation(void);
  __intrinsic void __enable_interrupt(void);
  __intrinsic void __disable_interrupt(void);

  __intrinsic istate_t __get_interrupt_state(void);
  __intrinsic void     __set_interrupt_state(istate_t);

  __intrinsic void __op_code(unsigned short);

  __intrinsic unsigned short __swap_bytes(unsigned short);

  __intrinsic void           __bic_SR_register(unsigned short);
  __intrinsic void           __bis_SR_register(unsigned short);
  __intrinsic unsigned short __get_SR_register(void);

  __intrinsic void           __bic_SR_register_on_exit(unsigned short);
  __intrinsic void           __bis_SR_register_on_exit(unsigned short);
  __intrinsic unsigned short __get_SR_register_on_exit(void);

  __intrinsic unsigned short     __bcd_add_short(unsigned short,
                                                 unsigned short);

  __intrinsic unsigned long      __bcd_add_long (unsigned long,
                                                 unsigned long);

  __intrinsic unsigned long long __bcd_add_long_long(unsigned long long,
                                                     unsigned long long);

  /*
   * Support for efficient switch:es. E.g. switch(__even_in_range(x, 10))
   *
   * Note that the value must be even and in the range from 0 to
   * __bound, inclusive. No code will be generated that checks this.
   *
   * This is typically used inside interrupt dispatch functions, to
   * switch on special processor registers like TAIV.
   */

  __intrinsic unsigned short __even_in_range(unsigned short __value,
                                             unsigned short __bound);

  /* Insert a delay with a specific number of cycles. */
  __intrinsic void __delay_cycles(unsigned long __cycles);

  /*
   * The following R4/R5 intrinsic functions are only available when
   * the corresponding register is locked.
   */

  __intrinsic unsigned short __get_R4_register(void);
  __intrinsic void           __set_R4_register(unsigned short);

  __intrinsic unsigned short __get_R5_register(void);
  __intrinsic void           __set_R5_register(unsigned short);

  __intrinsic unsigned short __get_SP_register(void);
  __intrinsic void           __set_SP_register(unsigned short);


  /*
   * If the application provides this function, it is called by the
   * startup code before variables are initialized. If the function
   * returns 0 the data segments will not be initialized.
   */
  __intrinsic int __low_level_init(void);


  /* ----------------------------------------
   * MSP430X-specific intrinsic functions.
   */

  /*
   * Intrinsic functions to allow access to the full 1 Mbyte memory
   * range in small data model.
   *
   * The functions are available in medium and large data model
   * aswell, however it is recommended to access memory using normal
   * __data20 variables and/or pointers.
   *
   * Please note that interrupts must be disabled when the following
   * intrinsics are used.
   */

  __intrinsic void __data20_write_char (unsigned long  __addr,
                                        unsigned char  __value);

  __intrinsic void __data20_write_short(unsigned long  __addr,
                                        unsigned short __value);

  __intrinsic void __data20_write_long (unsigned long  __addr,
                                        unsigned long  __value);

  __intrinsic unsigned char  __data20_read_char (unsigned long __addr);
  __intrinsic unsigned short __data20_read_short(unsigned long __addr);
  __intrinsic unsigned long  __data20_read_long (unsigned long __addr);

  /*
   * The following two functions can be used to access 20-bit SFRs in the
   * lower 64kB. They are only available in extended mode (--core=430X).
   */
  __intrinsic void __data16_write_addr (unsigned short __addr,
                                        unsigned long  __value);

  __intrinsic unsigned long  __data16_read_addr (unsigned short __addr);







/*
 * Alias for locations used for global register variables.  For example,
 * "__no_init __regvar int x @ __R4;".
 */




/*
 * Control bits in the processor status register, SR.
 */








/*
 * Functions for controlling the processor operation modes.
 */


















#line 190 "D:\\Program Files\\IAR Systems\\Embedded Workbench 6.0 Evaluation\\430\\inc\\intrinsics.h"








#pragma language=restore

#line 21 "D:\\Program Files\\IAR Systems\\Embedded Workbench 6.0 Evaluation\\430\\inc\\io430G2231.h"

#pragma system_include









#pragma language=save
#pragma language=extended









/*-------------------------------------------------------------------------
 *   Standard Bits
 *-------------------------------------------------------------------------*/

#line 63 "D:\\Program Files\\IAR Systems\\Embedded Workbench 6.0 Evaluation\\430\\inc\\io430G2231.h"

/*-------------------------------------------------------------------------
 *   Status register bits
 *-------------------------------------------------------------------------*/

#line 77 "D:\\Program Files\\IAR Systems\\Embedded Workbench 6.0 Evaluation\\430\\inc\\io430G2231.h"

/* Low Power Modes coded with Bits 4-7 in SR */








#line 97 "D:\\Program Files\\IAR Systems\\Embedded Workbench 6.0 Evaluation\\430\\inc\\io430G2231.h"



/*-------------------------------------------------------------------------
 *   Special Function
 *-------------------------------------------------------------------------*/


__no_init volatile union
{
  unsigned char IE1;   /* Interrupt Enable 1 */

  struct
  {
    unsigned char WDTIE           : 1; /* Watchdog Interrupt Enable */
    unsigned char OFIE            : 1; /* Osc. Fault  Interrupt Enable */
    unsigned char                : 2;
    unsigned char NMIIE           : 1; /* NMI Interrupt Enable */
    unsigned char ACCVIE          : 1; /* Flash Access Violation Interrupt Enable */
  }IE1_bit;
} @0x0000;


enum {
  WDTIE           = 0x0001,
  OFIE            = 0x0002,
  NMIIE           = 0x0010,
  ACCVIE          = 0x0020
};


__no_init volatile union
{
  unsigned char IFG1;   /* Interrupt Flag 1 */

  struct
  {
    unsigned char WDTIFG          : 1; /* Watchdog Interrupt Flag */
    unsigned char OFIFG           : 1; /* Osc. Fault Interrupt Flag */
    unsigned char PORIFG          : 1; /* Power On Interrupt Flag */
    unsigned char RSTIFG          : 1; /* Reset Interrupt Flag */
    unsigned char NMIIFG          : 1; /* NMI Interrupt Flag */
  }IFG1_bit;
} @ 0x0002;


enum {
  WDTIFG          = 0x0001,
  OFIFG           = 0x0002,
  PORIFG          = 0x0004,
  RSTIFG          = 0x0008,
  NMIIFG          = 0x0010
};



/*-------------------------------------------------------------------------
 *   ADC10
 *-------------------------------------------------------------------------*/


__no_init volatile union
{
  unsigned char ADC10DTC0;   /* ADC10 Data Transfer Control 0 */

  struct
  {
    unsigned char ADC10FETCH      : 1; /* This bit should normally be reset */
    unsigned char ADC10B1         : 1; /* ADC10 block one */
    unsigned char ADC10CT         : 1; /* ADC10 continuous transfer */
    unsigned char ADC10TB         : 1; /* ADC10 two-block mode */
  }ADC10DTC0_bit;
} @0x0048;


enum {
  ADC10FETCH      = 0x0001,
  ADC10B1         = 0x0002,
  ADC10CT         = 0x0004,
  ADC10TB         = 0x0008
};


  /* ADC10 Data Transfer Control 1 */
__no_init volatile unsigned char ADC10DTC1 @ 0x0049;


  /* ADC10 Analog Enable 0 */
__no_init volatile unsigned char ADC10AE0 @ 0x004A;


__no_init volatile union
{
  unsigned short ADC10CTL0;   /* ADC10 Control 0 */

  struct
  {
    unsigned short ADC10SC         : 1; /* ADC10 Start Conversion */
    unsigned short ENC             : 1; /* ADC10 Enable Conversion */
    unsigned short ADC10IFG        : 1; /* ADC10 Interrupt Flag */
    unsigned short ADC10IE         : 1; /* ADC10 Interrupt Enalbe */
    unsigned short ADC10ON         : 1; /* ADC10 On/Enable */
    unsigned short REFON           : 1; /* ADC10 Reference on */
    unsigned short REF2_5V         : 1; /*  */
    unsigned short MSC             : 1; /* ADC10 Multiple SampleConversion */
    unsigned short REFBURST        : 1; /* ADC10 Reference Burst Mode */
    unsigned short REFOUT          : 1; /* ADC10 Enalbe output of Ref. */
    unsigned short ADC10SR         : 1; /* ADC10 Sampling Rate 0:200ksps / 1:50ksps */
    unsigned short ADC10SHT0       : 1; /* ADC10 Sample Hold Select Bit: 0 */
    unsigned short ADC10SHT1       : 1; /* ADC10 Sample Hold Select Bit: 1 */
    unsigned short SREF0           : 1; /* ADC10 Reference Select Bit: 0 */
    unsigned short SREF1           : 1; /* ADC10 Reference Select Bit: 1 */
    unsigned short SREF2           : 1; /* ADC10 Reference Select Bit: 2 */
  }ADC10CTL0_bit;
} @0x01B0;


enum {
  ADC10SC         = 0x0001,
  ENC             = 0x0002,
  ADC10IFG        = 0x0004,
  ADC10IE         = 0x0008,
  ADC10ON         = 0x0010,
  REFON           = 0x0020,
  REF2_5V         = 0x0040,
  MSC             = 0x0080,
  REFBURST        = 0x0100,
  REFOUT          = 0x0200,
  ADC10SR         = 0x0400,
  ADC10SHT0       = 0x0800,
  ADC10SHT1       = 0x1000,
  SREF0           = 0x2000,
  SREF1           = 0x4000,
  SREF2           = 0x8000
};


__no_init volatile union
{
  unsigned short ADC10CTL1;   /* ADC10 Control 1 */

  struct
  {
    unsigned short ADC10BUSY       : 1; /* ADC10 BUSY */
    unsigned short CONSEQ0         : 1; /* ADC10 Conversion Sequence Select 0 */
    unsigned short CONSEQ1         : 1; /* ADC10 Conversion Sequence Select 1 */
    unsigned short ADC10SSEL0      : 1; /* ADC10 Clock Source Select Bit: 0 */
    unsigned short ADC10SSEL1      : 1; /* ADC10 Clock Source Select Bit: 1 */
    unsigned short ADC10DIV0       : 1; /* ADC10 Clock Divider Select Bit: 0 */
    unsigned short ADC10DIV1       : 1; /* ADC10 Clock Divider Select Bit: 1 */
    unsigned short ADC10DIV2       : 1; /* ADC10 Clock Divider Select Bit: 2 */
    unsigned short ISSH            : 1; /* ADC10 Invert Sample Hold Signal */
    unsigned short ADC10DF         : 1; /* ADC10 Data Format 0:binary 1:2's complement */
    unsigned short SHS0            : 1; /* ADC10 Sample/Hold Source Bit: 0 */
    unsigned short SHS1            : 1; /* ADC10 Sample/Hold Source Bit: 1 */
    unsigned short INCH0           : 1; /* ADC10 Input Channel Select Bit: 0 */
    unsigned short INCH1           : 1; /* ADC10 Input Channel Select Bit: 1 */
    unsigned short INCH2           : 1; /* ADC10 Input Channel Select Bit: 2 */
    unsigned short INCH3           : 1; /* ADC10 Input Channel Select Bit: 3 */
  }ADC10CTL1_bit;
} @0x01B2;


enum {
  ADC10BUSY       = 0x0001,
  CONSEQ0         = 0x0002,
  CONSEQ1         = 0x0004,
  ADC10SSEL0      = 0x0008,
  ADC10SSEL1      = 0x0010,
  ADC10DIV0       = 0x0020,
  ADC10DIV1       = 0x0040,
  ADC10DIV2       = 0x0080,
  ISSH            = 0x0100,
  ADC10DF         = 0x0200,
  SHS0            = 0x0400,
  SHS1            = 0x0800,
  INCH0           = 0x1000,
  INCH1           = 0x2000,
  INCH2           = 0x4000,
  INCH3           = 0x8000
};


  /* ADC10 Memory */
__no_init volatile unsigned short ADC10MEM @ 0x01B4;


  /* ADC10 Data Transfer Start Address */
__no_init volatile unsigned short ADC10SA @ 0x01BC;









#line 303 "D:\\Program Files\\IAR Systems\\Embedded Workbench 6.0 Evaluation\\430\\inc\\io430G2231.h"











#line 322 "D:\\Program Files\\IAR Systems\\Embedded Workbench 6.0 Evaluation\\430\\inc\\io430G2231.h"






#line 345 "D:\\Program Files\\IAR Systems\\Embedded Workbench 6.0 Evaluation\\430\\inc\\io430G2231.h"

/*-------------------------------------------------------------------------
 *   System Clock
 *-------------------------------------------------------------------------*/


__no_init volatile union
{
  unsigned char DCOCTL;   /* DCO Clock Frequency Control */

  struct
  {
    unsigned char MOD0            : 1; /* Modulation Bit 0 */
    unsigned char MOD1            : 1; /* Modulation Bit 1 */
    unsigned char MOD2            : 1; /* Modulation Bit 2 */
    unsigned char MOD3            : 1; /* Modulation Bit 3 */
    unsigned char MOD4            : 1; /* Modulation Bit 4 */
    unsigned char DCO0            : 1; /* DCO Select Bit 0 */
    unsigned char DCO1            : 1; /* DCO Select Bit 1 */
    unsigned char DCO2            : 1; /* DCO Select Bit 2 */
  }DCOCTL_bit;
} @0x0056;


enum {
  MOD0            = 0x0001,
  MOD1            = 0x0002,
  MOD2            = 0x0004,
  MOD3            = 0x0008,
  MOD4            = 0x0010,
  DCO0            = 0x0020,
  DCO1            = 0x0040,
  DCO2            = 0x0080
};


__no_init volatile union
{
  unsigned char BCSCTL1;   /* Basic Clock System Control 1 */

  struct
  {
    unsigned char RSEL0           : 1; /* Range Select Bit 0 */
    unsigned char RSEL1           : 1; /* Range Select Bit 1 */
    unsigned char RSEL2           : 1; /* Range Select Bit 2 */
    unsigned char RSEL3           : 1; /* Range Select Bit 3 */
    unsigned char DIVA0           : 1; /* ACLK Divider 0 */
    unsigned char DIVA1           : 1; /* ACLK Divider 1 */
    unsigned char XTS             : 1; /* LFXTCLK 0:Low Freq. / 1: High Freq. */
    unsigned char XT2OFF          : 1; /* Enable XT2CLK */
  }BCSCTL1_bit;
} @0x0057;


enum {
  RSEL0           = 0x0001,
  RSEL1           = 0x0002,
  RSEL2           = 0x0004,
  RSEL3           = 0x0008,
  DIVA0           = 0x0010,
  DIVA1           = 0x0020,
  XTS             = 0x0040,
  XT2OFF          = 0x0080
};


__no_init volatile union
{
  unsigned char BCSCTL2;   /* Basic Clock System Control 2 */

  struct
  {
    unsigned char                : 1;
    unsigned char DIVS0           : 1; /* SMCLK Divider 0 */
    unsigned char DIVS1           : 1; /* SMCLK Divider 1 */
    unsigned char SELS            : 1; /* SMCLK Source Select 0:DCOCLK / 1:XT2CLK/LFXTCLK */
    unsigned char DIVM0           : 1; /* MCLK Divider 0 */
    unsigned char DIVM1           : 1; /* MCLK Divider 1 */
    unsigned char SELM0           : 1; /* MCLK Source Select 0 */
    unsigned char SELM1           : 1; /* MCLK Source Select 1 */
  }BCSCTL2_bit;
} @0x0058;


enum {
  DIVS0           = 0x0002,
  DIVS1           = 0x0004,
  SELS            = 0x0008,
  DIVM0           = 0x0010,
  DIVM1           = 0x0020,
  SELM0           = 0x0040,
  SELM1           = 0x0080
};


__no_init volatile union
{
  unsigned char BCSCTL3;   /* Basic Clock System Control 3 */

  struct
  {
    unsigned char LFXT1OF         : 1; /* Low/high Frequency Oscillator Fault Flag */
    unsigned char XT2OF           : 1; /* High frequency oscillator 2 fault flag */
    unsigned char XCAP0           : 1; /* XIN/XOUT Cap 0 */
    unsigned char XCAP1           : 1; /* XIN/XOUT Cap 1 */
    unsigned char LFXT1S0         : 1; /* Mode 0 for LFXT1 (XTS = 0) */
    unsigned char LFXT1S1         : 1; /* Mode 1 for LFXT1 (XTS = 0) */
    unsigned char XT2S0           : 1; /* Mode 0 for XT2 */
    unsigned char XT2S1           : 1; /* Mode 1 for XT2 */
  }BCSCTL3_bit;
} @ 0x0053;


enum {
  LFXT1OF         = 0x0001,
  XT2OF           = 0x0002,
  XCAP0           = 0x0004,
  XCAP1           = 0x0008,
  LFXT1S0         = 0x0010,
  LFXT1S1         = 0x0020,
  XT2S0           = 0x0040,
  XT2S1           = 0x0080
};









































/*-------------------------------------------------------------------------
 *   Flash
 *-------------------------------------------------------------------------*/


__no_init volatile union
{
  unsigned short FCTL1;   /* FLASH Control 1 */

  struct
  {
    unsigned short                : 1;
    unsigned short ERASE           : 1; /* Enable bit for Flash segment erase */
    unsigned short MERAS           : 1; /* Enable bit for Flash mass erase */
    unsigned short                : 3;
    unsigned short WRT             : 1; /* Enable bit for Flash write */
    unsigned short BLKWRT          : 1; /* Enable bit for Flash segment write */
  }FCTL1_bit;
} @0x0128;


enum {
  ERASE           = 0x0002,
  MERAS           = 0x0004,
  WRT             = 0x0040,
  BLKWRT          = 0x0080
};


__no_init volatile union
{
  unsigned short FCTL2;   /* FLASH Control 2 */

  struct
  {
    unsigned short FN0             : 1; /* Divide Flash clock by 1 to 64 using FN0 to FN5 according to: */
    unsigned short FN1             : 1; /* 32*FN5 + 16*FN4 + 8*FN3 + 4*FN2 + 2*FN1 + FN0 + 1 */
    unsigned short FN2             : 1; /*  */
    unsigned short FN3             : 1; /*  */
    unsigned short FN4             : 1; /*  */
    unsigned short FN5             : 1; /*  */
    unsigned short FSSEL0          : 1; /* Flash clock select 0 */        /* to distinguish from USART SSELx */
    unsigned short FSSEL1          : 1; /* Flash clock select 1 */
  }FCTL2_bit;
} @0x012A;


enum {
  FN0             = 0x0001,
  FN1             = 0x0002,
  FN2             = 0x0004,
  FN3             = 0x0008,
  FN4             = 0x0010,
  FN5             = 0x0020,
  FSSEL0          = 0x0040,
  FSSEL1          = 0x0080
};


__no_init volatile union
{
  unsigned short FCTL3;   /* FLASH Control 3 */

  struct
  {
    unsigned short BUSY            : 1; /* Flash busy: 1 */
    unsigned short KEYV            : 1; /* Flash Key violation flag */
    unsigned short ACCVIFG         : 1; /* Flash Access violation flag */
    unsigned short WAIT            : 1; /* Wait flag for segment write */
    unsigned short LOCK            : 1; /* Lock bit: 1 - Flash is locked (read only) */
    unsigned short EMEX            : 1; /* Flash Emergency Exit */
    unsigned short LOCKA           : 1; /* Segment A Lock bit: read = 1 - Segment is locked (read only) */
    unsigned short FAIL            : 1; /* Last Program or Erase failed */
  }FCTL3_bit;
} @ 0x012C;


enum {
  BUSY            = 0x0001,
  KEYV            = 0x0002,
  ACCVIFG         = 0x0004,
  WAIT            = 0x0008,
  LOCK            = 0x0010,
  EMEX            = 0x0020,
  LOCKA           = 0x0040,
  FAIL            = 0x0080
};

















/*-------------------------------------------------------------------------
 *   Port 1/2
 *-------------------------------------------------------------------------*/


__no_init volatile union
{
  unsigned const char P1IN;   /* Port 1 Input */

  struct
  {
    unsigned const char P0              : 1; /*  */
    unsigned const char P1              : 1; /*  */
    unsigned const char P2              : 1; /*  */
    unsigned const char P3              : 1; /*  */
    unsigned const char P4              : 1; /*  */
    unsigned const char P5              : 1; /*  */
    unsigned const char P6              : 1; /*  */
    unsigned const char P7              : 1; /*  */
  }P1IN_bit;
} @0x0020;


enum {
  P0              = 0x0001,
  P1              = 0x0002,
  P2              = 0x0004,
  P3              = 0x0008,
  P4              = 0x0010,
  P5              = 0x0020,
  P6              = 0x0040,
  P7              = 0x0080
};


__no_init volatile union
{
  unsigned char P1OUT;   /* Port 1 Output */

  struct
  {
    unsigned char P0              : 1; /*  */
    unsigned char P1              : 1; /*  */
    unsigned char P2              : 1; /*  */
    unsigned char P3              : 1; /*  */
    unsigned char P4              : 1; /*  */
    unsigned char P5              : 1; /*  */
    unsigned char P6              : 1; /*  */
    unsigned char P7              : 1; /*  */
  }P1OUT_bit;
} @0x0021;


/*
enum {
  P0              = 0x0001,
  P1              = 0x0002,
  P2              = 0x0004,
  P3              = 0x0008,
  P4              = 0x0010,
  P5              = 0x0020,
  P6              = 0x0040,
  P7              = 0x0080,
};
*/


__no_init volatile union
{
  unsigned char P1DIR;   /* Port 1 Direction */

  struct
  {
    unsigned char P0              : 1; /*  */
    unsigned char P1              : 1; /*  */
    unsigned char P2              : 1; /*  */
    unsigned char P3              : 1; /*  */
    unsigned char P4              : 1; /*  */
    unsigned char P5              : 1; /*  */
    unsigned char P6              : 1; /*  */
    unsigned char P7              : 1; /*  */
  }P1DIR_bit;
} @0x0022;


/*
enum {
  P0              = 0x0001,
  P1              = 0x0002,
  P2              = 0x0004,
  P3              = 0x0008,
  P4              = 0x0010,
  P5              = 0x0020,
  P6              = 0x0040,
  P7              = 0x0080,
};
*/


__no_init volatile union
{
  unsigned char P1IFG;   /* Port 1 Interrupt Flag */

  struct
  {
    unsigned char P0              : 1; /*  */
    unsigned char P1              : 1; /*  */
    unsigned char P2              : 1; /*  */
    unsigned char P3              : 1; /*  */
    unsigned char P4              : 1; /*  */
    unsigned char P5              : 1; /*  */
    unsigned char P6              : 1; /*  */
    unsigned char P7              : 1; /*  */
  }P1IFG_bit;
} @0x0023;


/*
enum {
  P0              = 0x0001,
  P1              = 0x0002,
  P2              = 0x0004,
  P3              = 0x0008,
  P4              = 0x0010,
  P5              = 0x0020,
  P6              = 0x0040,
  P7              = 0x0080,
};
*/


__no_init volatile union
{
  unsigned char P1IES;   /* Port 1 Interrupt Edge Select */

  struct
  {
    unsigned char P0              : 1; /*  */
    unsigned char P1              : 1; /*  */
    unsigned char P2              : 1; /*  */
    unsigned char P3              : 1; /*  */
    unsigned char P4              : 1; /*  */
    unsigned char P5              : 1; /*  */
    unsigned char P6              : 1; /*  */
    unsigned char P7              : 1; /*  */
  }P1IES_bit;
} @0x0024;


/*
enum {
  P0              = 0x0001,
  P1              = 0x0002,
  P2              = 0x0004,
  P3              = 0x0008,
  P4              = 0x0010,
  P5              = 0x0020,
  P6              = 0x0040,
  P7              = 0x0080,
};
*/


__no_init volatile union
{
  unsigned char P1IE;   /* Port 1 Interrupt Enable */

  struct
  {
    unsigned char P0              : 1; /*  */
    unsigned char P1              : 1; /*  */
    unsigned char P2              : 1; /*  */
    unsigned char P3              : 1; /*  */
    unsigned char P4              : 1; /*  */
    unsigned char P5              : 1; /*  */
    unsigned char P6              : 1; /*  */
    unsigned char P7              : 1; /*  */
  }P1IE_bit;
} @0x0025;


/*
enum {
  P0              = 0x0001,
  P1              = 0x0002,
  P2              = 0x0004,
  P3              = 0x0008,
  P4              = 0x0010,
  P5              = 0x0020,
  P6              = 0x0040,
  P7              = 0x0080,
};
*/


__no_init volatile union
{
  unsigned char P1SEL;   /* Port 1 Selection */

  struct
  {
    unsigned char P0              : 1; /*  */
    unsigned char P1              : 1; /*  */
    unsigned char P2              : 1; /*  */
    unsigned char P3              : 1; /*  */
    unsigned char P4              : 1; /*  */
    unsigned char P5              : 1; /*  */
    unsigned char P6              : 1; /*  */
    unsigned char P7              : 1; /*  */
  }P1SEL_bit;
} @0x0026;


/*
enum {
  P0              = 0x0001,
  P1              = 0x0002,
  P2              = 0x0004,
  P3              = 0x0008,
  P4              = 0x0010,
  P5              = 0x0020,
  P6              = 0x0040,
  P7              = 0x0080,
};
*/


__no_init volatile union
{
  unsigned char P1REN;   /* Port 1 Resistor Enable */

  struct
  {
    unsigned char P0              : 1; /*  */
    unsigned char P1              : 1; /*  */
    unsigned char P2              : 1; /*  */
    unsigned char P3              : 1; /*  */
    unsigned char P4              : 1; /*  */
    unsigned char P5              : 1; /*  */
    unsigned char P6              : 1; /*  */
    unsigned char P7              : 1; /*  */
  }P1REN_bit;
} @0x0027;


/*
enum {
  P0              = 0x0001,
  P1              = 0x0002,
  P2              = 0x0004,
  P3              = 0x0008,
  P4              = 0x0010,
  P5              = 0x0020,
  P6              = 0x0040,
  P7              = 0x0080,
};
*/


__no_init volatile union
{
  unsigned const char P2IN;   /* Port 2 Input */

  struct
  {
    unsigned const char P0              : 1; /*  */
    unsigned const char P1              : 1; /*  */
    unsigned const char P2              : 1; /*  */
    unsigned const char P3              : 1; /*  */
    unsigned const char P4              : 1; /*  */
    unsigned const char P5              : 1; /*  */
    unsigned const char P6              : 1; /*  */
    unsigned const char P7              : 1; /*  */
  }P2IN_bit;
} @0x0028;


/*
enum {
  P0              = 0x0001,
  P1              = 0x0002,
  P2              = 0x0004,
  P3              = 0x0008,
  P4              = 0x0010,
  P5              = 0x0020,
  P6              = 0x0040,
  P7              = 0x0080,
};
*/


__no_init volatile union
{
  unsigned char P2OUT;   /* Port 2 Output */

  struct
  {
    unsigned char P0              : 1; /*  */
    unsigned char P1              : 1; /*  */
    unsigned char P2              : 1; /*  */
    unsigned char P3              : 1; /*  */
    unsigned char P4              : 1; /*  */
    unsigned char P5              : 1; /*  */
    unsigned char P6              : 1; /*  */
    unsigned char P7              : 1; /*  */
  }P2OUT_bit;
} @0x0029;


/*
enum {
  P0              = 0x0001,
  P1              = 0x0002,
  P2              = 0x0004,
  P3              = 0x0008,
  P4              = 0x0010,
  P5              = 0x0020,
  P6              = 0x0040,
  P7              = 0x0080,
};
*/


__no_init volatile union
{
  unsigned char P2DIR;   /* Port 2 Direction */

  struct
  {
    unsigned char P0              : 1; /*  */
    unsigned char P1              : 1; /*  */
    unsigned char P2              : 1; /*  */
    unsigned char P3              : 1; /*  */
    unsigned char P4              : 1; /*  */
    unsigned char P5              : 1; /*  */
    unsigned char P6              : 1; /*  */
    unsigned char P7              : 1; /*  */
  }P2DIR_bit;
} @0x002A;


/*
enum {
  P0              = 0x0001,
  P1              = 0x0002,
  P2              = 0x0004,
  P3              = 0x0008,
  P4              = 0x0010,
  P5              = 0x0020,
  P6              = 0x0040,
  P7              = 0x0080,
};
*/


__no_init volatile union
{
  unsigned char P2IFG;   /* Port 2 Interrupt Flag */

  struct
  {
    unsigned char P0              : 1; /*  */
    unsigned char P1              : 1; /*  */
    unsigned char P2              : 1; /*  */
    unsigned char P3              : 1; /*  */
    unsigned char P4              : 1; /*  */
    unsigned char P5              : 1; /*  */
    unsigned char P6              : 1; /*  */
    unsigned char P7              : 1; /*  */
  }P2IFG_bit;
} @0x002B;


/*
enum {
  P0              = 0x0001,
  P1              = 0x0002,
  P2              = 0x0004,
  P3              = 0x0008,
  P4              = 0x0010,
  P5              = 0x0020,
  P6              = 0x0040,
  P7              = 0x0080,
};
*/


__no_init volatile union
{
  unsigned char P2IES;   /* Port 2 Interrupt Edge Select */

  struct
  {
    unsigned char P0              : 1; /*  */
    unsigned char P1              : 1; /*  */
    unsigned char P2              : 1; /*  */
    unsigned char P3              : 1; /*  */
    unsigned char P4              : 1; /*  */
    unsigned char P5              : 1; /*  */
    unsigned char P6              : 1; /*  */
    unsigned char P7              : 1; /*  */
  }P2IES_bit;
} @0x002C;


/*
enum {
  P0              = 0x0001,
  P1              = 0x0002,
  P2              = 0x0004,
  P3              = 0x0008,
  P4              = 0x0010,
  P5              = 0x0020,
  P6              = 0x0040,
  P7              = 0x0080,
};
*/


__no_init volatile union
{
  unsigned char P2IE;   /* Port 2 Interrupt Enable */

  struct
  {
    unsigned char P0              : 1; /*  */
    unsigned char P1              : 1; /*  */
    unsigned char P2              : 1; /*  */
    unsigned char P3              : 1; /*  */
    unsigned char P4              : 1; /*  */
    unsigned char P5              : 1; /*  */
    unsigned char P6              : 1; /*  */
    unsigned char P7              : 1; /*  */
  }P2IE_bit;
} @0x002D;


/*
enum {
  P0              = 0x0001,
  P1              = 0x0002,
  P2              = 0x0004,
  P3              = 0x0008,
  P4              = 0x0010,
  P5              = 0x0020,
  P6              = 0x0040,
  P7              = 0x0080,
};
*/


__no_init volatile union
{
  unsigned char P2SEL;   /* Port 2 Selection */

  struct
  {
    unsigned char P0              : 1; /*  */
    unsigned char P1              : 1; /*  */
    unsigned char P2              : 1; /*  */
    unsigned char P3              : 1; /*  */
    unsigned char P4              : 1; /*  */
    unsigned char P5              : 1; /*  */
    unsigned char P6              : 1; /*  */
    unsigned char P7              : 1; /*  */
  }P2SEL_bit;
} @0x002E;


/*
enum {
  P0              = 0x0001,
  P1              = 0x0002,
  P2              = 0x0004,
  P3              = 0x0008,
  P4              = 0x0010,
  P5              = 0x0020,
  P6              = 0x0040,
  P7              = 0x0080,
};
*/


__no_init volatile union
{
  unsigned char P2REN;   /* Port 2 Resistor Enable */

  struct
  {
    unsigned char P0              : 1; /*  */
    unsigned char P1              : 1; /*  */
    unsigned char P2              : 1; /*  */
    unsigned char P3              : 1; /*  */
    unsigned char P4              : 1; /*  */
    unsigned char P5              : 1; /*  */
    unsigned char P6              : 1; /*  */
    unsigned char P7              : 1; /*  */
  }P2REN_bit;
} @ 0x002F;


/*
enum {
  P0              = 0x0001,
  P1              = 0x0002,
  P2              = 0x0004,
  P3              = 0x0008,
  P4              = 0x0010,
  P5              = 0x0020,
  P6              = 0x0040,
  P7              = 0x0080
};
*/









/*-------------------------------------------------------------------------
 *   Timer A2
 *-------------------------------------------------------------------------*/


  /* Timer A Interrupt Vector Word */
__no_init volatile unsigned const short TAIV @ 0x012E;


__no_init volatile union
{
  unsigned short TACTL;   /* Timer A Control */

  struct
  {
    unsigned short TAIFG           : 1; /* Timer A counter interrupt flag */
    unsigned short TAIE            : 1; /* Timer A counter interrupt enable */
    unsigned short TACLR           : 1; /* Timer A counter clear */
    unsigned short                : 1;
    unsigned short MC0             : 1; /* Timer A mode control 0 */
    unsigned short MC1             : 1; /* Timer A mode control 1 */
    unsigned short ID0             : 1; /* Timer A clock input divider 0 */
    unsigned short ID1             : 1; /* Timer A clock input divider 1 */
    unsigned short TASSEL0         : 1; /* Timer A clock source select 1 */
    unsigned short TASSEL1         : 1; /* Timer A clock source select 0 */
  }TACTL_bit;
} @0x0160;


enum {
  TAIFG           = 0x0001,
  TAIE            = 0x0002,
  TACLR           = 0x0004,
  MC0             = 0x0010,
  MC1             = 0x0020,
  ID0             = 0x0040,
  ID1             = 0x0080,
  TASSEL0         = 0x0100,
  TASSEL1         = 0x0200
};


__no_init volatile union
{
  unsigned short TACCTL0;   /* Timer A Capture/Compare Control 0 */

  struct
  {
    unsigned short CCIFG           : 1; /* Capture/compare interrupt flag */
    unsigned short COV             : 1; /* Capture/compare overflow flag */
    unsigned short OUT             : 1; /* PWM Output signal if output mode 0 */
    unsigned short CCI             : 1; /* Capture input signal (read) */
    unsigned short CCIE            : 1; /* Capture/compare interrupt enable */
    unsigned short OUTMOD0         : 1; /* Output mode 0 */
    unsigned short OUTMOD1         : 1; /* Output mode 1 */
    unsigned short OUTMOD2         : 1; /* Output mode 2 */
    unsigned short CAP             : 1; /* Capture mode: 1 /Compare mode : 0 */
    unsigned short                : 1;
    unsigned short SCCI            : 1; /* Latched capture signal (read) */
    unsigned short SCS             : 1; /* Capture sychronize */
    unsigned short CCIS0           : 1; /* Capture input select 0 */
    unsigned short CCIS1           : 1; /* Capture input select 1 */
    unsigned short CM0             : 1; /* Capture mode 0 */
    unsigned short CM1             : 1; /* Capture mode 1 */
  }TACCTL0_bit;
} @0x0162;


enum {
  CCIFG           = 0x0001,
  COV             = 0x0002,
  OUT             = 0x0004,
  CCI             = 0x0008,
  CCIE            = 0x0010,
  OUTMOD0         = 0x0020,
  OUTMOD1         = 0x0040,
  OUTMOD2         = 0x0080,
  CAP             = 0x0100,
  SCCI            = 0x0400,
  SCS             = 0x0800,
  CCIS0           = 0x1000,
  CCIS1           = 0x2000,
  CM0             = 0x4000,
  CM1             = 0x8000
};


__no_init volatile union
{
  unsigned short TACCTL1;   /* Timer A Capture/Compare Control 1 */

  struct
  {
    unsigned short CCIFG           : 1; /* Capture/compare interrupt flag */
    unsigned short COV             : 1; /* Capture/compare overflow flag */
    unsigned short OUT             : 1; /* PWM Output signal if output mode 0 */
    unsigned short CCI             : 1; /* Capture input signal (read) */
    unsigned short CCIE            : 1; /* Capture/compare interrupt enable */
    unsigned short OUTMOD0         : 1; /* Output mode 0 */
    unsigned short OUTMOD1         : 1; /* Output mode 1 */
    unsigned short OUTMOD2         : 1; /* Output mode 2 */
    unsigned short CAP             : 1; /* Capture mode: 1 /Compare mode : 0 */
    unsigned short                : 1;
    unsigned short SCCI            : 1; /* Latched capture signal (read) */
    unsigned short SCS             : 1; /* Capture sychronize */
    unsigned short CCIS0           : 1; /* Capture input select 0 */
    unsigned short CCIS1           : 1; /* Capture input select 1 */
    unsigned short CM0             : 1; /* Capture mode 0 */
    unsigned short CM1             : 1; /* Capture mode 1 */
  }TACCTL1_bit;
} @0x0164;


/*
enum {
  CCIFG           = 0x0001,
  COV             = 0x0002,
  OUT             = 0x0004,
  CCI             = 0x0008,
  CCIE            = 0x0010,
  OUTMOD0         = 0x0020,
  OUTMOD1         = 0x0040,
  OUTMOD2         = 0x0080,
  CAP             = 0x0100,
  SCCI            = 0x0400,
  SCS             = 0x0800,
  CCIS0           = 0x1000,
  CCIS1           = 0x2000,
  CM0             = 0x4000,
  CM1             = 0x8000,
};
*/


  /* Timer A Counter Register */
__no_init volatile unsigned short TAR @ 0x0170;


  /* Timer A Capture/Compare 0 */
__no_init volatile unsigned short TACCR0 @ 0x0172;


  /* Timer A Capture/Compare 1 */
__no_init volatile unsigned short TACCR1 @ 0x0174;










/* Alternate register names */
#line 1298 "D:\\Program Files\\IAR Systems\\Embedded Workbench 6.0 Evaluation\\430\\inc\\io430G2231.h"

/* Alternate register names - 5xx style */
#line 1314 "D:\\Program Files\\IAR Systems\\Embedded Workbench 6.0 Evaluation\\430\\inc\\io430G2231.h"

#line 1327 "D:\\Program Files\\IAR Systems\\Embedded Workbench 6.0 Evaluation\\430\\inc\\io430G2231.h"

#line 1344 "D:\\Program Files\\IAR Systems\\Embedded Workbench 6.0 Evaluation\\430\\inc\\io430G2231.h"

/* TA2IV Definitions */
#line 1352 "D:\\Program Files\\IAR Systems\\Embedded Workbench 6.0 Evaluation\\430\\inc\\io430G2231.h"

/*-------------------------------------------------------------------------
 *   USI
 *-------------------------------------------------------------------------*/


__no_init volatile union
{
  unsigned char USICTL0;   /* USI  Control Register 0 */

  struct
  {
    unsigned char USISWRST        : 1; /* USI  Software Reset */
    unsigned char USIOE           : 1; /* USI  Output Enable */
    unsigned char USIGE           : 1; /* USI  General Output Enable Latch */
    unsigned char USIMST          : 1; /* USI  Master Select  0:Slave / 1:Master */
    unsigned char USILSB          : 1; /* USI  LSB first  1:LSB / 0:MSB */
    unsigned char USIPE5          : 1; /* USI  Port Enable Px.5 */
    unsigned char USIPE6          : 1; /* USI  Port Enable Px.6 */
    unsigned char USIPE7          : 1; /* USI  Port Enable Px.7 */
  }USICTL0_bit;
} @0x0078;


enum {
  USISWRST        = 0x0001,
  USIOE           = 0x0002,
  USIGE           = 0x0004,
  USIMST          = 0x0008,
  USILSB          = 0x0010,
  USIPE5          = 0x0020,
  USIPE6          = 0x0040,
  USIPE7          = 0x0080
};


__no_init volatile union
{
  unsigned char USICTL1;   /* USI  Control Register 1 */

  struct
  {
    unsigned char USIIFG          : 1; /* USI  Counter Interrupt Flag */
    unsigned char USISTTIFG       : 1; /* USI  START Condition interrupt Flag */
    unsigned char USISTP          : 1; /* USI  STOP Condition received */
    unsigned char USIAL           : 1; /* USI  Arbitration Lost */
    unsigned char USIIE           : 1; /* USI  Counter Interrupt enable */
    unsigned char USISTTIE        : 1; /* USI  START Condition interrupt enable */
    unsigned char USII2C          : 1; /* USI  I2C Mode */
    unsigned char USICKPH         : 1; /* USI  Sync. Mode: Clock Phase */
  }USICTL1_bit;
} @0x0079;


enum {
  USIIFG          = 0x0001,
  USISTTIFG       = 0x0002,
  USISTP          = 0x0004,
  USIAL           = 0x0008,
  USIIE           = 0x0010,
  USISTTIE        = 0x0020,
  USII2C          = 0x0040,
  USICKPH         = 0x0080
};


__no_init volatile union
{
  unsigned char USICKCTL;   /* USI  Clock Control Register */

  struct
  {
    unsigned char USISWCLK        : 1; /* USI  Software Clock */
    unsigned char USICKPL         : 1; /* USI  Clock Polarity 0:Inactive=Low / 1:Inactive=High */
    unsigned char USISSEL0        : 1; /* USI  Clock Source Select 0 */
    unsigned char USISSEL1        : 1; /* USI  Clock Source Select 1 */
    unsigned char USISSEL2        : 1; /* USI  Clock Source Select 2 */
    unsigned char USIDIV0         : 1; /* USI  Clock Divider 0 */
    unsigned char USIDIV1         : 1; /* USI  Clock Divider 1 */
    unsigned char USIDIV2         : 1; /* USI  Clock Divider 2 */
  }USICKCTL_bit;
} @0x007A;


enum {
  USISWCLK        = 0x0001,
  USICKPL         = 0x0002,
  USISSEL0        = 0x0004,
  USISSEL1        = 0x0008,
  USISSEL2        = 0x0010,
  USIDIV0         = 0x0020,
  USIDIV1         = 0x0040,
  USIDIV2         = 0x0080
};


__no_init volatile union
{
  unsigned char USICNT;   /* USI  Bit Counter Register */

  struct
  {
    unsigned char USICNT0         : 1; /* USI  Bit Count 0 */
    unsigned char USICNT1         : 1; /* USI  Bit Count 1 */
    unsigned char USICNT2         : 1; /* USI  Bit Count 2 */
    unsigned char USICNT3         : 1; /* USI  Bit Count 3 */
    unsigned char USICNT4         : 1; /* USI  Bit Count 4 */
    unsigned char USIIFGCC        : 1; /* USI  Interrupt Flag Clear Control */
    unsigned char USI16B          : 1; /* USI  16 Bit Shift Register Enable */
    unsigned char USISCLREL       : 1; /* USI  SCL Released */
  }USICNT_bit;
} @0x007B;


enum {
  USICNT0         = 0x0001,
  USICNT1         = 0x0002,
  USICNT2         = 0x0004,
  USICNT3         = 0x0008,
  USICNT4         = 0x0010,
  USIIFGCC        = 0x0020,
  USI16B          = 0x0040,
  USISCLREL       = 0x0080
};


  /* USI  Low Byte Shift Register */
__no_init volatile unsigned char USISRL @ 0x007C;


  /* USI  High Byte Shift Register */
__no_init volatile unsigned char USISRH @ 0x007D;


  /* USI  Control Register */
__no_init volatile unsigned short USICTL @ 0x0078;


  /* USI  Clock and Counter Control Register */
__no_init volatile unsigned short USICCTL @ 0x007A;


  /* USI  Shift Register */
__no_init volatile unsigned short USISR @ 0x007C;











#line 1515 "D:\\Program Files\\IAR Systems\\Embedded Workbench 6.0 Evaluation\\430\\inc\\io430G2231.h"

#line 1524 "D:\\Program Files\\IAR Systems\\Embedded Workbench 6.0 Evaluation\\430\\inc\\io430G2231.h"

/*-------------------------------------------------------------------------
 *   Watchdog Timer
 *-------------------------------------------------------------------------*/


__no_init volatile union
{
  unsigned short WDTCTL;   /* Watchdog Timer Control */

  struct
  {
    unsigned short WDTIS0          : 1; /*  */
    unsigned short WDTIS1          : 1; /*  */
    unsigned short WDTSSEL         : 1; /*  */
    unsigned short WDTCNTCL        : 1; /*  */
    unsigned short WDTTMSEL        : 1; /*  */
    unsigned short WDTNMI          : 1; /*  */
    unsigned short WDTNMIES        : 1; /*  */
    unsigned short WDTHOLD         : 1; /*  */
  }WDTCTL_bit;
} @ 0x0120;


enum {
  WDTIS0          = 0x0001,
  WDTIS1          = 0x0002,
  WDTSSEL         = 0x0004,
  WDTCNTCL        = 0x0008,
  WDTTMSEL        = 0x0010,
  WDTNMI          = 0x0020,
  WDTNMIES        = 0x0040,
  WDTHOLD         = 0x0080
};














/* WDT is clocked by fSMCLK (assumed 1MHz) */





/* WDT is clocked by fACLK (assumed 32KHz) */





/* WDT is clocked by fSMCLK (assumed 1MHz) */





/* WDT is clocked by fACLK (assumed 32KHz) */





/*-------------------------------------------------------------------------
 *   Calibration Data
 *-------------------------------------------------------------------------*/


  /* DCOCTL  Calibration Data for 1MHz */
__no_init volatile unsigned const char CALDCO_1MHZ @ 0x10FE;


  /* BCSCTL1 Calibration Data for 1MHz */
__no_init volatile unsigned const char CALBC1_1MHZ @ 0x10FF;






#pragma language=restore



/************************************************************
* Timer A interrupt vector value
************************************************************/

/* Compability definitions */






/************************************************************
* Interrupt Vectors (offset from 0xFFE0)
************************************************************/

#line 1641 "D:\\Program Files\\IAR Systems\\Embedded Workbench 6.0 Evaluation\\430\\inc\\io430G2231.h"


#line 663 "D:\\Program Files\\IAR Systems\\Embedded Workbench 6.0 Evaluation\\430\\inc\\io430.h"

#line 834 "D:\\Program Files\\IAR Systems\\Embedded Workbench 6.0 Evaluation\\430\\inc\\io430.h"


#line 2 "E:\\AllProject\\430\\G2231_Self\\main.c"
void delay(unsigned int t)
{
	while(t--);
}
int main( void )
{
	// Stop watchdog timer to prevent time out reset
	WDTCTL = (0x5A00u) + WDTHOLD;
	P1DIR|=0x41;
	
	while(1)
	{
		if(!(P1IN&0x08))//Èç¹ûS2°´ÏÂ
		{
			P1OUT|=0x40;
			P1OUT&=~0x01;
			delay(15000);
			P1OUT|=0x01;
			P1OUT&=~0x40;
			delay(15000);
		}
	}
	return 0;
}
