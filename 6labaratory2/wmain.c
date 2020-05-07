#ifndef UNICODE
#define UNICODE
#endif
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<math.h>
#include"logic.h"
#include"randnumber.h"
#include"world.h"
const char g_szClassName[] = "myWindowClass";
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_CLOSE:
        DestroyWindow(hwnd);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    hidecursor();
    HWND hwnd;
    char Title[1024];
    GetConsoleTitle(Title, 1024);
    hwnd = FindWindow(NULL, Title);
    HDC hdc = GetDC(hwnd);
    int NumberOfString = 30;
    int NumberOfColumn = 30;
    int size = 2 * (int)sqrt(NumberOfString * NumberOfColumn);
    int Time = 100;
    WNDCLASSEX wc;
    MSG Msg;
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = 0;
    wc.lpfnWndProc = WndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(8);
    wc.lpszMenuName = NULL;
    wc.lpszClassName = g_szClassName;
    wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
    if (!RegisterClassEx(&wc))
    {
        MessageBox(NULL, L"Window Registration Failed!", L"Error!",
            MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }
    hwnd = CreateWindowEx(WS_EX_CLIENTEDGE,g_szClassName,L"Labaratory6",WS_OVERLAPPEDWINDOW,CW_USEDEFAULT, CW_USEDEFAULT, 700, 700,NULL, NULL, hInstance, NULL);
    if (hwnd == NULL)
    {
        MessageBox(NULL, L"Window Creation Failed!", L"Error!",
            MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }
    while (GetMessage(&Msg, NULL, 0, 0) > 0){
        World W1 = MakeFullWorld(NumberOfString, NumberOfColumn);
        Point* points = MakePointsInWorld(15, W1);
        FreeAllPoints(&W1, points, 15);
        HDC hdc = GetDC(hwnd);
        for (int i = 0; i < NumberOfString; i++) {
            for (int j = 0; j < NumberOfColumn; j++) {
                if (W1.Arr[i][j] == 35) {
                    HBRUSH hBrush = CreateSolidBrush(RGB(255, 250, 250));
                    SelectObject(hdc, hBrush);
                    Ellipse(hdc, 10 + (i + 1) * 20, 10 + (j + 1) * 20, 10 + i * 20, 10 + j * 20);
                    DeleteObject(hBrush);
                }
                else
                {
                    HBRUSH hBrush = CreateSolidBrush(RGB(0, 0, 0));
                    SelectObject(hdc, hBrush);
                    Ellipse(hdc, 10 + (i + 1) * 20, 10 + (j + 1) * 20, 10 + i * 20, 10 + j * 20);
                    DeleteObject(hBrush);
                }
            }
        }
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
        ShowWindow(hwnd, nCmdShow);
       
    }
    return Msg.wParam;
}