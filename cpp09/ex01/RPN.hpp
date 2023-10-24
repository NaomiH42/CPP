#ifndef RPN_HPP
# define RPN_HPP

#include <stack>
#include <sstream>
#include <list>
#include <string.h>
#include <iostream>
#include <sstream>
#include <exception>

class RPN
{
	public:
		RPN(std::string);
		~RPN();
		RPN(const RPN& o);
		RPN&operator=(const RPN& o);
		int	seperate(std::string);
		bool	check(std::string);
		int 	doOper(int res, int num, std::string symbol);

	private:
		std::stack<std::string, std::list<std::string> > _stack;
		std::stack<std::string, std::list<std::string> > _operators;

	class BadOrderException : public std::exception
	{
		virtual const char *what() const throw();
	};

};

int strToInt(std::string str);
std::string intToStr(int i);

#endif
