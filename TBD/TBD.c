//#include <stdio.h>
//#include <windows.h>
//
//void check_sticky_keys() {
//    HKEY hKey;
//    DWORD dwType = REG_SZ;
//    wchar_t value[256];     //Wide charcater type
//    DWORD valueLength = sizeof(value);
//
//    // Path to reg key
//    const wchar_t* subKey = L"Control Panel\\Accessibility\\StickyKeys";
//
//    // Open reg key
//    if (RegOpenKeyExW(HKEY_CURRENT_USER, subKey, 0, KEY_READ, &hKey) != ERROR_SUCCESS) {
//        wprintf(L"Failed to open registry key.\n");
//    }
//
//    // Query the value of the "Flags" key
//    if (RegQueryValueExW(hKey, L"Flags", NULL, &dwType, (LPBYTE)value, &valueLength) == ERROR_SUCCESS) {
//        wprintf(L"Sticky Keys Flags: %ls\n", value);
//
//        // Check if Sticky Keys is enabled (value contains code 510)
//        if (wcsstr(value, L"510") != NULL) {
//            wprintf(L"Sticky Keys is enabled.\n");
//        }
//        else {
//            wprintf(L"Sticky Keys is disabled.\n");
//        }
//    }
//    else {
//        wprintf(L"Failed to query the registry value.\n");
//    }
//
//    // Close the registry key
//    RegCloseKey(hKey);
//
//}
//
//void check_ntlmv1_usage() {
//    HKEY hKey;
//    DWORD value = 0;
//    DWORD valueSize = sizeof(value);
//
//    // Path to the registry key
//    const wchar_t* subKey = L"SYSTEM\\CurrentControlSet\\Control\\Lsa";
//    const wchar_t* valueName = L"LmCompatibilityLevel";
//
//    // Open the registry key
//    if (RegOpenKeyExW(HKEY_LOCAL_MACHINE, subKey, 0, KEY_READ, &hKey) != ERROR_SUCCESS) {
//        fprintf(stderr, "[ERROR] Failed to open registry key: %ls\n", subKey);
//        fprintf(stderr, "[ERROR] Or key doesnt exist.");
//        return;
//    }
//
//    // Query the registry value
//    if (RegQueryValueExW(hKey, valueName, NULL, NULL, (LPBYTE)&value, &valueSize) == ERROR_SUCCESS) {
//        printf("[INFO] LmCompatibilityLevel: %u\n", value);
//
//        // Check if NTLMv1 is allowed
//        if (value < 3) {
//            printf("[WARNING] NTLMv1 is allowed. Consider setting LmCompatibilityLevel to 3 or higher to disable NTLMv1.\n");
//        }
//        else {
//            printf("[INFO] NTLMv1 is not allowed. The system is configured securely.\n");
//        }
//    }
//    else {
//        fprintf(stderr, "[ERROR] Failed to query registry value: %ls\n", valueName);
//    }
//
//    // Close the registry key
//    RegCloseKey(hKey);
//}
//
//int main() {
//    check_sticky_keys();
//    check_ntlmv1_usage();
//
//    return 0;
//}
