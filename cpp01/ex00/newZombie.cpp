#include "Zombie.hpp"

Zombie *newZombie(std::string name)
{
	Zombie *spawned;
	spawned = new Zombie(name);
	return (spawned);
}