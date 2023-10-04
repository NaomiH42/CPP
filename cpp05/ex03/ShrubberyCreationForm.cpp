#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
 : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& o)
 : AForm(o)
{
	_target = o.getTarget();
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs)
{
	if (this != &rhs)
	{
		AForm::operator=(rhs);
		_target = rhs.getTarget();
	}
	return (*this);
}

std::string ShrubberyCreationForm::getTarget() const
{
	return (_target);
}

void	ShrubberyCreationForm::executeActual() const
{
	std::string target = getTarget() + "_shrubbery";
	std::ofstream fileTree(target.c_str());
	fileTree << "  ^\n" << " < >\n" << "<< >>\n" << "  I " << std::endl;
	fileTree.close();
}
