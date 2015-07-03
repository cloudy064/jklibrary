#pragma once

#ifndef __JKLIB_TYPE_TRAIT_H__
#define __JKLIB_TYPE_TRAIT_H__

//////////////////////////////////////////////////////////////////////////
// Accept
typedef struct TrueType {} TrueType;
typedef struct FalseType {} FalseType;

template <typename TrueOrFalse, typename T>
struct AcceptType
{

};

template <typename T>
struct AcceptType<TrueType, T>
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

template <typename TrueOrFalse, typename T, typename U>
struct OptionType
{
	typedef T Type;
};

template <typename T, typename U>
struct OptionType<TrueType, T, U>
{
	typedef U Type;
};

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

template <typename T>
struct IsConst
{
	typedef FalseType Result;
};

template <typename T>
struct IsConst<const T>
{
	typedef TrueType Result;
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
