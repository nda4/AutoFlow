#include "ui.h"
#include "button.h"
#include "dropdown.h"
#include "trigger.h" // Include the header file for trigger

// Define the identifiers for the dropdown lists
#define ID_TRIGGER_DROPDOWN 1001
#define ID_SECOND_DROPDOWN 1002

// Declare the handle to the second dropdown list
HWND hSecondDropdown;

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
            MessageBox(hwnd, L"You clicked the button!", L"Notification", MB_ICONINFORMATION);
        }
        // Check if the message is a notification message from the trigger dropdown box
        else if (LOWORD(wParam) == ID_TRIGGER_DROPDOWN && HIWORD(wParam) == CBN_SELCHANGE)
        {
            // Get the handle to the trigger dropdown box
            HWND hTriggerDropdown = (HWND)lParam;

            // Get the selected item in the trigger dropdown box
            int iSelected = SendMessage(hTriggerDropdown, CB_GETCURSEL, 0, 0);

            // Get the text of the selected item
            wchar_t szSelected[256];
            SendMessage(hTriggerDropdown, CB_GETLBTEXT, iSelected, (LPARAM)szSelected);

            // Check if "Created" or "Updated" are selected
            if (wcscmp(szSelected, L"Created") == 0 || wcscmp(szSelected, L"Updated") == 0)
            {
                // Show the second dropdown box
                ShowWindow(hSecondDropdown, SW_SHOW);
            }
            else
            {
                // Hide the second dropdown box
                ShowWindow(hSecondDropdown, SW_HIDE);
            }
        }
        break;
    }
    return DefWindowProc(hwnd, msg, wParam, lParam);
}

// This function creates the main window, adds a number of dropdown lists to it, and a button. It returns the handle to the main window.
HWND CreateMainWindow(HINSTANCE hInst)
{
    const wchar_t CLASS_NAME[] = L"Sample Window Class";

    WNDCLASS wc = { };

    wc.lpfnWndProc = WindowProcedure;
    wc.hInstance = hInst;
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

    // Define the number of dropdown lists
    int numDropdowns = 3;

    // Calculate the height of the window based on the number of dropdown lists
    int windowHeight = 120 + (numDropdowns + 1) * 30; // Increase the window height to accommodate the trigger section

    HWND hwnd = CreateWindowEx(0, CLASS_NAME, L"Sample Window", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 350, windowHeight, NULL, NULL, hInst, NULL);

    if (hwnd == NULL)
    {
        return NULL;
    }

    // Create the trigger section
    HWND hTriggerDropdown = CreateTriggerSection(hwnd, 0); // Add the trigger section at the top

    // Set the identifier of the trigger dropdown box
    SetWindowLong(hTriggerDropdown, GWL_ID, ID_TRIGGER_DROPDOWN);

    // Create the second dropdown list
    hSecondDropdown = CreateWindow(L"COMBOBOX", NULL, CBS_DROPDOWN | CBS_HASSTRINGS | WS_CHILD | WS_OVERLAPPED, 240, 10, 100, 100, hwnd, (HMENU)ID_SECOND_DROPDOWN, NULL, NULL);

    // Add the options to the second dropdown list
    SendMessage(hSecondDropdown, CB_ADDSTRING, 0, (LPARAM)L"DataPoint1");
    SendMessage(hSecondDropdown, CB_ADDSTRING, 0, (LPARAM)L"DataPoint2");

    // Initially hide the second dropdown list
    ShowWindow(hSecondDropdown, SW_HIDE);

    // Create the dropdown lists
    for (int i = 0; i < numDropdowns; i++)
    {
        // Adjust the position of each dropdown list
        SetWindowPos(CreateDropdown(hwnd), NULL, 10, 40 + i * 30, 0, 0, SWP_NOSIZE | SWP_NOZORDER); // Start the dropdown lists below the trigger section
    }

    // Adjust the position of the button
    SetWindowPos(CreateButton(hwnd), NULL, 120, (numDropdowns + 1) * 30, 0, 0, SWP_NOSIZE | SWP_NOZORDER); // Position the button below the dropdown lists

    return hwnd;
}
