#ifndef __D12_USB_H_REVISION_FIRST__
#define __D12_USB_H_REVISION_FIRST__
#include <msp430x14x.H>

#define DataOut P2OUT
#define DataIn  P2IN
#define DataDir P2DIR

#define ALE_usb_0     P5OUT&=~0x02
#define ALE_usb_1     P5OUT|=0x02
#define CS_usb_0      P5OUT&=~0x04
#define CS_usb_1      P5OUT|=0x04
#define SUSP_usb_0    P5OUT&=~0x08
#define SUSP_usb_1    P5OUT|=0x08
#define RST_usb_0     P5OUT&=~0x01
#define RST_usb_1     P5OUT|=0x01
#define WR_usb_0      P6OUT&=~0x80
#define WR_usb_1      P6OUT|=0x80
#define RD_usb_0      P6OUT&=~0x40
#define RD_usb_1      P6OUT|=0x40
#define INT_usb       (P1IN&0x10)



#define D12_INT_ENDP0OUT      0x0001   //�жϼĴ���λ����
#define D12_INT_ENDP0IN       0x0002
#define D12_INT_ENDP1OUT      0x0004
#define D12_INT_ENDP1IN       0x0008
#define D12_INT_ENDP2OUT      0x0010
#define D12_INT_ENDP2IN       0x0020
#define D12_INT_BUSRESET      0x0040
#define D12_INT_SUSPENDCHANGE 0x0080
#define D12_INT_EOT           0x0100

#define D12_SETUPPACKET                     0x20  //�������״̬�Ĵ�����������Ϣ��0010,0000b
#define EP0_PACKET_SIZE                     16    //p0���16byte
#define USB_ENDPOINT_DIRECTION_MASK         0x80  //�豸��������,���䷽�� D7 1000,0000b
#define USB_REQUEST_TYPE_MASK               0x30  //bmRequest������
#define USB_REQUEST_MASK                    0x0f
#define USB_STANDARD_REQUEST                0x00  //5,6λ�Ķ���
#define USB_VENDOR_REQUEST                  0x20
#define USB_DEVICE_DESCRIPTOR_TYPE          0x01  //���������� �豸������01h,����������02,�ӿ�������04,�˵�������05
#define USB_CONFIGURATION_DESCRIPTOR_TYPE   0x02
#define CONFIG_DESCRIPTOR_LENGTH            0x002E//�����������ܳ���

//**************************************************************************
//Port And Macros And Structure And Union Definitions
#define SWAP(x)   ((((x) & 0x00FF) << 8) | (((x) >> 8) & 0x00FF)) //�����ߵ�8λ
#define MSB(x)    (((x) >> 8) & 0x00FF)        //ȡ���ݸ�8λ
#define LSB(x)    ((x) & 0x00FF)         //ȡ���ݵ�8λ

typedef union _Event_Flags_       //����USB�¼���־��������
{
    struct _Bit_Flags_
    {
        unsigned char Timer         : 1; //��ʱ������¼����
        unsigned char BusReset      : 1; //USB���߸�λ��־
        unsigned char Suspend       : 1; //USB���������־
        unsigned char SetupPacket   : 1; //�յ�SETUP����־
        unsigned char RemoteWakeup  : 1; //Զ�̻��ѱ�־
        unsigned char InISR         : 1; //USB�жϷ����־
        unsigned char ControlState  : 2; //���ƶ˵㴦��״̬
        //0:IDEL     ����״̬
        //1:TRANSMIT ���ݷ���״̬
        //2:RECEIVE ���ݽ���״̬
        unsigned char Configuration   : 1; //���ñ�־ (0:δ����;1:������)
        unsigned char Port1RxDone   : 1; //�˿�1�յ����ݱ�־
        unsigned char Port2RxDone   : 1; //�˿�2�յ����ݱ�־
        unsigned char Port1TxFull        : 1; //�˿�1�������������־
        unsigned char Port2TxFull   : 1; //�˿�2�������������־

        unsigned char Reserve    : 3; //����,δʹ��
    }Bits;
    unsigned short int Value;
}EVENT_FLAGS;          //�¼���־��������

