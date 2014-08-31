; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CSuper2051Dlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "super2051.h"

ClassCount=4
Class1=CSuper2051App
Class2=CSuper2051Dlg
Class3=CAboutDlg

ResourceCount=4
Resource1=IDD_SUPER2051_DIALOG
Resource2=IDR_MAINFRAME
Resource3=IDD_ABOUTBOX
Class4=CCanshuDlg
Resource4=IDD_DIALOG1

[CLS:CSuper2051App]
Type=0
HeaderFile=super2051.h
ImplementationFile=super2051.cpp
Filter=N

[CLS:CSuper2051Dlg]
Type=0
HeaderFile=super2051Dlg.h
ImplementationFile=super2051Dlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_PROGRESS1

[CLS:CAboutDlg]
Type=0
HeaderFile=super2051Dlg.h
ImplementationFile=super2051Dlg.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_SUPER2051_DIALOG]
Type=1
Class=CSuper2051Dlg
ControlCount=18
Control1=IDC_EDIT1,edit,1352728580
Control2=IDC_MSCOMM1,{648A5600-2C6E-101B-82B6-000000000014},1342242816
Control3=IDC_BUTTON_EXIT,button,1342242816
Control4=IDC_BUTTON_LOAD,button,1342242816
Control5=IDC_BUTTON_SB,button,1342242816
Control6=IDC_BUTTON_LOCK,button,1342242816
Control7=IDC_BUTTON_CHECK,button,1342242816
Control8=IDC_BUTTON_ERASE,button,1342242816
Control9=IDC_BUTTON_READ,button,1342242816
Control10=IDC_STATIC,static,1342308353
Control11=IDC_BUTTON_Clear,button,1342242816
Control12=IDC_BUTTON_DOWNLOAD,button,1342242816
Control13=IDC_BUTTON_Parameter,button,1342242816
Control14=IDC_BUTTON_Open,button,1342242816
Control15=IDC_STATIC,static,1342308352
Control16=IDC_STATIC,static,1342177294
Control17=IDC_BUTTON1,button,1342242816
Control18=IDC_PROGRESS1,msctls_progress32,1350565888

[DLG:IDD_DIALOG1]
Type=1
Class=CCanshuDlg
ControlCount=6
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_EDIT_PORTNUM,edit,1350631552
Control4=IDC_EDIT_PORTATTRIB,edit,1350631552
Control5=IDC_STATIC,static,1342308865
Control6=IDC_STATIC,static,1342308865

[CLS:CCanshuDlg]
Type=0
HeaderFile=CanshuDlg.h
ImplementationFile=CanshuDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_EDIT_PORTNUM

