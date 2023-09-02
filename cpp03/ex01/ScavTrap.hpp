#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{

public:

	ScavTrap();
	ScavTrap( std::string newName );
	~ScavTrap( void );
	ScavTrap( const ScavTrap &original);
	ScavTrap &operator=( const ScavTrap &c );


void	attack(const std::string& target);

private:
	std::string _name;
	int			_hp;
	int			_ep;
	int			_ad;

};

#endif