typedef struct _DEVICE_REQUEST_
{
    unsigned char bmRequestType;     //��������
    unsigned char bRequest;       //USB����
    unsigned short wValue;       //USB����ֵ
    unsigned short wIndex;       //USB��������
    unsigned short wLength;       //��������
}DEVICE_REQUEST;

#define MAX_CONTROLDATA_SIZE 8
typedef struct _control_xfer
{
    DEVICE_REQUEST DeviceRequest;     //USB����ṹ��
    unsigned short wLength;       //�������ݵ����ֽ���
    unsigned short wCount;       //�����ֽ���ͳ��
    unsigned char * pData;       //��������ָ��
    unsigned char dataBuffer[MAX_CONTROLDATA_SIZE]; //���������
}CONTROL_XFER;

static EVENT_FLAGS EventFlags;   //����Ϊȫ�ֱ���,�������������ͨ��
static CONTROL_XFER ControlData; //����SETUP���������ͺ���������
unsigned char EndPoint1Buffer[4]; //���ƶ˵㻺��
unsigned char EndPoint2Buffer[64];//���˵㻺��
//**************************************************************************
/////////////////kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk




void init_port(void)
{
  P2DIR=0xff;
  P2OUT=0x00;
  P5DIR|=0x0f;
  P5OUT=0x00;
  P6DIR|=0xc0;
  ALE_usb_0;
  WR_usb_1;
  RD_usb_1;
  CS_usb_0;
  _NOP();
}
////////////////kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk



//Ӳ����ȡ��,��·��ַ/�������߷�ʽ��д
void Outportb0(unsigned int addr)
{
    init_port();
    DataOut=addr;
    _NOP();
    ALE_usb_1;
    _NOP();
    ALE_usb_0;
    _NOP();
    ALE_usb_1;
//*((unsigned char xdata *) Addr) = Data;
}

