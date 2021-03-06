// BlueToolTestforJoyDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BlueToolTestforJoy.h"
#include "BlueToolTestforJoyDlg.h"
#include "DlgAdmin.h"
#include "NetConnection.h"
#include "./json/json.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
class DlgAdmin;
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
	afx_msg void OnBtnGotoadmin();
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
	ON_BN_CLICKED(ID_BTN_GOTOADMIN, OnBtnGotoadmin)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBlueToolTestforJoyDlg dialog

CBlueToolTestforJoyDlg::CBlueToolTestforJoyDlg(CWnd* pParent /*=NULL*/)
: CDialog(CBlueToolTestforJoyDlg::IDD, pParent)
{

	
	
	


	m_manager = DBManager();
// 	if (m_manager.InitConnection())
// 	{
// 		
// 	}
	m_lines=0;
	m_hardcheckindex=0;
	//{{AFX_DATA_INIT(CBlueToolTestforJoyDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CBlueToolTestforJoyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBlueToolTestforJoyDlg)
	DDX_Control(pDX, IDC_EDIT_PWD, m_testorpwd);
	DDX_Control(pDX, IDC_EDIT_TESTORID, m_testorid);
	DDX_Control(pDX, IDC_STATIC_RESULT9, m_label_result9);
	DDX_Control(pDX, IDC_STATIC_RESULT8, m_label_result8);
	DDX_Control(pDX, IDC_STATIC_RESULT7, m_label_result7);
	DDX_Control(pDX, IDC_STATIC_RESULT6, m_label_result6);
	DDX_Control(pDX, IDC_STATIC_RESULT5, m_label_result5);
	DDX_Control(pDX, IDC_STATIC_RESULT4, m_label_result4);
	DDX_Control(pDX, IDC_STATIC_RESULT3, m_label_result3);
	DDX_Control(pDX, IDC_STATIC_RESULT2, m_label_result2);
	DDX_Control(pDX, IDC_STATIC_RESULT16, m_label_result16);
	DDX_Control(pDX, IDC_STATIC_RESULT15, m_label_result15);
	DDX_Control(pDX, IDC_STATIC_RESULT14, m_label_result14);
	DDX_Control(pDX, IDC_STATIC_RESULT13, m_label_result13);
	DDX_Control(pDX, IDC_STATIC_RESULT12, m_label_result12);
	DDX_Control(pDX, IDC_STATIC_RESULT11, m_label_result11);
	DDX_Control(pDX, IDC_STATIC_RESULT10, m_label_result10);
	DDX_Control(pDX, IDC_STATIC_RESULT1, m_label_result1);
	DDX_Control(pDX, IDC_EDIT_CVC14, m_edit_cvc14);
	DDX_Control(pDX, IDC_EDIT_CVC9, m_edit_cvc9);
	DDX_Control(pDX, IDC_EDIT_CVC8, m_edit_cvc8);
	DDX_Control(pDX, IDC_EDIT_CVC7, m_edit_cvc7);
	DDX_Control(pDX, IDC_EDIT_CVC6, m_edit_cvc6);
	DDX_Control(pDX, IDC_EDIT_CVC5, m_edit_cvc5);
	DDX_Control(pDX, IDC_EDIT_CVC4, m_edit_cvc4);
	DDX_Control(pDX, IDC_EDIT_CVC3, m_edit_cvc3);
	DDX_Control(pDX, IDC_EDIT_CVC2, m_edit_cvc2);
	DDX_Control(pDX, IDC_EDIT_CVC16, m_edit_cvc16);
	DDX_Control(pDX, IDC_EDIT_CVC15, m_edit_cvc15);
	DDX_Control(pDX, IDC_EDIT_CVC13, m_edit_cvc13);
	DDX_Control(pDX, IDC_EDIT_CVC12, m_edit_cvc12);
	DDX_Control(pDX, IDC_EDIT_CVC11, m_edit_cvc11);
	DDX_Control(pDX, IDC_EDIT_CVC10, m_edit_cvc10);
	DDX_Control(pDX, IDC_EDIT_CVC1, m_edit_cvc1);
	DDX_Control(pDX, IDC_EDIT_DID9, m_edit_did9);
	DDX_Control(pDX, IDC_EDIT_DID8, m_edit_did8);
	DDX_Control(pDX, IDC_EDIT_DID7, m_edit_did7);
	DDX_Control(pDX, IDC_EDIT_DID5, m_edit_did5);
	DDX_Control(pDX, IDC_EDIT_DID6, m_edit_did6);
	DDX_Control(pDX, IDC_EDIT_DID4, m_edit_did4);
	DDX_Control(pDX, IDC_EDIT_DID3, m_edit_did3);
	DDX_Control(pDX, IDC_EDIT_DID2, m_edit_did2);
	DDX_Control(pDX, IDC_EDIT_DID16, m_edit_did16);
	DDX_Control(pDX, IDC_EDIT_DID15, m_edit_did15);
	DDX_Control(pDX, IDC_EDIT_DID14, m_edit_did14);
	DDX_Control(pDX, IDC_EDIT_DID13, m_edit_did13);
	DDX_Control(pDX, IDC_EDIT_DID12, m_edit_did12);
	DDX_Control(pDX, IDC_EDIT_DID11, m_edit_did11);
	DDX_Control(pDX, IDC_EDIT_DID10, m_edit_did10);
	DDX_Control(pDX, IDC_EDIT_DID1, m_edit_did1);
	DDX_Control(pDX, IDC_EDIT_BD_ADDR9, m_edit_macaddr9);
	DDX_Control(pDX, IDC_EDIT_BD_ADDR8, m_edit_macaddr8);
	DDX_Control(pDX, IDC_EDIT_BD_ADDR7, m_edit_macaddr7);
	DDX_Control(pDX, IDC_EDIT_BD_ADDR6, m_edit_macaddr6);
	DDX_Control(pDX, IDC_EDIT_BD_ADDR5, m_edit_macaddr5);
	DDX_Control(pDX, IDC_EDIT_BD_ADDR4, m_edit_macaddr4);
	DDX_Control(pDX, IDC_EDIT_BD_ADDR3, m_edit_macaddr3);
	DDX_Control(pDX, IDC_EDIT_BD_ADDR2, m_edit_macaddr2);
	DDX_Control(pDX, IDC_EDIT_BD_ADDR16, m_edit_macaddr16);
	DDX_Control(pDX, IDC_EDIT_BD_ADDR15, m_edit_macaddr15);
	DDX_Control(pDX, IDC_EDIT_BD_ADDR14, m_edit_macaddr14);
	DDX_Control(pDX, IDC_EDIT_BD_ADDR13, m_edit_macaddr13);
	DDX_Control(pDX, IDC_EDIT_BD_ADDR12, m_edit_macaddr12);
	DDX_Control(pDX, IDC_EDIT_BD_ADDR10, m_edit_macaddr10);
	DDX_Control(pDX, IDC_EDIT_BD_ADDR11, m_edit_macaddr11);
	DDX_Control(pDX, IDC_EDIT_BD_ADDR1, m_edit_macaddr1);
	DDX_Control(pDX, IDC_CHECK9, m_ckport9);
	DDX_Control(pDX, IDC_CHECK8, m_ckport8);
	DDX_Control(pDX, IDC_CHECK7, m_ckport7);
	DDX_Control(pDX, IDC_CHECK6, m_ckport6);
	DDX_Control(pDX, IDC_CHECK5, m_ckport5);
	DDX_Control(pDX, IDC_CHECK4, m_ckport4);
	DDX_Control(pDX, IDC_CHECK3, m_ckport3);
	DDX_Control(pDX, IDC_CHECK2, m_ckport2);
	DDX_Control(pDX, IDC_CHECK16, m_ckport16);
	DDX_Control(pDX, IDC_CHECK15, m_ckport15);
	DDX_Control(pDX, IDC_CHECK14, m_ckport14);
	DDX_Control(pDX, IDC_CHECK13, m_ckport13);
	DDX_Control(pDX, IDC_CHECK11, m_ckport11);
	DDX_Control(pDX, IDC_CHECK12, m_ckport12);
	DDX_Control(pDX, IDC_CHECK10, m_ckport10);
	DDX_Control(pDX, IDC_CHECK1, m_ckport1);
	DDX_Control(pDX, IDC_EDIT_GLOBAL_NAME, m_edit_global_burnname);
	DDX_Control(pDX, IDC_EDIT_GLOBAL_FILE, m_edit_global_burnfile);
	DDX_Control(pDX, ID_TEST_DO, m_test_do);
	DDX_Control(pDX, ID_CANCEL, m_btncancel);
	DDX_Control(pDX, IDC_RICHEDIT_OUTINFO, m_redit_outinfo);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CBlueToolTestforJoyDlg, CDialog)
	//{{AFX_MSG_MAP(CBlueToolTestforJoyDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(ID_TEST_DO, OnTestDo)
	ON_WM_SIZE()
	ON_BN_CLICKED(IDC_BUTTON_BURN, OnButtonBurn)
	ON_MESSAGE(WM_UPDATEINFO , ui_callback)
	ON_BN_CLICKED(IDC_BUTTON_DETECTDEVICE, OnButtonDetectdevice)
	ON_BN_CLICKED(IDC_BUTTON_WRITECHECK, OnButtonWritecheck)
	ON_BN_CLICKED(IDC_BUTTON_NEXTDC, OnButtonNextdc)
	ON_BN_CLICKED(IDC_BUTTON_FORMER, OnButtonFormer)
	ON_BN_CLICKED(IDC_BUTTON_HARDBTNALL, OnButtonHardbtnall)
	ON_BN_CLICKED(IDC_BUTTON_HARDBTN1, OnButtonHardbtn1)
	ON_BN_CLICKED(IDC_BUTTON_HARDBTN2, OnButtonHardbtn2)
	ON_BN_CLICKED(IDC_BUTTON_HARDBTN3, OnButtonHardbtn3)
	ON_BN_CLICKED(IDC_BUTTON_CALL, OnButtonCall)
	ON_BN_CLICKED(IDC_BUTTON_HARDBTNBEGIN, OnButtonHardbtnbegin)
	ON_BN_CLICKED(IDC_BUTTON_REQMACCVC, OnButtonReqmaccvc)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBlueToolTestforJoyDlg message handlers

