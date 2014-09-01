#ifndef _kkk_pca6107_h
#define _kkk_pca6107_h
#include "msp430x14x.h"
#define ADDR_pca6107 0x30


/********************************
Ϊ�˷��������д���������ú�
DDR(x)  ��AVRһ������ӦλΪ1���������Ϊ0��������
PIN     �õ���������
POUT(x) ��AVRһ������ӦλΪ1����ߵ�ƽ�����Ϊ0����͵�ƽ���
*********************************/
#define DDR(x) set_reg_6107(3,~(x))
#define PIN     get_reg_6107(0)
#define POUT(x) set_reg_6107(1,(x))
void set_reg_6107(unsigned char reg,unsigned char da);
unsigned char get_reg_6107(unsigned char reg);

#endif