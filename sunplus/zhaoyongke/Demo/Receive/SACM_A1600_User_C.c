//========================================================
//	文件名称：	SACM_A1600_User_C.c
//	功能描述：	A1600用户函数（C语言版），用于保存或获取语音资源数据
//				包括：
//					void USER_A1600_GetResource_Init(unsigned int SoundIndex);
//					void USER_A1600_GetResource(unsigned int *p_Buf, unsigned int Words);
//				这些函数被语音库自动调用，可根据需要自行修改这些函数的内容
//	维护记录：	2006-10-16	v1.0, by Qwerty
//========================================================

//======================================================
//	外部函数和变量声明
//======================================================
extern unsigned int *SACM_A1600_SpeechTable;		// 语音资源列表，在resource.asm中定义

//========================================================================
//	全局变量定义
//========================================================================
unsigned int ResAddr;								

//========================================================================
//	语法格式：	void USER_A1600_GetResource_Init(unsigned int SoundIndex);
//	实现功能：	(被A1600函数库自动调用)获取语音资源数据，初始化操作
//	参数：		SoundIndex:		语音资源序号
//	返回值：		无
//========================================================================
void USER_A1600_GetResource_Init(unsigned int SoundIndex)
{
	unsigned int *p_Addr;
	p_Addr = *(&SACM_A1600_SpeechTable + SoundIndex);
	ResAddr = *p_Addr;								// 获取待播放语音的起始地址
}

//========================================================================
//	语法格式：	void USER_A1600_GetResource(unsigned int *p_Buf, unsigned int Words);
//	实现功能：	(被A1600函数库自动调用)获取语音资源数据，并填充到解码队列中
//	参数：		p_Buf:		待填充解码队列的起始地址(该参数由函数库自动产生)
//				Words:		待填充数据的数量，单位为Word(该参数由函数库自动产生)
//	返回值：	无
//========================================================================
void USER_A1600_GetResource(unsigned int *p_Buf, unsigned int Words)
{
	while(Words>0)
	{
		*p_Buf = *(unsigned int*)ResAddr;
		p_Buf++;
		ResAddr++;
		Words--;
	}
}