BOOL CBlueToolTestforJoyDlg::OnInitDialog()
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
	 

	InitCtrl();


	if (m_manager.InitConnection())
	{
		
	}
	else
	{
		AppendTestInfo("数据库异常");
	}

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CBlueToolTestforJoyDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CBlueToolTestforJoyDlg::OnPaint() 
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
HCURSOR CBlueToolTestforJoyDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}


void CBlueToolTestforJoyDlg::OnTestDo() 
{
	// TODO: Add your control notification handler code here
//	SingleBurn(0);
	
	for (std::vector<BD_Item>::iterator itr= m_itemlists.begin(); itr!=m_itemlists.end(); itr++)
	{ 
		if (itr->isAllPass())
		{
			m_manager.Update_KeyCvc(itr->getCVC().c_str()) ;
			m_manager.Update_KeyMac(itr->getMac().c_str()) ;
			m_manager.InsertDevice(*itr) ;
			AfxBeginThread(TurnIndexedLightOff , (LPVOID) atoi( itr->getPort().c_str() )  );
		}
		else
		{
			AfxBeginThread( TurnIndexedLightOnForever , (LPVOID) atoi( itr->getPort().c_str() ) ) ; 
		}
		switch(itr - m_itemlists.begin())
		{
			case 0:
				if (itr->isAllPass())
				{
					m_label_result1.SetWindowText(ALL_PASSED);
				}
				else
				{ 
					m_label_result1.SetWindowText(itr->getLastError().c_str());
				}	
				break;
			case 1:
				if (itr->isAllPass())
				{
					m_label_result2.SetWindowText(ALL_PASSED);
				}
				else
				{
					m_label_result2.SetWindowText(itr->getLastError().c_str());
				}	
				break;
			case 2:
				if (itr->isAllPass())
				{
					m_label_result3.SetWindowText(ALL_PASSED);
				}
				else
				{
					m_label_result3.SetWindowText(itr->getLastError().c_str());
				}	
				break;
			case 3:
				if (itr->isAllPass())
				{
					m_label_result4.SetWindowText(ALL_PASSED);
				}
				else
				{
					m_label_result4.SetWindowText(itr->getLastError().c_str());
				}	
				break;
			case 4:
				if (itr->isAllPass())
				{
					m_label_result5.SetWindowText(ALL_PASSED);
				}
				else
				{
					m_label_result5.SetWindowText(itr->getLastError().c_str());
				}	
				break;
			case 5:
				if (itr->isAllPass())
				{
					m_label_result6.SetWindowText(ALL_PASSED);
				}
				else
				{
					m_label_result6.SetWindowText(itr->getLastError().c_str());
				}	
				break;
			case 6:
				if (itr->isAllPass())
				{
					m_label_result7.SetWindowText(ALL_PASSED);
				}
				else
				{
					m_label_result7.SetWindowText(itr->getLastError().c_str());
				}	
				break;
			case 7:
				if (itr->isAllPass())
				{
					m_label_result8.SetWindowText(ALL_PASSED);
				}
				else
				{
					m_label_result8.SetWindowText(itr->getLastError().c_str());
				}	
				break;
			case 8:
				if (itr->isAllPass())
				{
					m_label_result9.SetWindowText(ALL_PASSED);
				}
				else
				{
					m_label_result9.SetWindowText(itr->getLastError().c_str());
				}	
				break;
			case 9:
				if (itr->isAllPass())
				{
					m_label_result10.SetWindowText(ALL_PASSED);
				}
				else
				{
					m_label_result10.SetWindowText(itr->getLastError().c_str());
				}	
				break;
			case 10:
				if (itr->isAllPass())
				{
					m_label_result11.SetWindowText(ALL_PASSED);
				}
				else
				{
					m_label_result11.SetWindowText(itr->getLastError().c_str());
				}	
				break;
			case 11:
				if (itr->isAllPass())
				{
					m_label_result12.SetWindowText(ALL_PASSED);
				}
				else
				{
					m_label_result12.SetWindowText(itr->getLastError().c_str());
				}	
				break;
			case 12:
				if (itr->isAllPass())
				{
					m_label_result13.SetWindowText(ALL_PASSED);
				}
				else
				{
					m_label_result13.SetWindowText(itr->getLastError().c_str());
				}	
				break;
			case 13:
				if (itr->isAllPass())
				{
					m_label_result14.SetWindowText(ALL_PASSED);
				}
				else
				{
					m_label_result14.SetWindowText(itr->getLastError().c_str());
				}	
				break;
			case 14:
				if (itr->isAllPass())
				{
					m_label_result15.SetWindowText(ALL_PASSED);
				}
				else
				{
					m_label_result15.SetWindowText(itr->getLastError().c_str());
				}	
				break;
			case 15:
				if (itr->isAllPass())
				{
					m_label_result16.SetWindowText(ALL_PASSED);
				}
				else
				{
					m_label_result16.SetWindowText(itr->getLastError().c_str());
				}	
				break;

			default:
				break;
		} 
	}


#ifdef DEBUG

	CString strinfo;
//	getHandle(strinfo); 
	if (m_lines++%2)
	{
		CHARFORMAT cf;
		ZeroMemory(&cf, sizeof(CHARFORMAT));
		cf.cbSize = sizeof(CHARFORMAT);
		cf.dwMask = CFM_BOLD | CFM_COLOR | CFM_FACE |
			CFM_ITALIC | CFM_SIZE | CFM_UNDERLINE;
		cf.dwEffects = 0;
		cf.yHeight = 12*12;//文字高度
		cf.crTextColor = RGB(200, 100, 255); //文字颜色
		strcpy(cf.szFaceName ,_T("隶书"));//设置字体
		m_redit_outinfo.SetSel(-1, -1);  
		m_redit_outinfo.SetSelectionCharFormat(cf);
	}
	
	
	CString str="新的一行\r\n"; 
	m_redit_outinfo.SetSel(-1, -1); 
    m_redit_outinfo.ReplaceSel(str); 
#endif

	
}

