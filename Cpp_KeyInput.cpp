#include <Windows.h>
#include <string>
#include <tchar.h>
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{
    TCHAR appname[] = TEXT("Detect Key Input");
    MSG msg;
    HWND hwnd;
    WNDCLASS wndclass;
    wndclass.cbClsExtra = 0;
    wndclass.cbWndExtra = 0;
    wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wndclass.hInstance = hInstance;
    wndclass.lpfnWndProc = WndProc;
    wndclass.lpszClassName = appname;
    wndclass.lpszMenuName = NULL;
    wndclass.style = CS_HREDRAW | CS_VREDRAW;
    if (!RegisterClass(&wndclass))
    {
        MessageBox(NULL, TEXT("Class not registered"), TEXT("Error...."), MB_OK);
    }
    hwnd = CreateWindow(appname,
        appname,
        WS_OVERLAPPEDWINDOW,
        300,
        200,
        400,
        300,
        NULL,
        NULL,
        hInstance,
        NULL);
    ShowWindow(hwnd, iCmdShow);
    UpdateWindow(hwnd);
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return msg.wParam;
}
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    char buffer[127] = { 0 };
    switch (message)
    {
    case WM_KEYDOWN:
        sprintf_s(buffer, "WM_KEYDOWN: %d", wParam);
        SetWindowTextA(hwnd, buffer);
        break;
    case WM_KEYUP:
        sprintf_s(buffer, "WM_KEYUP: %d", wParam);
        SetWindowTextA(hwnd, buffer);
        break;
    case WM_DESTROY:
        PostQuitMessage(EXIT_SUCCESS);
        return 0;
    }
    return DefWindowProc(hwnd, message, wParam, lParam);
}
