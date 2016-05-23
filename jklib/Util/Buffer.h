#ifndef __JKLIB_UTIL_BUFFER_H__
#define __JKLIB_UTIL_BUFFER_H__

#include "jklib/Descriptor/IWritable.h"
#include <corecrt_memory.h>

namespace JkLib
{
    namespace Util
    {
        class Buffer
            : public Descriptor::IWritable
        {
        public:
            Buffer()
                : managed(true)
                , buffer(nullptr)
                , bufferSize(0)
                , bufferUsed(0)
            {
            }

            Buffer(const Buffer& rhs, bool copy)
                : bufferSize(rhs.bufferSize)
                , bufferUsed(rhs.bufferUsed)
            {
                if (copy)
                {
                    managed = true;
                    buffer = new unsigned char[bufferSize];
                    memcpy_s(buffer, bufferSize, rhs.buffer, bufferSize);
                }
                else
                {
                    managed = false;
                    buffer = rhs.buffer;
                }
            }

            Buffer(const Buffer& rhs)
                : Buffer(rhs, true)
            {

            }

            ~Buffer()
            {
                if (!managed)
                    return;

                if (buffer != nullptr)
                {
                    delete[] buffer;
                    buffer = nullptr;
                }
            }

        public:
            virtual int Write(unsigned char* buffer, int offset, int writeSize) override
            {
                PrepareBuffer(writeSize);
                memcpy_s(this->buffer + bufferUsed, bufferSize - bufferUsed, buffer + offset, writeSize);
                bufferUsed += writeSize;

                return writeSize;
            }

        protected:
            void PrepareBuffer(int writeSize)
            {
                if (bufferSize - bufferUsed >= writeSize)
                    return;

                int newBufferSize = bufferSize;
                if (bufferSize == 0)
                    newBufferSize = 1;

                while (newBufferSize - bufferUsed <= writeSize)
                    newBufferSize *= 2;

                unsigned char* newBuffer = new unsigned char[newBufferSize];
                if (buffer != nullptr)
                {
                    memcpy_s(newBuffer, newBufferSize, buffer, bufferSize);
                    delete[] buffer;
                }

                buffer = newBuffer;
                bufferSize = newBufferSize;
            }

        private:
            unsigned char* buffer;
            int bufferSize;
            int bufferUsed;
            bool managed;
        };
    }
}

#endif //!__JKLIB_UTIL_BUFFER_H__
