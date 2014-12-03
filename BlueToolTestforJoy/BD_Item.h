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

private:
	std::string _bd_port;
	std::string _bd_mac;
	std::string _bd_cvc;



};

#endif // !defined(AFX_BD_ITEM_H__10312ADA_F678_4F33_8A5C_B50F13077975__INCLUDED_)
