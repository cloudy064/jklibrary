#pragma once

#ifndef __JKLIB_ARRAY_H__
#define __JKLIB_ARRAY_H__

#include "Basic.h"
#include "Collection.h"
#include "Enumerator.h"
#include "TypeTrait.h"
#include <initializer_list>

template <typename T, unsigned int size>
class Array
	: public JkLib::Basic::Object
	, virtual public ICollection<T>
{
public:
	typedef T ElementType;

public:

	template <
		typename ArrayType, 
		typename U = OptionType<typename IsConst<ArrayType>::Result, const typename ArrayType::ElementType, typename ArrayType::ElementType>
	>
	class ArrayEnumerator
		: public Object
		, virtual public IEnumerator<U>
	{
	public:
		explicit ArrayEnumerator(ArrayType& array)
			: _array(array)
			, _index(0)
		{
		}

		~ArrayEnumerator()
		{

		}

	public:
		virtual void Next() override
		{
			++_index;
		}

		virtual U& Reference() override
		{
			return _array.GetElementAt(_index);
		}

		virtual bool IsValid() const override
		{
			if (_index < 0)
				return false;

			if (_index >= size)
				return false;

			return true;
		}

		virtual void Reset() override
		{
			_index = 0;
		}

	protected:
		ArrayType& _array;
		int _index;
	};

	typedef ArrayEnumerator<Array<T, size>> Enumerator;
	typedef ArrayEnumerator<const Array<T, size>> ConstEnumerator;

public:
	Array()
	{

	}

	template <typename U>
	Array(std::initializer_list<U> list)
		: _numOfElements(0)
	{
		auto begin = list.begin();
		auto end = list.end();

		for (it = begin; it != end; ++it)
		{
			if (_numOfElements >= size)
				break;

			_array[_numOfElements] = static_cast<T>(*it);
			++_numOfElements;
		}
	}

	template <typename U>
	explicit Array(const U& defaultValue)
	{
		while (_numOfElements < size)
		{
			_array[_numOfElements] = static_cast<T>(defaultValue);
			++_numOfElements;
		}
	}

	template <typename U>
	Array(const U* begin, const U* end)
	{
		for (auto it = begin; it != end; ++it)
		{
			if (_numOfElements >= size)
				break;

			_array[_numOfElements] = static_cast<T>(*it);
			++_numOfElements;
		}
	}

	~Array()
	{

	}

public:
	virtual IEnumerator<const T>* CreateEnumerator() const override
	{
		return new ConstEnumerator(*this);
	}

	virtual IEnumerator<T>* CreateEnumerator() override
	{
		return new Enumerator(*this);
	}

	virtual void ReleaseEnumerator(IEnumerator<ElementType>*& enumerator) const override
	{
		if (enumerator != nullptr)
		{
			delete enumerator;
			enumerator = nullptr;
		}
	}

	virtual unsigned int GetNumOfElements() const override
	{
		return _numOfElements;
	}

	ElementType& GetElementAt(int index)
	{
		return _array[index];
	}

	const ElementType& GetElementAt(int index) const
	{
		return _array[index];
	}

private:
	T _array[size];
	unsigned int _numOfElements;
};

#endif //!__JKLIB_ARRAY_H__

