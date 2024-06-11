#include "module1.h"

static HWND hScrollBar;
static int nPos;

static INT_PTR CALLBACK DialogProcessor(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_INITDIALOG:
        hScrollBar = CreateWindowEx(0, L"SCROLLBAR", NULL, WS_CHILD | WS_VISIBLE | SBS_HORZ, 10, 10, 200, 40, hwndDlg, NULL, NULL, NULL);
        SetScrollRange(hScrollBar, SB_CTL, 0, 100, TRUE);

        return TRUE;

    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
        case IDOK:
            nPos = GetScrollPos(hScrollBar, SB_CTL);
            EndDialog(hwndDlg, IDOK);
            break;

        case IDCANCEL:
            EndDialog(hwndDlg, IDCANCEL);
            break;
        }
        break;

    case WM_HSCROLL:

        if ((HWND)lParam == hScrollBar) {

            switch (LOWORD(wParam))
            {
            case SB_LINELEFT:
                SetScrollPos(hScrollBar, SB_CTL, GetScrollPos(hScrollBar, SB_CTL) - 2, TRUE);
                break;

            case SB_LINERIGHT:
                SetScrollPos(hScrollBar, SB_CTL, GetScrollPos(hScrollBar, SB_CTL) + 2, TRUE);
                break;

            case SB_PAGELEFT:
                SetScrollPos(hScrollBar, SB_CTL, GetScrollPos(hScrollBar, SB_CTL) - 5, TRUE);
                break;

            case SB_PAGERIGHT:
                SetScrollPos(hScrollBar, SB_CTL, GetScrollPos(hScrollBar, SB_CTL) + 5, TRUE);
                break;

            case SB_THUMBPOSITION:
            {
                SetScrollPos(hScrollBar, SB_CTL, HIWORD(wParam), TRUE);
            }
            break;
            }
        }
        break;
    case WM_CLOSE:
        EndDialog(hwndDlg, IDCANCEL);
        break;
    }

    return FALSE;
}

std::wstring Work1(HINSTANCE g_hInstance, HWND hWnd)
{
    DialogBoxW(g_hInstance, MAKEINTRESOURCE(107), hWnd, DialogProcessor);
    return std::to_wstring(nPos).c_str();
}