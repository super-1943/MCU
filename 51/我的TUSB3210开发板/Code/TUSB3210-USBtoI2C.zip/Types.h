/******************************************************************************
 *                         VAULT INFORMATION SERVICES                         *
 *                          TEXAS INSTRUMENTS, INC.                           *
 *                                                                            *
 *                              Type Header File                              *
 *                                                                            *
 *----------------------------------------------------------------------------*
 * Programmed by: Lobo Tai (lobotai@ti.com)                                   *
 * Develop Date:  30/Sep/2000                                                 *
 *----------------------------------------------------------------------------*
 * Description: This header file defines types that are used throughout       *
 *   the application.                                                         *
 ******************************************************************************/
 
#ifndef _TYPES_H_
#define _TYPES_H_

#include "intrins.h"

/*----------------------------------------------------------------------------+
| Include files                                                               |
+----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------+
| Function Prototype                                                          |
+----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------+
| Type Definition & Macro                                                     |
+----------------------------------------------------------------------------*/
typedef char            CHAR;
typedef unsigned char   UCHAR;
typedef int             INT;
typedef unsigned int    UINT;
typedef short           SHORT;
typedef unsigned short  USHORT;
typedef long            LONG;
typedef unsigned long   ULONG;
typedef void            VOID;
typedef unsigned long   HANDLE;
typedef char *          PSTR;
typedef double          DOUBLE;
typedef unsigned char   BYTE;
typedef unsigned char * PBYTE;
typedef unsigned int    WORD;
typedef unsigned long   DWORD;

	
/*----------------------------------------------------------------------------+
| Constant Definition                                                         |
+----------------------------------------------------------------------------*/
#define YES 1
#define NO  0

#define TRUE    1
#define FALSE   0

#define NOERR   0
#define ERR 1

#define NO_ERROR    0
#define ERROR       1

#define DISABLE     0
#define ENABLE      1

#define NULL 0x00

#define ASSERTED    1
#define DE_ASSERTED 0

typedef enum
{
    STATUS_ACTION_NOTHING,
    STATUS_ACTION_DATA_IN,
    STATUS_ACTION_DATA_OUT,
    STATUS_ACTION_SET_ADDRESS
} tSTATUS_ACTION_LIST;



#define DELAY_1000NS  _nop_(), _nop_(), _nop_(), _nop_()
#define DELAY_750NS   _nop_(), _nop_(), _nop_()
#define DELAY_700NS   _nop_(), _nop_(), _nop_()
#define DELAY_600NS   _nop_(), _nop_(), _nop_()
#define DELAY_500NS   _nop_(), _nop_()
#define DELAY_400NS   _nop_(), _nop_()
#define DELAY_300NS   _nop_()
#define DELAY_250NS   _nop_()

#define I2C_DEVICE_ADDRESS_DEFAULT 0
#define I2C_100KHZ          0
#define I2C_400KHZ          1

#define I2C_CATEGORY_1      1
#define I2C_CATEGORY_2      2
#define I2C_CATEGORY_3      3
#define I2C_CATEGORY_LAST   3

#define BIT_I2C_READ        1

#define BIT_I2C_DEVICE_TYPE_MEMORY  0xA0

#define MASK_I2C_DEVICE_ADDRESS     0x07

#endif /* _TYPES_H_ */
