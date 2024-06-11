#include "module2.h"

static INT_PTR CALLBACK DialogProcessor1(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_INITDIALOG:
        return TRUE;
    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
        case IDOK:
            EndDialog(hwndDlg, 1);
            break;

        case IDCANCEL:
            EndDialog(hwndDlg, 2);
            break;
        }
        break;
    }
    return FALSE;
}

static INT_PTR CALLBACK DialogProcessor2(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_INITDIALOG:
        return TRUE;
    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
        case IDOK:
            EndDialog(hwndDlg, 0);
            break;
        case IDOK2:
            EndDialog(hwndDlg, 2);
            break;
        case IDCANCEL:
            EndDialog(hwndDlg, 2);
            break;
        }
        break;
    }
    return FALSE;
}

int Work2_Part1(HINSTANCE g_hInstance, HWND hWnd)
{
    int res = DialogBoxW(g_hInstance, MAKEINTRESOURCE(IDD_DIALOG1), hWnd, DialogProcessor1);
    return res;
}

int Work2_Part2(HINSTANCE g_hInstance, HWND hWnd)
{
    int res = DialogBoxW(g_hInstance, MAKEINTRESOURCE(IDD_DIALOG2), hWnd, DialogProcessor2);
    return res;
}