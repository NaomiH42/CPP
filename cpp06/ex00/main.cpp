#include "ScalarConverter.hpp"

int main(void)
{
	std::string a("11.0f");
	ScalarConverter::convert(a);
	std::cout << INT_MAX << std::endl;
	std::cout << __FLT_MAX__ << std::endl;
	// std::cout << _LONG_MAX << std::endl;

}
