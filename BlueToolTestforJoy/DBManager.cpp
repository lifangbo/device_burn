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

bool DBManager::InitConnection()
{
	bool ret =false;
	m_Conn.SetConnectionString("Provider=Microsoft.Jet.OLEDB.4.0; Data Source= blueinfo.mdb;Jet OLEDB:DataBase password=;");
	ret = m_Conn.Open("","","",ConnectOption::adConnectUnspecified); 
    m_Cmd.SetActiveConnection(m_Conn);
	return  ret;
}



int DBManager::Update_KeyCvc(/* CString usd_time ,*/ CString usd_mac)
{
	int ret=0;

	CString strTime ;
	CTime time = CTime::GetCurrentTime();
	strTime = time.Format("%Y-%m-%d %H:%M:%S");

	CString sql;
	sql.Format("update t_cvc set used=1 , used_time='%s' where cvc='%s'"  , strTime , usd_mac );
	m_Cmd.SetCommandText(sql);
	long rows=0;
	m_Cmd.ExecuteUpdate(rows,CommandType::adCmdText,m_Rst);
	return ret;
}





int DBManager::Update_KeyMac(/* CString usd_time ,*/ CString usd_mac)
{
	int ret=0;

	CString strTime ;
	CTime time = CTime::GetCurrentTime();
	strTime = time.Format("%Y-%m-%d %H:%M:%S");

	CString sql;
	sql.Format("update t_mac set used=1 , used_time='%s' where mac='%s'"  , strTime , usd_mac );
	m_Cmd.SetCommandText(sql);
	long rows=0;
	m_Cmd.ExecuteUpdate(rows,CommandType::adCmdText,m_Rst);
	return ret;
}




int DBManager::Read_CVC( const int rcount , std::vector<std::string> & vtor)
{

	int ret=0;
	int rows=0;
	CString strSql;
	strSql.Format("select top %d cvc from t_cvc where used=0" ,rcount );
	m_Cmd.SetCommandText(strSql);
	m_Rst.Release();
	m_Cmd.ExecuteQuery( CommandType::adCmdText , m_Rst);
	
	ret = m_Rst.GetRecordCount();

	int pos = 0; 
	while((m_Rst.GetRecordCount()>= m_Rst.GetAbsolutePosition() ) && (m_Rst.GetAbsolutePosition()>=1) )
	{
		vtor.push_back(m_Rst.GetString("cvc").GetBuffer(0));
		m_Rst.MoveNext();
	}

	return ret;

}





int DBManager::Read_MAC( const int rcount , std::vector<std::string> & vtor)
{
	
	int ret=0;
	int rows=0;
	CString strSql;
	strSql.Format("select top %d mac from t_mac where used=0" ,rcount  );
	m_Cmd.SetCommandText(strSql);
	m_Rst.Release();
	m_Cmd.ExecuteQuery( CommandType::adCmdText , m_Rst);
	
	ret = m_Rst.GetRecordCount();
	
	while((m_Rst.GetRecordCount()>= m_Rst.GetAbsolutePosition() ) && (m_Rst.GetAbsolutePosition()>=1) )
	{
		vtor.push_back(m_Rst.GetString("mac").GetBuffer(0));
		m_Rst.MoveNext();
	}
	return ret;
	
}




int DBManager::InsertDevice(BD_Item &item)
{
	
	item.getMac() ;
	item.getCVC();
	int i= (int)item.isSpawnFileSucced ;
 
	CString strTime ;
	CTime time = CTime::GetCurrentTime();
	strTime = time.Format("%Y-%m-%d %H:%M:%S");

	int ret=0;
	CString sql;
	sql.Format("insert into t_device(mac,cvc,test_time,r_spawnfile,r_merge_system,r_merge_config,r_freqchk,r_writename,r_writeaddr,r_writecvc) values ('%s','%s','%s',%d , %d ,%d , %d , %d , %d , %d)", item.getMac().c_str() ,item.getCVC().c_str() , strTime , (int)item.isSpawnFileSucced , (int)item.isMergeSystemFileSucced , (int)item.isMergeConfigFileSucced , (int)item.isFreqCheckSucced , (int)item.isDeviceNameWrite , (int)item.isMacWriteSucced , (int)item.isCvcWriteSucced );
	m_Cmd.SetCommandText(sql);
	long rows=0;
	m_Cmd.ExecuteUpdate(rows,CommandType::adCmdText,m_Rst);
	return ret;
}