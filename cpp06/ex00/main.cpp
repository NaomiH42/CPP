#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	std::string a(argv[1]);
	ScalarConverter::convert(a);
	// std::cout << INT_MAX << std::endl;
	// std::cout << __FLT_MAX__ << std::endl;
	// // std::cout << _LONG_MAX << std::endl;

}
