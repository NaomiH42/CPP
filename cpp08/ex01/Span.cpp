#include "Span.hpp"

Span::Span()
{
	std::vector<int> _spans(0);
	_maxSize = 0;
}

Span::Span(unsigned int size)
{
	std::vector<int> _spans;
	_spans.reserve(size);
	_maxSize = size;
}

Span::~Span()
{}

Span::Span(const Span& o)
{
	_maxSize = o.GetSize();
	std::vector<int> _spans;
	_spans.reserve(_maxSize);
	for (int i = 0; i < static_cast<int>(o._spans.size()); i++)
		_spans.push_back(o.getInd(i));
}

Span& Span::operator=(const Span& o)
{
	if (this != &o)
	{
		_maxSize = o.GetSize();
		std::vector<int> _spans;
		_spans.reserve(_maxSize);
		for (int i = 0; i < (static_cast<int>(o._spans.size())); i++)
			_spans.push_back(o.getInd(i));
	}
	return *this;
}

void Span::addNumber(int newN)
{
	if (_maxSize != static_cast<int>(_spans.size()))
		_spans.push_back(newN);
	else
		throw VectorFullException();
}

const char* Span::VectorFullException::what() const throw()
{
	return ("Vector full!");
}

const char* Span::NotEnoughElementsException::what() const throw()
{
	return ("Zero or one number in vector.");
}

const char* Span::IncorrectRangeException::what() const throw()
{
	return ("Incorrect range.");
}

const char* Span::RangeTooBigException::what() const throw()
{
	return ("Numbers don't fit.");
}

int Span::GetSize() const
{
	return _maxSize;
}

int	Span::getInd(int i) const
{
	return (_spans[i]);
}

int Span::shortestSpan()
{
	int min = 0;
	if (_spans.size() == 0 || _spans.size() == 1)
		throw NotEnoughElementsException();
	sort(_spans.begin(), _spans.end());
	for (std::vector<int>::iterator i = _spans.begin() + 1; i != _spans.end(); i++)
	{
		std::vector<int>::iterator i2 = i-1;
		if (*i - *i2 < min || i == _spans.begin() +1)
			min = abs(*i - *i2);
	}
	return (min);
}

int Span::longestSpan()
{
	int max = 0;
	if (_spans.size() == 0 || _spans.size() == 1)
		throw NotEnoughElementsException();
	max = abs(*std::max_element(_spans.begin(), _spans.end()) - *std::min_element(_spans.begin(), _spans.end()));
	return (max);
}

void	Span::addRange(int start, int end)
{
	if (start >= end)
		throw IncorrectRangeException();
	if ((GetSize() - static_cast<int>(_spans.size())) < (end - start))
		throw RangeTooBigException();
	std::vector<int> range;
	range.reserve(end - start);
	for (int i = start; i <= end; i++)
		range.push_back(i);
	_spans.insert( _spans.end(), range.begin(), range.end());
}
