#include"Zombie.hpp"

void randomChump(std::string name)
{
	Zombie *spawned = newZombie(name);
	spawned->announce();
	delete spawned;
}