#include "AT89x52.H"
#include "USB.H"
#include "PDIUSBD12.H"
#include "My_type.h"
#include "UART.H"
#include "hardware.h"
#include "keyboard.h"

#define InitUART init_uart
#define Printc uart_putchar
#define Prints print_str
#define PrintLongInt print_longint
#define PrintHex print_hex
#define LEDs P2
#define DispLineInf()      \
{                          \
 Prints(" in file \"");    \
 Prints(__FILE__);         \
 Prints(", @ line ");      \
 PrintLongInt(__LINE__-1); \
 Prints("\r\n");           \
}

//#define debug

#define USB_COMMAND_ADD           1
#define USB_DATA_ADD              0

//USBоƬ��������
#define USB_DATA                  P0
#define USB_A0                    P3_5
#define USB_WR                    P3_6
#define USB_RD                    P3_7
#define USB_INT                   P3_2


#define ENDPOINT_NUMBER           2
#define MAX_CONTROL_DATA_SIZE     16


//���ƴ���ʱ��������
CONTROL_DATA_BUFF Control_Data;

//����
uint8 idata buffer[64];

//��������ʱ�õ�ָ��
uint8 *pData;

uint8 idle;     //����״̬
uint8 protocol; //��ǰЭ��

//�ߵ��ֽڽ���

#define SWAP16(x)  ((((uint16)(x))<<8)|(((uint16)(x))>>8))

//ȡһ�������ĵ��ֽ� 
#define LSB(x) ((uint8)(x))

//ȡһ�������ĸ��ֽ�
#define MSB(x) ((uint8)(((uint16)(x))>>8))                               

//�ַ������������õ��������� 
code uint8 LANGUAGE_ID[4]={0x04,0x03,0x09,0x04};                   

//�豸���к�										
code uint8 device_serial_number[]=
{22,STRING_DESCRIPTOR,'2',0,'0',0,'0',0,'7',0,'-',0,'1',0,'1',0,'-',0,'2',0,'9',0};

//�����ַ���������ȦȦ��USBר�� http://group.ednchina.com/93
//����Unicode���룬ʹ��http://computer00.21ic.org/user1/2198/archives/2007/42769.htmlת��
code uint8 ManufacturerString[80]=
{80,STRING_DESCRIPTOR,0x35,0x75,0x11,0x81,0x08,0x57,0x08,0x57,0x84,0x76,'U',0x00,
 'S',0x00,'B',0x00,0x13,0x4E,0x3A,0x53,0x20,0x00,'H',0,'t',0,'t',0,
 'p',0,':',0,'/',0,'/',0,'g',0,'r',0,'o',0,'u',0,'p',0,'.',0,'e',0,'d',0,'n',0,
 'c',0,'h',0,'i',0,'n',0,'a',0,'.',0,'c',0,'o',0,'m',0,'/',0,'9',0,'3',0};

//��Ʒ�ַ���������ȦȦ��USBר���֮USB���� http://group.ednchina.com/93
//����Unicode���룬ʹ��http://computer00.21ic.org/user1/2198/archives/2007/42769.htmlת��
code uint8 ProducterString[96]=
{96,STRING_DESCRIPTOR,0x35,0x75,0x11,0x81,0x08,0x57,0x08,0x57,0x84,0x76,'U',0x00,
 'S',0x00,'B',0x00,0x13,0x4E,0x3A,0x53,0x3B,0x6D,0xA8,0x52,0x4B,0x4E,'U',0x00,
 'S',0x00,'B',0x00,0x2E,0x95,0xD8,0x76,0x20,0x00,'H',0,'t',0,'t',0,
 'p',0,':',0,'/',0,'/',0,'g',0,'r',0,'o',0,'u',0,'p',0,'.',0,'e',0,'d',0,'n',0,
 'c',0,'h',0,'i',0,'n',0,'a',0,'.',0,'c',0,'o',0,'m',0,'/',0,'9',0,'3',0};

code DEVICE_DESCRIPTOR_STRUCT device_descriptor=     //�豸������
{
 sizeof(DEVICE_DESCRIPTOR_STRUCT),                   //�豸���������ֽ�����С
 DEVICE_DESCRIPTOR,	                                 //�豸���������ͱ��
 SWAP16(0x0110),                                     //USB�汾��,USB1.1
 0x00,                                               //USB������豸�����
 0x00,                                               //USB������������
 0x00,                                               //USB������豸Э�����
 0x10,                                               //�˵�0��������С
 SWAP16(0x8888),                                     //���̱��VID������ֻ����Ϊ�����ã���ʹ���Լ���VID
 SWAP16(0x0001),                                     //��Ʒ���PID������ֻ����Ϊ�����ã���ʹ���Լ���PID
 SWAP16(0x0001),                                     //�豸�������
 0x01,                                               //�豸�����ַ���������
 0x02,                                               //������Ʒ�ַ���������
 0x03,                                               //�����豸���к��ַ���������
 0x01                                                //���ܵ���������
};

