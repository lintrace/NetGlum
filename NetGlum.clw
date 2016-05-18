; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CAboutDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "NetGlum.h"

ClassCount=4
Class1=CNetGlumApp
Class2=CNetGlumDlg
Class3=CAboutDlg

ResourceCount=4
Resource1=IDD_NETGLUM_DIALOG
Resource2=IDR_MAINFRAME
Resource3=IDD_ABOUTBOX
Class4=CRegister
Resource4=IDD_REGISTER

[CLS:CNetGlumApp]
Type=0
HeaderFile=NetGlum.h
ImplementationFile=NetGlum.cpp
Filter=N

[CLS:CNetGlumDlg]
Type=0
HeaderFile=NetGlumDlg.h
ImplementationFile=NetGlumDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CNetGlumDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=AboutDlg.h
ImplementationFile=AboutDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CAboutDlg
VirtualFilter=dWC

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=14
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDOK,button,1342373889
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308364
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,button,1342177287
Control10=IDC_STATIC,button,1342177287
Control11=IDC_STATIC,button,1342177287
Control12=IDC_BREG,button,1342242816
Control13=IDC_LIST1,listbox,1352745217
Control14=IDC_STATIC,button,1342177287

[DLG:IDD_NETGLUM_DIALOG]
Type=1
Class=?
ControlCount=14
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_EDIT1,edit,1350631560
Control4=IDC_EDIT2,edit,1350631560
Control5=IDC_EDIT3,edit,1352732868
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,button,1342177287
Control9=IDC_STATIC,button,1342177287
Control10=IDC_BUTTON1,button,1342242816
Control11=IDC_STATIC,static,1476526080
Control12=IDC_STATIC,button,1342177287
Control13=IDC_CHECK1,button,1342258947
Control14=IDC_CHECK2,button,1342246915

[DLG:IDD_REGISTER]
Type=1
Class=CRegister
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDC_EDIT1,edit,1350631592
Control3=IDC_STATIC,button,1342177287

[CLS:CRegister]
Type=0
HeaderFile=Register.h
ImplementationFile=Register.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC

