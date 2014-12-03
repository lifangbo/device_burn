// BlueToolTestforJoyDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BlueToolTestforJoy.h"
#include "BlueToolTestforJoyDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

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
// CBlueToolTestforJoyDlg dialog

CBlueToolTestforJoyDlg::CBlueToolTestforJoyDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CBlueToolTestforJoyDlg::IDD, pParent)
{
	m_lines=0;
	//{{AFX_DATA_INIT(CBlueToolTestforJoyDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CBlueToolTestforJoyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBlueToolTestforJoyDlg)
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
	
	// TODO: Add extra initialization here
	

//	SendMessage(WM_SIZE);

	InitCtrl();

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
#ifdef DEBUG
	CString strinfo;
	getHandle(strinfo); 
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
	//	m_redit_outinfo.SetSel(1, 5); //设置处理区域
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
// 	
// 	if (m_redit_outinfo.GetSafeHwnd())
// 	{
// 		m_redit_outinfo.SetWindowPos(NULL,0,0,cx/4*3,cy,NULL);
// 	}
// 
// 	if (m_btncancel.GetSafeHwnd())
// 	{
// 		m_btncancel.SetWindowPos(NULL,cx*5/6,cy/3*2,54,16,SWP_NOSIZE);
// 	}
// 	if (m_test_do.GetSafeHwnd())
// 	{
// 		m_test_do.SetWindowPos(NULL,cx*5/6,cy/3,54,16,SWP_NOSIZE);
// 	}

	// TODO: Add your message handler code here
	
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
		cf.crTextColor = RGB(200, 100, 255); //文字颜色
		strcpy(cf.szFaceName ,_T("隶书"));//设置字体
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






// UINT  CBlueToolTestforJoyDlg::thd_Process(LPVOID lpParam)
// {
//  
// 		//获取可用设备的句柄。
// 	uint32 iHandle(0);
// 	uint16 maxLen(256);
// 	uint16 count(0);
// 	char* portsStr = new char[maxLen];
// 	char* transStr = new char[maxLen];
// 	vector<string> ports; // The human readable port strings (e.g. "LPT1")
// 	vector<string> trans; // The transport option strings (e.g. "SPITRANS=LPT SPIPORT=1")
// 	
// 	CString tempinfo; 
// 
// 	CBlueToolTestforJoyDlg *p_dlg = (CBlueToolTestforJoyDlg *)lpParam;  
// 
// 	memset(portsStr,0,maxLen);
// 	int32 status = teGetAvailableSpiPorts(&maxLen, portsStr, transStr, &count);
// 
//  	if( status != TE_OK && maxLen != 0 )
// 	{
// 		// Not enough space - resize the storage
// 		portsStr = new char[maxLen];
// 		transStr = new char[maxLen];
// 		status = teGetAvailableSpiPorts(&maxLen, portsStr, transStr, &count);
// 	 
// 		//更新ui
// 		tempinfo.Format("error teGetAvailableSpiPorts %d\r\n",status); 
// 		p_dlg->AppendTestInfo(tempinfo);
// 
// 	}
// 	if( status != TE_OK || count == 0 )
// 	{ 
//  		tempinfo.Format("Error getting SPI ports, or none found\r\n");
// 		p_dlg->AppendTestInfo(tempinfo);
// 		delete[] portsStr;
// 		delete[] transStr; 
// 	} 
// 	tempinfo.Format("portStr:%s portsStr:%s\r\n" , transStr , portsStr);
// 	p_dlg->AppendTestInfo(tempinfo);
// 	// Split up the comma separated strings of ports / transport options
// 	ports=split( string(portsStr), string(",")); // Use these for user selection (e.g. drop down list)
// 	trans=split(string(transStr), string(",")); // Use these to open a transport
// 
// 	//解析去掉括号	(600895)--->600895
// 	parseBrackets(ports);
// 
// 	//多路烧录文件。
// 	bitset<32> bitvec;  //32 bits,all zero
// 	for(int loop_bs=0 ; loop_bs<ports.size() ; loop_bs++ )
// 	{
// 		bitvec.set(loop_bs);
// 	}
// 	
// 	int devMask=bitvec.to_ulong();
// 	if(flmOpen(devMask, 26, TFL_SPI_USB) != TFL_OK)
//     {
//         //std::cout << "Failed to open devices (" << flmGetBitErrorField() << ")" << std::endl;
// 		tempinfo.Format("Failed to open devices %d \r\n" ,flmGetBitErrorField() );
// 		p_dlg->AppendTestInfo(tempinfo);
//     }
// 
//     if(flmReadProgramFiles("xpv\\merge.xpv") != TFL_OK)
//     {
//         //std::cout << "Failed to read flash program files" << std::endl;
// 		tempinfo.Format("Failed to read flash program files \r\n"  );
// 		p_dlg->AppendTestInfo(tempinfo);
//         flmClose(devMask);
//       
//     }
// 
//     if(flmProgramSpawn(devMask, 0, 0, 0) != TFL_OK)
//     {
//         //std::cout << "Failed to spawn flash program thread" << std::endl;
// 		tempinfo.Format("Failed to spawn flash program thread \r\n"  );
// 		p_dlg->AppendTestInfo(tempinfo);
//         flmClose(devMask);
//     }
// 	
//     uint16 devicesRunning;
//     int32 progress;
//     do
//     {
//         devicesRunning = 0;
//         for(uint32 devIndex = 0; devIndex < TFL_MAX_DEVICES; ++devIndex)
//         {
//             //Only check the progress if the device is in the mask
//             if((devMask >> devIndex) & 1)
//             {
//                 progress = flmGetDeviceProgress(devIndex);
//                 if(progress < 100)
//                 {
//                     ++devicesRunning;
//                 }
//               
// 				tempinfo.Format("dev %d progress = %d \r\n" , devIndex , progress );
// 				//更新ui
// 				p_dlg->AppendTestInfo(tempinfo); 
//             }
//         }
//         Sleep(1000);
//     }
//     while(devicesRunning > 0);
// 	
//     std::cout << "Completed" << std::endl;
// 	
//     int32 error = flmGetLastError();
//     if(error != TFL_OK)
//     {
//         
// 		tempinfo.Format("Programming failed with error:%d Failed devices mask = %d \r\n" , error , flmGetBitErrorField() );
// 		p_dlg->AppendTestInfo(tempinfo);
// 
//         flmClose(devMask);
//         
//     }
// 	
//     std::cout << "Successfully programmed devices" << std::endl;
//     flmClose(devMask);
// 
// 	//合并文件。
// 	for(vector<std::string>::iterator itr1=ports.begin();itr1!=ports.end();itr1++)
// 	{
// 		int ret=0;
// 		iHandle = openTestEngineSpi(atoi((*itr1).c_str()), 0, SPI_USB );
// 		if(	psMergeFromFile( iHandle , "xpv\\sink_config_10001v4_stereo.psr" ) ==1)
// 		{
// 			//std::cout<<"ps merge sink_config_10001v4_stereo.psr all right "<<std::endl;
// 			tempinfo.Format("ps merge sink_config_10001v4_stereo.psr all right \r\n" );
// 			p_dlg->AppendTestInfo(tempinfo);
// 		}
// 		else
// 		{
// 			//std::cout<<"ps merge sink_config_10001v4_stereo.psr failed "<<std::endl;
// 			tempinfo.Format("ps merge sink_config_10001v4_stereo.psr failed \r\n" );
// 			p_dlg->AppendTestInfo(tempinfo);
// 		}
// 
// 		if(	psMergeFromFile( iHandle , "xpv\\sink_system_csr8670.psr" ) ==1)
// 		{
// 			//std::cout<<"ps merge sink_system_csr8670.psr all right "<<std::endl;
// 			tempinfo.Format("ps merge sink_system_csr8670.psr all right  \r\n" );
// 			p_dlg->AppendTestInfo(tempinfo);
// 		}
// 		else
// 		{
// 			//std::cout<<"ps merge sink_system_csr8670.psr failed "<<std::endl;
// 			tempinfo.Format("ps merge sink_system_csr8670.psr failed  \r\n" );
// 			p_dlg->AppendTestInfo(tempinfo);
// 		}
// 		//sink_system_csr8670.psr
// 
// 		//写入蓝牙名称
// 		uint16 bd_name[20]={'\0'};
// 		strcpy( (char*)bd_name , DEFAULT_BD_NAME );
// 		if(psWrite(iHandle, PSKEY_DEVICE_NAME, PS_STORES_I, 20, bd_name) == TE_OK)
// 		{
// 			//std::cout << "Successfully wrote key PSKEY_DEVICE_NAME " << std::endl;
// 			tempinfo.Format("Successfully wrote key PSKEY_DEVICE_NAME  \r\n" );
// 			p_dlg->AppendTestInfo(tempinfo);
// 		}
// 		else
// 		{
// 			std::cout << "Failed to write key PSKEY_DEVICE_NAME" << std::endl;
// 			tempinfo.Format("Failed to write key PSKEY_DEVICE_NAME  \r\n" );
// 			p_dlg->AppendTestInfo(tempinfo);
// 			//closeTestEngine(iHandle);
// 		}
// 
// 		//读取蓝牙名
// 		uint16 r_bd_name[20]={'\0'};
// 		uint16 name_keySize;
// 		psSize(iHandle, PSKEY_DEVICE_NAME, PS_STORES_IFR, &name_keySize);
// 		std::cout << " name_keySize is " << name_keySize << endl << endl ;
// 		if( ( ret= psRead( iHandle , PSKEY_DEVICE_NAME , PS_STORES_IFR , 0 , r_bd_name , &name_keySize ) )==TE_OK )
// 		{
// 			//std::cout << "r_bd_name[0] = " << r_bd_name[0] << std::endl 
// 			//	<< "r_bd_name[1] = " << r_bd_name[1] << std::endl;
// 			tempinfo.Format("r_bd_name[0] =%s r_bd_name[1] =%s  \r\n" , (char*)r_bd_name[0] , (char*) r_bd_name[1] );
// 			p_dlg->AppendTestInfo(tempinfo);
// 		}
// 		else
// 		{
// 			//std::cout<<"psRead failed PSKEY_DEVICE_NAME " << ret << endl ;
// 			tempinfo.Format("psRead failed PSKEY_DEVICE_NAME=%d  \r\n" , ret );
// 			p_dlg->AppendTestInfo(tempinfo);
// 
// 		}
// 
// 		const uint16 PSKEY_USR0 = 650;
// 		uint16 data[20];
// 		data[0] = data[1] = 0;
// 		uint16 keySize;
//         psSize(iHandle , PSKEY_USR0, PS_STORES_IFR, &keySize);
//         data[0] = data[1] = 0;
// 		
//         if(psRead(iHandle, PSKEY_USR0, PS_STORES_IFR, 16, data, &keySize) == TE_OK)
//         {
//            
// 			tempinfo.Format("data[0] =%d data[1] =%d \r\n",data[0],data[1]   );
// 			p_dlg->AppendTestInfo(tempinfo);
//         }
//         else
//         {
//             //std::cout << "Failed to read key" << std::endl;
// 			tempinfo.Format("Failed to read key  \r\n"   );
// 			p_dlg->AppendTestInfo(tempinfo);
// 
//         }
// 
// 		//设置配对密码
// 		uint16 bd_pwd[20]={'\0'};
// 		strcpy( (char*)bd_pwd , DEFAULT_BD_PWD );
// 		if(psWrite( iHandle , PSKEY_FIXED_PIN , PS_STORES_I, 20 , bd_pwd) == TE_OK)
// 		{
// 			//std::cout << "Successfully wrote key PSKEY_FIXED_PIN" << std::endl;
// 			tempinfo.Format(" Successfully wrote key PSKEY_FIXED_PIN \r\n"   );
// 			p_dlg->AppendTestInfo(tempinfo);
// 		}
// 		else
// 		{
// 		 	tempinfo.Format(" Failed to write key PSKEY_FIXED_PIN \r\n"   );
// 			p_dlg->AppendTestInfo(tempinfo);
// 			//closeTestEngine(iHandle);
// 		}
// 
// 	 
// 		//cvc码（先做读取操作）
// 		uint16 bd_cvc[20]={'\0'};
// 		uint16 cvc_keySize;
// 		if(psRead( iHandle , PSKEY_DSP48 , PS_STORES_I, 16 , bd_cvc , &cvc_keySize) == TE_OK)
// 		{
// 		 
// 			tempinfo.Format("Successfully psRead key PSKEY_DSP48  \r\n"   );
// 			p_dlg->AppendTestInfo(tempinfo);
// 		}
// 		else
// 		{
// 		 
// 			tempinfo.Format("Failed to psRead key PSKEY_DSP48  \r\n"   );
// 			p_dlg->AppendTestInfo(tempinfo);
// 	 
// 		}
// 
// 		//蓝牙地址
// 		uint16 bd_addr[20]={'\0'};
// 		uint16 bdaddr_keySize;
// 		if(psRead( iHandle , PSKEY_BDADDR , PS_STORES_I, 16 , bd_addr , &bdaddr_keySize) == TE_OK)
// 		{
// 		 
// 			tempinfo.Format("Successfully psRead key PSKEY_BDADDR %s \r\n" , (char*)bd_addr );
// 			p_dlg->AppendTestInfo(tempinfo);
// 		}
// 		else
// 		{
//  
// 			tempinfo.Format("Failed to psRead key PSKEY_BDADDR\r\n"  );
// 			p_dlg->AppendTestInfo(tempinfo); 
// 		}
// 
// 		closeTestEngine(iHandle);
// 
// 	}
// 
// 	return 0;
// }









UINT  CBlueToolTestforJoyDlg::thread_ProcessBurnFirm(LPVOID lpParam)
{
  
 
	int ret=0;

	uint32 iHandle(0);

	CString tempinfo;
	
	CBlueToolTestforJoyDlg *p_dlg = (CBlueToolTestforJoyDlg *)lpParam;  


//	CString str_burnfilepath=

	//多路烧录文件。
	bitset<32> bitvec;  //32 bits,all zero
	for(int loop_bs=0 ; loop_bs<p_dlg->m_ports.size() ; loop_bs++ )
	{
		bitvec.set(loop_bs);
	}
	
	int devMask=bitvec.to_ulong();
	if(flmOpen(devMask, 26, TFL_SPI_USB) != TFL_OK)
    {
        //std::cout << "Failed to open devices (" << flmGetBitErrorField() << ")" << std::endl;
		tempinfo.Format("Failed to open devices %d \r\n" ,flmGetBitErrorField() );
		p_dlg->AppendTestInfo( tempinfo , TRUE );
    }

// 	//擦除fl中的内容
// 	if( (ret= flmEraseSpawn( devMask ) ) !=TFL_OK  )
// 	{
// 		tempinfo.Format("擦除fl中的内容失败 %d \r\n" ,ret );
// 		p_dlg->AppendTestInfo(tempinfo,FALSE);
// 	}
// 	else
// 	{
// 		tempinfo.Format("擦除内容成功 %d \r\n" ,ret );
// 		p_dlg->AppendTestInfo(tempinfo);
// 	}


    if(flmReadProgramFiles("xpv\\merge.xpv") != TFL_OK)
    {
        //std::cout << "Failed to read flash program files" << std::endl;
		tempinfo.Format("Failed to read flash program files \r\n"  );
		p_dlg->AppendTestInfo( tempinfo , TRUE);
        flmClose(devMask);
    }

    if(flmProgramSpawn(devMask, 0, 0, 0) != TFL_OK)
    {
        //std::cout << "Failed to spawn flash program thread" << std::endl;
		tempinfo.Format("Failed to spawn flash program thread \r\n"  );
		p_dlg->AppendTestInfo( tempinfo , TRUE);
        flmClose(devMask);
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
				tempinfo.Format("device %d progress = %d \r\n" , devIndex , progress );
				p_dlg->AppendTestInfo(tempinfo); 

            }
        }
        Sleep(1000);
    }
    while(devicesRunning > 0);
	
    //std::cout << "Completed" << std::endl;
	
    int32 error = flmGetLastError();
    if(error != TFL_OK)
    {
        
		tempinfo.Format("failed Programming with error:%d Failed devices mask = %d \r\n" , error , flmGetBitErrorField() );
		p_dlg->AppendTestInfo( tempinfo , TRUE);
        flmClose(devMask);
    }
	
    //std::cout << "Successfully programmed devices" << std::endl;
	tempinfo.Format("succed programmed devices\r\n"  );
	p_dlg->AppendTestInfo( tempinfo );

    flmClose(devMask);

	//合并文件。
	for(vector<std::string>::iterator itr1=p_dlg->m_ports.begin();itr1!=p_dlg->m_ports.end();itr1++)
	{
		int ret=0;
		iHandle = openTestEngineSpi(atoi((*itr1).c_str()), 0, SPI_USB );
		if(	psMergeFromFile( iHandle , "xpv\\sink_config_10001v4_stereo.psr" ) ==1)
		{
			//std::cout<<"ps merge sink_config_10001v4_stereo.psr all right "<<std::endl;
			tempinfo.Format("succed ps merge sink_config_10001v4_stereo.psr all right \r\n" );
			p_dlg->AppendTestInfo(tempinfo);
		}
		else
		{
			//std::cout<<"ps merge sink_config_10001v4_stereo.psr failed "<<std::endl;
			tempinfo.Format("failed port %s ps merge sink_config_10001v4_stereo.psr\r\n", (*itr1).c_str());
			p_dlg->AppendTestInfo(tempinfo, TRUE);
		}

		if(	psMergeFromFile( iHandle , "xpv\\sink_system_csr8670.psr" ) ==1)
		{
			//std::cout<<"ps merge sink_system_csr8670.psr all right "<<std::endl;
			tempinfo.Format("succed ps merge sink_system_csr8670.psr\r\n" );
			p_dlg->AppendTestInfo(tempinfo);
		}
		else
		{
			//std::cout<<"ps merge sink_system_csr8670.psr failed "<<std::endl;
			tempinfo.Format("failed port %s ps merge sink_system_csr8670.psr\r\n" , (*itr1).c_str());
			p_dlg->AppendTestInfo( tempinfo ,TRUE );
		}  

		closeTestEngine(iHandle);

	}
 
    flmClose(devMask);

	return 0;
}














