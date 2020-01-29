#include "stdafx.h"
#include"GameControlThread.h"

//原始访问英雄属性代码
//BYTE originalAccessGradeCode[] = { 0x8B, 0x96, 0xF8, 0xEC, 0x4D, 0x00, 0x52, 0xE8, 0x18, 0x8B};
//BYTE originalAccessDefenseCode[] = { 0x8B, 0x86, 0xF0, 0xEC, 0x4D, 0x00, 0x8D, 0x8F, 0x28, 0x0B};
//BYTE originalAccessAggressivityCode[] = { 0x8B, 0x96, 0xEC, 0xEC, 0x4D, 0x00, 0x8D, 0x8F, 0xC0, 0x09};
//BYTE originalAccessPositioningCode[] = { 0x8B, 0x8E, 0xF4, 0xEC, 0x4D, 0x00, 0x51, 0x8D, 0x8F, 0x90};
//BYTE originalAccessLifeCode[] = { 0x8B, 0x96, 0xD8, 0xEC, 0x4D, 0x00, 0x8B, 0x86, 0xD4, 0xEC};
//BYTE originalAccessStrengthCode[] = { 0x8B, 0x8E, 0xE0, 0xEC, 0x4D, 0x00, 0x8B, 0x96, 0xDC, 0xEC};
//BYTE originalAccessInternalforceCode[] = { 0x8B, 0x86, 0xE8, 0xEC, 0x4D, 0x00, 0x8B, 0x8E, 0xE4, 0xEC};
//BYTE originalAccessMoneyCode[] = { 0xA1, 0xC4, 0xD1, 0x55, 0x00, 0x8B, 0x4C, 0x24, 0x10, 0x50};

//注入的代码
BYTE crackAccessGradeCode[] = { 0xC7, 0x86, 0xF8, 0xEC, 0x4D, 0x00, 0x4C, 0x00, 0x00, 0x00};  //(4C是参数)
BYTE crackAccessDefenseCode[] = { 0xC7, 0x86, 0xF0, 0xEC, 0x4D, 0x00, 0x8D, 0x0A, 0x00, 0x00 };//(8D 0A是参数)
BYTE crackAccessAggressivityCode[] = { 0xC7, 0x86, 0xEC, 0xEC, 0x4D, 0x00, 0x8D, 0x0D, 0x00, 0x00 };//(8D 0D是参数)
BYTE crackAccessPositioningCode[] = { 0xC7, 0x86, 0xF4, 0xEC, 0x4D, 0x00, 0x58, 0x01, 0x00, 0x00 };//(58 01是参数)
BYTE crackAccessLifeCode[] = { 0xC7, 0x86, 0xD8, 0xEC, 0x4D, 0x00, 0x94, 0x0E, 0x00, 0x00 };//(94 0E是参数)
BYTE crackAccessStrengthCode[] = { 0xC7, 0x86, 0xE0, 0xEC, 0x4D, 0x00, 0x1D, 0x05, 0x00, 0x00 };//(1D 05是参数)
BYTE crackAccessInternalforceCode[] = { 0xC7, 0x86, 0xE8, 0xEC, 0x4D, 0x00, 0x2B, 0x04, 0x00, 0x00 };//(2B 04是参数)
BYTE crackAccessMoneyCode[] = { 0xC7, 0x05, 0xC4, 0xD1, 0x55, 0x00, 0x9A, 0x02, 0x00, 0x00 };//(9A 02是参数)
BYTE originalCode[80] = {0};
UINT curEsi = 0;
PROCESS_INFORMATION pi;
HANDLE hCurSpiritThread;
SpiritAutoProtect autoProtect;

