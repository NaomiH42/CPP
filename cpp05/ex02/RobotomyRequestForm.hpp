#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include "fstream"
#include <stdlib.h>
#include <time.h>

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm(std::string target);
		virtual ~RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm& o);
		RobotomyRequestForm &operator=(const RobotomyRequestForm& rhs);
		std::string 	getTarget() const;


	private:
		virtual void	executeActual() const;
		std::string _target;
};

#endif