//一个线程处理

void CBlueToolTestforJoyDlg::getHandle(CString &outInfo)
{ 

	//获取可用设备的句柄。
	uint32 iHandle(0);
	uint16 maxLen(256);
	uint16 count(0);
	char* portsStr = new char[maxLen];
	char* transStr = new char[maxLen];
	vector<string> ports; // The human readable port strings (e.g. "LPT1")
	vector<string> trans; // The transport option strings (e.g. "SPITRANS=LPT SPIPORT=1")
	
	CString tempinfo;

	memset(portsStr,0,maxLen);
	int32 status = teGetAvailableSpiPorts(&maxLen, portsStr, transStr, &count);

	//cout<<"teGetAvailableSpiPorts return val:"<<status<<" portstr:"<<portsStr<<" transStr :"<<transStr<<endl;

	if( status != TE_OK && maxLen != 0 )
	{
		// Not enough space - resize the storage
		portsStr = new char[maxLen];
		transStr = new char[maxLen];
		status = teGetAvailableSpiPorts(&maxLen, portsStr, transStr, &count);
		//cout<<"status for teGetAvailableSpiPorts is :"<<status<<endl;
		outInfo.Format("error teGetAvailableSpiPorts %d",status);
	}
	if( status != TE_OK || count == 0 )
	{
		//cout << "Error getting SPI ports, or none found" << endl;
		outInfo.Format("Error getting SPI ports, or none found");
		delete[] portsStr;
		delete[] transStr;
//		return;
	}
	
	//cout<<"----------------\n"<<"portStr:"<<portsStr<<" transStr:"<<transStr<<endl;
	// Split up the comma separated strings of ports / transport options
	ports=split( string(portsStr), string(",")); // Use these for user selection (e.g. drop down list)
	trans=split(string(transStr), string(",")); // Use these to open a transport

	//解析去掉括号	(600895)--->600895
	parseBrackets(ports);

	//多路烧录文件。
	bitset<32> bitvec;  //32 bits,all zero
	for(int loop_bs=0 ; loop_bs<ports.size() ; loop_bs++ )
	{
		bitvec.set(loop_bs);
	}
	
	int devMask=bitvec.to_ulong();
	if(flmOpen(devMask, 26, TFL_SPI_USB) != TFL_OK)
    {
        std::cout << "Failed to open devices (" << flmGetBitErrorField() << ")" << std::endl;
    }

    if(flmReadProgramFiles("xpv\\merge.xpv") != TFL_OK)
    {
        std::cout << "Failed to read flash program files" << std::endl;
        flmClose(devMask);
      
    }

    if(flmProgramSpawn(devMask, 0, 0, 0) != TFL_OK)
    {
        std::cout << "Failed to spawn flash program thread" << std::endl;
        flmClose(devMask);
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
                //std::cout << "dev" << devIndex << " progress = " << progress << "%" << std::endl;
				tempinfo.Format("dev %d progress = %d " , devIndex , progress );
				AppendTestInfo(tempinfo);
            }
        }
        Sleep(1000);
    }
    while(devicesRunning > 0);
	
    std::cout << "Completed" << std::endl;
	
    int32 error = flmGetLastError();
    if(error != TFL_OK)
    {
        std::cout << "Programming failed with error: " << error 
			<< ". Failed devices mask = " << flmGetBitErrorField() << std::endl;
        flmClose(devMask);
        
    }
	
    std::cout << "Successfully programmed devices" << std::endl;
    flmClose(devMask);

	//合并文件。
	for(vector<std::string>::iterator itr1=ports.begin();itr1!=ports.end();itr1++)
	{
		int ret=0;
		iHandle = openTestEngineSpi(atoi((*itr1).c_str()), 0, SPI_USB );
		if(	psMergeFromFile( iHandle , "xpv\\sink_config_10001v4_stereo.psr" ) ==1){
			std::cout<<"ps merge sink_config_10001v4_stereo.psr all right "<<std::endl;
		}else{
			std::cout<<"ps merge sink_config_10001v4_stereo.psr failed "<<std::endl;
		}

		if(	psMergeFromFile( iHandle , "xpv\\sink_system_csr8670.psr" ) ==1){
			std::cout<<"ps merge sink_system_csr8670.psr all right "<<std::endl;
		}else{
			std::cout<<"ps merge sink_system_csr8670.psr failed "<<std::endl;
		}
		//sink_system_csr8670.psr

		//写入蓝牙名称
		uint16 bd_name[20]={'\0'};
		strcpy( (char*)bd_name , DEFAULT_BD_NAME );
		if(psWrite(iHandle, PSKEY_DEVICE_NAME, PS_STORES_I, 20, bd_name) == TE_OK)
		{
			std::cout << "Successfully wrote key PSKEY_DEVICE_NAME " << std::endl;
		}
		else
		{
			std::cout << "Failed to write key PSKEY_DEVICE_NAME" << std::endl;
			//closeTestEngine(iHandle);
		}

		//读取蓝牙名
		uint16 r_bd_name[20]={'\0'};
		uint16 name_keySize;
		psSize(iHandle, PSKEY_DEVICE_NAME, PS_STORES_IFR, &name_keySize);
		std::cout << " name_keySize is " << name_keySize << endl << endl ;
		if( ( ret= psRead( iHandle , PSKEY_DEVICE_NAME , PS_STORES_IFR , 0 , r_bd_name , &name_keySize ) )==TE_OK )
		{
			std::cout << "r_bd_name[0] = " << r_bd_name[0] << std::endl 
				<< "r_bd_name[1] = " << r_bd_name[1] << std::endl;
		}else{
			std::cout<<"psRead failed PSKEY_DEVICE_NAME " << ret << endl ;
		}

		const uint16 PSKEY_USR0 = 650;
		uint16 data[20];
		data[0] = data[1] = 0;
		uint16 keySize;
        psSize(iHandle , PSKEY_USR0, PS_STORES_IFR, &keySize);
        data[0] = data[1] = 0;
		
        if(psRead(iHandle, PSKEY_USR0, PS_STORES_IFR, 16, data, &keySize) == TE_OK)
        {
            std::cout << "data[0] = " << data[0] << std::endl 
				<< "data[1] = " << data[1] << std::endl;
        }
        else
        {
            std::cout << "Failed to read key" << std::endl;
        }

		//设置配对密码
		uint16 bd_pwd[20]={'\0'};
		strcpy( (char*)bd_pwd , DEFAULT_BD_PWD );
		if(psWrite( iHandle , PSKEY_FIXED_PIN , PS_STORES_I, 20 , bd_pwd) == TE_OK)
		{
			std::cout << "Successfully wrote key PSKEY_FIXED_PIN" << std::endl;
		}
		else
		{
			std::cout << "Failed to write key PSKEY_FIXED_PIN" << std::endl;
			//closeTestEngine(iHandle);
		}

		//if( ( ret= psRead( iHandle , PSKEY_DEVICE_NAME , PS_STORES_I , 16 , data , &keySize ) )==TE_OK )
		//cvc码（先做读取操作）
		uint16 bd_cvc[20]={'\0'};
		uint16 cvc_keySize;
		if(psRead( iHandle , PSKEY_DSP48 , PS_STORES_I, 16 , bd_cvc , &cvc_keySize) == TE_OK)
		{
			std::cout << "Successfully psRead key PSKEY_DSP48 " << bd_cvc << std::endl;
		}
		else
		{
			std::cout << "Failed to psRead key PSKEY_DSP48" << std::endl;
			//closeTestEngine(iHandle);
		}

		//蓝牙地址
		uint16 bd_addr[20]={'\0'};
		uint16 bdaddr_keySize;
		if(psRead( iHandle , PSKEY_BDADDR , PS_STORES_I, 16 , bd_addr , &bdaddr_keySize) == TE_OK)
		{
			std::cout << "Successfully psRead key PSKEY_BDADDR" << bd_addr << std::endl;
		}
		else
		{
			std::cout << "Failed to psRead key PSKEY_BDADDR" << std::endl;
		//	closeTestEngine(iHandle);
		}

		closeTestEngine(iHandle);

	}


