#include "dropdown.h"
#include "options.h"

// This function creates a dropdown list in the given window (hwnd), adds options to it, and returns the handle to the dropdown list.
HWND CreateDropdown(HWND hwnd)
{
    HWND hComboBox = CreateWindow(L"COMBOBOX", NULL, CBS_DROPDOWN | CBS_HASSTRINGS | WS_CHILD | WS_OVERLAPPED | WS_VISIBLE, 10, 10, 100, 100, hwnd, NULL, NULL, NULL);
    AddOptions(hComboBox);
    return hComboBox;
}
