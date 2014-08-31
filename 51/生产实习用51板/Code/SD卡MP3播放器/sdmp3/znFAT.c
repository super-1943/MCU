#include "znfat.h"
#include "sd.h"        //�洢�豸��������д������������SD��
//#include "ch375.h"	   //�洢�豸��������д������������U��
//#include "cf.h"
#include "string.h"
#include<reg51.h>
sfr P1M1 = 0x91;
sfr P1M0 = 0x92;

/*******************************************************

        +-----------------------------------------+
        |���ϵ��� ԭ������ģ�� znFAT�ļ�ϵͳ 5.18 |
        +-----------------------------------------+

  ��Դ���Ȩ�� ���� ȫȨ���У��������ã�������������֪
        �Ͻ�����������ҵĿ�ģ�Υ�߱ؾ�������Ը�
         ���ϵ��� 
             ->��Ʒ��վ http://www.znmcu.cn/
             ->��Ʒ���� http://shop.znmcu.cn/
             ->��Ʒ��ѯ QQ:987582714 
			            MSN:yzn07@126.com
	                    WW:yzn07
˵����znFAT���෽���ԣ�ȷ������ȷ�����ȶ��ԣ������ʹ�ã�
      ����bug�����֪��лл����				  
********************************************************/

//ȫ�ֱ�������
struct direntry temp_rec;
INT8 temp_dir_name[13]; 
UINT32 temp_dir_cluster;
UINT32 temp_last_cluster;

UINT8 znFAT_Buffer[512]; //�������ݶ�д������,���ⲿ�ṩ

/******************************************************************
 - ����������znFAT�Ĵ洢�豸��ʼ������
 - ����ģ�飺znFAT�ļ�ϵͳģ��
 - �������ԣ��ⲿ�����ڶԴ洢�豸���г�ʼ����
 - ����˵������
 - ����˵������
 - ע���ڵ�znFAT��������֮ǰ�������ȶԴ洢�豸���гɹ��ĳ�ʼ����
 ******************************************************************/

void znFAT_Device_Init()
{
	SD_Reset();
	SD_Init(); 
}

/******************************************************************
 - ����������znFAT�Ĵ洢�豸�ײ������ӿڣ���ȡ�洢�豸��addr������
             512���ֽڵ����ݷ���buf���ݻ�������
 - ����ģ�飺znFAT�ļ�ϵͳģ��
 - �������ԣ��ڲ���������洢�豸�ĵײ������Խӣ�
 - ����˵����addr:������ַ
             buf:ָ�����ݻ�������ָ��
 - ����˵����0��ʾ��ȡ�����ɹ�������ʧ��
 - ע����������������Ǿ������ϵ����ִ洢�豸����SD������Ч����U�̡�
       CF��ͨ���ڳ����ж�̬���л���ͬ���豸�������Ӷ�ʵ�ֶ��豸(��ͬ
	   ʱ�Զ��ִ洢�豸���в����������SD�������ļ���U�̵ȵ�)����ͬ
	   �������л���ֻ��Ҫ�ڳ����иı�Dev_No���ȫ�ֱ�����ֵ����
 ******************************************************************/

UINT8 znFAT_ReadSector(UINT32 addr,UINT8 *buf) 
{
 switch(Dev_No)	//��Dev_No��������ʹ�õĴ洢�豸����
 {
  case SDCARD:
         return SD_Read_Sector(addr,buf);
         break;
  case UDISK:
         //return CH375_Read_Sector(addr,buf);
         break;
  case CFCARD:
         //return CF_Read_Sector(addr,buf);
         break;
  case OTHER:
         //return XXX_Read_Sector(addr,buf);
         break;
 }
}

/******************************************************************
 - ����������znFAT�Ĵ洢�豸�ײ������ӿڣ���buf���ݻ������е�512��
             �ֽڵ�����д�뵽�洢�豸��addr������
 - ����ģ�飺znFAT�ļ�ϵͳģ��
 - �������ԣ��ڲ���������洢�豸�ĵײ������Խӣ�
 - ����˵����addr:������ַ
             buf:ָ�����ݻ�����
 - ����˵����0��ʾ��ȡ�����ɹ�������ʧ��
 - ע����
 ******************************************************************/

UINT8 znFAT_WriteSector(UINT32 addr,UINT8 *buf)
{
 switch(Dev_No)	//��Dev_No��������ʹ�õĴ洢�豸����
 {
  case SDCARD:
         return SD_Write_Sector(addr,buf);
         break;
  case UDISK:
         //return CH375_Write_Sector(addr,buf);
         break;
  case CFCARD:
         //return CF_WriteSector(addr,buf);
         break;
  case OTHER:
         //return XXX_Write_Sector(addr,buf);
         break;
 }
}

/******************************************************************
 - ����������С��ת��ˣ���LittleEndian��BigEndian
 - ����ģ�飺znFAT�ļ�ϵͳģ��
 - �������ԣ��ڲ�
 - ����˵����dat:ָ��ҪתΪ��˵��ֽ�����
             len:ҪתΪ��˵��ֽ����г���
 - ����˵����תΪ���ģʽ���ֽ���������������
 - ע�����磺С��ģʽ��       0x33 0x22 0x11 0x00  (���ֽ���ǰ)
             תΪ���ģʽ��Ϊ 0x00 0x11 0x22 0x33  (���ֽ���ǰ)
             ��������ֵΪ   0x00112233
             (CISC��CPUͨ����С�˵ģ�����znFATҲ���ΪС�ˣ�����Ƭ��
              ����RISC��CPU��ͨ����˵���Ǵ�˵ģ�������Ҫ�����������
              �ڵĴ�Ŵ�����е��������ܵõ���ȷ����ֵ)
 ******************************************************************/

UINT32 LE2BE(UINT8 *dat,UINT8 len) 
{
	UINT32 temp=0;
	UINT32 fact=1;
	UINT8  i=0;
	for(i=0;i<len;i++)
	{
		temp+=dat[i]*fact; //�����ֽڳ�����Ӧ��Ȩֵ���ۼ�
		fact*=256; //����Ȩֵ
	}
	return temp;
}

//-----------------------------------

/**************************************************************************
 - �������������ĳ���ص��������������0
 - ����ģ�飺znFAT�ļ�ϵͳģ��
 - �������ԣ��ڲ�
 - ����˵����cluster:Ҫ��յĴصĴغ�
 - ����˵������
 **************************************************************************/
#ifdef ZNFAT_EMPTY_CLUSTER

void znFAT_Empty_Cluster(UINT32 Cluster)
{
 UINT32 iSec;
 UINT16 i;
 for(i=0;i<pArg->BytesPerSector;i++)
 {
  znFAT_Buffer[i]=0;
 }
 for(iSec=SOC(Cluster);iSec<SOC(Cluster)+pArg->SectorsPerClust;iSec++)
 {
  znFAT_WriteSector(iSec,znFAT_Buffer);
 }
}

#endif
/***********************************************************************
 - ������������ȡʣ������
 - ����ģ�飺znFAT�ļ�ϵͳģ��
 - �������ԣ��ⲿ��ʹ�û�ʹ��
 - ����˵������    
 - ����˵����ʣ����������λ�ֽ�
 - ע����FSInfo�ж�ȡ���д��������Ӽ���õ�ʣ�����������λ�ֽ�
 ***********************************************************************/
#ifdef znFAT_GET_REMAIN_CAP

UINT32 znFAT_Get_Remain_Cap(void)
{
 znFAT_ReadSector(1+pArg->BPB_Sector_No,znFAT_Buffer);
 if(((struct FSInfo *)znFAT_Buffer)->Free_Cluster[0]==0xff 
 && ((struct FSInfo *)znFAT_Buffer)->Free_Cluster[1]==0xff 
 && ((struct FSInfo *)znFAT_Buffer)->Free_Cluster[2]==0xff 
 && ((struct FSInfo *)znFAT_Buffer)->Free_Cluster[3]==0xff)
 return pArg->Total_Size;
 else
 return LE2BE(((struct FSInfo *)znFAT_Buffer)->Free_Cluster,4)*pArg->SectorsPerClust*pArg->BytesPerSector; 
}

#endif

//--------------------------------------------

/******************************************************************
 - ������������С���ַ�תΪ��д
 - ����ģ�飺znFAT�ļ�ϵͳģ��
 - �������ԣ��ڲ�
 - ����˵����c:Ҫת��Ϊ��д���ַ�            
 - ����˵����Ҫת�����ֽڵ���Ӧ�Ĵ�д�ַ�
 - ע��ֻ��Сд�ַ���Ч���������a~z��Сд�ַ�����ֱ�ӷ���
 ******************************************************************/

INT8 L2U(INT8 c)
{
 if(c>='a' && c<='z') return c+'A'-'a';
 else return c;
}

/***********************************************************************
 - �����������õ�DBR���ڵ�������(���û��MBR����DBR����0����)
 - ����ģ�飺znFAT�ļ�ϵͳģ��
 - �������ԣ��ڲ�
 - ����˵������     
 - ����˵����DBR��������ַ
 - ע��DBR�а����˺ܶ����õĲ�����Ϣ�������ȷ��λDBR������λ�ã��Ǽ�Ϊ
       ��Ҫ�ģ����潫��ר�ŵĺ�����DBR���н�������ȷ����DBR��ʵ��znFAT��
       ����
 ***********************************************************************/

UINT16 znFAT_Find_DBR(void)
{
 UINT16 sec_dbr;
 znFAT_ReadSector(0,znFAT_Buffer);
 if(znFAT_Buffer[0]!=0xeb) 
 {
  sec_dbr=LE2BE(((((struct PartSector *)(znFAT_Buffer))->Part[0]).StartLBA),4);
 }
 else
 {
  sec_dbr=0;
 }
 return sec_dbr;
}