// 	while(1)
// 		;

	for(vector<std::string>::iterator itr=ports.begin();itr!=ports.end();itr++)
	{
		int ret=0;
		iHandle = openTestEngineSpi(atoi((*itr).c_str()), 0, SPI_USB );
		
		if( iHandle != 0)
		{
			
			uint16 data[20]={'\0'};
			uint16 keySize;
			if( ( ret= psRead( iHandle , PSKEY_DEVICE_NAME , PS_STORES_I , 16 , data , &keySize ) )==TE_OK )
			{
				std::cout << "data[0] = " << data[0] << std::endl 
					<< "data[1] = " << data[1] << std::endl;
			}else{
				std::cout<<"psRead failed " << ret << endl ;
			}
			
			
			
			if(int ret=flInit(atoi((*itr).c_str()), 26, 2 , TFL_SPI_USB ) != TFL_OK)
			{
				std::cout << "Failed to flInit flash:"<<ret << std::endl;
			}
			else
			{
				cout<<"flInit ok ..."<<ret <<endl;
			}
			
			if(flReadProgramFiles("xpv\\merge.xpv") != TFL_OK)
			{
				std::cout << "Failed to read flash program files" << std::endl;
				flClose();
				
			}else{
				std::cout << "flReadProgramFiles succed "<<std::endl;
			}
			
			if(flProgramSpawn() != TFL_OK)
			{
				std::cout << "Failed to spawn flash program thread" << std::endl;
				flClose();
				
			}else{
				std::cout << "flProgramSpawn succed "<<std::endl;
			}
			
			
			int32 progress = flGetProgress();
			while(progress < 100)
			{
				std::cout << "Programming..." << progress << "%" << std::endl;
				Sleep(1000);
				progress = flGetProgress();
			}
			std::cout << "Completed" << std::endl;
			
			int32 error = flGetLastError();
			if(error != TFL_OK)
			{
				std::cout << "Programming failed with error: " << error << std::endl;
				flClose();
			}
			
			std::cout << "Successfully programmed device" << std::endl;
			flClose();
			
	 
			strcpy( (char*)data , "xiesong" );
			if(psWrite(iHandle, PSKEY_DEVICE_NAME, PS_STORES_I, 20, data) == TE_OK)
			{
				std::cout << "Successfully wrote key" << std::endl;
			}
			else
			{
				std::cout << "Failed to write key" << std::endl;
				closeTestEngine(iHandle);
			}
			
			uint16 temp=0;
			ret = bccmdGetChipVersion( iHandle , &temp );
            if(ret == TE_OK)
            {
                cout << "Chip version = " << temp <<" ;"<< endl;
            }else{
				
			}
			
			cout << "openTestEngineSpi Connected!" << endl;
			// Perform all your testing here
			closeTestEngine(iHandle);
		}
		else
		{
			cout<<"openTestEngineSpi failed"<<endl;
		}
				
		cout<<" iterator :"<<*itr<<endl;
		
	}
	
	delete[] portsStr;
	delete[] transStr;
	
	return;

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
	while(count--){
		lst.push_back("111111");//push_back("3465 A979 BC24 C86D 01FF");
	}
}


