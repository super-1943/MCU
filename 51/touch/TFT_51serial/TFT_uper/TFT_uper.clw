; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CTFT_uperDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "TFT_uper.h"

ClassCount=3
Class1=CTFT_uperApp
Class2=CTFT_uperDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_TFT_UPER_DIALOG

[CLS:CTFT_uperApp]
Type=0
HeaderFile=TFT_uper.h
ImplementationFile=TFT_uper.cpp
Filter=N

[CLS:CTFT_uperDlg]
Type=0
HeaderFile=TFT_uperDlg.h
ImplementationFile=TFT_uperDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CTFT_uperDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=TFT_uperDlg.h
ImplementationFile=TFT_uperDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_TFT_UPER_DIALOG]
Type=1
Class=CTFT_uperDlg
ControlCount=10
Control1=IDC_MSCOMM1,{648A5600-2C6E-101B-82B6-000000000014},1342242816
Control2=IDC_BUTTON_clear,button,1342242816
Control3=IDC_STATIC_message,static,1342308352
Control4=IDC_BUTTON_loadpic,button,1342242816
Control5=IDC_BUTTON_exit,button,1342242816
Control6=IDC_COMBO_com,combobox,1344340226
Control7=IDC_COMBO_baud,combobox,1344340226
Control8=IDC_BUTTON_opencom,button,1342242816
Control9=IDC_BUTTON_preview,button,1342242816
Control10=IDC_BUTTON_openbmp,button,1342242816

