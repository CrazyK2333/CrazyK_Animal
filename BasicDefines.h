#pragma once

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             // 从 Windows 头文件中排除极少使用的内容
#define _WINSOCK_DEPRECATED_NO_WARNINGS 
#define IDS_APP_TITLE			103
#define WND_WIDTH 1500
#define WND_HEIGHT 1200
#define BOARD_RIGHTLINE 1100
#define WND_BOARD 1101
#define WND_MESSAGE 1102
#define LABEL_COM 1103
#define LABEL_USER 1104
#define TEXT_COM 1105
#define TEXT_USER 1106
#define NUMBLOCK 44
#define BLOCKLENGTH (BOARD_RIGHTLINE/NUMBLOCK)
#define BUTTONS_Y_LINE_BOTTOM 900
#define IDR_MAINFRAME			128
#define IDD_GOBANG_DIALOG	102
#define IDD_ABOUTBOX			103
#define IDM_ABOUT				104
#define IDM_EXIT				105
#define IDI_GOBANG			107
#define IDI_SMALL				108
#define IDC_GOBANG			109
#define IDC_BUTTON_STARTGAME 110
#define IDC_BUTTON_GIVEUP 111
#define IDC_MYICON				2
#define GMD_INITED 1700
#define GMD_CONNECTED 1702
#define GMD_STARTED 1701
#define GMD_OVER 1702
#define RADIO_IP "230.1.1.99"
#define GMD_CONN_PORT 11111
#define GMDP_SIZE 1024
// Windows 头文件
#include <windows.h>
// C 运行时头文件
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <stack>
#include<map>
#include<memory>
#include<vector>
#include<string>
#include<list>
#include<iostream>
#include <winsock2.h>
#include <ws2tcpip.h>
// Need to link with Ws2_32.lib, Mswsock.lib, and Advapi32.lib
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")
#pragma comment(lib, "winmm.lib") 
#include <time.h> 
#include <strsafe.h>
#include <shellapi.h>
#include <mmsystem.h>
#include <conio.h>
#include<mutex>


//Say wide char
#define Say(T) MessageBox(0,T , L"Information", 0);
//Say multibyte char
#define SayC(T) int sBufSize=strlen(T); DWORD dbuffsize=MultiByteToWideChar(CP_ACP, 0, T, sBufSize, NULL, 0);\
wchar_t* dBuf=new wchar_t[dbuffsize];\
wmemset(dBuf,0,dbuffsize); int nRet=MultiByteToWideChar(CP_ACP, 0, T, sBufSize, dBuf, dbuffsize);\
if(nRet>0){MessageBox(0,dBuf , L"Information", 0);}\

#define DeBugOutputW(...) {wchar_t buffer[256];swprintf_s(buffer,__VA_ARGS__);OutputDebugString(buffer);}
//#define DeBugOutputNormal(...)char buffer[256];sprintf_s(buffer,##__VA_ARGS__);OutputDebugStringA(buffer);
//#define DeBugOutputNormal(...){std::string buffer_str=std::format(__VA_ARGS__)};OutputDebugStringA(buffer.c_str());}
#define DeBugOutputNormal(...) {char buffer[256];sprintf_s(buffer,256,__VA_ARGS__);OutputDebugStringA(buffer);}
enum class brushcolor
{
    Black, Pink, White, Blue, LightPink
};