void CBlueToolTestforJoyDlg::readMAC(std::vector<std::string> &lst,int count)
{
	while(count--){
		lst.push_back("123456789");//push_back("00025b00ff01");
	}
}


void CBlueToolTestforJoyDlg::OnButtonDetectdevice() 
{
	// TODO: Add your control notification handler code here
	
	CString strfile,strname;
	m_edit_global_burnfile.GetWindowText(strfile);
	
	m_edit_global_burnname.GetWindowText(strname);
	
	if (strfile.IsEmpty()&&strname.IsEmpty())
	{
		MessageBox("请设置烧录文件和设备名称");
		return;
	}
	
	clearStatus();
	m_ports.clear();
	m_trans.clear();
	m_cvc.clear();
	m_mac.clear();
	m_itemlists.clear();



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
		delete[] portsStr;
		delete[] transStr; 
	} 
	
	// Split up the comma separated strings of ports / transport options
	m_ports=split( string(portsStr), string(",")); // Use these for user selection (e.g. drop down list)
	m_trans=split(string(transStr), string(",")); // Use these to open a transport
	
	//解析去掉括号	(600895)--->600895
	parseBrackets(m_ports);
	
	
	//读取蓝牙mac地址。到一个vector，读取一个cvc列表到List
	readCVC(m_cvc,m_ports.size());
	
	//读取蓝牙设备的Mac地址到list
	readMAC(m_mac,m_ports.size());
	
	
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
	delete[] portsStr;
	delete[] transStr; 
	
}