/***********************************************************************
 - ������������ȡ������������
 - ����ģ�飺znFAT�ļ�ϵͳģ��
 - �������ԣ��ⲿ��ʹ�û�ʹ��
 - ����˵������     
 - ����˵������������ֵ����λΪ�ֽ�
 - ע������õ�����������znFAT������������һ��С��ʵ�ʵ���������
 ***********************************************************************/
#ifdef ZNFAT_GET_TOTAL_SIZE

UINT32 znFAT_Get_Total_Size(void) 
{
 return pArg->Total_Size;
}

#endif
/***********************************************************************
 - ������������ȡFSInfo��ȡ�����һ�����ÿ��д�
 - ����ģ�飺znFAT�ļ�ϵͳģ��
 - �������ԣ��ڲ�
 - ����˵������     
 - ����˵���������һ�����ÿ��д�
 - ע��znFAT�е�FSInfo����(����1����)�м�¼�������һ�����ÿ��д�
 ***********************************************************************/

UINT32 Search_Last_Usable_Cluster(void)
{
 znFAT_ReadSector(1+pArg->BPB_Sector_No,znFAT_Buffer);
 return LE2BE(((struct FSInfo *)znFAT_Buffer)->Last_Cluster,4);
}

/***********************************************************************
 - ����������znFAT�ļ�ϵͳ��ʼ��
 - ����ģ�飺znFAT�ļ�ϵͳģ��
 - �������ԣ��ⲿ��ʹ�û�ʹ��
 - ����˵����znFAT_Init_Arg���͵Ľṹ��ָ�룬����װ��һЩ��Ҫ�Ĳ�����Ϣ��
             �Ա�����ʹ��     
 - ����˵������
 - ע����ʹ��znFATǰ����������Ǳ����ȱ����õģ����ܶ������Ϣװ�뵽
       argָ��Ľṹ���У�����������С����Ŀ¼��λ�á�FAT���С�ȵȡ�
       ��Щ�������󲿷���������DBR��BPB�У���˴˺�����Ҫ������DBR�Ĳ�������
 ***********************************************************************/

void znFAT_Init(void)
{
	struct znFAT_BPB *bpb;
	bpb=(struct znFAT_BPB *)(znFAT_Buffer);               //�����ݻ�����ָ��תΪstruct znFAT_BPB ��ָ��
	pArg->DEV_No=Dev_No; //װ���豸��
	pArg->BPB_Sector_No   =znFAT_Find_DBR();               //znFAT_FindBPB()���Է���BPB���ڵ�������
	znFAT_ReadSector(pArg->BPB_Sector_No,znFAT_Buffer);
	pArg->FATsectors      =LE2BE((bpb->BPB_FATSz32)    ,4);//װ��FAT��ռ�õ���������FATsectors��
	pArg->FirstDirClust   =LE2BE((bpb->BPB_RootClus)   ,4);//װ���Ŀ¼�غŵ�FirstDirClust��
	pArg->BytesPerSector  =LE2BE((bpb->BPB_BytesPerSec),2);//װ��ÿ�����ֽ�����BytesPerSector��
	pArg->SectorsPerClust =LE2BE((bpb->BPB_SecPerClus) ,1);//װ��ÿ����������SectorsPerClust ��
	pArg->FirstFATSector  =LE2BE((bpb->BPB_RsvdSecCnt) ,2)+pArg->BPB_Sector_No;//װ���һ��FAT�������ŵ�FirstFATSector ��
	pArg->FirstDirSector  =(pArg->FirstFATSector)+(bpb->BPB_NumFATs[0])*(pArg->FATsectors); //װ���һ��Ŀ¼������FirstDirSector��
	pArg->Total_Size      =LE2BE((bpb->BPB_TotSec32),4)*pArg->BytesPerSector;         //���̵�����������λ���ֽ�
	temp_last_cluster=Search_Last_Usable_Cluster();
}

/***********************************************************************
 - ��������������FSInfo�еĿ��ÿ��дص�����
 - ����ģ�飺znFAT�ļ�ϵͳģ��
 - �������ԣ��ڲ�
 - ����˵����PlusOrMinus:���ÿ��д�����1���1    
 - ����˵������
 - ע�������ļ���׷�����ݡ�ɾ���ļ��Ȳ��������ܻ�ʹ���õĿ��д����仯
       Ҫ��ʱ����
 ***********************************************************************/
#ifdef ZNFAT_UPDATE_FSINFO_FREE_CLU

void znFAT_Update_FSInfo_Free_Clu(UINT32 PlusOrMinus)
{
 UINT32 Free_Clu=0;
 znFAT_ReadSector(1+pArg->BPB_Sector_No,znFAT_Buffer);

 Free_Clu=(znFAT_Get_Remain_Cap())/(pArg->SectorsPerClust*pArg->BytesPerSector);

 if(PlusOrMinus) Free_Clu++;
 else Free_Clu--;

 ((struct FSInfo *)znFAT_Buffer)->Free_Cluster[0]=Free_Clu&0x000000ff;//((UINT8 *)&Free_Clu)[0]; 
 ((struct FSInfo *)znFAT_Buffer)->Free_Cluster[1]=(Free_Clu&0x0000ff00)>>8;//((UINT8 *)&Free_Clu)[1];
 ((struct FSInfo *)znFAT_Buffer)->Free_Cluster[2]=(Free_Clu&0x00ff0000)>>16;//((UINT8 *)&Free_Clu)[2];
 ((struct FSInfo *)znFAT_Buffer)->Free_Cluster[3]=(Free_Clu&0xff000000)>>24;//((UINT8 *)&Free_Clu)[3];
 znFAT_WriteSector(1+pArg->BPB_Sector_No,znFAT_Buffer);   
}

#endif
/***********************************************************************
 - ��������������FSInfo�е���һ�����ÿ��дصĴغ�
 - ����ģ�飺znFAT�ļ�ϵͳģ��
 - �������ԣ��ڲ�
 - ����˵����Last_Clu:��Ҫ���µ�FSInfo�е���һ�����ÿ��дصĴغ�    
 - ����˵������
 - ע��FSInfo�е���һ�����ÿ��дغſ��Ը��ļ�ϵͳһ���ο���ֱ�Ӹ����ļ�ϵͳ
       ��һ�����õĿ��д���ʲô�ط�
 ***********************************************************************/
#ifdef ZNFAT_UPDATE_FSINFO_LAST_CLU

void znFAT_Update_FSInfo_Last_Clu(UINT32 Last_Clu)
{
 znFAT_ReadSector(1+pArg->BPB_Sector_No,znFAT_Buffer);  
 ((struct FSInfo *)znFAT_Buffer)->Last_Cluster[0]=Last_Clu&0x000000ff;//((UINT8 *)&Last_Clu)[0]; 
 ((struct FSInfo *)znFAT_Buffer)->Last_Cluster[1]=(Last_Clu&0x0000ff00)>>8;//((UINT8 *)&Last_Clu)[1];
 ((struct FSInfo *)znFAT_Buffer)->Last_Cluster[2]=(Last_Clu&0x00ff0000)>>16;//((UINT8 *)&Last_Clu)[2];
 ((struct FSInfo *)znFAT_Buffer)->Last_Cluster[3]=(Last_Clu&0xff000000)>>24;//((UINT8 *)&Last_Clu)[3];
 znFAT_WriteSector(1+pArg->BPB_Sector_No,znFAT_Buffer);
}

#endif
/***********************************************************************
 - ���������������һ���صĴغ�
 - ����ģ�飺znFAT�ļ�ϵͳģ��
 - �������ԣ��ڲ�
 - ����˵����LastCluster:��׼�غ�  
 - ����˵����LastClutster����һ�صĴغ�
 - ע�������һ�صĴغţ�����ƾ��FAT��������¼�Ĵ�����ϵ��ʵ�ֵ�
 ***********************************************************************/
#ifdef ZNFAT_GETNEXTCLUSTER

UINT32 znFAT_GetNextCluster(UINT32 LastCluster)
{
 UINT32 temp;
 struct znFAT_FAT *pFAT;
 struct znFAT_FAT_Item *pFAT_Item;
 temp=((LastCluster/128)+pArg->FirstFATSector);
 znFAT_ReadSector(temp,znFAT_Buffer);
 pFAT=(struct znFAT_FAT *)znFAT_Buffer;
 pFAT_Item=&((pFAT->Items)[LastCluster%128]);
 return LE2BE((UINT8 *)pFAT_Item,4);
}

#endif
/***********************************************************************
 - �����������Ƚ�Ŀ¼��
 - ����ģ�飺znFAT�ļ�ϵͳģ��
 - �������ԣ��ڲ�
 - ����˵����a:ָ��Ŀ¼��1��ָ��
             b:ָ��Ŀ¼��2��ָ��
 - ����˵�����������Ŀ¼����ͬ�ͷ���1������Ϊ0
 ***********************************************************************/
#ifdef COMPARE_DIR_NAME

UINT8 Compare_Dir_Name(CONST INT8 *a,CONST INT8 *b)
{
 UINT8 i;
 for(i=0;i<8;i++)
 {
  if(a[i]!=b[i]) return 0;
 }
 return 1;
}

#endif
/***********************************************************************
 - �����������ļ���ƥ��(֧�ִ�*?ͨ������ļ�����ƥ��)
 - ����ģ�飺znFAT�ļ�ϵͳģ��
 - �������ԣ��ڲ�
 - ����˵����pat:Դ�ļ��������Ժ�*��?ͨ��� �� *.txt �� A?.mp3�ȵ�
             name:Ŀ���ļ���
 - ����˵������������ļ���ƥ��ͷ���1������Ϊ0
 - ע������ͨ���ļ���ƥ�䣬�����������ӣ����� A*.txt �� ABC.txt��ƥ���
   ͬʱ�� ABCDE.txtҲ��ƥ��ġ��˹������ļ�ö���н����õ�������ƥ��
   �ļ�������һ���������ļ�
 ***********************************************************************/
#ifdef FILENAMEMATCH

