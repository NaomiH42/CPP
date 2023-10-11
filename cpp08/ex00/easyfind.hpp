#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <vector>
#include <algorithm>
#include <iostream>

template <typename T>
void easyfind(T cont, int i)
{
	if (std::find(cont.begin(), cont.end(), i) != cont.end())
		std::cout << "found" << std::endl;
	else
		std::cout << "not found" << std::endl;
}

#endif
