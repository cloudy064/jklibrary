#pragma once

#ifndef _JKLIB_SCOPE_POINTER_H__
#define _JKLIB_SCOPE_POINTER_H__

#include <assert.h>

#include "Basic.h"
#include "Pointer.h"

template <typename T>
class ScopePointer
	: public JkLib::Basic::Object
	, public JkLib::Basic::NoCopyable
{
	template <typename U>
	friend class ScopePointer;

public:
	ScopePointer()
	{

	}

	explicit ScopePointer(T* pointer)
		: _pointer(pointer)
	{

	}

	~ScopePointer()
	{
		Release();
	}

public:
	template <typename U>
	void Wrap(const U* pointer)
	{
		assert(_pointer.IsNull());
		_pointer.Wrap(pointer);
	}

	void Release()
	{
		if (_pointer.IsNull())
			return;

		T* ptr = _pointer.GetPointer();
		delete ptr;

		_pointer.Release();
	}

	bool IsValid() const
	{
		return (_pointer.IsValid());
	}

	bool IsNull() const
	{
		return (_pointer.IsNull());
	}

	void Swap(ScopePointer& pointer)
	{
		_pointer.Swap(pointer._pointer);
	}

	void Swap(ScopePointer&& pointer)
	{
		_pointer.Swap(pointer._pointer);
	}

public:
	T* operator->() const
	{
		return _pointer.operator->();
	}

	T& operator*() const
	{
		return _pointer->operator*();
	}

	template <typename U>
	ScopePointer<T>& operator=(const U* pointer)
	{
		assert(_pointer.IsNull());
		_pointer.Wrap(pointer);

		return (*this);
	}

	bool operator==(const ScopePointer<T>& obj) const
	{
		return (_pointer == obj._pointer);
	}

	bool operator==(ScopePointer<T>&& obj) const
	{
		return (_pointer == obj._pointer);
	}

	template <typename U>
	bool operator==(const ScopePointer<U>& obj) const
	{
		return false;
	}

	template <typename U>
	bool operator==(ScopePointer<U>&& obj) const
	{
		return false;
	}

	bool operator!=(const ScopePointer<T>& obj) const
	{
		return (_pointer != obj._pointer);
	}

	bool operator!=(ScopePointer<T>&& obj) const
	{
		return (_pointer != obj._pointer);
	}

	template <typename U>
	bool operator!=(const ScopePointer<U>& obj) const
	{
		return true;
	}

	template <typename U>
	bool operator!=(ScopePointer<U>&& obj) const
	{
		return true;
	}

protected:
	Pointer<T> _pointer;
};


#endif //!_JKLIB_SCOPE_POINTER_H__