UINT8 FilenameMatch(INT8 *pat,INT8 *name)
{
 UINT8 match,ndone;
 INT8 *cpp,*cpn;
 cpp=pat;
 cpn=name;
 match=1;
 ndone=1;
 while(ndone)
 {
  switch (*cpp)
  {
   case '*':
            cpp++;
            cpn=strchr(cpn,*cpp);
            if(cpn==NULL)
            {
             cpn=name;
             while(*cpn) cpn++;
            }
            break;
   case '?':
            cpp++;
            cpn++;
            break;
   case 0:
            if(*cpn!=0)
            match=0;
            ndone=0;
            break;
   default:
            if((*cpp)==(*cpn))
            {
             cpp++;
             cpn++;
            }
            else
            {
             match=0;
             ndone=0;
            }
            break;
  }
 }
 return(match);
}

#endif
/***********************************************************************
 - ����������znFAT���ļ�Ŀ¼����ļ����ֶ�(8���ֽ�)��תΪ��ͨ���ļ���
             �磺ABC     MP3 ��תΪ ABC.MP3
 - ����ģ�飺znFAT�ļ�ϵͳģ��
 - �������ԣ��ڲ�
 - ����˵����dName��ָ���ļ�Ŀ¼����ļ����ֶε�ָ��
             pName��ָ��ת����ɺ���ļ���
 - ����˵������
 - ע���˺�����������FilenameMatch�������Ϳ���ʵ�ֶ��ļ���ͨ��ƥ��
 ***********************************************************************/
#ifdef ZNFAT_TOFILENAME

void znFAT_toFileName(CONST INT8 *dName,INT8 *pName)
{
 UINT8 i=0;
 for(i=0;i<8;i++) pName[i]=dName[i];
 pName[8]='.';
 for(i=9;i<12;i++) pName[i]=dName[i-1];
 i--;
 while(pName[i]==0x20) pName[i--]=0;
 pName[i+1]=0;i=7;
 while(pName[i--]==0x20);i+=2;
 strcpy(pName+i,pName+8);
} 

#endif
/***********************************************************************
 - �������������ַ����е�Сд�ַ���תΪ��д�ַ�
 - ����ģ�飺znFAT�ļ�ϵͳģ��
 - �������ԣ��ڲ�
 - ����˵����str��ָ���ת�����ַ���
 - ����˵������
 - ע�����ļ���������£��ļ����е��ַ���ʵ���Ǵ�д�ַ���Ϊ�˷��㣬���ļ�
       ����תΪ��д
 ***********************************************************************/
#ifdef STR2UP

void Str2Up(INT8 *str)
{
 UINT8 len=strlen(str),i;
 for(i=0;i<len;i++)
 {
  str[i]=L2U(str[i]); 
 } 
}

#endif
/**************************************************************************
 - ��������������һ��Ŀ¼
 - ����ģ�飺znFAT�ļ�ϵͳģ��
 - �������ԣ��ⲿ��ʹ�û�ʹ��
 - ����˵����path:Ŀ¼��·�� ���磺"\\dir1\\dir2\\" �����һ������\\���� 
 - ����˵��������Ŀ¼�Ŀ�ʼ�غţ��������Ŀ¼ʧ�ܣ�����Ŀ¼�����ڣ��򷵻�0
 - ע���˺����ɺ����znFAT_Open_File�Ⱥ������ã�����ʵ�ִ�����Ŀ¼�µ��ļ�
       �������û�����
 **************************************************************************/
#ifdef ZNFAT_ENTER_DIR

UINT32 znFAT_Enter_Dir(CONST INT8 *path)
{
 UINT32 Cur_Clust,sec_temp,iSec,iDir,Old_Clust;
 UINT8 i=1,counter=0,flag=0;
 struct direntry *pDir;
 INT8 name[20];

 Cur_Clust=pArg->FirstDirClust;
 if(path[1]==0 && path[0]=='\\') return Cur_Clust;
 else
 {
  while(path[i]!=0)
  {
   if(path[i]=='\\')
   {
    for(;counter<8;counter++)
	{
	 name[counter]=' ';
	}
	name[counter]=0;
	counter=0;
	
	do
	{
	 sec_temp=(SOC(Cur_Clust));
	 for(iSec=sec_temp;iSec<sec_temp+pArg->SectorsPerClust;iSec++)
	 {
	  znFAT_ReadSector(iSec,znFAT_Buffer);
	  for(iDir=0;iDir<pArg->BytesPerSector;iDir+=sizeof(struct direntry))
      {
       pDir=((struct direntry *)(znFAT_Buffer+iDir));
	   if(Compare_Dir_Name(pDir->deName,name) && (pDir->deAttributes&0x10))
	   {
	    flag=1;
		Cur_Clust=LE2BE(pDir->deLowCluster,2)+LE2BE(pDir->deHighClust,2)*65536;
		iDir=pArg->BytesPerSector;
		iSec=sec_temp+pArg->SectorsPerClust;
	   } 
	  }
	 }
	 Old_Clust=Cur_Clust;
	}while(!flag && (Cur_Clust=znFAT_GetNextCluster(Cur_Clust))!=0x0fffffff);
	if(!flag) 
	{
	 temp_dir_cluster=Old_Clust;
	 strcpy(temp_dir_name,name);
	 flag=0;
	 return 0;
	}
	flag=0; 
   }
   else
   {
    name[counter++]=(L2U(path[i]));
   }
   i++;
  }
 }
 name[counter]=0; 
 flag=1;
 temp_dir_cluster=Cur_Clust;
 strcpy(temp_dir_name,name);
 return Cur_Clust;
}

#endif
/**************************************************************************
 - ������������һ���ļ�(֧���ļ���ͨ�䣬�� A*.txt �� *.*)
 - ����ģ�飺znFAT�ļ�ϵͳģ��
 - �������ԣ��ⲿ��ʹ�û�ʹ��
 - ����˵����pfi: FileInfoStruct���͵Ľṹ��ָ�룬����װ���ļ��Ĳ�����Ϣ
              �����ļ��Ĵ�С���ļ������ơ��ļ��Ŀ�ʼ�صȵȣ��Ա�����ʹ��
             filepath: �ļ���·����֧�������Ŀ¼ ����
              "\\dir1\\dir2\\dir3\\....\\test.txt"
			 item�����ļ�������ͨ���*��?������£�ʵ����֮ƥ����ļ�����
			 һ����item���Ǵ򿪵��ļ����������������ͨ���������ļ���6����
			 ���item=3����ô�˺����ͻ����6���ļ��а�˳���ź�Ϊ3���Ǹ�
			 �ļ�(item��Ŵ�0��ʼ)
 - ����˵����0���ɹ� 1���ļ������� 2��Ŀ¼������
 - ע�����ļ����ɹ��кܶ�ԭ�򣬱����ļ������ڡ��ļ���ĳһ��Ŀ¼������
       ͨ������������������ļ�����С��item��ֵ�ȵ�
	   ͨ������£��ļ�����û��ͨ�����item��ֵ����ȡ0�Ϳ�����
 **************************************************************************/
#ifdef ZNFAT_OPEN_FILE

UINT8 znFAT_Open_File(struct FileInfoStruct *pfi,CONST INT8 *filepath,UINT32 item,UINT8 is_file)
{
 UINT32 Cur_Clust,sec_temp,iSec,iFile,iItem=0;
 UINT8 flag=0,index=0,i=0,h=0;
 struct direntry *pFile;
 INT8 temp_file_name[30];

 while(filepath[i]!=0)
 {
  if(filepath[i]=='\\') index=i;
  i++;
 }
 if(Cur_Clust=znFAT_Enter_Dir(filepath))
 {
  Str2Up(temp_dir_name);
 do
 { 
  sec_temp=SOC(Cur_Clust);
  for(iSec=sec_temp;iSec<sec_temp+pArg->SectorsPerClust;iSec++)
  {	
   znFAT_ReadSector(iSec,znFAT_Buffer);
   for(iFile=0;iFile<pArg->BytesPerSector;iFile+=sizeof(struct direntry))
   {
    pFile=((struct direntry *)(znFAT_Buffer+iFile));
    if(pFile->deAttributes&(is_file?0x20:0x10))
   {
	znFAT_toFileName(pFile->deName,temp_file_name);
	if(is_file) 
	{
	 i=0;
	 while(temp_dir_name[i]!=0) {if(temp_dir_name[i++]=='.') h=1;}
	 if(!h) {temp_dir_name[i]='.';temp_dir_name[i+1]=0;} 
	}
	if(FilenameMatch(temp_dir_name,temp_file_name) && pFile->deName[0]!=0xe5 && pFile->deAttributes&(is_file?0x20:0x10)) //ƥ���ļ���
	{ 
	 if(item==iItem)
	 {	 
	 flag=1;
     Cur_Clust=LE2BE(pFile->deLowCluster,2)+LE2BE(pFile->deHighClust,2)*65536;

     pfi->FileSize=LE2BE(pFile->deFileSize,4);
	 if(pFile->deAttributes&0x10) 
	  temp_file_name[strlen(temp_file_name)-1]=0;

	 strcpy(pfi->FileName,temp_file_name);
	 pfi->FileStartCluster=LE2BE(pFile->deLowCluster,2)+LE2BE(pFile->deHighClust,2)*65536;
	 pfi->FileCurCluster=pfi->FileStartCluster;
	 pfi->FileCurSector=SOC(pfi->FileStartCluster);
	 pfi->FileCurPos=0;
	 pfi->FileCurOffset=0;
	 pfi->Rec_Sec=iSec;
	 pfi->nRec=iFile;

	 pfi->FileAttr=pFile->deAttributes;
	 sec_temp=LE2BE(pFile->deCTime,2);
	 (pfi->FileCreateTime).sec=(sec_temp&0x001f)*2;
	 (pfi->FileCreateTime).min=((sec_temp>>5)&0x003f);
	 (pfi->FileCreateTime).hour=((sec_temp>>11)&0x001f);
	 sec_temp=LE2BE(pFile->deCDate,2);
	 (pfi->FileCreateDate).day=((sec_temp)&0x001f);
	 (pfi->FileCreateDate).month=((sec_temp>>5)&0x000f);
	 (pfi->FileCreateDate).year=((sec_temp>>9)&0x007f)+1980;

	 sec_temp=LE2BE(pFile->deMTime,2);
	 (pfi->FileMTime).sec=(sec_temp&0x001f)*2;
	 (pfi->FileMTime).min=((sec_temp>>5)&0x003f);
	 (pfi->FileMTime).hour=((sec_temp>>11)&0x001f);
	 sec_temp=LE2BE(pFile->deMDate,2);
	 (pfi->FileMDate).day=((sec_temp)&0x001f);
	 (pfi->FileMDate).month=((sec_temp>>5)&0x000f);
	 (pfi->FileMDate).year=((sec_temp>>9)&0x007f)+1980;

	 sec_temp=LE2BE(pFile->deADate,2);
	 (pfi->FileADate).day=((sec_temp)&0x001f);
	 (pfi->FileADate).month=((sec_temp>>5)&0x000f);
	 (pfi->FileADate).year=((sec_temp>>9)&0x007f)+1980;
	    
	 iFile=pArg->BytesPerSector;
	 iSec=sec_temp+pArg->SectorsPerClust;
	 }
	 else
	 {
	  iItem++;
	 }
	} 
   }
   }
  }
 }while(!flag && (Cur_Clust=znFAT_GetNextCluster(Cur_Clust))!=0x0fffffff);
 if(!flag) 
 {
  return 1;
 }
 return 0;
 }
 else
 {
  return 2; 
 }
}

