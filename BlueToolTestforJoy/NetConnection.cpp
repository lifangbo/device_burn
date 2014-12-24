// NetConnection.cpp: implementation of the NetConnection class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "BlueToolTestforJoy.h"
#include "NetConnection.h"

#include <windows.h>
#include <Winsock2.h>
#include <iostream>
#pragma  comment(lib,"ws2_32.lib")

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

NetConnection* NetConnection::m_pInstance = NULL; 


NetConnection::NetConnection()
{

}

NetConnection::~NetConnection()
{

}


NetConnection* NetConnection::Instance()
{
	if (!m_pInstance)   // Only allow one instance of class to be generated.
		m_pInstance = new NetConnection;
	
	return m_pInstance;
}


int NetConnection::connect_server()
{
	int retVal=0;

	SOCKET clientSocket=socket(AF_INET,SOCK_STREAM,0);
	SOCKADDR_IN clientsock_in;
    clientsock_in.sin_addr.S_un.S_addr=inet_addr("192.168.0.113");
    clientsock_in.sin_family=AF_INET;
    clientsock_in.sin_port=htons(8080); 
    retVal = connect(clientSocket,(SOCKADDR*)&clientsock_in,sizeof(SOCKADDR));//开始连接 
	return retVal;
}



//only could send char buf, 
//if it contains none character, bugs may happen.
int NetConnection::send_buf(const char * buf,char * receiveBuf,int len)
{
//	char receiveBuf[10000]={'\0'};
	int retVal=0;
//	sprintf(buf, "%s","{\"count\": 16,\"testor\": \"test1\",\"pwd\": \"test1'pwd1\"}"); 
	char package[3072]={'\0'}; 
	//pack head
	strcat(package,"1234");
	//pack len
	char buflen[5]={'\0'};
	sprintf(buflen,"%04d",strlen(buf));
	strcat(package,buflen);
	
	//pack operation code
	char operbuf[5]={'\0'};
	sprintf(operbuf,"%04d",1002);
	strcat(package,operbuf);
	//data buf .
	strcat(package,buf);
	//pack end
	strcat(package,"4321");
	send(clientSocket, package ,strlen(package)+1,0);
	int rec_len=0;
	char temp[1500]={'\0'};
recive:
	memset(temp,0,sizeof(temp));
	rec_len=recv(clientSocket,temp,len,0);
	if ( (*(temp+rec_len-1-4)=='1')&&
		( *(temp+rec_len-1-4+1) == '2' )&&
		( *(temp+rec_len-1-4+2) == '3' )&&
		( *(temp+rec_len-1-4+3) == '4' )
	)//finished a package.
	{
		
	}

	return retVal;
}