#include "Brain.hpp"

Brain::Brain( void )
{
	this->_ideas = new std::string[100];
	for (int i = 0; i < 100; i++)
		_ideas[i] = "NEW IDEA";
	std::cout << "I SMART" << std::endl;
}

Brain::~Brain( void )
{
	delete [] this->_ideas;
	std::cout << "I STUPID" << std::endl;
}

Brain::Brain( const Brain &original )
{
	_ideas = new std::string[100];
	for (int i = 0; i < 100; i++)
			this->_ideas[i] = original._ideas[i];
	std::cout << "I PRETEND TO BE SMART" << std::endl;
}

Brain &Brain::operator=(const Brain &rhs)
{
	std::cout << "WE ARE BRAIN" << std::endl;
	if (this != &rhs)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = rhs._ideas[i];
	}
	return (*this);
}



