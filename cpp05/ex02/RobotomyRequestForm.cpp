#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target)
 : AForm("RobotomyRequestForm", 72, 45), _target(target)
{}

RobotomyRequestForm::~RobotomyRequestForm()
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& o)
 : AForm(o)
{
	_target = o.getTarget();
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs)
{
	if (this != &rhs)
	{
		AForm::operator=(rhs);
		_target = rhs.getTarget();
	}
	return (*this);
}

std::string RobotomyRequestForm::getTarget() const
{
	return (_target);
}


void	RobotomyRequestForm::executeActual() const
{
	srand(time(0));
	int	r = rand() % 100;
	if (r < 50)
		std:: cout << getTarget() << " has been succesfully robotomised." << std::endl;
	else
		std:: cout << getTarget() << " has failed to be robotomised." << std::endl;

}
