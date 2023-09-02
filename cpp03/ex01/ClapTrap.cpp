#include "ClapTrap.hpp"

ClapTrap::ClapTrap(){}

ClapTrap::ClapTrap( std::string newName ) : _name(newName), _hp(10), _ep(10), _ad(0)
{
	std::cout << "ClapTrap " << newName << " has been born!" << std::endl;
}

ClapTrap::~ClapTrap( void )
{
	std::cout << "ClapTrap " << _name << " has been destroyed!" << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap &original )
{
	this->_name = "<" + original._name + " copy>";
	this->_ad = original._ad;
	this->_hp = original._hp;
	this->_ep = original._ep;
	std::cout << "Copy ClapTrap " << _name << " has been born!" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &c)
{
	this->_name = "<" + c._name + " equal";
	this->_ad = c._ad;
	this->_hp = c._hp;
	this->_ep = c._ep;
	std::cout << "Equal ClapTrap " << this->_name << " has been born!" << std::endl;
	return (*this);
}

void	ClapTrap::attack(const std::string& target)
{
	if (_hp <= 0)
	{
		std::cout << "ClapTrap " << _name << " is dead... :c"
			<< std::endl;
		return ;
	}
	std::cout << "ClapTrap " << _name << " attacks "
		<< target << ", causing " << _ad << " points of damage!"
		<< std::endl;
}
void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hp <= 0)
	{
		std::cout << "ClapTrap " << _name << " is dead... :c"
			<< std::endl;
		return ;
	}
	std::cout << "ClapTrap " << _name << " took "
		<< amount << " damage." << std::endl;
	_hp -= amount;
	if (_hp <= 0)
		std::cout << "ClapTrap " << _name << " has died."
			<< std::endl;
}
void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_hp <= 0)
	{
		std::cout << "ClapTrap " << _name << " is dead... :c"
			<< std::endl;
		return ;
	}
	std::cout << "ClapTrap " << _name << " repairs itself for "
		<< amount << " of HP." << std::endl;
	if (_hp + amount > 10)
		_hp = 10;
	else
		_hp += amount;
}
