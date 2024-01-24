#include "Dog.hpp"

Dog::Dog( void ) : Animal()
{
	std::cout << "DOG HERE" << std::endl;
	_type = "Dog";
}

Dog::~Dog( void )
{
	std::cout << "DOG GONE" << std::endl;
}

Dog::Dog( const Dog &original ) : Animal(original)
{
	std::cout << "DOG COPPED" << std::endl;
	this->_type = original.getType();
}

Dog &Dog::operator=(const Dog &rhs)
{
	std::cout << "DOG EQUEDED" << std::endl;
	if (this != &rhs)
		this->_type = rhs.getType();
	return (*this);
}

void Dog::makeSound( void ) const
{
	std::cout << "BARK" << std::endl;
}
