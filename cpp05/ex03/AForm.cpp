#include "AForm.hpp"

AForm::AForm(std::string name, int signGrade, int execGrade) :
_name(name), _signGrade(signGrade), _execGrade(execGrade)
{
	if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
	else if (signGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
	_signed = false;
}

AForm::~AForm()
{
}

AForm::AForm(const AForm &o) :
_name(o.getName()), _signGrade(o.getSignGrade()), _execGrade(o.getExecGrade()),
_signed(o.getSigned())
{
}

AForm &AForm::operator=(const AForm &rhs)
{
	if (this != &rhs)
	{
		_signed = rhs.getSigned();
	}
	return (*this);
}

std::string AForm::getName() const
{
	return (_name);
}

int	AForm::getSignGrade() const
{
	return (_signGrade);
}

int	AForm::getExecGrade() const
{
	return (_execGrade);
}

bool AForm::getSigned() const
{
	return (_signed);
}

void AForm::beSigned(const Bureaucrat &signer)
{
	if (signer.getGrade() > this->getSignGrade())
		throw GradeTooLowException();
	if (getSigned() == true)
		throw AlreadySignedException();
	_signed = true;
}

const char *AForm::NotSignedException::what() const throw()
{
	return ("AForm - Not Signed.");
}

const char *AForm::AlreadySignedException::what() const throw()
{
	return ("AForm - Already Signed.");
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("AForm - Grade too high.");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("AForm - Grade too low.");
}

void	AForm::execute(Bureaucrat const & executor) const
{

	if (getSigned() == false)
		throw NotSignedException();
	else if (executor.getGrade() > getExecGrade())
		throw GradeTooLowException();
	else
		executeActual();
}

std::ostream &operator<<(std::ostream &out, AForm const &f)
{
	out << f.getName() << ", Aform - Sign Grade: " << f.getSignGrade()
		<< " Exec Grade: " << f.getExecGrade() << " Signed Status: "
		<< f.getSigned();
	return (out);
}
