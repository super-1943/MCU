// 430shangweiji.h : main header file for the 430SHANGWEIJI application
//

#if !defined(AFX_430SHANGWEIJI_H__FD3CD3FA_7819_4357_B847_C07F9D2775D2__INCLUDED_)
#define AFX_430SHANGWEIJI_H__FD3CD3FA_7819_4357_B847_C07F9D2775D2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMy430shangweijiApp:
// See 430shangweiji.cpp for the implementation of this class
//

class CMy430shangweijiApp : public CWinApp
{
public:
	CMy430shangweijiApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy430shangweijiApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMy430shangweijiApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_430SHANGWEIJI_H__FD3CD3FA_7819_4357_B847_C07F9D2775D2__INCLUDED_)
