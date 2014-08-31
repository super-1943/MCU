// TFT_uper.h : main header file for the TFT_UPER application
//

#if !defined(AFX_TFT_UPER_H__6DBC2E5D_E133_4BA1_8D7B_6E9445EC8902__INCLUDED_)
#define AFX_TFT_UPER_H__6DBC2E5D_E133_4BA1_8D7B_6E9445EC8902__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTFT_uperApp:
// See TFT_uper.cpp for the implementation of this class
//

class CTFT_uperApp : public CWinApp
{
public:
	CTFT_uperApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTFT_uperApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTFT_uperApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TFT_UPER_H__6DBC2E5D_E133_4BA1_8D7B_6E9445EC8902__INCLUDED_)
