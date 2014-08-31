//
// Copyright (c) 2004 Golden Bits Software, Inc.
// All rights reserved
//
//
// CryptAppDlg.cpp : implementation file
//


#include "stdafx.h"
#define INITGUID
#include <wbemcli.h>
#include "CryptApp.h"
#include "CryptAppDlg.h"
#include <Winioctl.h>

#include "..\Include\UsbCryptAppInc.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


DEFINE_GUID(CLSID_WbemLocator,
 0x4590f811, 0x1d3a, 0x11d0, 0x89, 0x1f,0x00, 0xaa, 0x00, 0x4b, 0x2e, 0x24 );

//
// Define the IID_IWbemLocator. It is defined in wbemcli.h only for C++ programs.
//

DEFINE_GUID(IID_IWbemLocator,
 0xdc12a687, 0x737f, 0x11cf, 0x88, 0x4d, 0x00, 0xaa, 0x00, 0x4b, 0x2e, 0x24 );


/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCryptAppDlg dialog

CCryptAppDlg::CCryptAppDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCryptAppDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCryptAppDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCryptAppDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCryptAppDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCryptAppDlg, CDialog)
	//{{AFX_MSG_MAP(CCryptAppDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ENCRYPT, OnEncrypt)
	ON_BN_CLICKED(IDC_DECRYPT, OnDecrypt)
	ON_BN_CLICKED(IDC_SEND_DATA, OnSendData)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCryptAppDlg message handlers

BOOL CCryptAppDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

    m_pIWbemServices = NULL;

    ConnectToWMI();
	
    // open handle to USB device
    OpenUSBDevice();

    SetButtons();

    if(m_bDevOpen)
        ConnectToWMI();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCryptAppDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CCryptAppDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CCryptAppDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}


void CCryptAppDlg::OpenUSBDevice()
{
  HANDLE hCryptDev;
  char szDevName[_MAX_PATH];


    hCryptDev = OpenCryptDevice((LPGUID)&GUID_CLASS_USBCRYPT, szDevName);

    if(hCryptDev == INVALID_HANDLE_VALUE)
    {
        AfxMessageBox("Failed to open USB device");
        m_bDevOpen = false;
        return;
    }

    // set file handle in CFile object
    m_cUsbDevice.m_hFile = (UINT)hCryptDev;

    m_bDevOpen = true;
}


HANDLE CCryptAppDlg::OpenCryptDevice(LPGUID pGuid, PCHAR pFullDevName)
{
   ULONG NumberDevices;
   HANDLE hOut = INVALID_HANDLE_VALUE;
   HDEVINFO                 hardwareDeviceInfo;
   SP_DEVICE_INTERFACE_DATA deviceInfoData;
   ULONG                    i;
   BOOLEAN                  done;


   NumberDevices = 0;

   //
   // Open a handle to the plug and play dev node.
   // SetupDiGetClassDevs() returns a device information set that contains info on all
   // installed devices of a specified class.
   //
   hardwareDeviceInfo = SetupDiGetClassDevs (
                           pGuid,
                           NULL, // Define no enumerator (global)
                           NULL, // Define no
                           (DIGCF_PRESENT | // Only Devices present
                            DIGCF_DEVICEINTERFACE)); // Function class devices.

   //
   // Take a wild guess at the number of devices we have;
   // Be prepared to realloc and retry if there are more than we guessed
   //
   NumberDevices = 4;
   done = FALSE;
   deviceInfoData.cbSize = sizeof (SP_DEVICE_INTERFACE_DATA);

   i=0;
   while (!done) 
   {

      for (i = 0; i < NumberDevices; i++) 
      {

         // SetupDiEnumDeviceInterfaces() returns information about device interfaces
         // exposed by one or more devices. Each call returns information about one interface;
         // the routine can be called repeatedly to get information about several interfaces
         // exposed by one or more devices.

         if (SetupDiEnumDeviceInterfaces (hardwareDeviceInfo,
                                         0, // We don't care about specific PDOs
                                         pGuid,
                                         i,
                                         &deviceInfoData)) {

            hOut = OpenOneDevice (hardwareDeviceInfo, &deviceInfoData, pFullDevName);

            if ( hOut != INVALID_HANDLE_VALUE ) 
            {
               done = TRUE;
               break;
            }
         } 
         else 
         {
            if (ERROR_NO_MORE_ITEMS == GetLastError()) 
            {
               done = TRUE;
               break;
            }
         }
      }
   }

   NumberDevices = i;

   // SetupDiDestroyDeviceInfoList() destroys a device information set
   // and frees all associated memory.
   SetupDiDestroyDeviceInfoList (hardwareDeviceInfo);

   return hOut;
}



