#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	setHP();
	setEP();
	setAD();
}

FragTrap::FragTrap( std::string newName ) : ClapTrap(newName)
{
	setName(newName);
	setHP();
	setEP();
	setAD();
	std::cout << "FragTrap " << newName << " has been born!" << std::endl;
}

FragTrap::~FragTrap( void )
{
		std::cout << "FragTrap " << this->getName() << " has been destroyed!" << std::endl;
}

FragTrap::FragTrap( const FragTrap &original ) : ClapTrap(original)
{
	this->setName("<" + original.getName() + " copy>");
	this->ClapTrap::setAD(original.getAD());
	this->ClapTrap::setHP(original.getHP());
	this->ClapTrap::setEP(original.getEP());
	std::cout << "Copy FragTrap " << getName() << " has been born!" << std::endl;
}

FragTrap &FragTrap::operator=( const FragTrap &c )
{
	ClapTrap::operator=(c);
	this->setName("<" + c.getName() + " equal>");
	this->ClapTrap::setAD(c.getAD());
	this->ClapTrap::setHP(c.getHP());
	this->ClapTrap::setEP(c.getEP());
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

void	FragTrap::setHP( void )
{
	_hp = 100;
}

void	FragTrap::setEP( void )
{
	_ep = 100;
}

void	FragTrap::setAD( void )
{
	_ad = 30;
}
