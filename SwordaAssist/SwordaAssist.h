#pragma once

#include "resource.h"
#include <commctrl.h>//高级控件函数宏
#include  <commdlg.h>
#include "Spirit.h"
#include "MemeryTamperingService.h"
#include "GameControlThread.h"

#pragma comment(lib, "comctl32.lib")

MemeryTamperingService memeryTamperingService;  //内存修改业务逻辑
Spirit currentSpirit;                           //当前主角信息
Spirit willModifySpirit;                        //将要修改的主角主信息































