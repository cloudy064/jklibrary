#pragma once

#ifndef __JKLIB_COLLECTION_H__
#define __JKLIB_COLLECTION_H__

template <typename T>
class IEnumerator;

template <typename T>
class ICollection
{
public:
	typedef T ElementType;

public:
	virtual ~ICollection() {}

public:
	virtual IEnumerator<ElementType>* CreateEnumerator() = 0;
	virtual IEnumerator<const ElementType>* CreateEnumerator() const = 0;
	virtual void ReleaseEnumerator(IEnumerator<ElementType>*&) const = 0;
	virtual unsigned int GetNumOfElements() const = 0;
};

#endif //!__JKLIB_COLLECTION_H__
