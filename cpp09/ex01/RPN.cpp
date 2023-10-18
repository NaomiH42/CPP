#include "RPN.hpp"

RPN::RPN(std::string input)
{seperate(input);};
RPN::~RPN(){};
RPN::RPN(const RPN& o){(void)o;}
RPN&RPN::operator=(const RPN& o){(void)o; return *this;}

bool	RPN::check()
{
	int flag = 2;
	int i = 0;
	std::stack<std::string, std::list<std::string> > cpy = _stack;
	while (!cpy.empty())
	{
		std::string next = cpy.top();
		if (next.length() != 1)
			std::cout << "a";
			return (false);
		if (flag)
		{
			if (next.find_first_not_of("0123456789") != std::string::npos)
				return(false);
			else
				flag--;
		}
		if (!flag)
		{
			if (next.find_first_not_of("+-*/") != std::string::npos)
			return(false);
			else
				flag++;
		}
		i++;
		cpy.pop();
	}
	if (i < 3)
		return (false);
	return (true);
}

void	RPN::seperate(std::string input)
{
	std::stringstream ss(input);
	std::string word;
	while (ss >> word)
		_stack.push(word);
}

int	RPN::calculate()
{
	int first;
	int second;
	std::stringstream ss(_stack.top());
	ss >> first;
	_stack.pop();
	std::stringstream ss(_stack.top());
	ss >> second;
	_stack.pop();
	doOper(first, second, _stack.top());
	_stack.pop();
	while(!_stack.empty())
	{
		std::stringstream ss(_stack.top());
		ss >> second;
		_stack.pop();
	}
}
