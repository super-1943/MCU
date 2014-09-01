//////////////////////////////////////////////////////////////////
// Function: SRAM access function for SACM_DVR Auto Mode
//////////////////////////////////////////////////////////////////
.INCLUDE hardware.inc
.RAM 
.PUBLIC  HighAddr      
.VAR  HighAddr

.CODE
//*********************************************************//
// дSRAM��ʼ��
//*********************************************************//
.PUBLIC _SP_InitWriteSRAM
.PUBLIC F_SP_InitWriteSRAM 
_SP_InitWriteSRAM:         .PROC
F_SP_InitWriteSRAM:
		push r1 to [sp]         
        pop r1 from [sp]
        retf 
        .ENDP

//*********************************************************//
//��SRAM��ʼ��
//*********************************************************//
.PUBLIC F_SP_InitReadSRAM 
.PUBLIC _SP_InitReadSRAM 

_SP_InitReadSRAM:          .PROC
F_SP_InitReadSRAM:
		push r1 to [sp]
        pop r1 from [sp]
        retf 
        .ENDP

//*********************************************************//
//����������main.c
//��SRAM�ж�����
//*********************************************************//  
.PUBLIC _SP_ReadSRAM 
_SP_ReadSRAM:              .PROC
        push bp to [sp]     
        pop bp from [sp] 
        retf 
        .ENDP
       
.PUBLIC F_SP_ReadSRAM
F_SP_ReadSRAM:
        push r2,r4 to [sp]
       
      
		pop r2,r4 from [sp]      
        retf 

//*********************************************************//
//��SRAM��д����
//*********************************************************//  
.PUBLIC _SP_WriteSRAM 
_SP_WriteSRAM: .PROC
        push bp to [sp] 
      
        pop bp from [sp] 
        retf 
        .ENDP

.PUBLIC F_SP_WriteSRAM
F_SP_WriteSRAM:
        push r1,r3 to [sp]
        
        
        pop r1,r3 from [sp]
        retf 

        

//=============================================================       
// End of sram.asm
//=============================================================
     