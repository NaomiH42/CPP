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

	void virtual attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	int	getHP( void ) const;
	int getEP( void ) const;
	int	getAD( void ) const;
	std::string	getName( void ) const;

protected:
	std::string _name;
	int			_hp;
	int			_ep;
	int			_ad;
	void	setHP(int newHP);
	void	setEP(int newEP);
	void	setAD(int newAD);
	void	setName(std::string newName);

};

#endif
