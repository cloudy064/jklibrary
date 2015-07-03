#pragma once

#ifndef __JKLIB_ENUMERABLE_H__
#define __JKLIB_ENUMERABLE_H__

template <typename T>
class IEnumerator;

template <typename T>
class Enumerable
{
public:
	typedef T ElementType;

public:
	virtual ~Enumerable() {}

public:
	virtual IEnumerator<ElementType>* CreateEnumerator() const = 0;
	virtual void ReleaseEnumerator(IEnumerator<ElementType>*&) const = 0;
	virtual unsigned int GetNumOfElements() const = 0;
};

#endif //!__JKLIB_ENUMERABLE_H__
