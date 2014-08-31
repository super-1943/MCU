 /*****************************************************************************
 *                         VAULT INFORMATION SERVICES                         *
 *                          TEXAS INSTRUMENTS, INC.                           *
 *----------------------------------------------------------------------------*
 *                  "TUSB2136 Generic Keyboard Demo Program"                  *
 *                                                                            * 
 * Programmed by: Craig Steiner, VIS (csteiner@vaultbbs.com)                  * 
 * Develop Date:  30/Sep/2000                                                 *  
 *----------------------------------------------------------------------------*
 * Description: This software is a fully functional demonstration program that*
 *   illustrates the use of the TUSB2136 to implement a USB 101-key keyboard. *
 *                                                                            *
 *   This module is the "main" module.  Also, pretty much everything that the *
 *   end-user will need to modify to create a standard keyboard is contained  * 
 *   in this module.                                                          * 
 *                                                                            *
 * Modified by Jim Chen 2001/01/03:                                           *
 *   1. total 102 keys                                                        *
 *   2. can work in Mac                                                       *
 *   3. use scanline8, scanline9 and return 0x40 as suspend key               *
 *   4. added usbSetIdle(void), void usbSetProtocol(void) for Mac             *
 *                                                                            *
 * Modified by Jim Chen 2001/01/19:                                           *
 *   1. fixed bug in high speed Mac                                           *
 *                                                                            *
 * Modified by Jim Chen 2001/03/02:                                           *
 *   1. merge 4 configurations into one binary code                           *
 *   2. solve phantom key issue by Mike's solution                            *
 *   3. version number started with Rev1.00                                   *
 *                                                                            *
 * Modified by Jim Chen 2001/06/01: Rev1.01                                   *
 *   1. changed version 4 from NewMotion one-key to flat keypad               *
 *                                                                            *
 ******************************************************************************/

#include <io51.h>
#include "types.h"
#include "delay.h"
#include "usb.h"
#include "tusb2136.h"

// Maximum size of the Keypress buffer is 6 bytes, because that's what fits in
// a single HID standard keyboard response

#define KEYPRESS_BUFFER_SIZE			0x06

// The following definitions indicate which bit of the data byte sent from
// the host to the keyboard correspond to each of the given LEDs.

#define BIT_NUMLOCK					0x01
#define BIT_CAPSLOCK				0x02
#define BIT_SCROLLLOCK				0x04

// The following definitions indicate which GPIO pin corresponds to each
// of the keyboard LEDs.

#define PIN_NUMLOCK				    P3.4
#define PIN_CAPSLOCK				P3.3
#define PIN_SCROLLLOCK				P3.2

extern unsigned char s0123;
extern BYTE deviceReady;
extern BYTE bSuspended;

extern void gpioInitialization(void);
extern void setLEDs(BYTE bData);
extern int readSwitches(void);
extern BYTE strlen(char *string);
void sendUartByte(BYTE bValue);void sendUartString(char *string, BYTE bCount);
void sendUartHex(BYTE bValue);

extern BYTE memcmp(char *string1, char *string2, BYTE count);
extern void memcpy(char *string1, char *string2, BYTE count);
extern void InitializeUsbData(void);
extern void InitializeUsbHub(void);
extern void InitializeUsbFunction(void);
extern void GetVidPidSetting(void);
unsigned char intFlags = 0x00;
unsigned char otherFlags = 0x00;

void ClearKeyBoardBuffer(void);
void sendKeyData(int x);
void UpdateIEP1WithKeypress(void);

BYTE bLED = 0;
BYTE modifierByte = 0x00;
BYTE keypressBuffer[KEYPRESS_BUFFER_SIZE + 1];
char previousIEP1packet[8];
char *iep1Buffer = 0x00;

#pragma memory = dataseg(TUSB2136_DEBOUNCE_SEG)
BYTE keypressDebounce[256];
#pragma memory = default

