//
// Created by Victor on 7/23/2021.
//
#include "injector.h"


DWORD get_proc_id(char * process_name)
{
    HANDLE hProcessSnap;
    PROCESSENTRY32 pe32;

    // Take a snapshot of all processes in the system.
    hProcessSnap = CreateToolhelp32Snapshot( TH32CS_SNAPPROCESS, 0 );
    if (hProcessSnap == INVALID_HANDLE_VALUE) {
        return 0;
    }

    // Set the size of the structure before using it.
    pe32.dwSize = sizeof(PROCESSENTRY32);

    // Retrieve information about the first process,
    // and exit if unsuccessful
    if (!Process32First(hProcessSnap, &pe32)) {
        CloseHandle( hProcessSnap );          // clean the snapshot object
        return 0;
    }

    // Now walk the snapshot of processes, and
    // display information about each process in turn
    do {
        int length = (int)strlen(pe32.szExeFile);
        if (strncmp(pe32.szExeFile, process_name, length) == 0) {
            return pe32.th32ProcessID;
        }

    } while(Process32Next(hProcessSnap, &pe32));

    CloseHandle(hProcessSnap);
    return 0;
}

