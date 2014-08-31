/******************************************************************************
 *                         VAULT INFORMATION SERVICES                         *
 *                          TEXAS INSTRUMENTS, INC.                           *
 *----------------------------------------------------------------------------*
 *     "VID/PID Selection Detection Module for TUSB2136 Keyboard Demo App"    *
 *                                                                            * 
 * Programmed by: Craig Steiner, VIS (csteiner@vaultbbs.com)                  * 
 * Develop Date:  30/Sep/2000                                                 *  
 *----------------------------------------------------------------------------*
 * Description: This module is a component of the TUSB2136 Demo App.  It      *
 *   detects the setting provided on the s0-s3 pins and chooses the product   *
 *   configuration base on that setting.                                      *
 *                                                                            * 
 * NOTE: The end user may easily modify the funcDefs[] structure defined below* 
 *       to support his/her product without requiring extensive modification  *  
 *       to the rest of the source code.                                      *   
 ******************************************************************************/

#include <io51.h>
#include "types.h"
#include "tusb2136.h"

/***************************************************************************
 * Structure: FUNCDEF Structure                                            *
 * Programmer: Craig Steiner (csteiner@vaultbbs.com)                       *
 * Description: The funcDefs[] structure contains the VID/PID settings for *
 *    each possible s0123 setting. The s0123 is read at boot-time from     *
 *    pins S0-S3 in order to obtain a given "personality" depending on the *
 *    way these pins are tied.  This allows a single firmware to handle a  * 
 *    variety of distinct manufacturer/products that essentially work the  *  
 *    same way.                                                            *   
 *                                                                         *    
 *    The last entry in the structure should use an s0123 setting of 0xFF  *    
 *    to indicate the "default" setting.  The parameters contained in this *    
 *    entry will be used if the value contained on s0123 is not found in   *     
 *    the structure.                                                       *      
 *                                                                         *     
 *    The structure definition for FUNCDEF_STRUCT is contained in the      *     
 *    types.h include file.                                                *      
 ***************************************************************************/

struct FUNCDEF_STRUCT code funcDefs[17] = {
	// VID/PID Setting 0 *******************************
	{0, // S0S1 value 
	0x0451, 0x0001, // HUB VID/PID */
	0x0451, 0x0010, // FNC VID/PID */
	0x1111,	// FNC revision level
	"Texas Instruments",
	"Texas Instruments TUSB2136 Keyboard (Ver 0)",
	NULL},

	// VID/PID Setting 1 ********************************
	{1, // S0S1 value 
	0x0451, 0x0002, // HUB VID/PID */
	0x0451, 0x0020, // FNC VID/PID */
	0x2222,	// FNC revision level
	"Texas Instruments",
	"Texas Instruments TUSB2136 EVM DEMO 1 (Ver 1)",
	NULL},
	
	// VID/PID Setting 2 ********************************
	{2, // S0S1 value 
	0x0451, 0x0003, // HUB VID/PID */
	0x0451, 0x0030, // FNC VID/PID */
	0x3333,	// FNC revision level
	"Texas Instruments",
	"Texas Instruments TUSB2136 EVM DEMO 2 (Ver 2)",
	NULL},

	// VID/PID Setting 3 ********************************
	{3, // S0S1 value 
	0x0451, 0x0004, // HUB VID/PID */
	0x0451, 0x0040, // FNC VID/PID */
	0x4444,	// FNC revision level
	"Texas Instruments",
//	"Texas Instruments TUSB2136 for NewMotion One-Key Keyboard (Ver 3)",
	"Texas Instruments TUSB2136 for Flat Keyboard (Ver 3)",
	NULL},

	// VID/PID DEFAULT SETTING ***************************	
	// ** WARNING: YOU MAY CHANGE THE DEFAULT PARAMETERS,
	//             BUT DO NOT REMOVE THIS ENTRY.  THE CODE
	//             MUST BE ABLE TO USE A DEFAULT VALUE TO
	//             HAVE VALID PARAMETERS IF NONE OF THE
	//             PREVIOUS ENTRIES HANDLE THE DETECTED
	//             S0123 SETTING.
	// ***************************************************
	{0xFF, // S0S1 value (default value = 0xFF)
	0x0451, 0xEEEE, // HUB VID/PID */
	0x0451, 0xFFFF, // FNC VID/PID */
	0xFFFF,	// FNC revision level
	"Texas Instruments",
	"Texas Instruments TUSB2136 Generic Setting",
	NULL}
	};

unsigned char s0123; // The s0132 value read from VIDSTA at boot time
unsigned char fncOffset; // The offset into the funcDefs structure, used in 
						// other modules to directly access the information
						// from the funcDefs[] structure.

/***************************************************************************
 * Function:   GetVidPidSetting                                            *
 * Programmer: Craig Steiner (csteiner@vaultbbs.com)                       *
 * Description: Obtains the setting from S0-S3 (P3.0/P3.1).  This is then  *
 *    used to select the various VID/PID settings for the hub and function.*
 ***************************************************************************/

void GetVidPidSetting(void)
{
int i;
	// Obtain the VID/PID setting from mapped memory.
	for(i=0; i<50; i++); // wait for stable of s0-s3
	
	s0123 = 1; // modified for TUSB3210 Keyboard EVM, Aug 7 2001
	
	// We now must search the funcDefs[] structure for the detected
	// s0123 setting.  The variable used as the index in the for... loop
	// is the global fncOffset variable.  Thus when the loop is complete
	// the fncOffset variable will point to the entry in fncDefs[] that
	// contains the selected configuration information.  We limit the
	// loop at 17 so that a structure without a terminating 0xFF entry
	// does not cause an infinite crash/loop.
	
	for(fncOffset = 0; fncOffset < 17; fncOffset++ )
		if(funcDefs[fncOffset].s0123 == s0123 || funcDefs[fncOffset].s0123 == 0xFF )
			break;
}

