#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name(""), _grade(150)
{
}


Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
	_grade = grade;
}

Bureaucrat::~Bureaucrat(void)
{
}
Bureaucrat::Bureaucrat(const Bureaucrat &o) : _name(o.getName()), _grade(o.getGrade())
{

}
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs)
{
	if (this != &rhs)
		_grade = rhs.getGrade();
	return (*this);
}
std::string Bureaucrat::getName() const
{
	return (_name);
}
int	Bureaucrat::getGrade() const
{
	return (_grade);
}
void		Bureaucrat::increaseGrade()
{
	if (_grade - 1 < 1)
		throw GradeTooHighException();
	_grade -= 1;
}
void		Bureaucrat::decreaseGrade()
{
	if (_grade + 1 > 150)
		throw GradeTooLowException();
	_grade += 1;
}

void Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		std::cout << getName() << " tried executing " << form.getName() << std::endl;
		form.execute(*this);
	}
	catch(std::exception &e)
	{
		std::cout << getName() << " failed to execute " << form.getName()
		<< " " << e.what() << std::endl;
	}
}

void Bureaucrat::signForm(AForm &f)
{
	try
	{
		std::cout << getName() << " tried signing " << f.getName() << std::endl;
		f.beSigned(*this);
	}
	catch(const std::exception& e)
	{
		std::cout << getName() << " couldn't sign form "
		<< f.getName() <<  e.what() << std::endl;
	}
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high.\n");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low.\n");
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &b)
{
	out << b.getName();
	out << ", bureaucrat grade ";
	out << b.getGrade();
	return (out);
}
