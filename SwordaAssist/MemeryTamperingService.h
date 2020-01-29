#include "Spirit.h"
#include "SpiritAutoProtect.h"
#include "Common.h"
#include "Resource.h"
#include <iostream>
#include <string>

extern PROCESS_INFORMATION pi;
extern BYTE crackAccessGradeCode[];
extern BYTE crackAccessDefenseCode[];
extern BYTE crackAccessAggressivityCode[];
extern BYTE crackAccessPositioningCode[];
extern BYTE crackAccessLifeCode[];
extern BYTE crackAccessStrengthCode[];
extern BYTE crackAccessInternalforceCode[];
extern BYTE crackAccessMoneyCode[];

#pragma once
class MemeryTamperingService
{
private:
	//操作状态 1:修改英雄属性(待完成)  2:修改英雄属性(已完成)  3:刷新信息(待完成)  4:刷新信息(已完成)
	volatile UINT operateState = NULL;
public:
	MemeryTamperingService();
	//启动游戏
	BOOL startGameAndDebug(LPWSTR gamePath);
	//设置操作状态
	void setOperateState(UINT operateState);
	//获取操作状态
	UINT getOperateState();
	//获取主角当前信息
	BOOL refreshCurrentSpiritInfo(HWND hWnd);
	//修改主角信息
	BOOL tamperingSpirit(Spirit *spirit, SpiritAutoProtect *inputAutoProtect);
	~MemeryTamperingService();
};

