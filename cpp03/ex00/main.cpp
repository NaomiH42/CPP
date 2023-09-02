#include "ClapTrap.hpp"

int	main( void )
{
	std::string name = "Naomi";
	ClapTrap CT1(name);
	CT1.takeDamage(5);
	ClapTrap CT2(CT1);
	ClapTrap CT3;
	CT3 = CT1;
	CT1.attack(name);
	// CT3.takeDamage(5);
	CT1.beRepaired(5);
}
