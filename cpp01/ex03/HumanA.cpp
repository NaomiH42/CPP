#include "HumanA.hpp"

HumanA::HumanA(std::string new_name, Weapon& new_weapon) : name(new_name), held_weapon(new_weapon)
{
	return ;
}

void	HumanA::attack()
{
	std::cout << this->name << " attacks with their " <<  this->held_weapon.getType() << std::endl;
}

void HumanA::setWeapon(Weapon &new_weapon)
{
	this->held_weapon = new_weapon;
}