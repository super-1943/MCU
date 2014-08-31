#ifndef _kkk_usb_h
#define _kkk_usb_h

code uint8 DeviceDescriptor[18]=
{

0x12,//bLength,����18�ֽ�
0x01,//bDescriptorType,�豸������
0x10,0x01,//bcdUSB��usb1.1
0x00,//bDeviceClass��һ��Ϊ0
0x00,//bDeviceSubClass,һ��Ϊ0
0x00,//bDevicePortocol���豸Э��
0x10,//bMaxPacketSize0���˵�0��������������16�ֽ�

0x88,0x88,//VID
0x02,0x00,//PID
0x00,0x01,//�豸�汾��
0x01,
0x02,
0x03,
0x01,
};

code uint8 LanguageId[4]=
{
0x04,//length
0x03,//string descriptor
0x09,//0x0409:America
0x04
};
/**************************************************/
/*********        ��ת���������         **********/
/********* Http://computer00.21ic.org    **********/
/*********        ����: ����ȦȦ         **********/
/*********         ��ӭ���ʹ��          **********/
/*********    ��Ȩ���У�������д������   **********/
/**************************************************/

//http://computer00.21ic.org/user1/2198/archives/2007/42769.html
//�ַ�����������ͬ־˼�����������������ͬ������й�������������Unicode����
//8λС�˸�ʽ
code uint8 ManufacturerStringDescriptor[52]={
52,         //���������ĳ���Ϊ52�ֽ�
0x03,       //�ַ��������������ͱ���Ϊ0x03
0x75, 0x8d, //��
0x38, 0x6c, //��
0xd1, 0x79, //��
0x0c, 0x54, //ͬ
0xd7, 0x5f, //־
0x1d, 0x60, //˼
0xf3, 0x60, //��
0xef, 0x7a, //��
0x63, 0x6b, //��
0x0c, 0xff, //��
0x31, 0x72, //��
0xfd, 0x56, //��
0x31, 0x72, //��
0x5a, 0x51, //��
0x0c, 0xff, //��
0x0c, 0x54, //ͬ
0x0f, 0x61, //��
0xa0, 0x52, //��
0x65, 0x51, //��
0x2d, 0x4e, //��
0xfd, 0x56, //��
0x71, 0x51, //��
0xa7, 0x4e, //��
0x5a, 0x51, //��
0x02, 0x30 //��
//ע���뽫���һ������Ķ���ɾ��
};
/**************************************************/
/*********        ��ת���������         **********/
/********* Http://computer00.21ic.org    **********/
/*********        ����: ����ȦȦ         **********/
/*********         ��ӭ���ʹ��          **********/
/*********    ��Ȩ���У�������д������   **********/
/**************************************************/

//http://computer00.21ic.org/user1/2198/archives/2007/42769.html
//�ַ���������ȦȦ��usb������ţ�ơ���Unicode����
//8λС�˸�ʽ
code uint8 ProductStringDescriptor[28]={
28,         //���������ĳ���Ϊ28�ֽ�
0x03,       //�ַ��������������ͱ���Ϊ0x03
0x35, 0x75, //��
0x11, 0x81, //��
0x08, 0x57, //Ȧ
0x08, 0x57, //Ȧ
0x84, 0x76, //��
0x75, 0x00, //u
0x73, 0x00, //s
0x62, 0x00, //b
0x1f, 0x77, //��
0xd6, 0x4e, //��
0x88, 0x59, //��
0x5b, 0x72, //ţ
0x3c, 0x90 //��
//ע���뽫���һ������Ķ���ɾ��
};
/**************************************************/
/*********        ��ת���������         **********/
/********* Http://computer00.21ic.org    **********/
/*********        ����: ����ȦȦ         **********/
/*********         ��ӭ���ʹ��          **********/
/*********    ��Ȩ���У�������д������   **********/
/**************************************************/

