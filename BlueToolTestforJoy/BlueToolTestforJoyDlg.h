// BlueToolTestforJoyDlg.h : header file
//

#if !defined(AFX_BLUETOOLTESTFORJOYDLG_H__D9AD1145_EB8C_4043_9385_BABDA28DBEE1__INCLUDED_)
#define AFX_BLUETOOLTESTFORJOYDLG_H__D9AD1145_EB8C_4043_9385_BABDA28DBEE1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#pragma   warning(disable:4786)

#include <VECTOR>
#include <STRING>

#include <iostream>
#include <windows.h> 
#include "testflash.h"
#include "testengine.h"
#include "TestPS.h"
#include <bitset>

#include "BD_Item.h"

#include "DBManager.h"

using namespace std;

#define MAX_TIMEOUT 5000

#define PSKEY_DEVICE_NAME					0x0108				//蓝牙设备名
#define PSKEY_FIXED_PIN						0x035b				//蓝牙设备配对密码
#define PSKEY_DSP48							0x2288				//cvc码
#define PSKEY_BDADDR						0x0001				//蓝牙地址
#define PSKEY_ANA_FTRIM_OFFSET				9619
#define PR0TECTED_CONST_DEFAULT_LO_FREQ		2441				//Protected Const DEFAULT_LO_FREQ As Integer = 2441

#define PSKEY_ANA_FREQ	9619				//频率校准，数据不详，待问。


#define DEFAULT_BD_NAME		"koovox"
#define DEFAULT_BD_PWD		"koovox"

#define INFOFORMATE	"烧录程序%s;蓝牙名称%s;蓝牙地址%s;CVC码%s;\r\n"

#define ALL_PASSED "合格"

#define ALL_FAILED "不合格"

#define WM_UPDATEINFO WM_USER+8

#define STATIC_FIRMFILE "\\xpv"

#define BTN_CALL		11
#define BTN_VOICEDOWN	12
#define BTN_VOICEUP		13 
#define BTN_MSG			14
/////////////////////////////////////////////////////////////////////////////
// CBlueToolTestforJoyDlg dialog



/*

finished list
---------------------------------------------

2014.12.09
本地数据读写

2014.12.10
判断当前设备是否已经有烧录，写入。。。。
如果已经烧录写入，则不可浪费自己的mac和cvc。

----------------------------------------------
TODO list

本地数据<----同步---->服务端。

设备频率测试。

操作手册。

*/


