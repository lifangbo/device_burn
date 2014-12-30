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

#include <string>


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
	isconnected = false ;
}

NetConnection::~NetConnection()
{

}


NetConnection* NetConnection::Instance()
{
	if (!m_pInstance)   // Only allow one instance of class to be generated.
	{
		m_pInstance = new NetConnection;
	
	}
	
	return m_pInstance;
}


int NetConnection::connect_server()
{
	if (isconnected)
	{
		return -1;
	}
	int retVal=0; 

	int err;
    WORD versionRequired;
	WSADATA wsaData;
    versionRequired=MAKEWORD(1,1);
    err=WSAStartup(versionRequired,&wsaData);//协议库的版本信息
    if (!err)    {
        printf("客户端嵌套字已经打开!\n");
    }else{
        printf("ERROR:客户端的嵌套字打开失败!\n");
        return 1;//结束
    }
	clientSocket=socket(AF_INET,SOCK_STREAM,0);
	SOCKADDR_IN clientsock_in;
    clientsock_in.sin_addr.S_un.S_addr=inet_addr("192.168.0.113");
    clientsock_in.sin_family=AF_INET;
    clientsock_in.sin_port=htons(8080); 
    retVal = connect(clientSocket,(SOCKADDR*)&clientsock_in,sizeof(SOCKADDR));//开始连接 

	isconnected= true;
	return retVal;
}



//only could send char buf, 
//if it contains none character, bugs may happen.
int NetConnection::send_buf(const char * buf,std::string &rec_str,int operation)
{

//	char receiveBuf[10000]={'\0'};
	int retVal=0; 
	char package[3072]={'\0'}; 
	//pack head
	strcat(package,"1234");
	//pack len
	char buflen[5]={'\0'};
	sprintf(buflen,"%04d",strlen(buf));
	strcat(package,buflen);
	
	//pack operation code
	char operbuf[5]={'\0'};
	sprintf(operbuf,"%04d",operation);
	strcat(package,operbuf);
	//data buf .
	strcat(package,buf);
	//pack end
	strcat(package,"4321");
	send(clientSocket, package ,strlen(package)+1,0);
	int rec_len=0;
	const int len=1500;
	char rec_temp[len]={'\0'};
 

	rec_len=recv(clientSocket,rec_temp,len-1,0);

	rec_str.append(rec_temp);

//	return retVal;
	while ( !( (*(rec_temp+rec_len-1-4+1)=='4')&&
		( *(rec_temp+rec_len-1-4+2) == '3' )&&
		( *(rec_temp+rec_len-1-4+3) == '2' )&&
		( *(rec_temp+rec_len-1-4+4) == '1' ) )
	)//finished a package.
	{
 
		int l=sizeof(rec_temp);

		memset(rec_temp,0,sizeof(rec_temp));
		rec_len=recv(clientSocket,rec_temp,len-1,0);
 
		rec_str.append(rec_temp);
	} 

	return retVal;

}