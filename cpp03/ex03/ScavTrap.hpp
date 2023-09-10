#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{

public:

	ScavTrap();
	ScavTrap( std::string newName );
	~ScavTrap( void );
	ScavTrap( const ScavTrap &original);
	ScavTrap &operator=( const ScavTrap &c );

	void	report();
	void	attack(const std::string& target);
	void	guardGate();

	void	setHP( void );
	void	setEP( void );
	void	setAD( void );

};

#endif