void CBlueToolTestforJoyDlg::clearStatus()
{
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
		int ret=0;
		iHandle = openTestEngineSpi( atoi( itr1->getPort().c_str() ) , 0 , SPI_USB ); 
		//写入蓝牙名称
		uint16 bd_name[20]={'\0'};
		strcpy( (char*)bd_name , DEFAULT_BD_NAME );
		if(psWrite(iHandle, PSKEY_DEVICE_NAME, PS_STORES_I, 20, bd_name) == TE_OK)
		{
			tempinfo.Format("Successfully wrote key PSKEY_DEVICE_NAME \r\n" );
			p_dlg->AppendTestInfo(tempinfo);
		}
		else
		{
			tempinfo.Format("Failed %s to write key PSKEY_DEVICE_NAME\r\n" ,itr1->getPort().c_str() );
			p_dlg->AppendTestInfo( tempinfo , TRUE );
		}
		
		//设置配对密码
		uint16 bd_pwd[20]={'\0'};
		strcpy( (char*)bd_pwd , DEFAULT_BD_PWD );
		if(psWrite( iHandle , PSKEY_FIXED_PIN , PS_STORES_I, 20 , bd_pwd) == TE_OK)
		{ 
			tempinfo.Format("Successfully wrote key PSKEY_FIXED_PIN \r\n" );
			p_dlg->AppendTestInfo( tempinfo  );
		}
		else
		{ 
			tempinfo.Format("Failed %s to write key PSKEY_FIXED_PIN \r\n",itr1->getPort().c_str() );
			p_dlg->AppendTestInfo( tempinfo , TRUE);
		}
		
		//cvc码（先做读取操作）
		uint16 bd_cvc[20]={'\0'};
		strcpy( (char*)bd_cvc , itr1->getCVC().c_str() );
		if(psWrite( iHandle , PSKEY_DSP48 , PS_STORES_I, 20 , bd_cvc ) == TE_OK)
		{ 
			tempinfo.Format("Successfully wrote key PSKEY_DSP48 \r\n" );
			p_dlg->AppendTestInfo( tempinfo );
		}
		else
		{ 
			tempinfo.Format("Failed %s to write key PSKEY_DSP48 \r\n" ,itr1->getPort().c_str() );
			p_dlg->AppendTestInfo(tempinfo , TRUE);
		}
		
		//蓝牙地址 
		uint16 bd_addr[4]={'\0'};
		strcpy( (char*)bd_addr , itr1->getMac().c_str() );
		if(psWrite( iHandle , PSKEY_BDADDR , PS_STORES_I,  4 , bd_addr ) == TE_OK)
		{ 
			tempinfo.Format("Successfully wrote key PSKEY_BDADDR %s \r\n" , itr1->getMac().c_str() );
			p_dlg->AppendTestInfo(tempinfo);
		}
		else
		{ 
			tempinfo.Format("Failed %s to write key PSKEY_BDADDR \r\n" ,itr1->getPort().c_str() );
			p_dlg->AppendTestInfo(tempinfo , TRUE );
		}
		
		closeTestEngine(iHandle);
		
	}
	
	return 1;
}
