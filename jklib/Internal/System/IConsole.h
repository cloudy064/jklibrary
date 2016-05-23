#ifndef __JKLIB_INTERNAL_ICONSOLE_H__
#define __JKLIB_INTERNAL_ICONSOLE_H__

#include "jklib/Descriptor/IWritable.h"

namespace JkLib
{
    namespace Internal
    {

        namespace System
        {
            class IConsole
                : public Descriptor::IWritable

            {
            };
        }
    }
}

#endif //!__JKLIB_INTERNAL_ICONSOLE_H__
