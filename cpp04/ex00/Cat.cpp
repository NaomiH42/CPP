#include "Cat.hpp"

Cat::Cat( void ) : Animal()
{
	_type = "Cat";
}

Cat::~Cat( void )
{

}

Cat::Cat( const Cat &original )
{
	this->_type = original.getType();
}

Cat &Cat::operator=(const Cat &rhs)
{
	if (this != &rhs)
		this->_type = rhs.getType();
	return (*this);
}

void Cat::makeSound( void ) const
{
	std::cout << "MEOW" << std::endl;
}