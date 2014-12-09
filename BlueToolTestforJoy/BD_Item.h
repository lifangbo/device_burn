// BD_Item.h: interface for the BD_Item class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BD_ITEM_H__10312ADA_F678_4F33_8A5C_B50F13077975__INCLUDED_)
#define AFX_BD_ITEM_H__10312ADA_F678_4F33_8A5C_B50F13077975__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <STRING>

class BD_Item  
{
public:
	BD_Item();
	virtual ~BD_Item();

	void setPort(std::string port){
		_bd_port=port;
	}
	std::string getPort(void){
		return _bd_port;
	}
	void setMac(std::string mac){
		_bd_mac=mac;
	}
	std::string getMac(){
		return _bd_mac;
	}
	void setCVC(std::string cvc){
		_bd_cvc=cvc;
	}
	std::string getCVC(){
		return _bd_cvc;
	}

	bool isAllPass();			//所有测试事项是否通过。


	bool isSpawnFileSucced ;	//烧录文件是否成功

	bool isMergeConfigFileSucced ;	//合并配置文件是否成功

	bool isMergeSystemFileSucced ;	//合并系统文件是否成功

	bool isMacWriteSucced ;			//写入mac是否成功

	bool isCvcWriteSucced ;			//cvc码是否写入成功

	bool isDeviceNameWrite ;		//设备名是否写入成功

	bool isFreqCheckSucced ;		//频率检查是否成功


	bool isVoiceDownSucced ;		//音量-

	bool isVoiceUpSucced ;			//音量+

	bool isMsgSucced ;				//消息键是否测试通过

	bool isCallSucced ;				//呼叫键是否测试通过

private:


	std::string _bd_port;		//设备的spi端口号。
	std::string _bd_mac;		//分配给此设备的mac地址。
	std::string _bd_cvc;		//分配给此设备的cvc码



};

#endif // !defined(AFX_BD_ITEM_H__10312ADA_F678_4F33_8A5C_B50F13077975__INCLUDED_)
