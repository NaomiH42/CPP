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
			return (false);
		if (flag)
		{
			if (next.find_first_not_of("0123456789") != std::string::npos)
			{	std::cout << cpy.top() << flag;
				return(false);
			}
			else
				flag--;
		}
		else if (!flag)
		{
			if (next.find_first_not_of("+-*/") != std::string::npos)
				return(false);
			else
				flag++;
		}
		std::cout << flag << "\n";
		i++;
		cpy.pop();
	}
	if (flag != 1 || i < 3)
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

int	RPN::doOper(int res, int num, std::string symbol)
{
	if (symbol[0] == '+')
		return (res + num);
	else if (symbol[0] == '-')
		return (res - num);
	else if (symbol[0] == '*')
		return (res * num);
	else if (symbol[0] == '/')
		return (res / num);
	return (res);
}


int	RPN::calculate()
{
	int res;
	int num;
	std::stringstream ss(_stack.top());
	ss >> res;
	_stack.pop();
	while(!_stack.empty())
	{
		std::stringstream ss(_stack.top());
		ss >> num;
		_stack.pop();
		res = doOper(res, num, _stack.top());
		_stack.pop();
	}
	return (res);
}