void Outportb1(unsigned int addr, unsigned char dat)
{
    init_port();
    DataOut=addr;
    _NOP();
    ALE_usb_1;
    _NOP();
    ALE_usb_0;
    _NOP();
    DataOut=dat;
    WR_usb_0;
    _NOP();
    WR_usb_1;
    ALE_usb_1;
//*((unsigned char xdata *) Addr) = Data;
    
}
void Outportb2(unsigned int addr, unsigned char dat1,unsigned char dat2)
{
    init_port();
    DataOut=addr;
    _NOP();
    ALE_usb_1;
    _NOP();
    ALE_usb_0;
    _NOP();
    DataOut=dat1;
    WR_usb_0;
    _NOP();
    WR_usb_1;
    _NOP();
    DataOut=dat2;
    WR_usb_0;
    _NOP();
    WR_usb_1;
    ALE_usb_1;
//*((unsigned char xdata *) Addr) = Data;
    
}
void Inportb1(unsigned int addr,unsigned char *d)
{
//return *((unsigned char xdata *) Addr);
  unsigned char itsdata;
  init_port();
  DataOut=addr;
  _NOP();
  ALE_usb_1;
  _NOP();
  ALE_usb_0;
  DataDir=0x00;
  DataOut=0xff;
  RD_usb_0;
  _NOP();
  RD_usb_1;
  itsdata=DataIn;
  ALE_usb_1;
  DataDir=0xff;
  *d=itsdata;    
}
void Inportb2(unsigned int addr,unsigned char *d1,unsigned char *d2)
{
//return *((unsigned char xdata *) Addr);
  init_port();
  DataOut=addr;
  _NOP();
  ALE_usb_1;
  _NOP();
  ALE_usb_0;
  DataDir=0x00;
  DataOut=0xff;
  RD_usb_0;
  _NOP();
  RD_usb_1;
  *d1=DataIn;
  _NOP();
  RD_usb_0;
  _NOP();
  RD_usb_1;
  *d2=DataIn;  
  ALE_usb_1;
  DataDir=0xff;
}
void USB_Delay1ms(unsigned int count)
{
    unsigned int i,j;
    for(i=0;i<count;i++)
    for(j=0;j<120;j++);
}
//**************************************************************************
#define D12_DATA    0
#define D12_COMMAND 1
//PDIUSBD12����ӿں���
void D12_SetMode(unsigned char bConfig,unsigned char bClkDiv)
{
    Outportb2(0xF3,bConfig,bClkDiv);
}
//���ö˵�
void D12_SetEndpointStatus(unsigned char bEndp,unsigned char bStalled)
{
    Outportb1(0x40+bEndp,bStalled);
}
//Ӧ��!!!!!
void D12_AcknowledgeEndpoint(unsigned char endp)
{
    Outportb0(endp);
    Outportb0(0xF1);
    if(endp==0)
    {
        Outportb0(0xF2);
    }
}
//���õ�ַʹ��
void D12_SetAddressEnable(unsigned char bAddress,unsigned char bEnable)
{
    if(bEnable)
    {
        bAddress |= 0x80;
    }
    Outportb1(0xd0,bAddress);
}
//���ö˵�ʹ��
void D12_SetEndpointEnable(unsigned char bEnable)
{

    if(bEnable)
    {
        Outportb1(0xD8,1);
    }
    else
    {
        Outportb1(0xD8,0);
    }
}
//���жϼĴ���
unsigned short D12_ReadInterruptRegister(void)
{
    unsigned char b1,j1;
    unsigned int j;
    Inportb2(0xF4,&b1,&j1);
    j=j1<<8;
    j+=b1;
    return j;
}
//��ȡ�˵�״̬
unsigned char D12_ReadEndpointStatus(unsigned char EndPoint) 
{
    unsigned char BackValue;

    if(EventFlags.Bits.InISR == 0)
    {
    _DINT();
    }

    Inportb1(0x80 + EndPoint,&BackValue);
    if(EventFlags.Bits.InISR == 0)
    {
        _EINT();
    }

    return BackValue;
}
//���˵������״̬
unsigned char D12_ReadLastTransactionStatus(unsigned char bEndp)
{
    unsigned char i;
    Inportb1(0x40+bEndp,&i);
    return i;
}
//���˿�
unsigned char D12_ReadEndpoint(unsigned char endp,unsigned char len,unsigned char *buf)
{
    unsigned char i,j;
    Inportb1(endp,&i);
    if((i&0xff)==0)//" define D12_FULLEMPTY as 0xFF by newer
    {
        return 0;
    }
    Inportb1(0x80+endp,&i);
    i=i&0x60;
    Inportb2(0xF0,&j,&j);
    if(j>len)
    {
        j=len;
    }
    for(i=0;i<j;i++)
    {
        _NOP();
        RD_usb_0;
        _NOP();
        RD_usb_1;
        *(buf+i)=DataIn;         
    }

    Outportb0(0xF2);
    return j;
}

unsigned char D12_ReadEndpoint_Int(unsigned char endp,unsigned char len,unsigned char *buf)
{
    unsigned char i,j;
    Inportb1(endp,&i);
    if((i&0xff)==0)//" define D12_FULLEMPTY as 0xFF by newer
    {
        return 0;
    }
    Inportb1(0x80+endp,&i);
    i=i&0x60;

//    Inportb2(0xF0,&j,&j);
  
  DataOut=0xf0;
  _NOP();
  ALE_usb_1;
  _NOP();
  ALE_usb_0;
  DataDir=0x00;
  DataOut=0xff;
  RD_usb_0;
  _NOP();
  RD_usb_1;
  j=DataIn;
  _NOP();
  RD_usb_0;
  _NOP();
  RD_usb_1;
  j=DataIn;  

    if(j>len)
    {
        j=len;
    }
    for(i=0;i<j;i++)
    {
 //       *(buf+i)=Inportb(D12_DATA);
        _NOP();
  RD_usb_0;
  _NOP();
  RD_usb_1;
      *(buf+i)=DataIn;
    }
    Outportb0(0xF2);
    return j;
}