//�������ã��ӿڣ��˵���������ṹ�壬��Ϊ������������������һ�𷵻ص�
typedef struct _CON_INT_ENDP_DESCRIPTOR_STRUCT
{
 CONFIGURATION_DESCRIPTOR_STRUCT configuration_descriptor;
 INTERFACE_DESCRIPTOR_STRUCT  interface_descriptor;
 HID_DESCRIPTOR_STRUCT hid_descriptor;
 ENDPOINT_DESCRIPTOR_STRUCT  endpoint_descriptor[ENDPOINT_NUMBER];
}CON_INT_ENDP_DESCRIPTOR_STRUCT;

code CON_INT_ENDP_DESCRIPTOR_STRUCT con_int_endp_descriptor=
{
//configuration_descriptor                                          //����������
{
 sizeof(CONFIGURATION_DESCRIPTOR_STRUCT),                           //�������������ֽ�����С
 CONFIGURATION_DESCRIPTOR,                                          //�������������ͱ��
 SWAP16(sizeof(CON_INT_ENDP_DESCRIPTOR_STRUCT)),
 0x01,                                                            //ֻ����һ���ӿ�
 0x01,                                                            //�����õı��
 0x00,                                                            //iConfiguration�ֶ�
 0xA0,                                                            //�������߹��磬֧��Զ�̻���
 0xC8                                                            //�����߻�ȡ������400mA
},
//interface_descritor                                             //�ӿ�������
{
 sizeof(INTERFACE_DESCRIPTOR_STRUCT),                             //�ӿ����������ֽ�����С
 INTERFACE_DESCRIPTOR,                                            //�ӿ����������ͱ��
 0x00,                                                            //�ӿڱ��Ϊ0
 0x00,                                                            //�ýӿ��������ı��
 ENDPOINT_NUMBER,                                                 //��0�˵�����Ϊ2��ֻʹ�ö˵����˵���������
 0x03,                                                            //�˻��ӿ��豸��HID����
 0x01,                                                            //ʹ�õ����ࣺ֧��BIOS������Boot������
 0x01,                                                            //ʹ�õ�Э�飺����
 0x00                                                             //�ӿ��������ַ�������
},
//hid_descriptor
{
 sizeof(HID_DESCRIPTOR_STRUCT),                                   //HID���������ֽ�����С
 HID_DESCRIPTOR,                                                  //HID���������ͱ��
 SWAP16(0x0110),                                                  //HID��Э��汾�ţ�Ϊ1.1
 0x21,                                                            //�̼��Ĺ��ҵ������ţ�0x21Ϊ����
 NUM_SUB_DESCRIPTORS,                                             //�¼�������������
 {
  {
   REPORT_DESCRIPTOR,                                             //�¼�������Ϊ����������
   SWAP16(sizeof(KeyBoardReportDescriptor))                       //�¼��������ĳ���
  }
 },
},
//endpoint_descriptor[]
{
 {                                                                //���˵���������
  sizeof(ENDPOINT_DESCRIPTOR_STRUCT),                             //�˵����������ֽ�����С
  ENDPOINT_DESCRIPTOR,                                            //�˵����������ͱ��
  MAIN_POINT_IN,                                                  //�˵�ţ�������˵�
  ENDPOINT_TYPE_INTERRUPT,                                        //ʹ�õĴ������ͣ��жϴ���
  SWAP16(0x0040),                                                 //�ö˵�֧�ֵ������ߴ磬64�ֽ�
  0x0A                                                            //�ж�ɨ��ʱ�䣺����Ϊ10ms
 },
  
 {                                                                //���˵��������
  sizeof(ENDPOINT_DESCRIPTOR_STRUCT),                             //�˵����������ֽ�����С
  ENDPOINT_DESCRIPTOR,                                            //�˵����������ͱ��
  MAIN_POINT_OUT,                                                 //�˵�ţ�������˵�
  ENDPOINT_TYPE_INTERRUPT,                                        //ʹ�õĴ������ͣ��жϴ���
  SWAP16(0x0040),                                                 //�ö˵�֧�ֵ������ߴ磬64�ֽ�
  0x0A                                                            //�ж�ɨ��ʱ�䣺����Ϊ10ms
 }
}
};

union                                          //�����־λ
{
uint16 Register;
struct 
{
 uint8 bus_reset        :1;
 uint8 suspend          :1;
 uint8 remote_wakeup    :1;
 uint8 int_isr          :1;
 uint8 not_end          :1;
 uint8 usb_idle         :1;
 uint8 usb_busy         :1;
 uint8 setup_packet_in  :1;
 uint8 setup_packet_out :1;
 uint8 set_addr         :1;
 uint8 usb_endp0_in     :1;
 uint8 usb_endp2_in     :1;
 uint8 usb_endp2_out    :1;
}flags;
}usb_flags;

union                                         //�жϼĴ���
{
 uint8 Register[2];
 struct 
  {
   uint8 control_out_port  :1;
   uint8 control_in_port   :1;
   uint8 port_out_1        :1;
   uint8 port_in_1         :1;
   uint8 main_out_port     :1;
   uint8 main_in_port      :1;
   uint8 bus_reset         :1;
   uint8 suspend_change    :1;
   uint8 DMA_EOT           :1;
   uint8 not_use           :7;
  }Interrupt;
}Interrupt_Register;