void CBlueToolTestforJoyDlg::OnSize(UINT nType, int cx, int cy) 
{
	CDialog::OnSize(nType, cx, cy);
 
}


void CBlueToolTestforJoyDlg::AppendTestInfo(CString strInfo,BOOL b_color)
{
	
	if (b_color)
	{
		CHARFORMAT cf;
		ZeroMemory(&cf, sizeof(CHARFORMAT));
		cf.cbSize = sizeof(CHARFORMAT);
		cf.dwMask = CFM_BOLD | CFM_COLOR | CFM_FACE |
			CFM_ITALIC | CFM_SIZE | CFM_UNDERLINE;
		cf.dwEffects = 0;
		cf.yHeight = 14*14;//文字高度
		cf.crTextColor = RGB(255, 50, 20); //文字颜色
		//strcpy(cf.szFaceName ,_T("隶书"));//设置字体
		m_redit_outinfo.SetSel(-1, -1); 
		//	m_redit_outinfo.SetSel(1, 5); //设置处理区域
		m_redit_outinfo.SetSelectionCharFormat(cf);
	}
//	CString str="新的一行\r\n"; 
	m_redit_outinfo.SetSel(-1, -1); 
    m_redit_outinfo.ReplaceSel(strInfo); 

}






//字符串分割函数，参考boost::split
std::vector<std::string> CBlueToolTestforJoyDlg::split(std::string str,std::string pattern)
{
    std::string::size_type pos;
    std::vector<std::string> result;
    str+=pattern;//扩展字符串以方便操作
    int size=str.size();
	
    for(int i=0; i<size; i++)
    {
        pos=str.find(pattern,i);
        if(pos<size)
        {
            std::string s=str.substr(i,pos-i);
            result.push_back(s);
            i=pos+pattern.size()-1;
        }
    }
	
	
    return result;
}





//解析括号
void CBlueToolTestforJoyDlg::parseBrackets(std::vector<std::string> &vt)
{
	
	for (std::vector<string>::iterator itr=vt.begin() ; itr!=vt.end() ; itr++ )
	{
		int pos=(*itr).find("(");
		*itr=(*itr).substr(pos+1,(*itr).size());
		
		pos=(*itr).find(")");
		*itr=(*itr).substr(0,pos);
		
	}
}


 





UINT  CBlueToolTestforJoyDlg::thread_ProcessBurnFirm(LPVOID lpParam)
{
	
	
	int ret=0;
	uint32 iHandle(0);
	CString tempinfo;
	CBlueToolTestforJoyDlg *p_dlg = (CBlueToolTestforJoyDlg *)lpParam;  
	
	//多路烧录文件。
	bitset<16> bitvec;  //32 bits,all zero
	for(int loop_bs=0 ; loop_bs<p_dlg->m_ports.size() ; loop_bs++ )
	{
		bitvec.set(loop_bs);
	}
	
	int devMask=bitvec.to_ulong();
	if(flmOpen(devMask, 26, TFL_SPI_USB) != TFL_OK)
    {
        //std::cout << "Failed to open devices (" << flmGetBitErrorField() << ")" << std::endl;
		tempinfo.Format("打开设备%s失败%d \r\n" , bitvec.to_string().c_str() , flmGetBitErrorField() );
		p_dlg->AppendTestInfo( tempinfo , TRUE );
		return -1;
    }
	
    if(flmReadProgramFiles("xpv\\merge.xpv") != TFL_OK)
    {
        //std::cout << "Failed to read flash program files" << std::endl;
		tempinfo.Format("读取烧录文件失败\r\n"  );
		p_dlg->AppendTestInfo( tempinfo , TRUE);
        flmClose(devMask);
		return -1;
    }
	
    if(flmProgramSpawn(devMask, 0, 0, 0) != TFL_OK)
    {
        //std::cout << "Failed to spawn flash program thread" << std::endl;
		tempinfo.Format("烧录程序到设备失败\r\n"  );
		p_dlg->AppendTestInfo( tempinfo , TRUE);
        flmClose(devMask);
		return -1;
    } 

	
	
    uint16 devicesRunning;
    int32 progress;
    do
    {
        devicesRunning = 0;
        for(uint32 devIndex = 0; devIndex < TFL_MAX_DEVICES; ++devIndex)
        {
            //Only check the progress if the device is in the mask
            if((devMask >> devIndex) & 1)
            {
                progress = flmGetDeviceProgress(devIndex);
                if(progress < 100)
                {
                    ++devicesRunning;
                }
				
				//更新ui
				tempinfo.Format("设备编号=%d 进度= %d\r\n" , devIndex , progress );
				p_dlg->AppendTestInfo(tempinfo); 
				
            }
        }
        Sleep(1000);
    }
    while(devicesRunning > 0);
	
    int32 error = flmGetLastError();
    if(error != TFL_OK)
    {
        
		tempinfo.Format("烧录程序失败:%d 设备掩码=%d \r\n" , error , flmGetBitErrorField() );
		p_dlg->AppendTestInfo( tempinfo , TRUE);
        flmClose(devMask);
    } 
	
	tempinfo.Format("烧录成功,执行合并配置文件...\r\n"  );
	p_dlg->AppendTestInfo( tempinfo );
	
    flmClose(devMask);
	
	//合并文件。
//	for(std::vector<std::string>::iterator itr1=p_dlg->m_ports.begin();itr1!=p_dlg->m_ports.end();itr1++)
	for(std::vector<BD_Item>::iterator itr1=p_dlg->m_itemlists.begin();itr1!=p_dlg->m_itemlists.end();itr1++)
	{
		int ret=0;
		iHandle = openTestEngineSpi(atoi((*itr1).getPort().c_str()), 0, SPI_USB );
	
		if (iHandle)
		{
			if(	psMergeFromFile( iHandle , "xpv\\sink_config_10001v4_stereo.psr" ) ==1)
			{
				itr1->isMergeConfigFileSucced = true ; 
				tempinfo.Format("%s设备成功合并配置文件\r\n" , (*itr1).getPort().c_str() ); 
				p_dlg->AppendTestInfo(tempinfo);
			}
			else
			{
				//std::cout<<"ps merge sink_config_10001v4_stereo.psr failed "<<std::endl;
				//itr1->isMergeConfigFileSucced = false ;
				tempinfo.Format("%s设备合并失败配置文件\r\n", (*itr1).getPort().c_str());
				p_dlg->AppendTestInfo(tempinfo, TRUE);
			}
			
			if(	psMergeFromFile( iHandle , "xpv\\sink_system_csr8670.psr" ) ==1)
			{
				//std::cout<<"ps merge sink_system_csr8670.psr all right "<<std::endl;
				itr1->isMergeSystemFileSucced = true ;
				tempinfo.Format("%s设备成功合并系统文件\r\n" , (*itr1).getPort().c_str() );
				p_dlg->AppendTestInfo(tempinfo);
			}
			else
			{ 
				tempinfo.Format("%s设备合并系统文件失败\r\n" , (*itr1).getPort().c_str());
				p_dlg->AppendTestInfo( tempinfo ,TRUE );
			}  
		
			closeTestEngine(iHandle);
		}
		else
		{
			tempinfo.Format("%s设备执行合并打开设备失败\r\n" , (*itr1).getPort().c_str() );
			p_dlg->AppendTestInfo( tempinfo,true  );
		}
		
		
	}
	
    flmClose(devMask);
	

	
	tempinfo.Format("烧录文件执行结束\r\n\r\n" );
	p_dlg->AppendTestInfo( tempinfo );

	return 0;
}

 

void CBlueToolTestforJoyDlg::OnButtonBurn() 
{
	// TODO: Add your control notification handler code here
  	AfxBeginThread( thread_ProcessBurnFirm , this );
}


LRESULT CBlueToolTestforJoyDlg::ui_callback(WPARAM,LPARAM)
{
	AfxMessageBox("...");
	return 0;
}


