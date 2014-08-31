#ifndef __ZNFAT_H__
#define __ZNFAT_H__

#include "mytype.h" //�����ض���

/*******************************************************

        +-----------------------------------------+
        |���ϵ��� ԭ������ģ�� znFAT�ļ�ϵͳ 5.18 |
        +-----------------------------------------+

  ��Դ���Ȩ�� ���� ȫȨ���У��������ã�������������֪
        �Ͻ�����������ҵĿ�ģ�Υ�߱ؾ�������Ը�
         ���ϵ��� 
             ->��Ʒ��վ http://www.znmcu.cn/
             ->��Ʒ��̳ http://bbs.znmcu.cn/
             ->��Ʒ���� http://shop.znmcu.cn/
             ->��Ʒ��ѯ QQ:987582714 MSN:yzn07@126.com
	                WW:yzn07
˵����znFAT���෽���ԣ�ȷ������ȷ�����ȶ��ԣ������ʹ�ã�
      ����bug�����֪��лл����				  
********************************************************/

//znFAT�Ĳü���---------------------------------------------------------
//#define  ZNFAT_ENTER_DIR	 //�д˺꣬���� znFAT_Enter_Dir() �������
#define  ZNFAT_OPEN_FILE	 //�д˺꣬���� znFAT_Open_File() �������
//#define  ZNFAT_SEEK_FILE	 //�д˺꣬���� znFAT_Seek_File() �������
//#define  ZNFAT_READ_FILE	 //�д˺꣬���� znFAT_Read_File() �������
#define  ZNFAT_READ_FILEX	 //�д˺꣬���� znFAT_Read_FileX() �������
//#define  ZNFAT_ADD_DAT	     //�д˺꣬���� znFAT_Add_Dat() �������
//#define  ZNFAT_CREATE_DIR	 //�д˺꣬���� znFAT_Create_Dir() �������
//#define  ZNFAT_CREATE_FILE	 //�д˺꣬���� znFAT_Create_File() �������
//#define  ZNFAT_DEL_FILE	     //�д˺꣬���� znFAT_Del_File() �������
//#define  ZNFAT_XCOPY_FILE	 //�д˺꣬���� znFAT_XCopy_File() �������
//#define  ZNFAT_RENAME_FILE	 //�д˺꣬���� znFAT_Rename_File() �������

//#define ZNFAT_GET_TOTAL_SIZE  //�д˺꣬���� znFAT_Get_Total_Size() �������
//#define znFAT_GET_REMAIN_CAP  //�д˺꣬���� znFAT_Get_Remain_Cap() �������

#include "cj.h"
#include "cj.h"
//----------------------------------------------------------------------

#define SOC(c) (((c-pArg->FirstDirClust)*(pArg->SectorsPerClust))+pArg->FirstDirSector) // ���ڼ���صĿ�ʼ����
#define CONST const

//�豸��
#define SDCARD 0 //SD��
#define UDISK  1 //U��
#define CFCARD 2 //CF��
#define OTHER  3 //����
				 //����Ĵ洢�豸������������䣬��ʵ�ֶԸ���洢�豸��֧��
//-------------------------------------------

#define MAKE_FILE_TIME(h,m,s)	((((unsigned int)h)<<11)+(((unsigned int)m)<<5)+(((unsigned int)s)>>1))	/* ����ָ��ʱ������ļ�ʱ������ */
#define MAKE_FILE_DATE(y,m,d)	(((((unsigned int)y)+20)<<9)+(((unsigned int)m)<<5)+((unsigned int)d))	/* ����ָ�������յ��ļ��������� */

//DPT:������¼�ṹ����
struct PartRecord
{
 UINT8 Active;         //0x80��ʾ�˷�����Ч
 UINT8 StartHead;      //�����Ŀ�ʼ��ͷ
 UINT8 StartCylSect[2];//��ʼ����������
 UINT8 PartType;       //��������
 UINT8 EndHead;        //�����Ľ���ͷ
 UINT8 EndCylSect[2];  //��������������
 UINT8 StartLBA[4];    //�����ĵ�һ������
 UINT8 Size[4];        //�����Ĵ�С 
};

