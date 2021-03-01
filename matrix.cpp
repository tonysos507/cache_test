// matrix.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <Windows.h>
#include <malloc.h>
#include <stdio.h>
#include <iostream>

#define N 1000
double __declspec(align(64)) res[N][N];
double __declspec(align(64)) mul1[N][N];
double __declspec(align(64)) mul2[N][N];

typedef BOOL(WINAPI* LPFN_GLPI)(PSYSTEM_LOGICAL_PROCESSOR_INFORMATION, PDWORD);

int main()
{
    LPFN_GLPI glpi = (LPFN_GLPI)GetProcAddress(GetModuleHandle(TEXT("kernel32")), "GetLogicalProcessorInformation");
    PSYSTEM_LOGICAL_PROCESSOR_INFORMATION buffer = NULL;
    PSYSTEM_LOGICAL_PROCESSOR_INFORMATION ptr = NULL;
    DWORD returnLength = 0;
    DWORD rc = glpi(buffer, &returnLength);
    buffer = (PSYSTEM_LOGICAL_PROCESSOR_INFORMATION)malloc(returnLength);
    rc = glpi(buffer, &returnLength);
    DWORD byteOffset = 0;
    PCACHE_DESCRIPTOR Cache;
    ptr = buffer;
    while (byteOffset + sizeof(SYSTEM_LOGICAL_PROCESSOR_INFORMATION) <= returnLength)
    {
        switch (ptr->Relationship)
        {
        case RelationCache:
            Cache = &ptr->Cache;
            printf("Level:%d LineSize:%d TotalSize:%d CacheType:%d\n", Cache->Level, Cache->LineSize, Cache->Size, Cache->Type);
        default:
            break;
        }
        byteOffset += sizeof(SYSTEM_LOGICAL_PROCESSOR_INFORMATION);
        ptr++;
    }
    free(buffer);
    return 0;
}


