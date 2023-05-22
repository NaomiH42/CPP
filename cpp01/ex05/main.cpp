#include "Harl.hpp"

int	main( void )
{
	std::string error = "error";
	std::string info = "info";
	std::string debug = "debug";
	std::string warning = "warning";
	Harl karl;
	karl.complain(error);
	karl.complain(info);
	karl.complain(debug);
	karl.complain(warning);
}
