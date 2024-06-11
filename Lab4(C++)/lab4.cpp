#include "framework.h"
#include "lab4.h";
#include "module1.h"; 
#include "module2.h"; 

HWND hWnd;
HWND button1;
HWND button2;
HWND message1;

HINSTANCE g_hInstance;

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_COMMAND:

        if (HIWORD(wParam) == BN_CLICKED && (HWND)lParam == button1) {

            SetWindowText(message1, Work1(g_hInstance, hWnd).c_str());
        }

        if (HIWORD(wParam) == BN_CLICKED && (HWND)lParam == button2) {

            int result = Work2_Part1(g_hInstance, hWnd);

            while (result != 2) {
                if (result == 0) {
                    result = Work2_Part1(g_hInstance, hWnd);
                }
                else if (result == 1) {
                    result = Work2_Part2(g_hInstance, hWnd);
                }
                else {
                    result = 2;
                }
            }
        }

        break;

    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
    g_hInstance = hInstance;

    WNDCLASS wc = { };
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = L"mainMenu";

    RegisterClass(&wc);

    hWnd = CreateWindowEx(WS_EX_LEFT, L"mainMenu", L"homework_C++", WS_OVERLAPPEDWINDOW, 500, 500, 250, 120, NULL, NULL, hInstance, NULL);
    button1 = CreateWindowEx(0, L"BUTTON", L"Work 1", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 10, 10, 50, 20, hWnd, NULL, hInstance, NULL);
    button2 = CreateWindowEx(0, L"BUTTON", L"Work 2", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 10, 50, 50, 20, hWnd, NULL, hInstance, NULL);
    message1 = CreateWindowEx(0, L"Static", L"", WS_CHILD | WS_VISIBLE, 70, 10, 150, 20, hWnd, NULL, hInstance, NULL);

    ShowWindow(hWnd, nCmdShow);

    MSG msg = { };
    while (GetMessage(&msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}
