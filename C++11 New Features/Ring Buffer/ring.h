#ifndef RING_H
#define RING_H

#include <iostream>

template<class T>
class ring
{
public:
	class iterator;

	ring(int size)
		: m_size(size)
		, m_pos(0)
		, m_values(new T[size])
	{}

	~ring()
	{
		delete [] m_values;
	}

	int size() { return m_size; }

	iterator begin()
	{
		return iterator(0, *this);
	}

	iterator end()
	{
		return iterator(m_size, *this);
	}

	void add(T value)
	{
		m_values[m_pos++] = value;

		if (m_pos == m_size)
		{
			m_pos = 0;
		}
	}

	T& get(int pos)
	{
		return m_values[pos];
	}

private:
	int m_size;
	int m_pos;
	T* m_values;
};

template<class T>
class ring<T>::iterator
{
public:
	iterator(int pos, ring& r)
		: m_pos(pos)
		, m_ring(r)
	{}

	T& operator*()
	{
		return m_ring.get(m_pos);
	}

	bool operator!=(const iterator& other) const 
	{
		return m_pos != other.m_pos;
	}

	iterator& operator++()
	{
		m_pos++;
		return *this;
	}

	iterator& operator++(int)
	{
		m_pos++;
		return *this;
	}

private:
	int m_pos;
	ring& m_ring;
};


#endif RING_H