HANDLE
CCryptAppDlg::OpenOneDevice(HDEVINFO HardwareDeviceInfo,
                            PSP_DEVICE_INTERFACE_DATA  DeviceInfoData,
                            char *devName)
{
    PSP_DEVICE_INTERFACE_DETAIL_DATA     functionClassDeviceData = NULL;
    ULONG  predictedLength = 0;
    ULONG  requiredLength = 0;
    HANDLE hOut = INVALID_HANDLE_VALUE;

    //
    // allocate a function class device data structure to receive the
    // goods about this particular device.
    //
    SetupDiGetDeviceInterfaceDetail (
            HardwareDeviceInfo,
            DeviceInfoData,
            NULL, // probing so no output buffer yet
            0, // probing so output buffer length of zero
            &requiredLength,
            NULL); // not interested in the specific dev-node


    predictedLength = requiredLength;
    // sizeof (SP_FNCLASS_DEVICE_DATA) + 512;

    functionClassDeviceData = (PSP_DEVICE_INTERFACE_DETAIL_DATA )malloc (predictedLength);
    functionClassDeviceData->cbSize = sizeof (SP_DEVICE_INTERFACE_DETAIL_DATA);

    //
    // Retrieve the information from Plug and Play.
    //
    if (! SetupDiGetDeviceInterfaceDetail (
               HardwareDeviceInfo,
               DeviceInfoData,
               functionClassDeviceData,
               predictedLength,
               &requiredLength,
               NULL)) 
    {
        free( functionClassDeviceData );
        return INVALID_HANDLE_VALUE;
    }

        strcpy( devName,functionClassDeviceData->DevicePath) ;

    hOut = CreateFile (
                  functionClassDeviceData->DevicePath,
                  GENERIC_READ | GENERIC_WRITE,
                  FILE_SHARE_READ | FILE_SHARE_WRITE,
                  NULL, // no SECURITY_ATTRIBUTES structure
                  OPEN_EXISTING, // No special create flags
                  0, // No special attributes
                  NULL); // No template file

    free( functionClassDeviceData );

    return hOut;
}





void CCryptAppDlg::SetButtons()
{
    if(!m_bDevOpen)
    {
        // disable everyting
        EnableItem(IDC_ENCRYPT, FALSE);
        EnableItem(IDC_DECRYPT, FALSE);
        EnableItem(IDC_SEND_DATA, FALSE);

        SetDlgItemText(IDC_APP_INFO, "Failed to open USB device");
        return;
    }

    // get type of funciton - encrypting or decrypting
    m_dwCryptFunction = GetCryptFunction();

    EnableItem(IDC_ENCRYPT, TRUE);
    EnableItem(IDC_DECRYPT, TRUE);

    if(m_dwCryptFunction == CRYPT_FUNCTION_ENCRYPTION)
    {
        SetDlgItemText(IDC_APP_INFO, "You are currently encrypting");
        CheckRadioButton(IDC_ENCRYPT, IDC_DECRYPT, IDC_ENCRYPT);
    }
    else
    {
        SetDlgItemText(IDC_APP_INFO, "You are currently decrypting");
        CheckRadioButton(IDC_ENCRYPT, IDC_DECRYPT, IDC_DECRYPT);
    }
}


DWORD CCryptAppDlg::GetCryptFunction()
{
  DWORD dwFuncType = 0;
  DWORD dwBytesReturned;


  ::DeviceIoControl((HANDLE)m_cUsbDevice.m_hFile, IOCTL_CRYPT_GET_FUNCTION, &dwFuncType, 
                    sizeof(DWORD), &dwFuncType, sizeof(dwFuncType),
                     &dwBytesReturned, NULL);

    return dwFuncType;
}


void CCryptAppDlg::EnableItem(int nDlgItem, BOOL bEnable)
{
  CWnd *pWnd;

    pWnd = GetDlgItem(nDlgItem);

    if(pWnd != NULL)
    {
        pWnd->EnableWindow(bEnable);
    }
}


void CCryptAppDlg::OnEncrypt() 
{
  BOOL bRetOK;
  DWORD dwBytesReturned;
  DWORD dwFuncType = CRYPT_FUNCTION_ENCRYPTION;

    bRetOK = DeviceIoControl((HANDLE)m_cUsbDevice.m_hFile, IOCTL_CRYPT_SET_FUNCTION, 
                              &dwFuncType, sizeof(DWORD), &dwFuncType, sizeof(dwFuncType),
                              &dwBytesReturned, NULL);

    if(bRetOK)
    {
        SetButtons();
    }
    else
    {
        AfxMessageBox("Failed to set encryption mode.");
    }
}

