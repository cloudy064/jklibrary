#ifndef __JKLIB_PLATFORM_WIN32_CONSOLE_H__
#define __JKLIB_PLATFORM_WIN32_CONSOLE_H__

#include "jklib/Internal/System/IConsole.h"

namespace JkLib
{
    namespace Platform
    {
        namespace Win32
        {
            class Console
                : public Internal::System::IConsole
            {
            public:
                virtual int Write(void* buffer, int nOffset, int nWriteSize) override
                {

                }
            }
        }
    }
}

#endif //!__JKLIB_PLATFORM_WIN32_CONSOLE_H__
