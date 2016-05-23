#include "CriticalSection.h"
#include <synchapi.h>

bool JkLib::Platform::Win32::CriticalSection::TryLock()
{
    return (!!::TryEnterCriticalSection(&csLock));
}

void JkLib::Platform::Win32::CriticalSection::Unlock()
{
    ::LeaveCriticalSection(&csLock);
}

void JkLib::Platform::Win32::CriticalSection::Lock()
{
    ::EnterCriticalSection(&csLock);
}

JkLib::Platform::Win32::CriticalSection::~CriticalSection()
{
    ::DeleteCriticalSection(&csLock);
}

JkLib::Platform::Win32::CriticalSection::CriticalSection()
{
    ::InitializeCriticalSection(&csLock);
}