void CBlueToolTestforJoyDlg::readCVC(std::vector<std::string> &lst,int count)
{
	int retVal = 0; 
	retVal = m_manager.Read_CVC( count , lst ) ;
	if (!retVal)
	{
		AppendTestInfo("cvc耗尽" , true );
	}
	else if( retVal !=count )
	{
		AppendTestInfo("cvc编号不足" , true );
	}

// 	while(count--){ 
// 		lst.push_back("111111");//push_back("3465 A979 BC24 C86D 01FF");
// 	}
}


void CBlueToolTestforJoyDlg::readMAC(std::vector<std::string> &lst,int count)
{
	int retVal = 0 ;
	retVal = m_manager.Read_MAC( count , lst ) ;
	if (!retVal)
	{
		AppendTestInfo("mac耗尽",true ) ;
	}
	else if (retVal != count)
	{
		AppendTestInfo("mac地址不足", true );
	}
// 	while(count--){
// 		lst.push_back("123456789"); 
// 	}
}




/*
准备阶段，需要读取mac和cvc字段。如果其中有内容，则有两种可能：
其一，烧录了mac和cvc，但是按键测试和其他测试没有通过。
	此时对应某测试电脑的本地数据库肯定是没有这个mac和cvc匹配的记录。
	此时可以烧录
其二，已经烧录过，且其他测试均通过。已经将烧录设备的结果写回了数据库。
	此时不可以再烧录。
*/
/*bool CBlueToolTestforJoyDlg::isDeviceBurned()
{
	for (std::vector<std::string>::iterator itr = m_ports.begin();
		itr!=m_ports.end();
		itr++
	)
	{
		
	}
}
*/

void CBlueToolTestforJoyDlg::OnButtonDetectdevice() 
{
	// TODO: Add your control notification handler code here
	
	clearStatus(); 
	
	CString strfile,strname; 
	m_edit_global_burnfile.GetWindowText(strfile); 
	m_edit_global_burnname.GetWindowText(strname);
	
	if (strfile.IsEmpty()&&strname.IsEmpty())
	{
		MessageBox("请设置烧录文件和设备名称");
		return;
	}

	uint32 iHandle(0);
	uint16 maxLen(256);
	uint16 count(0);
	char* portsStr = new char[maxLen];
	char* transStr = new char[maxLen]; 
	
 
	
	memset(portsStr,0,maxLen);

	int32 status = teGetAvailableSpiPorts(&maxLen, portsStr, transStr, &count);
	
	if( status != TE_OK && maxLen != 0 )
	{
		// Not enough space - resize the storage
		portsStr = new char[maxLen];
		transStr = new char[maxLen];
		status = teGetAvailableSpiPorts(&maxLen, portsStr, transStr, &count);
		
	}
	if( status != TE_OK || count == 0 )
	{ 
		if (portsStr)
		{
			delete[] portsStr;
			portsStr=NULL;
		}
		if (transStr)
		{
			delete[] transStr; 
			transStr=NULL;
		}
		AppendTestInfo("打开设备失败\r\n",true);
		return  ;
	} 
	
	// Split up the comma separated strings of ports / transport options
	m_ports=split( string(portsStr), string(",")); // Use these for user selection (e.g. drop down list)
	m_trans=split(string(transStr), string(",")); // Use these to open a transport
	
	//解析去掉括号	(600895)--->600895
	parseBrackets(m_ports);
	
	

	//检查设备是否有烧录过？如果是，停止分配mac和cvc。



	//读取蓝牙mac地址。到一个vector，读取一个cvc列表到List
	readCVC(m_cvc,m_ports.size());
	
	//读取蓝牙设备的Mac地址到list
	readMAC(m_mac,m_ports.size());

	
	

	if (CheckConnection())
	{
		return ;
	}
	
	
	//初始化m_lists 
	std::vector<std::string>::iterator macitr=m_mac.begin();
	std::vector<std::string>::iterator cvcitr=m_cvc.begin();
	
	for( vector<std::string>::iterator portitr=m_ports.begin() ;
			portitr!=m_ports.end()&&macitr!=m_mac.end()&&cvcitr!=m_cvc.end();
			portitr++,macitr++,cvcitr++
		)
	{
		BD_Item items=BD_Item();
		items.setCVC(*cvcitr);
		items.setMac(*macitr);
		items.setPort(*portitr);
		
		m_itemlists.push_back(items); 
		
	}
	int index=0;
	for (std::vector<BD_Item>::iterator itr=m_itemlists.begin() ;
			itr!=m_itemlists.end();
			itr++,index++
		)
	{
		BD_Item item=*itr;
		switch(index)
		{
		case 0:
			m_ckport1.SetCheck(1);
			m_edit_macaddr1.SetWindowText(item.getMac().c_str());
			m_edit_cvc1.SetWindowText(item.getCVC().c_str());
			m_edit_did1.SetWindowText(item.getPort().c_str());
			break;
		case 1:
			m_ckport2.SetCheck(1);
			m_edit_macaddr2.SetWindowText(item.getMac().c_str());
			m_edit_cvc2.SetWindowText(item.getCVC().c_str());
			m_edit_did2.SetWindowText(item.getPort().c_str());
			break;
		case 2:
			m_ckport3.SetCheck(1);
			m_edit_macaddr3.SetWindowText(item.getMac().c_str());
			m_edit_cvc3.SetWindowText(item.getCVC().c_str());
			m_edit_did3.SetWindowText(item.getPort().c_str());
			break;
		case 3:
			m_ckport4.SetCheck(1);
			m_edit_macaddr4.SetWindowText(item.getMac().c_str());
			m_edit_cvc4.SetWindowText(item.getCVC().c_str());
			m_edit_did4.SetWindowText(item.getPort().c_str());
			break;
		case 4:
			m_ckport5.SetCheck(1);
			m_edit_macaddr5.SetWindowText(item.getMac().c_str());
			m_edit_cvc5.SetWindowText(item.getCVC().c_str());
			m_edit_did5.SetWindowText(item.getPort().c_str());
			break;
		case 5:
			m_ckport6.SetCheck(1);
			m_edit_macaddr6.SetWindowText(item.getMac().c_str());
			m_edit_cvc6.SetWindowText(item.getCVC().c_str());
			m_edit_did6.SetWindowText(item.getPort().c_str());
			break;
		case 6:
			m_ckport7.SetCheck(1);
			m_edit_macaddr7.SetWindowText(item.getMac().c_str());
			m_edit_cvc7.SetWindowText(item.getCVC().c_str());
			m_edit_did7.SetWindowText(item.getPort().c_str());
			break;
		case 7:
			m_ckport8.SetCheck(1);
			m_edit_macaddr8.SetWindowText(item.getMac().c_str());
			m_edit_cvc8.SetWindowText(item.getCVC().c_str());
			m_edit_did8.SetWindowText(item.getPort().c_str());
			break;
		case 8:
			m_ckport9.SetCheck(1);
			m_edit_macaddr9.SetWindowText(item.getMac().c_str());
			m_edit_cvc9.SetWindowText(item.getCVC().c_str());
			m_edit_did9.SetWindowText(item.getPort().c_str());
			break;
		case 9:
			m_ckport10.SetCheck(1);
			m_edit_macaddr10.SetWindowText(item.getMac().c_str());
			m_edit_cvc10.SetWindowText(item.getCVC().c_str());
			m_edit_did10.SetWindowText(item.getPort().c_str());
			break;
		case 10:
			m_ckport11.SetCheck(1);
			m_edit_macaddr11.SetWindowText(item.getMac().c_str());
			m_edit_cvc11.SetWindowText(item.getCVC().c_str());
			m_edit_did11.SetWindowText(item.getPort().c_str());
			break;
		case 11:
			m_ckport12.SetCheck(1);
			m_edit_macaddr12.SetWindowText(item.getMac().c_str());
			m_edit_cvc12.SetWindowText(item.getCVC().c_str());
			m_edit_did12.SetWindowText(item.getPort().c_str());
			break;
		case 12:
			m_ckport13.SetCheck(1);
			m_edit_macaddr13.SetWindowText(item.getMac().c_str());
			m_edit_cvc13.SetWindowText(item.getCVC().c_str());
			m_edit_did13.SetWindowText(item.getPort().c_str());
			break;
		case 13:
			m_ckport14.SetCheck(1);
			m_edit_macaddr14.SetWindowText(item.getMac().c_str());
			m_edit_cvc14.SetWindowText(item.getCVC().c_str());
			m_edit_did14.SetWindowText(item.getPort().c_str());
			break;
		case 14:
			m_ckport15.SetCheck(1);
			m_edit_macaddr15.SetWindowText(item.getMac().c_str());
			m_edit_cvc15.SetWindowText(item.getCVC().c_str());
			m_edit_did15.SetWindowText(item.getPort().c_str());
			break;
		case 15:
			m_ckport16.SetCheck(1);
			m_edit_macaddr16.SetWindowText(item.getMac().c_str());
			m_edit_cvc16.SetWindowText(item.getCVC().c_str());
			m_edit_did16.SetWindowText(item.getPort().c_str());
			break;
		}
		
	}
	if (portsStr)
	{
		delete[] portsStr;
		portsStr=NULL;
	}
	if (transStr)
	{
		delete[] transStr; 
		transStr=NULL;
	}
	AppendTestInfo("准备完成\r\n");

}






