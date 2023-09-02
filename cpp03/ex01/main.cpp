#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main( void )
{
	std::string name = "Naomi";
	ScavTrap CT1(name);
	ScavTrap CT2(CT1);
	ScavTrap CT3;
	CT3 = CT1;
	// CT1.attack(name);
	// CT1.beRepaired(5);
	CT1.takeDamage(50);
}
