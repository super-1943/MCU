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

//USB芯片连接引脚
#define USB_DATA                  P0
#define USB_A0                    P3_5
#define USB_WR                    P3_6
#define USB_RD                    P3_7
#define USB_INT                   P3_2


#define ENDPOINT_NUMBER           2
#define MAX_CONTROL_DATA_SIZE     16


//控制传输时保存数据
CONTROL_DATA_BUFF Control_Data;

//缓冲
uint8 idata buffer[64];

//交换数据时用的指针
uint8 *pData;

uint8 idle;     //空闲状态
uint8 protocol; //当前协议

//高低字节交换

#define SWAP16(x)  ((((uint16)(x))<<8)|(((uint16)(x))>>8))

//取一个整数的低字节 
#define LSB(x) ((uint8)(x))

//取一个整数的高字节
#define MSB(x) ((uint8)(((uint16)(x))>>8))                               

//字符串描述符所用的语言种类 
code uint8 LANGUAGE_ID[4]={0x04,0x03,0x09,0x04};                   

//设备序列号										
code uint8 device_serial_number[]=
{22,STRING_DESCRIPTOR,'2',0,'0',0,'0',0,'7',0,'-',0,'1',0,'1',0,'-',0,'2',0,'9',0};

//厂商字符串　电脑圈圈的USB专区 http://group.ednchina.com/93
//汉字Unicode编码，使用http://computer00.21ic.org/user1/2198/archives/2007/42769.html转换
code uint8 ManufacturerString[80]=
{80,STRING_DESCRIPTOR,0x35,0x75,0x11,0x81,0x08,0x57,0x08,0x57,0x84,0x76,'U',0x00,
 'S',0x00,'B',0x00,0x13,0x4E,0x3A,0x53,0x20,0x00,'H',0,'t',0,'t',0,
 'p',0,':',0,'/',0,'/',0,'g',0,'r',0,'o',0,'u',0,'p',0,'.',0,'e',0,'d',0,'n',0,
 'c',0,'h',0,'i',0,'n',0,'a',0,'.',0,'c',0,'o',0,'m',0,'/',0,'9',0,'3',0};

//产品字符串　电脑圈圈的USB专区活动之USB键盘 http://group.ednchina.com/93
//汉字Unicode编码，使用http://computer00.21ic.org/user1/2198/archives/2007/42769.html转换
code uint8 ProducterString[96]=
{96,STRING_DESCRIPTOR,0x35,0x75,0x11,0x81,0x08,0x57,0x08,0x57,0x84,0x76,'U',0x00,
 'S',0x00,'B',0x00,0x13,0x4E,0x3A,0x53,0x3B,0x6D,0xA8,0x52,0x4B,0x4E,'U',0x00,
 'S',0x00,'B',0x00,0x2E,0x95,0xD8,0x76,0x20,0x00,'H',0,'t',0,'t',0,
 'p',0,':',0,'/',0,'/',0,'g',0,'r',0,'o',0,'u',0,'p',0,'.',0,'e',0,'d',0,'n',0,
 'c',0,'h',0,'i',0,'n',0,'a',0,'.',0,'c',0,'o',0,'m',0,'/',0,'9',0,'3',0};

code DEVICE_DESCRIPTOR_STRUCT device_descriptor=     //设备描述符
{
 sizeof(DEVICE_DESCRIPTOR_STRUCT),                   //设备描述符的字节数大小
 DEVICE_DESCRIPTOR,	                                 //设备描述符类型编号
 SWAP16(0x0110),                                     //USB版本号,USB1.1
 0x00,                                               //USB分配的设备类代码
 0x00,                                               //USB分配的子类代码
 0x00,                                               //USB分配的设备协议代码
 0x10,                                               //端点0的最大包大小
 SWAP16(0x8888),                                     //厂商编号VID，这里只是作为测试用，请使用自己的VID
 SWAP16(0x0001),                                     //产品编号PID，这里只是作为测试用，请使用自己的PID
 SWAP16(0x0001),                                     //设备出厂编号
 0x01,                                               //设备厂商字符串的索引
 0x02,                                               //描述产品字符串的索引
 0x03,                                               //描述设备序列号字符串的索引
 0x01                                                //可能的配置数量
};

