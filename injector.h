//
// Created by Victor on 7/23/2021.
//

#ifndef DLL_INJECTOR_INJECTOR_H
#define DLL_INJECTOR_INJECTOR_H
#include <stdio.h>
#include <windows.h>
#include <tlhelp32.h>
#include <tchar.h>
#include <stdbool.h>

DWORD get_proc_id(char* process_name);


#endif //DLL_INJECTOR_INJECTOR_H