#endif
/**************************************************************************
 - �����������ļ���λ
 - ����ģ�飺znFAT�ļ�ϵͳģ��
 - �������ԣ��ⲿ��ʹ�û�ʹ��
 - ����˵����pfi:FileInfoStruct���͵Ľṹ��ָ�룬����װ���ļ�������Ϣ���ļ�
             ��λ��pfi��ָ��Ľṹ���е���ز����ͱ������ˣ������ļ��ĵ�ǰ
             �������ļ���ǰ�����е�λ�ã��ļ��ĵ�ǰƫ�����ȵȣ��Ա�����ʹ��
             offset:Ҫ��λ��ƫ���������offset�����ļ��Ĵ�С����λ���ļ���
             ĩβ
 - ����˵�����ļ���λ�ɹ�����0������Ϊ1
 - ע���˺����������znFAT_Read_File���ã�����ʵ�ִ�ָ��λ�ö�ȡ���ݣ�������
       �û�ֱ�ӵ���Щ����
 **************************************************************************/
#ifdef ZNFAT_SEEK_FILE

UINT8 znFAT_Seek_File(struct FileInfoStruct *pfi,UINT32 offset)
{
 UINT32 i,temp;

if(offset<=pfi->FileSize)
{ 
 if(offset==pfi->FileCurOffset)
 {
  pfi->FileCurPos%=pArg->BytesPerSector;
  return 1;  
 }
 if(offset<pfi->FileCurOffset) 
 {
  pfi->FileCurCluster=pfi->FileStartCluster;
  pfi->FileCurSector=SOC(pfi->FileCurCluster);
  pfi->FileCurPos=0;
  pfi->FileCurOffset=0;
 } 
 if((offset-pfi->FileCurOffset)>=(pArg->BytesPerSector-pfi->FileCurPos))	 //Ŀ��ƫ�������ļ���ǰƫ����������ֽ�����С���ļ��ڵ�ǰ�����е�λ�õ�����ĩβ���ֽ���
 {
  pfi->FileCurOffset+=(pArg->BytesPerSector-pfi->FileCurPos);
  pfi->FileCurPos=0;
  if(pfi->FileCurSector-SOC(pfi->FileCurCluster)==(pArg->SectorsPerClust-1))
  {
   pfi->FileCurCluster=znFAT_GetNextCluster(pfi->FileCurCluster);
   pfi->FileCurSector=SOC(pfi->FileCurCluster);
  }
  else
  {
   pfi->FileCurSector++; 
  }
 }
 else
 {
  pfi->FileCurPos=(pfi->FileCurPos+offset-pfi->FileCurOffset)%pArg->BytesPerSector;
  pfi->FileCurOffset=offset;
  return 1;
 }
 temp=SOC(pfi->FileCurCluster);
 if((offset-(pfi->FileCurOffset))/pArg->BytesPerSector+(pfi->FileCurSector-temp)>(pArg->SectorsPerClust-1))
 {
  pfi->FileCurOffset+=(((pArg->SectorsPerClust)-(pfi->FileCurSector-(SOC(pfi->FileCurCluster))))*pArg->BytesPerSector);
  pfi->FileCurCluster=znFAT_GetNextCluster(pfi->FileCurCluster);
  pfi->FileCurSector=SOC(pfi->FileCurCluster);
  pfi->FileCurPos=0;
 }
 else
 {
  pfi->FileCurSector+=(offset-pfi->FileCurOffset)/pArg->BytesPerSector;
  pfi->FileCurPos=(offset-pfi->FileCurOffset)%pArg->BytesPerSector;
  pfi->FileCurOffset=offset;
  return 1;
 }

 temp=(offset-pfi->FileCurOffset)/(pArg->BytesPerSector*pArg->SectorsPerClust);
 for(i=0;i<temp;i++)
 {
  pfi->FileCurCluster=znFAT_GetNextCluster(pfi->FileCurCluster);
 }
 pfi->FileCurOffset+=(temp*(pArg->BytesPerSector*pArg->SectorsPerClust));
 pfi->FileCurSector=(SOC(pfi->FileCurCluster))+(offset-pfi->FileCurOffset)/pArg->BytesPerSector;
 pfi->FileCurPos=((offset-pfi->FileCurOffset))%pArg->BytesPerSector;
 pfi->FileCurOffset=offset;
}
else
{
 return 1;
}
 return 0;
}

#endif
/**************************************************************************
 - �������������ļ���ĳһ��λ�ô�����ȡһ�����ȵ����ݣ��������ݻ�������
 - ����ģ�飺znFAT�ļ�ϵͳģ��
 - �������ԣ��ⲿ��ʹ�û�ʹ��
 - ����˵����pfi:FileInfoStruct���͵Ľṹ��ָ�룬����װ���ļ�������Ϣ���ļ�
             ��ȡ�Ĺ����У��˽ṹ���е���ز�������£������ļ��ĵ�ǰƫ������
             �ļ��ĵ�ǰ�������ļ��ĵ�ǰ�صȵ�
             offset:Ҫ��λ��ƫ������ҪС���ļ��Ĵ�С 
             len:Ҫ��ȡ�����ݵĳ��ȣ����len+offset�����ļ��Ĵ�С����ʵ�ʶ�
             ȡ���������Ǵ�offset��ʼ���ļ�����
             pbuf:���ݻ�����
 - ����˵������ȡ����ʵ�ʵ����ݳ��ȣ������ȡʧ�ܣ�����ָ����ƫ�����������ļ�
             ��С���򷵻�0
 - ע���ڶ�ȡһ���ļ�������ǰ�������Ƚ����ļ���znFAT_Open_File��
 **************************************************************************/
#ifdef ZNFAT_READ_FILE

UINT32 znFAT_Read_File(struct FileInfoStruct *pfi,UINT32 offset,UINT32 len,UINT8 *pbuf)
{
 UINT32 i,j,k,temp;
 UINT32 counter=0;
 if(offset<pfi->FileSize)
 {
  if(offset+len>pfi->FileSize) len=pfi->FileSize-offset;
  znFAT_Seek_File(pfi,offset);
  
  znFAT_ReadSector(pfi->FileCurSector,znFAT_Buffer);
  for(i=pfi->FileCurPos;i<pArg->BytesPerSector;i++)
  {
   if(counter>=len) 
   {
     return len;
   }
   pbuf[counter]=znFAT_Buffer[i];
   counter++;
   pfi->FileCurPos++;
   pfi->FileCurOffset++;
  }
  if(pfi->FileCurSector-(SOC(pfi->FileCurCluster))!=(pArg->SectorsPerClust-1))
  {
   for(j=pfi->FileCurSector+1;j<(SOC(pfi->FileCurCluster))+pArg->SectorsPerClust;j++)
   {
    znFAT_ReadSector(j,znFAT_Buffer);
    pfi->FileCurSector=j;
    for(i=0;i<pArg->BytesPerSector;i++)
    {
     if(counter>=len)
     {
       return len;
     }
     pbuf[counter]=znFAT_Buffer[i];
     counter++;
     pfi->FileCurPos++;
     pfi->FileCurOffset++;
    }
   }
  } 
  temp=(len-counter)/(pArg->BytesPerSector*pArg->SectorsPerClust);
  for(k=0;k<temp;k++)
  {
   pfi->FileCurCluster=znFAT_GetNextCluster(pfi->FileCurCluster);
   for(j=(SOC(pfi->FileCurCluster));j<(SOC(pfi->FileCurCluster))+pArg->SectorsPerClust;j++)
   {
    znFAT_ReadSector(j,znFAT_Buffer);
    pfi->FileCurSector=j;
    for(i=0;i<pArg->BytesPerSector;i++)
    {
     if(counter>=len)  
 	 {
       return len;
     }
     pbuf[counter]=znFAT_Buffer[i];
     counter++;
     pfi->FileCurOffset++;
	 pfi->FileCurPos++;
	 pfi->FileCurPos%=pArg->BytesPerSector;
    } 
   }    
  }
  pfi->FileCurCluster=znFAT_GetNextCluster(pfi->FileCurCluster);
  temp=(SOC(pfi->FileCurCluster))+((len-counter)/pArg->BytesPerSector);
  pfi->FileCurSector=(SOC(pfi->FileCurCluster));
  for(j=(SOC(pfi->FileCurCluster));j<temp;j++)
  {
   znFAT_ReadSector(j,znFAT_Buffer);
   pfi->FileCurSector=j;
   for(i=0;i<pArg->BytesPerSector;i++)
   {
    if(counter>=len) 
    {
      return len;
    }
    pbuf[counter]=znFAT_Buffer[i];
    counter++;
    pfi->FileCurPos++;
    pfi->FileCurPos%=pArg->BytesPerSector;
    pfi->FileCurOffset++;
   }   
  }
  pfi->FileCurSector=j;
  znFAT_ReadSector(pfi->FileCurSector,znFAT_Buffer);
  temp=len-counter;
  for(i=0;i<temp;i++)
  {
   if(counter>=len) 
   {
     return len;
   }
   pbuf[counter]=znFAT_Buffer[i];
   counter++;
   pfi->FileCurPos++;
   pfi->FileCurPos%=pArg->BytesPerSector;
   pfi->FileCurOffset++;  
  }
 }
 else
 {
  len=0;
 }
 return len;
}

