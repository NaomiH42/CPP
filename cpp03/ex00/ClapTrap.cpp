#include "ClapTrap.hpp"

ClapTrap::ClapTrap( std::string newName ) : _name(newName), _hp(10), _ep(10), _ad(0)
{
	std::cout << "ClapTrap " << newName << " has been born!" << std::endl;
}

ClapTrap::~ClapTrap( void )
{

}

ClapTrap::ClapTrap( const ClapTrap &original )
{

}

ClapTrap &ClapTrap::operator=(const ClapTrap &rhs)
{
	if (this != &rhs)

	return (*this);
}

void	ClapTrap::attack(const std::string& target)
{
	if (_hp < 0)
	{
		std::cout << "ClapTrap " << name << " is dead... :c"
			<< std::endl;
		return ;
	}
	std::cout << "ClapTrap " << _name << " attacks "
		<< target << ", causing " << _ad << " points of damage!"
		<< sdt::endl;
}
void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hp < 0)
	{
		std::cout << "ClapTrap " << name << " is dead... :c"
			<< std::endl;
		return ;
	}
}
void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_hp < 0)
	{
		std::cout << "ClapTrap " << name << " is dead... :c"
			<< std::endl;
		return ;
	}
}
