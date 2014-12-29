#if !defined(AFX_DLGADMIN_H__85F3A0F4_FC87_4056_BE8C_5B1DB7FC3FDD__INCLUDED_)
#define AFX_DLGADMIN_H__85F3A0F4_FC87_4056_BE8C_5B1DB7FC3FDD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgAdmin.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// DlgAdmin dialog

class DlgAdmin : public CDialog
{
// Construction
public:
	DlgAdmin(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DlgAdmin)
	enum { IDD = IDD_DIALOG_ADMIN };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DlgAdmin)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(DlgAdmin)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
// CDlgAdmin dialog

class CDlgAdmin : public CDialog
{
// Construction
public:
	CDlgAdmin(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgAdmin)
	enum { IDD = IDD_DIALOG_ADMIN };
	CEdit	m_testorname;
	CEdit	m_pwd;
	CEdit	m_comfirmpwd;
	CEdit	m_adminpwd;
	CEdit	m_adminname;
	CStatic	m_label_addresult;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgAdmin)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgAdmin)
	afx_msg void OnButtonAdd();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()


private:
	static UINT AddTestorAccount(LPVOID lpParam);



};
//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGADMIN_H__85F3A0F4_FC87_4056_BE8C_5B1DB7FC3FDD__INCLUDED_)
