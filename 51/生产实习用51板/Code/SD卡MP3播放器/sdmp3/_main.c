#include "znFAT.h"
#include "myfun.h"
#include "vs1003.h"
#include "uart.h"
#include"LCD1602.h"
//#include <reg51.h>
/**************************************************************
           +-------------------------------------+
           | 振南电子  实验代码 之 SD卡MP3播放器 |
           +-------------------------------------+
  此源码版权属 振南 全权享有，如欲引用，敬请署名并告知
        严禁随意用于商业目的，违者必究，后果自负
         振南电子 
             ->产品网站 http://www.znmcu.cn/
             ->产品网店 http://shop.znmcu.cn/
             ->产品咨询 QQ:987582714 
			            MSN:yzn07@126.com
	                    WW:yzn07
  运行环境：STC51 1T单片机 22.1184M晶振	 推荐使用 STC12C5A60S2
  程序说明：在此实验中，读取SD卡（事先经过FAT32格式化）根目录下
            的所有音频文件（MP3、WMA、MIDI与WAV）。读文件时，我
			们使用振南的znFAT，并通过数据重定向功能将读到的数据
			直接送到VS1003进行解码播放，在操作的过程中串口输出
			相关信息。
			因为51单片机的速度仍然有限，加之 SD卡、VS1003的通信
			都串行，而且SPI也是IO模拟的，再加之中间还有znFAT这样
			一个文件系统层，因此播放的MP3文件码率不可太高。振南
			建议使用64KBPS左右的MP3为宜。
  注：相关教程请参见 
     《振南带你作实验》51版 之 《SD卡MP3播放器》 一集				  
**************************************************************/
unsigned char Dev_No; //设备号		 //在znfat.h中使用
struct znFAT_Init_Arg *pArg; //用于指针文件系统参数集合的指针
struct znFAT_Init_Arg Init_Arg_SDCARD; //文件系统参数集合，用于记录文件系统的重要参数
struct FileInfoStruct FileInfo_MP3;	//文件参数集合
unsigned char n=0; //文件序号，不断递增以实现文件枚举
int Lcd_j=0;
void main()
{
	LcdInt();
	// LcdShow();
	//  LcdShow_init();
	UART_Init(); //串口初始化
	znFAT_Device_Init(); //存储设备初始化
	pArg=&Init_Arg_SDCARD;	//指针指向SD卡文件系统参数集合，znFAT将从这个集合中获取参数
	Dev_No=SDCARD; //设备号为SDCARD，znFAT依照此设备号选择存储设备驱动
	znFAT_Init();	//文件系统初始化
	UART_Put_Inf("总存储容量：(字节)",pArg->Total_Size);  //从串口输出各种参数信息
	UART_Put_Inf("每扇区字节：(个)",pArg->BytesPerSector);
	UART_Put_Inf("每簇扇区：(个)",pArg->SectorsPerClust);
	VS_Reset(); //VS1003复位初始化
	while(!znFAT_Open_File(&FileInfo_MP3,"\\*.mp3",n,1))	//打开SD卡根目录下所有MP3文件中的第n个
	{
		UART_Send_Str("===========================================================\n");
		UART_Send_Str("打开文件成功\n"); //从串口输出文件参数信息
		UART_Send_Str("文件名为：");
		UART_Send_Str(FileInfo_MP3.FileName);
		UART_Send_Enter();
		UART_Put_Inf("文件大小(字节)：",FileInfo_MP3.FileSize);
		UART_Put_Inf("文件当前偏移量(字节)：",FileInfo_MP3.FileCurOffset);
		UART_Send_Str("文件创建时间：\n");
		UART_Put_Num(FileInfo_MP3.FileCreateDate.year);
		UART_Send_Str("年");
		UART_Put_Num(FileInfo_MP3.FileCreateDate.month);
		UART_Send_Str("月");
		UART_Put_Num(FileInfo_MP3.FileCreateDate.day);
		UART_Send_Str("日");
		UART_Put_Num(FileInfo_MP3.FileCreateTime.hour);
		UART_Send_Str("时");
		UART_Put_Num(FileInfo_MP3.FileCreateTime.min);
		UART_Send_Str("分");
		UART_Put_Num(FileInfo_MP3.FileCreateTime.sec);
		UART_Send_Str("秒");
		UART_Send_Enter();
		VS_Reset();//VS1003复位初始化
		//必须每首歌都复位，否则只能播放一首
		UART_Send_Str1( FileInfo_MP3.FileName);
		VS_sin_test(200); //正弦测试，可以听到一声滴
		znFAT_Read_FileX(&FileInfo_MP3,0,FileInfo_MP3.FileSize,VS_Send_Dat); //调用读取文件函数(重定向)，将数据送至VS1003
		VS_Flush_Buffer(); //清空VS1003的数据缓冲区
		n++;
	}
	UART_Send_Str("===========================================================\n");
	UART_Put_Inf("文件列举完毕，共有文件(个)：",n);
	while(1);
}