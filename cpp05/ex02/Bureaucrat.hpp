#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat &o);
		Bureaucrat &operator=(const Bureaucrat &rhs);
		std::string getName() const;
		int			getGrade() const;
		void		increaseGrade();
		void		decreaseGrade();
		void		signForm(AForm &f);
		void		executeForm(AForm const & form);
	private:
		const std::string	_name;
		int					_grade;

	class GradeTooHighException : public std::exception
	{
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		virtual const char *what() const throw();
	};
};


std::ostream &operator<<(std::ostream &out, Bureaucrat const &b);

#endif
