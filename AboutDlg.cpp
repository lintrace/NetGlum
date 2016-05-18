// AboutDlg.cpp : implementation file
//

#include "stdafx.h"
#include "NetGlum.h"
#include "NetGlumDlg.h"
#include "AboutDlg.h"
#include "Register.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog


CAboutDlg::CAboutDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAboutDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}


void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	DDX_Control(pDX, IDC_BREG, m_breg);
	DDX_Control(pDX, IDC_LIST1, m_reginfo);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
	ON_BN_CLICKED(IDC_BREG, OnBreg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg message handlers

BOOL CAboutDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	if (!CNetGlumDlg::Registered)
	{
		m_reginfo.ResetContent();
		m_reginfo.AddString(_T("НЕЗАРЕГИСТРИРОВАННАЯ КОПИЯ!"));
		m_reginfo.AddString(_T("Стоимость регистрации - 1 бут. \"Дизеля\""));
		m_reginfo.AddString(_T("Поддержим отечественного производителя! ;-)"));
	}
	else
	{
		m_reginfo.ResetContent();
		m_reginfo.AddString(_T("Спасибо за регистрацию!"));

		GetDlgItem(IDC_BREG) -> EnableWindow(FALSE);
	}

	UpdateData(false);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CAboutDlg::OnBreg() 
{
	CRegister reg;
	reg.DoModal();
	PostMessage(WM_CLOSE);
}
