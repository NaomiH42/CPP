#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : FragTrap(), ScavTrap()
{
	FragTrap::setHP();
	ScavTrap::setEP();
	FragTrap::setAD();
}

DiamondTrap::DiamondTrap( std::string newName ) : FragTrap(newName), ScavTrap(newName)
{
	FragTrap::setName(newName);
	FragTrap::setHP();
	ScavTrap::setEP();
	FragTrap::setAD();
	std::cout << "DiamondTrap " << newName << " has been born!" << std::endl;
}

DiamondTrap::~DiamondTrap( void )
{
		std::cout << "DiamondTrap " << this->FragTrap::ClapTrap::getName() << " has been destroyed!" << std::endl;
}

DiamondTrap::DiamondTrap( const DiamondTrap &original ) : ClapTrap(original)
{
	this->FragTrapClapTrap::setName("<" + original.FragTrap::ClapTrap::getName() + " copy>");
	this->FragTrap::ClapTrap::setAD(original.FragTrap::ClapTrap::getAD());
	this->FragTrap::ClapTrap::setHP(original.FragTrap::ClapTrap::getHP());
	this->FragTrap::ClapTrap::setEP(original.FragTrap::ClapTrap::getEP());
	std::cout << "Copy DiamondTrap " << FragTrap::ClapTrap::getName() << " has been born!" << std::endl;
}

DiamondTrap &DiamondTrap::operator=( const DiamondTrap &c )
{
	FragTrap::ClapTrap::operator=(c);
	this->FragTrap::ClapTrap::setName("<" + c.FragTrap::ClapTrap::getName() + " equal>");
	this->FragTrap::ClapTrap::setAD(c.FragTrap::ClapTrap::getAD());
	this->FragTrap::ClapTrap::setHP(c.FragTrap::ClapTrap::getHP());
	this->FragTrap::ClapTrap::setEP(c.FragTrap::ClapTrap::getEP());
	std::cout << "Equal DiamondTrap " << this->FragTrap::ClapTrap::getName() << " has been born!" << std::endl;
	return (*this);
}

void	DiamondTrap::report()
{
	std::cout << FragTrap::getHP() << std::endl;
}

