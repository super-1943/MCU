// 430boboshang.h : main header file for the 430BOBOSHANG application
//

#if !defined(AFX_430BOBOSHANG_H__A1486D7E_1CBE_4759_B2C4_5248926E6F35__INCLUDED_)
#define AFX_430BOBOSHANG_H__A1486D7E_1CBE_4759_B2C4_5248926E6F35__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMy430boboshangApp:
// See 430boboshang.cpp for the implementation of this class
//

class CMy430boboshangApp : public CWinApp
{
public:
	CMy430boboshangApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy430boboshangApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMy430boboshangApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_430BOBOSHANG_H__A1486D7E_1CBE_4759_B2C4_5248926E6F35__INCLUDED_)
