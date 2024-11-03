#ifndef UNICODE
#define UNICODE
#endif
#include <windows.h>
HWND hwnd;
LRESULT CALLBACK wndProc(HWND hwnd, UINT umsg, WPARAM wp, LPARAM lp)
{
    switch (umsg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hwnd, umsg, wp, lp);
}
int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrev, LPSTR cmd, int nCmdShow)
{
	WNDCLASSEX wc = {};
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.lpfnWndProc = wndProc;
	wc.hInstance = hInst;
	wc.lpszClassName = L"DefClass";
	RegisterClassEx(&wc);
	hwnd = CreateWindowEx(0, L"DefClass", L"Default Win32 Program", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, 0, 1280, 720, NULL, NULL, hInst, NULL);
	ShowWindow(hwnd, nCmdShow);
    MSG  msg;
    msg.message = WM_NULL;
    PeekMessage(&msg, NULL, 0, 0, PM_NOREMOVE);
    while (WM_QUIT != msg.message)
    {
        if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE) != 0)
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        else
        {

        }
    }
    DestroyWindow(hwnd);
    UnregisterClass(L"DefClass", hInst);
    return 0;
}