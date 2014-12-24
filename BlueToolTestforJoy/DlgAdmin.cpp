// DlgAdmin.cpp : implementation file
//

#include "stdafx.h"
#include "BlueToolTestforJoy.h"
#include "DlgAdmin.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DlgAdmin dialog


DlgAdmin::DlgAdmin(CWnd* pParent /*=NULL*/)
	: CDialog(DlgAdmin::IDD, pParent)
{
	//{{AFX_DATA_INIT(DlgAdmin)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void DlgAdmin::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DlgAdmin)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DlgAdmin, CDialog)
	//{{AFX_MSG_MAP(DlgAdmin)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DlgAdmin message handlers
/////////////////////////////////////////////////////////////////////////////
// CDlgAdmin dialog


CDlgAdmin::CDlgAdmin(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgAdmin::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgAdmin)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDlgAdmin::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgAdmin)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgAdmin, CDialog)
	//{{AFX_MSG_MAP(CDlgAdmin)
	ON_BN_CLICKED(IDC_BUTTON_ADD, OnButtonAdd)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgAdmin message handlers

void CDlgAdmin::OnButtonAdd() 
{
	// TODO: Add your control notification handler code here
	
}
