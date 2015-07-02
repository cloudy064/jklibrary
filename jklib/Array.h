#pragma once

#ifndef __JKLIB_ARRAY_H__
#define __JKLIB_ARRAY_H__

template <typename T, unsigned int size>
class Array
	: public Object
{
public:
	Array()
	{

	}

	template <typename U>
	Array(initializer_list<U> list)
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
	explicit Array(U defaultValue)
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

private:
	T _array[size];
	unsigned int _numOfElements;
};

#endif //!__JKLIB_ARRAY_H__

