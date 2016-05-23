#ifndef __JKLIB_PATTERN_SINGLETON_H__
#define __JKLIB_PATTERN_SINGLETON_H__

namespace JkLib
{
    namespace Pattern
    {

        template <typename ObjectType, typename LockType>
        class Singleton
        {
        private:
            Singleton()
                : objectImpl(nullptr)
            {

            }

            Singleton(const Singleton&)
            {

            }

            virtual ~Singleton()
            {

            }

        public:
            static ObjectType* GetInstance()
            {
                if (objectImpl == nullptr)
                {
                    lock.Lock();
                    if (objectImpl == nullptr)
                    {
                        objectImpl = new ObjectType();
                    }
                    lock.Unlock();
                }

                return objectImpl;
            }

        private:
            static LockType lock;
            static ObjectType* objectImpl;
        };

        template <typename ObjectType, typename>
        ObjectType* Singleton::objectImpl = nullptr;

        template <typename, typename LockType>
        LockType Singleton::lock;

#define JKLIB_SINGLETON_DECLARE(classname)\
    private:\
        classname& operator=(const classname& rhs) {return (*this)};\
        classname(const classname&){}\
        classname()

    }
}

#endif // !__JKLIB_PATTERN_SINGLETON_H__