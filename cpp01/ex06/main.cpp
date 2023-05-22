#include "Harl.hpp"

int	main( void )
{
	std::string error = "error";
	std::string info = "info";
	std::string debug = "debug";
	std::string warning = "warning";
	Harl karl;
	karl.complain(debug);
	std::cout << std::endl;
	karl.complain(info);
	std::cout << std::endl;
	karl.complain(warning);
	std::cout << std::endl;
	karl.complain(error);
}