union                                    //�˵������״̬
{
 uint8 Register;
 struct
 {
  uint8 successful          :1;
  uint8 error_code          :4;
  uint8 setup_packet        :1;
  uint8 data_1              :1;
  uint8 prestatus_not_read  :1;
 }Status;
}Last_Status;


/*****************   ��ʱx���뺯�� ***********/
void delay(uint16 x)                
{
 uint16 i;
 uint16 j;
 for(i=0;i<x;i++)
 for(j=0;j<230;j++);
}
/********************************************/

/*******************************дUSB����******************************************/
void write_usb_command(uint8 usb_command)
{
 USB_A0=USB_COMMAND_ADD;
 USB_DATA=usb_command;
 USB_WR=0;
 USB_WR=1;
 USB_DATA=0xFF;
}
/******************************************************************************/

/*********************дһ�ֽ�USB����*******************************************/
void write_a_usb_data(uint8 usb_data)       
{
 USB_A0=USB_DATA_ADD;
 USB_DATA=usb_data;
 USB_WR=0;
 USB_WR=1;
 USB_DATA=0XFF;
}
/******************************************************************************/

/****************************��һ�ֽ�USB����************************************/
uint8 read_a_usb_data(void)
{
 uint8 temp;
 USB_A0=USB_DATA_ADD;
 USB_RD=0;
 temp=USB_DATA;
 USB_RD=1;
 return temp;
}
/******************************************************************************/

/************************��USB�жϼĴ���**************************************/
void read_interrupt_register(void)
{
 write_usb_command(Read_Interrupt_Register);
 Interrupt_Register.Register[0]=read_a_usb_data();
 Interrupt_Register.Register[1]=read_a_usb_data();
}
/******************************************************************************/

/************************����USB��ַ*******************************************/
void set_usb_addr(uint8 addr)
{
 write_usb_command(Set_Address);
 write_a_usb_data(0x80|addr);
 Prints("   ���õ�ַ.\r\n");
 Prints("       ��ַΪ��  ");
 PrintLongInt(addr);
 Prints("\r\n");
}
/******************************************************************************/

/*************************�˵�ʹ��******************************************/
void set_endpoint_enable(void)
{
 write_usb_command(Set_Endpoint_Enable);
 write_a_usb_data(0x01);
}
/******************************************************************************/

/****************************ѡ���ն˵�*************************************/
uint8 select_endpoint(uint8 endp)
{
 write_usb_command(Select_EndPoint+endp);
 return read_a_usb_data();
}
/******************************************************************************/

/****************************���˵����״̬**********************************/
uint8  read_last_status(uint8 endp)
{
 write_usb_command(Read_Last_Status+endp);
 return read_a_usb_data();
}
/******************************************************************************/

/****************************���ö˵�״̬**************************************/
void set_endpoint_status(uint8 endp,uint8 status)  
{
 write_usb_command(0x40+endp);
 write_a_usb_data(!status);
}
/******************************************************************************/

/*****************************���˵�״̬**************************************/
uint8 read_endpoint_status(uint8 endp)
{
 write_usb_command(0x80+endp);
 return read_a_usb_data();
}
/******************************************************************************/

/************************�建�壬�ڶ�ȡ�������ݺ����**************************/
void clear_buffer(void)
{
 write_usb_command(Clear_Buffer);
#ifdef debug
 Prints("Clear buffer.\r\n");
#endif
}
/******************************************************************************/

/***********************������������Ч����д��������**************************/
void validate_buffer(void)
{
 write_usb_command(Validate_Buffer);
#ifdef debug
 Prints("Validate buffer.\r\n");
#endif
}
/******************************************************************************/

/***************************Ӧ������************************************/
void ack_setup(uint8 endp)
{
 select_endpoint(endp);
 write_usb_command(Ack_Setup);
#ifdef debug
 Prints("Ack setup ");
 PrintLongInt(endp);
 Prints(".\r\n");
#endif
}
/******************************************************************************/

/***********************������******************************************/
void error(uint8 number)
{
 Prints("�д�����������\r\n");
 number=0;
}
/******************************************************************************/

/*************************���ն˵㻺��****************************************/
uint8 read_endpoint_buff(uint8 endp,uint8 len,uint8 * buff)
{
 uint8 i,j;
 read_last_status(endp);
 if(!(select_endpoint(endp)&0x01)){error(0); return 0;}
 if((read_endpoint_status(endp)&0x60)!=0x60)  //��������û�ж������������ж�
 {
  read_last_status(endp);  //���ж�
 }
 write_usb_command(Read_Buffer);
 read_a_usb_data();
 j=read_a_usb_data();
 if(j>len)
  j=len;  
#ifdef debug
 Prints("Read endpoint");
 PrintLongInt(endp);
 Prints("\'s buffer ");
 PrintLongInt(j);
 Prints(" bytes.\r\n");
#endif  
 for(i=0;i<j;i++)
  {
   USB_RD=0;
   *(buff+i)=USB_DATA;
   USB_RD=1;
#ifdef debug
   PrintHex(*(buff+i));
#endif
  }
#ifdef debug
 Prints("\r\n");
#endif
 clear_buffer();
 return j;
}
/******************************************************************************/

