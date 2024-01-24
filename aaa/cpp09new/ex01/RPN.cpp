#include "RPN.hpp"

RPN::RPN(std::string input)
{
	if (check(input))
	{
		try
		{
			std::cout << seperate(input);
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	else
		std::cout << "Incorrect input\n";
}
RPN::~RPN()
{}

RPN::RPN(const RPN& o)
{
	this->_stack = o._stack;
}

RPN&RPN::operator=(const RPN& o)
{
	if (this != &o)
		this->_stack = o._stack;
	return *this;
}

bool	RPN::check(std::string input)
{
	int check = 0;
	std::stringstream ss(input);
	std::string word;
	while (ss >> word)
	{
		if (word.length() != 1)
			return (false);
		if (word.find_first_not_of("0123456789+-*/") != std::string::npos)
		{
			std::cout << word << "\n";
			return(false);
		}
		if (word.find_first_not_of("0123456789") == std::string::npos)
			check++;
		else if (word.find_first_not_of("+-*/") == std::string::npos)
			check--;
	}
	if (check != 1)
		return (false);
	return (true);
}

int	RPN::seperate(std::string input)
{
	int first;
	int second;
	std::stringstream ss(input);
	std::string word;
	while (ss >> word)
	{
		if (word.find_first_not_of("0123456789-+*/") != std::string::npos)
			std::cout << "incorrect val\n";
		else if (word.find_first_not_of("*+-/") == std::string::npos)
		{
			if (_stack.size() < 2)
				throw BadOrderException();
			first = strToInt(_stack.top());
			_stack.pop();
			second = strToInt(_stack.top());
			_stack.pop();
			first = doOper(second, first, word);
			_stack.push(intToStr(first));
		}
		else if (word.find_first_not_of("0123456789") == std::string::npos)
			_stack.push(word);
	}
	return (strToInt(_stack.top()));

}

const char *RPN::BadOrderException::what() const throw()
{
	return ("Bad order of... things.\n");
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

std::string intToStr(int i)
{
	std::ostringstream stri;
	stri << i;
	return(stri.str());
}

int strToInt(std::string str)
{
	int result;
	std::stringstream ss(str);
	ss >> result;
	return (result);
}
