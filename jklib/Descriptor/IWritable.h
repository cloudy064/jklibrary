#ifndef __IWRITABLE_H__
#define __IWRITABLE_H__

namespace JkLib
{
    namespace Descriptor
    {
        class IWritable
        {
        public:
            virtual int Write(unsigned char* buffer, int nOffset, int nWriteSize) = 0;
        };
    }
}

#endif //!__IWRITABLE_H__