/*************************д�ն˵㻺��*****************************************/
uint8 write_endpoint_buff(uint8 endp,uint8 len,uint8 * buff)
{
 uint8 i;
 read_last_status(endp);
 select_endpoint(endp);
 write_usb_command(Write_Buffer);
 write_a_usb_data(0);
 write_a_usb_data(len);
#ifdef debug
 Prints("Write endpoint");
 PrintLongInt(endp);
 Prints("\'s buffer ");
 PrintLongInt(len);
 Prints(" bytes.\r\n");
#endif
 for(i=0;i<len;i++)
  {
   USB_DATA=*(buff+i);
   USB_WR=0;
   USB_WR=1;
#ifdef debug
   PrintHex(*(buff+i));
#endif
  }
#ifdef debug
 Prints("\r\n");
#endif  
 USB_DATA=0xFF;
 validate_buffer();
 return len;
}
/******************************************************************************/

/***************************�Ͽ�USB����****************************************/
void disconnect_usb(void)
{
 Prints("�Ͽ�USB����.\r\n");
 write_usb_command(0xf3);
 write_a_usb_data(0x0e);
 write_a_usb_data(0x47);
 delay(100);
}
/******************************************************************************/

/*******************************����USB**************************************/
void connect_usb(void)
{
 Prints("����USB.\r\n");
 write_usb_command(0xf3);                         //��ʼ��USBD12
 write_a_usb_data(0x1e);                          //����USB
 write_a_usb_data(0x47);                          //����Ƶ��
}
/******************************************************************************/

/***************************��ʼ��USB***************************************************/
void init_usb(void)               
{
 Prints("USBD12оƬ��ʼ��\r\n");
 set_usb_addr(0);
 set_endpoint_enable();
}
/******************************************************************************/

/****************************USB���߸�λ����***********************************/
void usb_bus_reset(void)
{
 Prints("USB���߸�λ.\r\n");
 usb_flags.Register=0;
 set_endpoint_enable();
}
/******************************************************************************/

/*****************************USB���߹�����**********************************/
void usb_bus_suspend(void)
{
 Prints("USB���߹���.\r\n");
}
/******************************************************************************/

/***************************���õ�ַ***************************************/
void set_usb_address(void)
{
 usb_flags.flags.set_addr=1;
 set_usb_addr(Control_Data.DeviceRequest.wValue);
 while(select_endpoint(1)&0x01);
 write_endpoint_buff(1,0,0);
 while(select_endpoint(1)&0x01);
 usb_flags.flags.usb_endp0_in=0;
 usb_flags.flags.setup_packet_out=0;
}
/******************************************************************************/

/**************************��ȡ״̬��Ӧ*****************************************/
void get_status(uint8 receiver)
{
 uint8 status[2];
 switch (receiver)
  {
   case 0:                        //��ȡ�豸״̬
    status[0]=0x00;
    status[1]=0x00;
    break;
   case 1:                        //��ȡ�ӿ�״̬
    status[0]=0x00;
    status[0]=0x00;
    break;
   case 2:                        //��ȡ�˵�״̬
    status[0]=0x00;
    status[1]=0x00;
    break;
   }
  write_endpoint_buff(1,2,status);
  usb_flags.flags.usb_endp0_in=0;
}
/******************************************************************************/

/*********************�������*******************************************/
void clear_feature(uint8 receiver)    
{
 Prints("    �������.\r\n");
 receiver=0;
 write_endpoint_buff(1,0,0);
 usb_flags.flags.usb_endp0_in=0;
 usb_flags.flags.setup_packet_out=0;
}
/******************************************************************************/

/*******************��������**************************************************/
void set_feature(uint8 receiver)
{
 Prints("    ��������.\r\n");
 receiver=0;
 write_endpoint_buff(1,0,0);
 usb_flags.flags.usb_endp0_in=0;
 usb_flags.flags.setup_packet_out=0;
}
/******************************************************************************/

/*****************************��������*****************************************/
void set_descriptor(void)
{
 Prints("    ����������.\r\n");
 usb_flags.flags.usb_endp0_in=0;
 usb_flags.flags.setup_packet_out=0;
}
/******************************************************************************/

/***************************��������*******************************************/
void set_configuration(void)
{
 Prints("    ��������.\r\n");
 write_endpoint_buff(1,0,0);
 usb_flags.flags.usb_endp0_in=0;
 usb_flags.flags.setup_packet_out=0;
}
/******************************************************************************/

/************************��ȡ����״̬******************************************/
void get_configuration(void)
{ 
 uint8 value=0x01;
 Prints("    ��ȡ����.\r\n");
 write_endpoint_buff(1,1,&value);
 usb_flags.flags.usb_endp0_in=0;
}
/******************************************************************************/

/****************************���ýӿ�************************************/
void set_interface(void)
{
 Prints("    ���ýӿ�.\r\n");
 write_endpoint_buff(1,0,0);
 usb_flags.flags.usb_endp0_in=0;
 usb_flags.flags.setup_packet_out=0;
}
/******************************************************************************/

