#ifndef _kkk_usb_h
#define _kkk_usb_h

code uint8 DeviceDescriptor[18]=
{

0x12,//bLength,长度18字节
0x01,//bDescriptorType,设备描述符
0x10,0x01,//bcdUSB，usb1.1
0x00,//bDeviceClass，一般为0
0x00,//bDeviceSubClass,一般为0
0x00,//bDevicePortocol，设备协议
0x10,//bMaxPacketSize0，端点0最大包长，这里是16字节

0x88,0x88,//VID
0x02,0x00,//PID
0x00,0x01,//设备版本号
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
/*********        本转换结果来自         **********/
/********* Http://computer00.21ic.org    **********/
/*********        作者: 电脑圈圈         **********/
/*********         欢迎大家使用          **********/
/*********    版权所有，盗版请写明出处   **********/
/**************************************************/

//http://computer00.21ic.org/user1/2198/archives/2007/42769.html
//字符串“赵永科同志思想端正，爱国爱党，同意加入中国共产党。”的Unicode编码
//8位小端格式
code uint8 ManufacturerStringDescriptor[52]={
52,         //该描述符的长度为52字节
0x03,       //字符串描述符的类型编码为0x03
0x75, 0x8d, //赵
0x38, 0x6c, //永
0xd1, 0x79, //科
0x0c, 0x54, //同
0xd7, 0x5f, //志
0x1d, 0x60, //思
0xf3, 0x60, //想
0xef, 0x7a, //端
0x63, 0x6b, //正
0x0c, 0xff, //，
0x31, 0x72, //爱
0xfd, 0x56, //国
0x31, 0x72, //爱
0x5a, 0x51, //党
0x0c, 0xff, //，
0x0c, 0x54, //同
0x0f, 0x61, //意
0xa0, 0x52, //加
0x65, 0x51, //入
0x2d, 0x4e, //中
0xfd, 0x56, //国
0x71, 0x51, //共
0xa7, 0x4e, //产
0x5a, 0x51, //党
0x02, 0x30 //。
//注：请将最后一个多余的逗号删除
};
/**************************************************/
/*********        本转换结果来自         **********/
/********* Http://computer00.21ic.org    **********/
/*********        作者: 电脑圈圈         **********/
/*********         欢迎大家使用          **********/
/*********    版权所有，盗版请写明出处   **********/
/**************************************************/

//http://computer00.21ic.org/user1/2198/archives/2007/42769.html
//字符串“电脑圈圈的usb真他妈牛逼”的Unicode编码
//8位小端格式
code uint8 ProductStringDescriptor[28]={
28,         //该描述符的长度为28字节
0x03,       //字符串描述符的类型编码为0x03
0x35, 0x75, //电
0x11, 0x81, //脑
0x08, 0x57, //圈
0x08, 0x57, //圈
0x84, 0x76, //的
0x75, 0x00, //u
0x73, 0x00, //s
0x62, 0x00, //b
0x1f, 0x77, //真
0xd6, 0x4e, //他
0x88, 0x59, //妈
0x5b, 0x72, //牛
0x3c, 0x90 //逼
//注：请将最后一个多余的逗号删除
};
/**************************************************/
/*********        本转换结果来自         **********/
/********* Http://computer00.21ic.org    **********/
/*********        作者: 电脑圈圈         **********/
/*********         欢迎大家使用          **********/
/*********    版权所有，盗版请写明出处   **********/
/**************************************************/

//http://computer00.21ic.org/user1/2198/archives/2007/42769.html
//字符串“2009-12-19”的Unicode编码
//8位小端格式
code uint8 SerialNumberStringDescriptor[22]={
22,         //该描述符的长度为22字节
0x03,       //字符串描述符的类型编码为0x03
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
//注：请将最后一个多余的逗号删除
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
//配置描述符9字节
0x09,//bLength
0x02,//bDescriptorType
sizeof(ConfigurationDescriptor)&0xff,//wTotalLength low byte
(sizeof(ConfigurationDescriptor)>>8)&0xff,//wTotalLength high byte
0x01,//bNumInterfaces
0x01,//bConfiguration
0x00,//iConfiguration,none
0x80,//bmAttributes
0x32,//bMaxPower

//接口描述符
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
//in端点描述符
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