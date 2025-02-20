#include <stdio.h>
#include <windows.h>
#include "common_checks.h"
#include "utils.h"

void check_sticky_keys() {
    HKEY hKey;
    DWORD dwType = REG_SZ;
    wchar_t value[256];     //Wide charcater type
    DWORD valueLength = sizeof(value);

    // Path to reg key
    const wchar_t* subKey = L"Control Panel\\Accessibility\\StickyKeys";

    // Open reg key
    if (RegOpenKeyExW(HKEY_CURRENT_USER, subKey, 0, KEY_READ, &hKey) != ERROR_SUCCESS) {
        //wprintf(L"Failed to open registry key.\n");
        LOG_ERROR("Failed to open the registry key.");
    }

    // Query the value of the "Flags" key
    if (RegQueryValueExW(hKey, L"Flags", NULL, &dwType, (LPBYTE)value, &valueLength) == ERROR_SUCCESS) {
        //wprintf(L"Sticky Keys Flag is: %ls\n", value);

        // Check if Sticky Keys is enabled (value contains code 510)
        if (wcsstr(value, L"510") != NULL) {
            //wprintf(L"Sticky Keys is enabled.\n");
            LOG_INFO("Sticky Keys is enabled.");
        }
        else if (wcsstr(value, L"506") != NULL) {
            //wprintf(L"Sticky Keys is disabled.\n");
            LOG_INFO("Sticky Keys is disabled.");
        }
        else {
            LOG_ERROR("Sticky Key value isnt 510 or 506.");
        }
    }
    else {
        //wprintf(L"Failed to query the registry value.\n");
        LOG_ERROR("Failed to query the registry value.");
    }

    // Close the registry key
    RegCloseKey(hKey);

}