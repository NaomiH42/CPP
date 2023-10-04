#ifndef INTERN_HPP
# define INTERN_HPP

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class AForm;

class Intern
{
	public:
		Intern();
		~Intern();
		Intern(const Intern &o);
		Intern &operator=(const Intern &rhs);
		AForm *makeForm(std::string type, std::string target);

	private:
		static const char* _types[3];
		AForm *Robotomy(std::string target);
		AForm *Shrubbery(std::string target);
		AForm *Pardon(std::string target);
};

#endif