class CBlueToolTestforJoyDlg : public CDialog
{
// Construction
public:
	CBlueToolTestforJoyDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CBlueToolTestforJoyDlg)
	enum { IDD = IDD_BLUETOOLTESTFORJOY_DIALOG };
	CStatic	m_label_result9;
	CStatic	m_label_result8;
	CStatic	m_label_result7;
	CStatic	m_label_result6;
	CStatic	m_label_result5;
	CStatic	m_label_result4;
	CStatic	m_label_result3;
	CStatic	m_label_result2;
	CStatic	m_label_result16;
	CStatic	m_label_result15;
	CStatic	m_label_result14;
	CStatic	m_label_result13;
	CStatic	m_label_result12;
	CStatic	m_label_result11;
	CStatic	m_label_result10;
	CStatic	m_label_result1;
	CEdit	m_edit_cvc14;
	CEdit	m_edit_cvc9;
	CEdit	m_edit_cvc8;
	CEdit	m_edit_cvc7;
	CEdit	m_edit_cvc6;
	CEdit	m_edit_cvc5;
	CEdit	m_edit_cvc4;
	CEdit	m_edit_cvc3;
	CEdit	m_edit_cvc2;
	CEdit	m_edit_cvc16;
	CEdit	m_edit_cvc15;
	CEdit	m_edit_cvc13;
	CEdit	m_edit_cvc12;
	CEdit	m_edit_cvc11;
	CEdit	m_edit_cvc10;
	CEdit	m_edit_cvc1;
	CEdit	m_edit_did9;
	CEdit	m_edit_did8;
	CEdit	m_edit_did7;
	CEdit	m_edit_did5;
	CEdit	m_edit_did6;
	CEdit	m_edit_did4;
	CEdit	m_edit_did3;
	CEdit	m_edit_did2;
	CEdit	m_edit_did16;
	CEdit	m_edit_did15;
	CEdit	m_edit_did14;
	CEdit	m_edit_did13;
	CEdit	m_edit_did12;
	CEdit	m_edit_did11;
	CEdit	m_edit_did10;
	CEdit	m_edit_did1;
	CEdit	m_edit_macaddr9;
	CEdit	m_edit_macaddr8;
	CEdit	m_edit_macaddr7;
	CEdit	m_edit_macaddr6;
	CEdit	m_edit_macaddr5;
	CEdit	m_edit_macaddr4;
	CEdit	m_edit_macaddr3;
	CEdit	m_edit_macaddr2;
	CEdit	m_edit_macaddr16;
	CEdit	m_edit_macaddr15;
	CEdit	m_edit_macaddr14;
	CEdit	m_edit_macaddr13;
	CEdit	m_edit_macaddr12;
	CEdit	m_edit_macaddr10;
	CEdit	m_edit_macaddr11;
	CEdit	m_edit_macaddr1;
	CButton	m_ckport9;
	CButton	m_ckport8;
	CButton	m_ckport7;
	CButton	m_ckport6;
	CButton	m_ckport5;
	CButton	m_ckport4;
	CButton	m_ckport3;
	CButton	m_ckport2;
	CButton	m_ckport16;
	CButton	m_ckport15;
	CButton	m_ckport14;
	CButton	m_ckport13;
	CButton	m_ckport11;
	CButton	m_ckport12;
	CButton	m_ckport10;
	CButton	m_ckport1;
	CEdit	m_edit_global_burnname;
	CEdit	m_edit_global_burnfile;
	CButton	m_test_do;
	CButton	m_btncancel;
	CRichEditCtrl	m_redit_outinfo;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBlueToolTestforJoyDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CBlueToolTestforJoyDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnTestDo();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnButtonBurn();
	afx_msg LRESULT ui_callback(WPARAM,LPARAM);
	afx_msg void OnButtonDetectdevice();
	afx_msg void OnButtonWritecheck();
	afx_msg void OnButtonNextdc();
	afx_msg void OnButtonFormer();
	afx_msg void OnButtonHardbtnall();
	afx_msg void OnButtonHardbtn1();
	afx_msg void OnButtonHardbtn2();
	afx_msg void OnButtonHardbtn3();
	afx_msg void OnButtonCall();
	afx_msg void OnButtonHardbtnbegin();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

		
private:

	int m_lines;
	vector<string> m_ports; // The human readable port strings (e.g. "LPT1")
	vector<string> m_trans; // The transport option strings (e.g. "SPITRANS=LPT SPIPORT=1")
	vector<std::string> m_cvc;	//cvc lists.
	std::vector<std::string> m_mac;

	
	
	vector<BD_Item> m_itemlists;
	std::vector<BD_Item>::size_type m_hardcheckindex  ;


	DBManager m_manager ;

public:

	void AppendTestInfo(CString strInfo,BOOL b_color=FALSE);
	
	static std::vector<std::string> split(std::string str,std::string pattern);
	
	static void parseBrackets(std::vector<std::string> &vt);
	
	
//	void getHandle(CString &outInfo);
	
	static UINT thread_HardwareCheck(LPVOID lpParam);
	
	static UINT  thread_ProcessBurnFirm(LPVOID lpParam);
	
	static UINT  thread_WriteCheckFreq(LPVOID lpParam);
	
	void readCVC(std::vector<std::string> &lst,int count);
	
	void readMAC(std::vector<std::string> &lst,int count);
	
	void clearStatus();
	
	void InitCtrl();
	
	void CheckFreq();
	
	static UINT TurnLightOn(LPVOID lpParam);
	static UINT TurnIndexedLightOn(LPVOID lpParam);
	
	static UINT  TurnIndexedLightOnForever(LPVOID lpParam);

	static UINT  TurnIndexedLightOff(LPVOID lpParam);

	static int SingleBurn(int index , void * phandle);

	int CheckConnection();
	bool isDeviceConnectable(int index);

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BLUETOOLTESTFORJOYDLG_H__D9AD1145_EB8C_4043_9385_BABDA28DBEE1__INCLUDED_)
