// super2051Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "super2051.h"
#include "super2051Dlg.h"
#include "CanshuDlg.h"


#include<string.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define MAX_SIZE 600
unsigned char IsLoaded=0;

unsigned char G_currentstat=0;
unsigned char G_busy=0;
const int MaxSize=0x800;
const char hexcode[17]="0123456789ABCDEF";
int length=0,address=0,accumulater=0;
char buffer[100];
int sram[MaxSize];
void init_buffer(void)
{
	int i;
	for(i=0;i<50;i++)
	{
		buffer[i]=0;
	}
}
void init_sram(void)
{
	int i;
	for(i=0;i<MaxSize;i++)
	{
		sram[i]=255;
	}
}
int hex2int(char x,char y)
{
	int temp=0;
	if(x>='a' && x<='z')
	{
		x-=32;
	}
	if(y>='a' && y<='z')
	{
		y-=32;
	}
	for(int i=0;i<16;i++)
	{
		if(hexcode[i]==x)
		{
			temp+=i*16;
		}
	}
	for(i=0;i<16;i++)
	{
		if(hexcode[i]==y)
		{
			temp+=i;
		}
	}
	return temp;
}
CString Int2HexCString(int myint)
{
	CString myCString="";
	if(myint==0)
	{
		myCString+="00";
		return myCString;
	}
	else if(myint <16 && myint >0)
	{
		myCString+="0";
		myCString+=hexcode[myint];
		return myCString;
	}
	char s[6]={0};
	for(int i=0;myint>0;i++)
	{
		s[i]=hexcode[myint%16];
		myint/=16;
	}
	myCString+=s;
	myCString.MakeReverse();
	return myCString;
}
/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSuper2051Dlg dialog

CSuper2051Dlg::CSuper2051Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSuper2051Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSuper2051Dlg)
	m_strEditRxdata = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSuper2051Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSuper2051Dlg)
	DDX_Control(pDX, IDC_PROGRESS1, m_ctrlpro);
	DDX_Control(pDX, IDC_EDIT1, m_editCtrl);
	DDX_Text(pDX, IDC_EDIT1, m_strEditRxdata);
	DDX_Control(pDX, IDC_MSCOMM1, m_ctrlComm);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSuper2051Dlg, CDialog)
	//{{AFX_MSG_MAP(CSuper2051Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_EXIT, OnButtonExit)
	ON_BN_CLICKED(IDC_BUTTON_READ, OnButtonRead)
	ON_BN_CLICKED(IDC_BUTTON_ERASE, OnButtonErase)
	ON_BN_CLICKED(IDC_BUTTON_WRITE, OnButtonWrite)
	ON_BN_CLICKED(IDC_BUTTON_CHECK, OnButtonCheck)
	ON_BN_CLICKED(IDC_BUTTON_LOCK, OnButtonLock)
	ON_BN_CLICKED(IDC_BUTTON_SB, OnButtonSb)
	ON_BN_CLICKED(IDC_BUTTON_LOAD, OnButtonLoad)
	ON_BN_CLICKED(IDC_BUTTON_Clear, OnBUTTONClear)
	ON_BN_CLICKED(IDC_BUTTON_DOWNLOAD, OnButtonDownload)
	ON_BN_CLICKED(IDC_BUTTON_Parameter, OnBUTTONParameter)
	ON_BN_CLICKED(IDC_BUTTON_Open, OnBUTTONOpen)
	ON_WM_RBUTTONDOWN()
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSuper2051Dlg message handlers

BOOL CSuper2051Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here

	m_ctrlComm.SetCommPort(1);//com1
	m_ctrlComm.SetInputMode(1);//binary
	m_ctrlComm.SetInBufferSize(1024);
	m_ctrlComm.SetOutBufferSize(512);
	m_ctrlComm.SetSettings("2400,n,8,1");
	if(!m_ctrlComm.GetPortOpen())
		m_ctrlComm.SetPortOpen(TRUE);
	m_ctrlComm.SetRThreshold(1);
	m_ctrlComm.SetInputLen(0);
	m_ctrlComm.GetInput();



	m_ctrlpro.SetRange(0,100);
	m_ctrlpro.SetStep(1);
	m_ctrlpro.SetPos(0);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CSuper2051Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CSuper2051Dlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CSuper2051Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CSuper2051Dlg::OnButtonExit() 
{
	// TODO: Add your control notification handler code here
	CDialog::OnOK();
}

BEGIN_EVENTSINK_MAP(CSuper2051Dlg, CDialog)
    //{{AFX_EVENTSINK_MAP(CSuper2051Dlg)
	ON_EVENT(CSuper2051Dlg, IDC_MSCOMM1, 1 /* OnComm */, OnComm, VTS_NONE)
	//}}AFX_EVENTSINK_MAP
END_EVENTSINK_MAP()

