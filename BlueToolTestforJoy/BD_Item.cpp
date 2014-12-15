// BD_Item.cpp: implementation of the BD_Item class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "BlueToolTestforJoy.h"
#include "BD_Item.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

BD_Item::BD_Item()
{
	isCvcWriteSucced = false ;
	isFreqCheckSucced = false ;
	isMacWriteSucced = false ;
	isMergeConfigFileSucced = false ;
	isMergeSystemFileSucced = false ;
	isSpawnFileSucced = true ;
	isDeviceNameWrite = false ;

	isVoiceDownSucced =false ;		//音量-
	isVoiceUpSucced =false ;		//音量+
	isMsgSucced =false ;			//消息键是否测试通过
	isCallSucced =false;			//呼叫键是否测试通过

}

BD_Item::~BD_Item()
{

}


bool BD_Item::isAllPass()
{
	if (isCallSucced&&isCvcWriteSucced&&isDeviceNameWrite
		/*&&isFreqCheckSucced*/&&isMacWriteSucced&&isMergeConfigFileSucced&&
		isMergeSystemFileSucced&&isMsgSucced&&isSpawnFileSucced&&
		isVoiceDownSucced&&isVoiceUpSucced)
	{
		return true;
	}
	else
	{
		return false ;
	}
}



std::string BD_Item::getLastError()
{
	std::string msg;
	if (! isSpawnFileSucced)
	{
		msg = "烧录文件未通过";
		return msg;
	}
	else if (!isMergeConfigFileSucced)
	{
		msg = "配置文件合并失败";
		return msg ;
	}
	else if (!isMergeSystemFileSucced)
	{
		msg = "系统文件合并未通过";
		return msg ;
	}
	else if (!isCvcWriteSucced)
	{
		msg = "cvc码写入未通过";
		return msg ;
	}
	else if (!isDeviceNameWrite)
	{
		msg = "设备名写入未通过";
		return msg ;
	}
	else if (!isMacWriteSucced)
	{
		msg = "mac地址写入未通过";
		return msg ;
	} 
	else if (!isMsgSucced)
	{
		msg = "消息按键未通过";
		return msg ;
	}
	else if (!isCallSucced)
	{
		msg = "呼叫键测试失败";
		return msg ;
	}
	else if (!isVoiceDownSucced)
	{
		msg = "音量减按键未通过";
		return msg ;
	}
	else if (!isVoiceUpSucced)
	{
		msg = "音量加按键未通过";
		return msg ;
	}
}