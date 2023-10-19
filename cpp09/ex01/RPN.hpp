#ifndef RPN_HPP
# define RPN_HPP

#include <stack>
#include <sstream>
#include <list>
#include <string.h>
#include <iostream>
#include <sstream>

class RPN
{
	public:
		RPN(std::string);
		~RPN();
		RPN(const RPN& o);
		RPN&operator=(const RPN& o);
		void	seperate(std::string);
		bool	check();
		int		calculate();
		int 	doOper(int res, int num, std::string symbol);

	private:
		std::stack<std::string, std::list<std::string> > _stack;

};

#endif
