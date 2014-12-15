// DBManager.h: interface for the DBManager class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DBMANAGER_H__38D6D86B_0FDC_4E64_92D5_101CA85ED651__INCLUDED_)
#define AFX_DBMANAGER_H__38D6D86B_0FDC_4E64_92D5_101CA85ED651__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "ADO\Connection.h"
#include "ADO\Command.h"
#include "ADO\Recordset.h"

#include <vector>
#include "BD_Item.h"
class DBManager  
{
public:
	DBManager();
	virtual ~DBManager();


	bool InitConnection();


	int Update_KeyCvc(  /*CString usd_time ,*/ CString usd_mac);
 
	int Update_KeyMac( /*CString usd_time , */CString usd_mac);


	//int Read_Key(CString dbtable , CString key, const int rcount ,  std::vector<std::string> & vtor);
	int Read_CVC( const int rcount , std::vector<std::string> & vtor);

	int Read_MAC( const int rcount , std::vector<std::string> & vtor);

	int InsertDevice(BD_Item &item);


private:
	CConnection m_Conn;
	CRecordset  m_Rst;
	CCommand    m_Cmd;



};

#endif // !defined(AFX_DBMANAGER_H__38D6D86B_0FDC_4E64_92D5_101CA85ED651__INCLUDED_)
