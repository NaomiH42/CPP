#include "ScavTrap.hpp"

ScavTrap::ScavTrap(){}

ScavTrap::ScavTrap( std::string newName ) : ClapTrap(newName)
{
	_name = newName;
	_hp = 100;
	_ep = 50;
	_ad = 20;
	std::cout << "ScavTrap " << newName << " has been born!" << std::endl;
}

ScavTrap::~ScavTrap( void )
{
		std::cout << "ScavTrap " << this->_name << " has been destroyed!" << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap &original ) : ClapTrap(original)
{
	this->_name = "<" + original._name + " copy>";
	this->_ad = original._ad;
	this->_hp = original._hp;
	this->_ep = original._hp;
	std::cout << "Copy ScavTrap " << _name << " has been born!" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &c)
{
	ClapTrap::operator=(c);
	this->_name = "<" + c._name + " equal>";
	this->_ad = c._ad;
	this->_hp = c._hp;
	this->_ep = c._hp;
	std::cout << "Equal ScavTrap " << this->_name << " has been born!" << std::endl;
	return (*this);
}


void	ScavTrap::attack(const std::string& target)
{
	if (_hp <= 0)
	{
		std::cout << "ScavTrap " << _name << " is dead... :c"
			<< std::endl;
		return ;
	}
	std::cout << "ScavTrap " << _name << " attacks "
		<< target << ", causing " << _ad << " points of damage!"
		<< std::endl;
}
