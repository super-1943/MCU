.INCLUDE hardware.inc;

.PUBLIC	F_Key_Scan_Initial;
.PUBLIC _Key_Scan_ServiceLoop;
.PUBLIC F_Key_Scan_ServiceLoop;

.PUBLIC F_Key_DebounceCnt_Down;
.PUBLIC _SP_GetCh;
.PUBLIC	F_SP_GetCh;

.PUBLIC R_KeyStrobe;

//////////////////////////////////////////////////////////////////
// RAM Define Area								
//////////////////////////////////////////////////////////////////
.RAM
.VAR	R_DebounceReg;						//for keyboard scan
.DEFINE C_DebounceCnt			0x0002;		

.VAR	R_DebounceCnt;						//for keyboard scan
.VAR	R_KeyBuf;							//for keyboard scan
.VAR	R_KeyStrobe;						//for keyboard scan

.CODE
//////////////////////////////////////////////////////////////////
// Function: Initialization for F_Key_Scan_ServiceLoop
//////////////////////////////////////////////////////////////////     
_Key_Scan_ServiceLoop:
F_Key_Scan_Initial:
		r1 = 0x0000;					//
		[R_DebounceReg] = r1;			//
		[R_KeyBuf] = r1; 				//
		[R_KeyStrobe] = r1;				//
		r1 = C_DebounceCnt;				//
		[R_DebounceCnt] = r1;			//reset debounce counter
		retf;

//////////////////////////////////////////////////////////////////
// Function: Get Key code from key pad(8 x 1 key pad)
// Input: Port IOA b7-b0
// Output: R_KeyStrobe b7-b0
//          | 	  |     |     | 
// +Vcc --- x --- x ... x --- x ---   
//          |     |     |     |
//          IOA.7             IOA.0
// Note: 1)link F_DebounceCntDown is necessary 
// Destory register: r1, r2                                            
////////////////////////////////////////////////////////////////// 
F_Key_Scan_ServiceLoop:
		
     	r1 = [P_IOA_Data];			// get key data from IOA   
    	//r1 = [P_IOB_Data];			// get key data from IOB
	    	
        r1 = r1 and 0xff;				//
        r2 = [R_DebounceReg];			//
        [R_DebounceReg] = r1;			//
        cmp r2,[R_DebounceReg];			//
        je	L_KS_StableTwoSample;		//
        
        r1 = C_DebounceCnt;				//debounce time setting
        [R_DebounceCnt] = r1;			//
        retf;							//
        
L_KS_StableTwoSample:
		r1 = [R_DebounceCnt];			//
		jz	L_KS_StableOverDebounce;	//
		retf;
	
L_KS_StableOverDebounce:        
		[R_DebounceCnt] = r1;			//
		r2 = [R_DebounceReg];			//
		r1 = [R_KeyBuf];				//
		[R_KeyBuf] = r2;				//
		r1 = r1 xor 0x00ff;				//
		r1 = r1 and [R_KeyBuf];			//
		r1 = r1 and 0x00ff;				//
		r1 = r1 or [R_KeyStrobe];		//
		[R_KeyStrobe] = r1;				//save stable key code to R_KeyStrobe
		retf;		
	
//////////////////////////////////////////////////////////////////
// Function: debounce counter down count
//////////////////////////////////////////////////////////////////
F_Key_DebounceCnt_Down:
		r1 = [R_DebounceCnt];			// Debounce subroutine for F_IO_Key_Scan:
		jz	L_DebounceCntZero;			// stop count if zero
		r1 -= 0x0001;					//
		[R_DebounceCnt] = r1;			//
L_DebounceCntZero:						//
		retf;  							//	


//****************************************************************
// Function: Get Keycode for I/O Port                                 
// Destory register: r1, r2                          
//****************************************************************
_SP_GetCh:					
F_SP_GetCh:
		//push	BP,BP to [SP];
  		//BP = SP + 1;
		  
		r1 = [R_KeyStrobe];				// Get Key code
        r2 = 0x0000;					// Clear KeyStrobe for next key	
        [R_KeyStrobe] = r2;				//
        //pop		BP,BP from [SP];
        retf;


//========================================================================================        
// End of key.asm
//========================================================================================
