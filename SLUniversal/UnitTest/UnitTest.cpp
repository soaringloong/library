// UnitTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SLUniversal.h"
#pragma comment(lib,"SLUniversal.lib")

using namespace SoaringLoong;

CLogSystem* pLog = NULL;

CLogSystem* GetLogSystem()
{
	return pLog;
}

int _tmain(int argc, _TCHAR* argv[])
{
	CLogSystem gLog(TEXT("Test"), CLogSystem::All, CLogSystem::DAY);

	pLog = &gLog;

	g_hRes = 0;
	pLog->ResLog(CLogSystem::INF, 104, TEXT("Test."));
	pLog->ResLog(CLogSystem::ERR, 205, TEXT("Test Error."));
	pLog->ResLog(CLogSystem::FATAL, 001, TEXT("Test fatal."));
	pLog->ResLog(CLogSystem::ERR, 206, SoaringLoong::Format(TEXT("Test Result = %d"), 256));
	pLog->ResLog(CLogSystem::INF, 123, SoaringLoong::Format(TEXT("Test string, %s"), SoaringLoong::Format(TEXT("Test"))));
	OFSTRUCT ofBuffer;
	HFILE hFile = OpenFile( ("C:\\NOFIle.abs"), &ofBuffer, OF_READ );
	g_hRes = -1;
	if ( -1 == hFile )
	{
		pLog->ResLog(CLogSystem::ERR, 1, TEXT("Open File Test."));
	}

	gLog.Log(TEXT("Test"));
	gLog.Log(TEXT("2"));

	CLogSystem gLog2(TEXT("Log2.log"), CLogSystem::All, CLogSystem::ONEFILE, true);
	gLog2.Log(TEXT("Test"));
	gLog2.Log(TEXT("2"));

	g_oLog.Log(TEXT("g_oLog test."));

	
	_tsystem(Format(TEXT("notepad.exe %s"),gLog.GetFileName()));
	_tsystem(Format(TEXT("notepad.exe %s"),gLog2.GetFileName()));
	_tsystem(Format(TEXT("notepad.exe %s"),g_oLog.GetFileName()));
	return 0;
}

