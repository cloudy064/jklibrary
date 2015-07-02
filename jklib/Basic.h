#pragma once

#ifndef __JKLIB_BASIC_H__
#define __JKLIB_BASIC_H__

#include "Common.h"
#include "TypeTrait.h"

JKLIB_MODULE_BEGIN(Basic)

class Object
{
public:
	virtual ~Object() {};
};

template <typename T>
class ValueSetListener
{
public:
	virtual void OnValueSetListener(T& val) = 0;
	virtual void OnValueSetListener(T&& val) = 0;
};

template <typename T>
class ObjectBox
	: public Object
{
public:
	ObjectBox(const T& val)
		: _val(val)
		, _beforeValueSetListener(nullptr)
		, _afterValueSetListener(nullptr)
	{

	}

	ObjectBox(T&& val)
		: _val(std::move(val))
	{

	}

	~ObjectBox()
	{

	}

public:
	void SetBeforeSetListner(const ValueSetListener* listner)
	{
		_beforeValueSetListener = listner;
	}

	void SetAfterSetListener(const ValueSetListener* listener)
	{
		_afterValueSetListener = listener;
	}

	void SetValue(const T& val)
	{
		_val = val;
	}

	void SetValue(T&& val)
	{
		if (_beforeValueSetListener != nullptr)
			_beforeValueSetListener->OnValueSetListener(val);

		_val = std::move(val);

		if (_afterValueSetListener != nullptr)
			_afterValueSetListener->OnValueSetListener(_val);
	}

	T GetValue()
	{
		return _val;
	}

	T& Release()
	{
		_beforeValueSetListener = nullptr;
		_afterValueSetListener = nullptr;
		return _val;
	}

private:
	T _val;
	ValueSetListener* _beforeValueSetListener;
	ValueSetListener* _afterValueSetListener;
};


class NoCopyable
{
public:
	NoCopyable()
	{

	}

	NoCopyable(const NoCopyable&) = delete;
	NoCopyable(NoCopyable&&) = delete;

	virtual ~NoCopyable()
	{

	}

public:
	NoCopyable& operator=(const NoCopyable&) = delete;
	NoCopyable& operator=(NoCopyable&&) = delete;
};

typedef struct TrueType {} TrueType;
typedef struct FalseType {} FalseType;

template <typename T, typename AcceptOrNot>
struct AcceptType
{

};

template <typename T>
struct AcceptType<T, TrueType>
{
	typedef T Type;
};

template <typename T>
struct AcceptValue
{
	static const bool accept = false;
};

template <>
struct AcceptValue<TrueType>
{
	static const bool accept = true;
};

JKLIB_MODULE_END(Basic)

#endif //!__JKLIB_BASIC_H__
