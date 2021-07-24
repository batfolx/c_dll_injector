//
// Created by Victor on 7/24/2021.
//

#include "windows.h"
#include "stdio.h"

BOOL WINAPI DllMain(
        HINSTANCE hinstDLL,  // handle to DLL module
DWORD fdwReason,     // reason for calling function
LPVOID lpReserved )  // reserved
{
    printf("Successfully called DllMain\n");
    // Perform actions based on the reason for calling.
    switch( fdwReason )
    {
        case DLL_PROCESS_ATTACH:
            MessageBoxA(NULL, "Hello :)", "Destroyed.", MB_OK);
            printf("DLL PROCESS ATTACH\n");
            break;

        case DLL_THREAD_ATTACH:
            MessageBoxA(NULL, "Hello :)", "Destroyed.", MB_OK);
            printf("DLL THREAD ATTACH\n");
            // Do thread-specific initialization.
            break;

        case DLL_THREAD_DETACH:
            // Do thread-specific cleanup.
            break;

        case DLL_PROCESS_DETACH:
            // Perform any necessary cleanup.
            break;
    }
    return TRUE;  // Successful DLL_PROCESS_ATTACH.
}