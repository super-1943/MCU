// super2051.h : main header file for the SUPER2051 application
//

#if !defined(AFX_SUPER2051_H__97B481A1_951F_4C96_9093_0234910F3491__INCLUDED_)
#define AFX_SUPER2051_H__97B481A1_951F_4C96_9093_0234910F3491__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSuper2051App:
// See super2051.cpp for the implementation of this class
//

class CSuper2051App : public CWinApp
{
public:
	CSuper2051App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSuper2051App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSuper2051App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SUPER2051_H__97B481A1_951F_4C96_9093_0234910F3491__INCLUDED_)
