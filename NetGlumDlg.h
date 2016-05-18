// NetGlumDlg.h : header file
//

#if !defined(AFX_NETGLUMDLG_H__B17A89DE_D32C_45E5_8328_D8E72032354F__INCLUDED_)
#define AFX_NETGLUMDLG_H__B17A89DE_D32C_45E5_8328_D8E72032354F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CNetGlumDlg dialog

class CNetGlumDlg : public CDialog
{
// Construction
public:
	CNetGlumDlg(CWnd* pParent = NULL);	// standard constructor

	static BOOL Registered;

// Dialog Data
	//{{AFX_DATA(CNetGlumDlg)
	enum { IDD = IDD_NETGLUM_DIALOG };
	CString	m_text;
	CString	m_komu;
	CString	m_kto;
	BOOL	m_check;
	BOOL	m_check2;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNetGlumDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	HKEY p_hkey;
	TCHAR buffer[1024];	

	void ClearBuffer(void)
	{
		for (int i=0; i<1024; i++)
		{
			buffer[i] = 0;
		}
	}

	// Generated message map functions
	//{{AFX_MSG(CNetGlumDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg void OnAbout();
	afx_msg void OnClose();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NETGLUMDLG_H__B17A89DE_D32C_45E5_8328_D8E72032354F__INCLUDED_)
