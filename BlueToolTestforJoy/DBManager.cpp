// DBManager.cpp: implementation of the DBManager class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "BlueToolTestforJoy.h"
#include "DBManager.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

DBManager::DBManager()
{

}

DBManager::~DBManager()
{

}

int DBManager::InitConnection()
{
	int ret=0;
	m_Conn.SetConnectionString("Provider=Microsoft.Jet.OLEDB.4.0; Data Source= blueinfo.mdb;Jet OLEDB:DataBase password=;");
	m_Conn.Open("","","",ConnectOption::adConnectUnspecified); 
    m_Cmd.SetActiveConnection(m_Conn);
	return ret;
}



int DBManager::Update_TMac(CString usd_time , CString usd_mac)
{
	int ret=0;
	CString sql;
	sql.Format("update t_mac set used=1 , used_time='%s' where mac='%s'" , usd_time , usd_mac );
	m_Cmd.SetCommandText(sql);
	long rows=0;
	m_Cmd.ExecuteUpdate(rows,CommandType::adCmdText,m_Rst);
	return ret;
}



int DBManager::Read_Key(CString dbtable , CString key , const int rcount , std::vector<std::string> & vtor)
{

	int ret=0;
	int rows=0;
	CString strSql;
	strSql.Format("select top %d %s from %s where used=0" ,rcount ,key , dbtable);
	m_Cmd.SetCommandText(strSql);
	m_Rst.Release();
	m_Cmd.ExecuteQuery( CommandType::adCmdText , m_Rst);
	
	while(m_Rst.GetRecordCount()>0)
	{
		vtor.push_back(m_Rst.GetString(key).GetBuffer(0));
		m_Rst.MoveNext();
	}

	return ret;

}