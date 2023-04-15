#include "Zombie.hpp"

Zombie *newZombie(std::string name)
{
	Zombie	spawned(name);

	return (spawned);
}