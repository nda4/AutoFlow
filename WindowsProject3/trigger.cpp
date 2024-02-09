#include "trigger.h"
#include "options.h"

// This function creates a trigger section in the given window (hwnd), adds options to it, and returns the handle to the trigger dropdown list.
HWND CreateTriggerSection(HWND hwnd, int position)
{
    // Create a static text control for the "Choose a trigger: " label
    HWND hStatic = CreateWindow(L"STATIC", L"Choose a trigger: ", WS_CHILD | WS_VISIBLE | SS_LEFT, 10, 10 + position * 30, 120, 20, hwnd, NULL, NULL, NULL);

    // Create a dropdown list for the trigger options
    HWND hComboBox = CreateWindow(L"COMBOBOX", NULL, CBS_DROPDOWN | CBS_HASSTRINGS | WS_CHILD | WS_OVERLAPPED | WS_VISIBLE, 130, 10 + position * 30, 100, 100, hwnd, NULL, NULL, NULL);

    // Add the trigger options to the dropdown list
    SendMessage(hComboBox, CB_ADDSTRING, 0, (LPARAM)L"Created");
    SendMessage(hComboBox, CB_ADDSTRING, 0, (LPARAM)L"Updated");
    SendMessage(hComboBox, CB_ADDSTRING, 0, (LPARAM)L"Manual Trigger");

    // Create a second dropdown list for the data points
    HWND hComboBox2 = CreateWindow(L"COMBOBOX", NULL, CBS_DROPDOWN | CBS_HASSTRINGS | WS_CHILD | WS_OVERLAPPED, 240, 10 + position * 30, 100, 100, hwnd, NULL, NULL, NULL);

    // Add the data point options to the second dropdown list
    SendMessage(hComboBox2, CB_ADDSTRING, 0, (LPARAM)L"DataPoint1");
    SendMessage(hComboBox2, CB_ADDSTRING, 0, (LPARAM)L"DataPoint2");

    // Initially hide the second dropdown list
    ShowWindow(hComboBox2, SW_HIDE);

    return hComboBox;
}
