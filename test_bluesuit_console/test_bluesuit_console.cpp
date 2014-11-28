// test_bluesuit_console.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <VECTOR>
#include <STRING>
using namespace std;




#include <iostream>
#include <windows.h> 
#include "testflash.h"

#include "testengine.h"

#include "TestPS.h"


#include <bitset>

// #include "tokenizer.hpp"
// #include "algorithm/string.hpp"

#define MAX_TIMEOUT 5000

#define PSKEY_DEVICE_NAME					0x0108				//蓝牙设备名
#define PSKEY_FIXED_PIN						0x035b				//蓝牙设备配对密码
#define PSKEY_DSP48							0x2288				//cvc码
#define PSKEY_BDADDR						0x0001				//蓝牙地址



#define PSKEY_ANA_FREQ	0x002a				//频率校准，数据不详，待问。


#define DEFAULT_BD_NAME		"koovox"
#define DEFAULT_BD_PWD		"koovox"




void getHandle();
int readKey(const uint16 keys) ;
int setKey(const uint16 keys, const char * keyVal , const int ksize);

int main(int argc, char** argv)
{


	setKey(PSKEY_DEVICE_NAME,"xiesong" ,strlen("xiesong" ) ) ;

	readKey(PSKEY_DEVICE_NAME);
	
	setKey(PSKEY_FIXED_PIN , "default_pwd" , strlen("default_pwd") );

	readKey(PSKEY_FIXED_PIN);

	setKey(PSKEY_DSP48 , "cvc_code" , strlen("cvc_code") );
	readKey(PSKEY_DSP48);


	std::cout << "PSKEY_HOSTIO_PROTOCOL_INFO9" << std::endl;
	readKey(PSKEY_ANA_FREQ);


	while(1)
		;

	getHandle();


 
    // Program 4 devices
    uint32 devMask = 1;//0xF;
    if(flmOpen(devMask, 26, TFL_SPI_USB) != TFL_OK)
    {
        std::cout << "Failed to open devices " << (int)flmGetBitErrorField()   << std::endl;
        return -1;
    }else{
		cout<<" flmopen api works "<<endl;
	}

    if(flmReadProgramFiles("testBuild\\default") != TFL_OK)
    {
        std::cout << "Failed to read flash program files" << std::endl;
        flmClose(devMask);
        return -1;
    }
    if(flmProgramSpawn(devMask, 0, 0, 0) != TFL_OK)
    {
        std::cout << "Failed to spawn flash program thread" << std::endl;
        flmClose(devMask);
        return -1;
    }
	
    uint16 devicesRunning;
    int32 progress;
    do
    {
        devicesRunning = 0;
        for(uint32 devIndex = 0; devIndex < TFL_MAX_DEVICES; ++devIndex)
        {
            // Only check the progress if the device is in the mask
            if((devMask >> devIndex) & 1)
            {
                progress = flmGetDeviceProgress(devIndex);
                if(progress < 100)
                {
                    ++devicesRunning;
                }
                std::cout << "dev" << devIndex << " progress = " << progress << "%" << std::endl;
            }
        }
        Sleep(1000);
    }
    while(devicesRunning > 0);
	
    std::cout << "Completed" << std::endl;
	
    int32 error = flmGetLastError();
    if(error != TFL_OK)
    {
        std::cout << "Programming failed with error: " << error 
			<< ". Failed devices mask = " << flmGetBitErrorField() << std::endl;
        flmClose(devMask);
        return -1;
    }
	
    std::cout << "Successfully programmed devices" << std::endl;
    flmClose(devMask);
	

    return 0;
}




//字符串分割函数，参考boost::split
std::vector<std::string> split(std::string str,std::string pattern)
{
    std::string::size_type pos;
    std::vector<std::string> result;
    str+=pattern;//扩展字符串以方便操作
    int size=str.size();
	
    for(int i=0; i<size; i++)
    {
        pos=str.find(pattern,i);
        if(pos<size)
        {
            std::string s=str.substr(i,pos-i);
            result.push_back(s);
            i=pos+pattern.size()-1;
        }
    }

 
    return result;
}

//解析括号
void parseBrackets(std::vector<std::string> &vt){

	for (std::vector<string>::iterator itr=vt.begin() ; itr!=vt.end() ; itr++ )
	{
		int pos=(*itr).find("(");
		*itr=(*itr).substr(pos+1,(*itr).size());

		pos=(*itr).find(")");
		*itr=(*itr).substr(0,pos);
	
	}
}