void CBlueToolTestforJoyDlg::clearStatus()
{

	m_ports.clear();
	m_trans.clear();
	m_cvc.clear();
	m_mac.clear();
	m_itemlists.clear();

	m_hardcheckindex = 0 ;

	m_ckport1.SetCheck(0);
 	m_edit_did1.SetWindowText(NULL);
	m_edit_cvc1.SetWindowText(NULL);
	m_edit_macaddr1.SetWindowText(NULL);
	m_ckport2.SetCheck(0);
	m_edit_did2.SetWindowText(NULL);
	m_edit_cvc2.SetWindowText(NULL);
	m_edit_macaddr2.SetWindowText(NULL);
	m_ckport3.SetCheck(0);
	m_edit_did3.SetWindowText(NULL);
	m_edit_cvc3.SetWindowText(NULL);
	m_edit_macaddr3.SetWindowText(NULL);
	m_ckport4.SetCheck(0);
	m_edit_did4.SetWindowText(NULL);
	m_edit_cvc4.SetWindowText(NULL);
	m_edit_macaddr4.SetWindowText(NULL);
	m_ckport5.SetCheck(0);
	m_edit_did5.SetWindowText(NULL);
	m_edit_cvc5.SetWindowText(NULL);
	m_edit_macaddr5.SetWindowText(NULL);
	m_ckport6.SetCheck(0);
	m_edit_did6.SetWindowText(NULL);
	m_edit_cvc6.SetWindowText(NULL);
	m_edit_macaddr6.SetWindowText(NULL);
	m_ckport7.SetCheck(0);
	m_edit_did7.SetWindowText(NULL);
	m_edit_cvc7.SetWindowText(NULL);
	m_edit_macaddr7.SetWindowText(NULL);
	m_ckport8.SetCheck(0);
	m_edit_did8.SetWindowText(NULL);
	m_edit_cvc8.SetWindowText(NULL);
	m_edit_macaddr8.SetWindowText(NULL);
	m_ckport9.SetCheck(0);
	m_edit_did9.SetWindowText(NULL);
	m_edit_cvc9.SetWindowText(NULL);
	m_edit_macaddr9.SetWindowText(NULL);
	m_ckport10.SetCheck(0);
	m_edit_did10.SetWindowText(NULL);
	m_edit_cvc10.SetWindowText(NULL);
	m_edit_macaddr10.SetWindowText(NULL);
	m_ckport11.SetCheck(0);
	m_edit_did11.SetWindowText(NULL);
	m_edit_cvc11.SetWindowText(NULL);
	m_edit_macaddr11.SetWindowText(NULL);
	m_ckport12.SetCheck(0);
	m_edit_did12.SetWindowText(NULL);
	m_edit_cvc12.SetWindowText(NULL);
	m_edit_macaddr12.SetWindowText(NULL);
	m_ckport13.SetCheck(0);
	m_edit_did13.SetWindowText(NULL);
	m_edit_cvc13.SetWindowText(NULL);
	m_edit_macaddr13.SetWindowText(NULL);
	m_ckport14.SetCheck(0);
	m_edit_did14.SetWindowText(NULL);
	m_edit_cvc14.SetWindowText(NULL);
	m_edit_macaddr14.SetWindowText(NULL);
	m_ckport15.SetCheck(0);
	m_edit_did15.SetWindowText(NULL);
	m_edit_cvc15.SetWindowText(NULL);
	m_edit_macaddr15.SetWindowText(NULL);
	m_ckport16.SetCheck(0);
	m_edit_did16.SetWindowText(NULL);
	m_edit_cvc16.SetWindowText(NULL);
	m_edit_macaddr16.SetWindowText(NULL);

}



void CBlueToolTestforJoyDlg::InitCtrl()
{
	//CString str;
	char s_curDir[MAX_PATH+128]={'\0'};

	GetCurrentDirectory(MAX_PATH , s_curDir);
	
	strcat(s_curDir , STATIC_FIRMFILE );
	
	m_edit_global_burnfile.SetWindowText(s_curDir);
	m_edit_global_burnname.SetWindowText(DEFAULT_BD_NAME);

}

void CBlueToolTestforJoyDlg::OnButtonWritecheck() 
{
	// TODO: Add your control notification handler code here
	AfxBeginThread( thread_WriteCheckFreq , this );
}




/************************************************************************/
/*处理写入配置信息和频率校验
                                                                        */
/************************************************************************/
UINT CBlueToolTestforJoyDlg::thread_WriteCheckFreq(LPVOID lpParam)
{
	// TODO: Add your control notification handler code here
	CBlueToolTestforJoyDlg *p_dlg = (CBlueToolTestforJoyDlg *)lpParam;  
	uint32 iHandle(0);
	CString tempinfo; 
	
	for(std::vector<BD_Item>::iterator itr1=p_dlg->m_itemlists.begin() ; itr1!=p_dlg->m_itemlists.end() ; itr1++)
	{
		int retVal=0;
		iHandle = openTestEngineSpi( atoi( itr1->getPort().c_str() ) , 0 , SPI_USB ); 
		if (iHandle)
		{

			//写入蓝牙名称...蓝牙名字不得超过四十个字节！
			CString str_bdName;
			p_dlg->m_edit_global_burnname.GetWindowText(str_bdName);
			uint16 bd_name[20]={'\0'};
			strcpy( (char*)bd_name , str_bdName.GetBuffer(0) );
			if(psWrite(iHandle, PSKEY_DEVICE_NAME, PS_STORES_I, 20, bd_name) == TE_OK)
			{
				itr1->isDeviceNameWrite = true ;
				tempinfo.Format("%s设备名写入成功\r\n" , itr1->getPort().c_str() );
				p_dlg->AppendTestInfo(tempinfo);
			}
			else
			{
				retVal = 1 ;
				tempinfo.Format("%s设备名写入失败\r\n" , itr1->getPort().c_str() );
				p_dlg->AppendTestInfo( tempinfo , TRUE );
			}
			
			//设置配对密码
			/*
			uint16 bd_pwd[20]={'\0'};
			strcpy( (char*)bd_pwd , DEFAULT_BD_PWD );
			if(psWrite( iHandle , PSKEY_FIXED_PIN , PS_STORES_I, 20 , bd_pwd) == TE_OK)
			{ 
				tempinfo.Format("%s写入配对密码成功\r\n" , itr1->getPort().c_str() );
				p_dlg->AppendTestInfo( tempinfo  );
			}
			else
			{ 
				retVal = 2 ;
				tempinfo.Format("%s写入配对密码失败\r\n",itr1->getPort().c_str() );
				p_dlg->AppendTestInfo( tempinfo , TRUE);
			}
			*/
			
			//cvc码（先做读取操作）
			uint16 bd_cvc[20]={'\0'};
			strcpy( (char*)bd_cvc , itr1->getCVC().c_str() );
			if(psWrite( iHandle , PSKEY_DSP48 , PS_STORES_I, 20 , bd_cvc ) == TE_OK)
			{ 
				itr1->isCvcWriteSucced = true ;
				tempinfo.Format("%sCVC码写入成功\r\n" , itr1->getPort().c_str() );
				p_dlg->AppendTestInfo( tempinfo );
			}
			else
			{
				retVal = 3 ;
				tempinfo.Format("%sCVC码写入失败\r\n" , itr1->getPort().c_str() );
				p_dlg->AppendTestInfo(tempinfo , TRUE);
			}
			
			//MAC蓝牙地址
			uint16 bd_addr[4]={'\0'};
			strcpy( (char*)bd_addr , itr1->getMac().c_str() );
			if(psWrite( iHandle , PSKEY_BDADDR , PS_STORES_I,  4 , bd_addr ) == TE_OK)
			{ 
				itr1->isMacWriteSucced = true ;
				tempinfo.Format("%sMAC地址写入%s成功\r\n" , itr1->getPort().c_str() , itr1->getMac().c_str() );
				p_dlg->AppendTestInfo(tempinfo);
			}
			else
			{ 
				tempinfo.Format("%sMAC地址写入失败\r\n" ,itr1->getPort().c_str() );
				p_dlg->AppendTestInfo(tempinfo , TRUE );
			}
 
	
			
			closeTestEngine(iHandle);

		}
	
	}
	
	tempinfo.Format("配置读写操作结束\r\n\r\n" );
	p_dlg->AppendTestInfo(tempinfo );

	return 1;
}




