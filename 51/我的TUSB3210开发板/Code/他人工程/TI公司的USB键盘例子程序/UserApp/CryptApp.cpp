//
// Copyright (c) 2004 Golden Bits Software, Inc.
// All rights reserved
//
//
// CryptApp.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include <objbase.h>
#include <wbemcli.h>
#include "CryptApp.h"
#include "CryptAppDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCryptAppApp

BEGIN_MESSAGE_MAP(CCryptAppApp, CWinApp)
	//{{AFX_MSG_MAP(CCryptAppApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCryptAppApp construction

CCryptAppApp::CCryptAppApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CCryptAppApp object

CCryptAppApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CCryptAppApp initialization

BOOL CCryptAppApp::InitInstance()
{
	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

	CoInitialize(NULL);

	HRESULT hr = CoInitializeSecurity(NULL /*sd*/, -1, NULL, NULL,
						RPC_C_AUTHN_LEVEL_NONE /*RPC_C_AUTHN_LEVEL_PKT*/, 
						RPC_C_IMP_LEVEL_IMPERSONATE, NULL, EOAC_NONE, NULL);


#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	CCryptAppDlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}

	// Uninitialize com
	CoUninitialize();

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}
