#include "PmergeMe.hpp"

PmergeMe::PmergeMe(char** input)
{
	struct timeval timeb, timea;
	gettimeofday(&timeb, NULL);
	putIn(input);
	sortPairs();
	sortFakeRecursive(0);
	sortB();
	gettimeofday(&timea, NULL);
	std::cout << "Before: ";
	for (int i = 1; input[i]; i++)
		std::cout << input[i] << " ";
	std::cout << "\nAfter: ";
	for (std::vector<std::pair<int, int> >::iterator it = _set.begin(); it != _set.end(); it++)
		std::cout << it->first << " ";
	std::cout << "\nTime to process a range of " << _set.size() << " elements with std::vector<pair>: ";
	std::cout << timea.tv_usec - timeb.tv_usec << "\n";
	gettimeofday(&timeb, NULL);
	gettimeofday(&timeb, NULL);
	putInLst(input);
	sortPairsLst();
	sortRecurLst(0);
	putInA();
	gettimeofday(&timea, NULL);
	std::cout << "Time to process a range of " << _set.size() << " elements with std::list: ";
	std::cout << timea.tv_usec - timeb.tv_usec << "\n";
}

std::vector<std::pair<int, int> > PmergeMe::get()
{
	return (_set);
}

PmergeMe::~PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe& o)
{
	this->_set = o._set;
	this->_listA = o._listA;
	this->_listB = o._listB;
}

PmergeMe&PmergeMe::operator=(const PmergeMe& o)
{
	if (this != &o)
	{
		this->_set = o._set;
		this->_listA = o._listA;
		this->_listB = o._listB;
	}
	return *this;
}

void PmergeMe::sortFakeRecursive(int i)
{
	std::vector<std::pair<int, int> >::iterator it = _set.begin();
	for (int l = 0; l < i && it != _set.end(); l++)
		it++;
	if (it == _set.end())
		return ;
	std::vector<std::pair<int, int> >::iterator itA = it;
	itA++;
	if (itA != _set.end() && it->first < itA->first)
	{
		int temp = it->first;
		int tempB = it->second;
		it->first = itA->first;
		it->second = itA->second;
		itA->first = temp;
		itA->second = tempB;
		sortFakeRecursive(0);
	}
	else if (it != _set.end())
		sortFakeRecursive(i + 1);
}

void PmergeMe::	sortRecurLst(int i)
{
	std::list<int>::iterator itA = _listA.begin();
	std::list<int>::iterator itB = _listB.begin();
	for (int l = 0; l < i; l++)
	{
		itA++;
		itB++;
	}
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
		sortRecurLst(0);
	}
	else if (itA2 != _listA.end())
	{
		sortRecurLst(i + 1);
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
	if (_size % 2 == 0)
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
	int i = 0;
	int num = 0;

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