void CBlueToolTestforJoyDlg::CheckFreq()
{
	/*
	先设置trim offset to crystal frequency =0
	then read TXSTART actual freq, value is b
	then we execute "set Xtal Offset", the actual freq value b.
	*/
}

void CBlueToolTestforJoyDlg::OnButtonNextdc() 
{
	// TODO: Add your control notification handler code here
	if (m_hardcheckindex < m_itemlists.size()-1 )
	{
		m_hardcheckindex++;
	}
	else
	{
		AppendTestInfo("已经是最后一个设备\r\n",true);
	}
}

void CBlueToolTestforJoyDlg::OnButtonFormer() 
{
	// TODO: Add your control notification handler code here
	if (m_hardcheckindex>0)
	{
		m_hardcheckindex--;
	}
	else
	{
		AppendTestInfo("已经是第一个设备\r\n",true);
	}
}


/*
00000000000000000100000000010000 
00000000000000000010000000010011 
00000000000000000001000000010000 
00000000000000000000100000010011
*/
void CBlueToolTestforJoyDlg::OnButtonHardbtnall() 
{
	// TODO: Add your control notification handler code here
	//测试电压等参数。
	//GiveHint(0);
	AfxBeginThread( TurnLightOn , this );

	AfxBeginThread( thread_HardwareCheck , this );

	return;


}





void CBlueToolTestforJoyDlg::OnButtonHardbtn1() 
{
	// TODO: Add your control notification handler code here
	//测试电压等参数。
	if (m_hardcheckindex>=m_itemlists.size())
	{
		AppendTestInfo( "测试设备越界\r\n" );
		return;
	}
	CString tempinfo;
	uint32 direction=0;
	uint32 value=0;
	uint32 iHandle=0;
	iHandle = openTestEngineSpi( atoi( m_itemlists.at(m_hardcheckindex).getPort().c_str() ) , 0 , SPI_USB ); 
	if(iHandle != 0)
	{
		
		// Get the direction and value of the PIO lines.
		int32 success = bccmdGetPio32(iHandle, &direction, &value);
		if(success == TE_OK)
		{
			std::bitset<32> bits(value);
			//00000000000000000111000100010000 
			if (!bits.test(BTN_VOICEDOWN))
			{
				AppendTestInfo("音量-异常\r\n" ,true);
			}
			else
			{
				m_itemlists.at(m_hardcheckindex).isVoiceDownSucced = true ;
				AppendTestInfo("音量-正常\r\n");
			}
			
		}
		else
		{
			tempinfo.Format("failed bccmdGetPio32 %d %d \r\n" , direction , value);
			AppendTestInfo(tempinfo );
		} 
		
	}
	else
	{
		AppendTestInfo( "设备连接失败\r\n" , TRUE ) ;
	}
	closeTestEngine(iHandle);
}

void CBlueToolTestforJoyDlg::OnButtonHardbtn2() 
{
	// TODO: Add your control notification handler code here
	if (m_hardcheckindex>=m_itemlists.size())
	{
		AppendTestInfo( "测试设备越界\r\n" );
		return;
	}
	CString tempinfo;
	uint32 direction=0;
	uint32 value=0;
	uint32 iHandle=0;
	iHandle = openTestEngineSpi( atoi( m_itemlists.at(m_hardcheckindex).getPort().c_str() ) , 0 , SPI_USB ); 
	if(iHandle != 0)
	{
		
		// Get the direction and value of the PIO lines.
		int32 success = bccmdGetPio32(iHandle, &direction, &value);
		if(success == TE_OK)
		{
			std::bitset<32> bits(value);
			//00000000000000000111000100010000 
			if (!bits.test(BTN_VOICEUP))
			{
				AppendTestInfo("音量+异常\r\n" ,true);
			}
			else
			{
				m_itemlists.at(m_hardcheckindex).isVoiceUpSucced = true ;
				AppendTestInfo("音量+正常\r\n");
			}
			
		}
		else
		{
			tempinfo.Format("failed bccmdGetPio32 %d %d \r\n" , direction , value);
			AppendTestInfo(tempinfo );
		} 
		
	}
	else
	{
		AppendTestInfo( "设备连接失败\r\n" , TRUE ) ;
	}
	closeTestEngine(iHandle);
}

void CBlueToolTestforJoyDlg::OnButtonHardbtn3() 
{
	// TODO: Add your control notification handler code here
	if (m_hardcheckindex>=m_itemlists.size())
	{
		AppendTestInfo( "测试设备越界\r\n" );
		return;
	}
	CString tempinfo;
	uint32 direction=0;
	uint32 value=0;
	uint32 iHandle=0;
	iHandle = openTestEngineSpi( atoi( m_itemlists.at(m_hardcheckindex).getPort().c_str() ) , 0 , SPI_USB ); 
	if(iHandle != 0)
	{
		
		// Get the direction and value of the PIO lines.
		int32 success = bccmdGetPio32(iHandle, &direction, &value);
		if(success == TE_OK)
		{
			std::bitset<32> bits(value);
			//00000000000000000111000100010000 
			if (!bits.test(BTN_MSG))
			{
				AppendTestInfo("消息键异常\r\n" ,true);
			}
			else
			{
				m_itemlists.at(m_hardcheckindex).isMsgSucced = true ;
				AppendTestInfo("消息键正常\r\n");
			}
			
		}
		else
		{
			tempinfo.Format("failed bccmdGetPio32 %d %d \r\n" , direction , value);
			AppendTestInfo(tempinfo );
		} 
		
	}
	else
	{
		AppendTestInfo( "设备连接失败\r\n" , TRUE ) ;
	}
	closeTestEngine(iHandle);
}






/************************************************************************/
/*硬件测试
	暂时未使用                                                          */
