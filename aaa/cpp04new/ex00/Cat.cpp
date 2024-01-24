#include "Cat.hpp"

Cat::Cat( void ) : Animal()
{
	std::cout << "I CAT" << std::endl;
	_type = "Cat";
}

Cat::~Cat( void )
{
	std::cout << "Cat :c" << std::endl;
}

Cat::Cat( const Cat &original ) : Animal(original)
{
	std::cout << "I'm a CopyCat" << std::endl;
	this->_type = original.getType();
}

Cat &Cat::operator=(const Cat &rhs)
{
	std::cout << "Cats equalized" << std::endl;
	if (this != &rhs)
		this->_type = rhs.getType();
	return (*this);
}

void Cat::makeSound( void ) const
{
	std::cout << "MEOW" << std::endl;
}