/***************************��ȡ�ӿ�״̬***************************************/
void get_interface(void)
{
 uint8 value=0x01;
 Prints("    ��ȡ�ӿ�.\r\n");
 write_endpoint_buff(1,1,&value);
 usb_flags.flags.usb_endp0_in=0;
}
/******************************************************************************/

/***********************��ȡ������*********************************************/
void get_descriptor(void)
{
 Prints("    ��ȡ������.\r\n");
  if(!usb_flags.flags.not_end)
     {
      switch(MSB(Control_Data.DeviceRequest.wValue))
	   {
        case DEVICE_DESCRIPTOR:
		     Prints("        ��ȡ�豸������.\r\n");
	         Control_Data.wCount=sizeof(DEVICE_DESCRIPTOR_STRUCT);
 	         Control_Data.pData=(uint8 *)(&device_descriptor);
             break;
        case CONFIGURATION_DESCRIPTOR:
			 Prints("        ��ȡ����������.\r\n");
             Control_Data.wCount=SWAP16(con_int_endp_descriptor.configuration_descriptor.wTotalLength);
			 Control_Data.pData=(uint8 *)(&con_int_endp_descriptor);
             if(Control_Data.wLength<Control_Data.wCount)Control_Data.wCount=Control_Data.wLength;
             break;
		case STRING_DESCRIPTOR:
		     Prints("        ��ȡ�ַ���������.\r\n");
			 switch(LSB(Control_Data.DeviceRequest.wValue))
			  {
			   case 0:
			    Prints("            ��ȡ����ID.\r\n");
			    Control_Data.wCount=LANGUAGE_ID[0];
                Control_Data.pData=LANGUAGE_ID;
   			    break;

			   case 1:
			    Prints("            ��ȡ�����ַ���.\r\n");
			    Control_Data.wCount=ManufacturerString[0];
                Control_Data.pData=ManufacturerString;
			    break;

			   case 2:
			    Prints("            ��ȡ��Ʒ�ַ���.\r\n");
			    Control_Data.wCount=ProducterString[0];
                Control_Data.pData=ProducterString;
			    break;

			   case 3:
                 Prints("            ��ȡ�豸���к�.\r\n");
			     Control_Data.wCount=device_serial_number[0];
			     Control_Data.pData=device_serial_number;
			   break;

			   default:
                 Prints("            ����������(δ֪).\r\n");
                 Prints("�ļ�");
				 Prints(__FILE__);
				 Prints("\r\n");
				 Prints("��:");
				 Prints(__LINE__);
				 Prints("\r\n");
               break;
			  }
			 break;
		 default:
		     Prints("       ��ȡ����������..................����������Ϊ��");
			 PrintLongInt(MSB(Control_Data.DeviceRequest.wValue));
			 Prints("\r\n"); 
		  break;
	   	}
      if(Control_Data.wLength<Control_Data.wCount)Control_Data.wCount=Control_Data.wLength;
	 }
	//д���ݵ�D12����˵�
    if(Control_Data.wCount>=MAX_CONTROL_DATA_SIZE)
     {
	  write_endpoint_buff(1,MAX_CONTROL_DATA_SIZE,Control_Data.pData);
	  Control_Data.pData+=MAX_CONTROL_DATA_SIZE;
      Control_Data.wCount-=MAX_CONTROL_DATA_SIZE;
	  if(usb_flags.flags.set_addr)usb_flags.flags.not_end=1;
	   else usb_flags.flags.usb_endp0_in=0;
	  return;
	 }
    else
     {
	  write_endpoint_buff(1,Control_Data.wCount,Control_Data.pData);
      usb_flags.flags.setup_packet_in=0;
	  usb_flags.flags.usb_endp0_in=0;
	  return;
	 }      
}
/******************************************************************************/

/*********************�����ӿڵĻ�ȡ������**************************************/
void get_descriptor_interface(void)
{
 Prints("    ��ȡ���������ӽӿڣ�.\r\n");
  if(!usb_flags.flags.not_end)
     {
      switch(MSB(Control_Data.DeviceRequest.wValue))
	   {
        case HID_DESCRIPTOR:
		     Prints("        ��ȡHID������.\r\n");
	         Control_Data.wCount=sizeof(HID_DESCRIPTOR_STRUCT);
 	         //Control_Data.pData=(uint8 *)(&hid_descriptor);
             break;
        case REPORT_DESCRIPTOR:
			 Prints("        ��ȡ����������.\r\n");
             Control_Data.wCount=sizeof(KeyBoardReportDescriptor);
			 Control_Data.pData=(uint8 *)(KeyBoardReportDescriptor);
             if(Control_Data.wLength<Control_Data.wCount)Control_Data.wCount=Control_Data.wLength;
             break;
		case PHYSICAL_DESCRIPTOR:
		     Prints("        ��ȡ����������.\r\n");
			 break;
		 default:
		     Prints("       ��ȡ����������..................����������Ϊ��");
			 PrintLongInt(MSB(Control_Data.DeviceRequest.wValue));
			 Prints("\r\n"); 
		  break;
	   	}
      if(Control_Data.wLength<Control_Data.wCount)Control_Data.wCount=Control_Data.wLength;
	 }
	//д���ݵ�D12����˵�
    if(Control_Data.wCount>=MAX_CONTROL_DATA_SIZE)
     {
	  write_endpoint_buff(1,MAX_CONTROL_DATA_SIZE,Control_Data.pData);
	  Control_Data.pData+=MAX_CONTROL_DATA_SIZE;
      Control_Data.wCount-=MAX_CONTROL_DATA_SIZE;
	  if(usb_flags.flags.set_addr)usb_flags.flags.not_end=1;
	   else usb_flags.flags.usb_endp0_in=0;
	  return;
	 }
    else
     {
	  write_endpoint_buff(1,Control_Data.wCount,Control_Data.pData);
      usb_flags.flags.setup_packet_in=0;
	  usb_flags.flags.usb_endp0_in=0;
	  return;
	 }      
}
/******************************************************************************/

