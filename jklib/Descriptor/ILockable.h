#ifndef __ILOCKABLE_H__
#define __ILOCKABLE_H__

namespace Descriptor
{
    class ILockable
    {
    public:
        virtual void Lock() = 0;
        virtual void Unlock() = 0;
        virtual bool TryLock() = 0;
    };
}

#endif //!__ILOCKABLE_H__
