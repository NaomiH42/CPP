#include "WrongCat.hpp"

WrongCat::WrongCat( void ) : WrongAnimal()
{
	std::cout << "TAC" << std::endl;
	_type = "WrongCat";
}

WrongCat::~WrongCat( void )
{
	std::cout << "): TAC" << std::endl;
}

WrongCat::WrongCat( const WrongCat &original ) : WrongAnimal(original)
{
	std::cout << "taCypoC" << std::endl;
	this->_type = original.getType();
}

WrongCat &WrongCat::operator=(const WrongCat &rhs)
{
	std::cout << "TAC EQ" << std::endl;
	if (this != &rhs)
		this->_type = rhs.getType();
	return (*this);
}

void WrongCat::makeSound( void ) const
{
	std::cout << "mEoWeWoL" << std::endl;
}
