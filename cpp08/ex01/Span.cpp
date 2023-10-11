#include "Span.hpp"

Span::Span()
{
	std::vector<int> _spans(0);
	_maxSize = 0;
}

Span::Span(unsigned int size)
{
	std::vector<int> _spans(size);
	_maxSize = size;
}

Span::~Span()
{}

Span::Span(const Span& o)
{
	_maxSize = o.GetSize();
	std::vector<int> _spans;
	for (int i = 0; i < static_cast<int>(o._spans.size()); i++)
		_spans.push_back(o.getInd(i));
}

Span& Span::operator=(const Span& o)
{
	if (this != &o)
	{
		_maxSize = o.GetSize();
		std::vector<int> _spans;
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
	for (int i = 1; i < static_cast<int>(_spans.size()); i++)
	{
		if (_spans[i] - _spans[i - 1] < min || i == 1)
			min = abs(_spans[i] - _spans[i - 1]);
	}
	return (min);
}

int Span::longestSpan()
{
	int max = 0;
	if (_spans.size() == 0 || _spans.size() == 1)
		throw NotEnoughElementsException();
	sort(_spans.begin(), _spans.end());
	max = abs(_spans[0] - _spans[_spans.size() - 1]);
	return (max);
}
