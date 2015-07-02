#pragma once

#ifndef __JKLIB_COMMON_H__
#define __JKLIB_COMMON_H__

#define JKLIB_NS_BEGIN	namespace JkLib {
#define JKLIB_NS_END	}

#define JKLIB_MODULE_BEGIN(name)	namespace JkLib { namespace name {
#define JKLIB_MODULE_END(name)		} }


#define USING_MODULE(name) using namespace JkLib::name;

#endif //!__JKLIB_COMMON_H__
