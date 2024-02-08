#include "ui.h"
#include "options.h"
#include "button.h"

// This function handles the messages for the main window.
LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_CLOSE:
        PostQuitMessage(0);
        break;
    case WM_COMMAND:
        if (LOWORD(wParam) == 1) {
            MessageBox(hwnd, L"You clicked the button!", L"Notification", MB_OK | MB_ICONINFORMATION);
        }
        break;
    }
    return DefWindowProc(hwnd, msg, wParam, lParam);
}

// This function creates the main window, adds a combo box with options to it, and a button. It returns the handle to the main window.
HWND CreateMainWindow(HINSTANCE hInst)
{
    const wchar_t CLASS_NAME[] = L"Sample Window Class";

    WNDCLASS wc = { };

    wc.lpfnWndProc = WindowProcedure;
    wc.hInstance = hInst;
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

    HWND hwnd = CreateWindowEx(0, CLASS_NAME, L"Sample Window", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 240, 120, NULL, NULL, hInst, NULL);

    if (hwnd == NULL)
    {
        return NULL;
    }

    // Create a dropdown list
    HWND hComboBox = CreateWindow(L"COMBOBOX", NULL, CBS_DROPDOWN | CBS_HASSTRINGS | WS_CHILD | WS_OVERLAPPED | WS_VISIBLE, 10, 10, 100, 100, hwnd, NULL, NULL, NULL);
    AddOptions(hComboBox);

    // Create a button
    CreateButton(hwnd);

    return hwnd;
}