void CSuper2051Dlg::OnComm() 
{
	// TODO: Add your control notification handler code here

		VARIANT variant_inp;
		COleSafeArray safearray_inp;
		LONG len,k;
		BYTE rxdata[2048];
		CString strtemp;
//		if(m_editCtrl.GetLineCount()>=23)
		{
//			m_strEditRxdata.Empty();
		}
		if(m_ctrlComm.GetCommEvent()==2)//you zi fu
		{
			if(G_busy==0)
			{
				variant_inp=m_ctrlComm.GetInput();
				safearray_inp=variant_inp;
				len=safearray_inp.GetOneDimSize();
				for(k=0;k<len;k++)
					safearray_inp.GetElement(&k,rxdata+k);
				for(k=0;k<len;k++)
				{
					BYTE bt=*(char *)(rxdata+k);
					strtemp.Format("%c",bt);
					m_strEditRxdata+=strtemp;
				}
				m_ctrlpro.StepIt();
			}
			if(G_busy==1)
			{
				G_currentstat++;
				OnButtonDownload();
			}
		}
		UpdateData(FALSE);
}

void CSuper2051Dlg::OnButtonRead() 
{
	// TODO: Add your control notification handler code here
	CByteArray a;
	a.SetSize(3);
	a.SetAt(0,'#');
	a.SetAt(1,1);
	a.SetAt(2,'$');
	m_ctrlComm.SetOutput(COleVariant(a));
/*	
	m_strEditRxdata="Reading...";*/
	UpdateData(0);
	m_ctrlpro.SetPos(90);
	m_strEditRxdata="OK";
	UpdateData(0);
	m_ctrlpro.SetPos(100);
}

void CSuper2051Dlg::OnButtonErase() 
{
	// TODO: Add your control notification handler code here
	CByteArray a;
	a.SetSize(3);
	a.SetAt(0,'#');
	a.SetAt(1,10);
	a.SetAt(2,'$');
	m_ctrlComm.SetOutput(COleVariant(a));
	m_strEditRxdata="";	
}

void CSuper2051Dlg::OnButtonWrite() 
{
	// TODO: Add your control notification handler code here
	CByteArray a;
	a.SetSize(3);
	a.SetAt(0,'#');
	a.SetAt(1,2);
	a.SetAt(2,'$');
	m_ctrlComm.SetOutput(COleVariant(a));
	m_strEditRxdata="";	
}

void CSuper2051Dlg::OnButtonCheck() 
{
	// TODO: Add your control notification handler code here
/*	CByteArray a;
	a.SetSize(3);
	a.SetAt(0,'#');
	a.SetAt(1,3);
	a.SetAt(2,'$');
	m_ctrlComm.SetOutput(COleVariant(a));
	m_strEditRxdata="";	*/
	m_strEditRxdata="Checking...";
	UpdateData(0);
	m_ctrlpro.SetPos(90);
	m_strEditRxdata="OK";
	UpdateData(0);
	m_ctrlpro.SetPos(100);
}

void CSuper2051Dlg::OnButtonLock() 
{
	// TODO: Add your control notification handler code here
	CByteArray a;
	a.SetSize(3);
	a.SetAt(0,'#');
	a.SetAt(1,4);
	a.SetAt(2,'$');
	m_ctrlComm.SetOutput(COleVariant(a));
	m_strEditRxdata="";	
}

void CSuper2051Dlg::OnButtonSb() 
{
	// TODO: Add your control notification handler code here
	CByteArray a;
	a.SetSize(3);
	a.SetAt(0,'#');
	a.SetAt(1,5);
	a.SetAt(2,'$');
	m_ctrlComm.SetOutput(COleVariant(a));
	m_strEditRxdata="";	
}

void CSuper2051Dlg::OnButtonLoad() 
{
	// TODO: Add your control notification handler code here
	CFile file;	
	CFileDialog fdl(TRUE,NULL,NULL,OFN_HIDEREADONLY,"hex文件 (*.hex)|*.hex|All Files (*.*)|*.*||");
	if(fdl.DoModal()==IDOK)
	{
		file.Open(fdl.GetFileName(),CFile::modeRead);
		CArchive infile(&file,CArchive::load);
		init_buffer();
		init_sram();
		m_strEditRxdata="";
		CString temp="";
		while(temp.Compare(":00000001FF"))
		{
			infile.ReadString(buffer,100);
			temp=buffer;
			if(buffer[0]!=':')
			{
				MessageBox("Not hex file!");
				infile.Close();
				return;
			}
			length=hex2int(buffer[1],buffer[2]);
			accumulater+=length;
			address=hex2int(buffer[3],buffer[4]);
			accumulater+=address;
			address*=256;
			address+=hex2int(buffer[5],buffer[6]);
			accumulater+=address%256;
			for(int count=0;count<length;count++)
			{
				sram[address+count]=hex2int(buffer[9+count*2],buffer[10+count*2]);
				accumulater+=sram[address+count];
				accumulater%=256;
			}
			accumulater+=hex2int(buffer[9+count*2],buffer[10+count*2]);
			if(accumulater%256!=0)
			{
				for(int count=0;count<length;count++)
				{
					sram[address+count]=0xff;
				}			
			}
			length=0;
			address=0;
			accumulater=0;
		}
		for(int i=0;i<0x800;i++)
		{			
			m_strEditRxdata+=" ";
			m_strEditRxdata+=Int2HexCString(sram[i]);
			if(i%16==15)
			{
				m_strEditRxdata+="\r\n";
			}

		}
		m_strEditRxdata+="\r\n";
		UpdateData(FALSE);
		infile.Close();
		IsLoaded=1;
	}
	else
	{
		MessageBox("没有装入文件！");
		IsLoaded=0;
	}
}

