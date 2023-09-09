#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal
{

public:
	WrongAnimal( void );
	~WrongAnimal( void );
	WrongAnimal( const WrongAnimal &c);
	WrongAnimal &operator=( const WrongAnimal &c);

private:

};

#endif