/************************�ն˵�0����жϴ���************************************/
void endp0_out(void)
{
 Last_Status.Register=read_last_status(0);
 if(Last_Status.Status.setup_packet)
  {
   Control_Data.wLength=0;
   Control_Data.wCount=0;
   if(read_endpoint_buff(0,sizeof(Control_Data.DeviceRequest),(uint8 *)(&(Control_Data.DeviceRequest)))!=sizeof(REQUESTCMD))
    {
	 set_endpoint_status(0,0);
	 set_endpoint_status(1,0);
	 return;
	}
  Control_Data.DeviceRequest.wValue=SWAP16(Control_Data.DeviceRequest.wValue);
  Control_Data.DeviceRequest.wIndex=SWAP16(Control_Data.DeviceRequest.wIndex);
  Control_Data.DeviceRequest.wLength=SWAP16(Control_Data.DeviceRequest.wLength);

  ack_setup(0);
  ack_setup(1);
  select_endpoint(0);
  clear_buffer();  
  
  Control_Data.wLength=Control_Data.DeviceRequest.wLength;
  usb_flags.flags.not_end=0;
  usb_flags.flags.usb_endp0_in=1;
  if(Control_Data.DeviceRequest.bmRequestType&0x80)
  {
   usb_flags.flags.setup_packet_in=1;
   usb_flags.flags.setup_packet_out=0;
   return;
  }
  else 
  {
   usb_flags.flags.setup_packet_in=0;
   usb_flags.flags.setup_packet_out=1;
   if(Control_Data.wLength!=0)
   {
    usb_flags.flags.usb_endp0_in=0;
   }
   return;
  }
 }
 else
 {
  if(usb_flags.flags.setup_packet_out) 
  {
   usb_flags.flags.usb_endp0_in=1;
  }
  else
  {
   select_endpoint(0);
   clear_buffer();
  }
 }
}
/******************************************************************************/

/***********************��ȡ����*********************************************/
void get_report(void)
{
 Prints("        ��ȡ����.\r\n");
}
/******************************************************************************/

/**********************��ȡ����״̬*********************************************/
void get_idle(void)
{
 Prints("    ��ȡ����.\r\n");
 write_endpoint_buff(1,1,&idle);
 usb_flags.flags.usb_endp0_in=0;
}
/******************************************************************************/

/*************************��ȡЭ��**********************************************/
void get_protocol(void)
{
 Prints("    ��ȡЭ��.\r\n");
 write_endpoint_buff(1,1,&protocol);
 usb_flags.flags.usb_endp0_in=0;
}
/******************************************************************************/

/***********************���ñ���***********************************************/
void set_report(void)
{
 Prints("    ���ñ���.\r\n");
}
/******************************************************************************/

/***********************���ÿ���***********************************************/
void set_idle(void)
{
 Prints("    ���ÿ���.\r\n");
 while(select_endpoint(1)&0x01);
 write_endpoint_buff(1,0,0);
 idle=Control_Data.DeviceRequest.wValue;
 usb_flags.flags.usb_endp0_in=0;
 usb_flags.flags.setup_packet_out=0;
}
/******************************************************************************/

/**********************����Э��**************************************************/
void set_protocol(void)
{
 Prints("    ����Э��.\r\n");
 while(select_endpoint(1)&0x01);
 write_endpoint_buff(1,0,0);
 protocol=Control_Data.DeviceRequest.wValue;
 usb_flags.flags.usb_endp0_in=0;
 usb_flags.flags.setup_packet_out=0;
}
/******************************************************************************/