/***************************************************************************
 * Structure: KEYDEFS Structure                                            *
 * Programmer: Craig Steiner (csteiner@vaultbbs.com)                       *
 * Description: The keyDefs[] structure contains a list of all the keys    *
 *    that are supported by the keyboard and information related to each   *
 *    key.  Additional keys may be added to the program by adding          *
 *    additional entries in this table.  The structure is defined in       * 
 *    types.h.                                                             *
 *                                                                         *
 *    vidPidMask: The first column is a bit-mapped mask that indicates     *
 *          whether the given key is supported by each VID/PID version.    *
 *          For example, 0x0001 means that the given key is only supported *
 *          by VIDSTA configuration #1.  0x0003 means it is supported only * 
 *          by configuration #1 and #2.  0xFFFF means it is supported by   *
 *          all 16 possible configurations of VIDSTA.  This allows a       * 
 *          single firmware which includes specialized key definitions     *
 *          that only apply to certain products.                           *
 *    scanLine: The second column indicates which keyboard scan line must  *
 *          be selected in order to detect the keypress.  The current      *
 *          software supports 18 scan lines.  More scan lines may be       *
 *          supported by modifying the "scan line selection" code in       *
 *          the main() module.                                             *
 *    keyPressMask: The third column is a bitmask which indicates which    *
 *          bit will be brought low when the given key is pressed.         *
 *    hidCode: The fourth column indicates the HID usage code for the      *
 *          given keypress.  The constants are delcared in usb.h.  A       *
 *          value of 0 in the hidCode coumn will cause the keypress to     *
 *          be ignored.                                                    *
 *    modBit: The fifth (optional) column indicates which bit, if any,     *
 *          should be set in the keyboard modifier byte.  This is for      *
 *          ALT, SHIFT, CTRL, and GUI keys.  This is implemented as a      *
 *          field in the array so that additional keys can easily be       *
 *          added that mimic the functionality of the keys above.  If the  *
 *          value is omitted, it will be compiled to 0x00 which means the  *
 *          key will NOT set any bit in the modifier byte of the report.   *
 ***************************************************************************/
/* for reference only
struct KEYMAP_STRUCT
	{
	unsigned int	vidPidMask; // Each bit indicates whether this key is supported in given VID/PID setting
	unsigned long	scanLine; // Indicates the column to select
	BYTE			keyPressMask; // Indicates the value returned if the given key is pressed
	BYTE			hidCode; // The value that is returned via USB to computer for this keypress
	BYTE			modBit; // Holds the bit which should be turned on in the modifier byte if this key is pressed
	};
*/
// 4 kinds of keyboard matrix mapping
struct KEYMAP_STRUCT code keyDefs[] = {
    //VID, Col, Ret, USB, ModByteBit
    {0x0001, 18, 0x02, usbUsageLeftGUI, 0x08},
        {0x0002, 18, 0x80, usbUsage1},
	    {0x0006, 18, 0x40, usbUsageA}, // for S[3:0]=2 and S[3:0]=4, 6=2+4
	    {0x0006, 18, 0x20, usbUsageJ},
	    {0x0006, 18, 0x10, usbUsageS},
            {0x0004, 18, 0x80, usbUsageKeypadNumlock},
    	        {0x0008, 18,  0x80, usbUsageQ}, // for David's keypad
    	        {0x0008, 18,  0x40, usbUsageW}, // for David's keypad
    	        {0x0008, 18,  0x20, usbUsageE}, // for David's keypad
    	        {0x0008, 18,  0x10, usbUsageR}, // for David's keypad
    	        {0x0008, 18,  0x08, usbUsageT}, // for David's keypad
    	        {0x0008, 18,  0x04, usbUsageY}, // for David's keypad
    	        {0x0008, 18,  0x02, usbUsageU}, // for David's keypad
	    
    {0x0001, 17, 0x80, usbUsageRightAlt, 0x40},
    {0x0001, 17, 0x20, usbUsageLeftAlt, 0x04 },
    {0x0001, 17, 0x08, usbUsageScrollLock},
    {0x0001, 17, 0x04, usbUsagePrintScreen},
        {0x0002, 17, 0x80, usbUsage2},
	    {0x0006, 17, 0x40, usbUsageB}, // for S[3:0]=2 and S[3:0]=4, 6=2+4
	    {0x0006, 17, 0x20, usbUsageK},
	    {0x0006, 17, 0x10, usbUsageT},
            {0x0004, 17, 0x80, usbUsageCapsLock},
    	        {0x0008, 17,  0x80, usbUsage9}, // for David's keypad
    	        {0x0008, 17,  0x40, usbUsage8}, // for David's keypad
    	        {0x0008, 17,  0x20, usbUsage7}, // for David's keypad
    	        {0x0008, 17,  0x10, usbUsageEscape}, // for David's keypad
//    	        {0x0008, 17,  0x08, usbUsageOut}, // for David's keypad
    	        {0x0008, 17,  0x08, usbUsageLeftShift, 0x02}, // for David's keypad
    	        {0x0008, 17,  0x04, usbUsageP}, // for David's keypad
    	        {0x0008, 17,  0x02, usbUsageO}, // for David's keypad
    	        {0x0008, 17,  0x01, usbUsageI}, // for David's keypad
	    