#endif
/**************************************************************************
 - �������������ļ�ĳһλ�ö�ȡһ�����ȵ����ݣ���pfun��ָ��ĺ���������
 - ����ģ�飺znFAT�ļ�ϵͳģ��
 - �������ԣ��ⲿ��ʹ�û�ʹ��
 - ����˵����pfi:FileInfoStruct���͵Ľṹ��ָ�룬����װ���ļ�������Ϣ���ļ�
             ��ȡ�Ĺ����У��˽ṹ���е���ز�������£������ļ��ĵ�ǰƫ������
             �ļ��ĵ�ǰ�������ļ��ĵ�ǰ�صȵ�
             offset:Ҫ��λ��ƫ������ҪС���ļ��Ĵ�С 
             len:Ҫ��ȡ�����ݵĳ��ȣ����len+offset�����ļ��Ĵ�С����ʵ�ʶ�
             ȡ���������Ǵ�offset��ʼ���ļ�����
             pfun:�Զ�ȡ�����ݵĴ�������pfunָ��������������������
             �����������ȥ���������Ƿ��ڻ������У����ǰ�����ͨ�����ڷ���
             ��ȥ��ֻ��Ҫpfunȥָ����Ӧ�Ĵ�����������
 - ����˵������ȡ����ʵ�ʵ����ݳ��ȣ������ȡʧ�ܣ�����ָ����ƫ�����������ļ�
             ��С���򷵻�0
 - ע���ڶ�ȡһ���ļ�������ǰ�������Ƚ����ļ���znFAT_Open_File��
 **************************************************************************/
#ifdef ZNFAT_READ_FILEX

UINT32 znFAT_Read_FileX(struct FileInfoStruct *pfi,UINT32 offset,UINT32 len,void (*pfun)(UINT8))
{
 UINT32 i,j,k,temp;
 UINT32 counter=0;
 if(offset<pfi->FileSize)
 {
  if(offset+len>pfi->FileSize) len=pfi->FileSize-offset;
  znFAT_Seek_File(pfi,offset);
  
  znFAT_ReadSector(pfi->FileCurSector,znFAT_Buffer);
  for(i=pfi->FileCurPos;i<pArg->BytesPerSector;i++)
  {
   if(counter>=len) 
   {
     return len;
   }
   (*pfun)(znFAT_Buffer[i]);
   counter++;
   pfi->FileCurPos++;
   pfi->FileCurOffset++;
  }
  if(pfi->FileCurSector-(SOC(pfi->FileCurCluster))!=(pArg->SectorsPerClust-1))
  {
   for(j=pfi->FileCurSector+1;j<(SOC(pfi->FileCurCluster))+pArg->SectorsPerClust;j++)
   {
    znFAT_ReadSector(j,znFAT_Buffer);
    pfi->FileCurSector=j;
    for(i=0;i<pArg->BytesPerSector;i++)
    {
     if(counter>=len)
     {
       return len;
     }
     (*pfun)(znFAT_Buffer[i]);
     counter++;
     pfi->FileCurPos++;
     pfi->FileCurOffset++;
    }
   }
  } 
  temp=(len-counter)/(pArg->BytesPerSector*pArg->SectorsPerClust);
  for(k=0;k<temp;k++)
  {
   pfi->FileCurCluster=znFAT_GetNextCluster(pfi->FileCurCluster);
   for(j=(SOC(pfi->FileCurCluster));j<(SOC(pfi->FileCurCluster))+pArg->SectorsPerClust;j++)
   {
    znFAT_ReadSector(j,znFAT_Buffer);
    pfi->FileCurSector=j;
    for(i=0;i<pArg->BytesPerSector;i++)
    {
     if(counter>=len)  
 	 {
       return len;
     }
     (*pfun)(znFAT_Buffer[i]);
     counter++;
     pfi->FileCurOffset++;
	 pfi->FileCurPos++;
	 pfi->FileCurPos%=pArg->BytesPerSector;
    } 
   }    
  }
  pfi->FileCurCluster=znFAT_GetNextCluster(pfi->FileCurCluster);
  temp=(SOC(pfi->FileCurCluster))+((len-counter)/pArg->BytesPerSector);
  pfi->FileCurSector=(SOC(pfi->FileCurCluster));
  for(j=(SOC(pfi->FileCurCluster));j<temp;j++)
  {
   znFAT_ReadSector(j,znFAT_Buffer);
   pfi->FileCurSector=j;
   for(i=0;i<pArg->BytesPerSector;i++)
   {
    if(counter>=len) 
    {
      return len;
    }
    (*pfun)(znFAT_Buffer[i]);
    counter++;
    pfi->FileCurPos++;
    pfi->FileCurPos%=pArg->BytesPerSector;
    pfi->FileCurOffset++;
   }   
  }
  pfi->FileCurSector=j;
  znFAT_ReadSector(pfi->FileCurSector,znFAT_Buffer);
  temp=len-counter;
  for(i=0;i<temp;i++)
  {
   if(counter>=len) 
   {
     return len;
   }
   (*pfun)(znFAT_Buffer[i]);
   counter++;
   pfi->FileCurPos++;
   pfi->FileCurPos%=pArg->BytesPerSector;
   pfi->FileCurOffset++;  
  }
 }
 else
 {
  len=0;
 }
 return len;
}

#endif
/**************************************************************************
 - ����������Ѱ�ҿ��õĿ��д�
 - ����ģ�飺znFAT�ļ�ϵͳģ��
 - �������ԣ��ڲ�
 - ����˵������
 - ����˵��������ҵ��˿��дأ����ؿ��дصĴغţ����򷵻�0
 - ע��Ѱ�ҿ��д��Ǵ���Ŀ¼/�ļ��Լ����ļ�д�����ݵĻ�����������ܺܿ��Ѱ
       �ҵ����дأ���ô����Ŀ¼/�ļ��Լ����ļ�д��������Щ����Ҳ��ȽϿ졣
       �������Ǿ�������ʼ�Ĵ�����ȥѰ�ң�����ʹ���˶����������㷨���Դ�
       ���Ϻõ�Ч����������д�û���ҵ������п��ܾ�˵���洢�豸�Ѿ�û�пռ�
       ��
 **************************************************************************/
#ifdef ZNFAT_FIND_FREE_CLUST

UINT32 znFAT_Find_Free_Clust(UINT8 flag)
{
 UINT32 iClu,iSec;
 struct znFAT_FAT *pFAT;
 for(iSec=pArg->FirstFATSector+temp_last_cluster/128;iSec<pArg->FirstFATSector+pArg->FATsectors;iSec++)
 {
  znFAT_ReadSector(iSec,znFAT_Buffer);
  pFAT=(struct znFAT_FAT *)znFAT_Buffer;
  for(iClu=0;iClu<pArg->BytesPerSector/4;iClu++)
  {
   if(LE2BE((UINT8 *)(&((pFAT->Items))[iClu]),4)==0)
   {
    if(!flag)
	{
	 znFAT_Update_FSInfo_Free_Clu(0);
	 temp_last_cluster=128*(iSec-pArg->FirstFATSector)+iClu;
	 znFAT_Empty_Cluster(temp_last_cluster);	   
     return temp_last_cluster;
	}
	else
	{
	 znFAT_Update_FSInfo_Last_Clu(128*(iSec-pArg->FirstFATSector)+iClu);
	 return 128*(iSec-pArg->FirstFATSector)+iClu;
	}
   }
  }
 }
 return 0;
}

#endif
/**************************************************************************
 - ��������������ļ�/Ŀ¼��
 - ����ģ�飺znFAT�ļ�ϵͳģ��
 - �������ԣ��ڲ�
 - ����˵����prec:ָ��һ��direntry���͵Ľṹ�壬���Ľṹ����znFAT���ļ�/
             Ŀ¼��Ľṹ
             name:�ļ���Ŀ¼������
             is_dir:ָʾ����ļ�/Ŀ¼�����ļ�����Ŀ¼���ֱ�����ʵ���ļ���
             Ŀ¼�Ĵ��� 1��ʾ����Ŀ¼ 0��ʾ�����ļ�
 - ����˵������
 - ע�����ﴴ���ļ���Ŀ¼�ķ����ǣ��Ƚ��ļ���Ŀ¼����Ϣ��䵽һ���ṹ���У�
       Ȼ���ٽ�����ṹ�������д�뵽�洢�豸����Ӧ����������Ӧλ����ȥ����
       ����������ļ���Ŀ¼�Ĵ�����
       ������ļ���Ŀ¼����Ϣʱ���ļ���Ŀ¼���״ز�û�����ȥ������ȫ0
 **************************************************************************/
#ifdef FILL_REC_INF

