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