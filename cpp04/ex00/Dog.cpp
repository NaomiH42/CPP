#include "Dog.hpp"

Dog::Dog( void ) : Animal()
{
	_type = "Dog";
}

Dog::~Dog( void )
{

}

Dog::Dog( const Dog &original )
{
	this->_type = original.getType();
}

Dog &Dog::operator=(const Dog &rhs)
{
	if (this != &rhs)
		this->_type = rhs.getType();
	return (*this);
}

void Dog::makeSound( void ) const
{
	std::cout << "BARK" << std::endl;
}