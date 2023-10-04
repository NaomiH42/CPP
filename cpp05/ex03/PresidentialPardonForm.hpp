#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include "fstream"

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm(std::string target);
		virtual ~PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm& o);
		PresidentialPardonForm &operator=(const PresidentialPardonForm& rhs);
		std::string 	getTarget() const;


	private:
		virtual void	executeActual() const;
		std::string _target;
};

#endif
