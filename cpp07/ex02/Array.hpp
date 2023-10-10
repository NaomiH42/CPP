#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <exception>
#include <stdlib.h>

template <class T>
class Array
{
	private:
		unsigned int _size;
		T* arr;

	public:
		Array();
		~Array();
		Array(unsigned int n);
		Array(const Array &o);
		Array &operator=(const Array &o);
		unsigned int size() const;
		T& operator[](int i);

	class OutOfBounds : public std::exception
	{
		virtual const char *what() const throw();
	};
};

#include "Array.tpp"


#endif
