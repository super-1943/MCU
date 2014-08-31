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

#ifdef __cplusplus
extern "C"
{
#endif

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
typedef int             BOOL;
typedef double          DOUBLE;
typedef unsigned char   BYTE;
typedef unsigned char * PBYTE;
typedef unsigned int    WORD;
typedef unsigned long   DWORD;

/*----------------------------------------------------------------------------+
| Structure Definition                                                        |
+----------------------------------------------------------------------------*/
struct FUNCDEF_STRUCT
	{
	unsigned char			s0123;
	unsigned int			hubVID;
	unsigned int			hubPID;
	unsigned int			fncVID;
	unsigned int			fncPID;
	unsigned int			fncRevision;
	char					*mfgDescription;
	char					*prodDescription;
	char					*serialNumber;
	};

struct KEYMAP_STRUCT
	{
	unsigned int	vidPidMask; // Each bit indicates whether this key is supported in given VID/PID setting
	unsigned long	scanLine; // Indicates the column to select
	BYTE			keyPressMask; // Indicates the value returned if the given key is pressed
	BYTE			hidCode; // The value that is returned via USB to computer for this keypress
	BYTE			modBit; // Holds the bit which should be turned on in the modifier byte if this key is pressed
	};

	
	

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

typedef enum
{
    STATUS_ACTION_NOTHING,
    STATUS_ACTION_DATA_IN,
    STATUS_ACTION_DATA_OUT,
    STATUS_ACTION_SET_ADDRESS
} tSTATUS_ACTION_LIST;


#ifdef __cplusplus
}
#endif
#endif /* _TYPES_H_ */
