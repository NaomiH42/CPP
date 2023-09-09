#include "Animal.hpp"

Animal::Animal( void )
{

}

Animal::~Animal( void )
{

}

Animal::Animal( const Animal &original )
{
	this->_type = original._type;
}

Animal &Animal::operator=(const Animal &rhs)
{
	this->_type = rhs._type;
	return (*this);
}

void Animal::makeSound( void ) const
{
	std::cout << "I AM JUST AN ANIMAL LOL" << std::endl;
}

std::string Animal::getType( void ) const
{
	return (this->_type);
}



