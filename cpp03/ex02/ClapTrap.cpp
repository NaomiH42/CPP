#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name(""), _hp(10), _ep(10), _ad(0)
{

}

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
	this->setName("<" + original.getName() + " copy>");
	this->setAD(original.getAD());
	this->setHP(original.getHP());
	this->setEP(original.getEP());
	std::cout << "Copy ClapTrap " << _name << " has been born!" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &c)
{
	this->_name = "<" + c._name + " equal>";
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
		std::cout <<_name << " is dead... :c"
			<< std::endl;
		return ;
	}
	std::cout <<  _name << " attacks "
		<< target << ", causing " << _ad << " points of damage!"
		<< std::endl;
}
void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hp <= 0)
	{
		std::cout << _name << " is dead... :c"
			<< std::endl;
		return ;
	}
	std::cout << _name << " took "
		<< amount << " damage." << std::endl;
	_hp -= amount;
	if (_hp <= 0)
		std::cout << _name << " has died."
			<< std::endl;
}
void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_hp <= 0)
	{
		std::cout << _name << " is dead... :c"
			<< std::endl;
		return ;
	}
	std::cout << _name << " repairs itself for "
		<< amount << " of HP." << std::endl;
	_hp += amount;
}

void	ClapTrap::setHP(int newHP)
{
	_hp = newHP;
}

void	ClapTrap::setEP(int newEP)
{
	_ep = newEP;
}

void	ClapTrap::setAD(int newAD)
{
	_ad = newAD;
}

void	ClapTrap::setName(std::string newName)
{
	_name = newName;
}

int	ClapTrap::getAD( void ) const
{
	return (this->_ad);
}

int	ClapTrap::getEP( void ) const
{
	return (this->_ep);
}

int	ClapTrap::getHP( void ) const
{
	return (this->_hp);
}

std::string	ClapTrap::getName( void ) const
{
	return (this->_name);
}