void Fill_Rec_Inf(struct direntry *prec,INT8 *name,UINT8 is_dir,UINT8 *ptd)
{
 UINT8 i=0,len=0,h=0;
 UINT16 temp;

 if(is_dir)
 {
  len=strlen(name);
  if(len>8)
  {
   for(i=0;i<6;i++)
   {
    (prec->deName)[i]=L2U(name[i]);
   }
   (prec->deName)[6]='~';
   (prec->deName)[7]='1';
  }
  else
  {
   for(i=0;i<len;i++)
   {
    (prec->deName)[i]=L2U(name[i]);
   }
   for(;i<8;i++)
   {
    (prec->deName)[i]=' ';
   }
  }
  for(i=0;i<3;i++)
  {
   (prec->deExtension)[i]=' ';
  }
 }
 else
 {
  while(name[len]!=0) {if(name[len]=='.') h=1;len++;}
  if(!h) {name[len]='.';name[len+1]=0;}  
  len=0;
  while(name[len]!='.' && name[len]!=0) len++;
  if(len>8)
  {
   for(i=0;i<6;i++)
   {
    (prec->deName)[i]=L2U(name[i]);
   }
   (prec->deName)[6]='~';
   (prec->deName)[7]='1';
  }
  else
  {
   for(i=0;i<len;i++)
   {
    (prec->deName)[i]=L2U(name[i]);
   }
   for(;i<8;i++)
   {
    (prec->deName)[i]=' ';
   }
  }
  if(name[len]==0)
  {
   for(i=0;i<3;i++)
   {
    (prec->deExtension)[i]=' ';
   }
  }
  else
  {
   for(i=0;i<3;i++)
   {
    (prec->deExtension)[i]=' ';
   }
   len++;
   i=0;
   while(name[len]!=0)
   {
    (prec->deExtension)[i++]=L2U(name[len]);
	len++;
   }
  }
 }
 if(is_dir)
  (prec->deAttributes)=0x10;
 else
  (prec->deAttributes)=0x20;
 
 temp=MAKE_FILE_TIME(ptd[3],ptd[4],ptd[5]);
 (prec->deCTime)[0]=temp;
 (prec->deCTime)[1]=temp>>8;
 temp=MAKE_FILE_DATE(ptd[0],ptd[1],ptd[2]);
 (prec->deCDate)[0]=temp;
 (prec->deCDate)[1]=temp>>8;

 (prec->deLowerCase)=0;
 (prec->deHighClust)[0]=0;
 (prec->deHighClust)[1]=0;
 (prec->deLowCluster)[0]=0;
 (prec->deLowCluster)[1]=0;
 for(i=0;i<4;i++)
 {
  (prec->deFileSize)[i]=0;
 }				
}

#endif
/**************************************************************************
 - ��������������FAT��
 - ����ģ�飺znFAT�ļ�ϵͳģ��
 - �������ԣ��ڲ�
 - ����˵����cluster:Ҫ���µĴ����
             dat:Ҫ����Ӧ�Ĵ������Ϊdat
 - ����˵������
 - ע�������ļ�д�������ݺ���Ҫ��FAT����и����Ա��������ݵĴ�����ϵ 
       ɾ���ļ���ʱ��Ҳ��Ҫ�����ļ��Ĵ����������������ļ��Ĵ�����ϵ
 **************************************************************************/
#ifdef ZNFAT_MODIFY_FAT

void znFAT_Modify_FAT(UINT32 cluster,UINT32 dat)
{
 znFAT_ReadSector(pArg->FirstFATSector+(cluster*4/pArg->BytesPerSector),znFAT_Buffer);
 znFAT_Buffer[((cluster*4)%pArg->BytesPerSector)+0]=dat&0x000000ff;
 znFAT_Buffer[((cluster*4)%pArg->BytesPerSector)+1]=(dat&0x0000ff00)>>8;
 znFAT_Buffer[((cluster*4)%pArg->BytesPerSector)+2]=(dat&0x00ff0000)>>16;
 znFAT_Buffer[((cluster*4)%pArg->BytesPerSector)+3]=(dat&0xff000000)>>24;
 znFAT_WriteSector(pArg->FirstFATSector+(cluster*4/pArg->BytesPerSector),znFAT_Buffer);

 znFAT_ReadSector(pArg->FirstFATSector+pArg->FATsectors+(cluster*4/pArg->BytesPerSector),znFAT_Buffer);
 znFAT_Buffer[((cluster*4)%pArg->BytesPerSector)+0]=dat&0x000000ff;
 znFAT_Buffer[((cluster*4)%pArg->BytesPerSector)+1]=(dat&0x0000ff00)>>8;
 znFAT_Buffer[((cluster*4)%pArg->BytesPerSector)+2]=(dat&0x00ff0000)>>16;
 znFAT_Buffer[((cluster*4)%pArg->BytesPerSector)+3]=(dat&0xff000000)>>24;
 znFAT_WriteSector(pArg->FirstFATSector+pArg->FATsectors+(cluster*4/pArg->BytesPerSector),znFAT_Buffer); 
}

#endif

/**************************************************************************
 - �����������ڴ洢�豸�д���һ���ļ�/Ŀ¼��
 - ����ģ�飺znFAT�ļ�ϵͳģ��
 - �������ԣ��ڲ�
 - ����˵����pfi:ָ��FileInfoStruct���͵Ľṹ�壬����װ�ظմ������ļ�����Ϣ
                 Ҳ����˵�������������Ŀ¼����˽ṹ�岻�ᱻ����
             cluster:��cluster������д����ļ�/Ŀ¼�����ʵ��������Ŀ¼��
                 �����ļ���Ŀ¼������ͨ��znFAT_Enter_Dir����ȡĳһ��Ŀ¼�Ŀ�
                 ʼ��
             name:�ļ�/Ŀ¼������
             is_dir:ָʾҪ���������ļ�����Ŀ¼���ļ���Ŀ¼�Ĵ��������ǲ�ͬ��
                 1��ʾ����Ŀ¼ 0��ʾ�����ļ�
 - ����˵�����ɹ�����1��ʧ�ܷ���-1
 **************************************************************************/
#ifdef ZNFAT_CREATE_REC

UINT8 znFAT_Create_Rec(struct FileInfoStruct *pfi,UINT32 cluster,INT8 *name,UINT8 is_dir,UINT8 *ptd)
{
 UINT32 iSec,iRec,temp_sec,temp_clu,new_clu,i,old_clu;
 UINT8 flag=0;
 UINT16 temp_Rec;
 struct direntry *pRec;
 Fill_Rec_Inf(&temp_rec,name,is_dir,ptd);
 do
 {
  old_clu=cluster;
  temp_sec=SOC(cluster);
  for(iSec=temp_sec;iSec<temp_sec+pArg->SectorsPerClust;iSec++)
  {
   znFAT_ReadSector(iSec,znFAT_Buffer);
   for(iRec=0;iRec<pArg->BytesPerSector;iRec+=sizeof(struct direntry))
   {
    pRec=(struct direntry *)(znFAT_Buffer+iRec);
	if((pRec->deName)[0]==0)
	{
	 flag=1;
	 if(is_dir)
	 {
	  if(!(new_clu=znFAT_Find_Free_Clust(0))) return -1;
	  znFAT_Modify_FAT(new_clu,0x0fffffff);
	  (temp_rec.deHighClust)[0]=(new_clu&0x00ff0000)>>16;
      (temp_rec.deHighClust)[1]=(new_clu&0xff000000)>>24;
      (temp_rec.deLowCluster)[0]=(new_clu&0x000000ff);
      (temp_rec.deLowCluster)[1]=(new_clu&0x0000ff00)>>8;
	 }
	 znFAT_ReadSector(iSec,znFAT_Buffer);
	 for(i=0;i<sizeof(struct direntry);i++)
	 {
	  ((UINT8 *)pRec)[i]=((UINT8 *)(&temp_rec))[i];
	 }
	 znFAT_WriteSector(iSec,znFAT_Buffer);
	 temp_sec=iSec;
	 temp_Rec=iRec;
	 iRec=pArg->BytesPerSector;
	 iSec=temp_sec+pArg->SectorsPerClust;
	}
   }
  }
 }while(!flag && (cluster=znFAT_GetNextCluster(cluster))!=0x0fffffff);
 if(!flag)
 {
  if(!(temp_clu=znFAT_Find_Free_Clust(0))) return -1;
  znFAT_Modify_FAT(temp_clu,0x0fffffff);
  znFAT_Modify_FAT(old_clu,temp_clu);
  temp_sec=SOC(temp_clu);
  temp_Rec=0;
  znFAT_ReadSector(temp_sec,znFAT_Buffer);
  if(is_dir)
  {
   if(!(new_clu=znFAT_Find_Free_Clust(0))) return -1;
   znFAT_Modify_FAT(new_clu,0x0fffffff);
   znFAT_ReadSector(temp_sec,znFAT_Buffer);
   (temp_rec.deHighClust)[0]=(new_clu&0x00ff0000)>>16;
   (temp_rec.deHighClust)[1]=(new_clu&0xff000000)>>24;
   (temp_rec.deLowCluster)[0]=(new_clu&0x000000ff);
   (temp_rec.deLowCluster)[1]=(new_clu&0x0000ff00)>>8;
  }
  for(i=0;i<sizeof(struct direntry);i++)
  {
   znFAT_Buffer[i]=((UINT8 *)(&temp_rec))[i]; 
  }
  znFAT_WriteSector(temp_sec,znFAT_Buffer);
 }
 if(is_dir)
 {
  znFAT_Empty_Cluster(new_clu);

  Fill_Rec_Inf(&temp_rec,".",1,ptd);
  (temp_rec.deHighClust)[0]=(new_clu&0x00ff0000)>>16;
  (temp_rec.deHighClust)[1]=(new_clu&0xff000000)>>24;
  (temp_rec.deLowCluster)[0]=(new_clu&0x000000ff);
  (temp_rec.deLowCluster)[1]=(new_clu&0x0000ff00)>>8;
  for(i=0;i<sizeof(struct direntry);i++)
  {
   znFAT_Buffer[i]=((UINT8 *)(&temp_rec))[i]; 
  }
  Fill_Rec_Inf(&temp_rec,"..",1,ptd);
  if(cluster==pArg->FirstDirClust)
  {
   (temp_rec.deHighClust)[0]=0;
   (temp_rec.deHighClust)[1]=0;
   (temp_rec.deLowCluster)[0]=0;
   (temp_rec.deLowCluster)[1]=0;
  }
  else
  {
   (temp_rec.deHighClust)[0]=(cluster&0x00ff0000)>>16;
   (temp_rec.deHighClust)[1]=(cluster&0xff000000)>>24;
   (temp_rec.deLowCluster)[0]=(cluster&0x000000ff);
   (temp_rec.deLowCluster)[1]=(cluster&0x0000ff00)>>8;
  }
    
  for(i=sizeof(struct direntry);i<2*sizeof(struct direntry);i++)
  {
   znFAT_Buffer[i]=((UINT8 *)(&temp_rec))[i-sizeof(struct direntry)]; 
  }
  for(;i<pArg->BytesPerSector;i++)
  {
   znFAT_Buffer[i]=0;
  }		
  temp_sec=SOC(new_clu);
  znFAT_WriteSector(temp_sec,znFAT_Buffer);
 }
 else
 {
  strcpy(pfi->FileName,name);
  pfi->FileStartCluster=0;
  pfi->FileCurCluster=0;
  pfi->FileSize=0;
  pfi->FileCurSector=0;
  pfi->FileCurPos=0;
  pfi->FileCurOffset=0;
  pfi->Rec_Sec=temp_sec;
  pfi->nRec=temp_Rec;

  pfi->FileAttr=temp_rec.deAttributes;
 }
 znFAT_Find_Free_Clust(1);
 return 1;
}

