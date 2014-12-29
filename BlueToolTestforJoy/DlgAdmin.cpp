// DlgAdmin.cpp : implementation file
//

#include "stdafx.h"
#include "BlueToolTestforJoy.h"
#include "DlgAdmin.h"
#include "NetConnection.h"

#include <string>

#include "./json/json.h"

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
	//}}AFX_DATA_INIT
	NetConnection::Instance()->connect_server();
}


void CDlgAdmin::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);

	//{{AFX_DATA_MAP(CDlgAdmin)
	DDX_Control(pDX, IDC_EDIT_TESTORNAME, m_testorname);
	DDX_Control(pDX, IDC_EDIT_PWD, m_pwd);
	DDX_Control(pDX, IDC_EDIT_COMFIRMPWD, m_comfirmpwd);
	DDX_Control(pDX, IDC_EDIT_ADMINPWD, m_adminpwd);
	DDX_Control(pDX, IDC_EDIT_ADMINNAME, m_adminname);
	DDX_Control(pDX, IDC_STATIC_ADDRESULT, m_label_addresult);
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
	std::string str;
//	NetConnection::Instance()->send_buf("{\"count\": 16,\"testor\": \"test1\",\"pwd\": \"test1'pwd1\"}",str,1002);
// 	NetConnection::Instance()->send_buf("{\"admin\": \"joysoftadmin\",\"adminpwd\": \"obasang\",\"testor\": \"testor's work id\",\"testorpwd\": \"pwd\"}",str,1001);
	CString stradminname;
	CString stradminpwd;
	CString strtestorname;
	CString strtestorpwd;
	CString strtestorcomfirmpwd;
	m_adminname.GetWindowText(stradminname);
	m_adminpwd.GetWindowText(stradminpwd);
	m_testorname.GetWindowText(strtestorname);
	m_comfirmpwd.GetWindowText(strtestorcomfirmpwd);
	m_pwd.GetWindowText(strtestorpwd);
	if (stradminname.IsEmpty()||stradminpwd.IsEmpty()||strtestorname.IsEmpty()||strtestorpwd.IsEmpty()||strtestorcomfirmpwd.IsEmpty())
	{
		m_label_addresult.SetWindowText("账号或密码不能有空");
	}else if (strtestorcomfirmpwd.Compare(strtestorpwd))
	{
		m_label_addresult.SetWindowText("确认密码不一致");
	}
	else{
		AfxBeginThread( AddTestorAccount , this );
	}

	
}

//UINT  CBlueToolTestforJoyDlg::thread_ProcessBurnFirm(LPVOID lpParam)
UINT CDlgAdmin::AddTestorAccount(LPVOID lpParam)
{
	CDlgAdmin *p_dlg = (CDlgAdmin *)lpParam;  
	CString stradminname;
	CString stradminpwd;
	CString strtestorname;
	CString strtestorpwd; 
	p_dlg->m_adminname.GetWindowText(stradminname);
	p_dlg->m_adminpwd.GetWindowText(stradminpwd);
	p_dlg->m_testorname.GetWindowText(strtestorname); 
	p_dlg->m_pwd.GetWindowText(strtestorpwd);
	CString sendbuf;
	sendbuf.Format("{\"admin\": \"%s\",\"adminpwd\": \"%s\",\"testor\": \"%s\",\"testorpwd\": \"pwd\"}", stradminname, stradminpwd, strtestorname, strtestorpwd);
//	p_dlg->m_label_addresult = "{\"admin\": \"joysoftadmin\",\"adminpwd\": \"obasang\",\"testor\": \"testor's work id\",\"testorpwd\": \"pwd\"}"
	std::string reqstr;
	NetConnection::Instance()->send_buf(sendbuf, reqstr, 1001);

 
// 	FILE * pf = fopen("E:\\log.txt","a+");
// 	if (pf)
// 	{
// 		fprintf(pf,"%s",strjson.c_str());
// 		fclose(pf);
// 	}
//	strjson="{\"result\": \"0\"}";
	
	std::string strjson(reqstr.c_str()+12 , reqstr.size() );

	Json::Reader reader;
	Json::Value value;
	bool bRet = reader.parse(strjson, value);
	if (false == bRet)
	{
	//	cerr << endl << "read value error \n";
		p_dlg->m_label_addresult.SetWindowText( "json formate error");
		return -1;
	}else{
		std::string str =  value["result"].asString();
		int jsonresult =0;
		if (jsonresult==0)
		{
			p_dlg->m_label_addresult.SetWindowText("账号添加成功");
		}else{
			p_dlg->m_label_addresult.SetWindowText("账号添加失败");
		}
		
	}
	
//	cout << value["name"].asString()<<endl;
//	cout << value["age"].asInt()<<endl;
//	cout << value["major"].asString()<<endl;

	return 0;
}
