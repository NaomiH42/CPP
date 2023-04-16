#include "Weapon.hpp"

Weapon::Weapon(std::string weapon) : type(weapon)
{
	return ;
}

void Weapon::setType(std::string new_type)
{
	this->type = new_type;
}

const std::string &Weapon::getType()
{
	return(this->type);
}