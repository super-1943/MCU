// 430boboshangDlg.h : header file
//
//{{AFX_INCLUDES()
#include "mscomm.h"
//}}AFX_INCLUDES

#if !defined(AFX_430BOBOSHANGDLG_H__65A14095_6AF9_4896_A86D_08BA74B637DB__INCLUDED_)
#define AFX_430BOBOSHANGDLG_H__65A14095_6AF9_4896_A86D_08BA74B637DB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMy430boboshangDlg dialog

class CMy430boboshangDlg : public CDialog
{
// Construction
public:
	CMy430boboshangDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMy430boboshangDlg)
	enum { IDD = IDD_MY430BOBOSHANG_DIALOG };
	int		m_zhouqi;
	int		m_xiangcha;
	CMSComm	m_ctrlComm;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy430boboshangDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMy430boboshangDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_430BOBOSHANGDLG_H__65A14095_6AF9_4896_A86D_08BA74B637DB__INCLUDED_)
