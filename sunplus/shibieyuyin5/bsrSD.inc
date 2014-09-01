
.DEFINE BSR_SI_MODE	0
.DEFINE BSR_SD_MODE	1
.DEFINE BSR_MIX_MODE	2

.DEFINE BSR_MIC		0
.DEFINE BSR_LINE_IN	1

.DEFINE BSR_TRAIN_TWICE 	0
.DEFINE BSR_TRAIN_ONCE		1

.DEFINE BSR_SPR512	1
.DEFINE BSR_SPR1024A	2
.DEFINE BSR_SPR4096	3

.EXTERNAL F_BSRStartPlay
//Parameters: R1 = Buffer address, R2 = Number of samples, R3 = Memory bank no.

.EXTERNAL F_BSRAudioStop
//....This function is used to clear all interrupt, so the audio function is disabled.
//Parameters: NONE

.EXTERNAL F_BSR_InitRecognizer
//....This function is used to initialize the recognizer engine.
//Parameters: NONE

.EXTERNAL F_BSR_GetResult
//....This function is used to perform recognition. Return value = 0 if no recognition result
//is available, otherwise it returns the word index.
//Parameters: NONE

.EXTERNAL F_BSR_StopRecognizer

.EXTERNAL F_BSR_GetRecognizerScore
//....This function return the score of current recognizer result. The value is in the range of 
// -0x1000 to 0x1000. Negative value means that the result is rejected.

.EXTERNAL F_BSR_GetRejectedResult

.EXTERNAL F_BSR_EnableCPUIndicator

.EXTERNAL F_BSR_DisableCPUIndicator

.EXTERNAL F_BSR_Train
// Parameter: 
//       R1 = SD Word ID.
//	 R2 = Train mode.
// Return: 
//       R1 = 0: successfully trained.
//       R1 = -1: No voice detected.
//       R1 = -2: Needs to be trained again.
//       R1 = -3: The environment may be too noisy.
//       R1 = -4: database is full.
// Description: 
//       This function is used to train the SD word.
// Each SD word to be trained should be given a unique wordID, this ID is an integer value >= 100.
// When recognizer recognize the trained word, it will return the corresponding word ID to user.

.EXTERNAL F_BSR_IsDBFull
// Parameter: NONE
// Return: 
//	R1 = -1: if SD model space is full.
//      otherwise R1 = 0.
// Description:
//      This function is used to check whether the SD model space is full.
//You can only start the SD training session when there is available SD model space.

.EXTERNAL F_BSR_IsDBEmpty
// Parameter: NONE
// Return:
//      R1 = -1: if SD model space is empty.
//      otherwise R1 = 0
// Description:
//      This function is used to check whether the SD model space is empty.
// You can check the SD model space first (whether it is empty) before doing the SD recognition.

.EXTERNAL F_BSR_DeleteSDWord
// Parameter: 
//      R1 = WordID
// Return: 
//      R1 = 0: if the corresponding SD word is successfully deleted.
//	R1 = -1: if Flash error.
//      R1 = -2: if wordID not found.
// Description:
//      This function is used to delete the trained SD word from SD model space.
//Currently, SD model space can only store five SD command.

.EXTERNAL F_BSR_DeleteAll
.EXTERNAL F_BSR_SetTrainMode
.EXTERNAL F_BSR_GetNumSDWord
.EXTERNAL F_BSR_FlashInit
.EXTERNAL F_BSR_DeleteSDGroup
.EXTERNAL F_BSR_FlashEraseSector
.EXTERNAL F_BSR_FlashWriteByte
.EXTERNAL F_BSR_FlashReadByte
.EXTERNAL F_BSR_FindSDWord
.EXTERNAL F_BSR_GetNumWordErased
.EXTERNAL F_BSR_SelectSDGroup
.EXTERNAL F_BSR_ExportSDWord
.EXTERNAL F_BSR_ImportSDWord
.EXTERNAL F_BSR_FlashSelectBank
.EXTERNAL F_BSR_FlashEraseAll