int readKey(const uint16 keys)
{

	const uint16 PSKEY_USR0 = keys ;//650;
	

	uint32 devHandle =  openTestEngineSpi(600935, 0, SPI_USB );// openTestEngine(BCSP, "600935", 115200, 5000, 0);
	
    if(devHandle != 0)
    {
        std::cout << "Device Handle = " << devHandle << std::endl;
		
        uint16 data[20] ={'\0'};

//         if(psWrite(devHandle, PSKEY_USR0, PS_STORES_I, 2, data) == TE_OK)
//         {
//             std::cout << "Successfully wrote key" << std::endl;
//         }
//         else
//         {
//             std::cout << "Failed to write key" << std::endl;
//             closeTestEngine(devHandle);
//             return -1;
//         }
		
        uint16 keySize;
        psSize(devHandle, PSKEY_USR0, PS_STORES_IFR, &keySize);
		
        data[0] = data[1] = 0;
		
        if(psRead(devHandle, PSKEY_USR0, PS_STORES_IFR, 16, data, &keySize) == TE_OK)
        {
            std::cout << "data[0] = " << data[0] << std::endl 
				<< "data[1] = " << data[1] << std::endl;

			char bufstr[128]={'\0'};
			memcpy( bufstr , data , sizeof(data)*sizeof(uint16) );
			std::cout << "read into char :" << bufstr <<endl ;
        }
        else
        {
            std::cout << "Failed to read key" << std::endl;
            closeTestEngine(devHandle);
            return -1;
        }
		
        closeTestEngine(devHandle);
    }
    else
    {
        std::cout << "Failed to initialise device" << std::endl;
        return -1;
    }


}










int setKey(const uint16 keys, const char * keyVal , const int ksize)
{
	
	const uint16 PSKEY_USR0 = keys ;//650; 
	
	uint32 devHandle =  openTestEngineSpi(600935, 0, SPI_USB );// openTestEngine(BCSP, "600935", 115200, 5000, 0);
	
    if(devHandle != 0)
    {
        std::cout << "Device Handle = " << devHandle << std::endl;
		
        uint16 data[20]={'\0'};

		memcpy( ((char*)data ), keyVal , ksize );
		
		if(psWrite(devHandle, PSKEY_USR0, PS_STORES_I, ksize/2, data) == TE_OK)
		{
			std::cout << "Successfully wrote key" << std::endl;
		}
		else
		{
			std::cout << "Failed to write key" << std::endl;
			closeTestEngine(devHandle);
			return -1;
		}
		
  
		
        closeTestEngine(devHandle);
    }
    else
    {
        std::cout << "Failed to initialise device" << std::endl;
        return -1;
    }
	
	
}