//定义配置，接口，端点等描述符结构体，因为它们是随配置描述符一起返回的
typedef struct _CON_INT_ENDP_DESCRIPTOR_STRUCT
{
 CONFIGURATION_DESCRIPTOR_STRUCT configuration_descriptor;
 INTERFACE_DESCRIPTOR_STRUCT  interface_descriptor;
 HID_DESCRIPTOR_STRUCT hid_descriptor;
 ENDPOINT_DESCRIPTOR_STRUCT  endpoint_descriptor[ENDPOINT_NUMBER];
}CON_INT_ENDP_DESCRIPTOR_STRUCT;

code CON_INT_ENDP_DESCRIPTOR_STRUCT con_int_endp_descriptor=
{
//configuration_descriptor                                          //配置描述符
{
 sizeof(CONFIGURATION_DESCRIPTOR_STRUCT),                           //配置描述符的字节数大小
 CONFIGURATION_DESCRIPTOR,                                          //配置描述符类型编号
 SWAP16(sizeof(CON_INT_ENDP_DESCRIPTOR_STRUCT)),
 0x01,                                                            //只包含一个接口
 0x01,                                                            //该配置的编号
 0x00,                                                            //iConfiguration字段
 0xA0,                                                            //采用总线供电，支持远程唤醒
 0xC8                                                            //从总线获取最大电流400mA
},
//interface_descritor                                             //接口描述符
{
 sizeof(INTERFACE_DESCRIPTOR_STRUCT),                             //接口描述符的字节数大小
 INTERFACE_DESCRIPTOR,                                            //接口描述符类型编号
 0x00,                                                            //接口编号为0
 0x00,                                                            //该接口描述符的编号
 ENDPOINT_NUMBER,                                                 //非0端点数量为2，只使用端点主端点输入和输出
 0x03,                                                            //人机接口设备（HID）类
 0x01,                                                            //使用的子类：支持BIOS根启动Boot的子类
 0x01,                                                            //使用的协议：键盘
 0x00                                                             //接口描述符字符串索引
},
//hid_descriptor
{
 sizeof(HID_DESCRIPTOR_STRUCT),                                   //HID描述符的字节数大小
 HID_DESCRIPTOR,                                                  //HID描述符类型编号
 SWAP16(0x0110),                                                  //HID类协议版本号，为1.1
 0x21,                                                            //固件的国家地区代号，0x21为美国
 NUM_SUB_DESCRIPTORS,                                             //下级描述符的数量
 {
  {
   REPORT_DESCRIPTOR,                                             //下级描述符为报告描述符
   SWAP16(sizeof(KeyBoardReportDescriptor))                       //下级描述符的长度
  }
 },
},
//endpoint_descriptor[]
{
 {                                                                //主端点输入描述
  sizeof(ENDPOINT_DESCRIPTOR_STRUCT),                             //端点描述符的字节数大小
  ENDPOINT_DESCRIPTOR,                                            //端点描述符类型编号
  MAIN_POINT_IN,                                                  //端点号，主输入端点
  ENDPOINT_TYPE_INTERRUPT,                                        //使用的传输类型：中断传输
  SWAP16(0x0040),                                                 //该端点支持的最大包尺寸，64字节
  0x0A                                                            //中断扫描时间：设置为10ms
 },
  
 {                                                                //主端点输出描述
  sizeof(ENDPOINT_DESCRIPTOR_STRUCT),                             //端点描述符的字节数大小
  ENDPOINT_DESCRIPTOR,                                            //端点描述符类型编号
  MAIN_POINT_OUT,                                                 //端点号，主输出端点
  ENDPOINT_TYPE_INTERRUPT,                                        //使用的传输类型：中断传输
  SWAP16(0x0040),                                                 //该端点支持的最大包尺寸，64字节
  0x0A                                                            //中断扫描时间：设置为10ms
 }
}
};

union                                          //程序标志位
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

union                                         //中断寄存器
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


union                                    //端点最后处理状态
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


/*****************   延时x毫秒函数 ***********/
void delay(uint16 x)                
{
 uint16 i;
 uint16 j;
 for(i=0;i<x;i++)
 for(j=0;j<230;j++);
}
/********************************************/

/*******************************写USB命令******************************************/
void write_usb_command(uint8 usb_command)
{
 USB_A0=USB_COMMAND_ADD;
 USB_DATA=usb_command;
 USB_WR=0;
 USB_WR=1;
 USB_DATA=0xFF;
}
/******************************************************************************/

