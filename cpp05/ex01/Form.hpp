#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
		Form(std::string name, int signGrade, int execGrade);
		~Form();
		Form(const Form &o);
		Form &operator=(const Form &rhs);
		std::string getName() const;
		int			getSignGrade() const;
		int			getExecGrade() const;
		bool		getSigned() const;
		void		beSigned(const Bureaucrat &signer);

	private:
		const std::string	_name;
		const int			_signGrade;
		const int			_execGrade;
		bool				_signed;

	class GradeTooHighException : public std::exception
	{
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		virtual const char *what() const throw();
	};
	class AlreadySignedException : public std::exception
	{
		virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &out, Form const &f);

#endif
