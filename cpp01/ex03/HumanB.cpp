#include "HumanB.hpp"
#include "Weapon.hpp"
#include <iostream>

HumanB::HumanB(std::string new_name) : name(new_name)
{
	this->held_weapon = NULL;
	return ;
}

void	HumanB::attack()
{
	if (this->held_weapon != NULL)
		std::cout << this->name << " attacks with their " << this->held_weapon->getType() << std::endl;
	else
		std::cout << this->name << " doesn't have a weapon" << std::endl;
}

void HumanB::setWeapon(Weapon &new_weapon)
{
	this->held_weapon = &new_weapon;
}