/****************************�ն˵�0���봦��**************************************/
void endp0_in(void)
{
 read_last_status(1);
 //��������������
 if(usb_flags.flags.setup_packet_in||usb_flags.flags.not_end)
  {
    switch(Control_Data.DeviceRequest.bmRequestType&0x60)
	 {
	   case 0x00:  //��׼����
	   Prints("USB��׼����.\r\n");
	   switch(Control_Data.DeviceRequest.bmRequestType&0x1F)
	    {
		 case 0: //���豸
		   switch (Control_Data.DeviceRequest.bRequest)
		    {
		     case 0: get_status(0);break;
		     case 6: get_descriptor();break;
		     case 8: get_configuration();break;
			 default:break;
		    }
		 break;

		 case 1:  //���ӿ�
		   switch (Control_Data.DeviceRequest.bRequest)
		    {
	         case  0: get_status(1);break;
			  case 6: get_descriptor_interface();break;
		     case 10: get_interface();break;
	         default: break;
			}
		 break;

		 case 2:  //���˵�
		  {
	       if(Control_Data.DeviceRequest.bRequest==0)get_status(2);  
		  }
		 default: break;
	    }
	   break;

	   case 0x20:  //������
       Prints("USB������.\r\n");
	   switch(Control_Data.DeviceRequest.bmRequestType&0x1F)
	    {
		 case 0:  //���豸
		   switch (Control_Data.DeviceRequest.bRequest)
		    {
			 default:break;
		    }
		 break;

		 case 1:  //���ӿ�
		   switch (Control_Data.DeviceRequest.bRequest)
		    {

	  		 case   GET_REPORT: get_report();   break; //��ȡ����
             case     GET_IDLE: get_idle();     break; //��ȡ����״̬
             case GET_PROTOCOL: get_protocol(); break; //��ȡЭ��
	         default: break;
			}
		 break;

		 case 2:  //���˵�
		  {
		   switch (Control_Data.DeviceRequest.bRequest)
		    {
	         default: break;
			}  
		  }
		 default: break;
	    }
	   break;

	   case 0x40:  //�û�����
       Prints("USB�û�����.\r\n");
	   switch(Control_Data.DeviceRequest.bmRequestType&0x1F)
	    {
		 case 0:  //���豸
		   switch (Control_Data.DeviceRequest.bRequest)
		    {
			 default: break;
		    }
	     break;

		 case 1:   //���ӿ�
		   switch (Control_Data.DeviceRequest.bRequest)
		    {
	         default: break;
			}
         break;

		 case 2:  //���˵�
		  {
		   switch (Control_Data.DeviceRequest.bRequest)
		    {
	         default: break;
			}  
		  }
		 default: break;
	    }
	}
    return;
  }

  //�������������
 if(usb_flags.flags.setup_packet_out) 
  {
    switch(Control_Data.DeviceRequest.bmRequestType&0x60)
	 {
	   case 0x00:  //��׼����
	   Prints("USB��׼����.\r\n");
	   switch(Control_Data.DeviceRequest.bmRequestType&0x1F)
	    {
		 case 0:   //���豸
	     switch (Control_Data.DeviceRequest.bRequest)
	      {
		   case     CLEAR_FEATURE: clear_feature(0);break;
		   case       SET_FEATURE: set_feature(0);break;
		   case       SET_ADDRESS: set_usb_address();break;          //set_address	           
		   case    SET_DESCRIPTOR: set_descriptor();break;           //set_descriptor
		   case SET_CONFIGURATION: set_configuration(); break;       //set_configurat               	          
	  	   default: break;
		  }
		 break;
		 
		 case 1:   //���ӿ�
	      switch (Control_Data.DeviceRequest.bRequest)
		   {
		    case CLEAR_FEATURE:  clear_feature(1);break;
		    case   SET_FEATURE:  set_feature(1); break;
	        case SET_INTERFACE: set_interface();break;
		    default: break;
	        }
		 break;
		 
		 case 2:   //���˵�
		  switch (Control_Data.DeviceRequest.bRequest)
		   {
		    case CLEAR_FEATURE: clear_feature(2);break;
		    case   SET_FEATURE: set_feature(2);break;
	        default: break;      
		   }
		 break;

		 default: break;
	    }
      break;

	  case 0x20:  //������
      Prints("USB������.\r\n");
	   switch(Control_Data.DeviceRequest.bmRequestType&0x1F)
	    {
		 case 0:    //������Ϊ�豸
	     switch (Control_Data.DeviceRequest.bRequest)
	      {             	          
	  	   default: break;
		  }
		 break;

		 case 1:   //������Ϊ�ӿ�
	      switch (Control_Data.DeviceRequest.bRequest)
		   {
            case   SET_REPORT: set_report();   break; //���ñ���
            case     SET_IDLE: set_idle();     break; //���ÿ���
            case SET_PROTOCOL: set_protocol(); break; //����Э��
		    default: break;
	        }
		 
		 break;

		 case 2:   //������Ϊ�˵�
		  switch (Control_Data.DeviceRequest.bRequest)
		   {
	        default: break;      
		   }
		 break;
		 
		 case 3: //����������
		  switch (Control_Data.DeviceRequest.bRequest)
		   {
	        default: break;      
		   }break;
		   		  
		 default: break;
	    }      
	   break;

       case 0x40:  //�û�����
	   Prints("USB�û�����.\r\n");
	   switch(Control_Data.DeviceRequest.bmRequestType&0x1F)
	    {
		 case 0:    //������Ϊ�豸
	     switch (Control_Data.DeviceRequest.bRequest)
	      {             	          
	  	   default: break;
		  }
		 break;
		 
		 case 1:   //������Ϊ�ӿ�
	      switch (Control_Data.DeviceRequest.bRequest)
		   {
		    default: break;
	        }
	     break;
		 
		 case 2:   //������Ϊ�˵�
		  switch (Control_Data.DeviceRequest.bRequest)
		   {
	        default: break;      
		   }
		 break;
		 
		 case 3: //����������
		  switch (Control_Data.DeviceRequest.bRequest)
		   {
	        default: break;      
		   }		   
		 break;
		   		  
		 default: break;
	    }
	}
  }
}
/******************************************************************************/