DWORD WINAPI MonitorThread(LPVOID lpParam) {
	//线程Flag
	BOOL whileDoFlag = TRUE;
	//生命 
	UINT curLife = 0;
	//最大生命
	UINT spiritLife = 0;
	//体力
	UINT curStrength = 0;
	//最大体力
	UINT spiritStrength = 0;
	//内力
	UINT curInternalforce = 0;
	//最大内力
	UINT spiritInternalforce = 0;
	while (whileDoFlag) {
		if (curEsi == 0) {
			Sleep(2000);
			continue;
		}

		if (NULL != autoProtect.getLowValInMaxLifePercent() && NULL != autoProtect.getAddValInMaxLifePercent()) {
			ReadProcessMemory(pi.hProcess, (LPCVOID)(curEsi + 0x004DECD8), &spiritLife, 2, NULL);
			ReadProcessMemory(pi.hProcess, (LPCVOID)(curEsi + 0x004DECD4), &curLife, 2, NULL);
			if (curLife < spiritLife * ((FLOAT )autoProtect.getLowValInMaxLifePercent() / 100)) {
				curLife += (UINT)(spiritLife * ((FLOAT)autoProtect.getAddValInMaxLifePercent() / 100));
				WriteProcessMemory(pi.hProcess, (LPVOID)(curEsi + 0x004DECD4), &curLife, 2, 0);
			}
		}
		if (NULL != autoProtect.getLowValInMaxStrengthPercent() && NULL != autoProtect.getAddValInMaxStrengthPercent()) {
			ReadProcessMemory(pi.hProcess, (LPCVOID)(curEsi + 0x004DECE0), &spiritStrength, 2, NULL);
			ReadProcessMemory(pi.hProcess, (LPCVOID)(curEsi + 0x004DECDC), &curStrength, 2, NULL);
			if (curStrength < spiritStrength * ((FLOAT)autoProtect.getLowValInMaxStrengthPercent() / 100)) {
				curStrength += (UINT)(spiritStrength * ((FLOAT)autoProtect.getAddValInMaxStrengthPercent() / 100));
				WriteProcessMemory(pi.hProcess, (LPVOID)(curEsi + 0x004DECDC), &curStrength, 2, 0);
			}
		}
		if (NULL != autoProtect.getLowValInMaxInternalforcePercent() && NULL != autoProtect.getAddValInMaxInternalforcePercent()) {
			ReadProcessMemory(pi.hProcess, (LPCVOID)(curEsi + 0x004DECE8), &spiritInternalforce, 2, NULL);
			ReadProcessMemory(pi.hProcess, (LPCVOID)(curEsi + 0x004DECE4), &curInternalforce, 2, NULL);
			if (curInternalforce < spiritInternalforce * ((FLOAT)autoProtect.getLowValInMaxInternalforcePercent() / 100)) {
				curInternalforce += (UINT)(spiritInternalforce * ((FLOAT)autoProtect.getAddValInMaxInternalforcePercent() / 100));
				WriteProcessMemory(pi.hProcess, (LPVOID)(curEsi + 0x004DECE4), &curInternalforce, 2, 0);
			}
		}
		Sleep(500);
	}
	return 0;
}