//MBR:��������������0��������������
struct PartSector
{
 UINT8 PartCode[446]; //MBR����������
 struct PartRecord Part[4];   //4��������¼
 UINT8 BootSectSig0;  //55
 UINT8 BootSectSig1;  //AA
};


//znFAT�ж�BPB�Ķ�������  һ��ռ��90���ֽ�
struct znFAT_BPB
{
 UINT8 BS_jmpBoot[3];     //��תָ��            offset: 0
 UINT8 BS_OEMName[8];     //                    offset: 3
 UINT8 BPB_BytesPerSec[2];//ÿ�����ֽ���        offset:11
 UINT8 BPB_SecPerClus[1]; //ÿ��������          offset:13
 UINT8 BPB_RsvdSecCnt[2]; //����������Ŀ        offset:14
 UINT8 BPB_NumFATs[1];    //�˾���FAT����       offset:16
 UINT8 BPB_RootEntCnt[2]; //znFATΪ0            offset:17
 UINT8 BPB_TotSec16[2];   //znFATΪ0            offset:19
 UINT8 BPB_Media[1];      //�洢����            offset:21
 UINT8 BPB_FATSz16[2];    //znFATΪ0            offset:22
 UINT8 BPB_SecPerTrk[2];  //�ŵ�������          offset:24
 UINT8 BPB_NumHeads[2];   //��ͷ��              offset:26
 UINT8 BPB_HiddSec[4];    //FAT��ǰ��������     offset:28
 UINT8 BPB_TotSec32[4];   //�þ���������        offset:32
 UINT8 BPB_FATSz32[4];    //һ��FAT��������     offset:36
 UINT8 BPB_ExtFlags[2];   //znFAT����           offset:40
 UINT8 BPB_FSVer[2];      //znFAT����           offset:42
 UINT8 BPB_RootClus[4];   //��Ŀ¼�غ�          offset:44
 UINT8 FSInfo[2];         //��������FSINFO������offset:48
 UINT8 BPB_BkBootSec[2];  //ͨ��Ϊ6             offset:50
 UINT8 BPB_Reserved[12];  //��չ��              offset:52
 UINT8 BS_DrvNum[1];      //                    offset:64
 UINT8 BS_Reserved1[1];   //                    offset:65
 UINT8 BS_BootSig[1];     //                    offset:66
 UINT8 BS_VolID[4];       //                    offset:67
 UINT8 BS_FilSysType[11]; //	                offset:71
 UINT8 BS_FilSysType1[8]; //"znFAT    "         offset:82
};

struct znFAT_FAT_Item
{
 UINT8 Item[4];
};

struct znFAT_FAT
{
 struct znFAT_FAT_Item Items[128];
};

struct direntry 
{
 UINT8 deName[8];       // �ļ��������㲿���Կո񲹳�
 UINT8 deExtension[3]; 	// ��չ�������㲿���Կո񲹳�
 UINT8 deAttributes;   	// �ļ�����
 UINT8 deLowerCase;    	// 0
 UINT8 deCHundredth;   	// ����
 UINT8 deCTime[2];     	// ����ʱ��
 UINT8 deCDate[2];     	// ��������
 UINT8 deADate[2];     	// ��������
 UINT8 deHighClust[2];  // ��ʼ�صĸ���
 UINT8 deMTime[2];     	// ������޸�ʱ��
 UINT8 deMDate[2];     	// ������޸�����
 UINT8 deLowCluster[2]; 	// ��ʼ�صĵ���
 UINT8 deFileSize[4];      // �ļ���С 
};

//znFAT��ʼ��ʱ��ʼ����װ�����½ṹ����
struct znFAT_Init_Arg
{
 UINT8 DEV_No;

 UINT8 BPB_Sector_No;   //BPB����������
 UINT32 Total_Size;      //���̵�������

 UINT32 FirstDirClust;   //��Ŀ¼�Ŀ�ʼ��
 UINT32  BytesPerSector;	//ÿ���������ֽ���
 UINT32  FATsectors;      //FAT����ռ������
 UINT32  SectorsPerClust;	 //ÿ�ص�������
 UINT32 FirstFATSector;	 //��һ��FAT����������
 UINT32 FirstDirSector;	 //��һ��Ŀ¼��������
};

