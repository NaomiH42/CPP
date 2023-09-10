#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{

public:

	FragTrap();
	FragTrap( std::string newName );
	~FragTrap( void );
	FragTrap( const FragTrap &original);
	FragTrap &operator=( const FragTrap &c );

	void	report();
	void	highFivesGuys() const;
};

#endif
