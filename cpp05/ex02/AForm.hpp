#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	public:
		AForm(std::string name, int signGrade, int execGrade);
		virtual ~AForm() = 0;
		AForm(const AForm &o);
		AForm &operator=(const AForm &rhs);
		std::string 	getName() const;
		int				getSignGrade() const;
		int				getExecGrade() const;
		bool			getSigned() const;
		void			beSigned(const Bureaucrat &signer);
		void			execute(Bureaucrat const & executor) const;

	private:
		virtual void	executeActual() const = 0;
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
	class NotSignedException : public std::exception
	{
		virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &out, AForm const &f);

#endif
