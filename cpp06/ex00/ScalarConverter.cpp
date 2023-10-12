#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{}

ScalarConverter::~ScalarConverter()
{}

ScalarConverter::ScalarConverter(const ScalarConverter& o)
{
	(void)o;
}

ScalarConverter&
ScalarConverter::operator=(const ScalarConverter& rhs)
{
	(void)rhs;
	return (*this);
}

void
ScalarConverter::toChar(std::string input)
{
	char c;
	const char *str;
	str = input.c_str();
	c = str[0];
	if (c < 32 || c > 126)
		std::cout << "char: unprintable" << std::endl;
	else
		std::cout << "char: " << c << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void
ScalarConverter::toInt(std::string input)
{
	int i;
	std::stringstream ss(input);
	ss >> i;
	std::stringstream test;
	std::string t;
	test << i;
	test >> t;
	std::cout << std::fixed << std::setprecision(1);
	if (t != input)
	{
		std::cout << "error\n";
		return;
	}
	if (i < 32 || i > 126)
		std::cout << "char: unprintable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(i) << std::endl;
	std::cout << "int: " << i << std::endl;
	if (i > 9999999 || i < -9999999)
		std::cout <<"float: overflow or float weirdery" << std::endl;
	else
		std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(i) << std::endl;
}

void
ScalarConverter::toFloat(std::string input)
{
	float f;
	std::string t;
	std::stringstream ss(input);
	ss >> f;
	std::stringstream test;
	test << std::fixed  << std::setprecision(1) << f;
	test >> t;
	if (t + 'f' != input)
	{
		std::cout << "error (float is weird :))\n";
		return;
	}
	std::cout << std::setprecision(1) << std::fixed;
	if (f < 32 || f > 126)
		std::cout << "char: unprintable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(f) << std::endl;
	if (f > INT_MAX || f < INT_MIN)
		std::cout <<"int: overflow" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(f) << std::endl;
	std::cout <<"float: " << f << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(f) << std::endl;
}

void
ScalarConverter::toDouble(std::string input)
{

	double d;
	std::string t;
	std::stringstream ss(input);
	ss >> d;
	std::stringstream test;
	test << std::fixed  << std::setprecision(1) << d;
	test >> t;
	if (t != input)
	{
		std::cout << "error\n";
		return;
	}
	std::cout << std::setprecision(1) <<  std::fixed;
	if (d < 32 || d > 126)
		std::cout << "char: unprintable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(d) << std::endl;
	if (d > INT_MAX || d < INT_MIN)
		std::cout <<"int: overflow" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	if (d > 9999999 || d < -9999999)
		std::cout <<"float: overflow or float weirdery" << std::endl;
	else
		std::cout <<"float: " << static_cast<float>(d) << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

int
ScalarConverter::doBsNan(std::string input)
{
	(void)input;
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout <<"float: nanf" << std::endl;
	std::cout << "double: nan"<< std::endl;
	return (1);
}

int
ScalarConverter::doBsInf(std::string input)
{
	char s;
	if (input.find("-") != std::string::npos)
		s = '-';
	else
		s = '+';
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout <<"float: " << s << "inff" << std::endl;
	std::cout << "double: "<< s << "inf" << std::endl;
	return (1);
}

int
ScalarConverter::bsCheck(std::string input)
{
	if ("nan" == input || input == "nanf"
		|| "-nan" == input || input == "-nanf"
		|| "+nan" == input || input == "+nanf")
		return (doBsNan(input));
	else if (input == "inf" || input == "inff"
			|| input == "-inf" || input == "-inff"
			|| input == "+inf" || input == "+inff")
		return (doBsInf(input));
	return (0);
}

void
ScalarConverter::convert(std::string input)
{
	if (input.length() == 1 && !(input[0] > '0' && input[0] < '9'))
		toChar(input);
	else if (bsCheck(input))
		return ;
	else if (input.find(".") != std::string::npos)
	{
		if (input.find("f") != std::string::npos)
			toFloat(input);
		else
			toDouble(input);
	}
	else
		toInt(input);
}

void
ScalarConverter::decideType()
{}


