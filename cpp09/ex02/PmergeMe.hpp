#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <bits/stdc++.h>
#include <set>
#include <map>
#include <algorithm>
#include <utility>
#include <sys/time.h>

class PmergeMe
{
	public:
		PmergeMe(char**);
		~PmergeMe();
		PmergeMe(const PmergeMe& o);
		PmergeMe&operator=(const PmergeMe& o);
		std::vector<std::pair<int, int> > get();

	private:
		std::vector<std::pair<int, int> > _set;
		std::list<int> _listA;
		std::list<int> _listB;
		void	putIn(char**);
		void	sortPairs();
		void	sortPairsLst();
		void	sortFakeRecursive(int i);
		void	sortB();
		bool	isSorted();
		void	putInLst(char **input);
		int		findPos(int);
		void	sortRecurLst(int i);
		std::list<int>::iterator	findPosLst(int num);
		void	putInA();

		int 	_size;
};

int strToInt(std::string str);

#endif
