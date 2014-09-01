#ifndef	__a2000_H__
#define	__a2000_H__
//	write your header here
//////////////////////////////////////////////////////////////////////////////////////////
// Progarm: SACM-A2000 C API external definition for sacmV26e.lib
// Writen by: Andy
// 	Date: 2000/06/20
// 	Date: 2001/10/11 	Add Manual mode definition
//////////////////////////////////////////////////////////////////////////////////////////

extern int SACM_A2000_Initial(int);					// 
extern void SACM_A2000_ServiceLoop(void);			// For Auto Mode only
extern void SACM_A2000_Play(int,int,int);			// For Auto Mode only
extern void SACM_A2000_Play_EX(int);				// For Auto Mode only/few delay for sentence
extern void SACM_A2000_Stop(void);					// 
extern void SACM_A2000_Pause(void);					// 
extern void SACM_A2000_Resume(void);				// 
extern void SACM_A2000_Volume(int);					// 
extern unsigned int SACM_A2000_Status(void);		// 

extern void SACM_A2000_InitDecoder(int);			// For Manual Mode only
extern void SACM_A2000_Decoder(void);				// For Manual Mode only
extern void SACM_A2000_InitQueue(void);				// For Manual Mode only
extern void SACM_A2000_FillQueue(int);				// For Manual Mode only
extern unsigned int SACM_A2000_TestQueue(void);		// For Manual Mode only

//========================================================================================        
// End of a2000.h
//========================================================================================
#endif
