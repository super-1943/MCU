//============================================================
// 文件名称：flash.asm     
// 实现功能: SPCE061 32K flash 的读写
// 维护记录： 2003-6-9 V1.0
//============================================================



.INCLUDE hardware.inc

.DEFINE C_FLASH_SIZE			0x8000
.DEFINE C_FLASH_BLOCK_SIZE		0x100
.DEFINE C_FLASH_MATCH			0xAAAA
.DEFINE C_FLASH_PAGE_ERASE		0x5511		//擦除一页
.DEFINE C_FLASH_MASS_ERASE		0x5522		//
.DEFINE C_FLASH_1WORD_PGM		0x5533		//写一个字
.DEFINE C_FLASH_SEQUENT_PGM		0x5544		//写多个字
.DEFINE C_FLASH_MAIN_BLOCK		0x5555		
.DEFINE C_FLASH_INFORM_BLOCK	0x5566		


.CODE
//============================================================================================
//语法：void F_FlashWrite1Word(int addr,int Value )
//描述：写一个字到FLASH中
//参数：addr-被写数据的存储地址  Value-被写数据
//返回：无
//===============================================================================================
.PUBLIC _F_FlashWrite1Word
.DEFINE  P_Flash_Ctrl  0x7555
_F_FlashWrite1Word:	 .proc 
	push bp to [sp]
	bp = sp+1
	r1 = C_FLASH_MATCH				//AAAA
	[P_Flash_Ctrl] = r1
	r1 = C_FLASH_1WORD_PGM			//5533
	[P_Flash_Ctrl] = r1
	r1 =  [bp+3]					//flash address
	r2 =  [bp+4]					//data
	[r1] = r2
	
	pop bp from [sp]
	retf
	.ENDP

//=============================================================================================
//语法：F_FlashWrite(int sector,int &num, int size)
//描述：顺序写多个字
//参数：sector-被写数据的起始地址 &num-被写数据 size-写数据的数量
//返回：无
//============================================================================================= 
.PUBLIC _F_FlashWrite
_F_FlashWrite: .proc 
	push bp to [sp]
	bp = sp+1
	r1 = [bp+3]						//flash base address
	r2 = [bp+4]						//data
	r3 = [bp+5]						//多个字节	
	r4 = C_FLASH_MATCH				//AAAA
	[P_Flash_Ctrl] = r4
L_FlashWriteLoop:
	r4 = C_FLASH_SEQUENT_PGM		//5544
	[P_Flash_Ctrl] = r4
	r4 = [r2++]
	[r1++] = r4

	r3 -= 1
	jnz L_FlashWriteLoop
	[P_Flash_Ctrl] = r3				//写结束
	pop bp from [sp]
	retf
	.ENDP


// ============================================================================================
//语法：void F_FlashErase(sector)
//描述：擦除256字节
//参数: sector-擦除页的起始地址
//返回：无
// ============================================================================================
.PUBLIC _F_FlashErase
_F_FlashErase: .proc 
	push bp to [sp]
	bp = sp + 1
	r1 = C_FLASH_MATCH				//AAAA
	[P_Flash_Ctrl] = r1
	r1 = C_FLASH_PAGE_ERASE			//5511
	[P_Flash_Ctrl] = r1
	r1 = [bp+3]						//擦除一页
	[r1] = r1

	pop bp from [sp]
	retf
	.ENDP
    .END

