#pragma once
#include <windows.h>
#include <tchar.h>
#include <time.h>
#include <ctime>
#include "resource.h"
#include <windowsX.h>
#include <commctrl.h>

#pragma comment(lib,"comctl32")

HWND hbutton1,hbutton2,hbutton3;
HWND hradio1,hradio2;
HWND hcombo;
HWND hedit1, hedit2, hedit3, hedit4, hedit5, hedit6, hedit7, hedit8, hedit9, hedit10, hedit11, hedit12, hedit13, hedit14;
HWND hcheck1, hcheck2, hcheck3, hcheck4;

int sum1 = 0, sum2 = 0, sum3 = 0;
int const benz1 = 10;
int const benz2 = 10;

void Close(HWND hwnd)
{
	EndDialog(hwnd, 0);
}

BOOL InitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam)
{
	hcombo = GetDlgItem(hwnd, IDC_COMBO1);

	hedit1 = GetDlgItem(hwnd, IDC_EDIT1);
	hedit2 = GetDlgItem(hwnd, IDC_EDIT2);
	hedit3 = GetDlgItem(hwnd, IDC_EDIT3);
	hedit4 = GetDlgItem(hwnd, IDC_EDIT4);
	hedit5 = GetDlgItem(hwnd, IDC_EDIT5);
	hedit6 = GetDlgItem(hwnd, IDC_EDIT6);
	hedit7 = GetDlgItem(hwnd, IDC_EDIT7);
	hedit8 = GetDlgItem(hwnd, IDC_EDIT8);
	hedit9 = GetDlgItem(hwnd, IDC_EDIT9);
	hedit10 = GetDlgItem(hwnd, IDC_EDIT10);
	hedit11 = GetDlgItem(hwnd, IDC_EDIT11);
	hedit12 = GetDlgItem(hwnd, IDC_EDIT12);
	hedit13 = GetDlgItem(hwnd, IDC_EDIT13);
	hedit14 = GetDlgItem(hwnd, IDC_EDIT14);

	hradio1 = GetDlgItem(hwnd, IDC_RADIO1);
	hradio2 = GetDlgItem(hwnd, IDC_RADIO2);

	hcheck1 = GetDlgItem(hwnd, IDC_CHECK1);
	hcheck2 = GetDlgItem(hwnd, IDC_CHECK2);
	hcheck3 = GetDlgItem(hwnd, IDC_CHECK3);
	hcheck4 = GetDlgItem(hwnd, IDC_CHECK4);

	SendDlgItemMessage(hwnd, IDC_CHECK1, BM_SETCHECK, WPARAM(BST_CHECKED), 0);
	SendDlgItemMessage(hwnd, IDC_RADIO1, BM_SETCHECK, WPARAM(BST_CHECKED), 0);

	SendMessage(hcombo, CB_ADDSTRING, 0, LPARAM(TEXT("A-92")));
	SendMessage(hcombo, CB_ADDSTRING, 0, LPARAM(TEXT("A-95")));

	return TRUE;
}
void Command(HWND hwnd, UINT message, HWND hwndCtl, UINT codeNotify)
{
	LRESULT re1 = SendDlgItemMessage(hwnd, IDC_RADIO1, BM_GETCHECK, 0, 0);
	LRESULT re2 = SendDlgItemMessage(hwnd, IDC_RADIO2, BM_GETCHECK, 0, 0);

	LRESULT re3 = SendDlgItemMessage(hwnd, IDC_CHECK1, BM_GETCHECK, 0, 0);
	LRESULT re4 = SendDlgItemMessage(hwnd, IDC_CHECK2, BM_GETCHECK, 0, 0);
	LRESULT re5 = SendDlgItemMessage(hwnd, IDC_CHECK3, BM_GETCHECK, 0, 0);
	LRESULT re6 = SendDlgItemMessage(hwnd, IDC_CHECK4, BM_GETCHECK, 0, 0);

	TCHAR benz[10];
	TCHAR oper[25];
	TCHAR Sum[25];

	TCHAR A1[25],A2[25], A3[25], A4[25];
	TCHAR B1[25], B2[25], B3[25], B4[25];

	int a=0;

	int a1=0, a2=0, a3=0, a4=0;
	int b1=0, b2=0, b3=0, b4=0;

    int index = SendMessage(hcombo, CB_GETCURSEL, 0, 0);
	switch(index)
	{
	case 0:
		wsprintf(benz, TEXT("%d"), benz1);
		SendMessage(hedit2, WM_SETTEXT, 0, LPARAM(benz));
		break;
	case 1:
		wsprintf(benz, TEXT("%d"), benz2);
	    SendMessage(hedit2, WM_SETTEXT, 0, LPARAM(benz));
		break;
	}
	
	switch (message)
	{
	case IDC_BUTTON1:
		sum3 = sum1 + sum2;
		wsprintf(Sum, TEXT("%d"), sum3);
		SendMessage(hedit1, WM_SETTEXT, 0, LPARAM(Sum));
	case IDC_BUTTON2:
		if (re1 == BST_CHECKED)
		{
			GetWindowText(hedit3, oper, 20);
			wsprintf(oper, TEXT("%d"), a);
		}
		sum1 = a * benz1;
	case IDC_BUTTON3:
		if (re3 == BST_CHECKED)
		{
			GetWindowText(hedit5, A1, 20);
			wsprintf(A1, TEXT("%d"), a1);

			GetWindowText(hedit6, B1, 20);
			wsprintf(B1, TEXT("%d"), b1);

			sum2 += a1 * b1;
		}
		if (re4 == BST_CHECKED)
		{
			GetWindowText(hedit7, A2, 20);
			wsprintf(A2, TEXT("%d"), a2);

			GetWindowText(hedit7, B2, 20);
			wsprintf(B2, TEXT("%d"), b2);

			sum2 += a2 * b2;
		}
		if (re5 == BST_CHECKED)
		{
			GetWindowText(hedit9, A3, 20);
			wsprintf(A3, TEXT("%d"), a3);

			GetWindowText(hedit9, B3, 20);
			wsprintf(B3, TEXT("%d"), b3);

			sum2 += a3 * b3;
		}
		if (re6 == BST_CHECKED)
		{
			GetWindowText(hedit11, A4, 20);
			wsprintf(A4, TEXT("%d"), a4);

			GetWindowText(hedit11, B4, 20);
			wsprintf(B4, TEXT("%d"), b4);

			sum2 += a4 * b4;
		}
	}
}
BOOL CALLBACK DlgProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		HANDLE_MSG(hwnd, WM_CLOSE, Close);
		HANDLE_MSG(hwnd, WM_INITDIALOG, InitDialog);
		HANDLE_MSG(hwnd, WM_COMMAND, Command);
	}
	return FALSE;
}