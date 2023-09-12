#include "Cat.hpp"

Cat::Cat( void ) : Animal()
{
	std::cout << "I CAT" << std::endl;
	_type = "Cat";
	_brain = new Brain();
}

Cat::~Cat( void )
{
	std::cout << "Cat :c" << std::endl;
	delete _brain;
}

Cat::Cat( const Cat &original ) : Animal(original)
{
	std::cout << "I'm a CopyCat" << std::endl;
	this->_type = original.getType();
	this->_brain = original._brain;
}

Cat &Cat::operator=(const Cat &rhs)
{
	std::cout << "Cats equalized" << std::endl;
	if (this != &rhs)
	{
		this->_brain = rhs._brain;
		this->_type = rhs.getType();
	}
	return (*this);
}

void Cat::makeSound( void ) const
{
	std::cout << "MEOW" << std::endl;
}
