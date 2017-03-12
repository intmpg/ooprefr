#pragma once
#include "stdafx.h"
#include "MyArray.h"

template <typename T, bool isReverse>
class CMyIterator : public std::iterator<std::random_access_iterator_tag, T>
{
public:
	CMyIterator(const CMyIterator &it)
		:m_itemPtr(it.m_itemPtr)
	{
	}

	CMyIterator(T * itemPtr)
		:m_itemPtr(itemPtr)
	{
	}

	T operator *() const
	{
		return *m_itemPtr;
	}

	T & operator [](ptrdiff_t index)
	{
		return m_itemPtr[index];
	}

	const T & operator [](ptrdiff_t index) const
	{
		return m_itemPtr[index];
	}

	CMyIterator operator ++(int)
	{
		if (isReverse)
		{
			return{ m_itemPtr-- };
		}
		return{ m_itemPtr++ };
	}

	CMyIterator operator --(int)
	{
		if (isReverse)
		{
			return{ m_itemPtr++ };
		}
		return{ m_itemPtr-- };
	}

	T * operator ->()const
	{
		return itemPtr;
	}

	CMyIterator & operator ++()
	{
		if (isReverse)
		{
			return{ m_itemPtr-- };
		}
		return{ m_itemPtr++ };
	}

	CMyIterator & operator+=(ptrdiff_t numb)
	{
		m_itemPtr += (isReverse ? numb * (-1) : numb);
		return *this;
	}

	CMyIterator & operator-=(ptrdiff_t numb)
	{
		m_itemPtr -= (isReverse ? numb * (-1) : numb);
		return *this;
	}

	CMyIterator & operator --()
	{
		if (isReverse)
		{
			return{ m_itemPtr++ };
		}
		return{ m_itemPtr-- };
	}

	bool operator ==(CMyIterator const& it)
	{
		return (*m_itemPtr == *it);
	}

	bool operator !=(CMyIterator const& it)
	{
		return (*m_itemPtr != *it);
	}

private:
	T * m_itemPtr;
};