//http://computer00.21ic.org/user1/2198/archives/2007/42769.html
//�ַ�����2009-12-19����Unicode����
//8λС�˸�ʽ
code uint8 SerialNumberStringDescriptor[22]={
22,         //���������ĳ���Ϊ22�ֽ�
0x03,       //�ַ��������������ͱ���Ϊ0x03
0x32, 0x00, //2
0x30, 0x00, //0
0x30, 0x00, //0
0x39, 0x00, //9
0x2d, 0x00, //-
0x31, 0x00, //1
0x32, 0x00, //2
0x2d, 0x00, //-
0x31, 0x00, //1
0x39, 0x00 //9
//ע���뽫���һ������Ķ���ɾ��
};


code uint8 ReportDescriptor[63] = {
    0x05, 0x01,                    // USAGE_PAGE (Generic Desktop)
    0x09, 0x06,                    // USAGE (Keyboard)
    0xa1, 0x01,                    // COLLECTION (Application)
    0x05, 0x07,                    //   USAGE_PAGE (Keyboard)
    0x19, 0xe0,                    //   USAGE_MINIMUM (Keyboard LeftControl)
    0x29, 0xe7,                    //   USAGE_MAXIMUM (Keyboard Right GUI)
    0x15, 0x00,                    //   LOGICAL_MINIMUM (0)
    0x25, 0x01,                    //   LOGICAL_MAXIMUM (1)
    0x75, 0x01,                    //   REPORT_SIZE (1)
    0x95, 0x08,                    //   REPORT_COUNT (8)
    0x81, 0x02,                    //   INPUT (Data,Var,Abs)
    0x95, 0x01,                    //   REPORT_COUNT (1)
    0x75, 0x08,                    //   REPORT_SIZE (8)
    0x81, 0x03,                    //   INPUT (Cnst,Var,Abs)
    0x95, 0x05,                    //   REPORT_COUNT (5)
    0x75, 0x01,                    //   REPORT_SIZE (1)
    0x05, 0x08,                    //   USAGE_PAGE (LEDs)
    0x19, 0x01,                    //   USAGE_MINIMUM (Num Lock)
    0x29, 0x05,                    //   USAGE_MAXIMUM (Kana)
    0x91, 0x02,                    //   OUTPUT (Data,Var,Abs)
    0x95, 0x01,                    //   REPORT_COUNT (1)
    0x75, 0x03,                    //   REPORT_SIZE (3)
    0x91, 0x03,                    //   OUTPUT (Cnst,Var,Abs)
    0x95, 0x06,                    //   REPORT_COUNT (6)
    0x75, 0x08,                    //   REPORT_SIZE (8)
    0x15, 0x00,                    //   LOGICAL_MINIMUM (0)
    0x25, 0xFF,                    //   LOGICAL_MAXIMUM (101)
    0x05, 0x07,                    //   USAGE_PAGE (Keyboard)
    0x19, 0x00,                    //   USAGE_MINIMUM (Reserved (no event indicated))
    0x29, 0x65,                    //   USAGE_MAXIMUM (Keyboard Application)
    0x81, 0x00,                    //   INPUT (Data,Ary,Abs)
    0xc0                           // END_COLLECTION
};

code uint8 ConfigurationDescriptor[9+9+9+7+7]=
{
//����������9�ֽ�
0x09,//bLength
0x02,//bDescriptorType
sizeof(ConfigurationDescriptor)&0xff,//wTotalLength low byte
(sizeof(ConfigurationDescriptor)>>8)&0xff,//wTotalLength high byte
0x01,//bNumInterfaces
0x01,//bConfiguration
0x00,//iConfiguration,none
0x80,//bmAttributes
0x32,//bMaxPower

//�ӿ�������
0x09,
0x04,
0x00,
0x00,
0x02,
0x03,//class:HID
0x01,//subclass:Boot 
0x01,//Keyboard
0x00,//Index

//hid
0x09,
0x21,
0x10,
0x01,
0x21,
0x01,
0x22,
sizeof(ReportDescriptor)&0xff,
(sizeof(ReportDescriptor)>>8)&0xff,
//in�˵�������
0x07,
0x05,
0x81,
0x03,
0x10,
0x00,
0x0a,
//out endpoint
0x07,
0x05,
0x01,
0x03,
0x10,
0x00,
0x0a
};



#endif