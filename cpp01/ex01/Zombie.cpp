#include "Zombie.hpp"

Zombie::Zombie()
{
	return ;
}

Zombie::~Zombie(void)
{
	std::cout << this->_name << " has decayed." << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::naming(std::string name)
{
	this->_name = name;
}