/************************************************************************/
UINT CBlueToolTestforJoyDlg::thread_HardwareCheck(LPVOID lpParam)
{
	CBlueToolTestforJoyDlg *p_dlg = (CBlueToolTestforJoyDlg *)lpParam;  
	//测试电压等参数。
	if (p_dlg->m_hardcheckindex>=p_dlg->m_itemlists.size())
	{
		p_dlg->AppendTestInfo( "测试设备越界 " );
		return -1;
	}
	CString tempinfo;
	
	std::bitset<32> totalbits(0);
	uint32 direction=0;
	uint32 value=0;
	uint32 iHandle=0;
	iHandle = openTestEngineSpi( atoi( ( p_dlg->m_itemlists).at(p_dlg->m_hardcheckindex).getPort().c_str() ) , 0 , SPI_USB ); 
	if(iHandle != 0)
	{
		int loop = 100;
		while (loop--)
		{
			// Get the direction and value of the PIO lines.
			int32 success = bccmdGetPio32(iHandle, &direction, &value);
			if(success == TE_OK)
			{
				std::bitset<32> bit(value);
				//00000000000000000111000100010000 
				if (bit.test(BTN_CALL))
				{
					if (!totalbits.test(BTN_CALL))
					{
						p_dlg->m_itemlists.at(p_dlg->m_hardcheckindex).isCallSucced = true ;
						totalbits.set(BTN_CALL);
						p_dlg->AppendTestInfo("呼叫键按下\r\n");
					}
					
				}
				if (bit.test(BTN_VOICEDOWN))
				{
					if (!totalbits.test(BTN_VOICEDOWN))
					{ 
						p_dlg->m_itemlists.at(p_dlg->m_hardcheckindex).isVoiceDownSucced = true ;
						totalbits.set(BTN_VOICEDOWN);
						p_dlg->AppendTestInfo("音量-键按下\r\n");
					}
				}
				if (bit.test(BTN_VOICEUP))
				{
					if (!totalbits.test(BTN_VOICEUP))
					{
						p_dlg->m_itemlists.at(p_dlg->m_hardcheckindex).isVoiceUpSucced = true ;
						totalbits.set(BTN_VOICEUP);
						p_dlg->AppendTestInfo("音量+键按下\r\n");
					}
					
				}
				if (bit.test(BTN_MSG))
				{
					if (!totalbits.test(BTN_MSG))
					{
						p_dlg->m_itemlists.at(p_dlg->m_hardcheckindex).isMsgSucced = true ;
						totalbits.set(BTN_MSG);
						p_dlg->AppendTestInfo("消息键按下\r\n");
					}
					
				}
				if (totalbits.test(11)&&totalbits.test(12)&&totalbits.test(13)&&totalbits.test(14))
				{
					tempinfo.Format("设备%s所有按键测试正常\r\n" , p_dlg->m_itemlists.at(p_dlg->m_hardcheckindex).getPort().c_str() ) ;
					p_dlg->AppendTestInfo( tempinfo  );
					break;
				}
				Sleep(50);
			} 			
			else
			{
				tempinfo.Format("failed bccmdGetPio32 %d %d \r\n" , direction , value);
				p_dlg->AppendTestInfo(tempinfo );
			} 
		}
	}
	else
	{
		p_dlg->AppendTestInfo( "设备连接失败\r\n" , TRUE ) ;
	}
	closeTestEngine(iHandle);
}





UINT  CBlueToolTestforJoyDlg::TurnLightOn(LPVOID lpParam)
{
	
	CBlueToolTestforJoyDlg *p_dlg = (CBlueToolTestforJoyDlg *)lpParam;  
	uint32 direction=0xFFFF ,fdirection=0 ;
	uint32 cvalue=0,fvalue=0;
	uint32 iHandle=0;
	uint32 pioMask  ;
	uint32 errLines;
	int32 success=0;
	std::bitset<32> bits(1);
	//bits.set();
	bits.set(0);
	bits.set(1);
	
	pioMask  = bits.to_ulong();
	cvalue = bits.to_ulong();
	iHandle = openTestEngineSpi( atoi( p_dlg->m_itemlists.at(p_dlg->m_hardcheckindex).getPort().c_str() ) , 0 , SPI_USB ); 
	
	if(iHandle)
	{
		
		//备份当前PIO的数值
		success = bccmdGetPio32(iHandle, &fdirection, &fvalue);
	 
		success = bccmdSetPio32(iHandle, pioMask, direction, cvalue, &errLines);
		// Checks if any lines could not be mapped as PIOs
		if(success != TE_OK)
		{
			// Checks which PIO lines could not be set as input or output
			
		}
		else
		{
			Sleep(3000);
			success = bccmdSetPio32(iHandle, pioMask, fdirection, fvalue, &errLines);
		}
	}
	
	closeTestEngine(iHandle);
	
	return 0;
}





UINT  CBlueToolTestforJoyDlg::TurnIndexedLightOn(LPVOID lpParam)
{
	int port = (int) lpParam ;

	uint32 direction=0xFFFF ,fdirection=0 ;
	uint32 cvalue=0,fvalue=0;
	uint32 iHandle=0;
	uint32 pioMask  ;
	uint32 errLines;
	int32 success=0;
	std::bitset<32> bits(1); 
	bits.set(0);
	bits.set(1);
	
	pioMask  = bits.to_ulong();
	cvalue = bits.to_ulong();
	iHandle = openTestEngineSpi( port  , 0 , SPI_USB ); 
	
	if(iHandle)
	{
		
		//备份当前PIO的数值
		success = bccmdGetPio32(iHandle, &fdirection, &fvalue);
		
		success = bccmdSetPio32(iHandle, pioMask, direction, cvalue, &errLines);
		// Checks if any lines could not be mapped as PIOs
		if(success != TE_OK)
		{
			// Checks which PIO lines could not be set as input or output
			
		}
		else
		{
			Sleep(3000);
			success = bccmdSetPio32(iHandle, pioMask, fdirection, fvalue, &errLines);
		}
	}
	
	closeTestEngine(iHandle);
	
	return 0;
}



UINT  CBlueToolTestforJoyDlg::TurnIndexedLightOnForever(LPVOID lpParam)
{

	int port = (int) lpParam ; 
	uint32 direction=0xFFFF ,fdirection=0 ;
	uint32 cvalue=0,fvalue=0;
	uint32 iHandle=0;
	uint32 pioMask  ;
	uint32 errLines;
	int32 success=0;
	std::bitset<32> bits(1); 
	bits.set(0);
	bits.set(1);
	
	pioMask  = bits.to_ulong();
	cvalue = bits.to_ulong();
	iHandle = openTestEngineSpi( port  , 0 , SPI_USB ); 
	
	if(iHandle)
	{
		
		//备份当前PIO的数值
		success = bccmdGetPio32(iHandle, &fdirection, &fvalue);
		
		success = bccmdSetPio32(iHandle, pioMask, direction, cvalue, &errLines);
		// Checks if any lines could not be mapped as PIOs
		if(success != TE_OK)
		{
			// Checks which PIO lines could not be set as input or output
			
		}
		else
		{
// 			Sleep(3000);
// 			success = bccmdSetPio32(iHandle, pioMask, fdirection, fvalue, &errLines);
		}
	}
	
	closeTestEngine(iHandle);
	
	return 0;
}




UINT  CBlueToolTestforJoyDlg::TurnIndexedLightOff(LPVOID lpParam)
{
	
	int port = (int) lpParam ; 
	uint32 direction=0xFFFF ,fdirection=0 ;
	uint32 cvalue=0,fvalue=0;
	uint32 iHandle=0;
	uint32 pioMask  ;
	uint32 errLines;
	int32 success=0;
	std::bitset<32> bits(1); 
	bits.reset(0);
	bits.reset(1);
	
	pioMask  = bits.to_ulong();
	cvalue = bits.to_ulong();
	iHandle = openTestEngineSpi( port  , 0 , SPI_USB ); 
	
	if(iHandle)
	{
		
		//备份当前PIO的数值
		success = bccmdGetPio32(iHandle, &fdirection, &fvalue);
		
		success = bccmdSetPio32(iHandle, pioMask, direction, cvalue, &errLines);
		// Checks if any lines could not be mapped as PIOs
		if(success != TE_OK)
		{  
		}
		else
		{ 
		}
	}
	
	closeTestEngine(iHandle);
	
	return 0;
}







