// NetConnection.h: interface for the NetConnection class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_NETCONNECTION_H__BD1D870C_698E_43A1_BC41_41F3B3BDAE21__INCLUDED_)
#define AFX_NETCONNECTION_H__BD1D870C_698E_43A1_BC41_41F3B3BDAE21__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <Winsock2.h>
#include <string>

class NetConnection  
{
private:
	NetConnection();
	NetConnection(NetConnection const&){};             // copy constructor is private
	NetConnection& operator=(NetConnection const&){};  // assignment operator is private
	static NetConnection* m_pInstance;
	bool isconnected;
public:
	virtual ~NetConnection();

	static NetConnection* Instance();

	SOCKET clientSocket;


	int connect_server();
	int send_buf(const char * buf,std::string &rec_str,int operation);

};

#endif // !defined(AFX_NETCONNECTION_H__BD1D870C_698E_43A1_BC41_41F3B3BDAE21__INCLUDED_)