    {0x0001, 16, 0x80, usbUsageSpacebar}, 
    {0x0001, 16, 0x40, usbUsageEnter}, 
    {0x0001, 16, 0x20, usbUsageF5},
    {0x0001, 16, 0x10, usbUsageBackspace},
    {0x0001, 16, 0x04, usbUsageF10},
    {0x0001, 16, 0x02, usbUsageF9},
    {0x0001, 16, 0x01, usbUsageBackslash},
    	{0x0002, 16, 0x80, usbUsage3},
	    {0x0006, 16, 0x40, usbUsageC}, // for S[3:0]=2 and S[3:0]=4, 6=2+4
	    {0x0006, 16, 0x20, usbUsageL},
	    {0x0006, 16, 0x10, usbUsageU},
            {0x0004, 16, 0x80, usbUsageScrollLock},
    	        {0x0008, 16,  0x80, usbUsageA}, // for David's keypad
    	        {0x0008, 16,  0x40, usbUsageS}, // for David's keypad
    	        {0x0008, 16,  0x20, usbUsageD}, // for David's keypad
    	        {0x0008, 16,  0x10, usbUsageF}, // for David's keypad
    	        {0x0008, 16,  0x08, usbUsageG}, // for David's keypad
    	        {0x0008, 16,  0x04, usbUsageH}, // for David's keypad
    	        {0x0008, 16,  0x02, usbUsageJ}, // for David's keypad
    	        {0x0008, 16,  0x01, usbUsageComma}, // for David's keypad
    	
    {0x0001, 15, 0x80, usbUsageSlash},
    {0x0001, 15, 0x20, usbUsageApostrophe},
    {0x0001, 15, 0x10, usbUsageLeftBracket},
    {0x0001, 15, 0x08, usbUsageP},
    {0x0001, 15, 0x04, usbUsage0},
    {0x0001, 15, 0x02, usbUsageMinus},
    {0x0001, 15, 0x01, usbUsageSemicolon},
        {0x0006, 15, 0x80, usbUsage4}, // for S[3:0]=2 and S[3:0]=4, 6=2+4
	    {0x0006, 15, 0x40, usbUsageD},
	    {0x0006, 15, 0x20, usbUsageM},
	    {0x0006, 15, 0x10, usbUsageV},
    	        {0x0008, 15,  0x80, usbUsage6}, // for David's keypad
    	        {0x0008, 15,  0x40, usbUsage5}, // for David's keypad
    	        {0x0008, 15,  0x20, usbUsage4}, // for David's keypad
    	        {0x0008, 15,  0x10, usbUsageHome}, // for David's keypad
//    	        {0x0008, 15,  0x08, usbUsageIn}, // for David's keypad
    	        {0x0008, 15,  0x08, usbUsageRightAlt, 0x40}, // for David's keypad
    	        {0x0008, 15,  0x04, usbUsageApostrophe}, // for David's keypad
    	        {0x0008, 15,  0x02, usbUsageL}, // for David's keypad
    	        {0x0008, 15,  0x01, usbUsageK}, // for David's keypad
        
    {0x0001, 14, 0x40, usbUsagePeriod},
    {0x0001, 14, 0x10, usbUsageF7},
    {0x0001, 14, 0x08, usbUsageO},
    {0x0001, 14, 0x04, usbUsage9},
    {0x0001, 14, 0x02, usbUsageF8},
    {0x0001, 14, 0x01, usbUsageL},
    	{0x0006, 14, 0x80, usbUsage5}, // for S[3:0]=2 and S[3:0]=4, 6=2+4
	    {0x0006, 14, 0x40, usbUsageE},
	    {0x0006, 14, 0x20, usbUsageN},
	    {0x0006, 14, 0x10, usbUsageW},
    	        {0x0008, 14,  0x80, usbUsageZ}, // for David's keypad
    	        {0x0008, 14,  0x40, usbUsageX}, // for David's keypad
    	        {0x0008, 14,  0x20, usbUsageC}, // for David's keypad
    	        {0x0008, 14,  0x10, usbUsageV}, // for David's keypad
    	        {0x0008, 14,  0x08, usbUsageB}, // for David's keypad
    	        {0x0008, 14,  0x04, usbUsageN}, // for David's keypad
    	        {0x0008, 14,  0x02, usbUsageM}, // for David's keypad
    	        {0x0008, 14,  0x01, usbUsageLeftControl, 0x01}, // for David's keypad
    	
