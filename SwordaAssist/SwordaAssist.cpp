// SwordaAssist.cpp : 定义应用程序的入口点。
//

#include "stdafx.h"
#include "SwordaAssist.h"
#include "SpiritAutoProtect.h"

#define MAX_LOADSTRING 100

// 全局变量:
HINSTANCE hInst;                                // 当前实例
WCHAR szTitle[MAX_LOADSTRING];                  // 标题栏文本
WCHAR szWindowClass[MAX_LOADSTRING];            // 主窗口类名
WCHAR szFilePath[MAX_PATH];                     //打开的游戏路径
BOOL    OpenFileDlg(HWND);
HICON     hIcon;

// 此代码模块中包含的函数的前向声明:
LRESULT CALLBACK MainDialogProc(HWND, UINT, WPARAM, LPARAM);
VOID SettingDefaultValue(HWND hWnd);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

	hInst = hInstance;
	DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, (DLGPROC)MainDialogProc);

    // 初始化全局字符串
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_SWORDAASSIST, szWindowClass, MAX_LOADSTRING);

	return FALSE;
}

// “关于”框的消息处理程序。
INT_PTR CALLBACK about(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}

//
//  函数: MainDialogProc(HWND, UINT, WPARAM, LPARAM)
//
//  目标: 处理主对话框的消息。
//
//
LRESULT CALLBACK MainDialogProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
	int wmId, wmEvent;
	HWND startHnd, static22, static23, static24, edit;
	HFONT hFont;//定义静态字体变量
	Spirit inputSpirit;
	SpiritAutoProtect inputAutoProtect;
	LPWSTR gradeLps = new wchar_t[10];
	ZeroMemory(gradeLps, 10);
	LPWSTR defenseLps = new wchar_t[10];
	ZeroMemory(defenseLps, 10);
	LPWSTR aggressivityLps = new wchar_t[10];
	ZeroMemory(aggressivityLps, 10);
	LPWSTR positioningLps = new wchar_t[10];
	ZeroMemory(positioningLps, 10);
	LPWSTR lifeLps = new wchar_t[10];
	ZeroMemory(lifeLps, 10);
	LPWSTR strengthLps = new wchar_t[10];
	ZeroMemory(strengthLps, 10);
	LPWSTR internalforceLps = new wchar_t[10];
	ZeroMemory(internalforceLps, 10);
	LPWSTR moneyLps = new wchar_t[10];
	ZeroMemory(moneyLps, 10);

	LPWSTR lowValLifeLps  = new wchar_t[10];
	ZeroMemory(lowValLifeLps, 10);
	LPWSTR addValLifeLps = new wchar_t[10];
	ZeroMemory(addValLifeLps, 10);
	LPWSTR lowValStrengthLps = new wchar_t[10];
	ZeroMemory(lowValStrengthLps, 10);
	LPWSTR addValStrengthLps = new wchar_t[10];
	ZeroMemory(addValStrengthLps, 10);
	LPWSTR lowValInternalforceLps = new wchar_t[10];
	ZeroMemory(lowValInternalforceLps, 10);
	LPWSTR addValInternalforceLps = new wchar_t[10];
	ZeroMemory(addValInternalforceLps, 10);

	switch (message) {
	case WM_INITDIALOG:
		hIcon = LoadIcon(hInst, MAKEINTRESOURCE(IDI_ASSIST));
		SendMessage(hWnd, WM_SETICON, ICON_SMALL, (LPARAM)hIcon);
		InitCommonControls();
		SettingDefaultValue(hWnd);

		//创建字体
		hFont = CreateFont(11, 0, 0, 0, 0, FALSE, 
			FALSE, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
			DEFAULT_PITCH | FF_SWISS, TEXT("新宋体"));
		//发送设置字体消息
		static22 = GetDlgItem(hWnd, IDC_STATIC22);
		SendMessage(static22, WM_SETFONT, (WPARAM)hFont, TRUE);
		static23 = GetDlgItem(hWnd, IDC_STATIC23);
		SendMessage(static23, WM_SETFONT, (WPARAM)hFont, TRUE);
		static24 = GetDlgItem(hWnd, IDC_STATIC24);
		SendMessage(static24, WM_SETFONT, (WPARAM)hFont, TRUE);
		return TRUE;
	case WM_COMMAND:
		wmId = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		switch (wmId)
		{
		case ID_BUTTON_RUN_GAME:
			if (!OpenFileDlg(hWnd)) {
				MessageBox(hWnd, TEXT("打开游戏失败"), TEXT("提示"), MB_OK);
				return FALSE;
			}

			if (!memeryTamperingService.startGameAndDebug(szFilePath)) {
				MessageBox(hWnd, TEXT("创建调试线程失败"), TEXT("提示"), MB_OK);
			}

			//设置启动游戏按钮为灰色
			startHnd = GetDlgItem(hWnd, ID_BUTTON_RUN_GAME);
			//SetWindowText(startHnd, FALSE);
			EnableWindow(startHnd, FALSE);
			return TRUE;
		case ID_BUTTON_REFRESH:
			memeryTamperingService.refreshCurrentSpiritInfo(hWnd);
			return TRUE;
		case ID_BUTTON_MODIFY_DATA: 
				//读取文本内容
				edit = GetDlgItem(hWnd, IDC_EDIT9);
				GetWindowText(edit, gradeLps, IDC_EDIT9);
				inputSpirit.setGrade(_wtoi(gradeLps));

				edit = GetDlgItem(hWnd, IDC_EDIT5);
				GetWindowText(edit, defenseLps, IDC_EDIT5);
				inputSpirit.setDefense(_wtoi(defenseLps));

				edit = GetDlgItem(hWnd, IDC_EDIT1);
				GetWindowText(edit, aggressivityLps, IDC_EDIT1);
				inputSpirit.setAggressivity(_wtoi(aggressivityLps));

				edit = GetDlgItem(hWnd, IDC_EDIT3);
				GetWindowText(edit, positioningLps, IDC_EDIT3);
				inputSpirit.setPositioning(_wtoi(positioningLps));

				edit = GetDlgItem(hWnd, IDC_EDIT4);
				GetWindowText(edit, lifeLps, IDC_EDIT4);
				inputSpirit.setLife(_wtoi(lifeLps));

				edit = GetDlgItem(hWnd, IDC_EDIT6);
				GetWindowText(edit, strengthLps, IDC_EDIT6);
				inputSpirit.setStrength(_wtoi(strengthLps));

				edit = GetDlgItem(hWnd, IDC_EDIT8);
				GetWindowText(edit, internalforceLps, IDC_EDIT8);
				inputSpirit.setInternalforce(_wtoi(internalforceLps));

				edit = GetDlgItem(hWnd, IDC_EDIT7);
				GetWindowText(edit, moneyLps, IDC_EDIT7);
				inputSpirit.setMoney(_wtoi(moneyLps));

				edit = GetDlgItem(hWnd, IDC_EDIT2);
				GetWindowText(edit, lowValLifeLps, IDC_EDIT2);
				if (lowValLifeLps != NULL) {
					inputAutoProtect.setLowValInMaxLifePercent(_wtoi(lowValLifeLps));
				}
				edit = GetDlgItem(hWnd, IDC_EDIT10);
				GetWindowText(edit, addValLifeLps, IDC_EDIT10);
				if (addValLifeLps != NULL) {
					inputAutoProtect.setAddValInMaxLifePercent(_wtoi(addValLifeLps));
				}

				edit = GetDlgItem(hWnd, IDC_EDIT11);
				GetWindowText(edit, lowValStrengthLps, IDC_EDIT11);
				if (lowValStrengthLps != NULL) {
					inputAutoProtect.setLowValInMaxStrengthPercent(_wtoi(lowValStrengthLps));
				}
				edit = GetDlgItem(hWnd, IDC_EDIT12);
				GetWindowText(edit, addValStrengthLps, IDC_EDIT12);
				if (addValStrengthLps != NULL) {
					inputAutoProtect.setAddValInMaxStrengthPercent(_wtoi(addValStrengthLps));
				}

				edit = GetDlgItem(hWnd, IDC_EDIT13);
				GetWindowText(edit, lowValInternalforceLps, IDC_EDIT13);
				if (lowValInternalforceLps != NULL) {
					inputAutoProtect.setLowValInMaxInternalforcePercent(_wtoi(lowValInternalforceLps));
				}
				edit = GetDlgItem(hWnd, IDC_EDIT14);
				GetWindowText(edit, addValInternalforceLps, IDC_EDIT14);
				if (addValInternalforceLps != NULL) {
					inputAutoProtect.setAddValInMaxInternalforcePercent(_wtoi(addValInternalforceLps));
				}

				//请求修改英雄信息
				if (memeryTamperingService.tamperingSpirit(&inputSpirit, &inputAutoProtect)) {
					MessageBox(hWnd, TEXT("操作成功，切换回游戏后将生效"), TEXT("提示"), MB_OK);
				}

				return TRUE;
		case IDD_ABOUTBTN:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, (DLGPROC)about);
			return TRUE;
		case ID_BUTTON_CANCEL:
			EndDialog(hWnd, 0);
			return TRUE;
		}
		break;
	case WM_CLOSE:
		EndDialog(hWnd, 0);
		break;
	}

	delete(gradeLps);
	delete(defenseLps);
	delete(aggressivityLps);
	delete(positioningLps);
	delete(lifeLps);
	delete(strengthLps);
	delete(internalforceLps);
	delete(moneyLps);
	return 0;
}

