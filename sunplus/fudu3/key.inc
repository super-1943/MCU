//========================================================================================
// Progarm: The head file for pcplay.asm
// Wrote by: Andy Hsu
// Last modified date: 
// 		2000/06/23: first version
//		2000/07/20: modified
//========================================================================================

.EXTERNAL  F_Key_Scan_Initial;
.EXTERNAL  F_Key_Scan_ServiceLoop;			// 1 scan line +Vcc
.EXTERNAL  F_Key_Scan_ServiceLoop_2;		// 2 scan line +Vcc / IOA
.EXTERNAL  F_Key_DebounceCnt_Down;
.EXTERNAL 	F_SP_GetCh;