DWORD WINAPI RunGameThread(LPVOID lpParam) {
	STARTUPINFO si;
	ZeroMemory(&si, sizeof(STARTUPINFO));
	ZeroMemory(&pi, sizeof(PROCESS_INFORMATION));
	si.cb = sizeof(STARTUPINFO);
	int cpRes = -1;

	BOOL whileDoFlag = TRUE;
	if (!(cpRes = CreateProcess((LPCWSTR)lpParam, NULL, NULL, NULL, FALSE,
		DEBUG_PROCESS, NULL, NULL, &si, &pi))) {
		MessageBox(NULL, TEXT("创建游戏进程失败"), TEXT("提示"), MB_OK);
	}

	DEBUG_EVENT dEvent;
	CONTEXT regs;
	DWORD dwState;
	DWORD dwSSCnt = 0;
	regs.ContextFlags = CONTEXT_FULL | CONTEXT_DEBUG_REGISTERS;

	while (whileDoFlag) {
		WaitForDebugEvent(&dEvent, INFINITE);

		switch (dEvent.dwDebugEventCode) {
			case CREATE_PROCESS_DEBUG_EVENT:
				break;
			case EXIT_PROCESS_DEBUG_EVENT:
				whileDoFlag = FALSE;
				break;
			case EXCEPTION_DEBUG_EVENT:
				switch (dEvent.u.Exception.ExceptionRecord.ExceptionCode) {
					case EXCEPTION_SINGLE_STEP: {						
                        if (OPERATE_STATE_REQUEST_MODIFY_SPIRIT == memeryTamperingService.getOperateState()) {
							//修改属性
							GetThreadContext(pi.hThread, &regs);
							if (regs.Eip == ACCESS_GRADE_ADDRESS) {
								//EIP指向访问英雄等级代码的地址
								//将状态设置为修改中
								memeryTamperingService.setOperateState(OPERATE_STATE_MODIFYING_SPIRIT);
								//读取原始代码(用于执行完注入代码后恢复执行)
								ZeroMemory(originalCode, sizeof(originalCode));
								ReadProcessMemory(pi.hProcess, (LPCVOID)ACCESS_GRADE_ADDRESS, &originalCode, sizeof(originalCode), NULL);
								//读取当前esi的值
								curEsi = regs.Esi;
								//ReadProcessMemory(pi.hProcess, (LPCVOID)(regs.Esi), &curEsi, 4, NULL);
								//写入注入代码
								WriteProcessMemory(pi.hProcess, (LPVOID)ACCESS_GRADE_ADDRESS, &crackAccessGradeCode, sizeof(crackAccessGradeCode), 0);
								WriteProcessMemory(pi.hProcess, (LPVOID)(ACCESS_GRADE_ADDRESS + sizeof(crackAccessGradeCode)), &crackAccessDefenseCode, sizeof(crackAccessDefenseCode), 0);
								WriteProcessMemory(pi.hProcess, (LPVOID)(ACCESS_GRADE_ADDRESS + sizeof(crackAccessGradeCode) * 2), &crackAccessAggressivityCode, sizeof(crackAccessAggressivityCode), 0);
								WriteProcessMemory(pi.hProcess, (LPVOID)(ACCESS_GRADE_ADDRESS + sizeof(crackAccessGradeCode) * 3), &crackAccessPositioningCode, sizeof(crackAccessPositioningCode), 0);
								WriteProcessMemory(pi.hProcess, (LPVOID)(ACCESS_GRADE_ADDRESS + sizeof(crackAccessGradeCode) * 4), &crackAccessLifeCode, sizeof(crackAccessLifeCode), 0);
								WriteProcessMemory(pi.hProcess, (LPVOID)(ACCESS_GRADE_ADDRESS + sizeof(crackAccessGradeCode) * 5), &crackAccessStrengthCode, sizeof(crackAccessStrengthCode), 0);
								WriteProcessMemory(pi.hProcess, (LPVOID)(ACCESS_GRADE_ADDRESS + sizeof(crackAccessGradeCode) * 6), &crackAccessInternalforceCode, sizeof(crackAccessInternalforceCode), 0);
								WriteProcessMemory(pi.hProcess, (LPVOID)(ACCESS_GRADE_ADDRESS + sizeof(crackAccessGradeCode) * 7), &crackAccessMoneyCode, sizeof(crackAccessMoneyCode), 0);
								regs.Dr0 = ACCESS_GRADE_ADDRESS + sizeof(crackAccessGradeCode) * 8;
								regs.Dr7 = 0x101;
							}
							SetThreadContext(pi.hThread, &regs);
							ContinueDebugEvent(dEvent.dwProcessId, dEvent.dwThreadId, DBG_CONTINUE);  //WIN 10使用pi.dwProcessId和pi.dwThreadId启动不了程序，WIN 7可以
							WaitForDebugEvent(&dEvent, INFINITE);
							GetThreadContext(pi.hThread, &regs);
							if (regs.Eip == (ACCESS_GRADE_ADDRESS + sizeof(crackAccessGradeCode) * 8)) {
								//执行完注入代码
								//Eip指针指向上一条指令, 写入旧代码, 从旧代码处开始执行
								regs.Eip -= (sizeof(crackAccessGradeCode) * 8);
								WriteProcessMemory(pi.hProcess, (LPVOID)ACCESS_GRADE_ADDRESS, &originalCode, sizeof(originalCode), 0);
								memeryTamperingService.setOperateState(OPERATE_STATE_FINISH_MODIFY_SPIRIT);
							}
							regs.Dr0 = regs.Dr7 = 0;
							SetThreadContext(pi.hThread, &regs);
						} else {
							GetThreadContext(pi.hThread, &regs);
						    regs.Dr0 = regs.Dr7 = 0;
							SetThreadContext(pi.hThread, &regs);
						}
						break;
					}
					break;
					default:
						GetThreadContext(pi.hThread, &regs);
						regs.Dr0 = regs.Dr7 = 0;
						SetThreadContext(pi.hThread, &regs);
						break;
				}
				break;
			default:
				GetThreadContext(pi.hThread, &regs);
				regs.Dr0 = regs.Dr7 = 0;
				SetThreadContext(pi.hThread, &regs);
				break;
		}
		dwState = DBG_CONTINUE;
		DWORD a = dEvent.dwProcessId;
		DWORD b = dEvent.dwThreadId;
		ContinueDebugEvent(a, b, dwState);  //WIN 10使用pi.dwProcessId和pi.dwThreadId启动不了程序，WIN 7可以
	}
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);
	return 0;
}