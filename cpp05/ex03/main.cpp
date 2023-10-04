#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	Bureaucrat testB("Naomi", 6);
	Intern Naomi;
	AForm *test;
	test = Naomi.makeForm("robotomy request", "Bender");
	try
	{
		testB.signForm(*test);
		testB.executeForm(*test);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

}
