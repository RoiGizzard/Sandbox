#ifndef RING_H
#define RING_H

#include <iostream>

template<class T>
class ring
{
public:
	class iterator;
};

template<class T>
class ring<T>::iterator
{
public:
	void print();
};

template<class T>
void ring<T>::iterator::print()
{
	std::cout << "Iterator" << std::endl;
}

#endif RING_H
