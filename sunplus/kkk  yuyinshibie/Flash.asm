//============================================================
// �ļ����ƣ�flash.asm     
// ʵ�ֹ���: SPCE061 32K flash �Ķ�д
// ά����¼�� 2003-6-9 V1.0
//============================================================



.INCLUDE hardware.inc

.DEFINE C_FLASH_SIZE			0x8000
.DEFINE C_FLASH_BLOCK_SIZE		0x100
.DEFINE C_FLASH_MATCH			0xAAAA
.DEFINE C_FLASH_PAGE_ERASE		0x5511		//����һҳ
.DEFINE C_FLASH_MASS_ERASE		0x5522		//
.DEFINE C_FLASH_1WORD_PGM		0x5533		//дһ����
.DEFINE C_FLASH_SEQUENT_PGM		0x5544		//д�����
.DEFINE C_FLASH_MAIN_BLOCK		0x5555		
.DEFINE C_FLASH_INFORM_BLOCK	0x5566		


.CODE
//============================================================================================
//�﷨��void F_FlashWrite1Word(int addr,int Value )
//������дһ���ֵ�FLASH��
//������addr-��д���ݵĴ洢��ַ  Value-��д����
//���أ���
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
//�﷨��F_FlashWrite(int sector,int &num, int size)
//������˳��д�����
//������sector-��д���ݵ���ʼ��ַ &num-��д���� size-д���ݵ�����
//���أ���
//============================================================================================= 
.PUBLIC _F_FlashWrite
_F_FlashWrite: .proc 
	push bp to [sp]
	bp = sp+1
	r1 = [bp+3]						//flash base address
	r2 = [bp+4]						//data
	r3 = [bp+5]						//����ֽ�	
	r4 = C_FLASH_MATCH				//AAAA
	[P_Flash_Ctrl] = r4
L_FlashWriteLoop:
	r4 = C_FLASH_SEQUENT_PGM		//5544
	[P_Flash_Ctrl] = r4
	r4 = [r2++]
	[r1++] = r4

	r3 -= 1
	jnz L_FlashWriteLoop
	[P_Flash_Ctrl] = r3				//д����
	pop bp from [sp]
	retf
	.ENDP


// ============================================================================================
//�﷨��void F_FlashErase(sector)
//����������256�ֽ�
//����: sector-����ҳ����ʼ��ַ
//���أ���
// ============================================================================================
.PUBLIC _F_FlashErase
_F_FlashErase: .proc 
	push bp to [sp]
	bp = sp + 1
	r1 = C_FLASH_MATCH				//AAAA
	[P_Flash_Ctrl] = r1
	r1 = C_FLASH_PAGE_ERASE			//5511
	[P_Flash_Ctrl] = r1
	r1 = [bp+3]						//����һҳ
	[r1] = r1

	pop bp from [sp]
	retf
	.ENDP
    .END