unsigned char D12_WriteEndpoint(unsigned char endp,unsigned char len,unsigned char * buf)
{
    unsigned char i;

    Inportb1(endp,&i);
//  Outportb2(0xF0,0,len);
    init_port();
    DataOut=0xf0;
    _NOP();
    ALE_usb_1;
    _NOP();
    ALE_usb_0;
    _NOP();
    DataOut=0;
    WR_usb_0;
    _NOP();
    WR_usb_1;
    _NOP();
    DataOut=len;
    WR_usb_0;
    _NOP();
    WR_usb_1;

    for(i=0;i<len;i++)
    {
//        Outportb(D12_DATA,*(buf+i));
      DataOut=*(buf+i);
      WR_usb_0;
      _NOP();
      WR_usb_1;
    }
    Outportb0(0xFA);
    return len;
}

unsigned char D12_WriteEndpoint_Int(unsigned char endp,unsigned char len,unsigned char * buf)
{
    unsigned char i;
    
    Inportb1(endp,&i);
    init_port();
    DataOut=0xf0;
    _NOP();
    ALE_usb_1;
    _NOP();
    ALE_usb_0;
    _NOP();
    DataOut=0;
    WR_usb_0;
    _NOP();
    WR_usb_1;
    _NOP();
    DataOut=len;
    WR_usb_0;
    _NOP();
    WR_usb_1;

    for(i=0;i<len;i++)
    {
//        Outportb(D12_DATA,*(buf+i));
      DataOut=*(buf+i);
      WR_usb_0;
      _NOP();
      WR_usb_1;
    }
    
    Outportb0(0xFA);
    return len;
}

void DisconnectUSB(void)
{
D12_SetMode(0x02,0x03);//SET TO ONE? by newer
}

void InitialUSBInt(void);
void ConnectUSB(void)
{
    EventFlags.Value = 0x0000;
    InitialUSBInt();
    D12_SetMode(0x16,0x03);
}

void ReconnectUSB(void)
{
    SUSP_usb_0;
    DisconnectUSB();
    USB_Delay1ms(1000);
    ConnectUSB();
}

//**************************************************************************
//�жϷ������
void InitialUSBInt(void)
{
    P1IE|=0x10;
    P1IES|=0x10;
    P1IFG&=~0x10;
    _EINT();
}

void EP0_Out(void)
{
    unsigned char ep_last,i;
    ep_last=D12_ReadLastTransactionStatus(0);//interrupt symbol
    if(ep_last&D12_SETUPPACKET)
    { //recieved SETUP packet ---by newer
        ControlData.wLength=0;
        ControlData.wCount=0;
        if(D12_ReadEndpoint_Int(0,sizeof(ControlData.DeviceRequest),(unsigned char *)(&(ControlData.DeviceRequest)))!=sizeof(DEVICE_REQUEST))
        {
            D12_SetEndpointStatus(0,1);
            D12_SetEndpointStatus(1,1);
            EventFlags.Bits.ControlState=0; //should define USB_IDLE first --by newer
            return;
        }
    
        ControlData.DeviceRequest.wValue=SWAP(ControlData.DeviceRequest.wValue);
        ControlData.DeviceRequest.wIndex=SWAP(ControlData.DeviceRequest.wIndex);
        ControlData.DeviceRequest.wLength=SWAP(ControlData.DeviceRequest.wLength);
         
        D12_AcknowledgeEndpoint(0);
        D12_AcknowledgeEndpoint(1);
        ControlData.wLength=ControlData.DeviceRequest.wLength;
        ControlData.wCount=0;
        if(ControlData.DeviceRequest.bmRequestType&(unsigned char)USB_ENDPOINT_DIRECTION_MASK)
        {
            EventFlags.Bits.SetupPacket=1; //recv from host? --by newer
            EventFlags.Bits.ControlState=1; //by newer
        }
        else
        {
            if(ControlData.DeviceRequest.wLength==0)
            {
                EventFlags.Bits.SetupPacket=1;
                EventFlags.Bits.ControlState=0; //by newer
            }
            else
            {
                if(ControlData.DeviceRequest.wLength>16)//���16byte
                {
                    EventFlags.Bits.ControlState=0; //by newer
                    D12_SetEndpointStatus(0,1);
                    D12_SetEndpointStatus(1,1);
                }
                else
                {
                    EventFlags.Bits.ControlState=2;//by newer                
                }
            }
        }
    }
    else if(EventFlags.Bits.ControlState==2)
    {
        i=D12_ReadEndpoint_Int(0,EP0_PACKET_SIZE,ControlData.dataBuffer+ControlData.wCount);
        ControlData.wCount+=i;
        if(i!=EP0_PACKET_SIZE||ControlData.wCount>=ControlData.wLength)
        {
           EventFlags.Bits.SetupPacket=1;
           EventFlags.Bits.ControlState=0;
        }
    }
    else
    {
        EventFlags.Bits.ControlState=0;
    }
}

