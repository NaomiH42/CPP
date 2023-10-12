#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <exception>
#include <iostream>
#include <algorithm>

class Span
{
	public:
		Span();
		Span(unsigned int);
		~Span();
		Span(const Span&);
		Span& operator=(const Span&);
		int GetSize() const;
		int	getInd(int i ) const;
		void	addNumber(int);
		int shortestSpan();
		int longestSpan();
		void	addRange()

	private:
		std::vector<int> _spans;
		int	_maxSize;

	class VectorFullException : public std::exception
	{
		virtual const char *what() const throw();
	};

	class NotEnoughElementsException : public std::exception
	{
		virtual const char *what() const throw();
	};
};

#endif
