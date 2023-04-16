#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanB{


public:
	std::string name;
	Weapon *held_weapon;
	HumanB(std::string new_name);
	void	attack();
	void setWeapon(Weapon &new_weapon);

};


#endif