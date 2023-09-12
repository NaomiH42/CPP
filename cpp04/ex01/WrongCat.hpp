#ifndef WRONGCAT_HPP
# define WRONGAT_HPP

# include <iostream>
# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{

public:
	WrongCat( void );
	~WrongCat( void );
	WrongCat( const WrongCat &c);
	WrongCat &operator=(const WrongCat &c);
	void makeSound( void ) const;


private:

};

#endif