    {0x0001, 13, 0x40, usbUsageComma},
    {0x0001, 13, 0x20, usbUsageF6},
    {0x0001, 13, 0x10, usbUsageRightBracket},
    {0x0001, 13, 0x08, usbUsageI}, 
    {0x0001, 13, 0x04, usbUsage8},
    {0x0001, 13, 0x02, usbUsageEqual},
    {0x0001, 13, 0x01, usbUsageK},
    	{0x0006, 13, 0x80, usbUsage6}, // for S[3:0]=2 and S[3:0]=4, 6=2+4
	    {0x0006, 13, 0x40, usbUsageF},
	    {0x0006, 13, 0x20, usbUsageO},
	    {0x0006, 13, 0x10, usbUsageX},
    	        {0x0008, 13,  0x80, usbUsage3}, // for David's keypad
    	        {0x0008, 13,  0x40, usbUsage2}, // for David's keypad
    	        {0x0008, 13,  0x20, usbUsage1}, // for David's keypad
    	        {0x0008, 13,  0x10, usbUsageEnd}, // for David's keypad
    	        {0x0008, 13,  0x08, usbUsageEnter}, // for David's keypad
    	        {0x0008, 13,  0x04, usbUsageUpArrow}, // for David's keypad
    	        {0x0008, 13,  0x02, usbUsageBackslash}, // for David's keypad
    	        {0x0008, 13,  0x01, usbUsageSlash}, // for David's keypad
    	
    {0x0001, 12, 0x80, usbUsageN},
    {0x0001, 12, 0x40, usbUsageM},
    {0x0001, 12, 0x20, usbUsageH},
    {0x0001, 12, 0x10, usbUsageY},
    {0x0001, 12, 0x08, usbUsageU},
    {0x0001, 12, 0x04, usbUsage7},
    {0x0001, 12, 0x02, usbUsage6},
    {0x0001, 12, 0x01, usbUsageJ},
    	{0x0006, 12, 0x80, usbUsage7}, // for S[3:0]=2 and S[3:0]=4, 6=2+4
	    {0x0006, 12, 0x40, usbUsageG},
	    {0x0006, 12, 0x20, usbUsageP},
	    {0x0006, 12, 0x10, usbUsageY},
    	        {0x0008, 12,  0x80, usbUsageDeleteForward}, // for David's keypad
    	        {0x0008, 12,  0x40, usbUsage0}, // for David's keypad
    	        {0x0008, 12,  0x20, usbUsageInsert}, // for David's keypad
    	        {0x0008, 12,  0x10, usbUsageRightArrow}, // for David's keypad
    	        {0x0008, 12,  0x08, usbUsageSpacebar}, // for David's keypad
    	        {0x0008, 12,  0x04, usbUsageDownArrow}, // for David's keypad
    	        {0x0008, 12,  0x02, usbUsageLeftArrow}, // for David's keypad
    	        {0x0008, 12,  0x01, usbUsagePeriod}, // for David's keypad
    	
    {0x0001, 11, 0x80, usbUsageB},
    {0x0001, 11, 0x40, usbUsageV},
    {0x0001, 11, 0x20, usbUsageG},
    {0x0001, 11, 0x10, usbUsageT},
    {0x0001, 11, 0x08, usbUsageR},
    {0x0001, 11, 0x04, usbUsage4},
    {0x0001, 11, 0x02, usbUsage5},
    {0x0001, 11, 0x01, usbUsageF},
    	{0x0006, 11, 0x80, usbUsage8}, // for S[3:0]=2 and S[3:0]=4, 6=2+4
	    {0x0006, 11, 0x40, usbUsageH},
	    {0x0006, 11, 0x20, usbUsageQ},
	    {0x0006, 11, 0x10, usbUsageZ},
    	
    {0x0001, 10, 0x40, usbUsageC},
    {0x0001, 10, 0x20, usbUsageF4},
    {0x0001, 10, 0x10, usbUsageF3},
    {0x0001, 10, 0x08, usbUsageE},
    {0x0001, 10, 0x04, usbUsage3},
    {0x0001, 10, 0x02, usbUsageF2},
    {0x0001, 10, 0x01, usbUsageD},
    	{0x0006, 10, 0x80, usbUsage9}, // for S[3:0]=2 and S[3:0]=4, 6=2+4
	    {0x0006, 10, 0x40, usbUsageI},
	    {0x0006, 10, 0x20, usbUsageR},
	    {0x0006, 10, 0x10, usbUsageCapsLock},
    	
