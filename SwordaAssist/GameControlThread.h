#pragma once
#include "stdafx.h"
#include "Common.h"
#include "Spirit.h"
#include "MemeryTamperingService.h"
#include "SpiritAutoProtect.h"

extern MemeryTamperingService memeryTamperingService;  //内存修改业务逻辑
extern Spirit currentSpirit;                           //当前主角信息
extern Spirit willModifySpirit;                        //将要修改的主角主信息

DWORD WINAPI RunGameThread(LPVOID lpParam);
DWORD WINAPI MonitorThread(LPVOID lpParam);
