#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	Bureaucrat test1("Naomi", 1);
	Bureaucrat test2("Naomi2", 150);
	Bureaucrat test3("Naomi2", 5);
	Form testF("Form1", 5, 10);
	try
	{
		Form testF2("Form2", 0, 150);
	}
	catch (const std::exception &exc)
	{
		std::cout << exc.what() << std::endl;
	}
	try
	{
		testF.beSigned(test2);

	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		testF.beSigned(test3);

	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		testF.beSigned(test3);

	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << testF << std::endl;
}
