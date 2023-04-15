#include "Zombie.hpp"

Zombie::Zombie(std::string name) : name(name)
{
	return ;
}

void	Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}