#include "znFAT.h"
#include "myfun.h"
#include "vs1003.h"
#include "uart.h"
#include"LCD1602.h"
//#include <reg51.h>
/**************************************************************
           +-------------------------------------+
           | ���ϵ���  ʵ����� ֮ SD��MP3������ |
           +-------------------------------------+
  ��Դ���Ȩ�� ���� ȫȨ���У��������ã�������������֪
        �Ͻ�����������ҵĿ�ģ�Υ�߱ؾ�������Ը�
         ���ϵ��� 
             ->��Ʒ��վ http://www.znmcu.cn/
             ->��Ʒ���� http://shop.znmcu.cn/
             ->��Ʒ��ѯ QQ:987582714 
			            MSN:yzn07@126.com
	                    WW:yzn07
  ���л�����STC51 1T��Ƭ�� 22.1184M����	 �Ƽ�ʹ�� STC12C5A60S2
  ����˵�����ڴ�ʵ���У���ȡSD�������Ⱦ���FAT32��ʽ������Ŀ¼��
            ��������Ƶ�ļ���MP3��WMA��MIDI��WAV�������ļ�ʱ����
			��ʹ�����ϵ�znFAT����ͨ�������ض����ܽ�����������
			ֱ���͵�VS1003���н��벥�ţ��ڲ����Ĺ����д������
			�����Ϣ��
			��Ϊ51��Ƭ�����ٶ���Ȼ���ޣ���֮ SD����VS1003��ͨ��
			�����У�����SPIҲ��IOģ��ģ��ټ�֮�м仹��znFAT����
			һ���ļ�ϵͳ�㣬��˲��ŵ�MP3�ļ����ʲ���̫�ߡ�����
			����ʹ��64KBPS���ҵ�MP3Ϊ�ˡ�
  ע����ؽ̳���μ� 
     �����ϴ�����ʵ�顷51�� ֮ ��SD��MP3�������� һ��				  
**************************************************************/
unsigned char Dev_No; //�豸��		 //��znfat.h��ʹ��
struct znFAT_Init_Arg *pArg; //����ָ���ļ�ϵͳ�������ϵ�ָ��
struct znFAT_Init_Arg Init_Arg_SDCARD; //�ļ�ϵͳ�������ϣ����ڼ�¼�ļ�ϵͳ����Ҫ����
struct FileInfoStruct FileInfo_MP3;	//�ļ���������
unsigned char n=0; //�ļ���ţ����ϵ�����ʵ���ļ�ö��
int Lcd_j=0;
void main()
{
	LcdInt();
	// LcdShow();
	//  LcdShow_init();
	UART_Init(); //���ڳ�ʼ��
	znFAT_Device_Init(); //�洢�豸��ʼ��
	pArg=&Init_Arg_SDCARD;	//ָ��ָ��SD���ļ�ϵͳ�������ϣ�znFAT������������л�ȡ����
	Dev_No=SDCARD; //�豸��ΪSDCARD��znFAT���մ��豸��ѡ��洢�豸����
	znFAT_Init();	//�ļ�ϵͳ��ʼ��
	UART_Put_Inf("�ܴ洢������(�ֽ�)",pArg->Total_Size);  //�Ӵ���������ֲ�����Ϣ
	UART_Put_Inf("ÿ�����ֽڣ�(��)",pArg->BytesPerSector);
	UART_Put_Inf("ÿ��������(��)",pArg->SectorsPerClust);
	VS_Reset(); //VS1003��λ��ʼ��
	while(!znFAT_Open_File(&FileInfo_MP3,"\\*.mp3",n,1))	//��SD����Ŀ¼������MP3�ļ��еĵ�n��
	{
		UART_Send_Str("===========================================================\n");
		UART_Send_Str("���ļ��ɹ�\n"); //�Ӵ�������ļ�������Ϣ
		UART_Send_Str("�ļ���Ϊ��");
		UART_Send_Str(FileInfo_MP3.FileName);
		UART_Send_Enter();
		UART_Put_Inf("�ļ���С(�ֽ�)��",FileInfo_MP3.FileSize);
		UART_Put_Inf("�ļ���ǰƫ����(�ֽ�)��",FileInfo_MP3.FileCurOffset);
		UART_Send_Str("�ļ�����ʱ�䣺\n");
		UART_Put_Num(FileInfo_MP3.FileCreateDate.year);
		UART_Send_Str("��");
		UART_Put_Num(FileInfo_MP3.FileCreateDate.month);
		UART_Send_Str("��");
		UART_Put_Num(FileInfo_MP3.FileCreateDate.day);
		UART_Send_Str("��");
		UART_Put_Num(FileInfo_MP3.FileCreateTime.hour);
		UART_Send_Str("ʱ");
		UART_Put_Num(FileInfo_MP3.FileCreateTime.min);
		UART_Send_Str("��");
		UART_Put_Num(FileInfo_MP3.FileCreateTime.sec);
		UART_Send_Str("��");
		UART_Send_Enter();
		VS_Reset();//VS1003��λ��ʼ��
		//����ÿ�׸趼��λ������ֻ�ܲ���һ��
		UART_Send_Str1( FileInfo_MP3.FileName);
		VS_sin_test(200); //���Ҳ��ԣ���������һ����
		znFAT_Read_FileX(&FileInfo_MP3,0,FileInfo_MP3.FileSize,VS_Send_Dat); //���ö�ȡ�ļ�����(�ض���)������������VS1003
		VS_Flush_Buffer(); //���VS1003�����ݻ�����
		n++;
	}
	UART_Send_Str("===========================================================\n");
	UART_Put_Inf("�ļ��о���ϣ������ļ�(��)��",n);
	while(1);
}