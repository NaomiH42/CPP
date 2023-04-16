#include "Zombie.hpp"

int	main(void)
{
	std::string name = "Naomi";
	Zombie *naomi_zombie = zombieHorde(10, name);
	delete [] naomi_zombie;
}