    {0x0001, 9,  0x40, usbUsageX},
    {0x0001, 9,  0x10, usbUsageCapsLock},
    {0x0001, 9,  0x08, usbUsageW},
    {0x0001, 9,  0x04, usbUsage2},
    {0x0001, 9,  0x02, usbUsageF1},
    {0x0001, 9,  0x01, usbUsageS},
//    	        {0x0008, 9,  0x40, 0x66}, // for NewMotion one suspend-key keyboard 
    	        {0x0008, 9,  0x80, usbUsageF1}, // for David's keypad
    	        {0x0008, 9,  0x40, usbUsageF2}, // for David's keypad
    	        {0x0008, 9,  0x20, usbUsageF3}, // for David's keypad
    	        {0x0008, 9,  0x10, usbUsageF4}, // for David's keypad
    	        {0x0008, 9,  0x08, usbUsageF5}, // for David's keypad
    	        {0x0008, 9,  0x04, usbUsageF6}, // for David's keypad
    	        {0x0008, 9,  0x02, usbUsageF7}, // for David's keypad
    	        
    {0x0001, 8,  0x40, usbUsageZ},
    {0x0001, 8,  0x20, usbUsageEscape},
    {0x0001, 8,  0x10, usbUsageTab},
    {0x0001, 8,  0x08, usbUsageQ},
    {0x0001, 8,  0x04, usbUsage1},
    {0x0001, 8,  0x02, usbUsageTilde},
    {0x0001, 8,  0x01, usbUsageA},
    	        {0x0008, 8,  0x04, usbUsageF8}, // for David's keypad
    	        {0x0008, 8,  0x02, usbUsageF9}, // for David's keypad
    	        {0x0008, 8,  0x01, usbUsageF10}, // for David's keypad
    
    {0x0001, 7,  0x80, usbUsageDownArrow},
    {0x0001, 7,  0x40, usbUsageKeypadNumlock},
    {0x0001, 7,  0x10, usbUsageKeypad4},
    {0x0001, 7,  0x08, usbUsageKeypad7},
    {0x0001, 7,  0x04, usbUsageF11},
    {0x0001, 7,  0x02, usbUsageDeleteForward},
    {0x0001, 7,  0x01, usbUsageKeypad1},
    
    {0x0001, 6,  0x80, usbUsageRightArrow},
    {0x0001, 6,  0x40, usbUsageKeypadSlash},
    {0x0001, 6,  0x20, usbUsageKeypad0},
    {0x0001, 6,  0x10, usbUsageKeypad5},
    {0x0001, 6,  0x08, usbUsageKeypad8},
    {0x0001, 6,  0x04, usbUsageF12},
    {0x0001, 6,  0x02, usbUsageInsert},
    {0x0001, 6,  0x01, usbUsageKeypad2},
    
    {0x0001, 5,  0x40, usbUsageRightShift, 0x20},
    {0x0001, 5,  0x10, usbUsageLeftShift, 0x02},
    
    {0x0001, 4,  0x08, usbUsageWindowsKey},
    {0x0001, 4,  0x01, usbUsageRightGUI, 0x80},
    
    {0x0001, 3,  0x80, usbUsageKeypadMinus},
    {0x0001, 3,  0x40, usbUsageKeypadAsterisk},
    {0x0001, 3,  0x20, usbUsageKeypadPeriod},
    {0x0001, 3,  0x10, usbUsageKeypad6},
    {0x0001, 3,  0x08, usbUsageKeypad9},
    {0x0001, 3,  0x04, usbUsagePageDown},
    {0x0001, 3,  0x02, usbUsagePageUp},
    {0x0001, 3,  0x01, usbUsageKeypad3},
    
    {0x0001, 2,  0x80, usbUsageLeftArrow},
    {0x0001, 2,  0x40, usbUsagePause},
    {0x0001, 2,  0x20, usbUsageUpArrow},
    {0x0001, 2,  0x08, usbUsageKeypadPlus},
    {0x0001, 2,  0x04, usbUsageEnd},
    {0x0001, 2,  0x02, usbUsageHome},
	{0x0001, 2,  0x01, usbUsageKeypadEnter}, 
	
    {0x0001, 1,  0x40, usbUsageRightControl, 0x10},
    {0x0001, 1,  0x02, usbUsageLeftControl, 0x01},
    
    {0xFFFF, 0,  0x00, 0x00} // End of table flag
    };
 
	
void delay(int i)
{
  while(i--);
}

