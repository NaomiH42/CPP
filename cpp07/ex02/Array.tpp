#include "Array.hpp"

template <typename T>
Array<T>::Array()
{
	arr = new T[];
	_size = 0;
}

template <typename T>
Array<T>::~Array()
{
	delete[] arr;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	arr = new T[n];
	_size = n;
}

template <typename T>
Array<T>::Array(const Array<T>& o)
{
	unsigned int n = o.size();
	arr = new T[n];
	for (unsigned int i = 0; i < n; i++)
		arr[i] = o.arr[i];
	_size = n;
}

template <typename T>
Array<T>&
Array<T>::operator=(const Array& o)
{
	if (this != *o)
	{
		unsigned int n = o.size();
		arr = new T[n];
		for (int i = 0; i < n; i++)
			arr[i] = o[i];
		_size = n;
	}
	return (*this);
}

template <typename T>
unsigned int
Array<T>::size() const
{
	return _size;
}

template <typename T>
T&
Array<T>::operator[](int i)
{
	if (i < 0 || i > (int)_size - 1)
		throw OutOfBounds();
	return arr[i];
}

template <typename T>
const char*
Array<T>::OutOfBounds::what() const throw()
{
	return ("Out of scope.");
}