#endif
/**************************************************************************
 - ������������ĳһ���ļ�׷������
 - ����ģ�飺znFAT�ļ�ϵͳģ��
 - �������ԣ��ⲿ��ʹ�û�ʹ��
 - ����˵����pfi:ָ��FileInfoStruct���͵Ľṹ�壬����װ�ظմ������ļ�����Ϣ
             len:Ҫ׷�ӵ����ݳ���
             pbuf:ָ�����ݻ�������ָ��
 - ����˵�����ɹ�����ʵ��д������ݳ��ȣ�ʧ�ܷ���0
 - ע��׷������ʧ�ܺ��п����Ǵ洢�豸�Ѿ�û�пռ��ˣ�Ҳ�����Ҳ������д���
 **************************************************************************/
#ifdef ZNFAT_ADD_DAT

UINT32 znFAT_Add_Dat(struct FileInfoStruct *pfi,UINT32 len,UINT8 *pbuf)
{
 UINT32 i=0,counter=0,iSec,iClu;
 UINT32 temp_sub,temp_file_size,new_clu,temp_sec;
 struct direntry *prec;
 if(len>0)
 {
  znFAT_ReadSector(pfi->Rec_Sec,znFAT_Buffer);
  prec=(struct direntry *)(znFAT_Buffer+pfi->nRec);
  temp_file_size=LE2BE((prec->deFileSize),4);
  if(!temp_file_size)
  {   
   if(!(new_clu=znFAT_Find_Free_Clust(0))) return 0;
   znFAT_Modify_FAT(new_clu,0x0fffffff);
   pfi->FileStartCluster=new_clu;
   pfi->FileCurCluster=pfi->FileStartCluster;
   pfi->FileSize=0;
   pfi->FileCurSector=SOC(pfi->FileCurCluster);
   pfi->FileCurPos=0;
   pfi->FileCurOffset=0;
   znFAT_ReadSector(pfi->Rec_Sec,znFAT_Buffer);
   (prec->deHighClust)[0]=(new_clu&0x00ff0000)>>16;
   (prec->deHighClust)[1]=(new_clu&0xff000000)>>24;
   (prec->deLowCluster)[0]=(new_clu&0x000000ff);
   (prec->deLowCluster)[1]=(new_clu&0x0000ff00)>>8;
   znFAT_WriteSector(pfi->Rec_Sec,znFAT_Buffer);
  }
  else
  {
   if(!(temp_file_size%(pArg->SectorsPerClust*pArg->BytesPerSector))) //�ڴص���ĩβ�ٽ�ط�����ҪѰ���´�
   {
    znFAT_Seek_File(pfi,pfi->FileSize-1);
    if(!(new_clu=znFAT_Find_Free_Clust(0))) return 0;
	znFAT_Modify_FAT(pfi->FileCurCluster,new_clu);
    znFAT_Modify_FAT(new_clu,0x0fffffff);     
   }
   znFAT_Seek_File(pfi,pfi->FileSize);
  }

  iSec=pfi->FileCurSector;

  znFAT_ReadSector(iSec,znFAT_Buffer);
  for(i=pfi->FileCurPos;i<pArg->BytesPerSector;i++)
  {
   znFAT_Buffer[i]=pbuf[counter];
   counter++;
   if(counter>=len) 
   {
    iSec=pfi->FileCurSector;
    goto end;
   }
  }
  znFAT_WriteSector(pfi->FileCurSector,znFAT_Buffer); //���ݽӷ�  
  
  if(pfi->FileCurSector-(SOC(pfi->FileCurCluster))<(pArg->SectorsPerClust-1)) //�ж��ǲ���һ���ص����һ������,�Ƚ���ǰ�������������� 
  {
   for(iSec=pfi->FileCurSector+1;iSec<=(SOC(pfi->FileCurCluster)+pArg->SectorsPerClust-1);iSec++)
   {
    for(i=0;i<pArg->BytesPerSector;i++)
    {
	 znFAT_Buffer[i]=pbuf[counter];
	 counter++;
     if(counter>=len) 
	 {
	  goto end;
	 }
    }
    znFAT_WriteSector(iSec,znFAT_Buffer);
   }
  }
  
  temp_sub=len-counter;
  for(iClu=0;iClu<temp_sub/(pArg->SectorsPerClust*pArg->BytesPerSector);iClu++)
  {
   if(!(new_clu=znFAT_Find_Free_Clust(0))) return 0;
   znFAT_Modify_FAT(pfi->FileCurCluster,new_clu);
   znFAT_Modify_FAT(new_clu,0x0fffffff);
   pfi->FileCurCluster=new_clu;

   temp_sec=SOC(new_clu);
   for(iSec=temp_sec;iSec<temp_sec+pArg->SectorsPerClust;iSec++)
   {
    for(i=0;i<pArg->BytesPerSector;i++)
	{
   	 znFAT_Buffer[i]=pbuf[counter];
	 counter++;
	} 
	znFAT_WriteSector(iSec,znFAT_Buffer);
   }
  }

  temp_sub=len-counter;
  if(temp_sub)
  {
   if(!(new_clu=znFAT_Find_Free_Clust(0))) return 0;
   znFAT_Modify_FAT(pfi->FileCurCluster,new_clu);
   znFAT_Modify_FAT(new_clu,0x0fffffff);
   pfi->FileCurCluster=new_clu;
   temp_sec=SOC(new_clu);
   for(iSec=temp_sec;iSec<temp_sec+temp_sub/pArg->BytesPerSector;iSec++)
   {
    for(i=0;i<pArg->BytesPerSector;i++)
	{
   	 znFAT_Buffer[i]=pbuf[counter];
	 counter++;
	} 
	znFAT_WriteSector(iSec,znFAT_Buffer);    
   }   
  }

  temp_sub=len-counter;
  if(temp_sub)
  {
   for(i=0;i<pArg->BytesPerSector;i++)
   {
   	znFAT_Buffer[i]=pbuf[counter];
	counter++;
   } 
   znFAT_WriteSector(iSec,znFAT_Buffer);   
  }
end:
  znFAT_WriteSector(iSec,znFAT_Buffer);
  znFAT_ReadSector(pfi->Rec_Sec,znFAT_Buffer);
  (((struct direntry *)(znFAT_Buffer+pfi->nRec))->deFileSize)[0]=((temp_file_size+len)&0x000000ff);
  (((struct direntry *)(znFAT_Buffer+pfi->nRec))->deFileSize)[1]=((temp_file_size+len)&0x0000ff00)>>8;
  (((struct direntry *)(znFAT_Buffer+pfi->nRec))->deFileSize)[2]=((temp_file_size+len)&0x00ff0000)>>16;
  (((struct direntry *)(znFAT_Buffer+pfi->nRec))->deFileSize)[3]=((temp_file_size+len)&0xff000000)>>24;
  znFAT_WriteSector(pfi->Rec_Sec,znFAT_Buffer);

  pfi->FileSize=(temp_file_size+len);
  pfi->FileCurSector=(pfi->FileSize%pArg->BytesPerSector)?iSec:iSec+1;
  pfi->FileCurPos=pfi->FileSize%pArg->BytesPerSector;
  pfi->FileCurOffset=pfi->FileSize;
 }
 znFAT_Find_Free_Clust(1);
 return len;
}

#endif
/**************************************************************************
 - ��������������Ŀ¼(֧�������Ŀ¼����)
 - ����ģ�飺znFAT�ļ�ϵͳģ��
 - �������ԣ��ⲿ��ʹ�û�ʹ��
 - ����˵����pfi:����
             dirpath:Ŀ¼·�� ���� "\\dir1\\dir2\\dir3\\....\\dirn\\"
             ��������\\����
 - ����˵�����ɹ�����0��ʧ�ܷ���1
 - ע������м�ĳһ��Ŀ¼�����ڣ�������������·����dir3�����ڣ���ô�˺�����
       �������Ŀ¼��Ȼ���ټ���ȥ����������Ŀ¼
       ����Ŀ¼ʧ���п�������Ϊ�洢�豸�ռ䲻��
 **************************************************************************/
#ifdef ZNFAT_CREATE_DIR

