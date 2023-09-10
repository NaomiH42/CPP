#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{

private:

	std::string _name;

public:

	DiamondTrap();
	DiamondTrap( std::string newName );
	~DiamondTrap( void );
	DiamondTrap( const DiamondTrap &original);
	DiamondTrap &operator=( const DiamondTrap &c );

	void	report();
};

#endif
