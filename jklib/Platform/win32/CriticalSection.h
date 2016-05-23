#ifndef __CRITICAL_SECTION_H__
#define __CRITICAL_SECTION_H__

#include <windows.h>
#include "jklib/Descriptor/ILockable.h"


namespace JkLib
{
    namespace Platform
    {
        namespace Win32
        {
            class CriticalSection
                : public Descriptor::ILockable
            {
            public:
                CriticalSection();
                ~CriticalSection();

            public:
                virtual void Lock();
                virtual void Unlock();
                virtual bool TryLock();

            private:
                CRITICAL_SECTION csLock;
            };
        }
    }

}
#endif // !__CRITICAL_SECTION_H__