//
//  函数: OpenFileDlg(HWND)
//
//  目标: 打开游戏exe。
//
BOOL  OpenFileDlg(HWND hwnd) {
	OPENFILENAME ofn;
	memset(szFilePath, 0, MAX_PATH);
	memset(&ofn, 0, sizeof(ofn));

	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = hwnd;
	ofn.hInstance = GetModuleHandle(NULL);
	ofn.nMaxFile = MAX_PATH;
	ofn.lpstrInitialDir = TEXT(".");
	ofn.lpstrFile = szFilePath;
	ofn.lpstrTitle = TEXT("Open ...[SwordaAssist]");
	ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY;
	ofn.lpstrFilter = TEXT("*.*\0*.*\0");
	if (!GetOpenFileName(&ofn)) {
		return FALSE;
	}
	return TRUE;
}

VOID SettingDefaultValue(HWND hWnd) {
	HWND edit = GetDlgItem(hWnd, IDC_EDIT9);
	SetWindowText(edit, TEXT("79"));
	edit = GetDlgItem(hWnd, IDC_EDIT5);
	SetWindowText(edit, TEXT("2701"));
	edit = GetDlgItem(hWnd, IDC_EDIT1);
	SetWindowText(edit, TEXT("3469"));
	edit = GetDlgItem(hWnd, IDC_EDIT3);
	SetWindowText(edit, TEXT("344"));
	edit = GetDlgItem(hWnd, IDC_EDIT4);
	SetWindowText(edit, TEXT("3732"));
	edit = GetDlgItem(hWnd, IDC_EDIT6);
	SetWindowText(edit, TEXT("1309"));
	edit = GetDlgItem(hWnd, IDC_EDIT8);
	SetWindowText(edit, TEXT("1067"));
	edit = GetDlgItem(hWnd, IDC_EDIT7);
	SetWindowText(edit, TEXT("666"));
}
