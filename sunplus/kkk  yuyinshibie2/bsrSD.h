#ifndef	__BSRSD_H__
#define	__BSRSD_H__
//	write your header here
#define BSR_SI_MODE	0
#define BSR_SD_MODE	1
#define BSR_MIX_MODE	2

#define BSR_MIC		0
#define BSR_LINE_IN	1

#define BSR_TRAIN_TWICE 	0
#define BSR_TRAIN_ONCE	 	1

#define BSR_SPR512	1
#define BSR_SPR1024A	2
#define BSR_SPR4096	3

extern void BSRStartPlay(int *BufferAddr,int NumSample,int BankNo);

extern void BSRAudioStop();
//....This function is used to clear all interrupt, so the audio function is disabled.

extern void BSR_PauseRecognizer();
//....This function is used to temporary stop the recognizer. After calling this function
//all resource can be used by the main program, including CPU, RAM, Audio and Interrupt.
extern void BSR_ResumeRecognizer();
//....Call this function to continue the recognition process after BSRPause().

extern int BSR_InitRecognizer(int AudioSource);

extern int BSR_GetResult(void);
//....This function is used to perform recognition. Return value = 0 if no recognition result
//is available, otherwise it returns the word index.

extern void BSR_StopRecognizer(void);

extern int BSR_GetRecognizerScore(void);
//....This function return the score of current recognizer result. The value is in the range of 
// -0x1000 to 0x1000. Negative value means that the result is rejected.

extern int BSR_GetRejectedResult(void);
//....If current recognizer result is not rejected, this function will return 0.

extern void BSR_EnableCPUIndicator(void);

extern void BSR_DisableCPUIndicator(void);

//..................SD function.....................
extern int BSR_Train(int WordID,int TrainMode);

extern int BSR_IsDBFull();

extern int BSR_IsDBEmpty();

extern int BSR_DeleteSDWord(int WordID);

extern int BSR_DeleteAll();

extern int BSR_GetNumSDWord();

extern int BSR_FlashInit(int FlashType);
//....This function is used to initialize the recognizer engine.
//....FlashType = 1: SPR512 (num. sectors = 128, sector size = 512 Bytes)
//              = 2: SPR1024A (num. sectors = 128, sector size = 1024 Bytes)
//              = 3: SPR4096 (num. sectors = 256, sector size = 2048 Bytes)
//return -1: flash error.
//       -2: flash version mismatch.
//	 -3: flash size is too small (<32KBytes).
//        0: success
extern int BSR_DeleteSDGroup(int SDGroupNo);
//...This function is used to delete the SD words of the given SubGroupNo.
//.. When SDGroupNo = 0, the RAM word model will be erased.
//return -1: flash error.
//        0: success

extern int BSR_SelectSDGroup(int SDSubGroupNo);

extern void BSR_FlashEraseSector(int SectorNo);

extern void BSR_FlashWriteByte(int Addr,int Value);

extern int BSR_FlashReadByte(int Addr);

extern int BSR_FindSDWord(int WordID);

extern int BSR_GetNumWordErased();

extern int BSR_StartQuery();

extern int BSR_QueryNext();

extern int BSR_ExportSDWord(int WordID);

extern int BSR_ImportSDWord();

extern void BSR_FlashSelectBank(int Bankno);

extern void BSR_FlashEraseAll();

#endif