/*********************写一字节USB数据*******************************************/
void write_a_usb_data(uint8 usb_data)       
{
 USB_A0=USB_DATA_ADD;
 USB_DATA=usb_data;
 USB_WR=0;
 USB_WR=1;
 USB_DATA=0XFF;
}
/******************************************************************************/

/****************************读一字节USB数据************************************/
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

/************************读USB中断寄存器**************************************/
void read_interrupt_register(void)
{
 write_usb_command(Read_Interrupt_Register);
 Interrupt_Register.Register[0]=read_a_usb_data();
 Interrupt_Register.Register[1]=read_a_usb_data();
}
/******************************************************************************/

/************************设置USB地址*******************************************/
void set_usb_addr(uint8 addr)
{
 write_usb_command(Set_Address);
 write_a_usb_data(0x80|addr);
 Prints("   设置地址.\r\n");
 Prints("       地址为：  ");
 PrintLongInt(addr);
 Prints("\r\n");
}
/******************************************************************************/

/*************************端点使能******************************************/
void set_endpoint_enable(void)
{
 write_usb_command(Set_Endpoint_Enable);
 write_a_usb_data(0x01);
}
/******************************************************************************/

/****************************选择终端点*************************************/
uint8 select_endpoint(uint8 endp)
{
 write_usb_command(Select_EndPoint+endp);
 return read_a_usb_data();
}
/******************************************************************************/

/****************************读端点最后状态**********************************/
uint8  read_last_status(uint8 endp)
{
 write_usb_command(Read_Last_Status+endp);
 return read_a_usb_data();
}
/******************************************************************************/

/****************************设置端点状态**************************************/
void set_endpoint_status(uint8 endp,uint8 status)  
{
 write_usb_command(0x40+endp);
 write_a_usb_data(!status);
}
/******************************************************************************/

/*****************************读端点状态**************************************/
uint8 read_endpoint_status(uint8 endp)
{
 write_usb_command(0x80+endp);
 return read_a_usb_data();
}
/******************************************************************************/

/************************清缓冲，在读取缓冲数据后调用**************************/
void clear_buffer(void)
{
 write_usb_command(Clear_Buffer);
#ifdef debug
 Prints("Clear buffer.\r\n");
#endif
}
/******************************************************************************/

/***********************缓冲区数据有效，在写缓冲后调用**************************/
void validate_buffer(void)
{
 write_usb_command(Validate_Buffer);
#ifdef debug
 Prints("Validate buffer.\r\n");
#endif
}
/******************************************************************************/

/***************************应答建立包************************************/
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

/***********************出错处理******************************************/
void error(uint8 number)
{
 Prints("有错误发生！！！\r\n");
 number=0;
}
/******************************************************************************/

