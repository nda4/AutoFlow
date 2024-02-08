#include "button.h"

// This function creates a button with the text "Click me" in the given window (hwnd) and returns the handle to the button.
HWND CreateButton(HWND hwnd)
{
    // Create a button
    HWND hButton = CreateWindow(L"BUTTON", L"Click me", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 120, 10, 100, 25, hwnd, (HMENU)1, NULL, NULL);
    return hButton;
}