void CSuper2051Dlg::OnBUTTONClear() 
{
	// TODO: Add your control notification handler code here
	m_strEditRxdata="";
	UpdateData(FALSE);
}

void CSuper2051Dlg::OnButtonDownload() 
{
	// TODO: Add your control notification handler code here
	CByteArray a;
	int i;
	G_busy=1;	
	m_ctrlpro.SetStep(20);
	OnBUTTONClear();
	if(IsLoaded)
	{
		if(G_currentstat==0)
		{
			m_ctrlpro.SetPos(0);
			a.SetSize(3);
			a.SetAt(0,'#');
			a.SetAt(1,6);
			a.SetAt(2,'$');
			m_ctrlComm.SetOutput(COleVariant(a));
			MessageBox("准备好后请按确定");
			a.SetSize(512);
			for(i=0;i<512;i++)
			{
				a.SetAt(i,sram[i]);
			}
			m_ctrlpro.StepIt();
			m_ctrlComm.SetOutput(COleVariant(a));
		}
		if(G_currentstat==1)
		{
			a.SetSize(512);
			for(i=0;i<512;i++)
			{
				a.SetAt(i,sram[i+512]);				
			}
			m_ctrlpro.StepIt();
			m_ctrlComm.SetOutput(COleVariant(a));
		}
		if(G_currentstat==2)
		{
			a.SetSize(512);
			for(i=0;i<512;i++)
			{
				a.SetAt(i,sram[i+1024]);				
			}
			m_ctrlpro.StepIt();
			m_ctrlComm.SetOutput(COleVariant(a));
		}
		if(G_currentstat==3)
		{
			a.SetSize(512);
			for(i=0;i<512;i++)
			{
				a.SetAt(i,sram[i+1536]);				
			}
			m_ctrlpro.StepIt();
			m_ctrlComm.SetOutput(COleVariant(a));
			G_busy=0;
			G_currentstat=0;
			m_strEditRxdata="OK";
			UpdateData(0);
		}
	}
	else
	{
		MessageBox("没有装入Hex文件！");
		G_busy=0;
	}
	//////fasongbababa!~!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
}

void CSuper2051Dlg::OnBUTTONParameter() 
{
	// TODO: Add your control notification handler code here
//	MessageBox("参数格式应为：“波特率，校验位，数据位，停止位”\r\n\t\t如“9600,n,8,1”");	
	CCanshuDlg dlg;
	CString tmp;
	tmp=m_ctrlComm.GetSettings();
	dlg.m_intPortNum=m_ctrlComm.GetCommPort();
	dlg.m_strEditAttrib=tmp.Left(tmp.Find(',',0));
	dlg.UpdateData(0);
	if(m_ctrlComm.GetPortOpen())
	{
		m_ctrlComm.SetPortOpen(FALSE);
	}
	if(dlg.DoModal()==IDOK)
	{	
		m_ctrlComm.SetCommPort(dlg.m_intPortNum);
		m_ctrlComm.SetSettings(dlg.m_strEditAttrib+",n,8,1");
//		m_ctrlComm.SetPortOpen(TRUE);
	}
}

void CSuper2051Dlg::OnBUTTONOpen() 
{
	// TODO: Add your control notification handler code here
	if(!m_ctrlComm.GetPortOpen())
	{
		m_ctrlComm.SetPortOpen(TRUE);
	}
}

void CSuper2051Dlg::OnRButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CAboutDlg mydlg;
	mydlg.DoModal();
	CDialog::OnRButtonDown(nFlags, point);
}

void CSuper2051Dlg::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	CAboutDlg mydlg;
	mydlg.DoModal();	
	CDialog::OnClose();
}

void CSuper2051Dlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	UpdateData(1);

	m_ctrlComm.SetOutput(COleVariant(m_strEditRxdata));
}
