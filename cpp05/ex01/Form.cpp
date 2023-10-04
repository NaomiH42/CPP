#include "Form.hpp"

Form::Form(std::string name, int signGrade, int execGrade) :
_name(name), _signGrade(signGrade), _execGrade(execGrade)
{
	if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
	else if (signGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
	_signed = false;
}

Form::~Form()
{
}

Form::Form(const Form &o) :
_name(o.getName()), _signGrade(o.getSignGrade()), _execGrade(o.getExecGrade()),
_signed(o.getSigned())
{
}

Form &Form::operator=(const Form &rhs)
{
	if (this != &rhs)
	{
		_signed = rhs.getSigned();
	}
	return (*this);
}

std::string Form::getName() const
{
	return (_name);
}

int	Form::getSignGrade() const
{
	return (_signGrade);
}

int	Form::getExecGrade() const
{
	return (_execGrade);
}

bool Form::getSigned() const
{
	return (_signed);
}

void Form::beSigned(const Bureaucrat &signer)
{
	if (signer.getGrade() > this->getSignGrade())
		throw GradeTooLowException();
	if (getSigned() == true)
		throw AlreadySignedException();
	_signed = true;
}

const char *Form::AlreadySignedException::what() const throw()
{
	return ("Form - Already Signed.\n");
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Form - Grade too high.\n");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Form - Grade too low.\n");
}

std::ostream &operator<<(std::ostream &out, Form const &f)
{
	out << f.getName() << ", form - Sign Grade: " << f.getSignGrade()
		<< " Exec Grade: " << f.getExecGrade() << " Signed Status: "
		<< f.getSigned();
	return (out);
}
