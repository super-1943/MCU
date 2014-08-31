// super2051Dlg.h : header file
//
//{{AFX_INCLUDES()
#include "mscomm.h"
//}}AFX_INCLUDES

#if !defined(AFX_SUPER2051DLG_H__97D12373_011C_456A_AB24_745B76DC8151__INCLUDED_)
#define AFX_SUPER2051DLG_H__97D12373_011C_456A_AB24_745B76DC8151__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSuper2051Dlg dialog

class CSuper2051Dlg : public CDialog
{
// Construction
public:
	CSuper2051Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSuper2051Dlg)
	enum { IDD = IDD_SUPER2051_DIALOG };
	CProgressCtrl	m_ctrlpro;
	CEdit	m_editCtrl;
	CString	m_strEditRxdata;
	CMSComm	m_ctrlComm;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSuper2051Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSuper2051Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonExit();
	afx_msg void OnComm();
	afx_msg void OnButtonRead();
	afx_msg void OnButtonErase();
	afx_msg void OnButtonWrite();
	afx_msg void OnButtonCheck();
	afx_msg void OnButtonLock();
	afx_msg void OnButtonSb();
	afx_msg void OnButtonLoad();
	afx_msg void OnBUTTONClear();
	afx_msg void OnButtonDownload();
	afx_msg void OnBUTTONParameter();
	afx_msg void OnBUTTONOpen();
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnClose();
	afx_msg void OnButton1();
	DECLARE_EVENTSINK_MAP()
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SUPER2051DLG_H__97D12373_011C_456A_AB24_745B76DC8151__INCLUDED_)
