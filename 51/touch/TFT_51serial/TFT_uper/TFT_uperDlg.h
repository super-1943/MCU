// TFT_uperDlg.h : header file
//
//{{AFX_INCLUDES()
#include "mscomm.h"
//}}AFX_INCLUDES

#if !defined(AFX_TFT_UPERDLG_H__625C00EC_058A_4305_B10D_F938403DFC5B__INCLUDED_)
#define AFX_TFT_UPERDLG_H__625C00EC_058A_4305_B10D_F938403DFC5B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTFT_uperDlg dialog

class CTFT_uperDlg : public CDialog
{
// Construction
public:
	CTFT_uperDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTFT_uperDlg)
	enum { IDD = IDD_TFT_UPER_DIALOG };
	CComboBox	m_ctrlCombaud;
	CComboBox	m_ctrlComnum;
	CProgressCtrl	m_ctrlProgress;
	CMSComm	m_ctrlComm;
	CString	m_strStatic;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTFT_uperDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTFT_uperDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBUTTONopencom();
	afx_msg void OnComm();
	afx_msg void OnBUTTONexit();
	afx_msg void OnBUTTONclear();
	afx_msg void OnBUTTONloadpic();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnBUTTONloadpic2();
	afx_msg void OnBUTTONpreview();
	afx_msg void OnBUTTONopenbmp();
	DECLARE_EVENTSINK_MAP()
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TFT_UPERDLG_H__625C00EC_058A_4305_B10D_F938403DFC5B__INCLUDED_)
