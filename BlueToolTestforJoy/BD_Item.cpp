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

	isVoiceDownSucced =false ;		//����-
	isVoiceUpSucced =false ;		//����+
	isMsgSucced =false ;			//��Ϣ���Ƿ����ͨ��
	isCallSucced =false;			//���м��Ƿ����ͨ��

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
		msg = "��¼�ļ�δͨ��";
		return msg;
	}
	else if (!isMergeConfigFileSucced)
	{
		msg = "�����ļ��ϲ�ʧ��";
		return msg ;
	}
	else if (!isMergeSystemFileSucced)
	{
		msg = "ϵͳ�ļ��ϲ�δͨ��";
		return msg ;
	}
	else if (!isCvcWriteSucced)
	{
		msg = "cvc��д��δͨ��";
		return msg ;
	}
	else if (!isDeviceNameWrite)
	{
		msg = "�豸��д��δͨ��";
		return msg ;
	}
	else if (!isMacWriteSucced)
	{
		msg = "mac��ַд��δͨ��";
		return msg ;
	} 
	else if (!isMsgSucced)
	{
		msg = "��Ϣ����δͨ��";
		return msg ;
	}
	else if (!isCallSucced)
	{
		msg = "���м�����ʧ��";
		return msg ;
	}
	else if (!isVoiceDownSucced)
	{
		msg = "����������δͨ��";
		return msg ;
	}
	else if (!isVoiceUpSucced)
	{
		msg = "�����Ӱ���δͨ��";
		return msg ;
	}
}