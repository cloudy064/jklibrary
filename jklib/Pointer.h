#pragma once

#ifndef __JKLIB_POINTER_H__
#define __JKLIB_POINTER_H__

#include "basic.h"

template <typename T>
class Pointer
	: public JkLib::Basic::Object
{
	template <typename U>
	friend class Pointer;

public:
	Pointer()
		: _pointer(nullptr)
	{

	}

	template <typename U>
	explicit Pointer(U* pointer)
		: _pointer(static_cast<T*>(pointer))
	{

	}

	explicit Pointer(const Pointer<T>& obj)
		: _pointer(obj._pointer)
	{

	}

	explicit Pointer(Pointer<T>&& obj)
		: _pointer(obj._pointer)
	{

	}

	template <typename U>
	explicit Pointer(const Pointer<U>& obj)
		: Pointer<U>(obj._pointer)
	{

	}

	template <typename U>
	explicit Pointer(Pointer<U>&& obj)
		: Pointer<U>(obj._pointer)
	{

	}

	~Pointer()
	{

	}

public:
	template <typename U>
	void Wrap(U* pointer)
	{
		_pointer = static_cast<T*>(pointer);
	}

	void Release()
	{
		_pointer = nullptr;
	}

	T* GetPointer()
	{
		return _pointer;
	}

	void Swap(T*& pointer)
	{
		T* ptr = MoveValue(pointer._pointer);
		pointer._pointer = MoveValue(_pointer);
		_pointer = MoveValue(ptr);
	}

	void Swap(Pointer<T>& pointer)
	{
		T* ptr = MoveValue(pointer._pointer);
		pointer._pointer = MoveValue(_pointer);
		_pointer = MoveValue(ptr);
	}

	void Swap(Pointer<T>&& pointer)
	{
		T* ptr = MoveValue(pointer._pointer);
		pointer._pointer = MoveValue(_pointer);
		_pointer = MoveValue(ptr);
	}

	template <typename U>
	Pointer<U> Cast() const
	{
		return Pointer<U>(_pointer);
	}

	bool IsValid() const
	{
		return (_pointer != nullptr);
	}

	bool IsNull() const
	{
		return (_pointer == nullptr);
	}

public:
	T* operator->() const
	{
		return _pointer;
	}

	T& operator*() const
	{
		return (*_pointer);
	}

	template <typename U>
	Pointer<T>& operator=(U* pointer)
	{
		_pointer = static_cast<U*>(pointer);
		return (*this);
	}

	Pointer<T>& operator=(const Pointer<T>& obj)
	{
		if (this == &obj)
			return (*this);

		_pointer = obj._pointer;
		return (*this);
	}

	Pointer<T>& operator=(Pointer<T>&& obj)
	{
		if (this == &obj)
			return (*this);

		_pointer = obj._pointer;
		return (*this);
	}

	template <typename U>
	Pointer<T>& operator=(const Pointer<U>& obj)
	{
		_pointer = static_cast<T*>(obj._pointer);
		return (*this);
	}

	template <typename U>
	Pointer<T>& operator=(Pointer<U>& obj)
	{
		_pointer = static_cast<T*>(obj._pointer);
		return (*this);
	}

	bool operator==(const Pointer<T>& obj) const
	{
		return (_pointer == obj._pointer);
	}

	bool operator==(Pointer<T>&& obj) const
	{
		return (_pointer == obj._pointer);
	}

	template <typename U>
	bool operator==(const Pointer<U>& obj) const
	{
		return false;
	}

	template <typename U>
	bool operator==(Pointer<U>&& obj) const
	{
		return false;
	}

	bool operator!=(const Pointer<T>& obj) const
	{
		return (_pointer != obj._pointer);
	}

	bool operator!=(Pointer<T>&& obj) const
	{
		return (_pointer != obj._pointer);
	}

	template <typename U>
	bool operator!=(const Pointer<U>& obj) const
	{
		return true;
	}

	template <typename U>
	bool operator!=(Pointer<U>&& obj) const
	{
		return true;
	}

	template <typename U>
	explicit operator U()
	{
		return U(_pointer);
	}

private:
	T* _pointer;
};

#endif //!__JKLIB_POINTER_H__
