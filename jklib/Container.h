#pragma once

#ifndef __JKLIB_CONTAINER_H__
#define __JKLIB_CONTAINER_H__

template <typename T>
class IContainer
{
public:
	virtual IEnumerator<T> Begin() = 0;
	virtual IEnumerator<T> End() = 0;
};

template <typename T>
class ISequenceContainer
	: public IContainer
{
public:
	virtual IEnumerator<T> Begin() = 0;
	virtual IEnumerator<T> End() = 0;
};

#endif //!__JKLIB_CONTAINER_H__

