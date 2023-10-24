#include "PmergeMe.hpp"

PmergeMe::PmergeMe(char** input)
{
	struct timeval timeb, timea;
	gettimeofday(&timeb, NULL);
	putIn(input);
	sortPairs();
	sortFakeRecursive();
	sortB();
	gettimeofday(&timea, NULL);
	// std::cout << "Before: ";
	// for (int i = 1; input[i]; i++)
	// 	std::cout << input[i] << " ";
	// std::cout << "\nAfter: ";
	// for (std::vector<std::pair<int, int> >::iterator it = _set.begin(); it != _set.end(); it++)
	// 	std::cout << it->first << " ";
	// std::cout << "\nTime to process a range of " << _set.size() << " elements with std::vector<pair> :";
	// std::cout << timea.tv_usec - timeb.tv_usec << "\n";
	// gettimeofday(&timeb, NULL);
	putInLst(input);
	sortPairsLst();
	sortRecurLst();
	putInA();
	for (std::list<int>::iterator it = _listA.begin(); it != _listA.end(); it++)
		std::cout << *it << "\n";
}

std::vector<std::pair<int, int> > PmergeMe::get()
{
	return (_set);
}

PmergeMe::~PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe& o)
{
	(void)o;
}

PmergeMe&PmergeMe::operator=(const PmergeMe& o)
{
	(void)o;
	return *this;
}

void PmergeMe::	sortRecurLst()
{
	std::list<int>::iterator itA = _listA.begin();
	std::list<int>::iterator itB = _listB.begin();
	while (itA != _listA.end())
	{

		std::list<int>::iterator itA2 = itA;
		std::list<int>::iterator itB2 = itB;
		itB2++;
		itA2++;
		if (*itA < *itA2 && itA2 != _listA.end())
		{
			int temp = *itA2;
			int tempB = *itB2;
			*itA2 = *itA;
			*itB2 = *itB;
			*itA = temp;
			*itB = tempB;
			itA = _listA.begin();
			itB = _listB.begin();

		}
		else
		{
			itA++;
			itB++;
		}
	}
}

bool PmergeMe::isSorted()
{
	for (std::vector<std::pair<int, int> >::iterator it = _set.begin(); it != _set.end(); it++)
	{
		if (it->second != -1)
			return (false);
	}
	return (true);
}

std::list<int>::iterator	PmergeMe::findPosLst(int num)
{
	for (std::list<int>::iterator it = _listA.begin(); it != _listA.end(); it++)
	{
		if (*it <= num)
			return (it);
	}
	return (_listA.end());
}

void PmergeMe::putInA()
{
	for (std::list<int>::iterator it = _listB.begin(); it != _listB.end(); it++)
	{
		_listA.insert(findPosLst(*it), *it);
	}
	_listA.pop_back();
}

int	PmergeMe::findPos(int num)
{
	int i = 0;
	for (std::vector<std::pair<int, int> >::iterator it = _set.begin(); it != _set.end(); it++)
	{
		if (it->first <= num)
			break;
		i++;
	}
	return (i);
}

void PmergeMe::sortB()
{
	int i;
	int num;

	for (std::vector<std::pair<int, int> >::iterator it = _set.begin(); it != _set.end(); it++)
	{
		if (it->second != -1)
		{
			i = findPos(it->second);
			num = it->second;
			it->second = -1;
			break;
		}
	}
	_set.insert(_set.begin() + i, std::make_pair(num, -1));
	if (!isSorted())
		sortB();
	else if (_size % 2 == 0)
		_set.pop_back();

}

void PmergeMe::sortFakeRecursive()
{
	std::sort(_set.begin(), _set.end(), std::greater<std::pair<int, int> >());
}

void PmergeMe::sortPairs()
{
	for (std::vector<std::pair<int, int> >::iterator it = _set.begin(); it != _set.end(); it++)
	{
		if (it->first < it->second && it->first != -1)
		{
			int temp = it->first;
			it->first = it->second;
			it->second = temp;
		}
	}
}

void PmergeMe::putIn(char **input)
{
	int i = 1;
	while (input[i])
	{
		std::string number = input[i];
		if (input[i+1])
		{
			std::string number2 = input[i + 1];
			_set.push_back(std::make_pair(strToInt(number), strToInt(number2)));
			i += 2;
		}
		else
		{
			_set.push_back(std::make_pair(-1, strToInt(number)));
			i++;
		}
	}
	_size = i;
}


void PmergeMe::sortPairsLst()
{
	std::list<int>::iterator itA = _listA.begin();
	std::list<int>::iterator itB = _listB.begin();
	while (itA != _listA.end())
	{
		if (*itA < *itB && *itA != -1)
		{
			int temp = *itA;
			*itA = *itB;
			*itB = temp;
		}
		itA++;
		itB++;
	}
}

void PmergeMe::putInLst(char **input)
{
	int i = 1;
	while (input[i])
	{
		std::string number = input[i];
		if (input[i+1])
		{
			std::string number2 = input[i + 1];
			_listA.insert(_listA.begin(), strToInt(number));
			_listB.insert(_listB.begin(), strToInt(number2));
			i += 2;
		}
		else
		{
			_listB.insert(_listB.begin(), strToInt(number));
			_listA.insert(_listA.begin(), -1);
			i++;
		}
	}
	_size = i;
}

int strToInt(std::string str)
{
	int result;
	std::stringstream ss(str);
	ss >> result;
	return (result);
}
