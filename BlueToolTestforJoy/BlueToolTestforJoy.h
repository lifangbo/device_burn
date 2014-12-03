// BlueToolTestforJoy.h : main header file for the BLUETOOLTESTFORJOY application
//

#if !defined(AFX_BLUETOOLTESTFORJOY_H__F725E11E_5E0C_40DF_80F8_05F2840699F4__INCLUDED_)
#define AFX_BLUETOOLTESTFORJOY_H__F725E11E_5E0C_40DF_80F8_05F2840699F4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CBlueToolTestforJoyApp:
// See BlueToolTestforJoy.cpp for the implementation of this class
//

class CBlueToolTestforJoyApp : public CWinApp
{
public:
	CBlueToolTestforJoyApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBlueToolTestforJoyApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CBlueToolTestforJoyApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BLUETOOLTESTFORJOY_H__F725E11E_5E0C_40DF_80F8_05F2840699F4__INCLUDED_)