UINT8 znFAT_Create_Dir(CONST INT8 *dirpath,UINT8 *ptd)
{
 struct FileInfoStruct *pfi;
 while(!znFAT_Enter_Dir(dirpath))
 {
  if(znFAT_Create_Rec(pfi,temp_dir_cluster,temp_dir_name,1,ptd)==-1)
  {
   return 1;
  }
 }
 return 0;
}

#endif
/**************************************************************************
 - ���������������ļ�(֧�������Ŀ¼����)
 - ����ģ�飺znFAT�ļ�ϵͳģ��
 - �������ԣ��ⲿ��ʹ�û�ʹ��
 - ����˵����pfi:һ��ָ��FileInfoStruct���͵Ľṹ���ָ�룬����װ���´�����
             �ļ���Ϣ������´������ļ������ٴ򿪾Ϳ���ֱ��������
             filepath:�ļ�·�� ���� "\\dir1\\dir2\\dir3\\....\\dirn\\test.txt"
 - ����˵����0���ɹ� 1���ļ��Ѵ��� 2�������ļ�Ŀ¼ʧ�� 3�������ļ�ʧ��
 - ע������ļ�·����ĳһ���м�Ŀ¼�����ڣ���ô�˺����ᴴ�����Ŀ¼���ټ���
       ȥ����������Ŀ¼��һֱ�������ļ�������ɡ�
       �����ļ�ʧ���п�������Ϊ�洢�豸�ռ䲻�㣬���Ǵ��ļ��Ѿ�����
 **************************************************************************/
#ifdef ZNFAT_CREATE_FILE

UINT8 znFAT_Create_File(struct FileInfoStruct *pfi,CONST INT8 *filepath,UINT8 *ptd)
{
 if(znFAT_Open_File(pfi,filepath,0,1))
 { 
  if(!znFAT_Create_Dir(filepath,ptd))
  {
   if(znFAT_Create_Rec(pfi,temp_dir_cluster,temp_dir_name,0,ptd)==-1)
   {
    return 3;
   }    
  }
  else
  {
   return 2;   
  }
 }
 else
 {
  return 1;
 }
 return 0;
}

#endif
/**************************************************************************
 - ����������ɾ���ļ�(֧�������Ŀ¼)
 - ����ģ�飺znFAT�ļ�ϵͳģ��
 - �������ԣ��ⲿ��ʹ�û�ʹ��
 - ����˵����filepath:�ļ�·�� ���� "\\dir1\\dir2\\dir3\\....\\dirn\\test.txt"
 - ����˵����1:�ļ���Ŀ¼·�������� 0:�ɹ�
 - ע��ɾ������ļ���FAT���еĴ�����ϵ��ȫ���ƻ�
 **************************************************************************/
#ifdef ZNFAT_DEL_FILE

UINT8 znFAT_Del_File(CONST INT8 *filepath)
{
 UINT32 cur_clu,next_clu;
 struct FileInfoStruct fi;
 
 if(znFAT_Open_File(&fi,filepath,0,1))
 {
  return 1;
 }
 znFAT_ReadSector(fi.Rec_Sec,znFAT_Buffer);
 *(znFAT_Buffer+fi.nRec)=0xe5;
 znFAT_WriteSector(fi.Rec_Sec,znFAT_Buffer);
 
 if(cur_clu=fi.FileStartCluster)
 {
  if(cur_clu<Search_Last_Usable_Cluster()) 
   znFAT_Update_FSInfo_Last_Clu(cur_clu);
  znFAT_Update_FSInfo_Free_Clu(1);
  next_clu=znFAT_GetNextCluster(cur_clu);
  while(next_clu!=0x0fffffff)
  {
   znFAT_Update_FSInfo_Free_Clu(1);
   znFAT_Modify_FAT(cur_clu,0x00000000);
   cur_clu=next_clu;
   next_clu=znFAT_GetNextCluster(cur_clu);
  }
  znFAT_Modify_FAT(cur_clu,0x00000000);
 }
 return 0;
}

#endif
/**************************************************************************
 - �����������ļ�����(Դ�ļ�·����Ŀ���ļ�·����֧���������Ŀ¼������֧��
             �ļ���ͨ��)
 - ����ģ�飺znFAT�ļ�ϵͳģ��
 - �������ԣ��ⲿ��ʹ�û�ʹ��
 - ����˵����pArg1:��Դ�ļ����ڵĴ洢�豸�ĳ�ʼ�����ṹ���ָ��
             pArg2:��Ŀ���ļ����ڵĴ洢�豸�ĳ�ʼ�����ṹ���ָ��
             sfilename:Դ�ļ�·����Ҳ���ǿ�������������Դ
             tfilename:Ŀ���ļ�·����Ҳ�����������յ�д����ļ�
                       ���� "\\dir1\\dir2\\dir3\\....\\dirn\\test.txt" 
             file_buf:����������Ҫ�õ������ݻ��������˻���������Խ��
                      �����ٶ�Խ��
             buf_size:���ݻ������Ĵ�С 
 - ����˵����1:Ŀ¼�ļ�����ʧ�� 2:Դ�ļ��򿪴�� 0:�ɹ�
 - ע���˺���֧�ֶ��豸֮����ļ�������pArg1��pArg2������Դ�洢�豸��Ŀ��
       �洢�豸�ĳ�ʼ������Ϣ���Ӷ�����ͬʱ�������洢�豸���в�����
	   znFAT 5.01�濪ʼ֧�ֶ��豸�����豸����໥���ݿ���������͵�Ӧ��
 **************************************************************************/
#ifdef ZNFAT_XCOPY_FILE

UINT8 znFAT_XCopy_File(struct znFAT_Init_Arg *pArg1,struct znFAT_Init_Arg *pArg2,CONST INT8 *sfilename,CONST INT8 *tfilename,UINT8 *file_buf,UINT32 buf_size,UINT8 *pt)
{
 struct FileInfoStruct FileInfo2,FileInfo1;
 struct znFAT_Init_Arg *pArg_temp;
 UINT32 i;

 pArg_temp=pArg; //��pArgԭ����ָ�򸳸��м����

 pArg=pArg2;Dev_No=pArg->DEV_No; //�궨Ŀ��洢�豸
 if(znFAT_Create_File(&FileInfo1,tfilename,pt)) return 1; //��Ŀ��洢�豸�ϴ���Ŀ���ļ�

 pArg=pArg1;Dev_No=pArg->DEV_No; //�궨Դ�洢�豸
 if(znFAT_Open_File(&FileInfo2,sfilename,0,1)) return 2;  //��Դ�洢�豸�ϴ�Դ�ļ�

 for(i=0;i<FileInfo2.FileSize/buf_size;i++)  
 {
  pArg=pArg1;Dev_No=pArg->DEV_No; //�궨Դ�洢�豸 
  znFAT_Read_File(&FileInfo2,i*buf_size,buf_size,file_buf);	//��Դ�洢�豸�ϵ�Դ�ļ����ݵ����ݻ�����

  pArg=pArg2;Dev_No=pArg->DEV_No;	//�궨Ŀ��洢�豸 
  znFAT_Add_Dat(&FileInfo1,buf_size,file_buf); //�����ݼ�����������д�뵽Ŀ���ļ���
 }

 pArg=pArg1;Dev_No=pArg->DEV_No; //�궨Դ�洢�豸 
 znFAT_Read_File(&FileInfo2,i*buf_size,FileInfo2.FileSize%buf_size,file_buf);//��ȡ�����ļ�����

 pArg=pArg2;Dev_No=pArg->DEV_No; //�궨Ŀ��洢�豸
 znFAT_Add_Dat(&FileInfo1,FileInfo2.FileSize%buf_size,file_buf); //��������������д�뵽Ŀ���ļ���

 pArg=pArg_temp; //��pArg�ָ�

 return 0;
}

#endif
/**************************************************************************
 - �����������ļ�������
 - ����ģ�飺znFAT�ļ�ϵͳģ��
 - �������ԣ��ⲿ��ʹ�û�ʹ��
 - ����˵����filename:��Ҫ��������Դ�ļ���·�� ��\a.txt
             newfilename:Ŀ���ļ��� ��b.txt (עĿ���ļ����ǵ������ļ�����
			 ����·��)
 - ����˵����1:Դ�ļ��򿪴�� 0:�ɹ�
 - ע����
 **************************************************************************/
#ifdef ZNFAT_RENAME_FILE

UINT8 znFAT_Rename_File(CONST INT8 *filename,CONST INT8 *newfilename)
{
 struct FileInfoStruct fi;
 UINT8 i=0,j=0;
 if(znFAT_Open_File(&fi,filename,0,1)) return 1; //�ļ���ʧ��
 znFAT_ReadSector(fi.Rec_Sec,znFAT_Buffer);
 for(i=0;i<11;i++) (znFAT_Buffer+fi.nRec)[i]=0x20;
 i=0;
 while(newfilename[i]!='.')
 {
  (znFAT_Buffer+fi.nRec)[i]=L2U(newfilename[i]);
  i++;
 }
 i++;
 while(newfilename[i])
 {
  (znFAT_Buffer+fi.nRec+8)[j]=L2U(newfilename[i]);
  i++;j++;
 }
 znFAT_WriteSector(fi.Rec_Sec,znFAT_Buffer);
 return 0;
}

#endif
/**************************************************************************
 - �����������ļ��ر�
 - ����ģ�飺znFAT�ļ�ϵͳģ��
 - �������ԣ��ⲿ��ʹ�û�ʹ��
 - ����˵����pfi:ָ��ǰ�򿪵��ļ����ļ���Ϣ�ṹ
 - ����˵����0:�ɹ�
 - ע����
 **************************************************************************/
#ifdef ZNFAT_FILE_CLOSE

UINT8 znFAT_File_Close(struct FileInfoStruct *pfi)
{
 UINT16 i=0;							
 for(i=0;i<sizeof(struct FileInfoStruct);i++)
 {
  ((UINT8 *)pfi)[i]=0;
 }
 return 0;
}

#endif