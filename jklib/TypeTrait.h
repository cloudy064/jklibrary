#pragma once

#ifndef __JKLIB_TYPE_TRAIT_H__
#define __JKLIB_TYPE_TRAIT_H__

//////////////////////////////////////////////////////////////////////////
// Reference
template <typename T>
struct RemoveReference
{
	typedef T Type;
};

template <typename T>
struct RemoveReference<T&>
{
	typedef T Type;
};

template <typename T>
struct RemoveReference<T&&>
{
	typedef T Type;
};

//////////////////////////////////////////////////////////////////////////
// const
template <typename T>
struct RemoveConst
{
	typedef T Type;
};

template <typename T>
struct RemoveConst<const T>
{
	typedef T Type;
};

//////////////////////////////////////////////////////////////////////////
// Volatile
template <typename T>
struct RemoveVolatile
{
	typedef T Type;
};

template <typename T>
struct RemoveVolatile<volatile T>
{
	typedef T Type;
};

//////////////////////////////////////////////////////////////////////////
// Pointer
template <typename T>
struct RemovePointer
{
	typedef T Type;
};

template <typename T>
struct RemovePointer<T*>
{
	typedef typename RemovePointer<T>::Type Type;
};


//////////////////////////////////////////////////////////////////////////
// Combine
template <typename T>
struct RemoveCV
{
	typedef T Type;
};

template <typename T>
struct RemoveCV<const T>
{
	typedef RemoveCV<T> Type;
};

template <typename T>
struct RemoveCV<volatile T>
{
	typedef RemoveCV<T> Type;
};


//////////////////////////////////////////////////////////////////////////
// Move
template <typename T>
typename RemoveReference<T>::Type&& MoveValue(T&& val)
{
	return static_cast<typename RemoveReference<T>::Type&&>(val);
}

template <typename T>
typename RemoveReference<T>::Type&& ForwardValue(T& val)
{
	return static_cast<RemoveReference<T>::Type&&>(val);
}

template <typename T>
typename RemoveReference<T>::Type&& ForwardValue(T&& val)
{
	return static_cast<RemoveReference<T>::Type&&>(val);
}

#endif //!__JKLIB_TYPE_TRAIT_H__
