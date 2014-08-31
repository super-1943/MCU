// CanshuDlg.cpp : implementation file
//

#include "stdafx.h"
#include "super2051.h"
#include "CanshuDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCanshuDlg dialog


CCanshuDlg::CCanshuDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCanshuDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCanshuDlg)
	m_strEditAttrib = _T("");
	m_intPortNum = 0;
	//}}AFX_DATA_INIT
}


void CCanshuDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCanshuDlg)
	DDX_Text(pDX, IDC_EDIT_PORTATTRIB, m_strEditAttrib);
	DDV_MaxChars(pDX, m_strEditAttrib, 9);
	DDX_Text(pDX, IDC_EDIT_PORTNUM, m_intPortNum);
	DDV_MinMaxInt(pDX, m_intPortNum, 1, 99);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCanshuDlg, CDialog)
	//{{AFX_MSG_MAP(CCanshuDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCanshuDlg message handlers

void CCanshuDlg::OnOK() 
{
	// TODO: Add extra validation here

	CDialog::OnOK();
}

void CCanshuDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}
