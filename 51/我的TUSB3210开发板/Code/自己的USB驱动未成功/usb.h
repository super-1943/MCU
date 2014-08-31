#ifndef _kkk_usb_h
#define _kkk_usb_h
#include "tusb3210.h"


#define USB_DISCONNECT 	bUSBCTL&=~USBCTL_CONT
#define USB_CONNECT		bUSBCTL|=USBCTL_CONT
#define ENTER_SETUP		bUSBCTL|=USBCTL_SIR
#define EXIT_SETUP		bUSBCTL&=~USBCTL_SIR
#define SETUP_OUT		bUSBCTL&=~USBCTL_DIR
#define SETUP_IN		bUSBCTL|=USBCTL_DIR

#define GET_STATUS         0
#define CLEAR_FEATURE      1
#define SET_FEATURE        3
#define SET_ADDRESS        5
#define GET_DESCRIPTOR     6
#define SET_DESCRIPTOR     7
#define GET_CONFIGURATION  8
#define SET_CONFIGURATION  9
#define GET_INTERFACE      10
#define SET_INTERFACE      11
#define SYNCH_FRAME        12





extern code uint8 DeviceDescriptor[];
extern code uint8 LanguageId[];
extern code uint8 ManufacturerStringDescriptor[];
extern code uint8 ProductStringDescriptor[];
extern code uint8 SerialNumberStringDescriptor[];
extern code uint8 ReportDescriptor[];




extern void hardware_init(void);
extern void EP0_senddata(void);
extern void setup_handler(void);


#endif