void EP0_In(void)
{
    short i=ControlData.wLength-ControlData.wCount;
    D12_ReadLastTransactionStatus(1);
    if(EventFlags.Bits.ControlState!=1) 
    {
        return;
    }  
    if(i>=EP0_PACKET_SIZE)
    {
        D12_WriteEndpoint_Int(1,EP0_PACKET_SIZE,ControlData.pData+ControlData.wCount);
        ControlData.wCount+=EP0_PACKET_SIZE;
        EventFlags.Bits.ControlState=1;
        return;
    }
    if(i!=0)
    {
        D12_WriteEndpoint_Int(1,i,ControlData.pData+ControlData.wCount);
        ControlData.wCount+=i;
        EventFlags.Bits.ControlState=0;
        return;
    }
    D12_WriteEndpoint_Int(1,0,0);
    EventFlags.Bits.ControlState=0;
}
void EP1_Out(void)
{
    unsigned char Length;
    D12_ReadLastTransactionStatus(2); /* Clear interrupt flag */
    Length = D12_ReadEndpoint_Int(2, sizeof(EndPoint1Buffer),EndPoint1Buffer);
    if(Length != 0)
    EventFlags.Bits.Port1RxDone = 1;
}

void EP1_In(void)
{
    D12_ReadLastTransactionStatus(3);
}

void EP2_Out(void)
{
    unsigned char Length,EP2Status;
    D12_ReadLastTransactionStatus(4); /* Clear interrupt flag */
    
    EP2Status = D12_ReadEndpointStatus(4);
    EP2Status&=0x60;
    Length = D12_ReadEndpoint(4,sizeof(EndPoint2Buffer),EndPoint2Buffer);
    if(EP2Status==0x60)
    {
        Length = D12_ReadEndpoint(
                                  4,
                                  sizeof(EndPoint2Buffer),
                                  EndPoint2Buffer);
    }
    if(Length != 0)
    {
        EventFlags.Bits.Port2RxDone = 1;
    }
}

void EP2_In(void)
{
    D12_ReadLastTransactionStatus(5); /* Clear interrupt flag */
}
//**************************************************************************
//������
typedef struct _usb_device_descriptor
{
unsigned char bLength;
unsigned char bDescriptorType;
unsigned int bcdUSB;
unsigned char bDeviceClass;
unsigned char bDeviceSubClass;
unsigned char bDeviceProtocol;
unsigned char bMaxPacketSize0;
unsigned int idVendor;
unsigned int idProduct;
unsigned int bcdDevice;
unsigned char iManufacturer;
unsigned char iProduct;
unsigned char iSerialNumber;
unsigned char bNumConfiguations;
}USB_DEVICE_DESCRIPTOR;

USB_DEVICE_DESCRIPTOR DeviceDescr=
{
sizeof(USB_DEVICE_DESCRIPTOR),
    0x01,//USB_DEVICE_DESCRIPTOR_TYPE,
    SWAP(0x0100),
    0xDC,//USB_CLASS_CODE_TEST_CLASS_DEVICE,
    0, 0,
EP0_PACKET_SIZE,
SWAP(0x0471),
SWAP(0x0666),
SWAP(0x0100),
    0, 0, 0,
25
};
//����������
typedef struct _usb_configuration_descriptor
{
    unsigned char bLength[0x2e];
}USB_CONFIGURATION_DESCRIPTOR;

