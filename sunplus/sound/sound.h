#ifndef	__SOUND_h__
#define	__SOUND_h__
//	write your header here
void PlaySnd(unsigned int SndIndex);

enum SndIndex{										// 所有语音资源的索引
	S_0, S_1, S_2, S_3, S_4, S_5, S_6, S_7, S_8, S_9, S_10, 
	S_11, S_12, S_Liang, S_DING, S_XZSK, S_LC, S_SW, S_XW, S_WS, 
	S_Nian, S_Yue, S_Ri, S_Dian, S_Fen, S_Miao, S_Zheng	
};

#endif