void main(void)
{
	int vidPidMask;
	int iTemp;

#ifdef SERIALDEBUG
	// Enable serial port for debug at 9600 baud, using 48.000MHZ.
	SCON = 0x52;
	TH1 = -13;
	TMOD = 0x20;
	TR1 = 1;
#endif

	bPUR0 = 0x00;   // enable internal pull-ups
	bPUR1 = 0x00;
	bPUR2 = 0x00;
	bPUR3 = 0x00;
	
	P3 = 0xff; // speed-up pull-ups
	P2 = 0xff;
	P1 = 0xff;
	P0 = 0xff;
	
	GetVidPidSetting(); // Obtain the S0-S3 setting to determine VID/PID
	InitializeUsbHub(); // Initialize the USB hub connecting it to upstream port
	InitializeUsbFunction(); // Initialize the USB embedded function
	ClearKeyBoardBuffer(); // Clear the keyboard buffer
	
	vidPidMask = 1 << s0123; // Prepares our VID/PID mask to decide whether a given key is valid
	while(!deviceReady); // Wait for the setup packets to be exchanged, etc.
	
	for(iTemp = 0; iTemp < 256; iTemp++)
		keypressDebounce[iTemp] = 0x00;

	while(1) { // Indefinite loop to handle keyboard scanning
		
// for debug only
//		P3.2 = bVIDSTA&1;
//		P3.3 = (bVIDSTA>>1)&1;
//		P3.4 = (bVIDSTA>>2)&1;
//		P3.5 = (bVIDSTA>>3)&1;
		
		if(bSuspended) {
		
	        // disable P0, P1 and part of P3 internal pull-ups
			bPUR0 = 0xFF;
			bPUR1 = 0xFF;
			bPUR3 = 0xc3;  // disable P3.6, P3.7, P3.0, & P3.1 pull-ups 
			
			P0 = 0x00;
			P1 = 0x00;
			P3 = 0xff;     // turn LED off 
			P3.6 = 0;
			P3.7 = 0;                                                      

            // TUSB3210 Base EVM needs follow codes, otherwise it will comsume more 100uA power
            P3.0 = 0;      // since dip switch may tie P3.0 & P3.1 to ground
            P3.1 = 0;      
			
            EX1 = ENABLE;  // enable P2 interrupt
                        
			// Set IDLE bit in PCON to bring MCU to suspend
			PCON |= 0x01;

            // uC wakeups from suspend
			EX1 = DISABLE;
			bPUR0 = 0x00;
			bPUR1 = 0x00;
			bPUR3 = 0x00;

			// Execution will stop until we wake back up, at which point
			// we then conitnue by indicating we're no longer in Suspend
			// mode.
			bSuspended = FALSE;
		} // end of if(bSuspended)
			
		if(!deviceReady)
			continue;
			
		// We only scan the keyboard if the keypressBuffer is currently empty.
		if(keypressBuffer[0] == 0x00) {
			BYTE scanLine, keypress, keyDefOffset = 0;
			modifierByte = 0x00; // We initialize the modifier byte to zero initially

			// We now select each of the 18 scanlines (0-17) in sequence so that
			// we can detect any keys that have been pressed on the line.
			for(scanLine = 18; scanLine > 0; scanLine--) {
				// We start the loop by turning on all the bits of the 18 scanline select
				// lines.
				P0 = 0xFF;
				P1 = 0xFF;
				P3 |= 0xC0;
				
				// Now we turn off a single GPIO line to select the current scanline.
				switch(scanLine) {
                    case 1: P1.0 = 0; break;
                    case 2: P1.1 = 0; break;
                    case 3: P1.2 = 0; break;
                    case 4: P1.3 = 0; break;
                    case 5: P1.4 = 0; break;
                    case 6: P1.5 = 0; break;
                    case 7: P1.6 = 0; break;
                    case 8: P1.7 = 0; break;
                    case 9: P3.6 = 0; break;
                    case 10: P0.0 = 0; break;
                    case 11: P0.1 = 0; break;
                    case 12: P0.2 = 0; break;
                    case 13: P0.3 = 0; break;
                    case 14: P0.4 = 0; break;
                    case 15: P0.5 = 0; break;
                    case 16: P0.6 = 0; break;
                    case 17: P0.7 = 0; break;
                    case 18: P3.7 = 0; break;				
					// Additional scan lines may be added by adding more case statements
					// here and increasing the range of the for() statement above.
					default: break;
				} // end of switch(scanLine)
				
				// Get the current of the current scanline.  We invert it so that any bit that
				// is set indicates a key that has been pressed.
				keypress = ~P2; 

                if (keypress == 0x01 || keypress == 0x02 || keypress == 0x04 || keypress == 0x08 ||
                    keypress == 0x10 || keypress == 0x20 || keypress == 0x40 || keypress == 0x80) {
                    
                    // We now search the keyDefs[] table starting at the offset that we're at.
                    // We keep searching until the scanline indicated in the table is less than
                    // the current scanline, which means there are no more options for the current
                    // scanline.
                    while(keyDefs[keyDefOffset].scanLine >= scanLine ) {
                        // If the scanline of the table at our current offset is equal to our
                        // current scanline then we can proceed to analyze it.
                        if(keyDefs[keyDefOffset].scanLine == scanLine) {
                            // If the detected keypress ANDed with the keypress Mask from the table
                            // results in a non-zero value, it means the given key has been pressed.
                            // We also make sure the given keypress is supported in our current
                            // VID/PID mode.
                            if( (keypress & keyDefs[keyDefOffset].keyPressMask) && (vidPidMask & keyDefs[keyDefOffset].vidPidMask)) {
                            //  keypressDebounce[keyDefs[keyDefOffset].hidCode]++;
                            //  if(keypressDebounce[keyDefs[keyDefOffset].hidCode] > 5)
                            //      {
                            //      keypressDebounce[keyDefs[keyDefOffset].hidCode] = 6;
                                    // We check to see if the key that has been pressed is one of the
                                    // keys that is sent back in the modifier byte.
                                    if(keyDefs[keyDefOffset].modBit != 0x00 ) {
                                        modifierByte |= keyDefs[keyDefOffset].modBit;
                                    }
                                    else if(strlen(keypressBuffer) < KEYPRESS_BUFFER_SIZE ) {
                                        // If it was not a modifier byte key and there is still room in the
                                        // keypressBuffer, we will add this key to the buffer.
                                        keypressBuffer[strlen(keypressBuffer)] = keyDefs[keyDefOffset].hidCode;
                                    }
                                    //}
                            //  else
                            //      {
                            //      keypressDebounce[keyDefs[keyDefOffset].hidCode] = 0;
                            //      }
                            } // end of if( (keypress & keyDefs[keyDefOffset].keyPressMask) && (vidPidMask & keyDefs[keyDefOffset].vidPidMask))
                        } // end of if(keyDefs[keyDefOffset].scanLine == scanLine)
                        keyDefOffset++;
                    } // end of while(keyDefs[keyDefOffset].scanLine >= scanLine )

                    // If we reach the end of the keypress table then there's nothing else we can
                    // possibly find, so we exit our scanline loop even if we haven't checked every
                    // scan line.  We also exit if the keypress buffer has been completely filled.
                    // In this case, even if there are more valid keys waiting we won't be able to
                    // store them anyway, so we exit.
                    if(keyDefs[keyDefOffset].scanLine == 0 || strlen(keypressBuffer) >= KEYPRESS_BUFFER_SIZE)
                        break;
					
				} // end of if (keypress == 0x01 ...
			} // end of for(scanLine = 18; scanLine > 0; scanLine--)
			
			// Send the current keyboard buffer to IEP1 to be sent to host
			UpdateIEP1WithKeypress();
		} // end of if(keypressBuffer[0] == 0x00)
	} // end of while(1)
}

