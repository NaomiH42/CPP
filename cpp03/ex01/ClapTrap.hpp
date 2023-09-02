#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{

public:
	ClapTrap();
	ClapTrap( std::string newName );
	~ClapTrap( void );
	ClapTrap( const ClapTrap &original);
	ClapTrap &operator=( const ClapTrap &c );

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

private:
	std::string _name;
	int			_hp;
	int			_ep;
	int			_ad;

};

#endif
