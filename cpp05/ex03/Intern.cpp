#include "Intern.hpp"

const char* Intern::_types[3] = {"shrubbery request", "robotomy request", "pardon request"};

Intern::Intern(){}

Intern::~Intern(){}

Intern::Intern(const Intern &o)
{(void)o;}

Intern &Intern::operator=(const Intern &rhs)
{
	(void)rhs;
	return (*this);
}

AForm *Intern::Robotomy(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm *Intern::Shrubbery(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::Pardon(std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(std::string type, std::string target)
{
	int i;

	for (i = 0; i < 3 && _types[i] != type; i++)
		;
	switch(i)
	{
		case 0:
			return (Shrubbery(target));
		case 1:
			return (Robotomy(target));
		case 2:
			return (Pardon(target));
		case 3:
			std::cout << "Invalid form name." << std::endl;
	}
	return (NULL);
}