/***************************************************************************
 * Function:   ClearKeyBoardBuffer                                         *
 * Programmer: Craig Steiner (csteiner@vaultbbs.com)                       *
 * Description: Clears the keyboard's internal keypress buffer.  The       *
 *    keypress buffer is 6 bytes which represent a maximum of 6 keypresses *
 *    that can be returned via USB.  Once the keypresses are sent via USB, *
 *    this routine may be called to clear the buffer.                      * 
 ***************************************************************************/

void ClearKeyBoardBuffer(void)
{
	BYTE bTemp;

	for(bTemp = 0; bTemp < KEYPRESS_BUFFER_SIZE; bTemp++)
		keypressBuffer[bTemp] = 0x00;
}

/***************************************************************************
 * Function:   UpdateIEP1WithKeypress                                      *
 * Programmer: Craig Steiner (csteiner@vaultbbs.com)                       *
 * Description: Is called by the main() program in order to send the       *
 *    contents of the keypressBuffer[] to the host via USB.  The function  *
 *    does the following:                                                  *
 *                                                                         * 
 *    1. Makes sure the current IEP1 Byte Counter is "NAK", which means    * 
 *       there is nothing pending to send.  Any other value means the last * 
 *       packet sent to the host hasn't been sent yet, so we don't send    * 
 *       anything else until the previous packet is sent.                  * 
 *    2. If nothing is pending to send, the routine constructs the output  * 
 *       data packet in the IEP1 Output buffer, copying the modifier byte, * 
 *       the constant 0x00 byte, and the 6 bytes of keypressBufferp[] data.*   
 *    3. Compares to see if the current packet that is ready to send is    * 
 *       the same as the last packet that was sent.  If it is, it exits    * 
 *       since only *changes* in the keyboard state need to be reported.   *   
 *    4. If all of the above tests are successful, the routine sets the    * 
 *       Byte Counter to 8 which will cause the 8-byte packet to be        * 
 *       sent when the next IEP1 poll is received from the host.           *   
 ***************************************************************************/

