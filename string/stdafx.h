// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//
#ifndef STDAFX_H
#define STDAFX_H

#include "targetver.h"

#ifdef _WINDOWS
	#define WIN32_LEAN_AND_MEAN             // 从 Windows 头中排除极少使用的资料
	// Windows 头文件: 
	#include <windows.h>
#else
	#include <stdarg.h>
	#include <string.h>
	#include <stdlib.h>
	#include <stdio.h>
	#include <wchar.h>
#endif


// TODO:  在此处引用程序需要的其他头文件
#endif //STDAFX_H
