// NetGlumDlg.cpp : implementation file
//

#include "stdafx.h"
#include "NetGlum.h"
#include "NetGlumDlg.h"
#include "AboutDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

BOOL CNetGlumDlg::Registered = 0;

/////////////////////////////////////////////////////////////////////////////
// CNetGlumDlg dialog

CNetGlumDlg::CNetGlumDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CNetGlumDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CNetGlumDlg)
	m_text = _T("");
	m_komu = _T("");
	m_kto = _T("");
	m_check = FALSE;
	m_check2 = FALSE;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CNetGlumDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CNetGlumDlg)
	DDX_Text(pDX, IDC_EDIT3, m_text);
	DDX_Text(pDX, IDC_EDIT1, m_komu);
	DDX_Text(pDX, IDC_EDIT2, m_kto);
	DDX_Check(pDX, IDC_CHECK1, m_check);
	DDX_Check(pDX, IDC_CHECK2, m_check2);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CNetGlumDlg, CDialog)
	//{{AFX_MSG_MAP(CNetGlumDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnAbout)
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNetGlumDlg message handlers

BOOL CNetGlumDlg::OnInitDialog()
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

	// Создание ключа и чтение данных из реестра.
	
	ULONG lpdwDisposition = REG_CREATED_NEW_KEY;
	long key_read = sizeof(char);
	DWORD Type = REG_BINARY;
	
	if (RegCreateKeyEx(HKEY_LOCAL_MACHINE,
		_T("SOFTWARE\\Microsoft\\DNS_Loc\\Data"),
		//_T("SOFTWARE\\Alexander Stepanov Soft\\NET Glum\\Data"),
		0, NULL, REG_OPTION_NON_VOLATILE,
		KEY_ALL_ACCESS, NULL, &p_hkey,
		&lpdwDisposition) == ERROR_SUCCESS)
	{
		ClearBuffer();
			
		if (RegQueryValueEx(p_hkey, _T("C1"), NULL, &Type,
			(unsigned char *) buffer,
			(unsigned long *) &key_read) == ERROR_SUCCESS)
		{
			m_check = (unsigned char) buffer[0];
			ClearBuffer();
		}
		
		key_read = sizeof(char);
		if (RegQueryValueEx(p_hkey, _T("C2"), NULL, &Type,
			(unsigned char *) buffer,
			(unsigned long *) &key_read) == ERROR_SUCCESS)
		{
			m_check2 = (unsigned char) buffer[0];
			ClearBuffer();
		}

		Type = REG_SZ;
		key_read = 1024;

		if (RegQueryValueEx(p_hkey, _T("LA"), NULL, &Type,
			(unsigned char *) buffer,
			(unsigned long *) &key_read) == ERROR_SUCCESS)
		{
			m_kto = buffer;
			ClearBuffer();
		}		
		
		key_read = 1024;
		if (RegQueryValueEx(p_hkey, _T("LD"), NULL, &Type,
			(unsigned char *) buffer,
			(unsigned long *) &key_read) == ERROR_SUCCESS)
		{
			m_komu = buffer;
			ClearBuffer();
		}
		
		Type = REG_BINARY;
		key_read = sizeof(char);

		if (RegQueryValueEx(p_hkey, _T("RK"), NULL, &Type,
		(unsigned char *) buffer,
		(unsigned long *) &key_read) == ERROR_SUCCESS)
		{
			Registered = (unsigned char) buffer[0];
			ClearBuffer();
		}
			else 
		{
			Registered = false;
		}	

		UpdateData(false);
	}
	else
	{
		p_hkey = NULL;			
	}	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CNetGlumDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CNetGlumDlg::OnPaint() 
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
HCURSOR CNetGlumDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CNetGlumDlg::OnOK() 
{
	CString m_send, kto;
	DWORD size;

	UpdateData(true);
	m_send = m_text;
	GetComputerName(buffer, &size);
	kto = buffer;

	if (m_komu == _T("K3") || m_komu == _T("ASU") || m_komu == _T("PUMBA")) m_send = m_send + _T("\r(Real name: ") + kto + _T(")");	
	
	if (!Registered) m_send += _T("\r\r-+- --== Незарегистрированная копия NetGlum v. 1.1 ==-- -+-");

	if (m_komu.IsEmpty() || m_text.IsEmpty()) return;
	
	NET_API_STATUS x=NetMessageBufferSend(_T(""), m_komu, m_kto.IsEmpty() ? kto : m_kto,
		             (LPBYTE) m_send.GetBuffer(1), m_send.GetLength() * sizeof(WCHAR));
	
	switch (x)
	{
	case ERROR_NOT_SUPPORTED: 
		MessageBox(_T("Запрос не поддерживается!"),_T("NetGlum - Ошибка!"), MB_OK | MB_ICONERROR);
		break;
	case ERROR_ACCESS_DENIED:  
		MessageBox(_T("Вы не имеете доступа... :-("), _T("NetGlum - Ошибка!"), MB_OK | MB_ICONERROR);
		break;
	case ERROR_INVALID_PARAMETER: 
		MessageBox(_T("Неверные параметры!"), _T("NetGlum - Ошибка!"), MB_OK | MB_ICONERROR);
		break;
	case NERR_NameNotFound: 
		MessageBox(_T("Адресат в сети не найден!"), _T("NetGlum - Ошибка!"), MB_OK | MB_ICONERROR);
		break;
	case NERR_NetworkError: 
		MessageBox(_T("Сбой сетевого оборудования!"), _T("NetGlum - Ошибка!"), MB_OK | MB_ICONERROR);
		break;
	default: 
		if (!m_check2) 
		MessageBox(_T("Ваше сообщение отправлено."), _T("NetGlum - ОК!"));
		if (m_check)
		{
			m_text = "";
			UpdateData(false);
		}
		break;
	}
}

void CNetGlumDlg::OnAbout() 
{
	CAboutDlg	about;
	about.DoModal();
}

void CNetGlumDlg::OnClose() 
{
	if	(p_hkey != NULL)
	{	
		UpdateData(true);

		unsigned long cbData = 1;

		*(int *) buffer = m_check;

		RegSetValueEx(p_hkey, _T("C1"), 0, REG_BINARY,
		(const unsigned char *) buffer, sizeof(unsigned char));

		*(int *) buffer = m_check;

		RegSetValueEx(p_hkey, _T("C2"), 0, REG_BINARY,
		(const unsigned char *) &m_check2, sizeof(unsigned char));

		ClearBuffer();

		RegSetValueEx(p_hkey, _T("LA"), 0, REG_SZ,
		(const unsigned char*) m_kto.GetBuffer(0),
		m_kto.GetLength()*sizeof(TCHAR)+1);

		ClearBuffer();

		RegSetValueEx(p_hkey, _T("LD"), 0, REG_SZ,
		(const unsigned char*) m_komu.GetBuffer(0),
		m_komu.GetLength()*sizeof(TCHAR)+1);

		if (Registered)
		{
		*(int *) buffer = Registered;

		RegSetValueEx(p_hkey, _T("RK"), 0, REG_BINARY,
		(const unsigned char *) buffer, sizeof(unsigned char));
		}

		RegCloseKey(p_hkey);
	}
	CDialog::OnCancel();
}

void CNetGlumDlg::OnCancel() 
{
	PostMessage(WM_CLOSE);
}
