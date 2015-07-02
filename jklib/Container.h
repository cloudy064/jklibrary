#pragma once

#ifndef __JKLIB_CONTAINER_H__
#define __JKLIB_CONTAINER_H__

template <typename T>
class IContainer
{
public:
	IEnumerator<T> Begin();
	IEnumerator<T> End();
};

#endif //!__JKLIB_CONTAINER_H__

