#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"
# include <iostream>

class WrongCat : public WrongAnimal
{

public:
	WrongCat( void );
	~WrongCat( void );
	WrongCat( const WrongCat &c);
	WrongCat &operator=( const WrongCat &c);

private:

};

#endif
