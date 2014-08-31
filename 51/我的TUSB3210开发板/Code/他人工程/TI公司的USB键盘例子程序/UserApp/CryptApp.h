//
// Copyright (c) 2004 Golden Bits Software, Inc.
// All rights reserved
//
//
// CryptApp.h : main header file for the CRYPTAPP application
//

#if !defined(AFX_CRYPTAPP_H__A1C650FE_9F55_4AB1_8515_92EDF5B4E563__INCLUDED_)
#define AFX_CRYPTAPP_H__A1C650FE_9F55_4AB1_8515_92EDF5B4E563__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCryptAppApp:
// See CryptApp.cpp for the implementation of this class
//

class CCryptAppApp : public CWinApp
{
public:
	CCryptAppApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCryptAppApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCryptAppApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CRYPTAPP_H__A1C650FE_9F55_4AB1_8515_92EDF5B4E563__INCLUDED_)
