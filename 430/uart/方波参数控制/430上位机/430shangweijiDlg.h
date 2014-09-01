// 430shangweijiDlg.h : header file
//
//{{AFX_INCLUDES()
#include "mscomm.h"
//}}AFX_INCLUDES

#if !defined(AFX_430SHANGWEIJIDLG_H__5F776A1E_0C84_4EFD_8878_0D4D0D71D3C1__INCLUDED_)
#define AFX_430SHANGWEIJIDLG_H__5F776A1E_0C84_4EFD_8878_0D4D0D71D3C1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMy430shangweijiDlg dialog

class CMy430shangweijiDlg : public CDialog
{
// Construction
public:
	CMy430shangweijiDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMy430shangweijiDlg)
	enum { IDD = IDD_MY430SHANGWEIJI_DIALOG };
	int		m_int;
	CMSComm	m_ctrlcomm;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy430shangweijiDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMy430shangweijiDlg)
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

#endif // !defined(AFX_430SHANGWEIJIDLG_H__5F776A1E_0C84_4EFD_8878_0D4D0D71D3C1__INCLUDED_)
