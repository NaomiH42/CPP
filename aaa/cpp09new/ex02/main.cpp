#include "PmergeMe.hpp"
#include <sys/time.h>

int main(int argc, char **argv)
{
	if (argc == 1)
		return (0);
	int i = 1;
	while (argv[i])
	{
		int l = 0;
		while (argv[i][l])
		{
			if (!isdigit(argv[i][l]))
			{
				std::cout << "incorrect input\n";
				return (0);
			}
			l++;
		}
		i++;
	}
	// struct timeval timeb, timea;
	// gettimeofday(&timeb, NULL);
	// std::vector<std::pair<int, int> > first;
	PmergeMe test(argv);
	// first = test.get();
	// gettimeofday(&timea, NULL);
	// std::cout << "Before: ";
	// for (int i = 1; argv[i]; i++)
	// 	std::cout << argv[i] << " ";
	// std::cout << "\nAfter: ";
	// for (std::vector<std::pair<int, int> >::iterator it = first.begin(); it != first.end(); it++)
	// 	std::cout << it->first << " ";
	// std::cout << "\nTime to process a range of " << first.size() << " elements with std::vector<pair> :";
	// std::cout << timea.tv_usec - timeb.tv_usec << "\n";
}