/**********************�˵�1���***********************************************/
/*void endp1_out(void)
{
 Prints("�˵�1���.\r\n");
}*/
/******************************************************************************/

/*************************�˵�1����*****************************************/
/*void endp1_in(void)
{
 Prints("�˵�1����.\r\n");
}*/
/******************************************************************************/

/***************************�˵�2���****************************************/
void endp2_out(void)
{
 uint8 i,j;

 j=read_endpoint_buff(4,64,buffer);
 LEDs=~buffer[0];
 Prints("�˵�2���.\r\n");
 Prints("    �˵�2��������  ");
 for(i=0;i<j;i++)
  {
   PrintHex(buffer[i]);
   if(i==16)Prints("\r\n");
  }
 Prints("\r\n");
}
/******************************************************************************/


//�����������ݵĻ���
uint8 idata InBuffer[64];

/****************************���˵����봦��************************************/
void endp2_in(void)                                      
{
 uint8 i;
// Prints("�˵�2����.\r\n");
	i=keyscan();
 if(i) //����а�������
  {
   if(i==1) //��Ctrl��
    {
     InBuffer[0] |=1;
    }
   else
    {
     InBuffer[0]&=~1;
    }	
   if(i==2) //��shift��
    {
     InBuffer[0]|=1<<1;
    }
   else
    {
     InBuffer[0]&=~(1<<1);
    }
	
   if(i==3) //��ALT��
    {
     InBuffer[0]|=1<<2;
    }
   else
    {
	 InBuffer[0]&=~(1<<2);
	}

   i=2;
   if(i==4)
    {
     InBuffer[i++]=0x62;	    //0��
    }
   if(i==5)
    {
	 InBuffer[i++]=0x59;	    //1��
	}
   if(i==6)
    {
     InBuffer[i++]=0x5A;	    //2��
    }
   if(i==7)
    {
     InBuffer[i++]=0x39;	    //Caps Lock��
    }
   if(i==8)
    {
     InBuffer[i++]=0x53;	    //Num Lock��
    }
   for(;i<8;i++)
   {
    InBuffer[i]=0;  //�������0
   }
  }
 else //����ް������£��򷵻�0
  {
   for(i=0;i<8;i++)
    {
	 InBuffer[i]=0;
	}
  }

  write_endpoint_buff(5,8,InBuffer);


}
/******************************************************************************/

code uint8 HeadTable[][74]={
"********************************************************************\r\n",
"******                 EDN USBѧϰ����̳���                  ******\r\n",
"******                      AT89S52 CPU                       ******\r\n",
"******                  �������ڣ�",__DATE__,"                 ******\r\n",
"******                   ����ʱ�䣺",__TIME__,"                   ******\r\n",
"******                    ���ߣ�����ȦȦ                      ******\r\n",
"******                    ��ӭ�������ߵ�                      ******\r\n",
"******           USBר����http://group.ednchina.com/93/       ******\r\n",
"******      BLOG1��http://www.ednchina.com/blog/computer00    ******\r\n",
"******                BLOG2��http://computer00.21ic.org       ******\r\n",
"******                  �밴K1-K8�ֱ���в���                 ******\r\n",
"******       K1:��Ctrl��  K2:��Shift��  K3:��Alt��  K4:0��    ******\r\n",
"******       K5:1��  K6:2��  K7:Caps Lock�� K8:Num Lock��     ******\r\n",
"********************************************************************\r\n",
};



/***************************������**********************************************/
void main(void)
{
 uint8 i;
 InitUART();  //���ڳ�ʼ��
 Printc(0x0c);  //����
 Printc(0x0c);
 Prints("ϵͳ����.\r\n");
 for(i=0;i<18;i++)	  //��ʾ��Ϣ
 {
  Prints(HeadTable[i]);
 } 
 disconnect_usb(); 	   //�Ͽ�USB����
 delay(1000);	       //�ӳ�
 init_usb();		   //��ʼ��USBоƬ
 connect_usb();		   //����USB


 while(1)
  { 
   if(!USB_INT)		//�жϲ���
    {
  	 read_interrupt_register();
	 if(Interrupt_Register.Interrupt.bus_reset){usb_bus_reset();continue;}
	 if(Interrupt_Register.Interrupt.suspend_change){usb_bus_suspend();continue;}
     if(Interrupt_Register.Interrupt.control_out_port){endp0_out();continue;}
	 if(Interrupt_Register.Interrupt.control_in_port&&usb_flags.flags.usb_endp0_in){endp0_in();continue;}
//	 if(Interrupt_Register.Interrupt.port_out_1)endp1_out();
//	 if(Interrupt_Register.Interrupt.port_in_1)endp1_in();
	 if(Interrupt_Register.Interrupt.main_out_port){endp2_out();}
	 if(Interrupt_Register.Interrupt.main_in_port){endp2_in();}
    }
  }
}
