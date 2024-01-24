#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <bits/stdc++.h>
#include <set>
#include <map>
#include <algorithm>
#include <utility>
#include <sys/time.h>

typedef struct Lists_s{
	std::list<int> list1;
	std::list<int> list2;
}	Lists;

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
		int		findPosMerge(std::vector<std::pair<int, int> > vec, int num);
		Lists mergeLists(Lists lsts1, Lists lsts2);
		std::vector<std::pair<int, int> >	sortFakeRecursive(std::vector<std::pair<int, int> > vec);
		std::vector<std::pair<int, int> >	mergeVectors(std::vector<std::pair<int, int> > vec1, std::vector<std::pair<int, int> > vec2);
		void	sortB();
		bool	isSorted();
		void	putInLst(char **input);
		int		findPos(int);
		Lists	sortRecurLst(Lists lsts);
		std::list<int>::iterator	findPosLst(int num);
		void	putInA();

		int 	_size;
};

int strToInt(std::string str);

#endif
