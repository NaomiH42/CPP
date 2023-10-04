#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target)
 : AForm("PresidentialPardonForm", 25, 5), _target(target)
{}

PresidentialPardonForm::~PresidentialPardonForm()
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& o)
 : AForm(o)
{
	_target = o.getTarget();
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs)
{
	if (this != &rhs)
	{
		AForm::operator=(rhs);
		_target = rhs.getTarget();
	}
	return (*this);
}

std::string PresidentialPardonForm::getTarget() const
{
	return (_target);
}

void	PresidentialPardonForm::executeActual() const
{
	std::cout << "Zaphod Beeblebrox has pardoned " << getTarget() << std::endl;
}
