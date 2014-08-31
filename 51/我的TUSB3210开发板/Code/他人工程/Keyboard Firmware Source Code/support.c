/******************************************************************************
 *                         VAULT INFORMATION SERVICES                         *
 *                          TEXAS INSTRUMENTS, INC.                           *
 *----------------------------------------------------------------------------*
 *                  "Support Program for TUSB2136 Demo App"                   *
 *                                                                            * 
 * Programmed by: Craig Steiner, VIS (csteiner@vaultbbs.com)                  * 
 * Develop Date:  30/Sep/2000                                                 *  
 *----------------------------------------------------------------------------*
 * Description: This module is a component of the TUSB2136 Demo App.  It      *
 *   contains generic, non-specific support routines that are utilized by     *
 *   other modules in the project.                                            *
 ******************************************************************************/

#include <io51.h>
#include "types.h"
#include "tusb2136.h"

/***************************************************************************
 * Function:   strlen                                                      *
 * Programmer: Craig Steiner (csteiner@vaultbbs.com)                       *
 * Description: Generic, simple version of the normal strlen() C-function. *
 *    It is coded here because using the following version of strlen() is  *
 *    approximately 40 bytes more efficient than using the standard lib    *
 *    version of strlen() with IAR tools.                                  * 
 ***************************************************************************/

BYTE strlen(char *string)
{
	BYTE str;
	for(str = 0; str < 255 ; str++)
		if( string[str] == 0x00 )
			return(str);
	return(0);
}

void memcpy(char *string1, char *string2, BYTE count)
{
	BYTE str;
	for(str = 0; str < count; str++)
		string1[str] = string2[str];
}

BYTE memcmp(char *string1, char *string2, BYTE count)
{
	BYTE str;
	for(str = 0; str < count; str++)
		if( string1[str] != string2[str] )
			return(1);
	return(0);
}

#pragma warnings = off
void sendUartByte(BYTE bValue)
{
#ifdef SERIALDEBUG
	while(TI == 0);
	TI = 0;
	SBUF = bValue;
#endif
}

void sendUartString(char *string, BYTE bCount)
{
#ifdef SERIALDEBUG
	BYTE bIndex;
	for(bIndex = 0; bIndex < bCount; bIndex++)
		sendUartByte(string[bCount]);
#endif
}

void sendUartHex(BYTE bValue)
{
#ifdef SERIALDEBUG
	BYTE hexValue;
	hexValue = (bValue & 0xF0)>> 4;
	if(hexValue < 10 )
		sendUartByte(hexValue + '0');
	else
		sendUartByte(hexValue + 55);

	hexValue = (bValue & 0x0F);
	if(hexValue < 10 )
		sendUartByte(hexValue + '0');
	else
		sendUartByte(hexValue + 55);
#endif
}
#pragma warnings = default

#ifdef XXX
/***************************************************************************
 * Function:   DelaymSecond                                                *
 * Programmer: Horng-Ming Lobo Tai (lobotai@ti.com)                        *
 * Description: Delays the given amount of msecs, assuming the processor   *
 *    is running at 12MHz.                                                 *
 ***************************************************************************/

VOID DelaymSecond(UINT uiCounter)   // 12Mhz
{
    TMOD &= 0xf0;
    TMOD |= 0x01;               // timer 0 in mode 1, 16bit counter

    while(uiCounter--){
        TL0 = (65536-1000*SYS_CLOCK/12) % 256;
        TH0 = (65536-1000*SYS_CLOCK/12) / 256;
        TR0 = 1;                // start timer
        while(TF0 !=1);
        TF0 = 0;
    }
    TR0 = 0;
}
#endif