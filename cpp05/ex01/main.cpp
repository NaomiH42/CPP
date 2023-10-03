#include "Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat test1("Naomi", 1);
	try
	{
		Bureaucrat test2(test1);
		Bureaucrat test3;
		test3 = test1;
		Bureaucrat test4("Kipo", 0);
	}
	catch (const std::exception &exc)
	{
		std::cout << exc.what() << std::endl;
	}
	try
	{
		test1.increaseGrade();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		test1.decreaseGrade();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << test1 << std::endl;
}
