#if !defined(AFX_CANSHUDLG_H__07C61ADD_1D93_4705_AC4E_DC22237412BE__INCLUDED_)
#define AFX_CANSHUDLG_H__07C61ADD_1D93_4705_AC4E_DC22237412BE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CanshuDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCanshuDlg dialog

class CCanshuDlg : public CDialog
{
// Construction
public:
	CCanshuDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CCanshuDlg)
	enum { IDD = IDD_DIALOG1 };
	CString	m_strEditAttrib;
	int		m_intPortNum;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCanshuDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCanshuDlg)
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CANSHUDLG_H__07C61ADD_1D93_4705_AC4E_DC22237412BE__INCLUDED_)
