#include "Animal.hpp"

Animal::Animal( void )
{
	std::cout << "I THE ANIMAL HAS BEEN BORN" << std::endl;
}

Animal::~Animal( void )
{
	std::cout << "I THE ANIMAL HAS BEEN DESTROYED" << std::endl;
}

Animal::Animal( const Animal &original )
{
	std::cout << "I THE ANIMAL HAS BEEN COPIED" << std::endl;
	this->_type = original._type;
}

Animal &Animal::operator=(const Animal &rhs)
{
	std::cout << "I THE ANIMAL HAS BEEN EQUALED" << std::endl;
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



