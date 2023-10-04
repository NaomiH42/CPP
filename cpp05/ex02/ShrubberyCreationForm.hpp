#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include "fstream"

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm(std::string target);
		virtual ~ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm& o);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm& rhs);
		std::string 	getTarget() const;


	private:
		virtual void	executeActual() const;
		std::string _target;
};

#endif
