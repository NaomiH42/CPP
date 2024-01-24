#include "Cat.hpp"

Cat::Cat( void ) : Animal()
{
	std::cout << "I CAT" << std::endl;
	_type = "Cat";
	_brain = new Brain();
}

Cat::~Cat( void )
{
	delete _brain;
	std::cout << "Cat :c" << std::endl;
}

Cat::Cat( const Cat &original ) : Animal(original)
{
	std::cout << "I'm a CopyCat" << std::endl;
	_type = original.getType();
	_brain = new Brain(*original._brain);
}

Cat &Cat::operator=(const Cat &rhs)
{
	if (this != &rhs)
	{
		if (_brain)
			delete _brain;
		std::cout << "Cats equalized" << std::endl;
		_brain = new Brain (*rhs._brain);
		_type = rhs.getType();
	}
	return (*this);
}

void Cat::makeSound( void ) const
{
	std::cout << "MEOW" << std::endl;
}

void Cat::compareCats( const Cat &other)
{
	std::cout << "This cat adress " << &(this->_brain) << std::endl;
	std::cout << "Others cat adress " << &(other._brain) << std::endl;
}
