// 430boboshangDlg.cpp : implementation file
//

#include "stdafx.h"
#include "430boboshang.h"
#include "430boboshangDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

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
// CMy430boboshangDlg dialog

CMy430boboshangDlg::CMy430boboshangDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMy430boboshangDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMy430boboshangDlg)
	m_zhouqi = 0;
	m_xiangcha = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy430boboshangDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMy430boboshangDlg)
	DDX_Text(pDX, IDC_EDIT1, m_zhouqi);
	DDV_MinMaxInt(pDX, m_zhouqi, 0, 65536);
	DDX_Text(pDX, IDC_EDIT2, m_xiangcha);
	DDV_MinMaxInt(pDX, m_xiangcha, 0, 65536);
	DDX_Control(pDX, IDC_MSCOMM1, m_ctrlComm);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMy430boboshangDlg, CDialog)
	//{{AFX_MSG_MAP(CMy430boboshangDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMy430boboshangDlg message handlers

BOOL CMy430boboshangDlg::OnInitDialog()
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
	m_xiangcha=m_zhouqi=0;
	m_ctrlComm.SetCommPort(1);//com1
	m_ctrlComm.SetInputMode(1);//binary
	m_ctrlComm.SetInBufferSize(1024);
	m_ctrlComm.SetOutBufferSize(512);
	m_ctrlComm.SetSettings("9600,n,8,1");
	if(!m_ctrlComm.GetPortOpen())
		m_ctrlComm.SetPortOpen(TRUE);
	m_ctrlComm.SetRThreshold(1);
	m_ctrlComm.SetInputLen(0);
	m_ctrlComm.GetInput();
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMy430boboshangDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMy430boboshangDlg::OnPaint() 
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
HCURSOR CMy430boboshangDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMy430boboshangDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	UpdateData(1);
	CByteArray a;
	a.SetSize(6);
	a.SetAt(0,'#');
	a.SetAt(1,0);
	a.SetAt(2,m_xiangcha);
	a.SetAt(3,'#');
	a.SetAt(4,1);
	a.SetAt(5,m_zhouqi);
	m_ctrlComm.SetOutput(COleVariant(a));

	UpdateData(0);	
}
