#pragma once

#include "IUniversal.h"
using namespace Sloong::Universal;

class CLogSystem : public ILogSystem
{
public:
	CLogSystem();
	~CLogSystem();

	static int Init();
	virtual HRESULT STDMETHODCALLTYPE QueryInterface(const IID& riid, void** ppvObject);
	virtual ULONG STDMETHODCALLTYPE AddRef();
	virtual ULONG STDMETHODCALLTYPE Release();

	virtual void STDMETHODCALLTYPE Initialize(IUniversal* pUniversal, LPCTSTR szPathName = TEXT("Log.log"), LOGLEVEL emLevel = LOGLEVEL::All, LOGTYPE emType = LOGTYPE::ONEFILE, bool bIsCoverPrev = false);

	virtual DWORD STDMETHODCALLTYPE Write(LPCTSTR szMessage);
	virtual void STDMETHODCALLTYPE WriteLine(LPCTSTR szLog);
	virtual void STDMETHODCALLTYPE Log(LOGLEVEL emLevel, DWORD dwCode, LPCTSTR strErrorText, bool bFormatWinMsg = true, bool bJustFailedWrite = true);
	virtual void STDMETHODCALLTYPE SetConfiguration(LPCTSTR szFileName, LPCTSTR szFilePath, LOGTYPE* pType, LOGLEVEL* pLevel);
	virtual bool STDMETHODCALLTYPE IsOpen();
	virtual void STDMETHODCALLTYPE Close();
	virtual LPCTSTR STDMETHODCALLTYPE GetFileName();
	virtual LPCTSTR STDMETHODCALLTYPE GetPath();

protected:
	LPCTSTR FormatFatalMessage(DWORD dwCode, LPCTSTR strErrorText, bool bFormatWinMsg, bool bJustFailedWrite);
	LPCTSTR FormatErrorMessage(DWORD dwCode, LPCTSTR strErrorText, bool bFormatWinMsg, bool bJustFailedWrite);
	LPCTSTR FormatWarningMessage(DWORD dwCode, LPCTSTR strErrorText, bool bFormatWinMsg, bool bJustFailedWrite);
	LPCTSTR FormatInformationMessage(DWORD dwCode, LPCTSTR strErrorText, bool bFormatWinMsg, bool bJustFailedWrite);
	HRESULT OpenFile();
	void	Lock();
	void	Unlock();

protected:
	LOGLEVEL	m_emLevel;
	HANDLE		m_hFileHandle;
	LPTSTR		m_szFilePath;
	LPTSTR		m_szFileName;
	CRITICAL_SECTION m_csLock;
	LPTSTR		m_szLastDate;
	int			m_emType;
	ULONG		m_Ref;
	bool		m_bIsCoverPrev;
	IUniversal*	m_pUniversal;
	static ULONG m_objNum;
	static CRITICAL_SECTION m_cs;
};