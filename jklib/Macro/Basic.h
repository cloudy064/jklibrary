#ifndef __JKLIB_BASIC_H__
#define __JKLIB_BASIC_H__

#define __MACRO_NUM_QUERY__(\
    _1, _2, _3, _4, _5, _6, _7, _8, _9, _10,\
    _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, ...) N

#define __MACRO_NUM_N__()\
    20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0

#define __NUM_OF_MACROS__(...)\
    __MACRO_NUM_QUERY__(__VA_ARGS__, __MACRO_NUM_N__())

#define NUM_OF_MACROS(...)

#endif //!__JKLIB_BASIC_H__