void CBlueToolTestforJoyDlg::OnButtonCall() 
{
	// TODO: Add your control notification handler code here
	if (m_hardcheckindex>=m_itemlists.size())
	{
		AppendTestInfo( "测试设备越界\r\n" );
		return;
	}
	CString tempinfo;
	uint32 direction=0;
	uint32 value=0;
	uint32 iHandle=0;
	iHandle = openTestEngineSpi( atoi( m_itemlists.at(m_hardcheckindex).getPort().c_str() ) , 0 , SPI_USB ); 
	if(iHandle != 0)
	{
		
		// Get the direction and value of the PIO lines.
		int32 success = bccmdGetPio32(iHandle, &direction, &value);
		if(success == TE_OK)
		{
			std::bitset<32> bits(value);
			//00000000000000000111000100010000 
			if (!bits.test(BTN_CALL))
			{
				AppendTestInfo("呼叫键异常\r\n" ,true);
			}
			else
			{
				m_itemlists.at(m_hardcheckindex).isCallSucced = true ;
				AppendTestInfo("呼叫键正常\r\n");
			}
			
		}
		else
		{
			tempinfo.Format("failed bccmdGetPio32 %d %d \r\n" , direction , value);
			AppendTestInfo(tempinfo );
		} 
		
	}
	else
	{
		AppendTestInfo( "设备连接失败\r\n" , TRUE ) ;
	}
	closeTestEngine(iHandle);
}


 

void CBlueToolTestforJoyDlg::OnButtonHardbtnbegin() 
{
	// TODO: Add your control notification handler code here

	m_hardcheckindex = 0;
//	AfxBeginThread( TurnLightOn , this );
}



// 
// int devMask=bitvec.to_ulong();
// if(flmOpen(devMask, 26, TFL_SPI_USB) != TFL_OK)
//     {

int CBlueToolTestforJoyDlg::SingleBurn(int index , void * phandle)
{
	//单路烧录文件。
	CBlueToolTestforJoyDlg * pdlg = (CBlueToolTestforJoyDlg *)phandle;
	CString tempinfo ;
	bitset<16> bitvec;  //32 bits,all zero

	bitvec.set(index);
	
	int devMask=bitvec.to_ulong();
	if(flmOpen(devMask, 26, TFL_SPI_USB) != TFL_OK)
    { 
		return 1 ;
    }
	
    if(flmReadProgramFiles("xpv\\merge.xpv") != TFL_OK)
    {
        //std::cout << "Failed to read flash program files" << std::endl; 
        flmClose(devMask);
		return 2 ;
    }
	
    if(flmProgramSpawn(devMask, 0, 0, 0) != TFL_OK)
    { 
        flmClose(devMask);
		return 3;
    } 
 
	
    uint16 devicesRunning;
    int32 progress;
    do
    {
        devicesRunning = 0;
        for(uint32 devIndex = 0; devIndex < 1 ; ++devIndex)
        {
            //Only check the progress if the device is in the mask
            if((devMask >> devIndex) & 1)
            {
                progress = flmGetDeviceProgress(devIndex);
                if(progress < 100)
                {
                    ++devicesRunning;
                }
				
				//更新ui
				tempinfo.Format("设备编号 = %d 进度 = %d\r\n" , devIndex , progress );
				pdlg->AppendTestInfo(tempinfo); 
				
            }
        }
        Sleep(1000);
    }
    while(devicesRunning > 0);
	
    int32 error = flmGetLastError();
    if(error != TFL_OK)
    {
		flmClose(devMask);
		return 4;        
    } 
	

	
    flmClose(devMask);
	return 0;	

}






//准备就绪的时候检查设备是否可读。
int CBlueToolTestforJoyDlg::CheckConnection()
{
	int rVal=0;
	bitset<16> bitvec;  //32 bits,all zero
	for(int loop_bs=0 ; loop_bs<m_ports.size() ; loop_bs++ )
	{
		bitvec.set(loop_bs);
	}
	
	int devMask=bitvec.to_ulong();
	if(flmOpen(devMask, 26, TFL_SPI_USB) != TFL_OK)
    {  
		rVal=1;
    }
	
    if(flmReadProgramFiles("xpv\\merge.xpv") != TFL_OK)
    { 
        flmClose(devMask);
		rVal=2;
    }

	flmClose(devMask);

	if (rVal)//有设备连接异常，检查是哪个设备异常。
	{
		for (int i=0; i< m_ports.size() ; i++)
		{
			if (!isDeviceConnectable(i) )	//设备不可连接。提示异常设备。
			{
			
				CString strInfo ;
				strInfo.Format("亮红灯设备%s连接异常，请先行处理",m_ports.at(i).c_str());
				AppendTestInfo( strInfo , TRUE) ;
				AfxBeginThread( TurnIndexedLightOn , (LPVOID) atoi( m_ports.at(i).c_str() ) ) ;
				//UINT  CBlueToolTestforJoyDlg::TurnIndexedLightOn(LPVOID lpParam)
				break;
			}
		}
	}
	else	//全部测试通过。
	{
		AppendTestInfo( "全部测试通过" ) ;
		return rVal ;
	}
	
}



//如果准备就绪的时候检查多个设备不可读，则检测具体哪个设备不可读。
bool CBlueToolTestforJoyDlg::isDeviceConnectable(int index)
{
	bitset<16> bitvec;  //32 bits,all zero
	bitvec.set(index/*+1*/); 
	int devMask=bitvec.to_ulong();
	if(flmOpen(devMask, 26, TFL_SPI_USB) != TFL_OK)
    {  
		return false ;
    }
	else{
		//AppendTestInfo("..33333....");
		flmClose(devMask);
		return true ;
	}
	 
}



void CAboutDlg::OnBtnGotoadmin() 
{
	// TODO: Add your control notification handler code here
	CDlgAdmin  pDlg ;//= new CDlgAdmin(this);
	pDlg.DoModal();
	OnOK();
}

void CBlueToolTestforJoyDlg::OnButtonReqmaccvc() 
{
	// TODO: Add your control notification handler code here
	CString strtestorid;
	CString strtestorpwd; 
	
	m_testorid.GetWindowText(strtestorid);
	m_testorpwd.GetWindowText(strtestorpwd);
	if (!strtestorid.IsEmpty()&&!strtestorpwd.IsEmpty())
	{
		AfxBeginThread( ReqMacCvc , this );
	}else{
		AppendTestInfo("员工账号和密码不能为空\n",true);
	}
	
}






//UINT  CBlueToolTestforJoyDlg::thread_ProcessBurnFirm(LPVOID lpParam)
UINT CBlueToolTestforJoyDlg::ReqMacCvc(LPVOID lpParam)
{
	CBlueToolTestforJoyDlg *p_dlg = (CBlueToolTestforJoyDlg *)lpParam;  
	CString strtestorid;
	CString strtestorpwd;
	int reqnum =48;
 
	p_dlg->m_testorid.GetWindowText(strtestorid);
	p_dlg->m_testorpwd.GetWindowText(strtestorpwd);
 
	CString sendbuf;
	sendbuf.Format("{\"count\": %d,\"testor\":\"%s\",\"pwd\":\"%s\"}", reqnum, strtestorid, strtestorpwd);
	//	p_dlg->m_label_addresult = "{\"admin\": \"joysoftadmin\",\"adminpwd\": \"obasang\",\"testor\": \"testor's work id\",\"testorpwd\": \"pwd\"}"
	std::string reqstr;
	NetConnection::Instance()->connect_server();
	NetConnection::Instance()->send_buf(sendbuf, reqstr, 1002);
	
	std::string strjson(reqstr.c_str()+12 , reqstr.size() );
	
	Json::Reader reader;
	Json::Value value;
	bool bRet = reader.parse(strjson, value);
	if (false == bRet)
	{
		//	cerr << endl << "read value error \n";
		p_dlg->AppendTestInfo("数据请求失败\n",true);
		return -1;
	}else{
		//std::string str =  value["count"].asString();
	
		int jsonresult =0;
		jsonresult =	atoi(value["count"].asString().c_str()) ;
		if (0<jsonresult)
		{
			p_dlg->AppendTestInfo("数据更新成功\n",true);
		}
		else
		{
			p_dlg->AppendTestInfo("数据更新失败\n",true);
		}
		
	} 
	
	return 0;
}