const USB_CONFIGURATION_DESCRIPTOR ConfigDescr=
{
0x09,0x02,0x2e,0x00,0x01,0x01,0x00,0xa0,0x32,
0x09,0x04,0x00,0x00,0x04,0xdc,0xa0,0xb0,0x00,
0x07,0x05,0x81,0x03,0x02,0x00,0x0a,
0x07,0x05,0x01,0x03,0x02,0x00,0x0a,
0x07,0x05,0x82,0x02,0x40,0x00,0x0a,
0x07,0x05,0x02,0x02,0x40,0x00,0x0a
};
//code_tramsit
void code_transmit(unsigned char *pRomData,unsigned short len)
{
    ControlData.wCount=0;
    if(ControlData.wLength>len)
    {
        ControlData.wLength=len;
        ControlData.pData=pRomData;
        if(ControlData.wLength>=EP0_PACKET_SIZE)
        {
            D12_WriteEndpoint(1,EP0_PACKET_SIZE,ControlData.pData);
            ControlData.wCount+=EP0_PACKET_SIZE;
            _DINT();
            EventFlags.Bits.ControlState=1;
            _EINT();
        }
        else
        {
            D12_WriteEndpoint(1,ControlData.wLength,pRomData);
            ControlData.wCount+=ControlData.wLength;
            _DINT();
            EventFlags.Bits.ControlState=0;
            _EINT();
        }
    }
}
//��ȡ������
void get_descriptor(void)
{
if(MSB(ControlData.DeviceRequest.wValue)==USB_DEVICE_DESCRIPTOR_TYPE)
{
code_transmit((unsigned char *)&DeviceDescr,sizeof(USB_DEVICE_DESCRIPTOR));
return;
}
if(MSB(ControlData.DeviceRequest.wValue)==USB_CONFIGURATION_DESCRIPTOR_TYPE)
{ 
if(ControlData.DeviceRequest.wLength>CONFIG_DESCRIPTOR_LENGTH)
{
   ControlData.DeviceRequest.wLength=CONFIG_DESCRIPTOR_LENGTH;
   //��ʶ���ܴ�С2E byte,�ڶ�������ʱwlength=0x00ff
}
//�����ConfigDescr��ʵӦ�ð���������ʶ��!
code_transmit((unsigned char *)&ConfigDescr,ControlData.DeviceRequest.wLength);
return;
}
}
//single transmit
void single_transmit(unsigned char *buf,unsigned char len)
{
if(len<=EP0_PACKET_SIZE)
{
D12_WriteEndpoint(1,len,buf);
}
}
//���õ�ַ
void set_address(void)
{
D12_SetAddressEnable((unsigned char)(ControlData.DeviceRequest.wValue&0xff),1);
//����wValue��"02 00" Ӧ�õõ�02
single_transmit(0,0);
}

//��������
void set_configuration(void)
{
if(ControlData.DeviceRequest.wValue==0)
{
single_transmit(0,0);
EventFlags.Bits.Configuration=0;
D12_SetEndpointEnable(0);
}
else if(ControlData.DeviceRequest.wValue==1)
{
single_transmit(0,0);
D12_SetEndpointEnable(0);
D12_SetEndpointEnable(1);
EventFlags.Bits.Configuration=1;
}
}
//��ȡ����
void get_configuration(void)
{
unsigned char c=EventFlags.Bits.Configuration; 
single_transmit(&c,1);
}
//��ȡ�豸�ӿ���Ϣ
void get_interface(void)
{
unsigned char txdat=0;
single_transmit(&txdat,1);
}

static void (*StandardDeviceRequest[])(void)=
{ 
0,0,0,0,
   0,set_address,get_descriptor,0,
   get_configuration,set_configuration,get_interface,0,
   0,0,0,0
};

static void (*VendorDeviceRequest[])(void)=
{ 
0,0,0,0,
   0,0,0,0,
   0,0,0,0,
   0,0,0,0
};

void ControlHandler(void)
{
unsigned char type,req;
type=ControlData.DeviceRequest.bmRequestType&USB_REQUEST_TYPE_MASK;//0011,0000b
req=ControlData.DeviceRequest.bRequest&USB_REQUEST_MASK;//0000,1111b
if(type==USB_STANDARD_REQUEST)
(*StandardDeviceRequest[req])();
else if(type==USB_VENDOR_REQUEST)
(*VendorDeviceRequest[req])();
}


//**************************************************************************

#endif