void getHandle(){ 

	//获取可用设备的句柄。
	uint32 iHandle(0);
	uint16 maxLen(256);
	uint16 count(0);
	char* portsStr = new char[maxLen];
	char* transStr = new char[maxLen];
	vector<string> ports; // The human readable port strings (e.g. "LPT1")
	vector<string> trans; // The transport option strings (e.g. "SPITRANS=LPT SPIPORT=1")
	

	memset(portsStr,0,maxLen);
	int32 status = teGetAvailableSpiPorts(&maxLen, portsStr, transStr, &count);

	cout<<"teGetAvailableSpiPorts return val:"<<status<<" portstr:"<<portsStr<<" transStr :"<<transStr<<endl;

	if( status != TE_OK && maxLen != 0 )
	{
		// Not enough space - resize the storage
		portsStr = new char[maxLen];
		transStr = new char[maxLen];
		status = teGetAvailableSpiPorts(&maxLen, portsStr, transStr, &count);
		cout<<"status for teGetAvailableSpiPorts is :"<<status<<endl;
	}
	if( status != TE_OK || count == 0 )
	{
		cout << "Error getting SPI ports, or none found" << endl;
		delete[] portsStr;
		delete[] transStr;
		return;
	}
	
	cout<<"----------------\n"<<"portStr:"<<portsStr<<" transStr:"<<transStr<<endl;
	// Split up the comma separated strings of ports / transport options
	ports=split( string(portsStr), string(",")); // Use these for user selection (e.g. drop down list)
	trans=split(string(transStr), string(",")); // Use these to open a transport
	

	parseBrackets(ports);






	//多路烧录文件。
	bitset<32> bitvec;  //32 bits,all zero
	for(int loop_bs=0 ; loop_bs<ports.size() ; loop_bs++ )
	{
		bitvec.set(loop_bs);
	}
	
	int devMask=bitvec.to_ulong();
	if(flmOpen(devMask, 26, TFL_SPI_USB) != TFL_OK)
    {
        std::cout << "Failed to open devices (" << flmGetBitErrorField() << ")" << std::endl;
    }
    if(flmReadProgramFiles("xpv\\merge.xpv") != TFL_OK)
    {
        std::cout << "Failed to read flash program files" << std::endl;
        flmClose(devMask);
      
    }

    if(flmProgramSpawn(devMask, 0, 0, 0) != TFL_OK)
    {
        std::cout << "Failed to spawn flash program thread" << std::endl;
        flmClose(devMask);
       
    }
	
    uint16 devicesRunning;
    int32 progress;
    do
    {
        devicesRunning = 0;
        for(uint32 devIndex = 0; devIndex < TFL_MAX_DEVICES; ++devIndex)
        {
            // Only check the progress if the device is in the mask
            if((devMask >> devIndex) & 1)
            {
                progress = flmGetDeviceProgress(devIndex);
                if(progress < 100)
                {
                    ++devicesRunning;
                }
                std::cout << "dev" << devIndex << " progress = " << progress << "%" << std::endl;
            }
        }
        Sleep(1000);
    }
    while(devicesRunning > 0);
	
    std::cout << "Completed" << std::endl;
	
    int32 error = flmGetLastError();
    if(error != TFL_OK)
    {
        std::cout << "Programming failed with error: " << error 
			<< ". Failed devices mask = " << flmGetBitErrorField() << std::endl;
        flmClose(devMask);
        
    }
	
    std::cout << "Successfully programmed devices" << std::endl;
    flmClose(devMask);






	//合并文件。
	for(vector<std::string>::iterator itr1=ports.begin();itr1!=ports.end();itr1++)
	{
		int ret=0;
		iHandle = openTestEngineSpi(atoi((*itr1).c_str()), 0, SPI_USB );
		if(	psMergeFromFile( iHandle , "xpv\\sink_config_10001v4_stereo.psr" ) ==1){
			std::cout<<"ps merge sink_config_10001v4_stereo.psr all right "<<std::endl;
		}else{
			std::cout<<"ps merge sink_config_10001v4_stereo.psr failed "<<std::endl;
		}

		if(	psMergeFromFile( iHandle , "xpv\\sink_system_csr8670.psr" ) ==1){
			std::cout<<"ps merge sink_system_csr8670.psr all right "<<std::endl;
		}else{
			std::cout<<"ps merge sink_system_csr8670.psr failed "<<std::endl;
		}
//sink_system_csr8670.psr


		//写入蓝牙名称
		uint16 bd_name[20]={'\0'};
		strcpy( (char*)bd_name , DEFAULT_BD_NAME );
		if(psWrite(iHandle, PSKEY_DEVICE_NAME, PS_STORES_I, 20, bd_name) == TE_OK)
		{
			std::cout << "Successfully wrote key PSKEY_DEVICE_NAME " << std::endl;
		}
		else
		{
			std::cout << "Failed to write key PSKEY_DEVICE_NAME" << std::endl;
		//	closeTestEngine(iHandle);
		}

		//读取蓝牙名
		uint16 r_bd_name[20]={'\0'};
		uint16 name_keySize;
		psSize(iHandle, PSKEY_DEVICE_NAME, PS_STORES_IFR, &name_keySize);
		std::cout << " name_keySize is " << name_keySize << endl << endl ;
		if( ( ret= psRead( iHandle , PSKEY_DEVICE_NAME , PS_STORES_IFR , 0 , r_bd_name , &name_keySize ) )==TE_OK )
		{
			std::cout << "r_bd_name[0] = " << r_bd_name[0] << std::endl 
				<< "r_bd_name[1] = " << r_bd_name[1] << std::endl;
		}else{
			std::cout<<"psRead failed PSKEY_DEVICE_NAME " << ret << endl ;
		}



		const uint16 PSKEY_USR0 = 650;
		uint16 data[20];
		data[0] = data[1] = 0;
		uint16 keySize;
        psSize(iHandle , PSKEY_USR0, PS_STORES_IFR, &keySize);
        data[0] = data[1] = 0;
		
        if(psRead(iHandle, PSKEY_USR0, PS_STORES_IFR, 16, data, &keySize) == TE_OK)
        {
            std::cout << "data[0] = " << data[0] << std::endl 
				<< "data[1] = " << data[1] << std::endl;
        }
        else
        {
            std::cout << "Failed to read key" << std::endl;
        }




		//设置配对密码
		uint16 bd_pwd[20]={'\0'};
		strcpy( (char*)bd_pwd , DEFAULT_BD_PWD );
		if(psWrite( iHandle , PSKEY_FIXED_PIN , PS_STORES_I, 20 , bd_pwd) == TE_OK)
		{
			std::cout << "Successfully wrote key PSKEY_FIXED_PIN" << std::endl;
		}
		else
		{
			std::cout << "Failed to write key PSKEY_FIXED_PIN" << std::endl;
		//	closeTestEngine(iHandle);
		}


		//	if( ( ret= psRead( iHandle , PSKEY_DEVICE_NAME , PS_STORES_I , 16 , data , &keySize ) )==TE_OK )
		//cvc码（先做读取操作）
		uint16 bd_cvc[20]={'\0'};
		uint16 cvc_keySize;
		if(psRead( iHandle , PSKEY_DSP48 , PS_STORES_I, 16 , bd_cvc , &cvc_keySize) == TE_OK)
		{
			std::cout << "Successfully psRead key PSKEY_DSP48 " << bd_cvc << std::endl;
		}
		else
		{
			std::cout << "Failed to psRead key PSKEY_DSP48" << std::endl;
		//	closeTestEngine(iHandle);
		}

		//蓝牙地址
		uint16 bd_addr[20]={'\0'};
		uint16 bdaddr_keySize;
		if(psRead( iHandle , PSKEY_BDADDR , PS_STORES_I, 16 , bd_addr , &bdaddr_keySize) == TE_OK)
		{
			std::cout << "Successfully psRead key PSKEY_BDADDR" << bd_addr << std::endl;
		}
		else
		{
			std::cout << "Failed to psRead key PSKEY_BDADDR" << std::endl;
		//	closeTestEngine(iHandle);
		}


		closeTestEngine(iHandle);

	}





	while(1)
		;





	for(vector<std::string>::iterator itr=ports.begin();itr!=ports.end();itr++)
	{
		int ret=0;
		iHandle = openTestEngineSpi(atoi((*itr).c_str()), 0, SPI_USB );
		




		if( iHandle != 0)
		{
			
			uint16 data[20]={'\0'};
			uint16 keySize;
			if( ( ret= psRead( iHandle , PSKEY_DEVICE_NAME , PS_STORES_I , 16 , data , &keySize ) )==TE_OK )
			{
				std::cout << "data[0] = " << data[0] << std::endl 
					<< "data[1] = " << data[1] << std::endl;
			}else{
				std::cout<<"psRead failed " << ret << endl ;
			}
			
			
			
			if(int ret=flInit(atoi((*itr).c_str()), 26, 2 , TFL_SPI_USB ) != TFL_OK)
			{
				std::cout << "Failed to flInit flash:"<<ret << std::endl;
			}
			else
			{
				cout<<"flInit ok ..."<<ret <<endl;
			}
			
			if(flReadProgramFiles("xpv\\merge.xpv") != TFL_OK)
			{
				std::cout << "Failed to read flash program files" << std::endl;
				flClose();
				
			}else{
				std::cout << "flReadProgramFiles succed "<<std::endl;
			}
			
			if(flProgramSpawn() != TFL_OK)
			{
				std::cout << "Failed to spawn flash program thread" << std::endl;
				flClose();
				
			}else{
				std::cout << "flProgramSpawn succed "<<std::endl;
			}
			
			
			int32 progress = flGetProgress();
			while(progress < 100)
			{
				std::cout << "Programming..." << progress << "%" << std::endl;
				Sleep(1000);
				progress = flGetProgress();
			}
			std::cout << "Completed" << std::endl;
			
			int32 error = flGetLastError();
			if(error != TFL_OK)
			{
				std::cout << "Programming failed with error: " << error << std::endl;
				flClose();
				/*	return -1;*/
			}
			
			std::cout << "Successfully programmed device" << std::endl;
			flClose();
			
	 
			strcpy( (char*)data , "xiesong" );
			if(psWrite(iHandle, PSKEY_DEVICE_NAME, PS_STORES_I, 20, data) == TE_OK)
			{
				std::cout << "Successfully wrote key" << std::endl;
			}
			else
			{
				std::cout << "Failed to write key" << std::endl;
				closeTestEngine(iHandle);
			}
			
			
			uint16 temp=0;
			ret = bccmdGetChipVersion( iHandle , &temp );
            if(ret == TE_OK)
            {
                cout << "Chip version = " << temp <<" ;"<< endl;
            }else{
				
			}
			
			
			
			
			
			
			
			cout << "openTestEngineSpi Connected!" << endl;
			// Perform all your testing here
			closeTestEngine(iHandle);
		}
		else
		{
			cout<<"openTestEngineSpi failed"<<endl;
		}
		
		
		cout<<" iterator :"<<*itr<<endl;
		
	}
	
	

	 

	
	delete[] portsStr;
	delete[] transStr;
	
	return;



}