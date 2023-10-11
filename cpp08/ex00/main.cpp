#include "easyfind.hpp"

int	main(void)
{
	int ints[] = {54, 2, 69, 1};
	std::vector<int> v(ints, ints + sizeof(ints) / sizeof(int));
	::easyfind(v, 69);
	::easyfind(v, 32);

}
