#include "options.h"

// This function adds two options ("Option 1" and "Option 2") to the given combo box (hComboBox).
void AddOptions(HWND hComboBox)
{
    SendMessage(hComboBox, CB_ADDSTRING, 0, (LPARAM)L"Option 1");
    SendMessage(hComboBox, CB_ADDSTRING, 0, (LPARAM)L"Option 2");
    SendMessage(hComboBox, CB_ADDSTRING, 0, (LPARAM)L"Option 3");
}
