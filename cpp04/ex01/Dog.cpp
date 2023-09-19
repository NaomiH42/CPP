#include "Dog.hpp"

Dog::Dog( void ) : Animal()
{
	std::cout << "DOG HERE" << std::endl;
	_type = "Dog";
	_brain = new Brain();

}

Dog::~Dog( void )
{
	delete _brain;
	std::cout << "DOG GONE" << std::endl;
}

Dog::Dog( const Dog &original ) : Animal(original)
{
	std::cout << "DOG COPPED" << std::endl;
	_type = original.getType();
	_brain = new Brain(*original._brain);
}

Dog &Dog::operator=(const Dog &rhs)
{
	if (this != &rhs)
	{
		if (_brain)
			delete _brain;
		std::cout << "DOG EQUEDED" << std::endl;
		_brain = new Brain (*rhs._brain);
		_type = rhs.getType();
	}
	return (*this);
}

void Dog::makeSound( void ) const
{
	std::cout << "BARK" << std::endl;
}
