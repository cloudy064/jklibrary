#pragma once

#ifndef __JKLIB_ENUMERATOR_H__
#define __JKLIB_ENUMERATOR_H__

template <typename T>
class IEnumerator
{
public:
	virtual ~IEnumerator() {}

public:
	virtual void Next() = 0;
	virtual T& Reference() = 0;
	virtual bool IsValid() const = 0;
	virtual void Reset() = 0;
};

#endif //!__JKLIB_ENUMERATOR_H__
