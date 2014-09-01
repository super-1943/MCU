//////////////////////////////////////////////////////////////////////////////////////////
// Progarm: SACM-A2000 API external definition for sacmV26e.lib
// Writen by: Andy
// 	Date: 2000/06/20
// 	Date: 2001/10/11 	Add Manual mode definition
//////////////////////////////////////////////////////////////////////////////////////////

.EXTERNAL F_SACM_A2000_Initial						// 
.EXTERNAL F_SACM_A2000_ServiceLoop					// For Auto Mode only
.EXTERNAL F_SACM_A2000_Play							// For Auto Mode only
.EXTERNAL F_SACM_A2000_Play_Ex						// For Auto Mode only/few delay for sentence
.EXTERNAL F_SACM_A2000_Stop							// 
.EXTERNAL F_SACM_A2000_Pause						// 
.EXTERNAL F_SACM_A2000_Resume						// 
.EXTERNAL F_SACM_A2000_Volume						// 
.EXTERNAL F_SACM_A2000_Status						// 

.EXTERNAL F_SACM_A2000_InitDecoder					// For Manual Mode only
.EXTERNAL F_SACM_A2000_Decoder						// For Manual Mode only
.EXTERNAL F_SACM_A2000_InitQueue					// For Manual Mode only
.EXTERNAL F_SACM_A2000_FillQueue					// For Manual Mode only
.EXTERNAL F_SACM_A2000_TestQueue					// For Manual Mode only

.EXTERNAL F_FIQ_Service_SACM_A2000					// ISR


//========================================================================================        
// End of a2000.inc
//========================================================================================
        