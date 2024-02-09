#ifndef TRIGGER_H
#define TRIGGER_H

#include <windows.h>

// This function creates a trigger section in the given window (hwnd) and returns the handle to the trigger dropdown list.
HWND CreateTriggerSection(HWND hwnd, int position);

#endif // TRIGGER_H
