#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T> void incr(T &par)
{
	par++;
}

template <typename T>
void iter(T *arr, int len, void(*fun)(T&))
{
	for (int i = 0; i < len; i++)
		fun(arr[i]);
}

#endif