void UpdateIEP1WithKeypress(void)
{
	BYTE bTemp;

	// We first check to see if the character count is NAK.  If it's not
	// NAK that means we still have some output pending, so we leave it
	// alone for now.
	
	if(bIEPDCTX_1 != EPBCT_NAK)
		{
		ClearKeyBoardBuffer();
		return;
		}

	// Start by initialization the HID Keyboard report header
	iep1Buffer[0] = modifierByte; // Holds shift, alt, etc.
	iep1Buffer[1] = 0x00; // Second byte is always 0x00
	
	// We now copy the keypress buffer into the rest of the iep1Buffer.
	for(bTemp = 0; bTemp < 6; bTemp++)
		iep1Buffer[2 + bTemp] = keypressBuffer[bTemp];

	// We now compare the currently prepared IEP1 output buffer with the last
	// packet that was sent, which is held in the variable previousIEP1packet.
	// If the current packet is the same as the previous packet sent, we 
	// don't need to do anything since the host will assume the previous state
	// is still current until we report a different state.
	if( memcmp(iep1Buffer, previousIEP1packet, 8) == 0)
		{
		ClearKeyBoardBuffer();
		return;
		}

	// We now check to see if the device is currently suspended.  If it is,
	// the keypress should wake the system up--so we generate a Wakeup
	// pulse so things come back to life.
#ifdef XXX
	if(bSuspended)
		bUSBCTL |= USBCTL_RWUP;
#endif
	// We finally the set the CTX_1 to the number of bytes in the IEP1 output
	// buffer (8).  Thus, the next time the host issues an IN1 poll to the
	// TUSB2136, the data will be sent out immediately.  We will know that
	// the transfer has taken place when the IEP1InterruptHandler() interrupt
	// handler is called.
	bIEPDCTX_1 = 8;
}

/***************************************************************************
 * Function:   IEP1InterruptHandler                                        *
 * Programmer: Craig Steiner (csteiner@vaultbbs.com)                       *
 * Description: This function is the IEP1 interrupt handler.  It is called *
 *    whenever a packet of data has been transmitted from the device to the*
 *    host.  The routine performs the following tasks:                     *
 *                                                                         * 
 *    1. Makes a copy of the data packet that was just sent in the         * 
 *       variable previousIEP1packet.  This is used by the                 *
 *       UpdateIEP1WithKeypress function to determine whether or not there *
 *       has been a change in the keyboard state.                          *   
 *    2. Clears the keypressBuffer to allow the main program loop to       *  
 *       scan the keyboard and generate a new packet.                      *  
 *                                                                         *     
 ***************************************************************************/

void IEP1InterruptHandler(void)
{
	// This interrupt is triggered when we've finished sending a block of data
	// to the host.  At that point we copy the current IEP1 buffer to the
	// "previousIEP1packet" buffer.  This holds a copy of the last data that
	// was sent to the host.  This is used later to see if a subsequent packet
	// is the same as a new packet.  If it is, we won't have to resend it.
	memcpy(previousIEP1packet,  iep1Buffer, 8);
//	BYTE str;
//
//	for(str = 0; str < 8; str++)
//		previousIEP1packet[str] = iep1Buffer[str];
	
	// We clear the keypressBuffer.  The keyboard scan process will only begin
	// if the keypressBuffer is clear.
	ClearKeyBoardBuffer();
}

/***************************************************************************
 * Function:   OEP0SetLEDs                                                 *
 * Programmer: Craig Steiner (csteiner@vaultbbs.com)                       *
 * Description: This function is called by the usbReceiveNextPacketOnOEP0  *
 *    routine when the data packet of a LED SetReport transaction is       *
 *    received.  This routine sets/clears the keyboard LEDs based on the   *
 *    data received from the host.                                         * 
 *                                                                         *     
 ***************************************************************************/

void OEP0SetLEDs(void)
{
// This code is only enabled if this is a "real" keyboard, not the
// demo version selected by DIPSWITCHES.  If it is the demo version,
// changing the values of the P3.2-P3.4 pins seems to cause problems.

	if(bLED & BIT_NUMLOCK)
		PIN_NUMLOCK = 0;
	else
		PIN_NUMLOCK = 1;

	if(bLED & BIT_CAPSLOCK)
		PIN_CAPSLOCK = 0;
	else
		PIN_CAPSLOCK = 1;

	if(bLED & BIT_SCROLLLOCK)
		PIN_SCROLLLOCK = 0;
	else
		PIN_SCROLLLOCK = 1;
}
