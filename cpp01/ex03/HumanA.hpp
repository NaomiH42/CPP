#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanA{


public:

	std::string name;
	Weapon &held_weapon;
	HumanA(std::string new_name, Weapon &new_weapon);
	void	attack();
	void setWeapon(Weapon &new_weapon);

};


#endif