void CCryptAppDlg::OnDecrypt() 
{
  BOOL bRetOK;
  DWORD dwBytesReturned;
  DWORD dwFuncType = CRYPT_FUNCTION_DECRYPTION;


    bRetOK = DeviceIoControl((HANDLE)m_cUsbDevice.m_hFile, IOCTL_CRYPT_SET_FUNCTION, 
                             &dwFuncType, sizeof(DWORD), &dwFuncType, sizeof(dwFuncType),
                             &dwBytesReturned, NULL);

    if(bRetOK)
    {
        SetButtons();
    }
    else
    {
        AfxMessageBox("Failed to set decryption mode.");
    }
}

void CCryptAppDlg::OnSendData() 
{
  BYTE InputSampleData[20];
  BYTE OutputResults[20];

    // send simple 20 bytes of data
    memset(InputSampleData, 0x41, sizeof(InputSampleData));

    // write data
    m_cUsbDevice.Write(InputSampleData, sizeof(InputSampleData));

    // read back
    m_cUsbDevice.Read(OutputResults, sizeof(OutputResults));


    // if we're decrypting then get the number of bytes
    // decrypted
    if(m_dwCryptFunction == CRYPT_FUNCTION_DECRYPTION)
    {
        GetDecryptBytes();
    }
}



bool CCryptAppDlg::ConnectToWMI()
{
  IWbemLocator *pIWbemLocator = NULL;
  HRESULT hResult;
  BSTR NameSpace;
  CString csNameSpace;
  CString csPropNameDir, csProperty;
  

    hResult = CoCreateInstance(
                           CLSID_WbemLocator,
                           NULL,
                           CLSCTX_INPROC_SERVER,
                           IID_IWbemLocator,
                           (LPVOID *)&pIWbemLocator );

    if(!SUCCEEDED(hResult))
        return false;

    csNameSpace = "root\\WMI";
        //
        // Using the locator, connect to COM in the given namespace.
        //
    NameSpace = csNameSpace.AllocSysString();

    hResult = pIWbemLocator->ConnectServer(NameSpace, 
                        NULL,   // NULL means current account, for simplicity.
                        NULL,   // NULL means current password, for simplicity.
                        0L,     // locale
                        0L,     // securityFlags
                        NULL,   // authority (domain for NTLM)
                        NULL,   // context
                        &m_pIWbemServices ); // Returned IWbemServices.




    if(hResult == WBEM_S_NO_ERROR) 
    {
           //
           // Switch the security level to IMPERSONATE so that provider(s)
           // will grant access to system-level objects, and so that
           // CALL authorization will be used.
           //

           hResult = CoSetProxyBlanket(
                            (IUnknown *)m_pIWbemServices, // proxy
                            RPC_C_AUTHN_WINNT,        // authentication service
                            RPC_C_AUTHZ_NONE,         // authorization service
                            NULL,                     // server principle name
                            RPC_C_AUTHN_LEVEL_CALL,   // authentication level
                            RPC_C_IMP_LEVEL_IMPERSONATE, // impersonation level
                            NULL,                     // identity of the client
                            0 );                      // capability flags

    }


    return SUCCEEDED(hResult) ? true : false;
}



void CCryptAppDlg::GetDecryptBytes()
{
  HRESULT hResult;
  VARIANTARG vtProgressBytesVal;
  IEnumWbemClassObject *pEnumWbeObj;
  IWbemClassObject *pIWbemClassObj;
  CString csPropNameDir;
  ULONG ulNumReturned;
  CIMTYPE CimType = 0;
  LONG Flavor = 0;


    if(m_pIWbemServices == NULL)
        return;

    VariantInit(&vtProgressBytesVal);

        // now get pointer to enumerator, to enumerate
    // through classes
    csPropNameDir = "USBCryptInformation";  //"MSNdis";  //


    hResult = m_pIWbemServices->CreateInstanceEnum(csPropNameDir.AllocSysString(),
                                            WBEM_FLAG_DIRECT_READ,
                                            NULL, &pEnumWbeObj);

    if(!SUCCEEDED(hResult))
        return;

    // we'll just enum the first instance
    ulNumReturned = 0;
    hResult = pEnumWbeObj->Next(2000, 1, &pIWbemClassObj,
                                &ulNumReturned);

    if(!SUCCEEDED(hResult) || ulNumReturned == 0)
        return;



    hResult = pIWbemClassObj->Get(L"DecryptByteCount",  0, &vtProgressBytesVal,
                                    &CimType, &Flavor);

    if(SUCCEEDED(hResult))
    {
        SetDlgItemInt(IDC_PROGRESS, vtProgressBytesVal.ulVal, FALSE);
        //AfxMessageBox("Got decrypt byte count!!");
    }

    // release references
    pIWbemClassObj->Release();
    pEnumWbeObj->Release();


#ifdef _DEBUG
    if(!SUCCEEDED(hResult))
        AfxMessageBox("ERROR, failed to get decryption byte progress");
#endif
}




