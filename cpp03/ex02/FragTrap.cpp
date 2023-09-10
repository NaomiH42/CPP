#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	setHP(100);
	setEP(100);
	setAD(30);
}

FragTrap::FragTrap( std::string newName ) : ClapTrap(newName)
{
	setName(newName);
	setHP(100);
	setEP(100);
	setAD(30);
	std::cout << "FragTrap " << newName << " has been born!" << std::endl;
}

FragTrap::~FragTrap( void )
{
		std::cout << "FragTrap " << this->getName() << " has been destroyed!" << std::endl;
}

FragTrap::FragTrap( const FragTrap &original ) : ClapTrap(original)
{
	this->setName("<" + original.getName() + " copy>");
	this->setAD(original.getAD());
	this->setHP(original.getHP());
	this->setEP(original.getEP());
	std::cout << "Copy FragTrap " << getName() << " has been born!" << std::endl;
}

FragTrap &FragTrap::operator=( const FragTrap &c )
{
	ClapTrap::operator=(c);
	this->setName("<" + c.getName() + " equal>");
	this->setAD(c.getAD());
	this->setHP(c.getHP());
	this->setEP(c.getEP());
	std::cout << "Equal FragTrap " << this->getName() << " has been born!" << std::endl;
	return (*this);
}

void	FragTrap::report()
{
	std::cout << getHP() << std::endl;
}

void	FragTrap::highFivesGuys( void ) const
{
	std::cout << "FragTrap " << getName() << " wants to high five." << std::endl;
}
