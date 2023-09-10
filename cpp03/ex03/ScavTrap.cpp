#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	setHP();
	setEP();
	setAD();
}

ScavTrap::ScavTrap( std::string newName ) : ClapTrap(newName)
{
	setName(newName);
	setHP();
	setEP();
	setAD();
	std::cout << "ScavTrap " << newName << " has been born!" << std::endl;
}

ScavTrap::~ScavTrap( void )
{
		std::cout << "ScavTrap " << this->getName() << " has been destroyed!" << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap &original ) : ClapTrap(original)
{
	this->setName("<" + original.getName() + " copy>");
	this->ClapTrap::setAD(original.getAD());
	this->ClapTrap::setHP(original.getHP());
	this->ClapTrap::setEP(original.getEP());
	std::cout << "Copy ScavTrap " << getName() << " has been born!" << std::endl;
}

ScavTrap &ScavTrap::operator=( const ScavTrap &c )
{
	ClapTrap::operator=(c);
	this->setName("<" + c.getName() + " equal>");
	this->ClapTrap::setAD(c.getAD());
	this->ClapTrap::setHP(c.getHP());
	this->ClapTrap::setEP(c.getEP());
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

void	ScavTrap::setHP( void )
{
	_hp = 100;
}

void	ScavTrap::setEP( void )
{
	_ep = 50;
}

void	ScavTrap::setAD( void )
{
	_ad = 20;
}