/*************************读终端点缓冲****************************************/
uint8 read_endpoint_buff(uint8 endp,uint8 len,uint8 * buff)
{
 uint8 i,j;
 read_last_status(endp);
 if(!(select_endpoint(endp)&0x01)){error(0); return 0;}
 if((read_endpoint_status(endp)&0x60)!=0x60)  //两个缓冲没有都满，才能清中断
 {
  read_last_status(endp);  //清中断
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

/*************************写终端点缓冲*****************************************/
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

/***************************断开USB连接****************************************/
void disconnect_usb(void)
{
 Prints("断开USB连接.\r\n");
 write_usb_command(0xf3);
 write_a_usb_data(0x0e);
 write_a_usb_data(0x47);
 delay(100);
}
/******************************************************************************/

/*******************************连接USB**************************************/
void connect_usb(void)
{
 Prints("连接USB.\r\n");
 write_usb_command(0xf3);                         //初始化USBD12
 write_a_usb_data(0x1e);                          //连接USB
 write_a_usb_data(0x47);                          //设置频率
}
/******************************************************************************/

/***************************初始化USB***************************************************/
void init_usb(void)               
{
 Prints("USBD12芯片初始化\r\n");
 set_usb_addr(0);
 set_endpoint_enable();
}
/******************************************************************************/

/****************************USB总线复位处理***********************************/
void usb_bus_reset(void)
{
 Prints("USB总线复位.\r\n");
 usb_flags.Register=0;
 set_endpoint_enable();
}
/******************************************************************************/

/*****************************USB总线挂起处理**********************************/
void usb_bus_suspend(void)
{
 Prints("USB总线挂起.\r\n");
}
/******************************************************************************/

/***************************设置地址***************************************/
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

/**************************获取状态响应*****************************************/
void get_status(uint8 receiver)
{
 uint8 status[2];
 switch (receiver)
  {
   case 0:                        //获取设备状态
    status[0]=0x00;
    status[1]=0x00;
    break;
   case 1:                        //获取接口状态
    status[0]=0x00;
    status[0]=0x00;
    break;
   case 2:                        //获取端点状态
    status[0]=0x00;
    status[1]=0x00;
    break;
   }
  write_endpoint_buff(1,2,status);
  usb_flags.flags.usb_endp0_in=0;
}
/******************************************************************************/

/*********************清除特性*******************************************/
void clear_feature(uint8 receiver)    
{
 Prints("    清除特性.\r\n");
 receiver=0;
 write_endpoint_buff(1,0,0);
 usb_flags.flags.usb_endp0_in=0;
 usb_flags.flags.setup_packet_out=0;
}
/******************************************************************************/

/*******************设置特性**************************************************/
void set_feature(uint8 receiver)
{
 Prints("    设置特性.\r\n");
 receiver=0;
 write_endpoint_buff(1,0,0);
 usb_flags.flags.usb_endp0_in=0;
 usb_flags.flags.setup_packet_out=0;
}
/******************************************************************************/

/*****************************设置描述*****************************************/
void set_descriptor(void)
{
 Prints("    设置描述符.\r\n");
 usb_flags.flags.usb_endp0_in=0;
 usb_flags.flags.setup_packet_out=0;
}
/******************************************************************************/

/***************************设置配置*******************************************/
void set_configuration(void)
{
 Prints("    设置配置.\r\n");
 write_endpoint_buff(1,0,0);
 usb_flags.flags.usb_endp0_in=0;
 usb_flags.flags.setup_packet_out=0;
}
/******************************************************************************/

/************************获取配置状态******************************************/
void get_configuration(void)
{ 
 uint8 value=0x01;
 Prints("    获取配置.\r\n");
 write_endpoint_buff(1,1,&value);
 usb_flags.flags.usb_endp0_in=0;
}
/******************************************************************************/

/****************************设置接口************************************/
void set_interface(void)
{
 Prints("    设置接口.\r\n");
 write_endpoint_buff(1,0,0);
 usb_flags.flags.usb_endp0_in=0;
 usb_flags.flags.setup_packet_out=0;
}
/******************************************************************************/

/***************************获取接口状态***************************************/
void get_interface(void)
{
 uint8 value=0x01;
 Prints("    获取接口.\r\n");
 write_endpoint_buff(1,1,&value);
 usb_flags.flags.usb_endp0_in=0;
}
/******************************************************************************/

/***********************获取描述符*********************************************/
void get_descriptor(void)
{
 Prints("    获取描述符.\r\n");
  if(!usb_flags.flags.not_end)
     {
      switch(MSB(Control_Data.DeviceRequest.wValue))
	   {
        case DEVICE_DESCRIPTOR:
		     Prints("        获取设备描述符.\r\n");
	         Control_Data.wCount=sizeof(DEVICE_DESCRIPTOR_STRUCT);
 	         Control_Data.pData=(uint8 *)(&device_descriptor);
             break;
        case CONFIGURATION_DESCRIPTOR:
			 Prints("        获取配置描述符.\r\n");
             Control_Data.wCount=SWAP16(con_int_endp_descriptor.configuration_descriptor.wTotalLength);
			 Control_Data.pData=(uint8 *)(&con_int_endp_descriptor);
             if(Control_Data.wLength<Control_Data.wCount)Control_Data.wCount=Control_Data.wLength;
             break;
		case STRING_DESCRIPTOR:
		     Prints("        获取字符串描述符.\r\n");
			 switch(LSB(Control_Data.DeviceRequest.wValue))
			  {
			   case 0:
			    Prints("            获取语言ID.\r\n");
			    Control_Data.wCount=LANGUAGE_ID[0];
                Control_Data.pData=LANGUAGE_ID;
   			    break;

			   case 1:
			    Prints("            获取厂商字符串.\r\n");
			    Control_Data.wCount=ManufacturerString[0];
                Control_Data.pData=ManufacturerString;
			    break;

			   case 2:
			    Prints("            获取产品字符串.\r\n");
			    Control_Data.wCount=ProducterString[0];
                Control_Data.pData=ProducterString;
			    break;

			   case 3:
                 Prints("            获取设备序列号.\r\n");
			     Control_Data.wCount=device_serial_number[0];
			     Control_Data.pData=device_serial_number;
			   break;

			   default:
                 Prints("            其它描述符(未知).\r\n");
                 Prints("文件");
				 Prints(__FILE__);
				 Prints("\r\n");
				 Prints("行:");
				 Prints(__LINE__);
				 Prints("\r\n");
               break;
			  }
			 break;
		 default:
		     Prints("       获取其它描述符..................描述符索引为：");
			 PrintLongInt(MSB(Control_Data.DeviceRequest.wValue));
			 Prints("\r\n"); 
		  break;
	   	}
      if(Control_Data.wLength<Control_Data.wCount)Control_Data.wCount=Control_Data.wLength;
	 }
	//写数据到D12输入端点
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

/*********************发到接口的获取描述符**************************************/
void get_descriptor_interface(void)
{
 Prints("    获取描述符（从接口）.\r\n");
  if(!usb_flags.flags.not_end)
     {
      switch(MSB(Control_Data.DeviceRequest.wValue))
	   {
        case HID_DESCRIPTOR:
		     Prints("        获取HID描述符.\r\n");
	         Control_Data.wCount=sizeof(HID_DESCRIPTOR_STRUCT);
 	         //Control_Data.pData=(uint8 *)(&hid_descriptor);
             break;
        case REPORT_DESCRIPTOR:
			 Prints("        获取报告描述符.\r\n");
             Control_Data.wCount=sizeof(KeyBoardReportDescriptor);
			 Control_Data.pData=(uint8 *)(KeyBoardReportDescriptor);
             if(Control_Data.wLength<Control_Data.wCount)Control_Data.wCount=Control_Data.wLength;
             break;
		case PHYSICAL_DESCRIPTOR:
		     Prints("        获取物理描述符.\r\n");
			 break;
		 default:
		     Prints("       获取其它描述符..................描述符索引为：");
			 PrintLongInt(MSB(Control_Data.DeviceRequest.wValue));
			 Prints("\r\n"); 
		  break;
	   	}
      if(Control_Data.wLength<Control_Data.wCount)Control_Data.wCount=Control_Data.wLength;
	 }
	//写数据到D12输入端点
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

/************************终端点0输出中断处理************************************/
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

/***********************获取报告*********************************************/
void get_report(void)
{
 Prints("        获取报告.\r\n");
}
/******************************************************************************/

/**********************获取空闲状态*********************************************/
void get_idle(void)
{
 Prints("    获取空闲.\r\n");
 write_endpoint_buff(1,1,&idle);
 usb_flags.flags.usb_endp0_in=0;
}
/******************************************************************************/

/*************************获取协议**********************************************/
void get_protocol(void)
{
 Prints("    获取协议.\r\n");
 write_endpoint_buff(1,1,&protocol);
 usb_flags.flags.usb_endp0_in=0;
}
/******************************************************************************/

/***********************设置报告***********************************************/
void set_report(void)
{
 Prints("    设置报告.\r\n");
}
/******************************************************************************/

/***********************设置空闲***********************************************/
void set_idle(void)
{
 Prints("    设置空闲.\r\n");
 while(select_endpoint(1)&0x01);
 write_endpoint_buff(1,0,0);
 idle=Control_Data.DeviceRequest.wValue;
 usb_flags.flags.usb_endp0_in=0;
 usb_flags.flags.setup_packet_out=0;
}
/******************************************************************************/

/**********************设置协议**************************************************/
void set_protocol(void)
{
 Prints("    设置协议.\r\n");
 while(select_endpoint(1)&0x01);
 write_endpoint_buff(1,0,0);
 protocol=Control_Data.DeviceRequest.wValue;
 usb_flags.flags.usb_endp0_in=0;
 usb_flags.flags.setup_packet_out=0;
}
/******************************************************************************/

/****************************终端点0输入处理**************************************/
void endp0_in(void)
{
 read_last_status(1);
 //如果是输入请求包
 if(usb_flags.flags.setup_packet_in||usb_flags.flags.not_end)
  {
    switch(Control_Data.DeviceRequest.bmRequestType&0x60)
	 {
	   case 0x00:  //标准请求
	   Prints("USB标准请求.\r\n");
	   switch(Control_Data.DeviceRequest.bmRequestType&0x1F)
	    {
		 case 0: //到设备
		   switch (Control_Data.DeviceRequest.bRequest)
		    {
		     case 0: get_status(0);break;
		     case 6: get_descriptor();break;
		     case 8: get_configuration();break;
			 default:break;
		    }
		 break;

		 case 1:  //到接口
		   switch (Control_Data.DeviceRequest.bRequest)
		    {
	         case  0: get_status(1);break;
			  case 6: get_descriptor_interface();break;
		     case 10: get_interface();break;
	         default: break;
			}
		 break;

		 case 2:  //到端点
		  {
	       if(Control_Data.DeviceRequest.bRequest==0)get_status(2);  
		  }
		 default: break;
	    }
	   break;

	   case 0x20:  //类请求
       Prints("USB类请求.\r\n");
	   switch(Control_Data.DeviceRequest.bmRequestType&0x1F)
	    {
		 case 0:  //到设备
		   switch (Control_Data.DeviceRequest.bRequest)
		    {
			 default:break;
		    }
		 break;

		 case 1:  //到接口
		   switch (Control_Data.DeviceRequest.bRequest)
		    {

	  		 case   GET_REPORT: get_report();   break; //获取报告
             case     GET_IDLE: get_idle();     break; //获取空闲状态
             case GET_PROTOCOL: get_protocol(); break; //获取协议
	         default: break;
			}
		 break;

		 case 2:  //到端点
		  {
		   switch (Control_Data.DeviceRequest.bRequest)
		    {
	         default: break;
			}  
		  }
		 default: break;
	    }
	   break;

	   case 0x40:  //用户请求
       Prints("USB用户请求.\r\n");
	   switch(Control_Data.DeviceRequest.bmRequestType&0x1F)
	    {
		 case 0:  //到设备
		   switch (Control_Data.DeviceRequest.bRequest)
		    {
			 default: break;
		    }
	     break;

		 case 1:   //到接口
		   switch (Control_Data.DeviceRequest.bRequest)
		    {
	         default: break;
			}
         break;

		 case 2:  //到端点
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

  //如果是输出请求包
 if(usb_flags.flags.setup_packet_out) 
  {
    switch(Control_Data.DeviceRequest.bmRequestType&0x60)
	 {
	   case 0x00:  //标准请求
	   Prints("USB标准请求.\r\n");
	   switch(Control_Data.DeviceRequest.bmRequestType&0x1F)
	    {
		 case 0:   //到设备
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
		 
		 case 1:   //到接口
	      switch (Control_Data.DeviceRequest.bRequest)
		   {
		    case CLEAR_FEATURE:  clear_feature(1);break;
		    case   SET_FEATURE:  set_feature(1); break;
	        case SET_INTERFACE: set_interface();break;
		    default: break;
	        }
		 break;
		 
		 case 2:   //到端点
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

	  case 0x20:  //类请求
      Prints("USB类请求.\r\n");
	   switch(Control_Data.DeviceRequest.bmRequestType&0x1F)
	    {
		 case 0:    //接收者为设备
	     switch (Control_Data.DeviceRequest.bRequest)
	      {             	          
	  	   default: break;
		  }
		 break;

		 case 1:   //接收者为接口
	      switch (Control_Data.DeviceRequest.bRequest)
		   {
            case   SET_REPORT: set_report();   break; //设置报告
            case     SET_IDLE: set_idle();     break; //设置空闲
            case SET_PROTOCOL: set_protocol(); break; //设置协议
		    default: break;
	        }
		 
		 break;

		 case 2:   //接收者为端点
		  switch (Control_Data.DeviceRequest.bRequest)
		   {
	        default: break;      
		   }
		 break;
		 
		 case 3: //其它接收者
		  switch (Control_Data.DeviceRequest.bRequest)
		   {
	        default: break;      
		   }break;
		   		  
		 default: break;
	    }      
	   break;

       case 0x40:  //用户请求
	   Prints("USB用户请求.\r\n");
	   switch(Control_Data.DeviceRequest.bmRequestType&0x1F)
	    {
		 case 0:    //接收者为设备
	     switch (Control_Data.DeviceRequest.bRequest)
	      {             	          
	  	   default: break;
		  }
		 break;
		 
		 case 1:   //接收者为接口
	      switch (Control_Data.DeviceRequest.bRequest)
		   {
		    default: break;
	        }
	     break;
		 
		 case 2:   //接收者为端点
		  switch (Control_Data.DeviceRequest.bRequest)
		   {
	        default: break;      
		   }
		 break;
		 
		 case 3: //其它接收者
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

/**********************端点1输出***********************************************/
/*void endp1_out(void)
{
 Prints("端点1输出.\r\n");
}*/
/******************************************************************************/

/*************************端点1输入*****************************************/
/*void endp1_in(void)
{
 Prints("端点1输入.\r\n");
}*/
/******************************************************************************/

/***************************端点2输出****************************************/
void endp2_out(void)
{
 uint8 i,j;

 j=read_endpoint_buff(4,64,buffer);
 LEDs=~buffer[0];
 Prints("端点2输出.\r\n");
 Prints("    端点2的数据是  ");
 for(i=0;i<j;i++)
  {
   PrintHex(buffer[i]);
   if(i==16)Prints("\r\n");
  }
 Prints("\r\n");
}
/******************************************************************************/


//用来返回数据的缓冲
uint8 idata InBuffer[64];

/****************************主端点输入处理************************************/
void endp2_in(void)                                      
{
 uint8 i;
// Prints("端点2输入.\r\n");
	i=keyscan();
 if(i) //如果有按键按下
  {
   if(i==1) //左Ctrl键
    {
     InBuffer[0] |=1;
    }
   else
    {
     InBuffer[0]&=~1;
    }	
   if(i==2) //左shift键
    {
     InBuffer[0]|=1<<1;
    }
   else
    {
     InBuffer[0]&=~(1<<1);
    }
	
   if(i==3) //左ALT键
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
     InBuffer[i++]=0x62;	    //0键
    }
   if(i==5)
    {
	 InBuffer[i++]=0x59;	    //1键
	}
   if(i==6)
    {
     InBuffer[i++]=0x5A;	    //2键
    }
   if(i==7)
    {
     InBuffer[i++]=0x39;	    //Caps Lock键
    }
   if(i==8)
    {
     InBuffer[i++]=0x53;	    //Num Lock键
    }
   for(;i<8;i++)
   {
    InBuffer[i]=0;  //多余的清0
   }
  }
 else //如果无按键按下，则返回0
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
"******                 EDN USB学习板键盘程序                  ******\r\n",
"******                      AT89S52 CPU                       ******\r\n",
"******                  建立日期：",__DATE__,"                 ******\r\n",
"******                   建立时间：",__TIME__,"                   ******\r\n",
"******                    作者：电脑圈圈                      ******\r\n",
"******                    欢迎访问作者的                      ******\r\n",
"******           USB专区：http://group.ednchina.com/93/       ******\r\n",
"******      BLOG1：http://www.ednchina.com/blog/computer00    ******\r\n",
"******                BLOG2：http://computer00.21ic.org       ******\r\n",
"******                  请按K1-K8分别进行测试                 ******\r\n",
"******       K1:左Ctrl键  K2:左Shift键  K3:左Alt键  K4:0键    ******\r\n",
"******       K5:1键  K6:2键  K7:Caps Lock键 K8:Num Lock键     ******\r\n",
"********************************************************************\r\n",
};



/***************************主函数**********************************************/
void main(void)
{
 uint8 i;
 InitUART();  //串口初始化
 Printc(0x0c);  //清屏
 Printc(0x0c);
 Prints("系统启动.\r\n");
 for(i=0;i<18;i++)	  //显示信息
 {
  Prints(HeadTable[i]);
 } 
 disconnect_usb(); 	   //断开USB连接
 delay(1000);	       //延迟
 init_usb();		   //初始化USB芯片
 connect_usb();		   //连接USB


 while(1)
  { 
   if(!USB_INT)		//中断产生
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
