#ifndef LOG_H
#define LOG_H


#include "univ.h"
#ifdef _WINDOWS
#else
#include <semaphore.h>
#endif
using namespace Sloong::Universal;


#include <condition_variable>
namespace Sloong
{
	namespace Universal
	{

		typedef enum _emLogType
		{
			YEAR = 0,
			MONTH = 1,
			DAY = 2,
			ONEFILE = 3
		}LOGTYPE;

		typedef enum _emLogLevel
		{
			All = 0,
			Verbos = 1,
			Debug = 2,
			Info = 3,
			Warn = 4,
			Error = 5,
			Assert = 6,
			Fatal = 7,
		}LOGLEVEL;
		
		class UNIVERSAL_API CLog
		{
		public:
			CLog();
			~CLog();

			virtual void Initialize();
            virtual void Initialize(wstring szPathName, bool bDebug = true, LOGLEVEL emLevel = LOGLEVEL::All, LOGTYPE emType = LOGTYPE::ONEFILE, bool bIsCoverPrev = false);
			virtual void Initialize(string szPathName, bool bDebug = true, LOGLEVEL emLevel = LOGLEVEL::All, LOGTYPE emType = LOGTYPE::ONEFILE, bool bIsCoverPrev = false);
			virtual void Start();
			virtual void End();
			/************************************************************************/
			/* SetWorkInterval function                                             */
			/* Set the log system work loop sleep time when the log list is empty   */
			/* in default, it is 100. you can change it by your need.               */
			/************************************************************************/
			virtual void SetWorkInterval(int nInterval = 100);
			virtual void Write(std::string szMessage);
			virtual void WriteLine(std::string szLog);
			virtual void Log(std::string strErrorText, std::string strTitle , DWORD dwCode = 0 , bool bFormatSysMsg = false);
			virtual void Verbos(std::string strMsg);
			virtual void Debug(std::string strMsg);
			virtual void Info(std::string strInfo);
			virtual void Warn(std::string strMsg);
			virtual void Error(std::string strMsg);
			virtual void Assert(std::string strMsg);
			virtual void Fatal(std::string strMsg);
            virtual void SetConfiguration(std::wstring szFileName, LOGTYPE* pType, LOGLEVEL* pLevel, bool bDeubg = true);
			virtual void SetConfiguration(std::string szFileName, LOGTYPE* pType, LOGLEVEL* pLevel, bool bDeubg = true);
			virtual bool IsOpen();
			virtual void Close();
			virtual std::wstring GetFileName();
			virtual std::string GetFileNameA();
			virtual std::wstring GetPath();
			virtual std::string GetPathA();
			virtual bool IsInitialize();
			virtual void Flush();
		protected:
			bool OpenFile();
			static LPVOID LogSystemWorkLoop(LPVOID param);

		protected:
			LOGLEVEL	m_emLevel;
			ofstream	m_oFile;
			std::wstring		m_szFilePath;
			std::wstring		m_szFileName;
			int		m_nLastDate;
			int		m_emType;
			bool		m_bOpenFileFirst;
			bool		m_bIsCoverPrev;
			bool		m_bInit;
			// Debug mode
			// if true, the text will write to hard disk in every call.
			// if false, it just write to the cache. and the system to control to write to disk.
            bool        m_bDebug;
			int			m_nSleepInterval;
			condition_variable m_CV;
			mutex		m_Mutex;
			bool		m_bRunning;
		};
	}
}

#endif // !LOG_H

