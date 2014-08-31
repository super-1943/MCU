//
// Copyright (c) 2004 Golden Bits Software, Inc.
// All rights reserved
//
//
// CryptAppDlg.h : header file
//

#if !defined(AFX_CRYPTAPPDLG_H__AA5C3D59_0556_4A02_8D9F_7FB326936EC2__INCLUDED_)
#define AFX_CRYPTAPPDLG_H__AA5C3D59_0556_4A02_8D9F_7FB326936EC2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCryptAppDlg dialog

class CCryptAppDlg : public CDialog
{
// Construction
public:
	CCryptAppDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCryptAppDlg)
	enum { IDD = IDD_CRYPTAPP_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCryptAppDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

    CFile m_cUsbDevice;
    bool m_bDevOpen;
    DWORD m_dwCryptFunction;

    IWbemServices *m_pIWbemServices;

    void OpenUSBDevice();
    void EnableItem(int nDlgItem, BOOL bEnable);
    DWORD GetCryptFunction();
    void SetButtons();
    void GetDecryptBytes();
    HANDLE OpenCryptDevice(LPGUID pGuid, PCHAR pFullDevName);
    HANDLE OpenOneDevice(HDEVINFO HardwareDeviceInfo,
                         PSP_DEVICE_INTERFACE_DATA  DeviceInfoData,
                         char *devName);
    bool ConnectToWMI();



	// Generated message map functions
	//{{AFX_MSG(CCryptAppDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnEncrypt();
	afx_msg void OnDecrypt();
	afx_msg void OnSendData();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CRYPTAPPDLG_H__AA5C3D59_0556_4A02_8D9F_7FB326936EC2__INCLUDED_)
