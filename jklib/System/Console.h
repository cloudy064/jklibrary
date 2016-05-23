#ifndef __JKLIB_SYSTEM_CONSOLE_H__
#define __JKLIB_SYSTEM_CONSOLE_H__

#include "jklib/Internal/System/IConsole.h"
#include "jklib/Pattern/Singleton.h"
#include <wtypes.h>

namespace JkLib
{
    namespace System
    {

        class Console
            : public Internal::System::IConsole
        {
        private:
            ~Console()
            {

            }

        public:

        private:
        };
    }
}
#endif //!__JKLIB_SYSTEM_CONSOLE_H__
