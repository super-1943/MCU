.include hardware.inc

.define C_FLASH_SIZE			0x8000
.define C_FLASH_BLOCK_SIZE		0x100 
.define C_FLASH_MATCH			0xAAAA
.define C_FLASH_PAGE_ERASE		0x5511		//erase 1 page
.define C_FLASH_MASS_ERASE		0x5522		//only can execution on STOP=1
.define C_FLASH_1WORD_PGM		0x5533		//write 1 word 
.define C_FLASH_SEQUENT_PGM		0x5544		//write sequential word 
.define C_FLASH_MAIN_BLOCK		0x5555		//
.define C_FLASH_INFORM_BLOCK	0x5566		//
.define P_Flash_Ctrl  			0x7555

//*********************************************************//
//����:F_FlashWrite1Word()
//����:дһ���ֵ�FLASH��
//����:	1����д���ݵĴ洢��ַ
//		2����д����
//����:��
//*********************************************************//
.CODE
.public _F_FlashWrite1Word
_F_FlashWrite1Word:		.proc 
	push bp to [sp]
	bp=sp+1
	r1=C_FLASH_MATCH				//AAAA
	[P_Flash_Ctrl]=r1
	r1=C_FLASH_1WORD_PGM			//5533
	[P_Flash_Ctrl]=r1	
	r1=[bp+3]						//flash address
	r2=[bp+4]						//data
	[r1]=r2
	//delay 40us					//dont need,hardware auto block cpu

	pop bp from [sp]
	retf
	.endp

//*********************************************************//
//����:F_FlashWrite()
//����:˳��д�����
//������1����д���ݵ���ʼ��ַ
//		2����д����
//		3��д���ݵ�����
//����:��
//*********************************************************//
.public _F_FlashWrite
_F_FlashWrite:		.proc 
	push bp to [sp]
	bp=sp+1
	r1=[bp+3]						//flash base address
	r2=[bp+4]						//data
	r3=[bp+5]						//nBytes
	r4=C_FLASH_MATCH				//AAAA
	[P_Flash_Ctrl]=r4
L_FlashWriteLoop:
	r4=C_FLASH_SEQUENT_PGM			//5544
	[P_Flash_Ctrl]=r4	
	r4=[r2++]
	[r1++]=r4
	//delay 40us					//hardware auto block cpu
	r3-=1
	jnz L_FlashWriteLoop	
	[P_Flash_Ctrl]=r3				//end write
	pop bp from [sp]
	retf
	.endp

//*********************************************************//
//����:F_FlashErase()
//����:����256�ֽ�
//����:����ҳ����ʼ��ַ
//����:��
//*********************************************************//
.public _F_FlashErase
_F_FlashErase:		.proc 
	push bp to [sp]
	bp=sp+1

	r1=C_FLASH_MATCH				//AAAA
	[P_Flash_Ctrl]=r1
	r1=C_FLASH_PAGE_ERASE			//5511
	[P_Flash_Ctrl]=r1
	
	r1=[bp+3]						//erase page
	[r1]=r1
	//delay 20ms					//dont need,hardware auto block cpu
	pop bp from [sp]
	retf
	.endp
//*********************************************************//
//����:F_FlashRead()
//����:��flash�ж�������
//����:�������ݵĴ洢��ַ
//����:��
//*********************************************************//
.public _F_FlashRead
_F_FlashRead:		.proc 
	push bp to [sp]
	bp=sp+1
	r2=[bp+3]
	r1=[r2]
	pop bp from [sp]
	retf
	.endp

