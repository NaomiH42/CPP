#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main( void )
{
	std::string name = "Naomi";
	FragTrap CT1(name);
	// ScavTrap CT2(CT1);
	// ScavTrap CT3;
	// CT3 = CT1;
	ScavTrap CT2(name);
	// CT2.attack(name);
	CT1.ClapTrap::attack(name);
	// CT1.beRepaired(5);
	// CT1.takeDamage(50);
	// CT1.report();
	CT1.highFivesGuys();
}
