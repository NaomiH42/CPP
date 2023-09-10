#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	setHP(100);
	setEP(50);
	setAD(20);
}

ScavTrap::ScavTrap( std::string newName ) : ClapTrap(newName)
{
	setName(newName);
	setHP(100);
	setEP(50);
	setAD(20);
	std::cout << "ScavTrap " << newName << " has been born!" << std::endl;
}

ScavTrap::~ScavTrap( void )
{
		std::cout << "ScavTrap " << this->getName() << " has been destroyed!" << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap &original ) : ClapTrap(original)
{
	this->setName("<" + original.getName() + " copy>");
	this->setAD(original.getAD());
	this->setHP(original.getHP());
	this->setEP(original.getEP());
	std::cout << "Copy ScavTrap " << getName() << " has been born!" << std::endl;
}

ScavTrap &ScavTrap::operator=( const ScavTrap &c )
{
	ClapTrap::operator=(c);
	this->setName("<" + c.getName() + " equal>");
	this->setAD(c.getAD());
	this->setHP(c.getHP());
	this->setEP(c.getEP());
	std::cout << "Equal ScavTrap " << this->getName() << " has been born!" << std::endl;
	return (*this);
}


void	ScavTrap::attack(const std::string& target)
{
	if (getHP() <= 0)
	{
		std::cout << "ScavTrap " << getName() << " is dead... :c"
			<< std::endl;
		return ;
	}
	std::cout << "ScavTrap " << getName() << " attacks "
		<< target << ", causing " << getAD() << " points of damage!"
		<< std::endl;
}

void	ScavTrap::report()
{
	std::cout << getHP() << std::endl;
}

void	ScavTrap::guardGate( void )
{
	std::cout << "ScavTrap " << getName() << " is now in guard mode." << std::endl;
}