struct Date
{
 UINT16 year;
 UINT8 month;
 UINT8 day;
};

struct Time
{
 UINT8 hour;
 UINT8 min;
 UINT8 sec;
};

// Stuctures
struct FileInfoStruct
{
	UINT8  FileName[15];       //�ļ���
	UINT32  FileStartCluster;   //�ļ��Ŀ�ʼ��
	UINT32  FileCurCluster;	//�ļ��ĵ�ǰ��
	UINT32  FileSize;	    	//�ļ���С 
	UINT32  FileCurSector;	    //�ļ��ĵ�ǰ����
	UINT16   FileCurPos;         //�ļ��ڵ�ǰ�����е�λ��
	UINT32  FileCurOffset;	    //�ļ��ĵ�ǰƫ����
	UINT32  Rec_Sec;            //�ļ����ļ�/Ŀ¼�����ڵ�����
	UINT16   nRec;               //�ļ����ļ�/Ŀ¼�����������е�λ��
	UINT8  FileAttr;	    //�ļ�����				
	struct Time    FileCreateTime;	    //�ļ��Ĵ���ʱ��
	struct Date    FileCreateDate;	    //�ļ��Ĵ�������
	struct Time    FileMTime;          //�ļ����޸�ʱ��
	struct Date    FileMDate;          //�ļ����޸�����
	struct Date	FileADate;          //�ļ��ķ�������
};

struct FSInfo //znFAT���ļ�ϵͳ��Ϣ�ṹ
{
	UINT8 Head[4];
	UINT8 Resv1[480];
	UINT8 Sign[4];
	UINT8 Free_Cluster[4];
	UINT8 Last_Cluster[4];
	UINT8 Resv2[14];
	UINT8 Tail[2];
};

extern struct znFAT_Init_Arg *pArg; //��ʼ�������ṹ��ָ�룬����ָ��ĳһ�洢�豸�ĳ�ʼ�������ṹ�壬���ⲿ�ṩ
extern UINT8 Dev_No;//�豸�ţ��ⲿ����

//��������
void znFAT_Device_Init();

UINT32 znFAT_Get_Total_Size(void); //��ȡ������
UINT32 znFAT_Get_Remain_Cap(void); //��ȡʣ������

void znFAT_Init(void); //�ļ�ϵͳ��ʼ��
UINT32 znFAT_Enter_Dir(CONST INT8 *path); //����Ŀ¼
UINT8 znFAT_Open_File(struct FileInfoStruct *pfi,CONST INT8 *filepath,UINT32 item,UINT8 is_file); //���ļ���֧��ͨ��
UINT8 znFAT_Seek_File(struct FileInfoStruct *pfi,UINT32 offset); //�ļ���λ 
UINT32 znFAT_Read_File(struct FileInfoStruct *pfi,UINT32 offset,UINT32 len,UINT8 *pbuf); //��ȡ�ļ�����
UINT32 znFAT_Read_FileX(struct FileInfoStruct *pfi,UINT32 offset,UINT32 len,void (*pfun)(UINT8)); //��ȡ�ļ����ݲ��������ݴ���
UINT32 znFAT_Add_Dat(struct FileInfoStruct *pfi,UINT32 len,UINT8 *pbuf); //���ļ�׷������
UINT8 znFAT_Create_Dir(CONST INT8 *dirpath,UINT8 *ptd); //����Ŀ¼��֧�ִ���ʱ��
UINT8 znFAT_Create_File(struct FileInfoStruct *pfi,CONST INT8 *filepath,UINT8 *ptd); //�����ļ���֧�ִ���ʱ��
UINT8 znFAT_Del_File(CONST INT8 *filepath); //ɾ���ļ�
unsigned char znFAT_XCopy_File(struct znFAT_Init_Arg *pArg1,struct znFAT_Init_Arg *pArg2,CONST INT8 *sfilename,CONST INT8 *tfilename,UINT8 *file_buf,UINT32 buf_size,unsigned char *pt); //�ļ�������֧�ֶ��豸���ļ�����
UINT8 znFAT_File_Close(struct FileInfoStruct *pfi); //�ļ��ر�
UINT8 znFAT_Rename_File(CONST INT8 *filename,CONST INT8 *newfilename); //�ļ�������

#endif
