#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void )
{
	std::cout << "NROB NEEB SAH LAMINA EHT I" << std::endl;
}

WrongAnimal::~WrongAnimal( void )
{
	std::cout << "DEYORTSED NEEB SAH LAMINA EHT I" << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal &original )
{
	std::cout << "DEIPOC NEEB SAH LAMINA EHT I" << std::endl;
	this->_type = original._type;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &rhs)
{
	std::cout << "DELAUQE NEEB SAH LAMINA EHT I" << std::endl;
	this->_type = rhs._type;
	return (*this);
}

void WrongAnimal::makeSound( void ) const
{
	std::cout << "I AM JUST AN WrongAnimal LOL" << std::endl;
}

std::string WrongAnimal::getType( void ) const
{
	return (this->_type);
}



